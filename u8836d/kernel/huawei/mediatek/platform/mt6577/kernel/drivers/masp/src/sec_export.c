#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>


/*
    These prototypes are fake. This is only a compiler workaround.
    We need it because the actual functions are proprietary and their prototypes too.
    Do not use these prototypes for any purposes!
*/


void sec_ccci_is_cipherfmt();
EXPORT_SYMBOL(sec_ccci_is_cipherfmt);

void sec_ccci_version_info();
EXPORT_SYMBOL(sec_ccci_version_info);

void SST_Secure_DeInit();
EXPORT_SYMBOL(SST_Secure_DeInit);

void SST_Secure_Algo();
EXPORT_SYMBOL(SST_Secure_Algo);

void sec_ccci_signfmt_verify_file();
EXPORT_SYMBOL(sec_ccci_signfmt_verify_file);

void sec_boot_init();
EXPORT_SYMBOL(sec_boot_init);

void sec_emmc_project();
EXPORT_SYMBOL(sec_emmc_project);

void sec_ccci_decrypt_cipherfmt();
EXPORT_SYMBOL(sec_ccci_decrypt_cipherfmt);

void SST_Secure_Init();
EXPORT_SYMBOL(SST_Secure_Init);



