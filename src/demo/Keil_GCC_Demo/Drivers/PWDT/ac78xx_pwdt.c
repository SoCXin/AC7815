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
/**
*
* @file     ac78xx_pwdt.c
*
* @author   Autochips
*
* @version  0.0.1
*
* @date     March 24, 2016
*
* @brief    Pulse Width Timer (PWDT) source code.
*
*/
#include "ac78xx_pwdt.h"

PWDT_CallbackType PWDT_Callback[1] = {(PWDT_CallbackType)NULL}; /*!< PWDT initial callback */
/**
*
* @param[in] none
*
* @return none
*
* @brief Enable PWDT module.
*
*/
void PWDT_EnableModule(void)
{
    CKGEN_Enable(CLK_PWDT, 1);
    CKGEN_SoftReset(SRST_PWDT, 1);
}
/**
*
* @param[in] none
*
* @return none
*
* @brief Disable PWDT module.
*
*/
void PWDT_DisableModule(void)
{
    CKGEN_Enable(CLK_PWDT, 0);
    CKGEN_SoftReset(SRST_PWDT, 0);
}
/**
*
* @param[in] pwdtConfig: point to configuration
*
* @return 0 0:Success
*
* @brief initialize PWDT module.
*
*/
int32_t PWDT_Init(PWDT_ConfigType *pwdtConfig)
{
    PWDT_EnableModule();
    if (PWDT_GetOverflowFlag())
    {
        PWDT_ClrOverflowFlag();
    }

    if (PWDT_GetReadyFlag())
    {
        PWDT_ClrReadyFlag();
    }

    if (pwdtConfig->pwdtIntEn)
    {
        PWDT_EnableInt();
        NVIC_EnableIRQ(PWDT_IRQn);
    }
    else
    {
        PWDT_DisableInt();
        NVIC_DisableIRQ(PWDT_IRQn);
    }

    if (pwdtConfig->overflowIntEn)
    {
        PWDT_EnableOverFlowInt();
    }

    if (pwdtConfig->readyIntEn)
    {
        PWDT_EnableReadyInt();
    }

    if (pwdtConfig->pwdtTimerEn)
    {
        PWDT_SetTimerValue(pwdtConfig->pwdtTimerValue);
        PWDT_EnableTimer();
    }
    if (pwdtConfig->pwdtFilterEn)
    {
        PWDT_SetFilterValue(pwdtConfig->pwdtFilterPsc, pwdtConfig->pwdtFilterValue);
        PWDT_FilterEnable();
    }
    if (pwdtConfig->pwdtHallEn)
    {
        PWDT_EnableHall();
    }
    if (pwdtConfig->compEn)
    {
        PWDT_EnableCompMode();
    }
    PWDT_SetClockPreScaler(pwdtConfig->clockPreScaler);
    PWDT_SetEdgeMode(pwdtConfig->edgeMode);
    PWDT_SetPinSelect(pwdtConfig->pinSelect);

    if (pwdtConfig->clockSource)
    {
        PWDT_SetClockSource(pwdtConfig->clockSource);
    }

    if (pwdtConfig->pwdtEn)
    {
        PWDT_Enable();
    }
    return 0;
}


/**
*
* @param[in] pwdtCallback: point to call back.
*
* @return none
*
* @brief PWDT module set call back.
*
*/
void PWDT_SetCallback(PWDT_CallbackType pwdtCallback)
{
    PWDT_Callback[0] = pwdtCallback;
}
/**
*
* @param[in] none
*
* @return none
*
* @brief PWDT module de-initialize, reset PWDT register
*
*/
int32_t PWDT_DeInit(void)
{
    PWDT_ClrOverflowFlag();
    PWDT_ClrReadyFlag();
    NVIC_DisableIRQ(PWDT_IRQn);
    PWDT_DisableInt();
    PWDT_DisableReadyInt();
    PWDT_DisableOverFlowInt();
    PWDT_SetClockSource(0);
    PWDT_SetEdgeMode(0);
    PWDT_SetSoftReset();
    PWDT_Disable();

    while ((PWDT->INIT0 & PWDT_INIT0_PWDTEN_Msk));
    PWDT_DisableModule();
    return 0;
}
/**
*
* @param[in] none
*
* @return none
*
* @brief PWDT module isr.
*
*/
void PWDT_IRQHandler(void)
{

    if (PWDT_Callback[0])
    {
        PWDT_Callback[0]();
    }
}
