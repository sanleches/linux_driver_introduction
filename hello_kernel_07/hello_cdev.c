/*
 * =============================================================================
 * hello_kernel_07 - Character Device Open/Release Callbacks
 * =============================================================================
 *
 * Registers a character device and prints metadata from each open call. The
 * companion test program opens the device with different flag combinations so
 * the driver can show how those flags arrive in struct file.
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

static int my_open (struct inode *inode, struct file *filp) {

    pr_info("hello_cdev - Major: %d, Minor %d\n", imajor(inode), iminor(inode));

    pr_info("hello_cdev - filp->f_pos: %lld\n", filp->f_pos);
    pr_info("hello_cdev - filp->f_mode: 0x%x\n", filp->f_mode);
    pr_info("hello_cdev - filp->f_flags: 0x%x\n", filp->f_flags);

    return 0;
}

static int my_release (struct inode *inode, struct file *filp) {

    pr_info("hello_cdev - File is closed\n");

    return 0;
}

static struct file_operations fops = {
    .open = my_open,
    .release = my_release
};

// -----------------------------------------------------------------------------
// Module Lifecycle
// -----------------------------------------------------------------------------

static int __init my_Init(void){

    // Passing major 0 asks the kernel to allocate an available major number.
    major = register_chrdev(0, "hello_cdev", &fops);
    if(major < 0) { //if its major than 0 an error occurred while registering the device
        pr_err("hello_cdev - Error registering chrdev\n");
        return major;
    }
    pr_info("hello_cdev - Major device Number: %d\n", major);

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
