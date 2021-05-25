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

#ifndef AC78XX_WDOG_H_
#define AC78XX_WDOG_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "ac78xx_wdg_reg.h"

///< wparam and lparam are reserved for user's callback function
typedef int32_t (*WDOG_EventCallback)(uint32_t wparam, uint32_t lparam);

typedef struct {
    struct {
        uint32_t    stopEnable     : 1;    ///< enable watchdog in stop mode
        uint32_t    waitEnable     : 1;    ///< enable watchdog in wait mode
        uint32_t    updateEnable   : 1;    ///< enable update of watchdog control
        uint32_t    intEnable      : 1;    ///< watchdog interrupt enable
        uint32_t    enableWDOG     : 1;    ///< enable watchdog
        uint32_t    clkSource      : 2;    ///< watchdog clock source selection
        uint32_t    prescaler      : 1;    ///< prescaler
        uint32_t    interruptFlag  : 1;    ///< watchdog interrupt flag
        uint32_t    winEnable      : 1;    ///< enable watchdog window mode
    } control;
    uint32_t    timeout;                   ///< watchdog timeout value
    uint32_t    winTimeout;                ///< watchdog window timeout value
} WDOG_ConfigType, *WDOG_ConfigPtr;

int32_t WDOG_Initialize(WDOG_ConfigType *config);
int32_t WDOG_Uninitialize(void);
void WDOG_Feed(void);
void WDOG_Unlock(void);
int32_t WDOG_SetEventCallback(WDOG_EventCallback callback );

#ifdef __cplusplus
}
#endif

#endif
