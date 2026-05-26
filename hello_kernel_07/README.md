# hello_kernel_07 - Open and Release Callbacks

This lesson extends the character-device example by handling `.open` and `.release`. The included `test.c` program opens the device with different flag combinations so the driver can print the resulting `struct file` state.

## Concepts

| Concept | Purpose |
|---------|---------|
| `.open` | Called when user space opens the device node |
| `.release` | Called when user space closes the file descriptor |
| `imajor()` / `iminor()` | Read major/minor numbers from the inode |
| `filp->f_pos` | Current file offset |
| `filp->f_mode` | Access mode requested by user space |
| `filp->f_flags` | Open flags such as `O_SYNC` or `O_NONBLOCK` |

## Build and Run

Build and load the module:

```bash
make
sudo insmod hello_cdev.ko
dmesg
```

Create the device node using the major number printed by the module:

```bash
sudo mknod /tmp/hello0 c <major> 0
sudo chmod 666 /tmp/hello0
```

Build and run the user-space test helper:

```bash
gcc -Wall -Wextra -pedantic test.c -o test
./test /tmp/hello0
```

Clean up:

```bash
sudo rmmod hello_cdev
rm /tmp/hello0
make clean
```

## Notes

The driver does not transfer data in this lesson. Its purpose is to show when open/close callbacks fire and what metadata the kernel passes into them.
