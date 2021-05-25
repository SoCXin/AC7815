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

#ifndef AC78XX_CRC_REG_H_
#define AC78XX_CRC_REG_H_
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

#include "stdint.h"

#define __IO    volatile
#define __I     volatile const

#if defined ( __ICCARM__ )
#define __STATIC_INLINE static inline
#elif defined ( __GNUC__)
#define __STATIC_INLINE static inline
#elif defined (__CC_ARM)
#define __STATIC_INLINE static __inline
#endif

/* #pragma anon_unions */

typedef struct {
    union {
        struct {                                         ///< offset: 0x0
            __IO uint16_t DATAL;                         ///< CRC_DATAL register., offset: 0x0
            __IO uint16_t DATAH;                         ///< CRC_DATAH register., offset: 0x2
        } BIT16;
        __IO uint32_t BIT32;                              ///< CRC Data register, offset: 0x0
        struct {                                         ///< offset: 0x0
            __IO uint8_t DATA0;                          ///< CRC_DATA0 register., offset: 0x0
            __IO uint8_t DATA1;                          ///< CRC_DATA1 register., offset: 0x1
            __IO uint8_t DATA2;                          ///< CRC_DATA2 register., offset: 0x2
            __IO uint8_t DATA3;                          ///< CRC_DATA3 register., offset: 0x3
        } BIT8;
    } DATA;
    union {
        struct {                                         ///< offset: 0x4
            __IO uint16_t GPOLYL;                        ///< CRC_GPOLYL register., offset: 0x4
            __IO uint16_t GPOLYH;                        ///< CRC_GPOLYH register., offset: 0x6
        } BIT16;
        __IO uint32_t BIT32;                             ///< CRC Polynomial register, offset: 0x4
    } POLY;
    union {
        __IO uint32_t BIT32;                             ///< CRC Control register, offset: 0x8
        struct {                                         ///< offset: 0x8
            __IO uint32_t TCRC      : 1;                 ///< Tpye of CRC Protocol
            __IO uint32_t WAS       : 1;                 ///< Write as seed
            __IO uint32_t FXOR      : 1;                 ///< Complement Read Of CRC Data Register
            __IO uint32_t           : 1;                 ///< Reserved
            __IO uint32_t TOTR      : 2;                 ///< Type Of Transpose For Read
            __IO uint32_t TOTW      : 2;                 ///< Type Of Transpose For Write
            __IO uint32_t           : 24;                ///< Reserved
        } BIT8;
    } CTRL;
} CRC_Type;
/* ----------------------------------------------------------------------------
-- CRC Register Masks
---------------------------------------------------------------------------- */
///< DATAL Bit Fields
#define CRC_DATAL_DATAL_MASK                     0xFFFFu
#define CRC_DATAL_DATAL_SHIFT                    0
#define CRC_DATAL_DATAL(x)                       (((uint16_t)(((uint16_t)(x))<<CRC_DATAL_DATAL_SHIFT))&CRC_DATAL_DATAL_MASK)
///< DATAH Bit Fields
#define CRC_DATAH_DATAH_MASK                     0xFFFFu
#define CRC_DATAH_DATAH_SHIFT                    0
#define CRC_DATAH_DATAH(x)                       (((uint16_t)(((uint16_t)(x))<<CRC_DATAH_DATAH_SHIFT))&CRC_DATAH_DATAH_MASK)
///< DATA Bit Fields
#define CRC_DATA_LL_MASK                         0xFFu
#define CRC_DATA_LL_SHIFT                        0
#define CRC_DATA_LL(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_LL_SHIFT))&CRC_DATA_LL_MASK)
#define CRC_DATA_LU_MASK                         0xFF00u
#define CRC_DATA_LU_SHIFT                        8
#define CRC_DATA_LU(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_LU_SHIFT))&CRC_DATA_LU_MASK)
#define CRC_DATA_HL_MASK                         0xFF0000u
#define CRC_DATA_HL_SHIFT                        16
#define CRC_DATA_HL(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_HL_SHIFT))&CRC_DATA_HL_MASK)
#define CRC_DATA_HU_MASK                         0xFF000000u
#define CRC_DATA_HU_SHIFT                        24
#define CRC_DATA_HU(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_HU_SHIFT))&CRC_DATA_HU_MASK)
///< DATA0 Bit Fields
#define CRC_DATA0_DATA0_MASK                     0xFFu
#define CRC_DATA0_DATA0_SHIFT                    0
#define CRC_DATA0_DATA0(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_DATA0_DATA0_SHIFT))&CRC_DATA0_DATA0_MASK)
///< DATA1 Bit Fields
#define CRC_DATA1_DATA1_MASK                     0xFFu
#define CRC_DATA1_DATA1_SHIFT                    0
#define CRC_DATA1_DATA1(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_DATA1_DATA1_SHIFT))&CRC_DATA1_DATA1_MASK)
///< DATA2 Bit Fields
#define CRC_DATA2_DATA2_MASK                     0xFFu
#define CRC_DATA2_DATA2_SHIFT                    0
#define CRC_DATA2_DATA2(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_DATA2_DATA2_SHIFT))&CRC_DATA2_DATA2_MASK)
///< DATA3 Bit Fields
#define CRC_DATA3_DATA3_MASK                     0xFFu
#define CRC_DATA3_DATA3_SHIFT                    0
#define CRC_DATA3_DATA3(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_DATA3_DATA3_SHIFT))&CRC_DATA3_DATA3_MASK)
///< GPOLYL Bit Fields
#define CRC_GPOLYL_GPOLYL_MASK                   0xFFFFu
#define CRC_GPOLYL_GPOLYL_SHIFT                  0
#define CRC_GPOLYL_GPOLYL(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYL_GPOLYL_SHIFT))&CRC_GPOLYL_GPOLYL_MASK)
///< GPOLYH Bit Fields
#define CRC_GPOLYH_GPOLYH_MASK                   0xFFFFu
#define CRC_GPOLYH_GPOLYH_SHIFT                  0
#define CRC_GPOLYH_GPOLYH(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYH_GPOLYH_SHIFT))&CRC_GPOLYH_GPOLYH_MASK)
///< GPOLY Bit Fields
#define CRC_GPOLY_LOW_MASK                       0xFFFFu
#define CRC_GPOLY_LOW_SHIFT                      0
#define CRC_GPOLY_LOW(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_LOW_SHIFT))&CRC_GPOLY_LOW_MASK)
#define CRC_GPOLY_HIGH_MASK                      0xFFFF0000u
#define CRC_GPOLY_HIGH_SHIFT                     16
#define CRC_GPOLY_HIGH(x)                        (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_HIGH_SHIFT))&CRC_GPOLY_HIGH_MASK)
///< CTRL Bit Fields
#define CRC_CTRL_TCRC_MASK                       0x1u
#define CRC_CTRL_TCRC_SHIFT                      0
#define CRC_CTRL_WAS_MASK                        0x2u
#define CRC_CTRL_WAS_SHIFT                       1
#define CRC_CTRL_FXOR_MASK                       0x4u
#define CRC_CTRL_FXOR_SHIFT                      2
#define CRC_CTRL_TOTR_MASK                       0x30u
#define CRC_CTRL_TOTR_SHIFT                      4
#define CRC_CTRL_TOTR(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOTR_SHIFT))&CRC_CTRL_TOTR_MASK)
#define CRC_CTRL_TOT_MASK                        0xC0u
#define CRC_CTRL_TOT_SHIFT                       6
#define CRC_CTRL_TOT(x)                          (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOT_SHIFT))&CRC_CTRL_TOT_MASK)
///< CTRLLL Bit Fields
#define CRC_CTRLLL_TCRC_MASK                     0x1u
#define CRC_CTRLLL_TCRC_SHIFT                    0
#define CRC_CTRLLL_WAS_MASK                      0x2u
#define CRC_CTRLLL_WAS_SHIFT                     1
#define CRC_CTRLLL_FXOR_MASK                     0x4u
#define CRC_CTRLLL_FXOR_SHIFT                    2
#define CRC_CTRLLL_TOTR_MASK                     0x30u
#define CRC_CTRLLL_TOTR_SHIFT                    4
#define CRC_CTRLLL_TOTR(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLLL_TOTR_SHIFT))&CRC_CTRLLL_TOTR_MASK)
#define CRC_CTRLLL_TOTW_MASK                     0xC0u
#define CRC_CTRLLL_TOTW_SHIFT                    6
#define CRC_CTRLLL_TOT(x)                        (((uint8_t)(((uint8_t)(x))<<CRC_CTRLLL_TOT_SHIFT))&CRC_CTRLLL_TOT_MASK)

// CRC - Peripheral instance base addresses
///< Peripheral CRC base address
#define CRC_BASE                                 (0x20081000u)
///<  Peripheral CRC base pointer
#define CRC0                                     ((CRC_Type *)CRC_BASE)
///< Array initializer of CRC peripheral base pointers
#define CRC_BASES                                { CRC0 }
//*******************************************************************************
typedef void (*CRC_CallbackType)(void);
/******************************************************************************
* CRC API list
*******************************************************************************/

/**
* CRC_Init
*
* @param[in] CRCMode: 0-CRC 16, 1-CRC 32
* @param[in] byteReversal: Write & Read Byte Reversal
* @param[in] resultXOR: Output result reversal, 0-none, 1-reversal
* @return none
*
* @brief  Initialize CRC module
*/
__STATIC_INLINE void CRC_Init(uint32_t CRCMode, uint32_t byteReversal, uint32_t resultXOR)
{
    uint32_t tmpCtrlReg = 0;
    tmpCtrlReg |= CRCMode & CRC_CTRL_TCRC_MASK;
    tmpCtrlReg |= (byteReversal << CRC_CTRLLL_TOTR_SHIFT) & CRC_CTRLLL_TOTR_MASK;
    tmpCtrlReg |= (byteReversal << CRC_CTRL_TOTR_SHIFT) & CRC_CTRLLL_TOTW_MASK;
    tmpCtrlReg |= (resultXOR << CRC_CTRLLL_FXOR_SHIFT) & CRC_CTRLLL_FXOR_MASK;
    CRC0->CTRL.BIT32 = tmpCtrlReg;
}

/**
* CRC_SetPoly
*
* @param[in] CRCPoly: CRC Polynomial
* @return none
*
* @brief  Set CRC Polynomial
*/
__STATIC_INLINE void CRC_SetPoly(uint32_t CRCPoly)
{
    CRC0->POLY.BIT32 = CRCPoly;
}

/**
* CRC_SetSeed
*
* @param[in] CRCSeed: CRC Seed
* @return none
*
* @brief  Set CRC seed
*/
__STATIC_INLINE void CRC_SetSeed(uint32_t CRCSeed)
{
    CRC0->CTRL.BIT32 |= CRC_CTRL_WAS_MASK;
    CRC0->DATA.BIT32 = CRCSeed;
}

/**
* CRC_SetData
*
* @param[in] CRCData: CRC Data
* @return none
*
* @brief  Set CRC data in 32-bit
*/
__STATIC_INLINE void CRC_SetData(uint32_t CRCData)
{
    CRC0->CTRL.BIT32 &= ~CRC_CTRL_WAS_MASK;
    CRC0->DATA.BIT32 = CRCData;
}


void CRC_Init(uint32_t CRCMode, uint32_t byteReversal, uint32_t resultXOR);
void CRC_SetPoly(uint32_t CRCPoly);
void CRC_SetSeed(uint32_t CRCSeed);
void CRC_SetData(uint32_t CRCData);

#ifdef __cplusplus
}
#endif

#endif
