#include <linux/module.h>
#include <linux/init.h>

int helloInit(void){
    
    printk("hello - This is my hello printed line to the kernel! \n");
    return 0;
}

void helloExit(void){

    printk("hello - Goddbye Kernel. ZzZz \n");
}

module_init(helloInit);
module_exit(helloExit);

MODULE_LICENSE("GPL");