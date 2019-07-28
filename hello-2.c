
/*  
 *  hello-1.c - The simplest kernel module.
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h>
#define DRIVER_AUTHOR   "Dave <dbmarch@gmail.com>"
#define DRIVER_DESC     "Test module"

static int __init hello_2_init(void)
{
	printk(KERN_INFO "Hello world 1.\n");

	/* 
	 * A non 0 return means init_module failed; module can't be loaded. 
	 */
	return 0;
}

static void __exit hello_2_exit(void)
{
	printk(KERN_INFO "Goodbye world 1.\n");
}



module_init(hello_2_init);
module_exit(hello_2_exit);

MODULE_LICENSE("GPL");

MODULE_AUTHOR(DRIVER_AUTHOR);

MODULE_DESCRIPTION (DRIVER_DESC);

MODULE_SUPPORTED_DEVICE("testdevice");