# hello_kernel_08 - Character Device and USB Lookup Helper

This lesson keeps the basic character-device driver and adds `dev_id.c`, a user-space libudev helper that searches for a USB device by vendor ID, product ID, and revision.

## Kernel Module Concepts

| Concept | Purpose |
|---------|---------|
| `register_chrdev(0, ...)` | Allocate a dynamic character-device major number |
| `.read` | Observe reads from a device node |
| `unregister_chrdev()` | Release the device registration on unload |

## User-Space Helper Concepts

| Concept | Purpose |
|---------|---------|
| `udev_new()` | Create a libudev context |
| `udev_enumerate_add_match_subsystem()` | Limit enumeration to USB devices |
| `idVendor`, `idProduct`, `bcdDevice` | Match USB device identity attributes |
| `udev_device_get_devnode()` | Read the device node path, if one exists |
| `udev_device_get_driver()` | Show the currently bound kernel driver |

## Build and Run the Kernel Module

```bash
make
sudo insmod hello_cdev.ko
dmesg
sudo rmmod hello_cdev
make clean
```

## Build and Run the USB Helper

```bash
make dev_id
./dev_id
```

The helper currently searches for USB device `6666:0001` with revision `0100`. Keep those constants in sync with the USB firmware or hardware under test.

## Notes

`dev_id` is a normal user-space executable, not a kernel module. It uses libudev to inspect devices already known to the Linux device model.
