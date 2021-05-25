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


#ifndef AC78XX_H
#define AC78XX_H
#include <string.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif


///<Interrupt Number Definition
typedef enum {
/* -------------------  Cortex-M3 Processor Exceptions Numbers  ------------------- */
  Reset_IRQn                    = -15,              ///<  1  Reset Vector, invoked on Power up and warm reset                 
  NonMaskableInt_IRQn           = -14,              ///<  2  Non maskable Interrupt, cannot be stopped or preempted           
  HardFault_IRQn                = -13,              ///<  3  Hard Fault, all classes of Fault                                 
  MemoryManagement_IRQn         = -12,              ///<  4  Memory Management, MPU mismatch, including Access Violation and No Match                                                          
  BusFault_IRQn                 = -11,              ///<  5  Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault                                                         
  UsageFault_IRQn               = -10,              ///<  6  Usage Fault, i.e. Undef Instruction, Illegal State Transition    
  SVCall_IRQn                   =  -5,              ///< 11  System Service Call via SVC instruction                          
  DebugMonitor_IRQn             =  -4,              ///< 12  Debug Monitor                                                    
  PendSV_IRQn                   =  -2,              ///< 14  Pendable request for system service                              
  SysTick_IRQn                  =  -1,              ///< 15  System Tick Timer                                                
/* ----------------------  AC78xx Specific Interrupt Numbers  --------------------- */
  PWDT_IRQn                     =  0,
  UART1_IRQn				    =  1,
  UART2_IRQn                    =  2,
  UART3_IRQn                    =  3,
  UART4_IRQn                    =  4,
  UART5_IRQn                    =  5,
  UART6_IRQn                    =  6,
  EXTI0_IRQn                    =  7,
  EXTI1_IRQn                    =  8,
  EXTI2_IRQn                    =  9,
  EXTI3_IRQn                    = 10,
  EXTI4_IRQn                    = 11,
  EXTI5_9_IRQn                    = 12,
  SPI1_IRQn                     = 13,
  SPI2_IRQn                     = 14,
  I2C1_IRQn                     = 15,
  I2C2_IRQn                     = 16,
  DMA1_IRQn                     = 17,
  DMA2_IRQn                     = 18,
  DMA3_IRQn                     = 19,
  DMA4_IRQn                     = 20,  
  DMA5_IRQn                     = 21,
  DMA6_IRQn                     = 22,
  DMA7_IRQn                     = 23,
  DMA8_IRQn                     = 24, 
  DMA9_IRQn                     = 25,
  DMA10_IRQn                    = 26,
  DMA11_IRQn                    = 27,
  DMA12_IRQn                    = 28, 
  TIMER0_IRQn                   = 29,
  TIMER1_IRQn                   = 30,
  BKP_IRQn                      = 31,
  RTC_IRQn                      = 32,
  Watchdog_IRQn                 = 33,
  PWM0_IRQn                     = 34,
  PWM1_IRQn                     = 35,
  PWM2_IRQn                     = 36,
  PVD_IRQn                      = 37,
  LIN0_IRQn                     = 38,
  EXTI10_15_IRQn                = 39,
  SPM_IRQn                      = 40,
  CAN1_IRQn                     = 42,
  CAN2_IRQn                     = 43,
  ADC_IRQn                      = 44,
  ACMP0_IRQn                    = 45,
  ACMP1_IRQn                    = 46,
  TIMER2_IRQn                   = 47,
  TIMER3_IRQn                   = 48, 
  TIMER4_IRQn                   = 49,
  TIMER5_IRQn                   = 50, 
  TIMER6_IRQn                   = 51,
  TIMER7_IRQn                   = 52,
  PWM3_IRQn                     = 53,
  EFlash_IRQn                   = 54,
} IRQn_Type;


/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* ----------------Configuration of the Cortex-M3 Processor and Core Peripherals---------------- */
#define __CM3_REV                 0x0100            ///<Cortex-M3 Core Revision                                               */
#define __MPU_PRESENT                  1            ///<MPU present or not                                                    */
#define __NVIC_PRIO_BITS               4            ///<Number of Bits used for Priority Levels                               */
#define __Vendor_SysTickConfig         0            ///<Set to 1 if different SysTick Config is used                          */
/** @} */ /* End of group Configuration_of_CMSIS */

#include "core_cm3.h"                               ///<Cortex-M3 processor and core peripherals                              */
#include "system_AC78xx.h"                          ///<AC78xx System                                                         */
#include "ac78xx_ckgen.h"

/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */



/* -------------------  Start of section using anonymous unions  ------------------ */
#if defined(__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif


/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif


/*----------------------------------------------------------------------------
  DEFINES
 *----------------------------------------------------------------------------*/

#define SYSCLK_FREQ_27MHz   27000000
#define SYSCLK_FREQ_72MHz   72000000
#define SYSCLK_FREQ_96MHz   96000000
#define SYSCLK_FREQ_100MHz 100000000



#define IC_CLOCK_SRC_HSI  0      //High speed internal RC(HSI): The internal RC OSC to provide 8MHz clock source
#define IC_CLOCK_SRC_HSE  1      //The external OSC to provide 4MHZ ~30MHz  crystal
#define IC_CLOCK_SRC_XOSC 2      //The external OSC to provide 4MHZ ~30MHz  oscillator

#define AC78XX_CLOCK_SRC  IC_CLOCK_SRC_HSE


#define XTAL_8M       8000000
#define XTAL_4M       4000000
#define XTAL_30M     30000000

#define USE_XTAL      XTAL_8M

///<PLL available in HSE & HSI mode
#if USE_XTAL == XTAL_8M
#define PLL_POSDIV   PLL_POSDIV_4
#define PLL_FBKDIV   96
#define PLL_PREDIV   PLL_PREDIV_1

#define SYSCLK_DIV   SYSCLK_DIVIDER_1
#define APBCLK_DIV   APBCLK_DIVIDER_2
#define SYSCLK_FREQ  96000000
#define APB_BUS_FREQ 48000000

#elif USE_XTAL == XTAL_4M
#define PLL_POSDIV   PLL_POSDIV_4
#define PLL_FBKDIV   192
#define PLL_PREDIV   PLL_PREDIV_1
#define SYSCLK_DIV   SYSCLK_DIVIDER_1
#define APBCLK_DIV   APBCLK_DIVIDER_2
#define SYSCLK_FREQ  96000000
#define APB_BUS_FREQ 48000000

#elif USE_XTAL == XTAL_30M
#define PLL_POSDIV   PLL_POSDIV_4
#define PLL_FBKDIV   12
#define PLL_PREDIV   PLL_PREDIV_1
#define SYSCLK_DIV   SYSCLK_DIVIDER_1
#define APBCLK_DIV   APBCLK_DIVIDER_1
#define SYSCLK_FREQ  45000000
#define APB_BUS_FREQ 45000000

#else
#error
#endif

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
/* ToDo: add here your necessary defines for device initialization
         following is an example for different system frequencies             */
#define __SYSTEM_CLOCK    SYSCLK_FREQ

#ifdef __cplusplus
}
#endif


#endif  /* AC78xx_H */

