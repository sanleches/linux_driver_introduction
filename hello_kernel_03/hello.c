#include <linux/module.h>
#include <linux/init.h>

static int __init helloInit(void){
    
    printk("hello - This is my hello printed line to the kernel! \n");
    return 0;
}

static void __exit helloExit(void){

    printk("hello - Goddbye Kernel. ZzZz \n");
}

module_init(helloInit);
module_exit(helloExit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Santiago Ugarte - santiago.ugarte98@gmail.com");
MODULE_DESCRIPTION(" Basic hello world kernel module. ");