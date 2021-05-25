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
#ifndef AC78XX_ACMP_H_
#define  AC78XX_ACMP_H_
#ifdef __cplusplus
extern "C" {
#endif
#include "ac78xx_acmp_reg.h"
#include "ac78xx.h"

typedef void (*ACMP_CallbackType) (void); ///<  ACMP_CALLBACK function declaration
///<ACMP Mode Select
#define ACMP_LOWPOWER_MODE                        (0x00)
#define ACMP_NORMAL_MODE                          (0x01)
///<ACMP Hysteresis Select
#define ACMP_HYST_10MV                            (0x00)
#define ACMP_HYST_20MV                            (0x01)
///<ACMP Interrupt Mode Select
#define ACMP_INTERRUPT_EDGE_FALLING               (0x00)
#define ACMP_INTERRUPT_EDGE_RISING                (0x01)
#define ACMP_INTERRUPT_EDGE_FALLING_RISING        (0x03)

#define ACMP_DAC_REFERENCE_BANDGAP                (0x00)  ///< select bandgap as refference  
#define ACMP_DAC_REFERENCE_VDDA                   (0x01)  ///< select VDDA as refference  

#define ACMP_INPUT_EXT0                           (0x00)
#define ACMP_INPUT_EXT1                           (0x01)
#define ACMP_INPUT_EXT2                           (0x02)
#define ACMP_INPUT_EXT3                           (0x03)
#define ACMP_INPUT_EXT4                           (0x04)
#define ACMP_INPUT_DAC                            (0x05)
#define ACMP_INPUT_TIE                            (0x06)

#define ACMP0_POLLING_OUTPUT_CHANNEL0_FLAG        (0x01<<0)
#define ACMP0_POLLING_OUTPUT_CHANNEL1_FLAG        (0x01<<1)
#define ACMP0_POLLING_OUTPUT_CHANNEL2_FLAG        (0x01<<2)
#define ACMP0_POLLING_OUTPUT_CHANNEL3_FLAG        (0x01<<3)
#define ACMP0_POLLING_OUTPUT_CHANNEL4_FLAG        (0x01<<4)
#define ACMP0_POLLING_OUTPUT_CHANNEL5_FLAG        (0x01<<5)
#define ACMP0_WAKEUP_FLAG                         (0x01<<6)
#define ACMP0_OUTPUT_FLAG                         (0x01<<7)

#define ACMP1_OUTPUT_FLAG                         (0x01<<0)
#define ACMP1_INT_FLAG                            (0x01<<4)
#define ACMP1_WAKEUP_FLAG                         (0x01<<6)

#define ACMP0_POLLING_FREQ_DIVIDER_256            (0x00)
#define ACMP0_POLLING_FREQ_DIVIDER_100            (0x01)
#define ACMP0_POLLING_FREQ_DIVIDER_70             (0x10)
#define ACMP0_POLLING_FREQ_DIVIDER_50             (0x11)

#define ACMP_ENABLE  1
#define ACMP_DISABLE 0


typedef struct {
    uint8_t edgeType;               ///< Sensitivity modes of the interrupt trigger(Falling or Rising Type)
    uint8_t pollEn;                 ///<ACMP Polling Mode Enable
    uint8_t intEn;                  ///< ACMP interrupt enable
    uint8_t moduleEnable;           ///< Enables the ACMP module
    uint8_t hyst;                   ///< Selects ACMP hystersis
    uint32_t negPin;                ///< Negative pin select
    uint32_t posPin;                ///< Positive pin select
} ACMP_InitType;
typedef struct {
    uint8_t val;              ///< 6 bit DAC value
    uint8_t ref;              ///< 6 bit DAC reference select
    uint8_t enable;		      ///< 6 bit DAC enable bit
} ACMP_DACType;
typedef struct {
    uint8_t posPollingEnable;    ///< Positive Polling mode enable bit
    uint8_t negPollingEnable;    ///< Negative Polling mode enable bit
    uint8_t pollingDiv;		     ///< polling mode frequency divider select
    uint8_t  hallOutEn;          ///< Hall Output Enable
    uint32_t pollingChannelSeq;  ///< polling mode sequence select
    uint32_t hallAOutput;        ///< Hall output A channel select
    uint32_t hallBOutput;        ///< Hall Output B Channel Select
    uint32_t hallCOutput;        ///< Hall Output C Channel Select
} ACMP_PollingType;

void ACMP_ModuleEnable(void);
void ACMP_ModuleDisable(void);
void ACMP_Init(ACMP_CHANNEL acmpChannel, const ACMP_InitType* acmpConfig);
int32_t ACMP_PollingModeInit(ACMP_CHANNEL acmpChannel, const ACMP_PollingType* acmpPollConfig);
void ACMP_SetDacValue(ACMP_CHANNEL acmpChannel, const ACMP_DACType* acmpConfig);
void ACMP_DeInit(ACMP_CHANNEL acmpChannel);
void ACMP_SetCallBack(ACMP_CHANNEL acmpChannel, const ACMP_CallbackType acmpCallback);
void ACMP0_IRQHandler(void);
void ACMP1_IRQHandler(void);
#ifdef __cplusplus
}
#endif

#endif
