/*
 * =============================================================================
 * hello_kernel_01 - Minimal Loadable Kernel Module
 * =============================================================================
 *
 * This first lesson shows the two required lifecycle hooks for a kernel module:
 * one function runs when the module is inserted, and one function runs when the
 * module is removed.
 */

#include <linux/module.h>
#include <linux/init.h>

// -----------------------------------------------------------------------------
// Module Lifecycle
// -----------------------------------------------------------------------------

int helloInit(void){

    printk("hello - This is my hello printed line to the kernel! \n");
    return 0;
}

void helloExit(void){

    printk("hello - Goddbye Kernel. ZzZz \n");
}

// -----------------------------------------------------------------------------
// Kernel Module Declaration
// -----------------------------------------------------------------------------

module_init(helloInit);
module_exit(helloExit);

MODULE_LICENSE("GPL");
