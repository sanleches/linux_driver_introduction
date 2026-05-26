# hello_kernel_06 - Kernel Log Levels

This lesson demonstrates common kernel log severities and the difference between explicit `printk()` levels and the `pr_*()` helper macros.

## Concepts

| Concept | Purpose |
|---------|---------|
| `KERN_INFO` | Informational messages |
| `KERN_WARNING` | Warning messages |
| `KERN_ALERT` | High-priority alert messages |
| `KERN_DEBUG` | Debug-level messages |
| `pr_emerg()`, `pr_err()`, `pr_info()` | Convenience wrappers around `printk()` |

## Build and Run

```bash
make
sudo insmod log_level.ko
dmesg -l 1-7
sudo rmmod log_level
make clean
```

## Notes

Whether debug messages appear depends on the kernel log configuration and current console log level. `dmesg` usually shows the full ring buffer even when the console does not display every severity.
