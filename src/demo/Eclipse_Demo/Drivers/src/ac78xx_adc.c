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
* @file ac78xx_adc.c
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
#include "ac78xx_adc.h"
ADC_CallbackType g_adcCallback[1] = {(ADC_CallbackType)NULL};
/**
  * @param[in]  ADCx:the ADC peripheral.
  * @return none
  * @brief  Deinitializes the ADC peripheral registers to their default reset values.
  */
void ADC_DeInit(ADC_Type* ADCx)
{
    /********************Disable ADC Clock************************/
    CKGEN_SoftReset(SRST_ADC, 0);
    CKGEN_Enable(CLK_ADC, 0);
}

/**
  * @param[in] ADCx: select the ADC peripheral.
  * @param[in] adcAnalogWatchDogConfig: pointer to an ADC_AnalogWatchDogType structure that contains
  *         the configuration information for the specified ADC peripheral.
  * @return none
  * @brief  Initializes the ADC WatchDog Function
  *         in the adcAnalogWatchDogConfig.
  */
void ADC_AnalogWatchDogInit(ADC_Type* ADCx, ADC_AnalogWatchDogType* adcAnalogWatchDogConfig)
{
    ADCx->CTRL1 &= AMO_SETTING_RESET;
    if (adcAnalogWatchDogConfig->analogWatchDogSingleMode)
    {
        ADC_AnalogWatchDogSingleChannelModeEnable(ADCx);
    }
    if (adcAnalogWatchDogConfig->analogWatchDogOnInjectGroup)
    {
        ADC_AnalogWatchDogOnInjectChannelModeEnable(ADCx);
    }
    if (adcAnalogWatchDogConfig->analogWatchDogOnRegularGroup)
    {
        ADC_AnalogWatchDogOnRegularChannelModeEnable(ADCx);
    }
    ADC_AnalogWatchDogSingleChannelSel(ADCx, adcAnalogWatchDogConfig->analogWatchDogChannel);
}

/**
  * @param[in] ADCx: select the ADC peripheral.
  * @param[in] adcTrigSourceConfig: pointer to an ADC_TrigSourceType structure that contains
  *         the configuration information for the specified ADC peripheral.
  * @return none
  * @brief  Initializes the ADC Trigger Source
  *         in the adcTrigSourceConfig.
  */
void ADC_TrigSourceInit(ADC_Type* ADCx, ADC_TrigSourceType* adcTrigSourceConfig)
{
    ADCx->CTRL1 &= TRIG_SOURCE_SETTING_RESET;
    ADC_RegularTrigSourceSel(ADCx, adcTrigSourceConfig->regularTrigSource);
    ADC_InjectTrigSourceSel(ADCx, adcTrigSourceConfig->injectTrigSource);
}

/**
  * @param[in] ADCx: select the ADC peripheral.
  * @param[in] state: Enable or Disable the function.This parameter can be: ENABLE(1) or DISABLE(0).
  * @return none
  * @brief  Enable/Disable ADC DMA Function
  */
void ADC_DMACmd(ADC_Type* ADCx, uint8_t state)
{
    if (state == ADC_ENABLE)
    {
        ADC_DMAEnable(ADCx);
    }
    else
    {
        ADC_DMADisable(ADCx);
    }
}

/**
  * @param[in] ADCx: select the ADC peripheral.
  * @param[in] state: Enable or Disable the function.This parameter can be: ENABLE(1) or DISABLE(0).
  * @return none
  * @brief  ADC software start regular group convert.
  */
void ADC_SoftwareStartRegularConvCmd(ADC_Type* ADCx, uint8_t state)
{
    if (state == ADC_ENABLE)
    {
        ADC_SoftwareTriggerCovEnable(ADCx);
    }
    else
    {
        ADC_SoftwareTriggerCovDisable(ADCx);
    }
}

/**
  * @param[in] ADCx: select the ADC peripheral.
  * @param[in] state: Enable or Disable the function.This parameter can be: ENABLE(1) or DISABLE(0).
  * @return none
  * @brief  ADC software start inject group convert.
  */
void ADC_SoftwareStartInjectConvCmd(ADC_Type* ADCx, uint8_t state)
{
    if (state == ADC_ENABLE)
    {
        ADC_SoftwareTriggerInjectCovEnable(ADCx);
    }
    else
    {
        ADC_SoftwareTriggerInjectCovDisable(ADCx);
    }
}

/**
  * @param[in] ADCx: select the ADC peripheral.
  * @param[in] state: Enable or Disable the function.This parameter can be: ENABLE(1) or DISABLE(0).
  * @return none
  * @brief  Enables or disables the ADC peripheral.
  */
void ADC_Cmd(ADC_Type* ADCx, uint8_t state)
{
    if (state == ADC_ENABLE)
    {
        ADC_PowerOn(ADCx);
    }
    else
    {
        ADC_PowerDown(ADCx);
    }
}

/**
  * @param[in] ADCx: select the ADC peripheral.
  * @return none
  * @brief  Enables the ADC Clock.
  */
void ADC_ModuleEnable(ADC_Type* ADCx)
{
    /********************Enable ADC Clock************************/
    CKGEN_Enable(CLK_ADC, 1);
    CKGEN_SoftReset(SRST_ADC, 1);
    /************************************************************/
}

/**
  * @param[in] ADCx: select the ADC peripheral.
  * @return none
  * @brief  Disables the ADC Clock.
  */
void ADC_ModuleDisable(ADC_Type* ADCx)
{
    /********************Enable ADC Clock************************/
    CKGEN_SoftReset(SRST_ADC, 0);
    CKGEN_Enable(CLK_ADC, 0);
    /************************************************************/
}

/**
  * @param[in] ADCx: select the ADC peripheral.
  * @param[in] adcConfig: pointer to an ADC_InitType structure that contains the configuration information for the specified ADC peripheral.
  * @return none
  * @brief  Initializes the ADC peripheral according to the specified parameters
  *         in the adcConfig.
  */
void ADC_Init(ADC_Type* ADCx, ADC_InitType* adcConfig)
{
    uint32_t tmp = 0;
    ADC_ModuleEnable(ADCx);
    /*************************** ADC Mode Sel********************/
    tmp = ADCx->CTRL1;
    tmp &= ADC_MODE_RESET;
    tmp |= ((uint32_t)(adcConfig->injectAutoMode | ((uint32_t)adcConfig->disContinousModeOnInjectGroup << 1)\
                       | ((uint32_t)adcConfig->disContinousModeOnRegularGroup << 2) | ((uint32_t)adcConfig->continousMode << 3)\
                       | ((uint32_t)adcConfig->scanMode << 4))) << 11;
    ADCx->CTRL1 = tmp;
    /*************************** ADC Data alignment Sel********************/
    ADC_DataAlignSel(ADCx, adcConfig->dataAlign);
    /*************************** ADC Discontinous conversion length config********************/
    ADC_DiscModeNumSel(ADCx, adcConfig->discNum);
    ADC_LP1Disable(ADCx);
    ADC_LP0Disable(ADCx);
}

/**
  * @param[in] ADCx: select ADC peripheral.
  * @return The Data conversion value.
  * @brief  Returns the last ADCx conversion result data for regular channel.
  */
uint16_t ADC_GetRegularConversionValue(ADC_Type* ADCx)
{
    return (uint16_t)ADCx->RDR;
}

/**
  * @param[in] ADCx: select the ADC peripheral.
  * @param[in] adcInjectedChannel: the converted ADC injected channel.
  * @return The Data conversion value.
  * @brief  Returns the ADC injected channel conversion result
  */
uint16_t ADC_GetInjectedConversionValue(ADC_Type* ADCx, uint8_t adcInjectedChannel)
{
    __IO uint32_t tmp = 0;
    tmp = (uint32_t)ADCx;
    tmp += adcInjectedChannel + IDR_Offset;

    /* Returns the selected injected channel conversion data value */
    return (uint16_t) (*(__IO uint32_t*)  tmp);
}

/**
  * @param[in] ADCx: select the ADC peripheral.
  * @param[in] adcFlag: specifies the flag to clear.
  *     This parameter can be any combination of the following values:
  *     @arg ADC_FLAG_AMO: Analog monitor/watchdog flag
  *     @arg ADC_FLAG_EOC: End of conversion flag
  *     @arg ADC_FLAG_IEOC: End of injected group conversion flag
  * @return 0: Event No Flag,1: Event Flag
  * @brief  Get the ADCx's pending flags.
  */
int32_t ADC_GetIntFlag(ADC_Type* ADCx, uint8_t adcFlag)
{
    if((ADCx->STR & adcFlag) != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

/**
  * @param[in] ADCx: select the ADC peripheral.
  * @param[in] adcFlag: specifies the flag to clear.
  *     This parameter can be any combination of the following values:
  *     @arg ADC_FLAG_AMO: Analog monitor/watchdog flag
  *     @arg ADC_FLAG_EOC: End of conversion flag
  *     @arg ADC_FLAG_IEOC: End of injected group conversion flag
  * @return none
  * @brief  Clears the ADCx's pending flags.
  */
void ADC_ClearFlag(ADC_Type* ADCx, uint8_t adcFlag)
{
    /* Clear the selected ADC flags */
    ADCx->STR = ~(uint32_t)adcFlag;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @param[in] funcCallback: functon address.
  * @return none.
  * @brief This function sets the callback function.
  */
void ADC_SetCallback(ADC_Type *ADCx, ADC_CallbackType funcCallback)
{
    g_adcCallback[0] = funcCallback;
}

/**
  * @param[in] none.
  * @return none.
  * @brief  ADC_Isr interrupt service routine.
  */
void ADC_IRQHandler(void)
{
    if (g_adcCallback[0])
    {
        g_adcCallback[0]();
    }
}

