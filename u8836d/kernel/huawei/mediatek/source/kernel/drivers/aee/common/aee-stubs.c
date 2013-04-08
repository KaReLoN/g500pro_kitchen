#include <linux/module.h>
#include <linux/slab.h>
#include <linux/aee.h>
#include <linux/xlog.h>


void aee_trigger_kdb(void)
{
}

void aee_wdt_irq_info(void)
{
}

struct aee_oops *aee_oops_create(AE_DEFECT_ATTR attr, AE_EXP_CLASS clazz, const char *module)
{
    return 0;
}
EXPORT_SYMBOL(aee_oops_create);

void aee_oops_free(struct aee_oops *oops)
{
}
EXPORT_SYMBOL(aee_oops_free);

int aee_register_api(struct aee_kernel_api *aee_api)
{
    return 0;
}
EXPORT_SYMBOL(aee_register_api);

void aee_kernel_exception_api(const char *file, const int line, const char *module, const char *msg, ...)
{
}
EXPORT_SYMBOL(aee_kernel_exception_api);

void aee_kernel_warning_api(const char *file, const int line, const char *module, const char *msg, ...)
{
}
EXPORT_SYMBOL(aee_kernel_warning_api);

void aee_kernel_reminding_api(const char *file, const int line, const char *module, const char *msg, ...)
{
}
EXPORT_SYMBOL(aee_kernel_reminding_api);

void aed_md_exception1(const int *log, int log_size, const int *phy, int phy_size, const char *assert_type, const char *exp_filename, 
			unsigned int exp_linenum, unsigned int fatal1, unsigned int fatal2)
{
}
EXPORT_SYMBOL(aed_md_exception1);

void aed_md_exception2(const int *log, int log_size, const int *phy, int phy_size, const char* detail)
{
}
EXPORT_SYMBOL(aed_md_exception2);

void aee_sram_printk(const char *fmt, ...)
{
}
EXPORT_SYMBOL(aee_sram_printk);








