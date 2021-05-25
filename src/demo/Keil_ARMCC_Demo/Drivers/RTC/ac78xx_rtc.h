/* Copyright Statement:
 *
 * This software/firmware and related documentation ("AutoChips Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to AutoChips Inc. and/or its licensors. Without
 * the prior written permission of AutoChips inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of AutoChips Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * AutoChips Inc. (C) 2016. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("AUTOCHIPS SOFTWARE")
 * RECEIVED FROM AUTOCHIPS AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. AUTOCHIPS EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES AUTOCHIPS PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE AUTOCHIPS SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN AUTOCHIPS
 * SOFTWARE. AUTOCHIPS SHALL ALSO NOT BE RESPONSIBLE FOR ANY AUTOCHIPS SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND AUTOCHIPS'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE AUTOCHIPS SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT AUTOCHIPS'S OPTION, TO REVISE OR REPLACE THE
 * AUTOCHIPS SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO AUTOCHIPS FOR SUCH AUTOCHIPS SOFTWARE AT ISSUE.
 */

#ifndef _AC78XX_RTC_H_
#define _AC78XX_RTC_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "ac78xx_rtc_reg.h"

typedef int32_t (*RTC_EventCallback)(uint32_t wparam, uint32_t lparam );
typedef int32_t (*BKP_EventCallback)(uint32_t wparam, uint32_t lparam );
typedef struct
{
    uint32_t RTCOut                     : 1;    ///< 1: RTCO pin is enable, 0: RTCO pin is disable
    uint32_t interruptEn                : 1;    ///< 1: RTC interrupt is enable, 0: RTC interrupt is disable
    uint32_t interruptFlag              : 1;    ///< 1: RTC flag is set, 0: RTC flag is not set, write 1 to clr
    uint32_t clockSource                : 2;    ///< 0: Bus clk; 1: Real time 32KHz; 2: External OSC; 3:Internal 8M;
    uint32_t prescalerInterruptEn       : 1;    ///< 0: RTC interrupt is disable; 1: RTC interrupt is enable
    uint32_t prescalerInterruptFlag     : 1;    ///< 0: RTC flag is not set; 1: RTC flag is set 
    uint32_t reserved                   : 25;   ///< reserved */ 
    uint32_t moduloValue;                       ///< 32-bit rtc modulo value
    uint32_t prescalerValue;                    ///< 32-bit rtc Prescaler value 
} RTC_ConfigType, *RTC_ConfigPtr;               ///< RTC Config structure

int32_t RTC_Initialize(RTC_ConfigType *rtcConfig);
int32_t RTC_Uninitialize(void);
int32_t RTC_SetEventCallback(RTC_EventCallback callback);
int32_t BKP_SetEventCallback(BKP_EventCallback callback);

#ifdef __cplusplus
}
#endif

#endif
