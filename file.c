/*
			Armando Dalla Costa Neto,                               	15118029
                	Mateus Talzzia Diogo,                                     	15147861
                	Matheus Augusto Cremonez Guimarães,       			15004336
			Leonardo Borges Bergamo,					15251275
                	Paulo Vinicius Martimiano de Oliveira,             		15149313
                	Rafael Mont’Alverne de Souza,                         		15078371
*/



/*
 *  linux/fs/minix/file.c
 *
 *  Copyright (C) 1991, 1992 Linus Torvalds
 *
 *  minix regular file handling primitives
 */

#include <linux/moduleparam.h>
#include <linux/module.h>
#include <crypto/internal/skcipher.h>
#include <crypto/skcipher.h>
#include "minix.h"
#include <linux/uio.h>
/*
 * We have mostly NULLs here: the current defaults are OK for
 * the minix filesystem.
 */

MODULE_LICENSE("GPL");

static ssize_t criptografa(struct kiocb *iocb, struct iov_iter *from);
static ssize_t descriptografa(struct kiocb *iocb, struct iov_iter *iter);

static char *key = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; 	// variavel para receber chave passada no insmod

module_param(key, charp, 0000);

const struct file_operations minix_file_operations = {
	.llseek		= generic_file_llseek,
	.read_iter	= descriptografa,//Chama a função personalizada descriptografa.
	.write_iter	= criptografa,//Chama a função personalizada criptografa.
	.mmap		= generic_file_mmap,
	.fsync		= generic_file_fsync,
	.splice_read	= generic_file_splice_read,
};

struct tcrypt_result {
    struct completion completion;
    int err;
};

/* tie all data structures together */
struct skcipher_def {
    struct scatterlist sg;
    struct crypto_skcipher *tfm;
    struct skcipher_request *req;
    struct tcrypt_result result;
};

/* Callback function */
static void test_skcipher_cb(struct crypto_async_request *req, int error)
{
    struct tcrypt_result *result = req->data;

    if (error == -EINPROGRESS)
        return;
    result->err = error;
    complete(&result->completion);
    pr_info("Encryption finished successfully\n");
}

/* Perform cipher operation */
static unsigned int test_skcipher_encdec(struct skcipher_def *sk,
                     int enc)
{
    int rc = 0;

    if (enc)
        rc = crypto_skcipher_encrypt(sk->req);
    else
        rc = crypto_skcipher_decrypt(sk->req);

    switch (rc) {
    case 0:
        break;
    case -EINPROGRESS:
    case -EBUSY:
        rc = wait_for_completion_interruptible(
            &sk->result.completion);
        if (!rc && !sk->result.err) {
            reinit_completion(&sk->result.completion);
            break;
        }
    default:
        pr_info("skcipher encrypt returned with %d result %d\n",
            rc, sk->result.err);
        break;
    }
    init_completion(&sk->result.completion);

    return rc;
}

/* Initialize and trigger cipher operation */
static int retornaEncriptado(char buffer[],int acao)
{
    struct skcipher_def sk;
    struct crypto_skcipher *skcipher = NULL;
    struct skcipher_request *req = NULL;
    char *scratchpad = NULL;
    char *ivdata = NULL;
    unsigned char key1[32];
    int ret = -EFAULT,i;

    skcipher = crypto_alloc_skcipher("ecb(aes)", 0, 0);
    if (IS_ERR(skcipher)) {
        pr_info("could not allocate skcipher handle\n");
        return PTR_ERR(skcipher);
    }

    req = skcipher_request_alloc(skcipher, GFP_KERNEL);
    if (!req) {
        pr_info("could not allocate skcipher request\n");
        ret = -ENOMEM;
        goto out;
    }

    skcipher_request_set_callback(req, CRYPTO_TFM_REQ_MAY_BACKLOG,
                      test_skcipher_cb,
                      &sk.result);


	//Atribuindo a letra 'a' a chave.
	for(i=0;i < 32; i++)
	{
		key1[i] = 'a';
	}

	printk("Chave Utilizada:\n");

	//copia a key passada por parametro
	for(i=0; key[i] != '\0'; i++)
	{
		key1[i] = key[i];
		
		
	}
	//printa a chave no dmesg
	for(i=0;i < 32; i++)
	{
		printk("%c",key1[i]);
	}

	printk("\n");
	
		
	
    if (crypto_skcipher_setkey(skcipher, key1, 32)) {
        pr_info("key could not be set\n");
        ret = -EAGAIN;
        goto out;
    }

    /* IV will be random */
    ivdata = kmalloc(16, GFP_KERNEL);
    if (!ivdata) {
        pr_info("could not allocate ivdata\n");
        goto out;
    }
    get_random_bytes(ivdata, 16);

    /* Input data will be random */
    scratchpad = kmalloc(16, GFP_KERNEL);
    if (!scratchpad) {
        pr_info("could not allocate scratchpad\n");
        goto out;
    }

	strcpy(scratchpad,buffer);

    sk.tfm = skcipher;
    sk.req = req;

    /* We encrypt one block */
    sg_init_one(&sk.sg, scratchpad, 16);
    skcipher_request_set_crypt(req, &sk.sg, &sk.sg, 16, ivdata);
    init_completion(&sk.result.completion);

    /* encrypt data */
	//Escolhe qual operação realizara: 1 para criptografia e 0 para descriptografia 
	if(acao == 1)
	{
	    ret = test_skcipher_encdec(&sk, 1);
	}
	else if(acao == 0)
	{
	    ret = test_skcipher_encdec(&sk, 0);
	}	


	sg_copy_to_buffer (&sk.sg, 1, buffer, 16);
    if (ret)
        goto out;

    pr_info("Encryption triggered successfully\n");

out:
    if (skcipher)
        crypto_free_skcipher(skcipher);
    if (req)
        skcipher_request_free(req);
    if (ivdata)
        kfree(ivdata);
    if (scratchpad)
        kfree(scratchpad);
    return ret;
}

static int minix_setattr(struct dentry *dentry, struct iattr *attr)
{
	struct inode *inode = d_inode(dentry);
	int error;

	error = inode_change_ok(inode, attr);
	if (error)
		return error;

	if ((attr->ia_valid & ATTR_SIZE) &&
	    attr->ia_size != i_size_read(inode)) {
		error = inode_newsize_ok(inode, attr->ia_size);
		if (error)
			return error;

		truncate_setsize(inode, attr->ia_size);
		minix_truncate(inode);
	}

	setattr_copy(inode, attr);
	mark_inode_dirty(inode);
	return 0;
}

const struct inode_operations minix_file_inode_operations = {
	.setattr	= minix_setattr,
	.getattr	= minix_getattr,
};

//Função para criptografar
static ssize_t criptografa(struct kiocb *iocb, struct iov_iter *from)
{//write
	ssize_t retorno;
	int i,j;
	char buffer1[17]; 
	

	for(j=0; j < (from->iov[0].iov_len - 1); j=j+16) // Pega de 16 em 16 caracteres
	{ 
		for(i=0;i<16;i++)
		{
			buffer1[i] = 'a';
		}
		if((j+16)<(from->iov[0].iov_len - 1)){
			printk("Buffer 1 Antes de Criptografar:\n");
			for(i = 0; i < 16; i++)// Passa conteudo do arquivo para o buffer
			{
				buffer1[i] = *(((char *)from->iov[0].iov_base)+(i+j));
				printk("%c", buffer1[i]);
			}
			printk("\n");
		
			buffer1[16] = '\0';

			retornaEncriptado(buffer1,1); //Realiza criptografia com o conteudo do buffer1


			for(i = 0; i < 16; i++)
			{
				*(((char *)from->iov[0].iov_base)+(i+j)) = buffer1[i];//Passa conteudo do buffer para o arquivo.
			}
		
		}
	}	

	retorno = generic_file_write_iter(iocb,from); //função original
	
	return retorno;


}

//Função para descriptografar
static ssize_t descriptografa(struct kiocb *iocb, struct iov_iter *iter)
{//read
	char buffer1[17];
	ssize_t retorno;
	int i, j;

	retorno = generic_file_read_iter(iocb,iter); //função original

	


	for(j = 0; j < (strlen((char *)iter->kvec->iov_base)-1); j=j+16)//Pega de 16 em 16 caracteres
	{
		for(i = 0; i < 16; i++)
		{
			buffer1[i] = '\0';
		}


		
		if((j+16)<(strlen((char *)iter->kvec->iov_base)-1)){
			for(i = 0; i < 16; i++)// Passa conteudo do arquivo para o buffer
			{
				buffer1[i] = *(((char *)iter->kvec->iov_base)+(i+j));
			}
				
		
		
			retornaEncriptado(buffer1,0);//Realiza descriptografia com o conteudo do buffer1
			buffer1[16] = '\0';
		
			printk("Buffer 1 Depois de Descriptografar:\n");
			for(i = 0; i < 16; i++)
			{
				 *(((char *)iter->kvec->iov_base)+(i+j)) = buffer1[i];//Passa conteudo do buffer para o arquivo.
				printk("%c", buffer1[i]);
			}
			printk("\n");

		}


	
	}
	return retorno;
	
}
