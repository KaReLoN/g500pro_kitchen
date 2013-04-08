#obj-y				+= aee-common.o aed-process.o


obj-$(CONFIG_MTK_AEE_AED)				+= aee-common.o aed-process.o

ifeq ($(CONFIG_MTK_AEE_AED),)
obj-y							+= aee-stubs.o
endif