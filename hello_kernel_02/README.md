# hello_kernel_02 - Module Metadata

This lesson builds on `hello_kernel_01` by adding normal kernel-module annotations and metadata.

## Concepts

| Concept | Purpose |
|---------|---------|
| `static` init/exit callbacks | Keep module entry points private to this file |
| `__init` | Marks initialization code that can be freed after loading |
| `__exit` | Marks cleanup code used when unloading the module |
| `MODULE_AUTHOR()` | Exposes author metadata through `modinfo` |
| `MODULE_DESCRIPTION()` | Exposes a short module summary through `modinfo` |

## Build and Run

```bash
make
sudo insmod hello.ko
modinfo hello.ko
dmesg -w
sudo rmmod hello
make clean
```

## Notes

`modinfo hello.ko` reads metadata from the built module file. The kernel log still comes from `printk()` calls inside the init and exit callbacks.
