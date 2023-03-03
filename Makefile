#
#			Armando Dalla Costa Neto,                               	15118029
#               	Mateus Talzzia Diogo,                                     	15147861
#                	Matheus Augusto Cremonez Guimarães,       			15004336
#			Leonardo Borges Bergamo,					15251275
#                	Paulo Vinicius Martimiano de Oliveira,             		15149313
#                	Rafael Mont’Alverne de Souza,                         		15078371#
#


#
# Makefile for the Linux minix filesystem routines.
#

obj-$(CONFIG_MINIX_FS) += minix_1.o

minix_1-objs := bitmap.o itree_v1.o itree_v2.o namei.o inode.o file.o dir.o

KVERSION = $(shell uname -r)
all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
	
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
	


