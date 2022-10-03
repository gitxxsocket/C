TF-A
for p in `ls -1 ../*.patch`; do patch -p1 < $p; done //打补丁
https://github.com/STMicroelectronics/stm32wrapper4dbg   make   stm32wrapper4dbg -s
sudo apt-get install device-tree-compiler
Makefile.sdk    CROSS_COMPILE，将其改为“arm-none-linux-gnueabihf-”，    make -f ../Makefile.sdk all
https://wiki.st.com/stm32mpu/wiki/STM32CubeProgrammer_flashlayout     flashlayout     tf-a.tsv
boot_api_context_t 结构体是定义在 TF-A 源码里面的(plat/st/stm32mp1/include/boot_api.h
https://my.st.com/content/my_st_com/en/products/embedded-software/mcu-mpu-embedded-software/stm32-embedded-software/stm32-mpu-openstlinux-distribution/stm32mp1dev.html
#Opt	Id	Name	Type	Device	Offset	Binary
-	0x01	fsbl1-boot	Binary	none	0x0	tf-a-stm32mp157d-atk-serialboot.stm32
-	0x03	ssbl-boot	Binary	none	0x0	u-boot.stm32
P	0x04	fsbl1	Binary	mmc1	boot1	tf-a-stm32mp157d-atk-trusted.stm32
P	0x05	fsbl2	Binary	mmc1	boot2	tf-a-stm32mp157d-atk-trusted.stm32
P	0x06	ssbl	Binary	mmc1	0x00080000	u-boot.stm32
bl1：Boot loader stage 1 (BL1)。
bl2：Boot loader stage 2 (BL2)。
bl31：Boot loader stage 3-1 (BL31)。
bl32：Boot loader stage 3-2 (BL32)。
bl33：Boot loader stage 3-3 (BL33)。
bl1→ bl2→( bl31/ bl32/ bl33)
make -f ../Makefile.sdk all 


UBoot
make distclean
make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- stm32mp157d_atk_defconfig
make V=1 ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- DEVICE_TREE=stm32mp157d-atk all


setenv bootdelay 5
saveenv

setenv author 'console=ttySTM0,11520 root=/dev/mmcblk2p2 rootwait rw '
saveenv

setenv bootcmd 'tftp c2000000 uImage;tftp c4000000 stm32mp157d-atk.dtb;bootm c2000000 -
c4000000'
saveenv
boot










setenv ipaddr 192.168.1.250
setenv ethaddr b8:ae:1d:01:01:00
setenv gatewayip 192.168.1.1
setenv netmask 255.255.255.0
setenv serverip 192.168.1.249
saveenv
