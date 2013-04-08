#!/bin/bash


source ./environment.sh

ln -s ../huawei/mediatek/custom/$PROJECT/common/partition_define.h ../huawei/mediatek/platform/mt6577/kernel/drivers/dum-char/partition_define.h
ln -s ../huawei/mediatek/custom/$PROJECT/common/partition_define.h ../huawei/mediatek/platform/mt6577/kernel/drivers/mmc-host/partition_define.h
ln -s ../huawei/mediatek/custom/$PROJECT/common/partition_define.h ../huawei/mediatek/platform/mt6577/kernel/drivers/nand/partition_define.h

ln -s ../huawei/mediatek/custom/$PROJECT/common/pmt.h ../huawei/mediatek/platform/mt6577/kernel/drivers/dum-char/pmt.h

cp ../huawei/mediatek/custom/precompiled/hwe/mtk_hwe_init.o ../huawei/mediatek/platform/mt6577/kernel/drivers/hwe/prebuilt/mtk_hwe_init.o
cp ../huawei/mediatek/custom/precompiled/mdrvb/sec_drvb.o ../huawei/mediatek/platform/mt6577/kernel/drivers/mdrvb/prebuilt/sec_drvb.o

cd ../huawei/kernel/

cp .config ../mediatek/config/out/$PROJECT/autoconfig/kconfig

make -j3


