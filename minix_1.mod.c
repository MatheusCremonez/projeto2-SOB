/*
			Armando Dalla Costa Neto,                               	15118029
                	Mateus Talzzia Diogo,                                     	15147861
                	Matheus Augusto Cremonez Guimarães,       			15004336
			Leonardo Borges Bergamo,					15251275
                	Paulo Vinicius Martimiano de Oliveira,             		15149313
                	Rafael Mont’Alverne de Souza,                         		15078371
*/

#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x944af4ac, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x134aff86, __VMLINUX_SYMBOL_STR(crypto_alloc_skcipher) },
	{ 0x818bab06, __VMLINUX_SYMBOL_STR(kmem_cache_destroy) },
	{ 0x9144899e, __VMLINUX_SYMBOL_STR(iget_failed) },
	{ 0x9d882c0, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x405c1144, __VMLINUX_SYMBOL_STR(get_seconds) },
	{ 0x3831bbc4, __VMLINUX_SYMBOL_STR(drop_nlink) },
	{ 0xe9891940, __VMLINUX_SYMBOL_STR(mark_buffer_dirty_inode) },
	{ 0x7fe38f48, __VMLINUX_SYMBOL_STR(sg_copy_to_buffer) },
	{ 0x197c478a, __VMLINUX_SYMBOL_STR(generic_file_llseek) },
	{ 0xc6279b7e, __VMLINUX_SYMBOL_STR(__mark_inode_dirty) },
	{ 0x6bf1c17f, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0x754d539c, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0x60a13e90, __VMLINUX_SYMBOL_STR(rcu_barrier) },
	{ 0x79aa04a2, __VMLINUX_SYMBOL_STR(get_random_bytes) },
	{ 0x6d9c9c10, __VMLINUX_SYMBOL_STR(block_write_begin) },
	{ 0x7ae6caac, __VMLINUX_SYMBOL_STR(pagecache_get_page) },
	{ 0x25820c64, __VMLINUX_SYMBOL_STR(fs_overflowuid) },
	{ 0x179651ac, __VMLINUX_SYMBOL_STR(_raw_read_lock) },
	{ 0x16a51344, __VMLINUX_SYMBOL_STR(__lock_page) },
	{ 0x339f454b, __VMLINUX_SYMBOL_STR(__lock_buffer) },
	{ 0x1b2f15aa, __VMLINUX_SYMBOL_STR(inc_nlink) },
	{ 0x3a3958d0, __VMLINUX_SYMBOL_STR(block_read_full_page) },
	{ 0x791d5ada, __VMLINUX_SYMBOL_STR(put_zone_device_page) },
	{ 0xd7a86f37, __VMLINUX_SYMBOL_STR(mount_bdev) },
	{ 0x5fabd700, __VMLINUX_SYMBOL_STR(d_add) },
	{ 0x6397804d, __VMLINUX_SYMBOL_STR(generic_read_dir) },
	{ 0x4f346cde, __VMLINUX_SYMBOL_STR(__getblk_gfp) },
	{ 0x85ef3d04, __VMLINUX_SYMBOL_STR(unlock_buffer) },
	{ 0xf1f19936, __VMLINUX_SYMBOL_STR(truncate_setsize) },
	{ 0x147c1a8e, __VMLINUX_SYMBOL_STR(make_kgid) },
	{ 0x9e88526, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xb3a4127e, __VMLINUX_SYMBOL_STR(__insert_inode_hash) },
	{ 0xd3e2c6cc, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0xfb578fc5, __VMLINUX_SYMBOL_STR(memset) },
	{ 0xef45df3d, __VMLINUX_SYMBOL_STR(from_kuid) },
	{ 0xbce27e33, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0xcbb16770, __VMLINUX_SYMBOL_STR(__bread_gfp) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x449ad0a7, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0x7d96cea3, __VMLINUX_SYMBOL_STR(wait_for_completion_interruptible) },
	{ 0xa1c76e0a, __VMLINUX_SYMBOL_STR(_cond_resched) },
	{ 0xc96949b1, __VMLINUX_SYMBOL_STR(from_kgid) },
	{ 0x67649afa, __VMLINUX_SYMBOL_STR(kmem_cache_free) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0xfede80e6, __VMLINUX_SYMBOL_STR(set_nlink) },
	{ 0xe8db8dd2, __VMLINUX_SYMBOL_STR(_raw_write_lock) },
	{ 0xd920be6c, __VMLINUX_SYMBOL_STR(setattr_copy) },
	{ 0x3b3de8c8, __VMLINUX_SYMBOL_STR(page_symlink) },
	{ 0x813d41f5, __VMLINUX_SYMBOL_STR(sync_dirty_buffer) },
	{ 0x7e189e9d, __VMLINUX_SYMBOL_STR(truncate_pagecache) },
	{ 0xe2962303, __VMLINUX_SYMBOL_STR(unlock_page) },
	{ 0x3de8bd58, __VMLINUX_SYMBOL_STR(generic_file_read_iter) },
	{ 0x17d9a1a4, __VMLINUX_SYMBOL_STR(inode_nohighmem) },
	{ 0x28c784a1, __VMLINUX_SYMBOL_STR(__brelse) },
	{ 0xf11543ff, __VMLINUX_SYMBOL_STR(find_first_zero_bit) },
	{ 0x9c1d1f8f, __VMLINUX_SYMBOL_STR(inode_init_once) },
	{ 0x7cd8d75e, __VMLINUX_SYMBOL_STR(page_offset_base) },
	{ 0x47b5dd1f, __VMLINUX_SYMBOL_STR(invalidate_inode_buffers) },
	{ 0x856aa04d, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0xa916b694, __VMLINUX_SYMBOL_STR(strnlen) },
	{ 0xaaab6498, __VMLINUX_SYMBOL_STR(generic_file_mmap) },
	{ 0x85da939d, __VMLINUX_SYMBOL_STR(block_write_full_page) },
	{ 0xdccaa02f, __VMLINUX_SYMBOL_STR(block_write_end) },
	{ 0x45ed0a50, __VMLINUX_SYMBOL_STR(truncate_inode_pages_final) },
	{ 0xd3ba95f0, __VMLINUX_SYMBOL_STR(make_kuid) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xba2d4183, __VMLINUX_SYMBOL_STR(generic_write_end) },
	{ 0xee927cd2, __VMLINUX_SYMBOL_STR(unlock_new_inode) },
	{ 0x8d12cb40, __VMLINUX_SYMBOL_STR(kill_block_super) },
	{ 0x24505d71, __VMLINUX_SYMBOL_STR(inode_newsize_ok) },
	{ 0xf22798c, __VMLINUX_SYMBOL_STR(crypto_destroy_tfm) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0xa95ca4e9, __VMLINUX_SYMBOL_STR(inode_change_ok) },
	{ 0x419a2b83, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xe259ae9e, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xa740206a, __VMLINUX_SYMBOL_STR(kmem_cache_create) },
	{ 0x9add8b61, __VMLINUX_SYMBOL_STR(d_tmpfile) },
	{ 0xe365461e, __VMLINUX_SYMBOL_STR(register_filesystem) },
	{ 0x29ce5a1c, __VMLINUX_SYMBOL_STR(generic_file_write_iter) },
	{ 0xb6244511, __VMLINUX_SYMBOL_STR(sg_init_one) },
	{ 0xbeec20ce, __VMLINUX_SYMBOL_STR(iput) },
	{ 0x6eafa510, __VMLINUX_SYMBOL_STR(read_cache_page) },
	{ 0xa371dda1, __VMLINUX_SYMBOL_STR(generic_file_fsync) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xd8f70052, __VMLINUX_SYMBOL_STR(page_get_link) },
	{ 0xdddb19e0, __VMLINUX_SYMBOL_STR(ihold) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x643e0ce5, __VMLINUX_SYMBOL_STR(call_rcu_sched) },
	{ 0x6128b5fc, __VMLINUX_SYMBOL_STR(__printk_ratelimit) },
	{ 0x9b03b194, __VMLINUX_SYMBOL_STR(sync_filesystem) },
	{ 0xf37df20, __VMLINUX_SYMBOL_STR(block_truncate_page) },
	{ 0xf295f8fa, __VMLINUX_SYMBOL_STR(sb_set_blocksize) },
	{ 0xfae8a86e, __VMLINUX_SYMBOL_STR(generic_readlink) },
	{ 0x2fffe121, __VMLINUX_SYMBOL_STR(__bforget) },
	{ 0x785678c1, __VMLINUX_SYMBOL_STR(d_make_root) },
	{ 0x74c134b9, __VMLINUX_SYMBOL_STR(__sw_hweight32) },
	{ 0x7a4497db, __VMLINUX_SYMBOL_STR(kzfree) },
	{ 0x62f0d91b, __VMLINUX_SYMBOL_STR(__block_write_begin) },
	{ 0x9954e425, __VMLINUX_SYMBOL_STR(mark_buffer_dirty) },
	{ 0x875963a2, __VMLINUX_SYMBOL_STR(unregister_filesystem) },
	{ 0xa384c7a0, __VMLINUX_SYMBOL_STR(write_one_page) },
	{ 0xf266c829, __VMLINUX_SYMBOL_STR(init_special_inode) },
	{ 0xb2d5a552, __VMLINUX_SYMBOL_STR(complete) },
	{ 0x539bb92b, __VMLINUX_SYMBOL_STR(new_inode) },
	{ 0x37c859a, __VMLINUX_SYMBOL_STR(generic_file_splice_read) },
	{ 0x37b25005, __VMLINUX_SYMBOL_STR(clear_inode) },
	{ 0xbdb66d87, __VMLINUX_SYMBOL_STR(d_instantiate) },
	{ 0x9c4e5ef9, __VMLINUX_SYMBOL_STR(__put_page) },
	{ 0x82cbc735, __VMLINUX_SYMBOL_STR(generic_block_bmap) },
	{ 0x875a047b, __VMLINUX_SYMBOL_STR(iget_locked) },
	{ 0x754c8c75, __VMLINUX_SYMBOL_STR(generic_fillattr) },
	{ 0x9f20f320, __VMLINUX_SYMBOL_STR(inode_init_owner) },
	{ 0xe914e41e, __VMLINUX_SYMBOL_STR(strcpy) },
	{ 0xdf929370, __VMLINUX_SYMBOL_STR(fs_overflowgid) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "AAD0076DA4572511618EF93");
