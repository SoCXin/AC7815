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

#ifndef _SPM_AC78XX_H
#define _SPM_AC78XX_H

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

extern uint32_t g_wakeUpSource;    ///< For UCOS Wakeup Debug

///< config the power mode
typedef enum
{
    LOW_POWER_MODE_STOP_LITE = 0,
    LOW_POWER_MODE_STOP      = 1,
    LOW_POWER_MODE_STANDBY   = 3,
}LOW_POWER_MODE;

///< config the power setting
typedef struct _LOW_POWER_CFG
{
    uint32_t enableFastboot : 1;
    uint32_t enablePWRLVD : 1;
    uint32_t enablePWRWARNEn : 1;
}LOW_POWER_CFG;

typedef int32_t (*SPM_IRQEventFunc)(uint32_t wparam, uint32_t lparam );  
//config the low power mode
void SPM_EnableFastBoot(uint8_t enable);
void SPM_EnableLVD(uint8_t enable);
void SPM_EnablePVD(uint8_t enable);
void SPM_SetLVDTriggerLevel(uint8_t level);
void SPM_SetPVDTriggerLevel(uint8_t level);

void SPM_SetSPMIRQHandler(SPM_IRQEventFunc eventFunc);

//config the low power mode
void SPM_SetLowPowerMode(LOW_POWER_MODE mode);

void SPM_EnableXOSC(uint8_t enable);
void SPM_EnableXOSCBypassMode(uint8_t enable);

void SPM_EnablePLL(uint8_t enable);

void SPM_EnableCANLowpassFilter(uint8_t canIndex, uint8_t enable);

///< the module's index in SPM
typedef enum
{
    SPM_MODULE_ACMP0 = 0,
    SPM_MODULE_ACMP1,
    SPM_MODULE_I2C1,
    SPM_MODULE_I2C2,
    SPM_MODULE_SPI1,
    SPM_MODULE_SPI2,
    SPM_MODULE_LIN,
    SPM_MODULE_CAN1,
    SPM_MODULE_CAN2,
    SPM_MODULE_UART1,
    SPM_MODULE_UART2,
    SPM_MODULE_UART3,
    SPM_MODULE_UART4,
    SPM_MODULE_UART5,
    SPM_MODULE_UART6,
    SPM_MODULE_RTC, 
    SPM_MODULE_ADC,
    SPM_MODULE_GPIO,
    SPM_MODULE_NMI,
    SPM_MODULE_PVD,
    SPM_MODULE_SPM_OVER_COUNT,
    SPM_MODULE_NUM,
}SPM_MODULE;


/*
1) The clocks of all modules are already after wake up and can operate normally.
2) When the wake-up source of  UART, CAN, I2C, SPI, LIN generate wake-up signal, enter the IRQ of SPM firstly,then return to the next command of _WFI
3) When the wakeup source of GPIO,RTC£¬ADC,LVD,ACMP£¬T-Sensor generates wakeup signals£¬enter the IRQ of the module, and then return to the next command of _WFI.£¨Each module can ignore the interrupt of SPM£©
*/
int32_t SPM_EnableModuleWakeup(SPM_MODULE module, uint8_t enable);
int32_t SPM_EnableModuleSleepACK(SPM_MODULE module, uint8_t enable);
int32_t SPM_EnableModuleSPMIRQ(SPM_MODULE module, uint8_t enable);
uint32_t SPM_GetModuleWakeupSourceFlag(void);

void SPM_SetModuleAckCounter(uint16_t sleepAckCount, uint16_t wakeupAckCount);

#ifdef __cplusplus
}
#endif


#endif
