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
#ifndef _CKGEN_AC78XX_H
#define _CKGEN_AC78XX_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

///< clock module index
    typedef enum
    {
        //PERI_CLK_EN_0
        CLK_UART1 = 0,
        CLK_UART2,
        CLK_UART3,
        CLK_UART4,
        CLK_UART5,
        CLK_UART6,
        CLK_SPI1,
        CLK_SPI2,
        CLK_I2C1,
        CLK_I2C2,
        CLK_PWDT,
        CLK_PWM0_APB,
        CLK_PWM1_APB,
        CLK_PWM2_APB,
        CLK_PWM3_APB,
        CLK_PWM0_TIMER,
        CLK_PWM1_TIMER,
        CLK_PWM2_TIMER,
        CLK_PWM3_TIMER,
        CLK_TIM,
        CLK_RTC,
        CLK_DMA_APB,
        CLK_DMA_AHB,
        CLK_GPIO_APB,
        CLK_GPIO_AHB,
        CLK_WDT_APB,
        CLK_CRC,
        CLK_LIN,
        CLK_CAN1,
        CLK_CAN2,
        CLK_CAN1_CORE,
        CLK_CAN2_CORE,

        // PERI_CLK_EN_1
        CLK_SFLASH = 32 + 0,
        CLK_CTU_APB,
        CLK_ADC,
        CLK_ACMP,
        CLK_MODULE_NUM,
    }
    CLK_MODULE;

    int32_t CKGEN_Enable(CLK_MODULE module, uint8_t enable);

///< soft reset module index
    typedef enum
    {
        //PERI_SFT_RST1
        SRST_UART1 = 0,
        SRST_UART2,
        SRST_UART3,
        SRST_UART4,
        SRST_UART5,
        SRST_UART6,
        SRST_SPI1,
        SRST_SPI2,
        SRST_I2C1,
        SRST_I2C2,
        SRST_PWDT,
        SRST_PWM0_APB,
        SRST_PWM1_APB,
        SRST_PWM2_APB,
        SRST_PWM3_APB,
        SRST_PWM0_TIMER,
        SRST_PWM1_TIMER,
        SRST_PWM2_TIMER,
        SRST_PWM3_TIMER,
        SRST_TIM,
        SRST_RTC,
        SRST_DMA_APB,
        SRST_DMA_AHB,
        SRST_GPIO_APB,
        SRST_GPIO_AHB,
        SRST_WDG,
        SRST_CRC,
        SRST_LIN,
        SRST_CAN1,
        SRST_CAN2,

        //PERI_SFT_RST2
        SRST_SFLASH = 32 + 0,
        SRST_CTU,
        SRST_ADC,
        SRST_ACMP,
        SRST_ANA_REG,
        SRST_MODULE_NUM
    } SRST_MODULE;

    int32_t CKGEN_SoftReset(SRST_MODULE module, uint8_t active);

///< sysclk source
    typedef enum
    {
        SYSCLK_SRC_INTERNAL_OSC = 0,
        SYSCLK_SRC_PLL_OUTPUT,
        SYSCLK_SRC_EXTERNAL_OSC,
    } SYSCLK_SRC;

    void CKGEN_SetSysclkSrc(SYSCLK_SRC clockSource);

    void CKGEN_SetPllPrevDiv(uint8_t div);

    void CKGEN_SetPllPostDiv(uint8_t div);

    void CKGEN_SetPllFeedbackDiv(uint8_t div);
    
    void CKGEN_SetPllDiv(uint8_t div);

///< PLL Post divider
    enum
    {
        PLL_POSDIV_1 = 0,
        PLL_POSDIV_2 = 1,
        PLL_POSDIV_4 = 2,
    };

///< PLL Previous divider
    enum
    {
        PLL_PREDIV_1 = 0,
        PLL_PREDIV_2 = 1,
        PLL_PREDIV_4 = 2,
    };

///< sysclk divider
    typedef enum
    {
        SYSCLK_DIVIDER_1 = 0,
        SYSCLK_DIVIDER_2 = (1 << 3),
        SYSCLK_DIVIDER_4,
        SYSCLK_DIVIDER_8,
        SYSCLK_DIVIDER_16,
        SYSCLK_DIVIDER_64,
        SYSCLK_DIVIDER_128,
        SYSCLK_DIVIDER_256,
        SYSCLK_DIVIDER_512,
    } SYSCLK_DIVIDER;

    void CKGEN_SetSysclkDiv(SYSCLK_DIVIDER div);

///< sflash clock divider
    typedef enum
    {
        SFLASH_DIVIDER_1 = 0,
        SFLASH_DIVIDER_2,
        SFLASH_DIVIDER_4,
        SFLASH_DIVIDER_8,
    } SFLASH_DIVIDER;

///< sflash clock source
    typedef enum
    {
        SFLASH_CLK_SEL_PLL = 0,
        SFLASH_CLK_SEL_APB,
    } SFLASH_CLK_SEL;

    void CKGEN_SetSFlashClock(SFLASH_CLK_SEL sel, SFLASH_DIVIDER div);


///< APBCLK clock divider
    typedef enum
    {
        APBCLK_DIVIDER_1 = 0,
        APBCLK_DIVIDER_2 = (1 << 2),
        APBCLK_DIVIDER_4,
        APBCLK_DIVIDER_8,
        APBCLK_DIVIDER_16,
    } APBCLK_DIVIDER;

    void CKGEN_SetAPBClockDivider(APBCLK_DIVIDER div);

///< PLL Reference
    typedef enum
    {
        PLL_REF_INTERAL_OSC = 0,
        PLL_REF_EXTERNAL_OSC = 5,
    } PLL_REF;

    void CKGEN_SetPLLReference(PLL_REF ref);

///< CAN clock source
    typedef enum
    {
        CAN_CLK_SEL_EXTERNAL_OSC = 0,
        CAN_CLK_SEL_AHB,
    } CAN_CLK_SEL;

///< CAN clock divider
    typedef enum
    {
        CAN_CLK_DIVIDER_1 = 0,
        CAN_CLK_DIVIDER_2,
        CAN_CLK_DIVIDER_4,
        CAN_CLK_DIVIDER_8,
    } CAN_CLK_DIVIDER;

    void CKGEN_SetCANClock(uint8_t canIndex, CAN_CLK_SEL sel, CAN_CLK_DIVIDER div);

#ifdef __cplusplus
}
#endif


#endif
