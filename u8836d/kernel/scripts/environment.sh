#!/bin/bash


CUR_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

export ROOT_KERNEL_KITCHEN=/android

export ARCH=arm 




# Compiler
#export CROSS_COMPILE="$ROOT_KERNEL_KITCHEN/android-ndk-r8d/toolchains/arm-linux-androideabi-4.6/prebuilt/linux-x86/bin/arm-linux-androideabi-"
#export CROSS_COMPILE=/android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.7/prebuilt/linux-x86/bin/arm-linux-androideabi-
export CROSS_COMPILE=/android/android-ndk-r8e/toolchains/arm-linux-androideabi-4.7/prebuilt/linux-x86/bin/arm-linux-androideabi-


export PROJECT=huaqin77_cu_ics2

export CONFIG_INITRAMFS_SOURCE="$CUR_DIR/../prepared/boot.img-ramdisk"


#export PATH="$PATH:$ROOT_KERNEL_KITCHEN/tools:$ROOT_KERNEL_KITCHEN/android-ndk-r8d"
export PATH="$PATH:$ROOT_KERNEL_KITCHEN/tools"

#export CONFIG_DEBUG_SECTION_MISMATCH=y
