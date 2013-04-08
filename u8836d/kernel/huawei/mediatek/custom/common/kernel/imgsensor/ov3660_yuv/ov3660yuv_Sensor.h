/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
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

/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   sensor.h
 *
 * Project:
 * --------
 *   DUMA
 *
 * Description:
 * ------------
 *   CMOS sensor header file
 *
 ****************************************************************************/
#ifndef __SENSOR_H
#define __SENSOR_H



#include "image_sensor.h"//get IMAGE_SENSOR_DRVNAME
#define IMAGE_SENSOR_DRVNAME SENSOR_DRVNAME_OV3660_YUV

    //------------------------Engineer mode---------------------------------
#define FACTORY_START_ADDR 	0
#define ENGINEER_START_ADDR	10

    typedef enum group_enum {
       PRE_GAIN=0,
	   CMMCLK_CURRENT,
	   FRAME_RATE_LIMITATION,
	   REGISTER_EDITOR,
	   GROUP_TOTAL_NUMS
    } FACTORY_REGISTER_INDEX;

    typedef enum register_index {
        SENSOR_BASEGAIN=FACTORY_START_ADDR,
	      PRE_GAIN_R_INDEX,
	      PRE_GAIN_Gr_INDEX,
	      PRE_GAIN_Gb_INDEX,
	      PRE_GAIN_B_INDEX,
	      FACTORY_END_ADDR
    } CCT_REGISTER_INDEX;
    
 typedef enum engineer_index
{   
	CMMCLK_CURRENT_INDEX=ENGINEER_START_ADDR,
	ENGINEER_END
} FACTORY_ENGINEER_INDEX; 

    //------------------------Engineer mode---------------------------------
    typedef struct {
        SENSOR_REG_STRUCT Reg[ENGINEER_END];
        SENSOR_REG_STRUCT CCT[FACTORY_END_ADDR];
    } SENSOR_DATA_STRUCT,*PSENSOR_DATA_STRUCT;



	
 #define CAM_PREVIEW_30FPS
 #define SYSTEM_CLK                           (52*1000*1000)
		/* PIXEL CLOCK USED BY BANDING FILTER CACULATION*/
#if defined(CAM_PREVIEW_15FPS)
  #define PIXEL_CLK							    (SYSTEM_CLK/8)		// 52/8 MHz
#elif defined(CAM_PREVIEW_22FPS)
   #define PIXEL_CLK							    (SYSTEM_CLK/6)		// 52/6 MHz
#elif defined(CAM_PREVIEW_30FPS)
   #define PIXEL_CLK 						      	(SYSTEM_CLK/4)		// 52/4 MHz
#endif

   #define OV3660_VIDEO_NORMALMODE_FRAME_RATE							30		// Limitation for MPEG4 Encode Only
   #define OV3660_VIDEO_NIGHTMODE_FRAME_RATE							15
	/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
	#define VGA_PERIOD_PIXEL_NUMS					784
	#define VGA_PERIOD_LINE_NUMS					510

	/* SENSOR EXPOSURE LINE LIMITATION */
	#define VGA_EXPOSURE_LIMITATION					510

	/* SENSOR GLOBAL GAIN AT NIGHT MODE */
	#define OV3660_SENSOR_NIGHT_MODE_GAIN					0x08	// Please refer to OV7670 Implementation Guide
	
	/* SENSOR VGA SIZE */
	#define IMAGE_SENSOR_VGA_WIDTH					(1024-8)
	#define IMAGE_SENSOR_VGA_HEIGHT					(768-6)

	//#define __PREVIEW_SIZE_VGA__

#ifdef __PREVIEW_SIZE_VGA__
	#define IMAGE_SENSOR_PV_WIDTH					(640-8)
	#define IMAGE_SENSOR_PV_HEIGHT					(480-6)
#else
	#define IMAGE_SENSOR_PV_WIDTH					(1024-8)
	#define IMAGE_SENSOR_PV_HEIGHT					(768-6)
#endif

    #define IMAGE_SENSOR_FULL_WIDTH          		(2048-8) 
    #define IMAGE_SENSOR_FULL_HEIGHT         		(1536-6) 


    /* SENSOR EXPOSURE LINE LIMITATION */
    #define OV3660_FULL_EXPOSURE_LIMITATION    (1564)
    #define OV3660_PV_EXPOSURE_LIMITATION      (782)

	/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
	#define OV3660_FULL_PERIOD_PIXEL_NUMS    (2300) 	//   (OV3660_IMAGE_SENSOR_FULL_HACTIVE + OV3660_IMAGE_SENSOR_FULL_HBLANKING) /* 2376, must be even */
	#define OV3660_FULL_PERIOD_LINE_NUMS     (1564)   //   (OV3660_IMAGE_SENSOR_FULL_VACTIVE + OV3660_IMAGE_SENSOR_FULL_VBLANKING) /* 1568 */
	#define OV3660_PV_PERIOD_PIXEL_NUMS        (1150)  	//(OV3660_IMAGE_SENSOR_PV_HACTIVE + OV3660_IMAGE_SENSOR_PV_HBLANKING) /* 2376, must be even */
	#define OV3660_PV_PERIOD_LINE_NUMS           (768)    //(OV3660_IMAGE_SENSOR_PV_VACTIVE + OV3660_IMAGE_SENSOR_PV_VBLANKING) /* 792 */

	/* SENSOR START/END POSITION */
	#define OV3660_FULL_X_START                  16 /* avoid left rectangle image color abnormal */
	#define OV3660_FULL_Y_START                  12
	#define OV3660_PV_X_START                    8 //0	//((OV3660_FULL_X_START * OV3660_IMAGE_SENSOR_PV_WIDTH_DRV / OV3660_IMAGE_SENSOR_FULL_WIDTH_DRV)&0xFFFC)
	#define OV3660_PV_Y_START                    6  //0 //   1
	#define OV3660_IMAGE_SENSOR_PV_WIDTH        (1024) // (OV3660_IMAGE_SENSOR_PV_WIDTH_DRV - OV3660_PV_X_START)
	#define OV3660_IMAGE_SENSOR_PV_HEIGHT       (768) //(OV3660_IMAGE_SENSOR_PV_HEIGHT_DRV - 2) /* -2 for frame ready done */
	#define OV3660_IMAGE_SENSOR_FULL_WIDTH      (2048)// (OV3660_IMAGE_SENSOR_FULL_WIDTH_DRV - OV3660_FULL_X_START)
	#define OV3660_IMAGE_SENSOR_FULL_HEIGHT     (1536) //(OV3660_IMAGE_SENSOR_FULL_HEIGHT_DRV - 6)
 
	#define OV3660_DEFUALT_XGA_PIXEL_NUMS			(2030)
	#define OV3660_DEFULAT_XGA_LINE_NUMS			(788)
	#define OV3660_DEFUALT_QXGA_PIXEL_NUMS			(2300)
	#define OV3660_DEFULAT_QXGA_LINE_NUMS			(1668)
	
	/* SETUP TIME NEED TO BE INSERTED */
	#define IMAGE_SENSOR_VGA_INSERTED_PIXELS		128
	#define IMAGE_SENSOR_VGA_INSERTED_LINES		    17
	
	#define OV3660_WRITE_ID								0x78
	#define OV3660_READ_ID								0x79
	
//  #define OV3660_SENSOR_ID    (0x7673)  

struct OV3660_Sensor_Struct
{
	MSDK_SENSOR_CONFIG_STRUCT cfg_data;

	kal_uint32 Sensor_ID;
	
	kal_bool bIsCapture;
	kal_bool bVideoMode;
	
	kal_uint32 PV_PCLK;
	kal_uint32 CP_PCLK;
	
	kal_uint16 PV_Dummy_Pixels;
	kal_uint16 PV_Dummy_Lines;
	kal_uint16 CP_Dummy_Pixels;
	kal_uint16 CP_Dummy_Lines;
	kal_uint32 PV_Pixels_Per_Line;
	kal_uint32 PV_Lines_Per_Frame;
	kal_uint32 CP_Pixels_Per_Line;
	kal_uint32 CP_Lines_Per_Frame;
	
	kal_uint16 ExtraExposureLines;
	kal_uint16 ExposureLines;

	kal_bool AE_Enable;
	kal_bool AG_Enable;
	
	kal_uint32 PV_Gain;
	kal_uint32 PV_Shutter;
	kal_uint32 CP_Gain;
	kal_uint32 CP_Shutter;


	kal_bool bNight_mode;
	kal_uint8 u8WbValue; 
	kal_uint8 u8EffectValue;
	kal_uint8 u8EvValue;
	kal_uint8 u8BandValue;
	kal_uint8 Zoom_Factor;

};




#endif /* __SENSOR_H */ 
