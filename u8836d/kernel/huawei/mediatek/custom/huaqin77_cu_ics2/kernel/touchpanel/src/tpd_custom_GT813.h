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

#ifndef TOUCHPANEL_H__
#define TOUCHPANEL_H__

/* Pre-defined definition */
#define TPD_TYPE_CAPACITIVE
#define TPD_TYPE_RESISTIVE
#define TPD_POWER_SOURCE         MT6575_POWER_VGP2
#define TPD_I2C_NUMBER           0
#define TPD_WAKEUP_TRIAL         60
#define TPD_WAKEUP_DELAY         100

#define TPD_DELAY                (2*HZ/100)
//#define TPD_RES_X                480
//#define TPD_RES_Y                800
#define TPD_CALIBRATION_MATRIX  {962,0,0,0,1600,0,0,0};

#define TPD_HAVE_CALIBRATION
#define TPD_HAVE_TREMBLE_ELIMINATION

#define TPD_NO_GPIO
#define TPD_RESET_PIN_ADDR   (PERICFG_BASE + 0xC000)
#define TPD_DITO_SENSOR
#define TPD_CONDITION_SWITCH
#define TPD_RESET_ISSUE_WORKAROUND
#define TPD_MAX_RESET_COUNT 3
#define TPD_X_RES (540)
#define TPD_Y_RES (960)
#define TPD_WARP_Y(y) ( y )
#define TPD_WARP_X(x) ( x )

#define TPD_MAX_POINTS 5

#define TPD_HAVE_BUTTON
#define TPD_BUTTON_HEIGHT	480
#define TPD_KEY_COUNT           3
#define TPD_KEYS                { KEY_BACK, KEY_HOME, KEY_MENU}
#define TPD_KEYS_DIM            {{40,505,80,50},{120,505,80,50},{200,505,80,50}}



/* truly ctp id:0x00*/
static u8 cfg_data_version_TRULY[]=
{
/* high waterproof */
0x15,0x06,0x14,0x05,0x13,0x04,0x12,0x03,0x11,0x02,
0x1A,0x0B,0x19,0x0A,0x18,0x09,0x17,0x08,0x16,0x07,
0xFF,0xFF,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,
0x03,0x0D,0x04,0x0E,0x05,0x0F,0x06,0x10,0x07,0x11,
0x08,0x12,0xFF,0x0D,0x0E,0x0F,0xFF,0x11,0x12,0x13,
0x0F,0x03,0x88,0x88,0x88,0x28,0x00,0x00,0x08,0x00,
0x00,0x0E,0x5A,
0x35, //0x35
0x2D, // 0x2D
0x03,0x00,0x05,0x00,0x02,
0x1C,0x03,0xC0,0x5A,0x5A,0x50,0x50,0x1F,0x00,0x17,
0x19,0x65,0x14,0x10,0x00,0x05,0x01,0x07,0x13,0x36,
0x52, //0x52
0x00,
0x70, // 0x40
0x30, // 0x30
0x20,
0x14,
0x00,
0x00, // 0x00
0x00, // 0x00
0x14, // 0x22
0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x01
};

/* o-flim ctp id:0x01*/
static u8 * cfg_data_version_OFG = cfg_data_version_TRULY;
/*static u8 cfg_data_version_OFG[]=
{
0x15,0x06,0x14,0x05,0x13,0x04,0x12,0x03,0x11,0x02,
0x1A,0x0B,0x19,0x0A,0x18,0x09,0x17,0x08,0x16,0x07,
0xFF,0xFF,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,
0x03,0x0D,0x04,0x0E,0x05,0x0F,0x06,0x10,0x07,0x11,
0x08,0x12,0xFF,0x0D,0x0E,0x0F,0xFF,0x11,0x12,0x13,
0x0F,0x03,0x88,0x88,0x88,0x28,0x00,0x00,0x08,0x00,
0x00,0x0E,0x5A,0x35,0x2D,0x03,0x00,0x05,0x00,0x02,
0x1C,0x03,0xC0,0x5A,0x5A,0x50,0x50,0x1F,0x00,0x17,
0x19,0x65,0x14,0x10,0x00,0x05,0x01,0x07,0x13,0x36,
0x52,0x00,0x40,0x30,0x20,0x14,0x00,0x00,0x00,0x22,
0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x01
};*/

#endif /* TOUCHPANEL_H__ */

