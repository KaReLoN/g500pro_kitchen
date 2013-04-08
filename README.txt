*****************************************************************************************

This kitchen is prepared to build a kernel for the Huawei G500 Pro phone.

These tools must be installed before you proceed:
- bash
- perl
- make
- gzip
- lzop
- tar
- cpio
- readelf
- may be something else


Useful scripts can be found in the directory android/u8836d/kernel/scripts
NOTE! All scripts in this directory are tested when they are called inside the directory they placed.

Remember to adjust parameters in script android/u8836d/kernel/scripts/environment.sh accordingly to your installation.

Typical use case consists of next steps:
- Make some changes into source code
- Run script custom_kernel_make.sh in android/u8836d/kernel/scripts
- If previous step was successful run script custom_kernel_pack.sh in android/u8836d/kernel/scripts
- Get packed CWM patch in android/u8836d/kernel/packages


Have a nice job with the kitchen!



-- 
Best regards, 
Aleksei Ilin.

*****************************************************************************************
