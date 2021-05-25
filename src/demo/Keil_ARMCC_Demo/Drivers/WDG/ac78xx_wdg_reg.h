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

#ifndef _AC78XX_WDOG_REG_H_
#define _AC78XX_WDOG_REG_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "stdio.h"
   
#define __IO    volatile                            ///< All drivers need this type
#define __I     volatile const 
#define __STATIC_INLINE static __inline

typedef struct {
  __IO uint32_t CS1;                                ///< Watchdog Control and Status Register 1, offset: 0x0
  __IO uint32_t CS2;                                ///< Watchdog Control and Status Register 2, offset: 0x4
  __IO uint32_t CNT;                                ///< WDOG_CNT register,offset: 0x8
  __IO uint32_t TOVAL;                              ///< WDOG_TOVAL register,offset: 0xC
  __IO uint32_t WIN;                                ///< WDOG_WIN register,offset: 0x10 
} WDOG_Type;

/* ----------------------------------------------------------------------------
   -- WDOG Register Masks
   ---------------------------------------------------------------------------- */
///< CS1 Bit Fields
#define WDOG_CS1_STOP_MASK                       0x1u
#define WDOG_CS1_STOP_SHIFT                      0
#define WDOG_CS1_WAIT_MASK                       0x2u
#define WDOG_CS1_WAIT_SHIFT                      1
#define WDOG_CS1_UPDATE_MASK                     0x20u
#define WDOG_CS1_UPDATE_SHIFT                    5
#define WDOG_CS1_INT_MASK                        0x40u
#define WDOG_CS1_INT_SHIFT                       6
#define WDOG_CS1_EN_MASK                         0x80u
#define WDOG_CS1_EN_SHIFT                        7
///< CS2 Bit Fields 
#define WDOG_CS2_CLK_MASK                        0x3u
#define WDOG_CS2_CLK_SHIFT                       0
#define WDOG_CS2_CLK(x)                          (((uint8_t)(((uint8_t)(x))<<WDOG_CS2_CLK_SHIFT))&WDOG_CS2_CLK_MASK)
#define WDOG_CS2_PRES_MASK                       0x10u
#define WDOG_CS2_PRES_SHIFT                      4
#define WDOG_CS2_FLG_MASK                        0x40u
#define WDOG_CS2_FLG_SHIFT                       6
#define WDOG_CS2_WIN_MASK                        0x80u
#define WDOG_CS2_WIN_SHIFT                       7
///< CNT Bit Fields 
#define WDOG_CNT_CNT_MASK                        0xFFFFFFFFu
#define WDOG_CNT_CNT_SHIFT                       0
#define WDOG_CNT_CNT(x)                          (((uint16_t)(((uint16_t)(x))<<WDOG_CNT_CNT_SHIFT))&WDOG_CNT_CNT_MASK)
///< TOVAL Bit Fields 
#define WDOG_TOVAL_TOVAL_MASK                    0xFFFFFFFFu
#define WDOG_TOVAL_TOVAL_SHIFT                   0
#define WDOG_TOVAL_TOVAL(x)                      (((uint16_t)(((uint16_t)(x))<<WDOG_TOVAL_TOVAL_SHIFT))&WDOG_TOVAL_TOVAL_MASK)
///< WIN Bit Fields 
#define WDOG_WIN_WIN_MASK                        0xFFFFFFFFu
#define WDOG_WIN_WIN_SHIFT                       0
#define WDOG_WIN_WIN(x)                          (((uint16_t)(((uint16_t)(x))<<WDOG_WIN_WIN_SHIFT))&WDOG_WIN_WIN_MASK)

//WDOG - Peripheral instance base addresses 
///< Peripheral WDOG base address 
#define WDOG_BASE                                (0x4000b000u)
///<  Peripheral WDOG base pointer 
#define WDOG0                                     ((WDOG_Type *)WDOG_BASE)
///<  Array initializer of WDOG peripheral base pointers 
#define WDOG_BASES                               { WDOG0 }
//*******************************************************************************
typedef void (*WDOG_CallbackType)(void);

/******************************************************************************
* WDOG API list
*******************************************************************************/

/**
* WDOG_Enable
*
* @param[in] none
* @return none
*
* @brief  Enable WDOG module
*/
__STATIC_INLINE void WDOG_Enable(void)
{
    WDOG0->CS1 |= WDOG_CS1_EN_MASK;   
}

/**
* WDOG_Disable
*
* @param[in] none
* @return none
*
* @brief  Disable WDOG module
*/
__STATIC_INLINE void WDOG_Disable(void)
{
    WDOG0->CS1 &= ~WDOG_CS1_EN_MASK;   
}

/**
* WDOG_EnableInt
*
* @param[in] none
* @return none
*
* @brief  Enable WDOG interrupt
*/
__STATIC_INLINE void WDOG_EnableInt(void)
{
    WDOG0->CS1 |= WDOG_CS1_INT_MASK;   
}

/**
* WDOG_DisableInt
*
* @param[in] none
* @return none
*
* @brief  Disable WDOG interrupt
*/
__STATIC_INLINE void WDOG_DisableInt(void)
{
    WDOG0->CS1 &= ~WDOG_CS1_INT_MASK;   
}

/**
* WDOG_EnableUpdate
*
* @param[in] none
* @return none
*
* @brief  Enable WDOG update
*/
__STATIC_INLINE void WDOG_EnableUpdate(void)
{
    WDOG0->CS1 |= WDOG_CS1_UPDATE_MASK;   
}

/**
* WDOG_DisableUpdate
*
* @param[in] none
* @return none
*
* @brief  Disable WDOG update
*/
__STATIC_INLINE void WDOG_DisableUpdate(void)
{
    WDOG0->CS1 &= ~WDOG_CS1_UPDATE_MASK;   
}

/**
* WDOG_EnableWin
*
* @param[in] none
* @return none
*
* @brief  Enable WDOG window mode
*/
__STATIC_INLINE void WDOG_EnableWin(void)
{
    WDOG0->CS2 |= WDOG_CS2_WIN_MASK;   
}

/**
* WDOG_DisableWin
*
* @param[in]  none
* @return none
*
* @brief  Disable WDOG window mode
*/
__STATIC_INLINE void WDOG_DisableWin(void)
{
    WDOG0->CS2 &= ~WDOG_CS2_WIN_MASK;   
}

/**
* WDOG_GetFlag
*
* @param[in] none
* @return WDOG Flag
*
* @brief  Get WDOG interrupt falg
*/
__STATIC_INLINE uint32_t WDOG_GetFlag(void)
{
    return (WDOG0->CS2 & WDOG_CS2_FLG_MASK);   
}

/**
* WDOG_ClrFlag
*
* @param[in] none
* @return none
*
* @brief  Clear WDOG interrupt falg
*/
__STATIC_INLINE void WDOG_ClrFlag(void)
{
    WDOG0->CS2 |= WDOG_CS2_FLG_MASK;   
}

/**
* WDOG_EnablePres
*
* @param[in] none
* @return none
*
* @brief  Enable WDOG prescale
*/
__STATIC_INLINE void WDOG_EnablePres(void)
{
    WDOG0->CS2 |= WDOG_CS2_PRES_MASK;   
}

/**
* WDOG_DisablePres
*
* @param[in] none
* @return none
*
* @brief  Disable WDOG prescale
*/
__STATIC_INLINE void WDOG_DisablePres(void)
{
    WDOG0->CS2 &= ~WDOG_CS2_PRES_MASK;   
}

/**
* WDOG_SetClkSource
*
* @param[in] clkSource: 0:bus clk; 1:internal 32KHz; 2:internal 8M osciallator; 3:external osciallator 
* @return none
*
* @brief  Set WDOG clock source
*/
__STATIC_INLINE void WDOG_SetClkSource(uint32_t clkSource)
{
    WDOG0->CS2 &= ~WDOG_CS2_CLK_MASK;
    WDOG0->CS2 |= WDOG_CS2_CLK(clkSource);   
}

/**
* WDOG_GetCNT
*
* @param[in] none
* @return WDOG CNT register value
*
* @brief  Get WDOG CNT
*/
__STATIC_INLINE uint32_t WDOG_GetCNT(void)
{
    return WDOG0->CNT;   
}

/**
* WDOG_SetTOVAL
*
* @param[in] timeoutValue: 32bit WDOG timeout value 
* @return none
*
* @brief  Set WDOG timeout value
*/
__STATIC_INLINE void WDOG_SetTOVAL(uint32_t timeoutValue)
{
    WDOG0->TOVAL = timeoutValue;   
}

/**
* WDOG_SetWin
*
* @param[in] winTimeoutValue: 32bit WDOG window timeout value 
* @return none
*
* @brief  Set WDOG window timeout value
*/
__STATIC_INLINE void WDOG_SetWin(uint32_t winTimeoutValue)
{
    WDOG0->WIN = winTimeoutValue;   
}


#ifdef __cplusplus
}
#endif

#endif
