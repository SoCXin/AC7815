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

#include "ac78xx_rtc.h"
#include "ac78xx.h"

RTC_EventCallback g_RTCCallback[1] = {(RTC_EventCallback)NULL}; ///< RTC initial callback
BKP_EventCallback g_BKPCallback[1] = {(BKP_EventCallback)NULL}; ///< BKP initial callback

/**
* RTC_Initialize
*
* @param[in] RTCConfig: RTC configuration structure pointer
* @return 0: success, other: error value
*
* @brief  Initialize RTC module
*/
int32_t RTC_Initialize(RTC_ConfigType *RTCConfig)
{
    CKGEN_Enable(CLK_RTC, 1);
    CKGEN_SoftReset(SRST_RTC, 1);

    RTC_SetRTCO(RTCConfig->RTCOut);
    RTC_SetModulo(RTCConfig->moduloValue);

    if (RTCConfig->interruptEn)
    {
        NVIC_EnableIRQ(RTC_IRQn);
        RTC_EnableRTIE();
    }
    else
    {
        NVIC_DisableIRQ(RTC_IRQn);
        RTC_DisableRTIE();
    }
    if (RTCConfig->prescalerInterruptEn)
    {
        RTC_EnableRPIE();
    }
    else
    {
        RTC_DisableRPIE();
    }

    if (RTC_GetRTIF())
    {
        RTC_ClrRTIF();
    }
    if (RTC_GetRPIF())
    {
        RTC_ClrRPIF();
    }
    RTC_SetClkSource(RTCConfig->clockSource);
    RTC_SetPres(RTCConfig->prescalerValue);
    return 0;
}

/**
* RTC_Uninitialize
*
* @param[in] none
* @return 0: success, other: error value
*
* @brief  Uninitialize RTC module
*/
int32_t RTC_Uninitialize(void)
{
    NVIC_DisableIRQ(RTC_IRQn);
    CKGEN_Enable(CLK_RTC, 0);

    return 0;
}

/**
* RTC_SetEventCallback
*
* @param[in] callback£ºRTC callback function pointer
* @return 0: success, other: error value
*
* @brief  Set RTC callback function
*/
int32_t RTC_SetEventCallback(RTC_EventCallback callback)
{
    g_RTCCallback[0] = callback;

    return 0;
}

/**
* RTC_IRQHandler
*
* @param[in]  none
* @return none
*
* @brief  override the RTC_IRQHandler
*/
void RTC_IRQHandler(void)
{
    RTC_ClrRTIF();
    RTC_ClrRPIF();
    if (g_RTCCallback[0])
    {
        g_RTCCallback[0](0, 0);
    }
}

/**
* BKP_SetEventCallback
*
* @param[in]  callback£ºBKP callback type pointer
* @return 0: success, other: error value
*
* @brief  Set BKP callback function
*/
int32_t BKP_SetEventCallback(BKP_EventCallback callback)
{
    g_BKPCallback[0] = callback;

    return 0;
}

/**
* BKP_IRQHandler
*
* @param[in]  none
* @return none
*
* @brief  override the BKP_IRQHandler
*/
void BKP_IRQHandler(void)
{
    if (g_BKPCallback[0])
    {
        g_BKPCallback[0](BKP_IsTIF(), BKP_IsTEF());
    }
    BKP_ClrTIF();
    BKP_ClrTEF();
}
