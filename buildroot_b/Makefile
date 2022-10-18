KERNELDIR := /home/book/Desktop/st_source/linux-stm32mp-5.4.31-r0/linux-5.4.31
CURRENT_PATH := $(shell pwd)
ENV:=ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf-
obj-m := chrdevbase.o

build: kernel_modules

kernel_modules:
	$(MAKE) $(ENV) -C $(KERNELDIR) M=$(CURRENT_PATH) modules
clean:
	$(MAKE) $(ENV) -C $(KERNELDIR) M=$(CURRENT_PATH) clean