/*
 * A stub for some debug functions called by prebuilt proprietary modules
 *
 *
 */

#include <linux/i2c.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/version.h>
#include <linux/tty_driver.h>
#include <asm/atomic.h>
#include <linux/rwlock_types.h>
#include <linux/kprobes.h>

#ifndef CONFIG_DEBUG_SPINLOCK

void __raw_spin_lock_init(raw_spinlock_t *lock, const char *name, struct lock_class_key *key)
{
	lock->raw_lock = (arch_spinlock_t)__ARCH_SPIN_LOCK_UNLOCKED;
}
EXPORT_SYMBOL(__raw_spin_lock_init);


void __rwlock_init(rwlock_t *lock, const char *name, struct lock_class_key *key)
{
	lock->raw_lock = (arch_rwlock_t) __ARCH_RW_LOCK_UNLOCKED;
}
EXPORT_SYMBOL(__rwlock_init);

#endif



/*

  Workaround for Mediatek CCCI.KO module (prepared for 3.4.5 kernel)

*/
#if (LINUX_VERSION_CODE > KERNEL_VERSION(3,0,13))
struct tty_driver *alloc_tty_driver(int lines);
{
    return __alloc_tty_driver(lines, NULL);
}
EXPORT_SYMBOL(alloc_tty_driver);
#endif

static int __init debug_stub_init(void)
{
    return 0;
}

static void __exit debug_stub_exit(void)
{

}

module_init(debug_stub_init);
module_exit(debug_stub_exit);

MODULE_DESCRIPTION("Debug stub driver");
MODULE_AUTHOR("Aleksei Ilin <dencorpos@gmail.com>");
MODULE_LICENSE("GPL");


