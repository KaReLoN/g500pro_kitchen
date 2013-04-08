#!/bin/bash

USE_RD_LZO=1

source ./environment.sh

CURDATE=`date +%Y-%m-%d_%H-%M`

# copy kernel config

cp ../huawei/kernel/.config ../packages/_CONFIGS/kconfig-$CURDATE

# pack kernel

cp ../huawei/kernel/arch/arm/boot/zImage ../prepared/

../huawei/mediatek/build/tools/mkimage ../prepared/zImage KERNEL > ../prepared/boot_headered.img

cd ../prepared

if [[ $USE_RD_LZO -eq 1 ]]; then
    repack-MT65xx_lzo.pl -boot boot_headered.img boot.img-ramdisk boot_new.img > packer.log 2>&1
else
    repack-MT65xx.pl -boot boot_headered.img boot.img-ramdisk boot_new.img > packer.log 2>&1
fi



cat packer.log

# copy modules

echo "Searching modules..."

SPACE=" "
MODULES_LIST=`find ../huawei/kernel -name  "*.ko" -print`
MODULES_LIST=${MODULES_LIST}${SPACE}`find ../huawei/mediatek/custom/out -name  "*.ko" -print`
MODULES_LIST=${MODULES_LIST}${SPACE}`find ../huawei/mediatek/platform -name  "*.ko" -print`
MODULES_LIST=${MODULES_LIST}${SPACE}`find ../huawei/mediatek/source -name  "*.ko" -print`

rm -Rf ../prepared/built_modules
mkdir -p ../prepared/built_modules

echo "Copying modules..."

for MODULE in $MODULES_LIST
do
#    echo Copying module $MODULE
    cp $MODULE ../prepared/built_modules/
done

cd ../prepared/built_modules/

cd ../../scripts/

# check for unresolved externals in original proprietary modules

echo "Creating import/export reports..."

bash ./check_original_modules_import.sh

echo "Packing into CWM archives..."

# create patch CWM package

PACKAGES_DIR=../packages
cd $PACKAGES_DIR


# with original And built modules
rm -Rf _tmp
cp -R _TEMPLATE _tmp
cp ../prepared/boot_new.img _tmp/boot.img
cp ../prepared/built_modules/*.ko _tmp/system/lib/modules/
cp ../prepared/original_modules/used/*.ko _tmp/system/lib/modules/


MODULES_LIST=`find _tmp/system/lib/modules -name  "*.ko" -print`
echo "Stripping debug symbols from modules..."

for MODULE in $MODULES_LIST
do
    strip -g -S -d --strip-unneeded -x -I elf32-littlearm -O elf32-littlearm $MODULE
done

cd _tmp
zip -qr _tmp.zip *
mv _tmp.zip ../boot_new_$CURDATE.zip
cd ..


echo 
echo "Packing finished."




