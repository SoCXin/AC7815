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

#ifndef AC78xx_CTU_REG_H_
#define AC78xx_CTU_REG_H_
#ifdef __cplusplus
extern "C" {
#endif
#include "stdint.h"
#include "stdio.h"


#define __IO    volatile                    ///< All drivers need this type
#define __I     volatile const
#define __STATIC_INLINE static __inline
typedef struct {                                    ///< CTU Structure
    __IO uint32_t  CONFIG1;                           ///< CTU Configuration Register 1
    __IO uint32_t  CONFIG2;                           ///< CTU Configuration Register 2
} CTU_Type;
/* ================================================================================ */
/* ================          struct 'CTU' Position & Mask          ================ */
/* ================================================================================ */


/* ---------------------------------  CTU_CONFIG1  -------------------------------- */
#define CTU_CONFIG1_ACTRG_Pos                 5                                                       ///< CTU CONFIG1: ACTRG Position             
#define CTU_CONFIG1_ACTRG_Msk                 (0x01UL << CTU_CONFIG1_ACTRG_Pos)                       ///< CTU CONFIG1: ACTRG Mask                 
#define CTU_CONFIG1_RXDFE_Pos                 8                                                       ///< CTU CONFIG1: RXDFE Position             
#define CTU_CONFIG1_RXDFE_Msk                 (0x03UL << CTU_CONFIG1_RXDFE_Pos)                       ///< CTU CONFIG1: RXDFE Mask                 
#define CTU_CONFIG1_RXDFE(x)                  (((uint32_t)(((uint32_t)(x))<<CTU_CONFIG1_RXDFE_Pos))&CTU_CONFIG1_RXDFE_Msk)
#define CTU_CONFIG1_RTCC_Pos                  10                                                      ///< CTU CONFIG1: RTCC Position              
#define CTU_CONFIG1_RTCC_Msk                  (0x01UL << CTU_CONFIG1_RTCC_Pos)                        ///< CTU CONFIG1: RTCC Mask                  
#define CTU_CONFIG1_ACIC_Pos                  11                                                      ///< CTU CONFIG1: ACIC Position              
#define CTU_CONFIG1_ACIC_Msk                  (0x01UL << CTU_CONFIG1_ACIC_Pos)                        ///< CTU CONFIG1: ACIC Mask                  
#define CTU_CONFIG1_RXDCE_Pos                 12                                                      ///< CTU CONFIG1: RXDCE Position             
#define CTU_CONFIG1_RXDCE_Msk                 (0x01UL << CTU_CONFIG1_RXDCE_Pos)                       ///< CTU CONFIG1: RXDCE Mask                 
#define CTU_CONFIG1_PWMSYNC_Pos               14                                                      ///< CTU CONFIG1: PWMSYNC Position           
#define CTU_CONFIG1_PWMSYNC_Msk               (0x01UL << CTU_CONFIG1_PWMSYNC_Pos)                     ///< CTU CONFIG1: PWMSYNC Mask               
#define CTU_CONFIG1_TXDME_Pos                 15                                                      ///< CTU CONFIG1: TXDME Position             
#define CTU_CONFIG1_TXDME_Msk                 (0x01UL << CTU_CONFIG1_TXDME_Pos)                       ///< CTU CONFIG1: TXDME Mask                 
#define CTU_CONFIG1_CLK_Pos                   16                                                      ///< CTU CONFIG1: CLK Position               
#define CTU_CONFIG1_CLK_Msk                   (0x07UL << CTU_CONFIG1_CLK_Pos)                         ///< CTU CONFIG1: CLK Mask                   
#define CTU_CONFIG1_CLK(x)                    (((uint32_t)(((uint32_t)(x))<<CTU_CONFIG1_CLK_Pos))&CTU_CONFIG1_CLK_Msk)
#define CTU_CONFIG1_ADHWT1_Pos                20                                                      ///< CTU CONFIG1: ADHWT1 Position             
#define CTU_CONFIG1_ADHWT1_Msk                (0x07UL << CTU_CONFIG1_ADHWT1_Pos)                      ///< CTU CONFIG1: ADHWT1 Mask                 
#define CTU_CONFIG1_ADHWT1(x)				  (((uint32_t)(((uint32_t)(x))<<CTU_CONFIG1_ADHWT1_Pos))&CTU_CONFIG1_ADHWT1_Msk)
#define CTU_CONFIG1_DLYACT_Pos                23                                                      ///< CTU CONFIG1: DLYACT Position            
#define CTU_CONFIG1_DLYACT_Msk                (0x01UL << CTU_CONFIG1_DLYACT_Pos)                      ///< CTU CONFIG1: DLYACT Mask                
#define CTU_CONFIG1_DELAY_Pos                 24                                                      ///< CTU CONFIG1: DELAY Position             
#define CTU_CONFIG1_DELAY_Msk                 (0x000000ffUL << CTU_CONFIG1_DELAY_Pos)                 ///< CTU CONFIG1: DELAY Mask                 
#define CTU_CONFIG1_DELAY(x)                  (((uint32_t)(((uint32_t)(x))<<CTU_CONFIG1_DELAY_Pos))&CTU_CONFIG1_DELAY_Msk)
/* ---------------------------------  CTU_CONFIG2  -------------------------------- */
#define CTU_CONFIG2_ACPWDTS_Pos               3                                                       ///< CTU CONFIG2: ACPWTS Position            
#define CTU_CONFIG2_ACPWDTS_Msk                (0x01UL << CTU_CONFIG2_ACPWDTS_Pos)                      ///< CTU CONFIG2: ACPWTS Mask                
#define CTU_CONFIG2_UARTPWDTS_Pos             4                                                       ///< CTU CONFIG2: UARTPWDTS Position         
#define CTU_CONFIG2_UARTPWDTS_Msk             (0x03UL << CTU_CONFIG2_UARTPWDTS_Pos)                   ///< CTU CONFIG2: UARTPWDTS Mask             
#define CTU_CONFIG2_UARTPWDTS(x)              (((uint32_t)(((uint32_t)(x))<<CTU_CONFIG2_UARTPWDTS_Pos))&CTU_CONFIG2_UARTPWDTS_Msk)
#define CTU_CONFIG2_ADHWT2_Pos                6                                                       ///< CTU CONFIG2: ADHWT2 Position            
#define CTU_CONFIG2_ADHWT2_Msk                (0x07UL << CTU_CONFIG2_ADHWT2_Pos)                      ///< CTU CONFIG2: ADHWT2 Mask                
#define CTU_CONFIG2_ADHWT2(x)                 (((uint32_t)(((uint32_t)(x))<<CTU_CONFIG2_ADHWT2_Pos))&CTU_CONFIG2_ADHWT2_Msk)
/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */
#define CTU_BASE                        0x40016000UL
/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */
#define CTU                             ((CTU_Type                *) CTU_BASE)


/**
* @param[in] delayCnt: Trigger delay value
*
* @return none
*
* @brief delay PWM2 triggering ADC for delayCnt bus clock output divide
*/
__STATIC_INLINE void CTU_SetPwm2Trig2AdcDelayCnt(uint8_t delayCnt)
{
    CTU->CONFIG1 &= ~CTU_CONFIG1_DELAY_Msk;
    CTU->CONFIG1 |= CTU_CONFIG1_DELAY(delayCnt);
}
/**
* @param[in] none
*
* @return none
*
* @brief Uart1 RXD connect with Uart module  and PWM0 channel 1
*/
__STATIC_INLINE void CTU_EnableUart1RxdConnectToPwm0Ch1(void)
{
    CTU->CONFIG1 |= (CTU_CONFIG1_RXDCE_Msk);
}
/**
* @param[in] none
*
* @return none
*
* @brief Disable Uart1 RXD connect with Uart module  and PWM0 channel 1
*/
__STATIC_INLINE void CTU_DisableUart1RxdConnectToPwm0Ch1(void)
{
    CTU->CONFIG1 &= ~(CTU_CONFIG1_RXDCE_Msk);
}
/**
* @param[in] none
*
* @return none
*
* @brief enable Uart1 TX modulation By PWM0 Channel0
*/
__STATIC_INLINE void CTU_EnableUart1ModulationByPwm0Ch0(void)
{
    CTU->CONFIG1 |= (CTU_CONFIG1_TXDME_Msk);
}
/**
* @param[in] none
*
* @return none
*
* @brief Disable Uart1 TX modulation By PWM0 Channel0
*/
__STATIC_INLINE void CTU_DisableUart1ModulationByPwm0Ch0(void)
{
    CTU->CONFIG1 &= ~(CTU_CONFIG1_TXDME_Msk);
}
/**
* @param[in] none
*
* @return none
*
* @brief generate a softare sync trigger to PWM2 module (trigger)
*/
__STATIC_INLINE void CTU_GenerateSoftwareTrig2Pwm2(void)
{
    CTU->CONFIG1 |= (CTU_CONFIG1_PWMSYNC_Msk);
}
/**
* @param[in] none
*
* @return none
*
* @brief Uart1 RXD input signal is connected to Uart module directly
*/
__STATIC_INLINE void CTU_ByPassUart1Filter(void)
{
    CTU->CONFIG1 &= ~(CTU_CONFIG1_RXDFE_Msk);
}
/**
* @param[in] none
*
* @return none
*
* @brief Uart RXD1 input signal is filtered by ACMP0, then injected to Uart
*/
__STATIC_INLINE void CTU_EnableUart1FilterByAcmp0(void)
{
    CTU->CONFIG1 = (CTU->CONFIG1 & ~(CTU_CONFIG1_RXDFE_Msk)) | CTU_CONFIG1_RXDFE(1);
}
/**
* @param[in] none
*
* @return none
*
* @brief Uart1 RXD input signal is filtered by ACMP1, then injected to Uart
*/
__STATIC_INLINE void CTU_EnableUart1FilterByAcmp1(void)
{
    CTU->CONFIG1 = (CTU->CONFIG1 & ~(CTU_CONFIG1_RXDFE_Msk)) | CTU_CONFIG1_RXDFE(2);
}
/**
* @param[in] uartSource: Select ACMP0 or ACMP1 to filter UART1 RX
*
* @return none
*
* @brief set Uart1 Filter Source
*/
__STATIC_INLINE void CTU_SetUart1FilterSource(uint8_t uartSource)
{
    CTU->CONFIG1 = (CTU->CONFIG1 & ~(CTU_CONFIG1_RXDFE_Msk)) | CTU_CONFIG1_RXDFE(uartSource);
}
/**
* @param[in] none
*
* @return none
*
* @brief set ADC hardware trigger source to RTC overflow
*/
__STATIC_INLINE void CTU_TriggerAdcRegularGroupByRtcOverflow(void)
{
    CTU->CONFIG1 &= ~(CTU_CONFIG1_ADHWT1_Msk);
}
/**
* @param[in] none
*
* @return none
*
* @brief set ADC hardware trigger source to TIMER
*/
__STATIC_INLINE void CTU_TriggerAdcRegularGroupByPwm0Init(void)
{
    CTU->CONFIG1 = (CTU->CONFIG1 & ~(CTU_CONFIG1_ADHWT1_Msk)) | CTU_CONFIG1_ADHWT1(1);
}
/**
* @param[in] none
*
* @return none
*
* @brief set ADC hardware trigger source to PWM2 init trigger with 8-bit programmable delay
*/
__STATIC_INLINE void CTU_TriggerAdcRegularGroupByPwm2Init(void)
{
    CTU->CONFIG1 = (CTU->CONFIG1 & ~(CTU_CONFIG1_ADHWT1_Msk)) | CTU_CONFIG1_ADHWT1(2);
}

/**
* @param[in] none
*
* @return none
*
* @brief set ADC hardware trigger source to PWM2 match trigger with 8-bit programmable delay
*/
__STATIC_INLINE void CTU_TriggerAdcRegularGroupByPwm2Match(void)
{
    CTU->CONFIG1 = (CTU->CONFIG1 & ~(CTU_CONFIG1_ADHWT1_Msk)) | CTU_CONFIG1_ADHWT1(3);
}
/**
* @param[in] none
*
* @return none
*
* @brief set ADC hardware trigger source to TIMER channel0 overflow
*/
__STATIC_INLINE void CTU_TriggerAdcRegularGroupByTimerCh0Overflow(void)
{
    CTU->CONFIG1 = (CTU->CONFIG1 & ~(CTU_CONFIG1_ADHWT1_Msk)) | CTU_CONFIG1_ADHWT1(4);
}
/**
* @param[in] none
*
* @return none
*
* @brief set ADC hardware trigger source to TIMER channel1 overflow
*/
__STATIC_INLINE void CTU_TriggerAdcRegularGroupByTimerChannel1Overflow(void)
{
    CTU->CONFIG1 = (CTU->CONFIG1 & ~(CTU_CONFIG1_ADHWT1_Msk)) | CTU_CONFIG1_ADHWT1(5);
}
/**
* @param[in] none
*
* @return none
*
* @brief set ADC hardware trigger source to ACMP0 out
*/
__STATIC_INLINE void CTU_TriggerAdcRegularGroupByAcmp0Out(void)
{
    CTU->CONFIG1 = (CTU->CONFIG1 & ~(CTU_CONFIG1_ADHWT1_Msk)) | CTU_CONFIG1_ADHWT1(6);
}
/**
* @param[in] none
*
* @return none
*
* @brief set ADC hardware trigger source to ACMP1 out
*/
__STATIC_INLINE void CTU_TriggerAdcRegularGroupByAcmp1Out(void)
{
    CTU->CONFIG1 = (CTU->CONFIG1 & ~(CTU_CONFIG1_ADHWT1_Msk)) | CTU_CONFIG1_ADHWT1(7);
}
/**
* @param[in] adcSource: Trigger Source for ADC Regular Group
*
* @return none
*
* @brief set Trigger ADC Regular group Source
*/
__STATIC_INLINE void CTU_TriggerAdcRegularGroupSource(uint8_t adcSource)
{
    CTU->CONFIG1 = (CTU->CONFIG1 & ~(CTU_CONFIG1_ADHWT1_Msk)) | CTU_CONFIG1_ADHWT1(adcSource);
}
/**
* @param[in] none
*
* @return none
*
* @brief Select ACMP0 output as the trigger0 input of PWM2
*/
__STATIC_INLINE void CTU_SelAcmp0AsPwm2Trigger0(void)
{
    CTU->CONFIG1 &= ~(CTU_CONFIG1_ACTRG_Msk);
}
/**
* @param[in] none
*
* @return none
*
* @brief Select ACMP1 output as the trigger0 input of PWM2
*/
__STATIC_INLINE void CTU_SelAcmp1AsPwm2Trigger0(void)
{
    CTU->CONFIG1 |= (CTU_CONFIG1_ACTRG_Msk);
}
/**
* @param[in] none
*
* @return none
*
* @brief enable RTC capture to PWM1 input channel1
*/
__STATIC_INLINE void CTU_EnableRtcCaptureByPwm1Ch1(void)
{
    CTU->CONFIG1 |= (CTU_CONFIG1_RTCC_Msk);
}
/**
* @param[in] none
*
* @return none
*
* @brief Diasble RTC capture to PWM1 input channel1
*/
__STATIC_INLINE void CTU_DisableRtcCaptureByPwm1Ch1(void)
{
    CTU->CONFIG1 &= ~(CTU_CONFIG1_RTCC_Msk);
}
/**
* @param[in] none
*
* @return none
*
* @brief enable ACMP0 input capture to PWM1 input channel0
*/
__STATIC_INLINE void CTU_EnableAcmp0InputCaptureByPwm1Ch0(void)
{
    CTU->CONFIG1 |= (CTU_CONFIG1_ACIC_Msk);
}
/**
* @param[in] none
*
* @return none
*
* @brief Disable ACMP0 input capture to PWM1 input channel0
*/
__STATIC_INLINE void CTU_DisableAcmp0InputCaptureByPwm1Ch0(void)
{
    CTU->CONFIG1 &= ~(CTU_CONFIG1_ACIC_Msk);
}
/**
* @param[in] u8Divide: Clock Divide Value
*
* @return none
*
* @brief set bus divide BUSDIV
*/
__STATIC_INLINE void CTU_SetBusDivide(uint8_t u8Divide)
{
    CTU->CONFIG1 = (CTU->CONFIG1 & ~(CTU_CONFIG1_CLK_Msk)) | CTU_CONFIG1_CLK(u8Divide);
}
/**
* @param[in] none
*
* @return none
*
* @brief set ADC hardware trigger source to RTC overflow
*/
__STATIC_INLINE void CTU_TriggerAdcInjectGroupByRtcOverflow(void)
{
    CTU->CONFIG2 &= ~(CTU_CONFIG2_ADHWT2_Msk);
}
/**
* @param[in] none
*
* @return none
*
* @brief set ADC hardware trigger source to TIMER
*/
__STATIC_INLINE void CTU_TriggerAdcInjectGroupByPwm0Init(void)
{
    CTU->CONFIG2 = (CTU->CONFIG2 & ~(CTU_CONFIG2_ADHWT2_Msk)) | CTU_CONFIG2_ADHWT2(1);
}
/**
* @param[in] none
*
* @return none
*
* @brief set ADC hardware trigger source to PWM2 init trigger with 8-bit programmable delay
*/
__STATIC_INLINE void CTU_TriggerAdcInjectGroupByPwm2Init(void)
{
    CTU->CONFIG2 = (CTU->CONFIG2 & ~(CTU_CONFIG2_ADHWT2_Msk)) | CTU_CONFIG2_ADHWT2(2);
}

/**
* @param[in] none
*
* @return none
*
* @brief set ADC hardware trigger source to PWM2 match trigger with 8-bit programmable delay
*/
__STATIC_INLINE void CTU_TriggerAdcInjectGroupByPwm2Match(void)
{
    CTU->CONFIG2 = (CTU->CONFIG2 & ~(CTU_CONFIG2_ADHWT2_Msk)) | CTU_CONFIG2_ADHWT2(3);
}
/**
* @param[in] none
*
* @return none
*
* @brief set ADC hardware trigger source to TIMER channel0 overflow
*/
__STATIC_INLINE void CTU_TriggerAdcInjectGroupByTimerCh0Overflow(void)
{
    CTU->CONFIG2 = (CTU->CONFIG2 & ~(CTU_CONFIG2_ADHWT2_Msk)) | CTU_CONFIG2_ADHWT2(4);
}
/**
* @param[in] none
*
* @return none
*
* @brief set ADC hardware trigger source to TIMER channel1 overflow
*/
__STATIC_INLINE void CTU_TriggerAdcInjectGroupByTimerChannel1Overflow(void)
{
    CTU->CONFIG2 = (CTU->CONFIG2 & ~(CTU_CONFIG2_ADHWT2_Msk)) | CTU_CONFIG2_ADHWT2(5);
}
/**
* @param[in] none
*
* @return none
*
* @brief set ADC hardware trigger source to ACMP0 out
*/
__STATIC_INLINE void CTU_TriggerAdcInjectGroupByAcmp0Out(void)
{
    CTU->CONFIG2 = (CTU->CONFIG2 & ~(CTU_CONFIG2_ADHWT2_Msk)) | CTU_CONFIG2_ADHWT2(6);
}
/**
* @param[in] none
*
* @return none
*
* @brief set ADC hardware trigger source to ACMP1 out
*/
__STATIC_INLINE void CTU_TriggerAdcInjectGroupByAcmp1Out(void)
{
    CTU->CONFIG2 = (CTU->CONFIG2 & ~(CTU_CONFIG2_ADHWT2_Msk)) | CTU_CONFIG2_ADHWT2(7);
}
/**
* @param[in] adcSource:adc Source to Trigger ADC Inject Group
*
* @return none
*
* @brief set Trigger ADC Inject group Source
*/
__STATIC_INLINE void CTU_TriggerAdcInjectGroupSource(uint8_t adcSource)
{
    CTU->CONFIG2 = (CTU->CONFIG2 & ~(CTU_CONFIG2_ADHWT2_Msk)) | CTU_CONFIG2_ADHWT2(adcSource);
}
/**
* @param[in] none
*
* @return none
*
* @brief select PWDTIN3 input signal from UartRX
*/
__STATIC_INLINE void CTU_SetPwdtIn3InputFromUart1Rx(void)
{
    CTU->CONFIG2 = (CTU->CONFIG2 & (~CTU_CONFIG2_UARTPWDTS_Msk)) | CTU_CONFIG2_UARTPWDTS(0);
}
/**
* @param[in] none
*
* @return none
*
* @brief select PWDTIN3 input signal from UARTRX
*/
__STATIC_INLINE void CTU_SetPwdtIn3InputFromUart2Rx(void)
{
    CTU->CONFIG2 = (CTU->CONFIG2 & (~CTU_CONFIG2_UARTPWDTS_Msk)) | CTU_CONFIG2_UARTPWDTS(1);
}
/**
* @param[in] none
*
* @return none
*
* @brief select PWDTIN3 input signal from UART2RXX
*/
__STATIC_INLINE void CTU_SetPwdtIn3InputFromUart3Rx(void)
{
    CTU->CONFIG2 = (CTU->CONFIG2 & (~CTU_CONFIG2_UARTPWDTS_Msk)) | CTU_CONFIG2_UARTPWDTS(2);
}
/**
* @param[in] uartSource: Select uart source for PWDT_IN3 Measurement
*
* @return none
*
* @brief select PWDTIN3 input signal Source
*/
__STATIC_INLINE void CTU_SetPwdtIn3InputSource(uint8_t uartSource)
{
    CTU->CONFIG2 = (CTU->CONFIG2 & (~CTU_CONFIG2_UARTPWDTS_Msk)) | CTU_CONFIG2_UARTPWDTS(uartSource);
}

/**
* @param[in] none
*
* @return none
*
* @brief Set ACMP1 OUT connect to PWDT_INT2
*/
__STATIC_INLINE void CTU_SetPwdtIn3InputFromAcmp1(void)
{
    CTU->CONFIG2 &= ~(CTU_CONFIG2_ACPWDTS_Msk);
}
/**
* @param[in]  none
*
* @return none
*
* @brief Set ACMP0 OUT connect to PWDT_INT2
*/
__STATIC_INLINE void CTU_SetPwdtIn3InputFromAcmp0(void)
{
    CTU->CONFIG2 |= (CTU_CONFIG2_ACPWDTS_Msk);
}
#ifdef __cplusplus
}
#endif
#endif /* CTU_H_ */
