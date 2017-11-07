/*
 *  linux/fs/minix/file.c
 *
 *  Copyright (C) 1991, 1992 Linus Torvalds
 *
 *  minix regular file handling primitives
 */



#include "minix.h"
#include <linux/uio.h>
//#include "unistd.h"




/*
 * We have mostly NULLs here: the current defaults are OK for
 * the minix filesystem.
 */
static ssize_t criptografa(struct kiocb *iocb, struct iov_iter *from);
static ssize_t descriptografa(struct kiocb *iocb, struct iov_iter *iter);

const struct file_operations minix_file_operations = {
	.llseek		= generic_file_llseek,
	.read_iter	= descriptografa,
	.write_iter	= criptografa,
	.mmap		= generic_file_mmap,
	.fsync		= generic_file_fsync,
	.splice_read	= generic_file_splice_read,
};

struct data{
	int n;
	char s[10];
};

static ssize_t criptografa(struct kiocb *iocb, struct iov_iter *from)
{
	ssize_t retorno;
	int i;
	char buffer1[256],*caminho,buffer2[30]; 
	struct file *file = iocb->ki_filp;
	int fd;
	void *buf;
	struct data data[3];
	
	printk("CRIPTOGRAFAAA\n");

	printk("ANTERIORMENTE From iov_len [0] %d\n",from->iov[0].iov_len); //o numero do iov é dado por nr_segs
	printk("ANTERIORMENTE From iov_len [1] %d\n",from->iov[1].iov_len); //o numero do iov é dado por nr_seg
	printk("ANTERIORMENTE From iov_len [2] %d\n",from->iov[2].iov_len); //o numero do iov é dado por nr_seg		
	printk("ANTERIORMENTE From nr_segs [0] %d\n",from->nr_segs); //o numero do iov é dado por nr_segs
	printk("ANTERIORMENTE From iov_offset [0] %d\n",from->iov_offset); //o numero do iov é dado por nr_segs

	printk("iov_base[0] ANTES DA FUNCAO\n");
	for(i = 0; i < from->iov[0].iov_len - 1; i++)
	{
		*(((char *)from->iov[0].iov_base)+i) = '1';
		printk("%c",*(((char *)from->iov[0].iov_base)+i));

	}

	printk("\n");


	retorno = generic_file_write_iter(iocb,from); //função original


	caminho = dentry_path_raw(file->f_path.dentry, buffer1, 256);
	printk("CAMINHO DENTRY: %s\n",caminho);
	


	printk("From iov_len [0] %d\n",from->iov[0].iov_len); //o numero do iov é dado por nr_segs
	printk("From iov_len [1] %d\n",from->iov[1].iov_len); //o numero do iov é dado por nr_segs
	printk("From iov_len [2] %d\n",from->iov[2].iov_len); //o numero do iov é dado por nr_seg		
	printk("From nr_segs [0] %d\n",from->nr_segs); //o numero do iov é dado por nr_segs
	printk("From iov_offset [0] %d\n",from->iov_offset); //o numero do iov é dado por nr_segs
	printk("From iov_base [0] %s\n",(char *)from->iov[0].iov_base);
	printk("From iov_base [1] %s\n",(char *)from->iov[1].iov_base);

	printk("retorno crypt %zd\n",retorno);
	return retorno;



	/*
	struct sk_buff *buffer[200];

	skb_copy_datagram_from_iter(buffer,0,from,strlen(from));
	printk("From %s\n",buffer);*/
	
	//caminho = file->f_path.dentry->d_iname;
	//printk("CAMINHO DENTRY INAME: %s\n",caminho);

	//caminho = file->f_path.dentry->d_parent->d_iname;
	//printk("CAMINHO DENTRY PARENT: %s\n",caminho);


	//dentry_path_raw(file->f_path.mnt.mnt_root, buffer2, 30);
	//printk("CAMINHO mnt_root: %s\n",buffer2);
	
	//copy_to_iter(buf, 30, from);
	
	
	//for(i = 0; i < 30; i++)
	//{
		//printk("ANTERIOR %02x\n", ((uint8_t*) buf)[i]);
	//}
}

static ssize_t descriptografa(struct kiocb *iocb, struct iov_iter *iter)
{
	ssize_t retorno;
	int i;
	printk("DESCRIPTOGRAFAAAA\n");

	printk("DECRYPT iter iov_len [0] %d\n",iter->iov[0].iov_len); //o numero do iov é dado por nr_segs
	printk("DECRYPT iter iov_len [1] %d\n",iter->iov[1].iov_len); //o numero do iov é dado por nr_segs
	printk("DECRYPT iter iov_len [2] %d\n",iter->iov[2].iov_len); //o numero do iov é dado por nr_segs

	printk("iov_base[0] ANTES DA FUNCAO DECRYPT\n");
	/*for(i = 0; i < iter->iov[0].iov_len - 1; i++)
	{
		//*(((char *)iter->iov[0].iov_base)+i) = '1';
		printk("%c",*(((char *)iter->iov[0].iov_base)+i));

	}*/

	printk("\n");
	retorno = generic_file_read_iter(iocb,iter);
	printk("retorno decrypt %zd\n",retorno);
	return retorno;
	
}

static int minix_setattr(struct dentry *dentry, struct iattr *attr)
{
	printk("minix_setattr file.c\n");
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
