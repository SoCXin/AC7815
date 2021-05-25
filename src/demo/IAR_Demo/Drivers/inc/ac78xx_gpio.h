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

#ifndef AC78XX_GPIO_H
#define AC78XX_GPIO_H
#ifdef __cplusplus
extern "C" {
#endif

#include "ac78xx_gpio_reg.h"

#define GPIOA                                     ((GPIO_Type *)GPIOA_BASE)
#define GPIOB                                     ((GPIO_Type *)GPIOB_BASE)
#define GPIOC                                     ((GPIO_Type *)GPIOC_BASE)
#define GPIOD                                     ((GPIO_Type *)GPIOD_BASE)
#define GPIOE                                     ((GPIO_Type *)GPIOE_BASE)

#define GPIOINT                                   ((GPIO_Interrupt_Type *)(GPIOA_BASE + 0x160))

#define PMUX0                                     ((PMUX_Type *)PMUX0_BASE)
#define PMUX1                                     ((PMUX_Type *)PMUX1_BASE)
#define PMUX2                                     ((PMUX_Type *)PMUX2_BASE)
#define PMUX3                                     ((PMUX_Type *)PMUX3_BASE)
#define PMUX4                                     ((PMUX_Type *)PMUX4_BASE)
#define PMUX5                                     ((PMUX_Type *)PMUX5_BASE)
#define PMUX6                                     ((PMUX_Type *)PMUX6_BASE)

typedef enum{
    GPIOx_Pin_0 = (uint32_t)0x1,
    GPIOx_Pin_1 = (uint32_t)0x2,
    GPIOx_Pin_2 = (uint32_t)0x4,
    GPIOx_Pin_3 = (uint32_t)0x8,
    GPIOx_Pin_4 = (uint32_t)0x10,
    GPIOx_Pin_5 = (uint32_t)0x20,
    GPIOx_Pin_6 = (uint32_t)0x40,
    GPIOx_Pin_7 = (uint32_t)0x80,
    GPIOx_Pin_8 = (uint32_t)0x100,
    GPIOx_Pin_9 = (uint32_t)0x200,
    GPIOx_Pin_10 = (uint32_t)0x400,
    GPIOx_Pin_11 = (uint32_t)0x800,
    GPIOx_Pin_12 = (uint32_t)0x1000,
    GPIOx_Pin_13 = (uint32_t)0x2000,
    GPIOx_Pin_14 = (uint32_t)0x4000,
    GPIOx_Pin_15 = (uint32_t)0x8000,
    GPIOx_Pin_All = (uint32_t)0xFFFF,
}GPIO_PinNumMask;

typedef enum
{
    //GPIOA
    GPIO_PA0 = 0,
    GPIO_PA1,
    GPIO_PA2,
    GPIO_PA3,
    GPIO_PA4,
    GPIO_PA5,
    GPIO_PA6,
    GPIO_PA7,
    GPIO_PA8,
    GPIO_PA9,
    GPIO_PA10,
    GPIO_PA11,
    GPIO_PA12,
    GPIO_PA13,
    GPIO_PA14,
    GPIO_PA15,
    //GPIOB
    GPIO_PB0,        //Pin 16
    GPIO_PB1,
    GPIO_PB2,
    GPIO_PB3,
    GPIO_PB4,
    GPIO_PB5,
    GPIO_PB6,
    GPIO_PB7,
    GPIO_PB8,
    GPIO_PB9,
    GPIO_PB10,
    GPIO_PB11,
    GPIO_PB12,
    GPIO_PB13,
    GPIO_PB14,
    GPIO_PB15,
    //GPIOC
    GPIO_PC0,         //Pin 32
    GPIO_PC1,
    GPIO_PC2,
    GPIO_PC3,
    GPIO_PC4,
    GPIO_PC5,
    GPIO_PC6,
    GPIO_PC7,
    GPIO_PC8,
    GPIO_PC9,
    GPIO_PC10,
    GPIO_PC11,
    GPIO_PC12,
    GPIO_PC13,
    GPIO_PC14,
    GPIO_PC15,
    //GPIOD
    GPIO_PD0,          //Pin 48
    GPIO_PD1,
    GPIO_PD2,
    GPIO_PD3,
    GPIO_PD4,
    GPIO_PD5,
    GPIO_PD6,
    GPIO_PD7,
    GPIO_PD8,
    GPIO_PD9,
    GPIO_PD10,
    GPIO_PD11,
    GPIO_PD12,
    GPIO_PD13,
    GPIO_PD14,
    GPIO_PD15,
    //GPIOE
    GPIO_PE0,          //Pin 64
    GPIO_PE1,
    GPIO_PE2,
    GPIO_PE3,
    GPIO_PE4,
    GPIO_PE5,
    GPIO_PE6,
    GPIO_PE7,
    GPIO_PE8,
    GPIO_PE9,
    GPIO_PE10,
    GPIO_PE11,
    GPIO_PE12,
    GPIO_PE13,
    GPIO_PE14,
    GPIO_PE15,
}GPIO_GroupNum;

typedef void (*GPIO_EventCallback)(uint32_t gpioNum);
typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;

typedef enum
{
  EXTI_Trigger_Falling=0,
  EXTI_Trigger_Rising,
  EXTI_Trigger_Rising_Falling
}EXTITrigger_TypeDef;

#define MAX_PIN_NUM    68
#define GPIO_ONE_GROUP_NUM 16

typedef struct
{
    PMUX_Type *PMUXx;                 ///< PMUX index, can be configured by GPIO_GetPMUXConfig()
    uint32_t PMUXx_PFSEL;             ///< PFSEL index, can be configured by GPIO_GetPMUXConfig()
}GPIO_ConfigPMUXType;

//GPIO fast output operation by bit band
#define GPIOA_OUT(n)   BIT_ADDR(GPIOA_ODR_ADDR,n)
#define GPIOB_OUT(n)   BIT_ADDR(GPIOB_ODR_ADDR,n)
#define GPIOC_OUT(n)   BIT_ADDR(GPIOC_ODR_ADDR,n)
#define GPIOD_OUT(n)   BIT_ADDR(GPIOD_ODR_ADDR,n)
#define GPIOE_OUT(n)   BIT_ADDR(GPIOE_ODR_ADDR,n)

//GPIO fast input operation by bit band
#define GPIOA_IN(n)   BIT_ADDR(GPIOA_IDR_ADDR,n)
#define GPIOB_IN(n)   BIT_ADDR(GPIOB_IDR_ADDR,n)
#define GPIOC_IN(n)   BIT_ADDR(GPIOC_IDR_ADDR,n)
#define GPIOD_IN(n)   BIT_ADDR(GPIOD_IDR_ADDR,n)
#define GPIOE_IN(n)   BIT_ADDR(GPIOE_IDR_ADDR,n)

//Initialization of GPIO module by configure GPIO_ConfigPMUXType struct
int32_t GPIO_SetEventCallback(uint32_t gpioNum, const GPIO_EventCallback callback);
int32_t GPIO_SetFunc(uint32_t gpioNum, uint32_t functionx);
int32_t GPIO_SetDir(uint32_t gpioNum,uint32_t pinMode);
int32_t GPIO_SetFuncGroup(GPIO_Type *GPIOx, uint32_t pinMask, uint32_t functionx);
int32_t GPIO_SetDirGroup(GPIO_Type *GPIOx, uint32_t pinMask, uint32_t pinMode);

int32_t GPIO_SetPinValue(uint32_t gpioNum, uint32_t pinValue);
int32_t GPIO_SetPinBits(uint32_t gpioNum);
int32_t GPIO_ResetPinBits(uint32_t gpioNum);
int32_t GPIO_GetPinValue(uint32_t gpioNum);

int32_t GPIO_SetPullupEnable(uint32_t gpioNum, FunctionalState enable);
int32_t GPIO_SetPulldownEnable(uint32_t gpioNum, FunctionalState enable);
//Get GPIO Pin's PinMux Information by GPIO number
GPIO_ConfigPMUXType GPIO_GetPMUXConfig(uint32_t gpioNum);
int32_t GPIO_GetPinFunc(uint32_t gpioNum);
int32_t GPIO_GetPinMode(uint32_t gpioNum);

//Configure GPIO external interrupt
int32_t GPIO_EnableGPIOExtInt(uint32_t gpioNum, EXTITrigger_TypeDef risingFallingEdge);
int32_t GPIO_DisableGPIOExtInt(uint32_t gpioNum);

uint32_t GPIO_GetPendingIRQMask(void);
uint32_t GPIO_GetPendingExtIntGPIONum(uint32_t pendingIRQNum);
int32_t GPIO_ClearPendingExtInt(uint32_t gpioNum);

int32_t GPIO_SetE4E2(uint32_t gpioNum, uint32_t E4E2Value);

#ifdef __cplusplus
}
#endif

#endif
