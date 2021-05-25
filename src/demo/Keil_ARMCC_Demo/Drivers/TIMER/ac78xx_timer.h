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
/*****************************************************************************
*
* @file     ac78xx_timer.h
*
* @author   Autochips
*
* @version  0.0.1
*
* @date     March 23, 2016
*
* @brief    Periodic Interrupt TIMERer (TIMER) driver head file.
*
******************************************************************************/
#ifndef AC78xx_TIMER_H_
#define AC78xx_TIMER_H_
#ifdef __cplusplus
extern "C" {
#endif
#include "ac78xx_timer_reg.h"
#include "ac78xx.h"

#define TIMER_NUM    8
typedef void (*TIMER_CallbackType)(uint8_t arg);             ///< TIMER callback type
///< TIMER initial callback
static TIMER_CallbackType s_timerCallback[8] = {(TIMER_CallbackType)NULL};
///< TIMER  index map table
static const TIMER_Type * const s_timerCtrlMap[TIMER_NUM] = {TIMER0, TIMER1, TIMER2, TIMER3, TIMER4, TIMER5, TIMER6, TIMER7};
///< TIMER  interrupt  map table
static const uint8_t s_timerIrqnCtrlMap[TIMER_NUM] = {TIMER0_IRQn, TIMER1_IRQn, TIMER2_IRQn, TIMER3_IRQn, TIMER4_IRQn, TIMER5_IRQn, TIMER6_IRQn, TIMER7_IRQn};

typedef struct
{
    uint8_t timerEn        : 1;    ///< 1: channel TIMERer is enable, 0: channel TIMERer is disable
    uint8_t interruptEn    : 1;    ///< 1: channel TIMERer interrupt is enable, 0: channel TIMERer interrupt is disable
    uint8_t linkMode       : 1;    ///< 1: chain mode is enable, 0: chain mode is disable
    uint32_t loadValue     : 32;   ///< 32-bit channel load value
} TIMER_ConfigType;


TIMER_Type* TIMER_GetTimerCtrl(uint8_t timIndex);
void TIMER_ModuleEnable(void);
void TIMER_ModuleDisable(void);
int32_t TIMER_Init(TIMER_Type *TIMx, TIMER_ConfigType *timConfig);
void TIMER_SetLoadVal(TIMER_Type *TIMx, uint32_t loadValue);
uint8_t TIMER_GetIntFlag(TIMER_Type *TIMx);
void TIMER_ClrIntFlag(TIMER_Type *TIMx);
void TIMER_SetCallback(TIMER_Type *TIMx, TIMER_CallbackType timeCallback);
int32_t TIMER_DeInit(TIMER_Type *TIMx);
void TIMER0_IRQHandler(void);
void TIMER1_IRQHandler(void);
void TIMER2_IRQHandler(void);
void TIMER3_IRQHandler(void);
void TIMER4_IRQHandler(void);
void TIMER5_IRQHandler(void);
void TIMER6_IRQHandler(void);
void TIMER7_IRQHandler(void);
#ifdef __cplusplus
}
#endif
#endif /* TIMER_H_ */
