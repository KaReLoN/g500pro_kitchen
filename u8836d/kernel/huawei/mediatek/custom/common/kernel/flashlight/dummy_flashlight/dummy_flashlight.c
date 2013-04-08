/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/wait.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/poll.h>
#include <linux/device.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/cdev.h>
#include <linux/errno.h>
#include <linux/time.h>
#include "kd_flashlight.h"
#include <asm/io.h>
#include <asm/uaccess.h>
//#include <mach/mt6516_typedefs.h>
//#include <mach/mt6516_gpt_sw.h>

/******************************************************************************
 * Definition
******************************************************************************/
/* device name and major number */
#define STROBE_DEVNAME            "leds_strobe"

#define DELAY_MS(ms) {mdelay(ms);}//unit: ms(10^-3)
#define DELAY_US(us) {mdelay(us);}//unit: us(10^-6)
#define DELAY_NS(ns) {mdelay(ns);}//unit: ns(10^-9)

/******************************************************************************
 * Debug configuration
******************************************************************************/
#define PFX "[LEDS_STROBE]"
#define PK_DBG_NONE(fmt, arg...)    do {} while (0)
#define PK_DBG_FUNC(fmt, arg...)    printk(KERN_INFO PFX "%s: " fmt, __FUNCTION__ ,##arg)

#define PK_WARN(fmt, arg...)        printk(KERN_WARNING PFX "%s: " fmt, __FUNCTION__ ,##arg)
#define PK_NOTICE(fmt, arg...)      printk(KERN_NOTICE PFX "%s: " fmt, __FUNCTION__ ,##arg)
#define PK_INFO(fmt, arg...)        printk(KERN_INFO PFX "%s: " fmt, __FUNCTION__ ,##arg)
#define PK_TRC_FUNC(f)              printk(PFX "<%s>\n", __FUNCTION__);
#define PK_TRC_VERBOSE(fmt, arg...) printk(PFX fmt, ##arg)

//#define DEBUG_LEDS_STROBE
#ifdef DEBUG_LEDS_STROBE
#define PK_DBG PK_DBG_FUNC
#define PK_TRC PK_DBG_NONE //PK_TRC_FUNC
#define PK_VER PK_DBG_NONE //PK_TRC_VERBOSE
#define IH_DBG PK_DBG_NONE
#define PK_ERR(fmt, arg...)         printk(KERN_ERR PFX "%s: " fmt, __FUNCTION__ ,##arg)
#else
#define PK_DBG(a,...)
#define PK_TRC(a,...)
#define PK_VER(a,...)
#define IH_DBG(a,...)
#define PK_ERR(a,...)
#endif

#if 0
/*******************************************************************************
* structure & enumeration
*******************************************************************************/
struct strobe_data{
    spinlock_t lock;
    wait_queue_head_t read_wait;
    struct semaphore sem;
};

/******************************************************************************
 * local variables
******************************************************************************/
static struct class *strobe_class = NULL;
static struct device *strobe_device = NULL;
static struct strobe_data strobe_private;
static dev_t strobe_devno;
static struct cdev strobe_cdev;
//static BOOL g_strobe_On = FALSE;
#endif
/*****************************************************************************
User interface
*****************************************************************************/
static int dummy_flashlight_ioctl(MUINT32 cmd, MUINT32 arg)
{
    int i4RetValue = 0;
    int iFlashType = (int)FLASHLIGHT_NONE;
    
    switch(cmd)
    {
        case FLASHLIGHTIOC_G_FLASHTYPE:
            iFlashType = FLASHLIGHT_NONE;
            if (0 != arg) {
            if(copy_to_user((void __user *) arg , (void*)&iFlashType , _IOC_SIZE(cmd)))
            {
                PK_DBG("[strobe_ioctl] ioctl copy to user failed\n");
                    i4RetValue = -EFAULT;
                }
            }
            else {
                i4RetValue = -EPERM;
            }
            break;
            
    	default :
    		PK_DBG("ERROR Cmd ID \n");
    		//i4RetValue = -EPERM;
    		break;
    }
    return i4RetValue;
}

static int dummy_flashlight_open(void *pArg)
{
    return 0;
}
 
static int dummy_flashlight_release(void *pArg)
{
    return 0;
}

FLASHLIGHT_FUNCTION_STRUCT	dummyFlashlightFunc=
{
	dummy_flashlight_open,
	dummy_flashlight_release,
	dummy_flashlight_ioctl
};

MUINT32 dummyFlashlightInit(PFLASHLIGHT_FUNCTION_STRUCT *pfFunc) { 
    if (pfFunc!=NULL) {
        *pfFunc=&dummyFlashlightFunc;
    }
    return 0;
}


/* LED flash control for high current capture mode*/
ssize_t strobe_VDIrq(void)
{
    return 0;
}

EXPORT_SYMBOL(strobe_VDIrq);

#if 0
static int strobe_open(struct inode *inode, struct file *file)
{
    return 0;
}

static int strobe_release(struct inode *inode, struct file *file)
{
    return 0;
}

/*****************************************************************************/
/* Kernel interface */
static struct file_operations strobe_fops = {
    .owner      = THIS_MODULE,
    .ioctl      = strobe_ioctl,
    .open       = strobe_open,
    .release    = strobe_release,
};

/*****************************************************************************
Driver interface
*****************************************************************************/
#define ALLOC_DEVNO
static int strobe_probe(struct platform_device *dev)
{
    int ret = 0, err = 0;

#ifdef ALLOC_DEVNO
    ret = alloc_chrdev_region(&strobe_devno, 0, 1, STROBE_DEVNAME);
    if (ret) {
        PK_ERR("alloc_chrdev_region fail: %d\n", ret);
        goto strobe_probe_error;
    } else {
        PK_DBG("major: %d, minor: %d\n", MAJOR(strobe_devno), MINOR(strobe_devno));
    }
    cdev_init(&strobe_cdev, &strobe_fops);
    strobe_cdev.owner = THIS_MODULE;
    err = cdev_add(&strobe_cdev, strobe_devno, 1);
    if (err) {
        PK_ERR("cdev_add fail: %d\n", err);
        goto strobe_probe_error;
    }
#else
    #define STROBE_MAJOR 242
    ret = register_chrdev(STROBE_MAJOR, STROBE_DEVNAME, &strobe_fops);
    if (ret != 0) {
        PK_ERR("Unable to register chardev on major=%d (%d)\n", STROBE_MAJOR, ret);
        return ret;
    }
    strobe_devno = MKDEV(STROBE_MAJOR, 0);
#endif


    strobe_class = class_create(THIS_MODULE, "strobedrv");
    if (IS_ERR(strobe_class)) {
        PK_ERR("Unable to create class, err = %d\n", (int)PTR_ERR(strobe_class));
        goto strobe_probe_error;
    }

    strobe_device = device_create(strobe_class, NULL, strobe_devno, NULL, STROBE_DEVNAME);
    if(NULL == strobe_device){
        PK_ERR("device_create fail\n");
        goto strobe_probe_error;
    }

    /*initialize members*/
    spin_lock_init(&strobe_private.lock);
    init_waitqueue_head(&strobe_private.read_wait);
    init_MUTEX(&strobe_private.sem);

    //LED On Status
//    g_strobe_On = FALSE;

    return 0;

strobe_probe_error:
#ifdef ALLOC_DEVNO
    if (err == 0)
        cdev_del(&strobe_cdev);
    if (ret == 0)
        unregister_chrdev_region(strobe_devno, 1);
#else
    if (ret == 0)
        unregister_chrdev(MAJOR(strobe_devno), STROBE_DEVNAME);
#endif
    return -1;
}

static int strobe_remove(struct platform_device *dev)
{
#ifdef ALLOC_DEVNO
    cdev_del(&strobe_cdev);
    unregister_chrdev_region(strobe_devno, 1);
#else
    unregister_chrdev(MAJOR(strobe_devno), STROBE_DEVNAME);
#endif
    device_destroy(strobe_class, strobe_devno);
    class_destroy(strobe_class);

    //LED On Status
 //   g_strobe_On = FALSE;
    return 0;
}


static struct platform_driver strobe_platform_driver =
{
    .probe      = strobe_probe,
    .remove     = strobe_remove,
    .driver     = {
        .name = STROBE_DEVNAME,
		.owner	= THIS_MODULE,
    },
};

static struct platform_device strobe_platform_device = {
    .name = STROBE_DEVNAME,
    .id = 0,
    .dev = {
    }
};

static int __init strobe_init(void)
{
    int ret = 0;

	ret = platform_device_register (&strobe_platform_device);
	if (ret) {
        PK_ERR("platform_device_register fail\n");
        return ret;
	}

    ret = platform_driver_register(&strobe_platform_driver);
	if(ret){
		PK_ERR("platform_driver_register fail\n");
		return ret;
	}
    return ret;
}

static void __exit strobe_exit(void)
{
    platform_driver_unregister(&strobe_platform_driver);
}

/*****************************************************************************/
module_init(strobe_init);
module_exit(strobe_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jackie Su <jackie.su@mediatek.com>");
MODULE_DESCRIPTION("LED strobe control Driver");

/* LED flash control for capture mode*/
ssize_t strobe_StillExpCfgStart(void)
{
    return 0;
}

ssize_t strobe_StillExpEndIrqCbf(void)
{
    return 0;
}

EXPORT_SYMBOL(strobe_StillExpCfgStart);
EXPORT_SYMBOL(strobe_StillExpEndIrqCbf);
#endif

