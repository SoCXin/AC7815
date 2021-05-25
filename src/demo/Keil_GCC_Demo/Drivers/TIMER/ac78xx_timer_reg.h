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
/*****************************************************************************
*
* @file     ac78xx_timer_reg.h
*
* @author   Autochips
*
* @version  0.0.1
*
* @date     March 23, 2016
*
* @brief    Periodic Interrupt TIMERer (TIMER) driver head file.
*
******************************************************************************/
#ifndef AC78xx_TIMER_REG_H_
#define AC78xx_TIMER_REG_H_
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
* Includes
******************************************************************************/
#include "stdint.h"
#include "stdio.h"
#include "cmsis_gcc.h"
#define __IO    volatile                    ///< All drivers need this type
#define __I     volatile const
//#define __STATIC_INLINE static __inline

/******************************************************************************
* Constants
******************************************************************************/

/* ----------------------------------------------------------------------------
-- TIMER Peripheral Access Layer
---------------------------------------------------------------------------- */


typedef struct {                                    ///< TIMER Structure
    __IO uint32_t  MCR;                             ///< Timer Module Control Regitser
} TIMER_BASE_Type;

typedef struct {                                    ///< TIMER Structure
    __IO uint32_t  INITVAL;                         ///< Timer Init Load Value Register
    __I  uint32_t  CVAL;                            ///< Timer Current Count Value Register
    __IO uint32_t  INIT;                            ///< Timer Initialize Control Register
    __IO uint32_t  TF;                              ///< Timer Flag Register
} TIMER_Type;
/* ----------------------------------------------------------------------------
   -- TIMER Register Masks
   ----------------------------------------------------------------------------*/

/* ----------------------------------  TIMER_MCR  --------------------------------- */
#define TIMER_MCR_DBEN_Pos                    0                                                      ///< TIMER MCR: DBEN Position                
#define TIMER_MCR_DBEN_Msk                    (0x01UL << TIMER_MCR_DBEN_Pos)                         ///< TIMER MCR: DBEN Mask                    
#define TIMER_MCR_TMER_Pos                    1                                                      ///< TIMER MCR: TMER Position                
#define TIMER_MCR_TMER_Msk                    (0x01UL << TIMER_MCR_TMER_Pos)                         ///< TIMER MCR: TMER Mask                    
/* -------------------------------  TIMER_INITVAL  ------------------------------- */
#define TIMER_INITVAL_LDVAL_Pos              0                                                       ///< TIMER INITVAL: LDVAL Position          
#define TIMER_INITVAL_LDVAL_Msk              (0xffffffffUL << TIMER_INITVAL_LDVAL_Pos)               ///< TIMER INITVAL: LDVAL Mask              

/* ---------------------------------  TIMER_CVAL  -------------------------------- */
#define TIMER_CVAL_CNT_Pos                   0                                                       ///< TIMER CVAL: CNT Position               
#define TIMER_CVAL_CNT_Msk                   (0xffffffffUL << TIMER_CVAL_CNT_Pos)                    ///< TIMER CVAL: CNT Mask                   

/* ---------------------------------  TIMER_INIT  -------------------------------- */
#define TIMER_INIT_TIMEREN_Pos               0                                                       ///< TIMER INIT: TIMEREN Position           
#define TIMER_INIT_TIMEREN_Msk               (0x01UL << TIMER_INIT_TIMEREN_Pos)                      ///< TIMER INIT: TIMEREN Mask               
#define TIMER_INIT_TIE_Pos                   1                                                       ///< TIMER INIT: TIE Position               
#define TIMER_INIT_TIE_Msk                   (0x01UL << TIMER_INIT_TIE_Pos)                          ///< TIMER INIT: TIE Mask                   
#define TIMER_INIT_LINKEN_Pos                2                                                       ///< TIMER INIT: LINKEN Position            
#define TIMER_INIT_LINKEN_Msk                (0x01UL << TIMER_INIT_LINKEN_Pos)                       ///< TIMER INIT: LINKEN Mask                

/* ----------------------------------  TIMER_TF  --------------------------------- */
#define TIMER_TF_TIF_Pos                     0                                                       ///< TIMER TF: TIF Position                 
#define TIMER_TF_TIF_Msk                     (0x01UL << TIMER_TF_TIF_Pos)                            ///< TIMER TF: TIF Mask                     


///< TIMER - Peripheral instance base addresses
///< Peripheral TIMER base address */
#define TIMER_BASE                      0x40011000UL
#define TIMER0_BASE                     0x40011100UL
#define TIMER1_BASE                     0x40011110UL
#define TIMER2_BASE                     0x40011120UL
#define TIMER3_BASE                     0x40011130UL
#define TIMER4_BASE                     0x40011140UL
#define TIMER5_BASE                     0x40011150UL
#define TIMER6_BASE                     0x40011160UL
#define TIMER7_BASE                     0x40011170UL
///< Peripheral TIMER base pointer
#define TIMER                           ((TIMER_BASE_Type        *) TIMER_BASE)
#define TIMER0                          ((TIMER_Type             *) TIMER0_BASE)
#define TIMER1                          ((TIMER_Type             *) TIMER1_BASE)
#define TIMER2                          ((TIMER_Type             *) TIMER2_BASE)
#define TIMER3                          ((TIMER_Type             *) TIMER3_BASE)
#define TIMER4                          ((TIMER_Type             *) TIMER4_BASE)
#define TIMER5                          ((TIMER_Type             *) TIMER5_BASE)
#define TIMER6                          ((TIMER_Type             *) TIMER6_BASE)
#define TIMER7                          ((TIMER_Type             *) TIMER7_BASE)
///< Array initializer of TIMER peripheral base pointers
#define TIMER_BASES                                { TIMER,TIMER0,TIMER1,TIMER2,TIMER3,TIMER4,TIMER5,TIMER6,TIMER7}

/**
* @param[in] TIMx: TIMER channel
*
* @return none
*
* @brief enable TIMER channel timer
*/
__STATIC_INLINE void TIMER_Enable(TIMER_Type *TIMx)
{
    TIMx->INIT |= TIMER_INIT_TIMEREN_Msk;
}


/**
* @param[in] TIMx: TIMER channel
*
* @return none
*
* @brief  disable TIMER channel timer
*/
__STATIC_INLINE void TIMER_Disable(TIMER_Type *TIMx)
{
    TIMx->INIT &= ~ TIMER_INIT_TIMEREN_Msk;
}

/**
* @param[in] TIMx: TIMER channel
*
* @return none
*
* @brief  enable TIMER channel timer interrupt
*/
__STATIC_INLINE void TIMER_EnableInt(TIMER_Type *TIMx)
{
    TIMx->INIT |= TIMER_INIT_TIE_Msk;
}


/**
* @param[in] TIMx: TIMER channel
*
* @return none
*
* @brief disable TIMER channel timer interrupt
*/
__STATIC_INLINE void TIMER_DisableInt(TIMER_Type *TIMx)

{
    TIMx->INIT &= ~ TIMER_INIT_TIE_Msk;
}

/**
* @param[in] TIMx: TIMER channel
*
* @return none
*
* @brief  enable TIMER channel timer chain mode
*/
__STATIC_INLINE void TIMER_EnableLinkMode(TIMER_Type *TIMx)
{
    TIMx->INIT |= TIMER_INIT_LINKEN_Msk;
}

/**
* @param[in] TIMx: TIMER channel
*
* @return none
*
* @brief  disable TIMER channel timer chain mode
*/
__STATIC_INLINE void TIMER_DisableLinkMode(TIMER_Type *TIMx)
{
    TIMx->INIT &= ~TIMER_INIT_LINKEN_Msk;
}

#ifdef __cplusplus
}
#endif
#endif /* ac78xx_timer_reg_h */
