# hello_kernel_01 - Minimal Kernel Module

This lesson introduces the smallest useful loadable kernel module in the repository. It registers one function to run when the module is inserted and one function to run when the module is removed.

## Concepts

| Concept | Where |
|---------|-------|
| `module_init()` | Registers the load callback |
| `module_exit()` | Registers the unload callback |
| `printk()` | Writes messages to the kernel log |
| `MODULE_LICENSE()` | Declares the module license to the kernel |

## Build and Run

```bash
make
sudo insmod hello.ko
dmesg -w
sudo rmmod hello
make clean
```

## Expected Log Messages

Loading prints a hello message. Removing the module prints the goodbye message.

This first lesson intentionally avoids metadata and `__init`/`__exit` annotations so the callback wiring is easy to see.
