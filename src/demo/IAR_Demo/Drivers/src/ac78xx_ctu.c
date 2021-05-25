
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

/*******************************************************************************
*
* @file ac78xx_ctu.c
*
* @author AutoChips
*
* @version 0.0.1
*
* @date March.16.2016
*
* @brief providing APIs for configuring ctu.
*
*******************************************************************************/
#include "ac78xx_ctu.h"
/**
 * @param[in] none
 *
 * @return none
 *
 * @brief CTU module enable
 */
void CTU_ModuleEnable(void)
{
    ///<Enable CTU Clock
    CKGEN_Enable(CLK_CTU_APB, 1);
    CKGEN_SoftReset(SRST_CTU, 1);

}
/**
 * @param[in] none
 *
 * @return none
 *
 * @brief CTU module disnable
 */
void CTU_ModuleDisable(void)
{
    ///<Disable CTU Clock
    CKGEN_SoftReset(SRST_CTU, 0);
    CKGEN_Enable(CLK_CTU_APB, 0);
}
/**
 * @param[in] ctuConfig: CTU config type pointer
 *
 * @return 0:Success
 *
 * @brief CTU module initialize
 */
int32_t CTU_Init(CTUConfig_Type *ctuConfig)
{
    if (ctuConfig->acmpTrig)
    {
        CTU_SelAcmp1AsPwm2Trigger0();
    }
    else
    {
        CTU_SelAcmp0AsPwm2Trigger0();
    }
    if (ctuConfig->rtcCapture)
    {
        CTU_EnableRtcCaptureByPwm1Ch1();
    }
    if (ctuConfig->acmpCapture)
    {
        CTU_EnableAcmp0InputCaptureByPwm1Ch0();
    }
    if (ctuConfig->uartRxCapture)
    {
        CTU_EnableUart1RxdConnectToPwm0Ch1();
    }
    if (ctuConfig->pwmSync)
    {
        CTU_GenerateSoftwareTrig2Pwm2();
    }
    if (ctuConfig->uartTxModulate)
    {
        CTU_EnableUart1ModulationByPwm0Ch0();
    }
    if (ctuConfig->acmpCaptureByPwdt)
    {
        CTU_SetPwdtIn3InputFromAcmp0();
    }
    else
    {
        CTU_SetPwdtIn3InputFromAcmp1();
    }

    CTU_SetPwdtIn3InputSource(ctuConfig->uartRxCaptureByPwdt);
    CTU_TriggerAdcInjectGroupSource(ctuConfig->adcInjectHardwareTrig);
    CTU_SetUart1FilterSource(ctuConfig->uartRxFilter);
    CTU_TriggerAdcRegularGroupSource(ctuConfig->adcRegularHardwareTrig);
    CTU_SetBusDivide(ctuConfig->clk);
    CTU_SetPwm2Trig2AdcDelayCnt(ctuConfig->delayCnt);
    return 0;
}
