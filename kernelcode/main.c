#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("PAWAN");
MODULE_DESCRIPTION("A simple hello world program");
static int __init hello_init(void)
{
	printk(KERN_INFO"Hello World!\n");
	return 0;
}
 
static void __exit hello_cleanup(void)
{
	printk(KERN_INFO"Good BYe!\n");
}
module_init(hello_init);
module_exit(hello_cleanup);