# Linux Driver Introduction

Introductory Linux kernel module examples that build up from a basic loadable module to simple character-device drivers and host-side device discovery.

The repository is organized as numbered lessons. Each directory is intentionally small so one kernel-driver concept can be built, loaded, observed, and removed before moving to the next step.

## Lesson Map

| Directory | Focus |
|-----------|-------|
| `hello_kernel_01/` | Minimal loadable kernel module with init/exit callbacks |
| `hello_kernel_02/` | Module metadata and `__init`/`__exit` annotations |
| `hello_kernel_05/` | First character device using `register_chrdev()` and `.read` |
| `hello_kernel_06/` | Kernel log levels using `printk()` and `pr_*()` helpers |
| `hello_kernel_07/` | Character-device `.open`/`.release` callbacks and file flags |
| `hello_kernel_08/` | Character-device example plus libudev USB device lookup helper |

## Prerequisites

- Linux kernel headers for the running kernel
- Build tools: `make`, `gcc`, and related compiler packages
- Root privileges for loading and removing kernel modules
- `libudev` development headers for `hello_kernel_08/dev_id.c`

On Fedora-like systems, the usual packages are:

```bash
sudo dnf install kernel-devel kernel-headers gcc make systemd-devel
```

## Build Pattern

Each lesson with a kernel module uses the kernel build system from its own directory:

```bash
make
sudo insmod module_name.ko
dmesg -w
sudo rmmod module_name
make clean
```

Replace `module_name` with the generated module for that lesson, such as `hello`, `hello_cdev`, or `log_level`.

## Character Device Notes

The character-device examples use `register_chrdev(0, ...)`, which asks the kernel to allocate a dynamic major number. After loading the module, read the assigned major number from `dmesg`, then create a matching device node if the lesson requires direct user-space access:

```bash
sudo mknod /tmp/hello0 c <major> 0
sudo chmod 666 /tmp/hello0
```

Remove temporary nodes when done:

```bash
rm /tmp/hello0
```

## Safety

These examples run in kernel space. A bug can crash the machine or require a reboot, so build and test them on a development system or VM. Always remove a loaded module before rebuilding or switching lessons.

## Helper Commands

`commands.sh` is a quick-reference command sheet, not a script intended to be executed directly.
