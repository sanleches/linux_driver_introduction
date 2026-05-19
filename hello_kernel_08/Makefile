obj-m += hello_cdev.o

.PHONY: all clean

all:
		make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

dev_id: dev_id.c
		$(CC) -Wall -Wextra -pedantic $< -o $@ -ludev

clean:
		make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
		$(RM) dev_id
