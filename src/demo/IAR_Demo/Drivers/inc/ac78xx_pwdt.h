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
* @file     ac78xx_pwdt.h
*
* @author   Autochips
*
* @version  0.0.1
*
* @date     May 16, 2016
*
* @brief    Pulse Width Detect Timer (PWDT) source code.
*
*/
#ifndef AC78XX_PWDT_H_
#define AC78XX_PWDT_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "ac78xx_pwdt_reg.h"
#include "ac78xx.h"

#define DIVIDER_RATIO 1
#define TIMER_CLK     48000000L

#define PWDT_PCLKS_BUS               0 	///< select bus clock as PWDT clock source  
#define PWDT_PCLKS_ALTCLK            1	///< select alternative clock as PWDT clock source  

#define PWDT_PINSEL_PIN0             0	///< PWDTIN[0]  
#define PWDT_PINSEL_PIN1             1	///< PWDTIN[1]  
#define PWDT_PINSEL_PIN2             2	///< PWDTIN[2]  
#define PWDT_PINSEL_PIN3             3	///< PWDTIN[3]  ///Alternative clock

#define FALLING_START_CAPTURE_FALLING           0	///< first falling-edge start to measure, all falling-edge capture 
#define RISING_START_CAPTURE_ALL                1	///< first rising-edge start to measure, all edge capture 
#define FALLING_START_CAPTURE_ALL               2	///< first falling-edge start to measure, all edge capture 
#define RISING_START_CAPTURE_RISING             3	///< first rising-edge start to measure, all rising-edge capture 

#define PWDT_CLK_PRESCALER_1         0	///< presalcer is 1  
#define PWDT_CLK_PRESCALER_2         1	///< presalcer is 2  
#define PWDT_CLK_PRESCALER_4         2	///< presalcer is 4  
#define PWDT_CLK_PRESCALER_8         3	///< presalcer is 8  
#define PWDT_CLK_PRESCALER_16        4	///< presalcer is 16 
#define PWDT_CLK_PRESCALER_32        5	///< presalcer is 32 
#define PWDT_CLK_PRESCALER_64        6	///< presalcer is 64 
#define PWDT_CLK_PRESCALER_128       7	///< presalcer is 128 


typedef void (*PWDT_CallbackType)(void);             ///< PWDT callback type 

typedef struct
{
    uint32_t counterOverflow         : 1;    ///<1: overflow bit is set, 0: rno overflow
    uint32_t registerReady           : 1;    ///<1: register has been updated, 0: no up-to-date
    uint32_t softReset               : 1;    ///<1: reset PWDT, 0: no action
    uint32_t overflowIntEn           : 1;    ///<1: enable overflow interrupt, 0: disable overflow interrupt
    uint32_t readyIntEn              : 1;    ///<1: enable data ready interrupt, 0: disable data ready interrupt
    uint32_t pwdtIntEn               : 1;    ///<1: enable PWDT module interrupt, 0: disable PWDT module interrupt
    uint32_t pwdtEn                  : 1;    ///<1: enable PWDT module, 0: disable PWDT module
    uint32_t clockPreScaler          : 3;    ///<prescaler value is from 1 to 128
    uint32_t edgeMode                : 2;    ///<select edge triggers
    uint32_t pinSelect               : 2;    ///<input pin select
    uint32_t clockSource             : 1;    ///<1: PWDT clock source is alternative clock, 0: PWDT clock source is bus clock
    uint32_t pwdtTimerEn             : 1;    ///<1:Enable PWDT Timer Function; 0:Disable Timer function
    uint32_t pwdtTimerValue          : 16;   ///<Set Timer Count Value
    
    uint32_t compEn                  : 1;    ///<1:Enable PWDT Comp Function; 0:Disable Comp function
    uint32_t pwdtHallEn              : 1;    ///<1:Enable PWDT HallSensorDetect Function; 0:Disable Hall function
    uint32_t pwdtFilterEn            : 1;    ///<1:Enable PWDT Filter Function; 0:Disable Filter function
    uint32_t pwdtFilterPsc           : 4;    ///<Set PWDT Filter prescaler
    uint32_t pwdtFilterValue         : 4;    ///<Set PWDT Filter Value
} PWDT_ConfigType;


void PWDT_EnableModule(void);
void PWDT_DisableModule(void);
int32_t PWDT_Init(PWDT_ConfigType *pwdtConfig);
void PWDT_SetCallback(PWDT_CallbackType pwdtCallback);
int32_t PWDT_DeInit(void);
#ifdef __cplusplus
}
#endif
#endif
