# Linux Driver Introduction - Command Reference
#
# This file is a copy/paste command sheet, not a script intended to be run from
# top to bottom. Replace placeholders such as `module_name`, `hidraw14`, and the
# major device number with values from the lesson you are testing.

# -----------------------------------------------------------------------------
# Kernel Module Lifecycle
# -----------------------------------------------------------------------------

insmod module_name.ko          # Insert a module directly into the kernel
lsmod                         # List loaded kernel modules
lsmod | grep module_name      # Check whether a module is loaded
rmmod module_name             # Remove a loaded module
modinfo module_name.ko        # Show module metadata

# modprobe resolves dependencies, but the module must be installed under
# /lib/modules/$(uname -r)/ before the command can find it.
modprobe module_name          # Load a module and its dependencies
modprobe -r module_name       # Remove a module and its dependencies

# -----------------------------------------------------------------------------
# Kernel Log Inspection
# -----------------------------------------------------------------------------

dmesg                         # Print current kernel messages
dmesg -w                      # Watch kernel messages in real time
dmesg -W                      # Wait for and print new messages
dmesg -WT                     # Print human-readable timestamps
dmesg -l 1-7                  # Filter by kernel log levels

# -----------------------------------------------------------------------------
# Character Device Nodes
# -----------------------------------------------------------------------------

# Create a device node for a character device. Use the major number printed by
# the module at load time and the minor expected by the lesson.
sudo mknod hello0 c 236 0

# -----------------------------------------------------------------------------
# HID and udev Inspection
# -----------------------------------------------------------------------------

udevadm info -q property hidraw14  # Inspect one hidraw device
ls -lh /dev/hidraw*               # List hidraw devices
hexdump -C /dev/hidraw14          # Dump raw bytes from one hidraw device
# udevadm monitor --udev          # Watch udev events in real time
