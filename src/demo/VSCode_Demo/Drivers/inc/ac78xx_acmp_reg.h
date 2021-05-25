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
#ifndef AC78XX_ACMP_REG_H_
#define AC78XX_ACMP_REG_H_
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
#include "stdio.h"


#define __IO    volatile                    ///< All drivers need this type
#define __I     volatile const

#if defined ( __ICCARM__ )
#define __STATIC_INLINE static inline
#elif defined ( __GNUC__)
#define __STATIC_INLINE static inline
#elif defined (__CC_ARM)
#define __STATIC_INLINE static __inline
#endif

/* ================================================================================ */
/* ================                      ACMP0                     ================ */
/* ================================================================================ */


/**
  * @brief Analog comparator (ACMP0)
  */

typedef struct {                                      ///< ACMP0 Structure
    __IO uint32_t  CR0;                               ///< ACMP0 Configuration Register 0
    __IO uint32_t  CR1;                               ///< ACMP Configuration Register 1
    __IO uint32_t  CR2;                               ///< ACMP0 configuration register 2
    __IO uint32_t  CR3;                               ///< ACMP0 configuration register 3
    __IO uint32_t  CR4;                               ///< ACMP0 configuration register 4
    __IO uint32_t  DR;                                ///< ACMP0 data output register 0
    __IO uint32_t  SR;                                ///< ACMP0 status register 0
    __IO uint32_t  FD;                                ///< ACMP0 polling frequency divider register
    __IO uint32_t  OPA;                               ///< ACMP0 hall output A set register
    __IO uint32_t  OPB;                               ///< ACMP0 hall output B set register
    __IO uint32_t  OPC;                               ///< ACMP0 hall output C set register
    __IO uint32_t  DACSR;                             ///< ACMP DAC reference select register
} ACMP0_Type;


/* ================================================================================ */
/* ================                      ACMP1                     ================ */
/* ================================================================================ */


/**
  * @brief Analog comparator (ACMP1)
  */

typedef struct {                                      ///< ACMP1 Structure
    __IO uint32_t  CR0;                               ///< ACMP1 Configuration Register 0
    __IO uint32_t  CR1;                               ///< ACMP1 Configuration Register 1
    __IO uint32_t  CR2;                               ///< ACMP1 configuration register 2
    __IO uint32_t  DSR;                               ///< ACMP1 data output register 0
} ACMP1_Type;

typedef struct {
    __IO uint32_t RESERVED_0        : 10;
    __IO uint32_t LPFSEL            : 3;               ///<ACMP LPF
    __IO uint32_t HYST0             : 1;               ///<ACMP0 Hysteresis Select
    __IO uint32_t HYST1             : 1;               ///<ACMP1 Hysteresis Select
    __IO uint32_t MODE              : 1;               ///<ACMP Mode Select 1:Normal Mode; 0:Low Power Mode
    __IO uint32_t RESERVED_1        : 8;
    __IO uint32_t RESERVED_2        : 6;
    __IO uint32_t RESERVED_3        : 2;
} ACMP_DAC_CFG_Type;
typedef struct {                                      ///< ACMP Input Select Structure
    __IO uint32_t  MODE;                              ///<0x00!< ADC chanenel status Register
} ACMP_PIN_Type;
/* ================================================================================ */
/* ================         struct 'ACMP0' Position & Mask         ================ */
/* ================================================================================ */


/* ----------------------------------  ACMP0_CR0  --------------------------------- */
#define ACMP0_CR0_MOD_Pos                     0                                                       ///< ACMP0 CR0: MOD Position
#define ACMP0_CR0_MOD_Msk                     (0x03UL << ACMP0_CR0_MOD_Pos)                           ///< ACMP0 CR0: MOD Mask
#define ACMP0_CR0_MOD(x)                      (((uint8_t)(((uint8_t)(x))<<ACMP0_CR0_MOD_Pos))&ACMP0_CR0_MOD_Msk)
#define ACMP0_CR0_OPE_Pos                     2                                                       ///< ACMP0 CR0: OPE Position
#define ACMP0_CR0_OPE_Msk                     (0x01UL << ACMP0_CR0_OPE_Pos)                           ///< ACMP0 CR0: OPE Mask
#define ACMP0_CR0_IE_Pos                      4                                                       ///< ACMP0 CR0: IE Position
#define ACMP0_CR0_IE_Msk                      (0x01UL << ACMP0_CR0_IE_Pos)                            ///< ACMP0 CR0: IE Mask
#define ACMP0_CR0_HYST_Pos                    6                                                       ///< ACMP0 CR0: HYST Position
#define ACMP0_CR0_HYST_Msk                    (0x01UL << ACMP0_CR0_HYST_Pos)                          ///< ACMP0 CR0: HYST Mask
#define ACMP0_CR0_EN_Pos                      7                                                       ///< ACMP0 CR0: EN Position
#define ACMP0_CR0_EN_Msk                      (0x01UL << ACMP0_CR0_EN_Pos)                            ///< ACMP0 CR0: EN Mask

/* ----------------------------------  ACMP0_CR1  --------------------------------- */
#define ACMP0_CR1_NSEL_Pos                    0                                                       ///< ACMP0 CR1: NSEL Position
#define ACMP0_CR1_NSEL_Msk                    (0x07UL << ACMP0_CR1_NSEL_Pos)                          ///< ACMP0 CR1: NSEL Mask
#define ACMP0_CR1_PSEL_Pos                    4                                                       ///< ACMP0 CR1: PSEL Position
#define ACMP0_CR1_PSEL_Msk                    (0x07UL << ACMP0_CR1_PSEL_Pos)                          ///< ACMP0 CR1: PSEL Mask

/* ----------------------------------  ACMP0_CR2  --------------------------------- */
#define ACMP0_CR2_VAL_Pos                     0                                                       ///< ACMP0 CR2: VAL Position
#define ACMP0_CR2_VAL_Msk                     (0x3fUL << ACMP0_CR2_VAL_Pos)                           ///< ACMP0 CR2: VAL Mask
#define ACMP0_CR2_VAL(x)                      (((uint8_t)(((uint8_t)(x))<<ACMP0_CR2_VAL_Pos))&ACMP0_CR2_VAL_Msk)
#define ACMP0_CR2_DACEN_Pos                   7                                                       ///< ACMP0 CR2: DACEN Position
#define ACMP0_CR2_DACEN_Msk                   (0x01UL << ACMP0_CR2_DACEN_Pos)                         ///< ACMP0 CR2: DACEN Mask

/* ----------------------------------  ACMP0_CR3  --------------------------------- */
#define ACMP0_CR3_NSPLEN_Pos                  3                                                       ///< ACMP0 CR3: NSPLEN Position
#define ACMP0_CR3_NSPLEN_Msk                  (0x01UL << ACMP0_CR3_NSPLEN_Pos)                        ///< ACMP0 CR3: NSPLEN Mask
#define ACMP0_CR3_PSPLEN_Pos                  7                                                       ///< ACMP0 CR3: PSPLEN Position
#define ACMP0_CR3_PSPLEN_Msk                  (0x01UL << ACMP0_CR3_PSPLEN_Pos)                        ///< ACMP0 CR3: PSPLEN Mask

/* ----------------------------------  ACMP0_CR4  --------------------------------- */
#define ACMP0_CR4_PLSEQ_Pos                   0                                                       ///< ACMP0 CR4: PLSEQ Position
#define ACMP0_CR4_PLSEQ_Msk                   (0x3fUL << ACMP0_CR4_PLSEQ_Pos)                         ///< ACMP0 CR4: PLSEQ Mask
#define ACMP0_CR4_PLSEQ(x)                      (((uint32_t)(((uint32_t)(x))<<ACMP0_CR4_PLSEQ_Pos))&ACMP0_CR4_PLSEQ_Msk)
/* ----------------------------------  ACMP0_DR  ---------------------------------- */
#define ACMP0_DR_O0_Pos                       0                                                       ///< ACMP0 DR: O0 Position
#define ACMP0_DR_O0_Msk                       (0x01UL << ACMP0_DR_O0_Pos)                             ///< ACMP0 DR: O0 Mask
#define ACMP0_DR_O1_Pos                       1                                                       ///< ACMP0 DR: O1 Position
#define ACMP0_DR_O1_Msk                       (0x01UL << ACMP0_DR_O1_Pos)                             ///< ACMP0 DR: O1 Mask
#define ACMP0_DR_O2_Pos                       2                                                       ///< ACMP0 DR: O2 Position
#define ACMP0_DR_O2_Msk                       (0x01UL << ACMP0_DR_O2_Pos)                             ///< ACMP0 DR: O2 Mask
#define ACMP0_DR_O3_Pos                       3                                                       ///< ACMP0 DR: O3 Position
#define ACMP0_DR_O3_Msk                       (0x01UL << ACMP0_DR_O3_Pos)                             ///< ACMP0 DR: O3 Mask
#define ACMP0_DR_O4_Pos                       4                                                       ///< ACMP0 DR: O4 Position
#define ACMP0_DR_O4_Msk                       (0x01UL << ACMP0_DR_O4_Pos)                             ///< ACMP0 DR: O4 Mask
#define ACMP0_DR_O5_Pos                       5                                                       ///< ACMP0 DR: O5 Position
#define ACMP0_DR_O5_Msk                       (0x01UL << ACMP0_DR_O5_Pos)                             ///< ACMP0 DR: O5 Mask
#define ACMP0_DR_O_Pos                        7                                                       ///< ACMP0 DR: O Position
#define ACMP0_DR_O_Msk                        (0x01UL << ACMP0_DR_O_Pos)                              ///< ACMP0 DR: O Mask

/* ----------------------------------  ACMP0_SR  ---------------------------------- */
#define ACMP0_SR_F0_Pos                       0                                                       ///< ACMP0 SR: F0 Position
#define ACMP0_SR_F0_Msk                       (0x01UL << ACMP0_SR_F0_Pos)                             ///< ACMP0 SR: F0 Mask
#define ACMP0_SR_F1_Pos                       1                                                       ///< ACMP0 SR: F1 Position
#define ACMP0_SR_F1_Msk                       (0x01UL << ACMP0_SR_F1_Pos)                             ///< ACMP0 SR: F1 Mask
#define ACMP0_SR_F2_Pos                       2                                                       ///< ACMP0 SR: F2 Position
#define ACMP0_SR_F2_Msk                       (0x01UL << ACMP0_SR_F2_Pos)                             ///< ACMP0 SR: F2 Mask
#define ACMP0_SR_F3_Pos                       3                                                       ///< ACMP0 SR: F3 Position
#define ACMP0_SR_F3_Msk                       (0x01UL << ACMP0_SR_F3_Pos)                             ///< ACMP0 SR: F3 Mask
#define ACMP0_SR_F4_Pos                       4                                                       ///< ACMP0 SR: F4 Position
#define ACMP0_SR_F4_Msk                       (0x01UL << ACMP0_SR_F4_Pos)                             ///< ACMP0 SR: F4 Mask
#define ACMP0_SR_F5_Pos                       5                                                       ///< ACMP0 SR: F5 Position
#define ACMP0_SR_F5_Msk                       (0x01UL << ACMP0_SR_F5_Pos)                             ///< ACMP0 SR: F5 Mask
#define ACMP0_SR_WPF_Pos                      6                                                       ///< ACMP0 SR: WPF Position
#define ACMP0_SR_WPF_Msk                      (0x01UL << ACMP0_SR_WPF_Pos)                            ///< ACMP0 SR: WPF Mask
#define ACMP0_SR_F_Pos                        7                                                       ///< ACMP0 SR: F Position
#define ACMP0_SR_F_Msk                        (0x01UL << ACMP0_SR_F_Pos)                              ///< ACMP0 SR: F Mask

/* ----------------------------------  ACMP0_FD  ---------------------------------- */
#define ACMP0_FD_PLFD_Pos                     0                                                       ///< ACMP0 FD: PLFD Position
#define ACMP0_FD_PLFD_Msk                     (0x03UL << ACMP0_FD_PLFD_Pos)                           ///< ACMP0 FD: PLFD Mask

/* ----------------------------------  ACMP0_OPA  --------------------------------- */
#define ACMP0_OPA_OPASEL_Pos                  0                                                       ///< ACMP0 OPA: OPASEL Position
#define ACMP0_OPA_OPASEL_Msk                  (0x07UL << ACMP0_OPA_OPASEL_Pos)                        ///< ACMP0 OPA: OPASEL Mask

/* ----------------------------------  ACMP0_OPB  --------------------------------- */
#define ACMP0_OPB_OPBSEL_Pos                  0                                                       ///< ACMP0 OPB: OPBSEL Position
#define ACMP0_OPB_OPBSEL_Msk                  (0x07UL << ACMP0_OPB_OPBSEL_Pos)                        ///< ACMP0 OPB: OPBSEL Mask

/* ----------------------------------  ACMP0_OPC  --------------------------------- */
#define ACMP0_OPC_OPCSEL_Pos                  0                                                       ///< ACMP0 OPC: OPCSEL Position
#define ACMP0_OPC_OPCSEL_Msk                  (0x07UL << ACMP0_OPC_OPCSEL_Pos)                        ///< ACMP0 OPC: OPCSEL Mask

/* ---------------------------------  ACMP0_DACSR  -------------------------------- */
#define ACMP0_DACSR_DACREF_Pos                0                                                       ///< ACMP0 DACSR: DACREF Position
#define ACMP0_DACSR_DACREF_Msk                (0x01UL << ACMP0_DACSR_DACREF_Pos)                      ///< ACMP0 DACSR: DACREF Mask


/* ================================================================================ */
/* ================         struct 'ACMP1' Position & Mask         ================ */
/* ================================================================================ */


/* ----------------------------------  ACMP1_CR0  --------------------------------- */
#define ACMP1_CR0_MOD_Pos                     0                                                       ///< ACMP1 CR0: MOD Position
#define ACMP1_CR0_MOD_Msk                     (0x03UL << ACMP1_CR0_MOD_Pos)                           ///< ACMP1 CR0: MOD Mask
#define ACMP1_CR0_MOD(x)                      (((uint8_t)(((uint8_t)(x))<<ACMP1_CR0_MOD_Pos))&ACMP1_CR0_MOD_Msk)
#define ACMP1_CR0_IE_Pos                      4                                                       ///< ACMP1 CR0: IE Position
#define ACMP1_CR0_IE_Msk                      (0x01UL << ACMP1_CR0_IE_Pos)                            ///< ACMP1 CR0: IE Mask
#define ACMP1_CR0_HYST_Pos                    6                                                       ///< ACMP1 CR0: HYST Position
#define ACMP1_CR0_HYST_Msk                    (0x01UL << ACMP1_CR0_HYST_Pos)                          ///< ACMP1 CR0: HYST Mask
#define ACMP1_CR0_EN_Pos                      7                                                       ///< ACMP1 CR0: EN Position
#define ACMP1_CR0_EN_Msk                      (0x01UL << ACMP1_CR0_EN_Pos)                            ///< ACMP1 CR0: EN Mask

/* ----------------------------------  ACMP1_CR1  --------------------------------- */
#define ACMP1_CR1_NSEL_Pos                    0                                                       ///< ACMP1 CR1: NSEL Position
#define ACMP1_CR1_NSEL_Msk                    (0x07UL << ACMP1_CR1_NSEL_Pos)                          ///< ACMP1 CR1: NSEL Mask
#define ACMP1_CR1_PSEL_Pos                    4                                                       ///< ACMP1 CR1: PSEL Position
#define ACMP1_CR1_PSEL_Msk                    (0x07UL << ACMP1_CR1_PSEL_Pos)                          ///< ACMP1 CR1: PSEL Mask

/* ----------------------------------  ACMP1_CR2  --------------------------------- */
#define ACMP1_CR2_VAL_Pos                     0                                                       ///< ACMP1 CR2: VAL Position
#define ACMP1_CR2_VAL_Msk                     (0x3fUL << ACMP1_CR2_VAL_Pos)                           ///< ACMP1 CR2: VAL Mask
#define ACMP1_CR2_DACEN_Pos                   7                                                       ///< ACMP1 CR2: DACEN Position
#define ACMP1_CR2_DACEN_Msk                   (0x01UL << ACMP1_CR2_DACEN_Pos)                         ///< ACMP1 CR2: DACEN Mask
#define ACMP1_CR2_VAL(x)                      (((uint8_t)(((uint8_t)(x))<<ACMP1_CR2_VAL_Pos))&ACMP1_CR2_VAL_Msk)
/* ----------------------------------  ACMP1_DSR  --------------------------------- */
#define ACMP1_DSR_O_Pos                       0                                                       ///< ACMP1 DSR: O Position
#define ACMP1_DSR_O_Msk                       (0x01UL << ACMP1_DSR_O_Pos)                             ///< ACMP1 DSR: O Mask
#define ACMP1_DSR_F_Pos                       4                                                       ///< ACMP1 DSR: F Position
#define ACMP1_DSR_F_Msk                       (0x01UL << ACMP1_DSR_F_Pos)                             ///< ACMP1 DSR: F Mask
#define ACMP1_DSR_WUF_Pos                     6                                                       ///< ACMP1 DSR: WUF Position
#define ACMP1_DSR_WUF_Msk                     (0x01UL << ACMP1_DSR_WUF_Pos)                           ///< ACMP1 DSR: WUF Mask

/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */
#define ACMP0_BASE                      0x40005000UL
#define ACMP1_BASE                      0x40005030UL
#define ACMP_DAC_CFG_BASE               0x40008820UL
#define ACMP_PIN_BASE                   0x4000480CUL
/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */
#define ACMP0                           ((ACMP0_Type              *) ACMP0_BASE)
#define ACMP1                           ((ACMP1_Type              *) ACMP1_BASE)
#define ACMP_DAC_CFG                    ((ACMP_DAC_CFG_Type       *) ACMP_DAC_CFG_BASE)
#define ACMP_PIN_CFG                    ((ACMP_PIN_Type           *) ACMP_PIN_BASE)

#define ACMP_CHANNEL uint8_t
#define ACMP_CHANNEL0                             (0x00)
#define ACMP_CHANNEL1                             (0x01)
#define ACMP_HYST_DIS                             (0x02)

/**
* @param[in] acmpChannel: ACMP channel(0~1)
* @param[in] mode: ACMP  mode type
* @return none
*
* @brief  ACMP mode select
*/
__STATIC_INLINE void ACMP_ModeSel(ACMP_CHANNEL acmpChannel, uint8_t mode)
{
    ACMP_DAC_CFG->MODE = mode;
}
/**
* @param[in] acmpChannel: ACMP channel(0~1)
* @param[in] lpfVal: ACMP lpf value
* @return none
*
* @brief  set ACMP lpf value
*/
__STATIC_INLINE void ACMP_LpfSel(ACMP_CHANNEL acmpChannel, uint8_t lpfVal)
{
    if (lpfVal < 8)
    {
        ACMP_DAC_CFG->LPFSEL = lpfVal;
    }
}
/**
* @param[in] acmpChannel: ACMP channel(0~1)
*
* @return none
*
* @brief ACMP channel enable
*/
__STATIC_INLINE void ACMP_Enable(ACMP_CHANNEL acmpChannel)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->CR0 |= ACMP0_CR0_EN_Msk;
    }
    else
    {
        ACMP1->CR0 |= ACMP1_CR0_EN_Msk;
    }
}

/**
* @param[in] acmpChannel: ACMP channel(0~1)
*
* @return none
*
* @brief ACMP channel disable
*/
__STATIC_INLINE void ACMP_Disable(ACMP_CHANNEL acmpChannel)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->CR0 &= ~ACMP0_CR0_EN_Msk;
    }
    else
    {
        ACMP1->CR0 &= ~ACMP1_CR0_EN_Msk;
    }
}
/**
* @param[in] acmpChannel: ACMP channel(0~1)
*
* @return none
*
* @brief ACMP polling enable
*/
__STATIC_INLINE void ACMP_PollingEnable(ACMP_CHANNEL acmpChannel)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->CR0 |= ACMP0_CR0_OPE_Msk;
    }

}
/**
* @param[in] acmpChannel: ACMP channel(0~1)
*
* @return none
*
* @brief ACMP polling disable
*/
__STATIC_INLINE void ACMP_PollingDisable(ACMP_CHANNEL acmpChannel)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->CR0 &= ~ACMP0_CR0_OPE_Msk;
    }
}
/**
* @param[in] acmpChannel: ACMP channel(0~1)
* @param[in] hystValue: ACMP Hysteresis value
*            - 0:low hysteresis;
*            - 1:high hysteresis
* @return none
*
* @brief Set ACMP hysteresis value
*/
__STATIC_INLINE void ACMP_SetHystValue(ACMP_CHANNEL acmpChannel, uint8_t hystValue)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP_DAC_CFG->HYST0 = 1;
        ACMP0->CR0 &= ~ACMP0_CR0_HYST_Msk;
        ACMP0->CR0 |= (hystValue << ACMP0_CR0_HYST_Pos);
    }
    else
    {
        ACMP_DAC_CFG->HYST1 = 1;
        ACMP1->CR0 &= ~ACMP1_CR0_HYST_Msk;
        ACMP1->CR0 |= (hystValue << ACMP1_CR0_HYST_Pos);
    }
}
/**
* @param[in] acmpChannel: ACMP channel(0~1)
*
* @return none
*
* @brief Enable ACMP interrupt
*/
__STATIC_INLINE void ACMP_EnableInterrupt(ACMP_CHANNEL acmpChannel)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->CR0 |= ACMP0_CR0_IE_Msk;
    }
    else
    {
        ACMP1->CR0 |= ACMP1_CR0_IE_Msk;
    }
}

/**
* @param[in] acmpChannel: ACMP channel(0~1)
*
* @return none
*
* @brief Disable ACMP interrupt
*/
__STATIC_INLINE void ACMP_DisableInterrupt(ACMP_CHANNEL acmpChannel)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->CR0 &= ~ACMP0_CR0_IE_Msk;
    }
    else
    {
        ACMP1->CR0 &= ~ACMP1_CR0_IE_Msk;
    }
}

/**
* @param[in] acmpChannel: ACMP channel(0~1)
*
* @return none
*
* @brief Enable the ACMP module hall out mode
*/
__STATIC_INLINE void ACMP_EnableHallOut(ACMP_CHANNEL acmpChannel)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->CR0 |= ACMP0_CR0_OPE_Msk;
    }
}

/**
* @param[in] acmpChannel: ACMP channel(0~1)
*
* @return none
*
* @brief Disable the ACMP module hall out mode
*/
__STATIC_INLINE void ACMP_DisableHallOut(ACMP_CHANNEL acmpChannel)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->CR0 &= ~ACMP0_CR0_OPE_Msk;
    }
}
/**
* @param[in] acmpChannel: ACMP channel(0~1)
* @param[in] edgeSelect:
*            - 0:falling edge mode
*            - 1:rising edge mode
*            - 2:falling edge mode
*            - 3:falling or rising edge mode
*
* @return none
*
* @brief Select ACMP sensitivity modes of the interrupt trigger
*/
__STATIC_INLINE void ACMP_SelectIntMode(ACMP_CHANNEL acmpChannel, uint8_t edgeSelect)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->CR0 &= ~ACMP0_CR0_MOD_Msk;
        ACMP0->CR0 |= ACMP0_CR0_MOD(edgeSelect & 0x3);
    }
    else
    {
        ACMP1->CR0 &= ~ACMP1_CR0_MOD_Msk;
        ACMP1->CR0 |= ACMP1_CR0_MOD(edgeSelect & 0x3);
    }

}
/**
* @param[in] acmpChannel: ACMP channel(0~1)
* @param[in] posPinSel:  positive input select
*            - 000:External Input 0
*            - 001:External Input 1
*            - 010:External Input 2
*            - 011:External Input 3
*            - 100:External Input 4
*            - 101:DAC0 Output
*            - 110:reserved
*            - 111:reserved
*
* @return none
*
* @brief ACMP positive input select
*/
__STATIC_INLINE void ACMP_PositiveInputSelect(ACMP_CHANNEL acmpChannel, uint8_t posPinSel)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->CR1 &= ~ACMP0_CR1_PSEL_Msk;
        ACMP0->CR1 |= (posPinSel << ACMP0_CR1_PSEL_Pos);
    }
    else
    {
        ACMP1->CR1 &= ~ACMP1_CR1_PSEL_Msk;
        ACMP1->CR1 |= (posPinSel << ACMP1_CR1_PSEL_Pos);
    }

}

/**
* @param[in] acmpChannel: ACMP channel(0~1)
* @param[in] negPinSel:  negative input select
*            - 000:External Input 0
*            - 001:External Input 1
*            - 010:External Input 2
*            - 011:External Input 3
*            - 100:External Input 4
*            - 101:DAC0 Output
*            - 110:reserved
*            - 111:reserved
*
* @return none
*
* @brief ACMP negative input select
*/
__STATIC_INLINE void ACMP_NegativeInputSelect(ACMP_CHANNEL acmpChannel, uint8_t negPinSel)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->CR1 &= ~ACMP0_CR1_NSEL_Msk;
        ACMP0->CR1 |= (negPinSel << ACMP0_CR1_NSEL_Pos);
    }
    else
    {
        ACMP1->CR1 &= ~ACMP1_CR1_NSEL_Msk;
        ACMP1->CR1 |= (negPinSel << ACMP1_CR1_NSEL_Pos);
    }
}

/**
* @param[in] acmpChannel: ACMP channel(0~1)
*
* @return none
*
* @brief ACMP dac enable
*/
__STATIC_INLINE void ACMP_DacEnable(ACMP_CHANNEL acmpChannel)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->CR2 |= ACMP0_CR2_DACEN_Msk;
    }
    else
    {
        ACMP1->CR2 |= ACMP1_CR2_DACEN_Msk;
    }
}
/**
* @param[in] acmpChannel: ACMP channel(0~1)
*
* @return none
*
* @brief ACMP dac disable
*/
__STATIC_INLINE void ACMP_DacDisable(ACMP_CHANNEL acmpChannel)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->CR2 &= ~ACMP0_CR2_DACEN_Msk;
    }
    else
    {
        ACMP1->CR2 &= ~ACMP1_CR2_DACEN_Msk;
    }
}
/**
* @param[in] acmpChannel: ACMP channel(0~1)
* @param[in] dacValue: dac output set
*
* @return none
*
* @brief Set ACMP dac output
*/
__STATIC_INLINE void ACMP_DacOutputSet(ACMP_CHANNEL acmpChannel, uint8_t dacValue)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->CR2 &= ~ACMP0_CR2_VAL_Msk;
        ACMP0->CR2 |= ACMP0_CR2_VAL(dacValue);
    }
    else
    {
        ACMP1->CR2 &= ~ACMP1_CR2_VAL_Msk;
        ACMP1->CR2 |= ACMP1_CR2_VAL(dacValue);
    }

}
/**
* @param[in] acmpChannel: ACMP channel(0~1)
*
* @return none
*
* @brief Enable the ACMP positive input polling mode
*/

__STATIC_INLINE void ACMP_PositivePollingModeEnable(ACMP_CHANNEL acmpChannel)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->CR3 |= ACMP0_CR3_PSPLEN_Msk;
    }
}
/**
* @param[in] acmpChannel: ACMP channel(0~1)
*
* @return none
*
* @brief Disable the ACMP positive input polling mode
*/
__STATIC_INLINE void ACMP_PositivePollingModeDisable(ACMP_CHANNEL acmpChannel)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->CR3 &= ~ACMP0_CR3_PSPLEN_Msk;
    }
}
/**
* @param[in] acmpChannel: ACMP channel(0~1)
*
* @return none
*
* @brief Enable the ACMP nagetive input polling mode
*/
__STATIC_INLINE void ACMP_NegativePollingModeEnable(ACMP_CHANNEL acmpChannel)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->CR3 |= ACMP0_CR3_NSPLEN_Msk;
    }
}
/**
* @param[in] acmpChannel: ACMP channel(0~1)
*
* @return none
*
* @brief Disable the ACMP nagetive input polling mode
*/
__STATIC_INLINE void ACMP_NegativePollingModeDisable(ACMP_CHANNEL acmpChannel)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->CR3 &= ~ACMP0_CR3_NSPLEN_Msk;
    }
}
/**
* @param[in] acmpChannel: ACMP channel(0~1)
* @param[in] seqSel: Sequence select
*
* @return none
*
* @brief The ACMP polling mode sequence set
*/
__STATIC_INLINE void ACMP_SetPollingModeSeq(ACMP_CHANNEL acmpChannel, uint32_t seqSel)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->CR4 &= ~ACMP0_CR4_PLSEQ_Msk;
        ACMP0->CR4 |= ACMP0_CR4_PLSEQ(seqSel);
    }
}
/**
* @param[in] acmpChannel: ACMP channel(0~1)
* @param[in] channel: flag bit select
*
* @return: output value
*
* @brief Get the ACMP output value
*/
__STATIC_INLINE uint8_t ACMP_GetOutputValue(ACMP_CHANNEL acmpChannel, uint32_t channel)
{
    uint8_t err;
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        err = ACMP0->DR & channel;
    }
    else
    {
        err = ACMP1->DSR & channel;
    }
    return err;
}
/**
* @param[in] acmpChannel: ACMP channel(0~1)
* @param[in] channel:  flag bit select
*
* @return ACMP status register value
*
* @brief Get the ACMP interrupt flag bit
*/
__STATIC_INLINE uint8_t ACMP_GetFlag(ACMP_CHANNEL acmpChannel, uint32_t channel)
{
    uint8_t returnFlag;
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        returnFlag = ACMP0->SR & channel;
    }
    else
    {
        returnFlag = ACMP1->DSR & channel;
    }
    return returnFlag;
}

/**
* @param[in] acmpChannel: ACMP channel(0~1)
* @param[in] channel: flag bit select
*
* @return none
*
* @brief Clear the ACMP interrupt flag bit
*/
__STATIC_INLINE void ACMP_ClrFlag(ACMP_CHANNEL acmpChannel, uint32_t channel)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->SR |= channel;
    }
    else
    {
        ACMP1->DSR |= channel;
    }
}
/**
* @param[in] acmpChannel: ACMP channel(0~1)
* @param[in] div: Divider value
*            - 00:clk/256
*            - 01:clk/100
*            - 10:clk/70
*            - 11:clk/50
*
* @return none
*
* @brief Set ACMP Polling mode frequency divider
*/
__STATIC_INLINE void ACMP_SetPollingModeDiv(ACMP_CHANNEL acmpChannel, uint8_t div)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->FD &= ~ACMP0_FD_PLFD_Msk;
        ACMP0->FD |= div;
    }
}
/**
* @param[in] acmpChannel: ACMP channel(0~1)
* @param[in] channelA: ACMP hall output A set register
* @param[in] channelB: ACMP hall output B set register
* @param[in] channelC: ACMP hall output C set register
*            - 000:polling channel 0
*            - 001:polling channel 1
*            - 010:polling channel 2
*            - 011:polling channel 3
*            - 100:polling channel 4
*            - 101:polling channel 5
*            - 110:reserved
*            - 111:reserved
*
* @return none
*
* @brief ACMP Hall output select
*/
__STATIC_INLINE void ACMP_SetHallOutput(ACMP_CHANNEL acmpChannel, uint8_t channelA, uint8_t channelB, uint8_t channelC)
{
    if (ACMP_CHANNEL0 == acmpChannel)
    {
        ACMP0->OPA &= ~ACMP0_OPA_OPASEL_Msk;
        ACMP0->OPB &= ~ACMP0_OPB_OPBSEL_Msk;
        ACMP0->OPC &= ~ACMP0_OPC_OPCSEL_Msk;
        ACMP0->OPA |= channelA;
        ACMP0->OPB |= channelB;
        ACMP0->OPC |= channelC;
    }
}
/**
* @param[in] acmpChannel: ACMP channel(0~1)
* @param[in] refSel: Dac reference select
*            - 0:BandGap
*            - 1:VDD
*
* @return none
*
* @brief ACMP 6 bit DAC Reference Select
*/
__STATIC_INLINE void ACMP_DacReferenceSelect(ACMP_CHANNEL acmpChannel, uint8_t refSel)
{
    ACMP0->DACSR &= ~ACMP0_DACSR_DACREF_Msk;
    ACMP0->DACSR |= refSel;
}

#ifdef __cplusplus
}
#endif

#endif
