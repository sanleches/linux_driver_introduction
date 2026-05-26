# hello_kernel_05 - Basic Character Device

This lesson introduces a minimal character-device driver. The module registers a device name with the kernel and implements a `.read` callback through `struct file_operations`.

## Concepts

| Concept | Purpose |
|---------|---------|
| `register_chrdev(0, ...)` | Allocate a dynamic major number |
| `struct file_operations` | Connect VFS operations to driver callbacks |
| `.read` | Handle user-space reads from the device node |
| `unregister_chrdev()` | Release the major number during module unload |

## Build and Run

```bash
make
sudo insmod hello_cdev.ko
dmesg
```

The module prints the assigned major number. Create a node with that number:

```bash
sudo mknod /tmp/hello0 c <major> 0
sudo cat /tmp/hello0
```

Clean up when finished:

```bash
sudo rmmod hello_cdev
rm /tmp/hello0
make clean
```

## Notes

The `.read` callback returns `0`, which tells user space that the device has reached end-of-file. The lesson is focused on callback registration, not data transfer yet.
