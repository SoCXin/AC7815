;/* Copyright Statement:
; *
; * This software/firmware and related documentation ("AutoChips Software") are
; * protected under relevant copyright laws. The information contained herein is
; * confidential and proprietary to AutoChips Inc. and/or its licensors. Without
; * the prior written permission of AutoChips inc. and/or its licensors, any
; * reproduction, modification, use or disclosure of AutoChips Software, and
; * information contained herein, in whole or in part, shall be strictly
; * prohibited.
; *
; * AutoChips Inc. (C) 2016. All rights reserved.
; *
; * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
; * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("AUTOCHIPS SOFTWARE")
; * RECEIVED FROM AUTOCHIPS AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
; * ON AN "AS-IS" BASIS ONLY. AUTOCHIPS EXPRESSLY DISCLAIMS ANY AND ALL
; * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
; * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
; * NONINFRINGEMENT. NEITHER DOES AUTOCHIPS PROVIDE ANY WARRANTY WHATSOEVER WITH
; * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
; * INCORPORATED IN, OR SUPPLIED WITH THE AUTOCHIPS SOFTWARE, AND RECEIVER AGREES
; * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
; * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER''S SOLE RESPONSIBILITY TO
; * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN AUTOCHIPS
; * SOFTWARE. AUTOCHIPS SHALL ALSO NOT BE RESPONSIBLE FOR ANY AUTOCHIPS SOFTWARE
; * RELEASES MADE TO RECEIVER''S SPECIFICATION OR TO CONFORM TO A PARTICULAR
; * STANDARD OR OPEN FORUM. RECEIVER''S SOLE AND EXCLUSIVE REMEDY AND AUTOCHIPS''S
; * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE AUTOCHIPS SOFTWARE
; * RELEASED HEREUNDER WILL BE, AT AUTOCHIPS''S OPTION, TO REVISE OR REPLACE THE
; * AUTOCHIPS SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
; * CHARGE PAID BY RECEIVER TO AUTOCHIPS FOR SUCH AUTOCHIPS SOFTWARE AT ISSUE.
; */
;* File Name          : startup_ac78xx.s
;*
;* @file startup_ac78xx.s
;*
;* @author AutoChips
;*
;* @version 0.0.1
;*
;* @date Jan.02.2019
;* Description        : AC78xx Devices vector table for EWARM
;*                      toolchain.
;*                      This module performs:
;*                      - Set the initial SP
;*                      - Configure the clock system
;*                      - Set the initial PC == __iar_program_start,
;*                      - Set the vector table entries with the exceptions ISR 
;*                        address.
;*                      After Reset the Cortex-M3 processor is in Thread mode,
;*                      priority is Privileged, and the Stack is set to Main.
;********************************************************************************
;
; The modules in this file are included in the libraries, and may be replaced
; by any user-defined modules that define the PUBLIC symbol _program_start or
; a user defined start symbol.
; To override the cstartup defined in the library, simply add your modified
; version to the workbench project.
;
; The vector table is normally located at address 0.
; When debugging in RAM, it can be located in RAM, aligned to at least 2^6.
; The name "__vector_table" has special meaning for C-SPY:
; it is where the SP start value is found, and the NVIC vector
; table register (VTOR) is initialized to this address if != 0.
;
; Cortex-M version
;

        MODULE  ?cstartup

        ;; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)

        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        EXTERN  SystemInit        
        PUBLIC  __vector_table
        PUBLIC  __Vectors
        PUBLIC  __Vectors_End
        PUBLIC  __Vectors_Size

        DATA
__vector_table
        DCD     sfe(CSTACK)
        DCD     Reset_Handler             ; Reset Handler
        DCD     NMI_Handler               ; NMI Handler
        DCD     HardFault_Handler         ; Hard Fault Handler
        DCD     MemManage_Handler         ; MPU Fault Handler
        DCD     BusFault_Handler          ; Bus Fault Handler
        DCD     UsageFault_Handler        ; Usage Fault Handler
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     SVC_Handler               ; SVCall Handler
        DCD     DebugMon_Handler          ; Debug Monitor Handler
        DCD     0                         ; Reserved
        DCD     PendSV_Handler            ; PendSV Handler
        DCD     SysTick_Handler           ; SysTick Handler

         ; External Interrupts
        DCD     PWDT_IRQHandler
        DCD     UART1_IRQHandler
        DCD     UART2_IRQHandler
        DCD     UART3_IRQHandler
        DCD     UART4_IRQHandler
        DCD     UART5_IRQHandler
        DCD     UART6_IRQHandler
        DCD     EXTI0_IRQHandler
        DCD     EXTI1_IRQHandler
        DCD     EXTI2_IRQHandler
        DCD     EXTI3_IRQHandler
        DCD     EXTI4_IRQHandler
        DCD     EXTI5_9_IRQHandler
        DCD     SPI1_IRQHandler
        DCD     SPI2_IRQHandler
        DCD     I2C1_IRQHandler
        DCD     I2C2_IRQHandler
        DCD     DMA1_IRQHandler
        DCD     DMA2_IRQHandler
        DCD     DMA3_IRQHandler
        DCD     DMA4_IRQHandler
        DCD     DMA5_IRQHandler
        DCD     DMA6_IRQHandler
        DCD     DMA7_IRQHandler
        DCD     DMA8_IRQHandler
        DCD     DMA9_IRQHandler
        DCD     DMA10_IRQHandler
        DCD     DMA11_IRQHandler
        DCD     DMA12_IRQHandler
        DCD     TIMER0_IRQHandler
        DCD     TIMER1_IRQHandler
        DCD     BKP_IRQHandler
        DCD     RTC_IRQHandler
        DCD     Watchdog_IRQHandler
        DCD     PWM0_IRQHandler
        DCD     PWM1_IRQHandler
        DCD     PWM2_IRQHandler
        DCD     PVD_Handler
        DCD     LIN0_Handler
        DCD     EXTI10_15_IRQHandler
        DCD     SPM_IRQHandler
        DCD     0
        DCD     CAN1_Handler
        DCD     CAN2_Handler
        DCD     ADC_IRQHandler
        DCD     ACMP0_IRQHandler
        DCD     ACMP1_IRQHandler
        DCD     TIMER2_IRQHandler
        DCD     TIMER3_IRQHandler
        DCD     TIMER4_IRQHandler
        DCD     TIMER5_IRQHandler
        DCD     TIMER6_IRQHandler
        DCD     TIMER7_IRQHandler
        DCD     PWM3_IRQHandler
        DCD     EFlash_IRQHandler

__Vectors_End

__Vectors       EQU   __vector_table
__Vectors_Size  EQU   __Vectors_End - __Vectors
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
        THUMB

        PUBWEAK Reset_Handler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reset_Handler
        LDR     R0, =SystemInit
        BLX     R0
        LDR     R0, =__iar_program_start
        BX      R0
        
        PUBWEAK NMI_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
NMI_Handler
        B NMI_Handler
        
        PUBWEAK HardFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
HardFault_Handler
        B HardFault_Handler
        
        PUBWEAK MemManage_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
MemManage_Handler
        B MemManage_Handler
        
        PUBWEAK BusFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
BusFault_Handler
        B BusFault_Handler
        
        PUBWEAK UsageFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
UsageFault_Handler
        B UsageFault_Handler
        
        PUBWEAK SVC_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SVC_Handler
        B SVC_Handler
        
        PUBWEAK DebugMon_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
DebugMon_Handler
        B DebugMon_Handler
        
        PUBWEAK PendSV_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
PendSV_Handler
        B PendSV_Handler
        
        PUBWEAK SysTick_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SysTick_Handler
        B SysTick_Handler
        
        PUBWEAK PWDT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
PWDT_IRQHandler
        B PWDT_IRQHandler
        
        PUBWEAK UART1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART1_IRQHandler
        B UART1_IRQHandler
        
        PUBWEAK UART2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART2_IRQHandler
        B UART2_IRQHandler
        
        PUBWEAK UART3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART3_IRQHandler
        B UART3_IRQHandler
        
        PUBWEAK UART4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART4_IRQHandler
        B UART4_IRQHandler
        
        PUBWEAK UART5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART5_IRQHandler
        B UART5_IRQHandler
        
        PUBWEAK UART6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART6_IRQHandler
        B UART6_IRQHandler
        
        PUBWEAK EXTI0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI0_IRQHandler
        B EXTI0_IRQHandler
        
        PUBWEAK EXTI1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI1_IRQHandler
        B EXTI1_IRQHandler
        
        PUBWEAK EXTI2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI2_IRQHandler
        B EXTI2_IRQHandler
        
        PUBWEAK EXTI3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI3_IRQHandler
        B EXTI3_IRQHandler
        
        PUBWEAK EXTI4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI4_IRQHandler
        B EXTI4_IRQHandler
        
        PUBWEAK EXTI5_9_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI5_9_IRQHandler
        B EXTI5_9_IRQHandler
        
        PUBWEAK SPI1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI1_IRQHandler
        B SPI1_IRQHandler
        
        PUBWEAK SPI2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI2_IRQHandler
        B SPI2_IRQHandler
        
        PUBWEAK I2C1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C1_IRQHandler
        B I2C1_IRQHandler
        
        PUBWEAK I2C2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C2_IRQHandler
        B I2C2_IRQHandler
        
        PUBWEAK DMA1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA1_IRQHandler
        B DMA1_IRQHandler

        PUBWEAK DMA2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA2_IRQHandler
        B DMA2_IRQHandler

        PUBWEAK DMA3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA3_IRQHandler
        B DMA3_IRQHandler

        PUBWEAK DMA4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA4_IRQHandler
        B DMA4_IRQHandler

        PUBWEAK DMA5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA5_IRQHandler
        B DMA5_IRQHandler

        PUBWEAK DMA6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA6_IRQHandler
        B DMA6_IRQHandler

        PUBWEAK DMA7_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA7_IRQHandler
        B DMA7_IRQHandler

        PUBWEAK DMA8_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA8_IRQHandler
        B DMA8_IRQHandler

        PUBWEAK DMA9_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA9_IRQHandler
        B DMA9_IRQHandler

        PUBWEAK DMA10_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA10_IRQHandler
        B DMA10_IRQHandler

        PUBWEAK DMA11_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA11_IRQHandler
        B DMA11_IRQHandler  

        PUBWEAK DMA12_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA12_IRQHandler
        B DMA12_IRQHandler
		
        PUBWEAK TIMER0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER0_IRQHandler
        B TIMER0_IRQHandler
        
        PUBWEAK TIMER1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER1_IRQHandler
        B TIMER1_IRQHandler
        
        PUBWEAK BKP_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
BKP_IRQHandler
        B BKP_IRQHandler
        
        PUBWEAK RTC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
RTC_IRQHandler
        B RTC_IRQHandler
        
        PUBWEAK Watchdog_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
Watchdog_IRQHandler
        B Watchdog_IRQHandler
        
        PUBWEAK PWM0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
PWM0_IRQHandler
        B PWM0_IRQHandler
        
        PUBWEAK PWM1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
PWM1_IRQHandler
        B PWM1_IRQHandler
        
        PUBWEAK PWM2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
PWM2_IRQHandler
        B PWM2_IRQHandler
        
        PUBWEAK PVD_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
PVD_Handler
        B PVD_Handler
        
        PUBWEAK LIN0_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
LIN0_Handler
        B LIN0_Handler
        
        PUBWEAK EXTI10_15_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI10_15_IRQHandler
        B EXTI10_15_IRQHandler
        
        PUBWEAK SPM_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPM_IRQHandler
        B SPM_IRQHandler
        
        PUBWEAK CAN1_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
CAN1_Handler
        B CAN1_Handler
        
        PUBWEAK CAN2_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
CAN2_Handler
        B CAN2_Handler
                      
        PUBWEAK ADC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADC_IRQHandler
        B ADC_IRQHandler

        PUBWEAK ACMP0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ACMP0_IRQHandler
        B ACMP0_IRQHandler

        PUBWEAK ACMP1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ACMP1_IRQHandler
        B ACMP1_IRQHandler

        PUBWEAK TIMER2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER2_IRQHandler
        B TIMER2_IRQHandler

        PUBWEAK TIMER3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER3_IRQHandler
        B TIMER3_IRQHandler

		PUBWEAK TIMER4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER4_IRQHandler
        B TIMER4_IRQHandler
		
		PUBWEAK TIMER5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER5_IRQHandler
        B TIMER5_IRQHandler
		
		PUBWEAK TIMER6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER6_IRQHandler
        B TIMER6_IRQHandler
		
		PUBWEAK TIMER7_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER7_IRQHandler
        B TIMER7_IRQHandler
		
		PUBWEAK PWM3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
PWM3_IRQHandler
        B PWM3_IRQHandler
		
		PUBWEAK EFlash_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EFlash_IRQHandler
        B EFlash_IRQHandler
        END
/************************END OF FILE****/
