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
* @file ac78xx_acmp.c
*
* @author AutoChips
*
* @version 0.0.1
*
* @date March.16.2016
*
* @brief providing APIs for configuring ADC.
*
*******************************************************************************/
#include "ac78xx_acmp.h"
static ACMP_CallbackType s_acmpCallback[2] = {(ACMP_CallbackType)NULL}; ///< ACMP call back function
/**
 * @param[in] none
 *
 * @return none
 *
 * @brief enable ACMP module
 */
void ACMP_ModuleEnable(void)
{
    ///<Enable ACMP Clock
    CKGEN_Enable(CLK_ACMP, 1);
    CKGEN_SoftReset(SRST_ACMP, 1);

}
/**
 * @param[in] none
 *
 * @return none
 *
 * @brief disable ACMP module
 */
void ACMP_ModuleDisable(void)
{
    ///<Disable ACMP Clock
    CKGEN_Enable(CLK_ACMP, 0);
    CKGEN_SoftReset(SRST_ACMP, 0);

}
/**
 * @param[in] acmpChannel: ACMP channel  selection
 * @param[in] acmpConfig: ACMP  init type pointer
 * @return none
 *
 * @brief ACMP init
 */
void ACMP_Init(ACMP_CHANNEL acmpChannel, const ACMP_InitType* acmpConfig)
{
    ACMP_ModuleEnable();
    ACMP_SelectIntMode(acmpChannel, acmpConfig->edgeType);
    ACMP_SetHystValue(acmpChannel, acmpConfig->hyst);
    ACMP_PositiveInputSelect(acmpChannel, acmpConfig->posPin);
    ACMP_NegativeInputSelect(acmpChannel, acmpConfig->negPin);
    if (ACMP_ENABLE == acmpConfig->intEn)
    {
        ACMP_EnableInterrupt(acmpChannel);
    }
    else
    {
        ACMP_DisableInterrupt(acmpChannel);
    }
    if (ACMP_ENABLE == acmpConfig->pollEn)
    {
        ACMP_PollingEnable(acmpChannel);
    }
    else
    {
        ACMP_PollingDisable(acmpChannel);
    }
    if (ACMP_ENABLE == acmpConfig->moduleEnable)
    {
        ACMP_Enable(acmpChannel);
    }
    else
    {
        ACMP_Disable(acmpChannel);
    }
}
/**
 * @param[in] acmpChannel:  ACMP channel  selection
 * @param[in] acmpConfig: ACMP  dac type pointer
 * @return none
 *
 * @brief ACMP set dac value
 */
void ACMP_SetDacValue(ACMP_CHANNEL acmpChannel, const ACMP_DACType* acmpConfig)
{
    ACMP_DacDisable(acmpChannel);
    ACMP_DacReferenceSelect(acmpChannel, acmpConfig->ref);
    ACMP_DacOutputSet(acmpChannel, acmpConfig->val);
    if (ACMP_ENABLE == acmpConfig->enable)
    {
        ACMP_DacEnable(acmpChannel);
    }
    else
    {
        ACMP_DacDisable(acmpChannel);
    }
}
/**
 * @param[in] acmpChannel:  ACMP channel  selection
 * @param[in] acmpConfig: ACMP  polling type pointer
 * @return 0: success, 1: fail
 *
 * @brief ACMP polling mode init
 */
int32_t ACMP_PollingModeInit(ACMP_CHANNEL acmpChannel, const ACMP_PollingType* acmpPollConfig)
{
    int32_t err = 0;
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP_SetPollingModeDiv(acmpChannel, acmpPollConfig->pollingDiv);
        ACMP_SetPollingModeSeq(acmpChannel, acmpPollConfig->pollingChannelSeq);
        if (ACMP_ENABLE == acmpPollConfig->posPollingEnable)
        {
            ACMP_PositivePollingModeEnable(acmpChannel);
        }
        else
        {
            ACMP_PositivePollingModeDisable(acmpChannel);
        }
        if (ACMP_ENABLE == acmpPollConfig->negPollingEnable)
        {
            ACMP_NegativePollingModeEnable(acmpChannel);
        }
        else
        {
            ACMP_NegativePollingModeDisable(acmpChannel);
        }
        if (ACMP_ENABLE == acmpPollConfig->hallOutEn)
        {
            ACMP_SetHallOutput(acmpChannel, acmpPollConfig->hallAOutput, acmpPollConfig->hallBOutput, acmpPollConfig->hallCOutput);
        }
        err = 0;
    }
    else
    {
        err = 1; ///<error only acmp0 has polling mode
    }
    return err;
}
/**
 * @param[in] acmpChannel: ACMP channel  selection
 *
 * @return none
 *
 * @brief ACMP deinit
 */
void ACMP_DeInit(ACMP_CHANNEL acmpChannel)
{
    ACMP_DisableInterrupt(acmpChannel);
    ACMP_DacDisable(acmpChannel);
    ACMP_Disable(acmpChannel);
}
/**
 * @param[in] acmpChannel: ACMP channel  selection
 * @param[in] acmpCallback: ACMP type call back function
 * @return none
 *
 * @brief Set ACMP channel  call back function
 */
void ACMP_SetCallBack(ACMP_CHANNEL acmpChannel, const ACMP_CallbackType acmpCallback)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        s_acmpCallback[0] = acmpCallback;
    }
    else
    {
        s_acmpCallback[1] = acmpCallback;
    }
}
/**
 * @param[in] none
 *
 * @return none
 *
 * @brief ACMP0 interrupt service routine
 */
void ACMP0_IRQHandler(void)
{

    if (s_acmpCallback[0])
    {
        s_acmpCallback[0]();
    }
}
/**
 * @param[in] none
 *
 * @return none
 *
 * @brief ACMP1 interrupt service routine
 */
void ACMP1_IRQHandler(void)
{

    if (s_acmpCallback[1])
    {
        s_acmpCallback[1]();
    }
}
