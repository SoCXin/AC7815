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

#ifndef __AC78XX_SPI_REG_H
#define __AC78XX_SPI_REG_H

#ifdef __cplusplus
extern "C" {
#endif
//lint ++flb


#include "stdint.h"
#include "stdio.h"
#include "ac78xx.h"

#define __IO    volatile                   ///< All drivers need this type
#define __I     volatile const
#define __STATIC_INLINE static __inline


typedef struct {
    struct{
        __IO uint32_t SCK_HIGH  :8;        ///< SCK high Time
        __IO uint32_t SCK_LOW   :8;        ///< SCK low Time
        __IO uint32_t CS_HOLD   :8;        ///< CS Hold Time
        __IO uint32_t CS_SETUP  :8;        ///< CS Setup Time
    }CFG0;                                 ///< SPI Control Register 0, offset: 0x0
    struct{
        __IO uint32_t CS_IDLE   :8;        ///< CS Idle Time
        __IO uint32_t TXEIE     :1;        ///< TX Buffer Empty Interrupt Enable
        __IO uint32_t RXFIE     :1;        ///< RX Buffer Full Interrupt Enable
        __IO uint32_t TXUIE     :1;        ///< TX Buffer Underflow Interrupt Enable
        __IO uint32_t RXOIE     :1;        ///< RX Buffer Overflow Interrupt Enable
        __IO uint32_t MSTR      :1;        ///< Master or Slave Mode Selection
        __IO uint32_t MODEIE    :1;        ///< Mode Fault Interrupt Enable
        __IO uint32_t DMATXEN   :1;        ///< DMA TX channel enable
        __IO uint32_t DMARXEN   :1;        ///< DMA RX Request Enable
        __IO uint32_t CPOL      :1;        ///< Clock Polarity
        __IO uint32_t CPHA      :1;        ///< Clock Phase
        __IO uint32_t TMSBF     :1;        ///< TX MSB First
        __IO uint32_t RMSBF     :1;        ///< RX MSB First
        __IO uint32_t FRMSIZE   :4;        ///< Frame Size
        __IO uint32_t           :1;
        __IO uint32_t CSOE      :1;        ///< CS Hardware Output Enable
        __IO uint32_t MODFEN    :1;        ///< Master Mode Fault Detect Enable
        __IO uint32_t           :1;
        __IO uint32_t CONT_CS   :1;        ///< CS Continuous Output Enable
        __IO uint32_t           :1;
        __IO uint32_t WKUEN     :1;        ///< Slave Wakeup Function enable
        __IO uint32_t           :1;
    }CFG1;                                 ///< SPI Controister 1, offset: 0x4
    struct{
        __IO uint32_t SPI_EN    :1;        ///< SPI Enable
        __IO uint32_t           :3;        ///< Reserve
        __IO uint32_t SW_RST    :1;        ///< Software Reset
        __IO uint32_t CS_RLS    :1;        ///< CS Release
        __IO uint32_t RO_TRIG   :1;        ///< Enable Master RX only mode trig
        __IO uint32_t           :25;       ///< Reserve
    }CMD;                                  ///< SPI Baud Rate Register, offset: 0x8
    struct{
        __IO uint32_t TXEF      :1;        ///< TX Buffer Empty Flag
        __IO uint32_t RXFF      :1;        ///< RX Buffer Full Flag
        __IO uint32_t TXUF      :1;        ///< TX Buffer Underflow Flag
        __IO uint32_t RXOF      :1;        ///< RX Buffer Overflow Flag
        __IO uint32_t MODEF     :1;        ///< Mode Fault Error Flag
        __IO uint32_t           :2;        ///< Reserve
        __IO uint32_t MEBY      :1;        ///< SPI Master Engine Busy Flag
        __IO uint32_t IDLEF     :1;        ///< SPI IDLE Flag
        __IO uint32_t           :23;       ///< Reserve
    }STATUS;                               ///< SPI Status Register, offset: 0xc
  __IO uint32_t DATA;                      ///< SPI Data Register, offset: 0x10
   struct{
        __IO uint32_t           :1;        ///< Reserve
        __IO uint32_t MNOV      :1;        ///< Master No Overflow Mode
        __IO uint32_t TOEN      :1;        ///< Master TX only enable
        __IO uint32_t ROEN      :1;        ///< Master RX only enable
        __IO uint32_t           :28;       ///< Reserve
    }CFG2;                                 ///< SPI Control Register 2, offset: 0x14
} SPI_Type;

///< SPI - Peripheral instance base addresses
///< Peripheral SPI1 base address
#define SPI1_BASE                                (0x4000c000u)

///< Peripheral SPI2 base address
#define SPI2_BASE                                (0x4000d000u)

///< Array initializer of SPI peripheral base pointers
#define SPI_BASES                                { SPI1, SPI2 }
//*****************************************************************************

/******************************************************************************
* SPI API list
*******************************************************************************/

/**
 * SPI_SetBaud
 *
 * @param[in] SPIx: SPI type pointer
 * @param[in] sckLow: SPI SCK Low count, low_time = (SCK_LOW + 1) * Bus_Period
 * @param[in] sckHigh: SPI SCK High count, high_time = (SCK_LOW + 1) * SCK_High
 * @return    none
 *
 * @brief  Set SPI CS baud, 1/(low_time + high_time)
 */
__STATIC_INLINE void SPI_SetBaud(SPI_Type *SPIx, uint32_t sckLow, uint32_t sckHigh)
{
    SPIx->CFG0.SCK_LOW = sckLow;
    SPIx->CFG0.SCK_HIGH = sckHigh;
}

/**
 * SPI_SetFRMSize
 *
 * @param[in] SPIx: SPI type pointer
 * @param[in] frameSize: SPI frame size, support 4~16bits
 * @return    none
 *
 * @brief  Set SPI frame size
 */
__STATIC_INLINE void SPI_SetFRMSize(SPI_Type *SPIx, uint32_t frameSize)
{
    SPIx->CFG1.FRMSIZE = frameSize;
}

/**
 * SPI_SetCPHA
 *
 * @param[in] SPIx: SPI type pointer
 * @param[in] cpha: SPI CPHA
 * @return    none
 *
 * @brief  Set SPI CPHA
 */
__STATIC_INLINE void SPI_SetCPHA(SPI_Type *SPIx, uint32_t cpha)
{
    SPIx->CFG1.CPHA = cpha;
}

/**
 * SPI_SetCPOL
 *
 * @param[in] SPIx: SPI type pointer
 * @param[in] cpol: SPI cpol
 * @return    none
 *
 * @brief  Set SPI CPOL
 */
__STATIC_INLINE void SPI_SetCPOL(SPI_Type *SPIx, uint32_t cpol)
{
    SPIx->CFG1.CPOL = cpol;
}

/**
 * SPI_SetRMSBF
 *
 * @param[in] SPIx: SPI type pointer
 * @param[in] rxMsbFirst: SPI Rx MSB first
 * @return    none
 *
 * @brief  Set SPI Rx MSB first
 */
__STATIC_INLINE void SPI_SetRMSBF(SPI_Type *SPIx, uint32_t rxMsbFirst)
{
    SPIx->CFG1.RMSBF = rxMsbFirst;
}

/**
 * SPI_SetTMSBF
 *
 * @param[in] SPIx: SPI type pointer
 * @param[in] txMsbFirst: SPI Tx MSB first
 * @return    none
 *
 * @brief  Set SPI Tx MSB first
 */
__STATIC_INLINE void SPI_SetTMSBF(SPI_Type *SPIx, uint32_t txMsbFirst)
{
    SPIx->CFG1.TMSBF = txMsbFirst;
}

/**
 * SPI_SetCS
 *
 * @param[in] SPIx: SPI type pointer
 * @param[in] cs: SPI CS
 * @return    none
 *
 * @brief  Set SPI CS
 */
__STATIC_INLINE void SPI_SetCS(SPI_Type *SPIx, uint32_t cs)
{
    SPIx->CFG1.CONT_CS = cs;
}

/**
 * SPI_SetCSOE
 *
 * @param[in] SPIx: SPI type pointer
 * @param[in] csOutputEn: SPI CS output enable
 * @return    none
 *
 * @brief  Set SPI CS output enable
 */
__STATIC_INLINE void SPI_SetCSOE(SPI_Type *SPIx, uint32_t csOutputEn)
{
    SPIx->CFG1.CSOE = csOutputEn;
}

/**
 * SPI_SetModeFaultEnable
 *
 * @param[in] SPIx: SPI type pointer
 * @param[in] modeFaultEn: SPI MODF
 * @return    none
 *
 * @brief  Set SPI CS mode fault
 */
__STATIC_INLINE void SPI_SetModeFaultEnable(SPI_Type *SPIx, uint32_t modeFaultEn)
{
    SPIx->CFG1.MODFEN = modeFaultEn;
}

/**
 * SPI_SetWakeupEnable
 *
 * @param[in] SPIx: SPI type pointer
 * @param[in] wakuEn: SPI WAKUEN
 * @return    none
 *
 * @brief  Set SPI wake up enable
 */
__STATIC_INLINE void SPI_SetWakeupEnable(SPI_Type *SPIx, uint32_t wakuEn)
{
    SPIx->CFG1.WKUEN = wakuEn;
}

/**
 * SPI_CSIdle
 *
 * @param[in] SPIx: SPI type pointer
 * @param[in] csIdle: SPI CS Idle
 * @return    none
 *
 * @brief  Set SPI CS Idle cnt
 */
__STATIC_INLINE void SPI_CSIdle(SPI_Type *SPIx, uint32_t csIdle)
{
    SPIx->CFG1.CS_IDLE = csIdle;
}
/**
 * SPI_CSSetup
 *
 * @param[in] SPIx: SPI type pointer
 * @param[in] csSetup: SPI CS Setup
 * @return    none
 *
 * @brief  Set SPI CS Setup cnt
 */
__STATIC_INLINE void SPI_CSSetup(SPI_Type *SPIx, uint32_t csSetup)
{
    SPIx->CFG0.CS_SETUP = csSetup;
}

/**
 * SPI_CSHold
 *
 * @param[in] SPIx: SPI type pointer
 * @param[in] csHold: SPI CS Hold
 * @return    none
 *
 * @brief  Set SPI CS Hold cnt
 */
__STATIC_INLINE void SPI_CSHold(SPI_Type *SPIx, uint32_t csHold)
{
    SPIx->CFG0.CS_HOLD = csHold;
}

/**
 * SPI_Enable
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Enable SPI module
 */
__STATIC_INLINE void SPI_Enable(SPI_Type *SPIx)
{
    SPIx->CMD.SPI_EN = 1;
}

/**
 * SPI_Disable
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Disable SPI module
 */
__STATIC_INLINE void SPI_Disable(SPI_Type *SPIx)
{
    SPIx->CMD.SPI_EN = 0;
}

/**
 * SPI_SoftwareReset
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Reset SPI Module
 */
__STATIC_INLINE void SPI_SoftwareReset(SPI_Type *SPIx)
{
    SPIx->CMD.SW_RST = 1;
}

/**
 * SPI_CSRelease
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Release SPI CS, it will go high
 */
__STATIC_INLINE void SPI_CSRelease(SPI_Type *SPIx)
{
    SPIx->CMD.CS_RLS = 1;
}

/**
 * SPI_RxOnlyModeTrig
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Start Master Receive With Rx Only Mode
 */
__STATIC_INLINE void SPI_RxOnlyModeTrig(SPI_Type *SPIx)
{
    SPIx->CMD.RO_TRIG = 1;
}

/**
 * SPI_SetMSTR
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Set SPI Master
 */
__STATIC_INLINE void SPI_SetMSTR(SPI_Type *SPIx)
{
    SPIx->CFG1.MSTR = 1;
}

 /**
 * SPI_ClrMSTR
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Clear SPI Master
 */
__STATIC_INLINE void SPI_ClrMSTR(SPI_Type *SPIx)
{
    SPIx->CFG1.MSTR = 0;
}

/**
 * SPI_EnableTxEInt
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Enable SPI TxE Interrupt
 */
__STATIC_INLINE void SPI_EnableTxEInt(SPI_Type *SPIx)
{
    SPIx->CFG1.TXEIE = 1;
}

/**
 * SPI_DisableTxEInt
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Disable SPI TxE Interrupt
 */
__STATIC_INLINE void SPI_DisableTxEInt(SPI_Type *SPIx)
{
     SPIx->CFG1.TXEIE = 0;
}

/**
 * SPI_EnableRxFInt
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Enable SPI RxF Interrupt
 */
__STATIC_INLINE void SPI_EnableRxFInt(SPI_Type *SPIx)
{
    SPIx->CFG1.RXFIE = 1;
}

/**
 * SPI_DisableRxFInt
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Disable SPI RxF Interrupt
 */
__STATIC_INLINE void SPI_DisableRxFInt(SPI_Type *SPIx)
{
    SPIx->CFG1.RXFIE = 0;
}

/**
 * SPI_EnableTxUInt
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Enable SPI TxU Interrupt
 */
__STATIC_INLINE void SPI_EnableTxUInt(SPI_Type *SPIx)
{
    SPIx->CFG1.TXUIE = 1;
}

/**
 * SPI_DisableTxUInt
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Disable SPI TxU Interrupt
 */
__STATIC_INLINE void SPI_DisableTxUInt(SPI_Type *SPIx)
{
    SPIx->CFG1.TXUIE = 0;
}

/**
 * SPI_EnableRxOInt
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Enable SPI RxO Interrupt
 */
__STATIC_INLINE void SPI_EnableRxOInt(SPI_Type *SPIx)
{
    SPIx->CFG1.RXOIE = 1;
}

/**
 * SPI_DisableRxOInt
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Disable SPI RxO Interrupt
 */
__STATIC_INLINE void SPI_DisableRxOInt(SPI_Type *SPIx)
{
    SPIx->CFG1.RXOIE = 0;
}

/**
 * SPI_EnableModeEIEInt
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Enable SPI Mode Error Interrupt
 */
__STATIC_INLINE void SPI_EnableModeEIEInt(SPI_Type *SPIx)
{
    SPIx->CFG1.MODEIE = 1;
}

/**
 * SPI_DisableModeEIEInt
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Disable SPI Mode Error Interrupt
 */
__STATIC_INLINE void SPI_DisableModeEIEInt(SPI_Type *SPIx)
{
    SPIx->CFG1.MODEIE = 0;
}


/**
 * SPI_EnableDMATx
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Enable SPI DMA Tx channel
 */
__STATIC_INLINE void SPI_EnableDMATx(SPI_Type *SPIx)
{
    SPIx->CFG1.DMATXEN = 1;
}

/**
 * SPI_DisableDMATx
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Disable SPI DMA Tx channel
 */
__STATIC_INLINE void SPI_DisableDMATx(SPI_Type *SPIx)
{
    SPIx->CFG1.DMATXEN = 0;
}

/**
 * SPI_EnableDMARx
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Enable SPI DMA Rx channel
 */
__STATIC_INLINE void SPI_EnableDMARx(SPI_Type *SPIx)
{
    SPIx->CFG1.DMARXEN = 1;
}

/**
 * SPI_DisableDMARx
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Disable SPI DMA Rx channel
 */
__STATIC_INLINE void SPI_DisableDMARx(SPI_Type *SPIx)
{
    SPIx->CFG1.DMARXEN = 0;
}

/**
 * SPI_IsMaster
 *
 * @param[in] SPIx: SPI type pointer
 * @return    0:slave, 1:master
 *
 * @brief  check current SPI Master flag
 */
__STATIC_INLINE uint32_t SPI_IsMaster(SPI_Type *SPIx)
{
    return (SPIx->CFG1.MSTR);
}

/**
 * SPI_IsTxEF
 *
 * @param[in] SPIx: SPI type pointer
 * @return    0:not empty, 1:empty
 *
 * @brief  check current SPI Tx empty flag
 */
__STATIC_INLINE uint32_t SPI_IsTxEF(SPI_Type *SPIx)
{
    return (SPIx->STATUS.TXEF);
}

/**
 * SPI_IsRxFF
 *
 * @param[in] SPIx: SPI type pointer
 * @return    0:not full, 1:full
 *
 * @brief  check current SPI Rx full flag
 */
__STATIC_INLINE uint32_t SPI_IsRxFF(SPI_Type *SPIx)
{
    return (SPIx->STATUS.RXFF);
}

/**
 * SPI_IsTxUF
 *
 * @param[in] SPIx: SPI type pointer
 * @return    0:no underflow, 1:underflow
 *
 * @brief  check current SPI Tx underflow flag
 */
__STATIC_INLINE uint32_t SPI_IsTxUF(SPI_Type *SPIx)
{
    return (SPIx->STATUS.TXUF);
}

/**
 * SPI_IsRxOF
 *
 * @param[in] SPIx: SPI type pointer
 * @return    0:no overflow, 1:overflow
 *
 * @brief  check current SPI Rx overflow flag
 */
__STATIC_INLINE uint32_t SPI_IsRxOF(SPI_Type *SPIx)
{
    return (SPIx->STATUS.RXOF);
}

/**
 * SPI_IsBusy
 *
 * @param[in] SPIx: SPI type pointer
 * @return    0:not busy, 1:busy
 *
 * @brief  check current SPI Busy flag
 */
__STATIC_INLINE uint32_t SPI_IsBusy(SPI_Type *SPIx)
{
    return (SPIx->STATUS.MEBY);
}

/**
 * SPI_IsModeFault
 *
 * @param[in] SPIx: SPI type pointer
 * @return    0:no multi-master error detected , 1:master mode error detected
 *
 * @brief  check current SPI Mode error flag
 */
__STATIC_INLINE uint32_t SPI_IsModeFault(SPI_Type *SPIx)
{
    return (SPIx->STATUS.MODEF);
}

/**
 * SPI_WriteDataReg
 *
 * @param[in] SPIx: SPI type pointer
 * @param[in] dataBuff: SPI send data
 * @return    none
 *
 * @brief  Write data into DATA register
 */
__STATIC_INLINE void SPI_WriteDataReg(SPI_Type *SPIx, uint16_t dataBuff)
{
    SPIx->DATA = dataBuff;
}

/**
 * SPI_ReadDataReg
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Read data from DATA register
 */
__STATIC_INLINE uint32_t SPI_ReadDataReg(SPI_Type *SPIx)
{
    return (SPIx->DATA);
}


/**
 * SPI_MasterNoOverflowMode
 *
 * @param[in] SPIx: SPI type pointer
 * @param[in] enable: 1:enable  0:disable
 *
 * @return    none
 *
 * @brief  Config Master no overflow mode
 */
__STATIC_INLINE void SPI_MasterNoOverflowMode(SPI_Type *SPIx, uint8_t enable)
{
    SPIx->CFG2.MNOV = enable;
}

/**
 * SPI_TxOnlyEnable
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Enable Master Tx Only
 */
__STATIC_INLINE void SPI_TxOnlyEnable(SPI_Type *SPIx)
{
    SPIx->CFG2.TOEN = 1;
}

/**
 * SPI_TxOnlyDisable
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Disable Master Tx Only
 */
__STATIC_INLINE void SPI_TxOnlyDisable(SPI_Type *SPIx)
{
    SPIx->CFG2.TOEN = 0;
}

/**
 * SPI_RxOnlyEnable
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Enable Master Rx Only
 */
__STATIC_INLINE void SPI_RxOnlyEnable(SPI_Type *SPIx)
{
    SPIx->CFG2.ROEN = 1;
}

/**
 * SPI_RxOnlyDisable
 *
 * @param[in] SPIx: SPI type pointer
 * @return    none
 *
 * @brief  Disable Master Rx Only
 */
__STATIC_INLINE void SPI_RxOnlyDisable(SPI_Type *SPIx)
{
    SPIx->CFG2.ROEN = 0;
}


typedef struct
{
    SPI_Type *SPIx;             /* SPIx Type Pointer */
    IRQn_Type SPIx_IRQn;        /* SPIx IRQ Number */
    CLK_MODULE CKGEN_SPIx;      /* SPIx Clock Enable Data */
    SRST_MODULE SRST_SPIx;      /* SPIx Module Reset Data */
}SPI_INFO;

/******************************************************************************
* Global functions
******************************************************************************/
void SPI_SetBaud(SPI_Type *SPIx, uint32_t sckLow, uint32_t sckHigh);
void SPI_SetFRMSize(SPI_Type *SPIx, uint32_t frameSize);
void SPI_SetCPHA(SPI_Type *SPIx, uint32_t cpha);
void SPI_SetCPOL(SPI_Type *SPIx, uint32_t cpol);
void SPI_SetRMSBF(SPI_Type *SPIx, uint32_t rxMsbFirst);
void SPI_SetTMSBF(SPI_Type *SPIx, uint32_t txMsbFirst);
void SPI_SetCS(SPI_Type *SPIx, uint32_t cs);
void SPI_SetCSOE(SPI_Type *SPIx, uint32_t csOutputEn);
void SPI_SetModeFaultEnable(SPI_Type *SPIx, uint32_t modeFaultEn);

void SPI_CSIdle(SPI_Type *SPIx, uint32_t csIdle);
void SPI_CSSetup(SPI_Type *SPIx, uint32_t csSetup);
void SPI_CSHold(SPI_Type *SPIx, uint32_t csHold);
void SPI_Enable(SPI_Type *SPIx);
void SPI_Disable(SPI_Type *SPIx);
void SPI_CSRelease(SPI_Type *SPIx);
void SPI_RxOnlyModeTrig(SPI_Type *SPIx);
void SPI_SetMSTR(SPI_Type *SPIx);
void SPI_ClrMSTR(SPI_Type *SPIx);
void SPI_EnableTxEInt(SPI_Type *SPIx);
void SPI_DisableTxEInt(SPI_Type *SPIx);
void SPI_EnableRxFInt(SPI_Type *SPIx);
void SPI_DisableRxFInt(SPI_Type *SPIx);
void SPI_EnableTxUInt(SPI_Type *SPIx);
void SPI_DisableTxUInt(SPI_Type *SPIx);
void SPI_EnableRxOInt(SPI_Type *SPIx);
void SPI_DisableRxOInt(SPI_Type *SPIx);
void SPI_EnableModeEIEInt(SPI_Type *SPIx);
void SPI_DisableModeEIEInt(SPI_Type *SPIx);
void SPI_EnableDMATx(SPI_Type *SPIx);
void SPI_DisableDMATx(SPI_Type *SPIx);
void SPI_EnableDMARx(SPI_Type *SPIx);
void SPI_DisableDMARx(SPI_Type *SPIx);
void SPI_TxOnlyEnable(SPI_Type *SPIx);
void SPI_TxOnlyDisable(SPI_Type *SPIx);
void SPI_RxOnlyEnable(SPI_Type *SPIx);
void SPI_RxOnlyDisable(SPI_Type *SPIx);

uint32_t SPI_IsMaster(SPI_Type *SPIx);
uint32_t SPI_IsTxEF(SPI_Type *SPIx);
uint32_t SPI_IsRxFF(SPI_Type *SPIx);
uint32_t SPI_IsTxUF(SPI_Type *SPIx);
uint32_t SPI_IsRxOF(SPI_Type *SPIx);
uint32_t SPI_IsBusy(SPI_Type *SPIx);
uint32_t SPI_IsModeFault(SPI_Type *SPIx);
void SPI_WriteDataReg(SPI_Type *SPIx, uint16_t dataBuff);
uint32_t SPI_ReadDataReg(SPI_Type *SPIx);
void SPI_SoftwareReset(SPI_Type *SPIx);

void SPI1_IRQHandler(void);
void SPI2_IRQHandler(void);
int32_t SPI_MasterIntHandler(SPI_Type *SPIx,uint32_t wparam, uint32_t lparam);
int32_t SPI_SlaveIntHandler(SPI_Type *SPIx,uint32_t wparam, uint32_t lparam);

//lint --flb

#ifdef __cplusplus
}
#endif

#endif
