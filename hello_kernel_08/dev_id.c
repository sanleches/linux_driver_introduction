//
// Created by santiago on 5/18/26.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysmacros.h>
#include <sys/types.h>
#include <libudev.h>

#define VENDOR_ID   "6666"
#define PRODUCT_ID  "0001"
#define REVISION_ID "0100"

int main() {
    struct udev *udev = udev_new();
    if (!udev) {
        fprintf(stderr, "Can't create udev context\n");
        return 1;
    }

    // Create a scan enumerator
    struct udev_enumerate *enumerate = udev_enumerate_new(udev);
    // Filter specifically for the USB subsystem to speed up the scan
    udev_enumerate_add_match_subsystem(enumerate, "usb");
    udev_enumerate_scan_devices(enumerate);

    struct udev_list_entry *devices = udev_enumerate_get_list_entry(enumerate);
    struct udev_list_entry *entry;

    // Iterate through all matched USB devices
    udev_list_entry_foreach(entry, devices){
        const char *path = udev_list_entry_get_name(entry);
        struct udev_device *dev = udev_device_new_from_syspath(udev, path);

        // Get the core USB identification attributes
        const char *idVendor  = udev_device_get_sysattr_value(dev, "idVendor");
        const char *idProduct = udev_device_get_sysattr_value(dev, "idProduct");
        const char *bcdDevice = udev_device_get_sysattr_value(dev, "bcdDevice"); // Revision
        const char *idUsbModel = udev_device_get_property_value(dev, "ID_USB_MODEL");

        // Check if this matches your custom hardware (6666:0001 rev 0100)
        if (idVendor && strcmp(idVendor, VENDOR_ID) == 0 &&
            idProduct && strcmp(idProduct, PRODUCT_ID) == 0 &&
            bcdDevice && strcmp(bcdDevice, REVISION_ID) == 0) {

            printf("Target Custom Hardware Found!\n");
            printf("  Syspath:  %s\n", path);
            printf("  ID_USB_MODEL: %s\n", idUsbModel ? idUsbModel : "(none)");

            const char *devnode = udev_device_get_devnode(dev);
            printf("  Devnode:  %s\n", devnode ? devnode : "(none)");

            if (devnode) {
                dev_t devnum = udev_device_get_devnum(dev);
                printf("  Major:    %u\n", major(devnum));
                printf("  Minor:    %u\n", minor(devnum));
            } else {
                printf("  Major:    (none)\n");
                printf("  Minor:    (none)\n");
            }

            // Driver module info
            const char *driver = udev_device_get_driver(dev);
            printf("  Driver Bound: %s\n", driver ? driver : "(none - unbound)");

            udev_device_unref(dev);
            break;
            }
        udev_device_unref(dev);
    }

    udev_enumerate_unref(enumerate);
    udev_unref(udev);
    return 0;
}
