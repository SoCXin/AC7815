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
* @file     ac78xx_pwdt_reg.h
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
#ifndef AC78XX_PWDT_REG_H_
#define AC78XX_PWDT_REG_H_
#ifdef __cplusplus
extern "C" {
#endif
  
#if defined(__CC_ARM)
  #pragma anon_unions
#elif defined(CCARM__)
  #pragma language=extended
#elif defined (__ICCARM__)
/* anonymous unions are enabled by default */
#elif defined(__GNUC__)
/* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif

/**
* Includes
*/
#include "stdint.h"

#define __IO    volatile                    ///<All drivers need this type
#define __I     volatile const

#if defined ( __ICCARM__ )
#define __STATIC_INLINE static inline
#elif defined ( __GNUC__)
#define __STATIC_INLINE static inline
#elif defined (__CC_ARM)
#define __STATIC_INLINE static __inline
#endif

/**
  * @brief Pulse Width Detection Timer (PWDT)
  */

typedef struct {                                      ///< PWDT Structure
    __IO uint32_t  INIT0;                             ///< PWDT Initialize Register 0
    __I  uint32_t  NPWCV;                             ///< Negative Pulse Width Count Value
    __IO uint32_t  INIT1;                             ///< Pulse Width Detection Timer Initialize Register 1
} PWDT_Type;

/* ---------------------------------  PWDT_INIT0  --------------------------------- */
#define PWDT_INIT0_OVF_Pos                    0                                                       ///< PWDT INIT0: OVF Position
#define PWDT_INIT0_OVF_Msk                    (0x01UL << PWDT_INIT0_OVF_Pos)                          ///< PWDT INIT0: OVF Mask
#define PWDT_INIT0_RDYF_Pos                   1                                                       ///< PWDT INIT0: RDYF Position
#define PWDT_INIT0_RDYF_Msk                   (0x01UL << PWDT_INIT0_RDYF_Pos)                         ///< PWDT INIT0: RDYF Mask
#define PWDT_INIT0_SR_Pos                     2                                                       ///< PWDT INIT0: SR Position
#define PWDT_INIT0_SR_Msk                     (0x01UL << PWDT_INIT0_SR_Pos)                           ///< PWDT INIT0: SR Mask
#define PWDT_INIT0_OVIE_Pos                   3                                                       ///< PWDT INIT0: OVIE Position
#define PWDT_INIT0_OVIE_Msk                   (0x01UL << PWDT_INIT0_OVIE_Pos)                         ///< PWDT INIT0: OVIE Mask
#define PWDT_INIT0_PRDYIE_Pos                 4                                                       ///< PWDT INIT0: PRDYIE Position
#define PWDT_INIT0_PRDYIE_Msk                 (0x01UL << PWDT_INIT0_PRDYIE_Pos)                       ///< PWDT INIT0: PRDYIE Mask
#define PWDT_INIT0_IE_Pos                     5                                                       ///< PWDT INIT0: IE Position
#define PWDT_INIT0_IE_Msk                     (0x01UL << PWDT_INIT0_IE_Pos)                           ///< PWDT INIT0: IE Mask
#define PWDT_INIT0_PWDTEN_Pos                 6                                                       ///< PWDT INIT0: PWDTEN Position
#define PWDT_INIT0_PWDTEN_Msk                 (0x01UL << PWDT_INIT0_PWDTEN_Pos)                       ///< PWDT INIT0: PWDTEN Mask
#define PWDT_INIT0_PSC_Pos                    7                                                       ///< PWDT INIT0: PSC Position
#define PWDT_INIT0_PSC_Msk                    (0x07UL << PWDT_INIT0_PSC_Pos)                          ///< PWDT INIT0: PSC Mask
#define PWDT_INIT0_EDGE_Pos                   10                                                      ///< PWDT INIT0: EDGE Position
#define PWDT_INIT0_EDGE_Msk                   (0x03UL << PWDT_INIT0_EDGE_Pos)                         ///< PWDT INIT0: EDGE Mask
#define PWDT_INIT0_PINSEL_Pos                 12                                                      ///< PWDT INIT0: PINSEL Position
#define PWDT_INIT0_PINSEL_Msk                 (0x07UL << PWDT_INIT0_PINSEL_Pos)                       ///< PWDT INIT0: PINSEL Mask
#define PWDT_INIT0_PCLKSEL_Pos                15                                                      ///< PWDT INIT0: PCLKSEL Position
#define PWDT_INIT0_PCLKSEL_Msk                (0x01UL << PWDT_INIT0_PCLKSEL_Pos)                      ///< PWDT INIT0: PCLKSEL Mask
#define PWDT_INIT0_PPWCV_Pos                  16                                                      ///< PWDT INIT0: PPWCV Position
#define PWDT_INIT0_PPWCV_Msk                  (0x0000ffffUL << PWDT_INIT0_PPWCV_Pos)                  ///< PWDT INIT0: PPWCV Mask

/* ---------------------------------  PWDT_NPWCV  --------------------------------- */
#define PWDT_NPWCV_NPWCV_Pos                  0                                                       ///< PWDT NPWCV: NPWCV Position
#define PWDT_NPWCV_NPWCV_Msk                  (0x0000ffffUL << PWDT_NPWCV_NPWCV_Pos)                  ///< PWDT NPWCV: NPWCV Mask
#define PWDT_NPWCV_PWDTC_Pos                  16                                                      ///< PWDT NPWCV: PWDTC Position
#define PWDT_NPWCV_PWDTC_Msk                  (0x0000ffffUL << PWDT_NPWCV_PWDTC_Pos)                  ///< PWDT NPWCV: PWDTC Mask

/* ---------------------------------  PWDT_INIT1  --------------------------------- */
#define PWDT_INIT1_FILTVAL_Pos                0                                                       ///< PWDT INIT1: FILTVAL Position
#define PWDT_INIT1_FILTVAL_Msk                (0x0fUL << PWDT_INIT1_FILTVAL_Pos)                      ///< PWDT INIT1: FILTVAL Mask
#define PWDT_INIT1_FILTPSC_Pos                4                                                       ///< PWDT INIT1: FILTPSC Position
#define PWDT_INIT1_FILTPSC_Msk                (0x0fUL << PWDT_INIT1_FILTPSC_Pos)                      ///< PWDT INIT1: FILTPSC Mask
#define PWDT_INIT1_FILTEN_Pos                 8                                                       ///< PWDT INIT1: FILTEN Position
#define PWDT_INIT1_FILTEN_Msk                 (0x01UL << PWDT_INIT1_FILTEN_Pos)                       ///< PWDT INIT1: FILTEN Mask
#define PWDT_INIT1_HALLEN_Pos                 9                                                       ///< PWDT INIT1: HALLEN Position
#define PWDT_INIT1_HALLEN_Msk                 (0x01UL << PWDT_INIT1_HALLEN_Pos)                       ///< PWDT INIT1: HALLEN Mask
#define PWDT_INIT1_TIMEN_Pos                  10                                                      ///< PWDT INIT1: TIMEN Position
#define PWDT_INIT1_TIMEN_Msk                  (0x01UL << PWDT_INIT1_TIMEN_Pos)                        ///< PWDT INIT1: TIMEN Mask
#define PWDT_INIT1_CMPEN_Pos                  11                                                      ///< PWDT INIT1: TIMEN Position
#define PWDT_INIT1_CMPEN_Msk                  (0x01UL << PWDT_INIT1_CMPEN_Pos)                        ///< PWDT INIT1: TIMEN Mask
#define PWDT_INIT1_TIMCNTVAL_Pos              12                                                      ///< PWDT INIT1: TIMCNTVAL Position
#define PWDT_INIT1_TIMCNTVAL_Msk              (0x0000ffffUL << PWDT_INIT1_TIMCNTVAL_Pos)              ///< PWDT INIT1: TIMCNTVAL Mask
#define PWDT_INIT1_HALLSTATUS_Pos             28                                                      ///< PWDT INIT1: HALLSTATUS Position
#define PWDT_INIT1_HALLSTATUS_Msk             (0x07UL << PWDT_INIT1_HALLSTATUS_Pos)                   ///< PWDT INIT1: HALLSTATUS Mask


/* PWDT - Peripheral instance base addresses */
/** Peripheral PWDT base address */
#define PWDT_BASE                                 (0x40017000u)
/** Peripheral PWDT base pointer */
#define PWDT                                      ((PWDT_Type *)PWDT_BASE)
/** Array initializer of PWDT peripheral base pointers */
#define PWDT_BASES                                { PWDT }

/**
*
* @param[in] none
*
* @return none
*
* @brief enable PWDT module.
*
*/
__STATIC_INLINE void PWDT_Enable(void)
{
    PWDT->INIT0 |= PWDT_INIT0_PWDTEN_Msk;
}
/**
*
* @param[in] none
*
* @return none
*
* @brief disable PWDT module.
*
*/
__STATIC_INLINE void PWDT_Disable(void)
{
    PWDT->INIT0 &= ~PWDT_INIT0_PWDTEN_Msk;
}

/**
*
* @param[in] none
*
* @return none
*
* @brief enable PWDT module interrupt.
*
*/
__STATIC_INLINE void PWDT_EnableInt(void)
{
    PWDT->INIT0 |= PWDT_INIT0_IE_Msk;
}

/**
*
* @param[in] none
*
* @return none
*
* @brief disable PWDT module interrupt.
*
*/
__STATIC_INLINE void PWDT_DisableInt(void)
{
    PWDT->INIT0 &= ~PWDT_INIT0_IE_Msk;
}
/**
*
* @param[in] none
*
* @return none
*
* @brief enable PWDT module timer over flow interrupt.
*
*/
__STATIC_INLINE void PWDT_EnableOverFlowInt(void)
{
    PWDT->INIT0 |= PWDT_INIT0_OVIE_Msk;
}

/**
*
* @param[in] none
*
* @return none
*
* @brief disable PWDT module timer over flow interrupt.
*
*/
__STATIC_INLINE void PWDT_DisableOverFlowInt(void)
{
    PWDT->INIT0 &= ~PWDT_INIT0_OVIE_Msk;
}
/**
*
* @param[in] none
*
* @return none
*
* @brief enable PWDT module data ready interrupt.
*
*/
__STATIC_INLINE void PWDT_EnableReadyInt(void)
{
    PWDT->INIT0 |= PWDT_INIT0_PRDYIE_Msk;
}
/**
*
* @param[in] none
*
* @return none
*
* @brief disable PWDT module data ready interrupt.
*
*/
__STATIC_INLINE void PWDT_DisableReadyInt(void)
{
    PWDT->INIT0 &= ~PWDT_INIT0_PRDYIE_Msk;
}
/**
*
* @param[in] none
*
* @return none
*
* @brief set PWDT module soft reset.
*
*/
__STATIC_INLINE void PWDT_SetSoftReset(void)
{
    PWDT->INIT0 |= PWDT_INIT0_SR_Msk;
}
/**
*
* @param[in] pinNum: input pin
*            - PWDT_PINSEL_PIN0
*            - PWDT_PINSEL_PIN1
*            - PWDT_PINSEL_PIN2
*            - PWDT_PINSEL_PIN3
*
* @return none
*
* @brief set PWDT module input pin select.
*
*/
__STATIC_INLINE void PWDT_PinSelect(uint8_t pinNum)
{
    PWDT->INIT0 &= ~PWDT_INIT0_PINSEL_Msk;
    PWDT->INIT0 |= (pinNum << PWDT_INIT0_PINSEL_Pos);
}
/**
*
* @param[in] edgeMode: input edge sensitivity mode
*            - FALLING_START_CAPTURE_FALLING
*            - RISING_START_CAPTURE_ALL
*            - FALLING_START_CAPTURE_ALL
*            - RISING_START_CAPTURE_RISING
*
* @return none
*
* @brief set PWDT module input edge sensitivity.
*
*/
__STATIC_INLINE void PWDT_SetEdgeMode(uint8_t edgeMode)
{
    PWDT->INIT0 &= ~PWDT_INIT0_EDGE_Msk;
    PWDT->INIT0 |= (edgeMode << PWDT_INIT0_EDGE_Pos);
}
/**
*
* @param[in] clockSource: clock source
*            - PWDT_PCLKS_BUS
*            - PWDT_PCLKS_ALTCLK
*
* @return none
*
* @brief set PWDT module input clock source.
*
*/
__STATIC_INLINE void PWDT_SetClockSource(uint8_t clockSource)
{
    PWDT->INIT0 &= ~PWDT_INIT0_PCLKSEL_Msk;
    PWDT->INIT0 |= (clockSource << PWDT_INIT0_PCLKSEL_Pos);
}
/**
*
* @param[in] preScaler: prescaler ratio(000~111:1/2/4/8/бн/128)
*
* @return none
*
* @brief set PWDT module input clock prescaler.
*
*/
__STATIC_INLINE void PWDT_SetClockPreScaler(uint8_t preScaler)
{
    PWDT->INIT0 &= ~PWDT_INIT0_PSC_Msk;
    PWDT->INIT0 |= (preScaler << PWDT_INIT0_PSC_Pos);
}
/**
*
* @param[in] pinSel: Set PWDT Input PIN
*            - PWDT_PINSEL_PIN0
*            - PWDT_PINSEL_PIN1
*            - PWDT_PINSEL_PIN2
*            - PWDT_PINSEL_PIN3
*
* @return none
*
* @brief set PWDT pin Select
*
*/
__STATIC_INLINE void PWDT_SetPinSelect(uint8_t pinSel)
{
    PWDT->INIT0 |= (pinSel << PWDT_INIT0_PINSEL_Pos);
}
/**
*
* @param[in] none
*
* @return flag.
*
* @brief get PWDT overflow flag.
*
*/
__STATIC_INLINE uint8_t PWDT_GetOverflowFlag(void)
{
    uint8_t flag;

    flag = (PWDT->INIT0 & PWDT_INIT0_OVF_Msk);

    return flag;
}
/**
*
* @param[in] none
*
* @return none
*
* @brief clear PWDT overflow flag.
*
*/
__STATIC_INLINE void PWDT_ClrOverflowFlag(void)
{
    PWDT->INIT0 &= ~PWDT_INIT0_OVF_Msk;
}
/**
*
* @param[in] none
*
* @return flag.
*
* @brief get PWDT ready flag.
*
*/
__STATIC_INLINE uint8_t PWDT_GetReadyFlag(void)
{
    uint8_t flag;

    flag = (PWDT->INIT0 & PWDT_INIT0_RDYF_Msk);

    return flag;
}
/**
*
* @param[in] none
*
* @return none
*
* @brief clear PWDT ready flag.
*
*/
__STATIC_INLINE void PWDT_ClrReadyFlag(void)
{
    PWDT->INIT0 &= ~PWDT_INIT0_RDYF_Msk;
}
/**
*
* @param[in] none
*
* @return Positive pulse width count value
*
* @brief Get positive pulse width count value
*
*/
__STATIC_INLINE uint16_t PWDT_GetPositivePulseWidthCount(void)
{
    return ((PWDT->INIT0 & PWDT_INIT0_PPWCV_Msk) >> PWDT_INIT0_PPWCV_Pos);
}
/**
*
* @param[in] none
*
* @return Negative pulse width count value
*
* @brief Get negative pulse width count value
*
*/
__STATIC_INLINE uint16_t PWDT_GetNegativePulseWidthCount(void)
{
    return ((PWDT->NPWCV & PWDT_NPWCV_NPWCV_Msk) >> PWDT_NPWCV_NPWCV_Pos);
}

/**
*
* @param[in] none
*
* @return none
*
* @brief Enable PWDT hall Sensor.
*
*/
__STATIC_INLINE void PWDT_EnableHall(void)
{
    PWDT->INIT1 |= PWDT_INIT1_HALLEN_Msk;
}
/**
*
* @param[in] none
*
* @return none
*
* @brief Disable PWDT hall Sensor.
*
*/
__STATIC_INLINE void PWDT_DisableHall(void)
{
    PWDT->INIT1 &= ~PWDT_INIT1_HALLEN_Msk;
}
/**
*
* @param[in] none
*
* @return hall status
*
* @brief Get Hall Sensor Status
*
*/
__STATIC_INLINE uint8_t PWDT_GetHallStatus(void)
{
    return ((PWDT->INIT1 & PWDT_INIT1_HALLSTATUS_Msk) >> PWDT_INIT1_HALLSTATUS_Pos);
}
/**
*
* @param[in] none
*
* @return none
*
* @brief Enable PWDT/Hall Filter Function
*
*/
__STATIC_INLINE void PWDT_FilterEnable(void)
{
    PWDT->INIT1 |= PWDT_INIT1_FILTEN_Msk;
}
/**
*
* @param[in] preScale: prescale value(from 1 to 12)
* @param[in] filterValue: filter clock; Actual filterValue = PWDT_Clock/preScale/filerValue
*
* @return none
*
* @brief Set Hall Interface/PWDT Filter Value
*
*/
__STATIC_INLINE void PWDT_SetFilterValue(uint8_t preScale, uint8_t filterValue)
{
    PWDT->INIT1 &= ~(PWDT_INIT1_FILTPSC_Msk | PWDT_INIT1_FILTVAL_Msk);
    PWDT->INIT1 |= ((preScale << PWDT_INIT1_FILTPSC_Pos) | (filterValue << PWDT_INIT1_FILTVAL_Pos));
}
/**
*
* @param[in] none
*
* @return none
*
* @brief Enable PWDT Timer.
*
*/
__STATIC_INLINE void PWDT_EnableTimer(void)
{
    PWDT->INIT1 |= PWDT_INIT1_TIMEN_Msk;
}
/**
*
* @param[in] none
*
* @return none
*
* @brief Disable PWDT Timer.
*
*/
__STATIC_INLINE void PWDT_DisableTimer(void)
{
    PWDT->INIT1 &= ~PWDT_INIT1_TIMEN_Msk;
}
/**
*
* @param[in] none
*
* @return none
*
* @brief Enable PWDT Comparator Mode(Comp Output to PWDT in).
*
*/
__STATIC_INLINE void PWDT_EnableCompMode(void)
{
    PWDT->INIT1 |= PWDT_INIT1_CMPEN_Msk;
}
/**
*
* @param[in] none
*
* @return none
*
* @brief Disable PWDT Comparator Mode(Comp Output to PWDT in).
*
*/
__STATIC_INLINE void PWDT_DisableCompMode(void)
{
    PWDT->INIT1 &= ~PWDT_INIT1_CMPEN_Msk;
}
/**
*
* @param[in] timerValue (0x0000~0xFFFF)
*
* @return none
*
* @brief Set PWDT Timer Value.
*
*/
__STATIC_INLINE void PWDT_SetTimerValue(uint16_t timerValue)
{
    PWDT->INIT1 &= ~PWDT_INIT1_TIMCNTVAL_Msk;
    PWDT->INIT1 |= (timerValue << PWDT_INIT1_TIMCNTVAL_Pos);
}

#ifdef __cplusplus
}
#endif
#endif

