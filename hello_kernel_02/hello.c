/*
 * =============================================================================
 * hello_kernel_02 - Kernel Module Metadata
 * =============================================================================
 *
 * Adds normal module annotations and metadata to the minimal hello module.
 * `__init` marks setup code that can be discarded after loading; `__exit` marks
 * cleanup code used when the module is unloaded.
 */

#include <linux/module.h>
#include <linux/init.h>

// -----------------------------------------------------------------------------
// Module Lifecycle
// -----------------------------------------------------------------------------

static int __init helloInit(void){

    printk("hello - This is my hello printed line to the kernel! \n");
    return 0;
}

static void __exit helloExit(void){

    printk("hello - Goddbye Kernel. ZzZz \n");
}

// -----------------------------------------------------------------------------
// Kernel Module Declaration
// -----------------------------------------------------------------------------

module_init(helloInit);
module_exit(helloExit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Santiago Ugarte - santiago.ugarte98@gmail.com");
MODULE_DESCRIPTION(" Basic hello world kernel module. ");
