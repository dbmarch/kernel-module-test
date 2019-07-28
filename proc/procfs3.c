#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h>   
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#define BUFSIZE  100
static char buf [BUFSIZE];
 
#define procfs_name "hello"
 
MODULE_LICENSE("GPL");
 
static struct proc_dir_entry *ent;
 
static ssize_t mywrite(struct file *file, const char __user *ubuf,size_t count, loff_t *ppos) 
{
    int c;
	printk( KERN_DEBUG "hello - write handler\n");
	if(*ppos > 0 || count > BUFSIZE)
		return -EFAULT;
	if(copy_from_user(buf,ubuf,count))
		return -EFAULT;
	c = strlen(buf);
	*ppos = c;
	return c;
}
 
static ssize_t myread(struct file *file, char __user *ubuf,size_t count, loff_t *ppos) 
{
    int len = count;
    if (len > BUFSIZE ) 
       len = BUFSIZE;
	printk( KERN_DEBUG "read handler count=%d\n", (int) count);
	if(copy_to_user(ubuf,buf, len))
		return -EFAULT;
	*ppos = len;
	return len;
}
 
static struct file_operations myops = 
{
	.owner = THIS_MODULE,
	.read = myread,
	.write = mywrite,
};
 
static int simple_init(void)
{
    memset (buf, 0, sizeof(buf));
    strcpy (buf, "hello!");
	ent=proc_create(procfs_name,0666,NULL,&myops);
	return 0;
}
 
static void simple_cleanup(void)
{
	proc_remove(ent);
}
 
module_init(simple_init);
module_exit(simple_cleanup);
