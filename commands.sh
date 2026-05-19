insmod module_name.ko #Insert module into the kernel
lsmod #List modules
lsmod | grep module_name #Check if module is loaded
rmmod module_name #Remove module
dmesg #Check kernel messages for module loading/unloading
modinfo module_name.ko #Get information about the module
dmesg -w #Watch kernel messages in real-time
rmmod module_name #Force remove module (-f) if it is in use
modprobe module_name #Load module and its dependencies // must be in /lib/modules/$(uname -r)/kernel/
modprobe -r module_name #Remove module and its dependencies



udevadm info -q property hidraw14 #Get information about a specific device (replace hidraw14 with your device) (can match vendor and product ID )
ls -lh /dev/hidraw* #List hidraw devices with details
hexdump -C /dev/hidraw14 #Dump raw data from the device (replace hidraw14 with your device)
#udevadm monitor --udev #Monitor udev events in real-time 

 sudo mknod hello0 c 236 0 # create a new nod file that links to a major device Number


dmesg -W
dmesg -WT #formatted
dmesg -l 1-7 #what level or message want to see