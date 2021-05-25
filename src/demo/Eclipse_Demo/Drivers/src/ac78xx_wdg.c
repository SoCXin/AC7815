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

#include "ac78xx_wdg.h"
#include "ac78xx.h"

WDOG_EventCallback g_WDOGCallbackArray[1] = {(WDOG_EventCallback)NULL}; ///< WDOG initial callback

/**
* WDOG_Initialize
*
* @param[in]  config: pointer to a WDOG_ConfigType structure contains WDOG configuration information.
* @return 0: success, other: error value
*
* @brief  Initialize the WDOG module according to the WDOG_ConfigType structure
*/
int32_t WDOG_Initialize(WDOG_ConfigType *config)
{
    uint32_t CS1 = 0, CS2 = 0;

    CKGEN_Enable(CLK_WDT_APB, 1);
    CKGEN_SoftReset(SRST_WDG, 1);
    CS2 |= WDOG_CS2_CLK(config->control.clkSource);
    if (config->control.intEnable)
    {
        NVIC_EnableIRQ(Watchdog_IRQn);
        CS1 |= WDOG_CS1_INT_MASK;
    }
    else
    {
        NVIC_DisableIRQ(Watchdog_IRQn);
        CS1 &= ~WDOG_CS1_INT_MASK;
    }
    if (config->control.winEnable)
    {
        CS2 |= WDOG_CS2_WIN_MASK;
    }
    else
    {
        CS2 &= ~WDOG_CS2_WIN_MASK;
    }
    if (config->control.prescaler)
    {
        CS2 |= WDOG_CS2_PRES_MASK;
    }
    else
    {
        CS2 &= ~WDOG_CS2_PRES_MASK;
    }
    if (config->control.updateEnable)
    {
        CS1 |= WDOG_CS1_UPDATE_MASK;
    }
    else
    {
        CS1 &= ~WDOG_CS1_UPDATE_MASK;
    }
    if (config->control.enableWDOG)
    {
        CS1 |= WDOG_CS1_EN_MASK;
    }
    else
    {
        CS1 &= ~WDOG_CS1_EN_MASK;
    }
    DisableInterrupts;
    WDOG_Unlock();                      //unlock watchdog first
    WDOG0->CS2   = CS2;
    WDOG0->TOVAL = config->timeout;
    WDOG0->WIN   = config->winTimeout;
    WDOG0->CS1   = CS1;
    EnableInterrupts;
    return 0;
}

/**
* WDOG_Uninitialize
*
* @param[in] none
* @return 0: success, other: error value
*
* @brief  Uninitialize WDOG module by disbale IRQ, reset peripheral and disable CLK.
*/
int32_t WDOG_Uninitialize(void)
{
    NVIC_DisableIRQ(Watchdog_IRQn);
    CKGEN_SoftReset(SRST_WDG, 0);        //Inactive WDG reset
	CKGEN_Enable(CLK_WDT_APB, 0);

    return 0;
}

/**
* WDOG_SetEventCallback
*
* @param[in] callback: user-defined callback interface function
* @return 0: success, other: error value
*
* @brief  specify WDOG event callback function
*/
int32_t WDOG_SetEventCallback(WDOG_EventCallback callback)
{
    uint8_t  index = 0;

    g_WDOGCallbackArray[index] = callback;

    return 0;
}

/**
* Watchdog_IRQHandler
*
* @param[in] none
* @return none
*
* @brief  override the Watchdog_IRQHandler
*/
void Watchdog_IRQHandler(void)
{
    WDOG_ClrFlag();
    if (g_WDOGCallbackArray[0])
    {
        g_WDOGCallbackArray[0](0, 0);
    }

}

/**
* WDOG_Unlock
*
* @param[in] none
* @return none
*
* @brief  Unlock WDOG module for configing
*/
void WDOG_Unlock(void)
{
    WDOG0->CNT = 0x20C520C5;
    WDOG0->CNT = 0x28D928D9;
}

/**
* WDOG_Feed
*
* @param[in]  none
* @return none
*
* @brief  the function to feed dog
*/
void WDOG_Feed(void)
{
    DisableInterrupts;
    WDOG0->CNT = 0x02A602A6;
    WDOG0->CNT = 0x80B480B4;
    EnableInterrupts;
}
