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

#ifndef __AC78XX_DMA_REG_H
#define __AC78XX_DMA_REG_H
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

#define __IO    volatile                                    ///< All drivers need this type
#define __I     volatile const

#if defined ( __ICCARM__ )
#define __STATIC_INLINE static inline
#elif defined ( __GNUC__)
#define __STATIC_INLINE static inline
#elif defined (__CC_ARM)
#define __STATIC_INLINE static __inline
#endif

typedef struct {
    struct {
        __IO uint32_t WARM_RST                      :1;
        __IO uint32_t HARD_RST                      :1;
        __IO uint32_t                               :30;
    }TOP_RST;                                               ///< DMA Top Reset Register, offset: 0x0
} DMA_Top_Type;


typedef struct {
    union{
        struct {
            __IO uint32_t FINISH                    :1;
            __IO uint32_t HALF_FINISH               :1;
            __IO uint32_t TRANS_ERROR               :1;
            __IO uint32_t                           :29;
        }CHANNELx_STATUS_Bit;
        __IO uint32_t CHANNELx_STATUS_Byte;
    }CHANNELx_STATUS;                                       ///< DMA Channelx Status Register, offset: 0x0
    struct {
        __IO uint32_t FINISH_INTERRUPT_ENABLE       :1;
        __IO uint32_t HALF_FINISH_INTERRUPT_ENABLE  :1;
        __IO uint32_t TRANS_ERROR_INTERRUPT_ENABLE  :1;
        __IO uint32_t                               :29;
    }CHANNELx_INTEN;                                        ///< DMA Channelx Interrupt Enable Register, offset: 0x4
    struct {
        __IO uint32_t WARM_RST                      :1;
        __IO uint32_t HARD_RST                      :1;
        __IO uint32_t FLUSH                         :1;
        __IO uint32_t                               :29;
    }CHANNELx_RST;                                          ///< DMA Channelx Reset Register, offset: 0x8
    struct {
        __IO uint32_t STOP                          :1;     ///< 0:resume data transfer 1:transfer paused
        __IO uint32_t                               :31;
    }CHANNELx_STOP;                                         ///< DMA Channelx STOP Register, offset: 0xc
    struct {
        __IO uint32_t MEM2MEM                       :1;     ///< 0: transfer between non MEM and MEM  1: transfer between MEM and  MEM
        __IO uint32_t CHAN_PRIORITY                 :2;
        __IO uint32_t MEM_SIZE                      :2;
        __IO uint32_t PERIPH_SIZE                   :2;
        __IO uint32_t MEM_INCREAMENT                :1;     ///< 0: MEM address fixed  1: MEM address increment
        __IO uint32_t PERIPH_INCREAMENT             :1;     ///< 0: Peripheral address fixed  1: Peripheral address increment
        __IO uint32_t CHAN_CIRCULAR                 :1;     ///< 0: Circular mode disable  1: Circular mode enable
        __IO uint32_t CH_DIR                        :1;     ///< 0: read from Peripheral  1: read from MEM
        __IO uint32_t MEM_BYTE_MODE                 :2;
        __IO uint32_t                               :19;
    }CHANNELx_CONFIG;                                       ///< DMA Channelx Configuration Register, offset: 0x10
    struct {
        __IO uint32_t CHAN_LENGTH                   :15;
        __IO uint32_t                               :17;
    }CHANNELx_CHAN_LENGTH;                                  ///< DMA Channelx Channel Length Register, offset: 0x14
    __IO uint32_t CHANNELx_MEM_START_ADDR;                  ///< DMA Channelx Memory Start Address Register, offset: 0x18
    __IO uint32_t CHANNELx_MEM_END_ADDR;                    ///< DMA Channelx Memory End Address Register, offset: 0x1C
    __IO uint32_t CHANNELx_PERIPH_ADDR;                     ///< DMA Channelx Configuration Register, offset: 0x20
    struct {
        __IO uint32_t CHAN_ENABLE                   :1;
        __IO uint32_t                               :31;
    }CHANNELx_CHAN_ENABLE;                                  ///< DMA Channelx Channel Enable Register, offset: 0x24
    struct {
        __I uint32_t DATA_TRANS_NUM                 :16;
        __I uint32_t                                :16;
    }CHANNELx_DATA_TRANS_NUM;                               ///< DMA Channelx Data Transfered Number Register, offset: 0x28
    struct {
        __I uint32_t INTER_FIFO_DATA_LEFT_NUM       :6;
        __I uint32_t                                :26;
    }CHANNELx_INTER_FIFO_DATA_LEFT_NUM;                     ///< DMA Channelx Internal FIFO Data Left Number Register, offset: 0x2C

} DMA_Type;

/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/* DMA - Peripheral instance base addresses */
/** Peripheral DMA0 base address */
#define DMA0_BASE                                (0x40012000u)
/** Peripheral DMA0 base pointer */
#define DMA0                                     ((DMA_Top_Type *)DMA0_BASE)
/** Peripheral DMA1 base address */
#define DMA1_BASE                                (DMA0_BASE + 0x40u)
/** Peripheral DMA2 base address */
#define DMA2_BASE                                (DMA0_BASE + 0x80u)
/** Peripheral DMA3 base address */
#define DMA3_BASE                                (DMA0_BASE + 0xC0u)
/** Peripheral DMA4 base address */
#define DMA4_BASE                                (DMA0_BASE + 0x100u)
/** Peripheral DMA5 base address */
#define DMA5_BASE                                (DMA0_BASE + 0x140u)
/** Peripheral DMA6 base address */
#define DMA6_BASE                                (DMA0_BASE + 0x180u)
/** Peripheral DMA7 base address */
#define DMA7_BASE                                (DMA0_BASE + 0x1C0u)
/** Peripheral DMA8 base address */
#define DMA8_BASE                                (DMA0_BASE + 0x200u)
/** Peripheral DMA9 base address */
#define DMA9_BASE                                (DMA0_BASE + 0x240u)
/** Peripheral DMA10 base address */
#define DMA10_BASE                               (DMA0_BASE + 0x280u)
/** Peripheral DMA11 base address */
#define DMA11_BASE                               (DMA0_BASE + 0x2C0u)
/** Peripheral DMA12 base address */
#define DMA12_BASE                               (DMA0_BASE + 0x300u)

/** Array initializer of SPI peripheral base pointers */
#define DMA_BASES                                { DMA0, DMA1, DMA2, DMA3, DMA4, DMA5, DMA6, DMA7, DMA8, DMA9, DMA10, DMA11, DMA12}
//*****************************************************************************
typedef void (*DMA_CallbackType)(DMA_Type *DMAx);
/******************************************************************************
* DMA API list
*******************************************************************************/

/**
 * DMA_TopWarmRst
 *
 * @param[in] none
 * @return    none
 *
 * @brief  DMA Top warm reset
 */
__STATIC_INLINE void DMA_TopWarmRst(void)
{
    DMA0->TOP_RST.WARM_RST = 1;
}

/**
 * DMA_TopHardRst
 *
 * @param[in] none
 * @return    none
 *
 * @brief  DMA Top hard reset
 */
__STATIC_INLINE void DMA_TopHardRst(void)
{
    DMA0->TOP_RST.HARD_RST = 1;
    DMA0->TOP_RST.HARD_RST = 0;
}

/**
 * DMA_IsFinish
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @return    0:Data transfer not finished, 1:Data transfer finished
 *
 * @brief  check current DMA finish flag
 */
__STATIC_INLINE uint32_t DMA_IsFinish(DMA_Type *DMAx)
{
    return (DMAx->CHANNELx_STATUS.CHANNELx_STATUS_Bit.FINISH);
}

/**
 * DMA_IsHalfFinish
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @return    0:Half of data not finished, 1:Half of data finished
 *
 * @brief  check current DMA half finish flag
 */
__STATIC_INLINE uint32_t DMA_IsHalfFinish(DMA_Type *DMAx)
{
    return (DMAx->CHANNELx_STATUS.CHANNELx_STATUS_Bit.HALF_FINISH);
}

/**
 * DMA_IsTransferError
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @return    0:Error not happened, 1:Error happened
 *
 * @brief  check current DMA transfer error flag
 */
__STATIC_INLINE uint32_t DMA_IsTransferError(DMA_Type *DMAx)
{
    return (DMAx->CHANNELx_STATUS.CHANNELx_STATUS_Bit.TRANS_ERROR);
}

/**
 * DMA_EnableFinishInt
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @return    none
 *
 * @brief  Enable DMA Finish interrupt
 */
__STATIC_INLINE void DMA_EnableFinishInt(DMA_Type *DMAx)
{
    DMAx->CHANNELx_INTEN.FINISH_INTERRUPT_ENABLE = 1;
}

/**
 * DMA_EnableHalfFinishInt
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @return    none
 *
 * @brief  Enable DMA Half Finish interrupt
 */
__STATIC_INLINE void DMA_EnableHalfFinishInt(DMA_Type *DMAx)
{
    DMAx->CHANNELx_INTEN.HALF_FINISH_INTERRUPT_ENABLE = 1;
}

/**
 * DMA_EnableTransferErrorInt
 *
 * @param[in]  DMAx:DMA type pointer,x can be 1 to 12
 * @return     none
 *
 * @brief  Enable DMA Transfer Error interrupt
 */
__STATIC_INLINE void DMA_EnableTransferErrorInt(DMA_Type *DMAx)
{
    DMAx->CHANNELx_INTEN.TRANS_ERROR_INTERRUPT_ENABLE = 1;
}

/**
 * DMA_EnableFinishInt
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @return    none
 *
 * @brief  Disable DMA Finish interrupt
 */
__STATIC_INLINE void DMA_DisbleFinishInt(DMA_Type *DMAx)
{
    DMAx->CHANNELx_INTEN.FINISH_INTERRUPT_ENABLE = 0;
}

/**
 * DMA_DisableHalfFinishInt
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @return    none
 *
 * @brief  Disable DMA Half Finish interrupt
 */
__STATIC_INLINE void DMA_DisableHalfFinishInt(DMA_Type *DMAx)
{
    DMAx->CHANNELx_INTEN.HALF_FINISH_INTERRUPT_ENABLE = 0;
}

/**
 * DMA_DisableTransferErrorInt
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @return    none
 *
 * @brief  Disable DMA Transfer Error interrupt
 */
__STATIC_INLINE void DMA_DisableTransferErrorInt(DMA_Type *DMAx)
{
    DMAx->CHANNELx_INTEN.TRANS_ERROR_INTERRUPT_ENABLE = 0;
}

/**
 * DMA_ChannelWarmRst
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @return    none
 *
 * @brief  DMA channel warm reset
 */
__STATIC_INLINE void DMA_ChannelWarmRst(DMA_Type *DMAx)
{
    DMAx->CHANNELx_RST.WARM_RST = 1;
}

/**
 * DMA_ChannelHardRst
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @return    none
 *
 * @brief  DMA channel hard reset
 */
__STATIC_INLINE void DMA_ChannelHardRst(DMA_Type *DMAx)
{
    DMAx->CHANNELx_RST.HARD_RST = 1;
    DMAx->CHANNELx_RST.HARD_RST = 0;
}

/**
 * DMA_ChannelPause
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @return    none
 *
 * @brief  DMA channel transfer pause
 */
__STATIC_INLINE void DMA_ChannelPause(DMA_Type *DMAx)
{
    DMAx->CHANNELx_STOP.STOP= 1;
}

/**
 * DMA_ChannelResume
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @return    none
 *
 * @brief  DMA channel transfer resume
 */
__STATIC_INLINE void DMA_ChannelResume(DMA_Type *DMAx)
{
    DMAx->CHANNELx_STOP.STOP= 0;
}

/**
 * DMA_ChannelM2M
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @param[in] MEM2MEM:DMA Memory 2 Memory.
 *                    0:transfer between memory and periph
 *                    1:transfer between memory and memory
 * @return    none
 *
 * @brief  Set DMA channel transfer between MEM and MEM or Peripheral
 */
__STATIC_INLINE void DMA_ChannelM2M(DMA_Type *DMAx, uint32_t MEM2MEM)
{
    DMAx->CHANNELx_CONFIG.MEM2MEM = MEM2MEM;
}

/**
 * DMA_ChannelPriority
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @param[in] channelPriority:DMA Priority,value can be
 *                          - 0:low
 *                          - 1:middle
 *                          - 2:high
 *                          - 3:very high
 * @return    none
 *
 * @brief  Set DMA channel priority
 */
__STATIC_INLINE void DMA_ChannelPriority(DMA_Type *DMAx, uint32_t channelPriority)
{
    DMAx->CHANNELx_CONFIG.CHAN_PRIORITY = channelPriority;
}

/**
 * DMA_ChannelMemSize
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @param[in] memSize:DMA Memory size,value can be
 *                          - 0:8bit
 *                          - 1:16bit
 *                          - 2:32bit
 *                          - 3:reserve
 * @return    none
 *
 * @brief  Set DMA channel Memory size
 */
__STATIC_INLINE void DMA_ChannelMemSize(DMA_Type *DMAx, uint32_t memSize)
{
    DMAx->CHANNELx_CONFIG.MEM_SIZE = memSize;
}

/**
 * DMA_ChannelPeriphSize
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @param[in] periphSize:DMA Periph size,32bit data
 * @return    none
 *
 * @brief  Set DMA channel Peripheral size
 */
__STATIC_INLINE void DMA_ChannelPeriphSize(DMA_Type *DMAx, uint32_t periphSize)
{
    DMAx->CHANNELx_CONFIG.PERIPH_SIZE = periphSize;
}

/**
 * DMA_ChannelMemIncrement
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @param[in] memIncrement:DMA Memory increment,value can be
 *                          - 0:memory address fixed
 *                          - 1:memory address increment
 * @return    none
 *
 * @brief  Set DMA channel memory increment
 */
__STATIC_INLINE void DMA_ChannelMemIncrement(DMA_Type *DMAx, uint32_t memIncrement)
{
    DMAx->CHANNELx_CONFIG.MEM_INCREAMENT = memIncrement;
}

/**
 * DMA_ChannelPeriphIncrement
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @param[in] periphIncrement:DMA Periph increment,value can be
 *                          - 0:periph address fixed
 *                          - 1:periph address increment
 * @return    none
 *
 * @brief  Set DMA channel Peripheral increment
 */
__STATIC_INLINE void DMA_ChannelPeriphIncrement(DMA_Type *DMAx, uint32_t periphIncrement)
{
    DMAx->CHANNELx_CONFIG.PERIPH_INCREAMENT = periphIncrement;
}

/**
 * DMA_ChannelCircular
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @param[in] channelCircular:DMA channel circular,value can be
 *                          - 0:circular mode disable
 *                          - 1:circular mode enable
 * @return    none
 *
 * @brief  Set DMA channel circular
 */
__STATIC_INLINE void DMA_ChannelCircular(DMA_Type *DMAx, uint32_t channelCircular)
{
    DMAx->CHANNELx_CONFIG.CHAN_CIRCULAR = channelCircular;
}

/**
 * DMA_ChannelDir
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @param[in] channelDir:DMA channel direction,value can be
 *                          - 0:read from periph
 *                          - 1:read from memory
 * @return    none
 *
 * @brief  Set DMA channel direction
 */
__STATIC_INLINE void DMA_ChannelDir(DMA_Type *DMAx, uint32_t channelDir)
{
    DMAx->CHANNELx_CONFIG.CH_DIR = channelDir;
}

/**
 * DMA_ChannelMemByteMode
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @param[in] memByteMode:DMA channel mem byte mode,indicate memory word split
 *                        transfer number,value can be
 *                          - 0:means 32bit data don't split.direct send Bit[31:0]
 *                          - 1:means 32bit data will split to Bit[31:16]&Bit[15:0]
 *                              first send Bit[15:0],last send Bit[31:16].
 *                          - 2:means 32bit data will split to Bit[31:24,15:8]&Bit[23:16,7:0]
 *                              first send Bit[23:16,7:0],last send Bit[31:24,15:8].
 *                          - 3:means 32bit data will split to Bit[31:24]&Bit[23:16]&Bit[15:8]&Bit7:0]
 *                              first send Bit[7:0],second send Bit[15:8],the third time sendBit[23:16] and last Bit[31:24].
 * @return    none
 *
 * @brief  Set DMA channel memory byte mode
 */
__STATIC_INLINE void DMA_ChannelMemByteMode(DMA_Type *DMAx, uint32_t memByteMode)
{
    DMAx->CHANNELx_CONFIG.MEM_BYTE_MODE = memByteMode;
}

/**
 * DMA_ChannelSetLength
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @param[in] channelLength:DMA channel transfer length
 * @return    none
 *
 * @brief  Set DMA channel transfer length
 */
__STATIC_INLINE void DMA_ChannelSetLength(DMA_Type *DMAx, uint32_t channelLength)
{
    DMAx->CHANNELx_CHAN_LENGTH.CHAN_LENGTH = channelLength;
}



/**
 * DMA_ChannelMemStartAddr
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @param[in] memStartAddr:DMA memory start address,32bit data
 * @return    none
 *
 * @brief  Set DMA memory start address
 */
__STATIC_INLINE void DMA_ChannelMemStartAddr(DMA_Type *DMAx, uint32_t memStartAddr)
{
    DMAx->CHANNELx_MEM_START_ADDR = memStartAddr;
}

/**
 * DMA_ChannelMemEndAddr
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @param[in] memEndAddr:DMA memory end address,32bit data
 * @return    none
 *
 * @brief  Set DMA memory end address
 */
__STATIC_INLINE void DMA_ChannelMemEndAddr(DMA_Type *DMAx, uint32_t memEndAddr)
{
    DMAx->CHANNELx_MEM_END_ADDR = memEndAddr;
}

/**
 * DMA_ChannelPeriphAddr
 *
 * @param[in] DMAx:DMA type pointer,x can be 1 to 12
 * @param[in] periphAddr:DMA peripheral address,32bit data
 * @return    none
 *
 * @brief  Set DMA peripheral address
 */
__STATIC_INLINE void DMA_ChannelPeriphAddr(DMA_Type *DMAx, uint32_t periphAddr)
{
    DMAx->CHANNELx_PERIPH_ADDR = periphAddr;
}



/******************************************************************************
* Global functions
******************************************************************************/
void DMA_TopWarmRst(void);
void DMA_TopHardRst(void);
uint32_t DMA_IsFinish(DMA_Type *DMAx);
uint32_t DMA_IsHalfFinish(DMA_Type *DMAx);
uint32_t DMA_IsTransferError(DMA_Type *DMAx);
void DMA_EnableFinishInt(DMA_Type *DMAx);
void DMA_EnableHalfFinishInt(DMA_Type *DMAx);
void DMA_EnableTransferErrorInt(DMA_Type *DMAx);
void DMA_DisableFinishInt(DMA_Type *DMAx);
void DMA_DisableHalfFinishInt(DMA_Type *DMAx);
void DMA_DisableTransferErrorInt(DMA_Type *DMAx);
void DMA_ChannelWarmRst(DMA_Type *DMAx);
void DMA_ChannelHardRst(DMA_Type *DMAx);

void DMA_ChannelPause(DMA_Type *DMAx);
void DMA_ChannelResume(DMA_Type *DMAx);
void DMA_ChannelM2M(DMA_Type *DMAx, uint32_t MEM2MEM);
void DMA_ChannelPriority(DMA_Type *DMAx, uint32_t channelPriority);
void DMA_ChannelMemSize(DMA_Type *DMAx, uint32_t memSize);
void DMA_ChannelPeriphSize(DMA_Type *DMAx, uint32_t periphSize);
void DMA_ChannelMemIncrement(DMA_Type *DMAx, uint32_t memIncrement);
void DMA_ChannelPeriphIncrement(DMA_Type *DMAx, uint32_t periphIncrement);
void DMA_ChannelCircular(DMA_Type *DMAx, uint32_t channelCircular);
void DMA_ChannelDir(DMA_Type *DMAx, uint32_t channelDir);
void DMA_ChannelMemByteMode(DMA_Type *DMAx, uint32_t memByteMode);
void DMA_ChannelSetLength(DMA_Type *DMAx, uint32_t channelLength);
void DMA_ChannelMemStartAddr(DMA_Type *DMAx, uint32_t memStartAddr);
void DMA_ChannelMemEndAddr(DMA_Type *DMAx, uint32_t memEndAddr);
void DMA_ChannelPeriphAddr(DMA_Type *DMAx, uint32_t periphAddr);





#ifdef __cplusplus
}
#endif

#endif
