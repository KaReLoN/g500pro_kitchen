#!/bin/bash

source ./environment.sh

OLD_PWD=`pwd`

cd ../prepared
cp ../original/boot.img ./

unpack-MT65xx.pl boot.img > unpacker.log 2>&1

cat unpacker.log



cd "$OLD_PWD"

