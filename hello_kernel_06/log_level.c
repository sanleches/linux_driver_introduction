#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

static int __init my_Init(void){

    printk(KERN_INFO "log_level - This is info\n");
    printk(KERN_WARNING "log_level - This is a Warning\n");
    printk(KERN_ALERT "log_level - This is an Alert\n");
    printk(KERN_DEBUG "log_level - Debug Message %d\n", 42);

    return 0;
}

static void __exit my_Exit(void){

    pr_emerg("log_level - Module is unloaded\n");
    pr_err("log_level - Error\n");
    pr_info("log_level - the last info...");
}

module_init(my_Init);
module_exit(my_Exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Santiago Ugarte");
MODULE_DESCRIPTION(" Basic loglevel kernel module. ");