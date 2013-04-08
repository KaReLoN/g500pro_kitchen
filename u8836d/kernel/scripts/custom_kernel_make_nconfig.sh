#!/bin/bash

source ./environment.sh

cd ../huawei/kernel/

make nconfig

#cat ../../scripts/config_append.txt >> .config

cp .config ../mediatek/config/out/$PROJECT/autoconfig/kconfig


