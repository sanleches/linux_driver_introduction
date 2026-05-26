/*
 * =============================================================================
 * hello_kernel_08 - Basic Character Device Driver
 * =============================================================================
 *
 * Keeps the simple read-only character-device example alongside the libudev
 * helper in dev_id.c. The kernel portion still demonstrates dynamic major
 * allocation and file operation registration.
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

// -----------------------------------------------------------------------------
// Internal State
// -----------------------------------------------------------------------------

static int major;

// -----------------------------------------------------------------------------
// Character Device Operations
// -----------------------------------------------------------------------------

static ssize_t my_read(struct file *flip, char __user *buf, size_t count, loff_t *f_pos) {
    printk("hello_cdev - Read is called\n");
    return 0;
}

static struct file_operations fops = {
    .read = my_read
};

// -----------------------------------------------------------------------------
// Module Lifecycle
// -----------------------------------------------------------------------------

static int __init my_Init(void){

    // Passing major 0 asks the kernel to allocate an available major number.
    major = register_chrdev(0, "hello_cdev", &fops);
    if(major < 0) { //if its major than 0 an error occurred while registering the device
        printk("hello_cdev - Error registering chrdev\n");
        return major;
    }
    printk("hello_cdev - Major device Number: %d\n", major);

    return 0;
}

static void __exit my_Exit(void){

    unregister_chrdev(major, "hello_cdev");
}

// -----------------------------------------------------------------------------
// Kernel Module Declaration
// -----------------------------------------------------------------------------

module_init(my_Init);
module_exit(my_Exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Santiago Ugarte");
MODULE_DESCRIPTION(" Basic cdev kernel module. ");
