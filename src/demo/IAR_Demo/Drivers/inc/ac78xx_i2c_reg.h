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

#ifndef AC78XX_I2C_REG_H_
#define AC78XX_I2C_REG_H_
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
#include "ac78xx_dma.h"
#include "ac78xx.h"

#define __IO    volatile                    ///< All drivers need this type
#define __I    volatile const

#if defined ( __ICCARM__ )
#define __STATIC_INLINE static inline
#elif defined ( __GNUC__)
#define __STATIC_INLINE static inline
#elif defined (__CC_ARM)
#define __STATIC_INLINE static __inline
#endif


//***********************************************************************************************
typedef struct {
    __IO uint32_t ADDR1;                    ///< I2C Address 1 Register, offset: 0x0
    __IO uint32_t ADDR2;                    ///< I2C Address 2 Register, offset: 0x4
    __IO uint32_t SAMPLE_CNT;               ///< I2C Sample Count Register, offset: 0x8
    __IO uint32_t STEP_CNT;                 ///< I2C Step Count Register, offset: 0xC
    struct {
        __IO uint32_t SWRST     : 1;        ///< Reserved
        __IO uint32_t           : 1;        ///< Reserved
        __IO uint32_t WUEN      : 1;        ///< Wakeup function Enable
        __IO uint32_t TACK      : 1;        ///< Ackmowledge Control
        __IO uint32_t TX        : 1;        ///< Transmit direction select
        __IO uint32_t MSTR      : 1;        ///< I2C Operation mode select
        __IO uint32_t IICIE     : 1;        ///< I2C Interrupt Enable
        __IO uint32_t IICEN     : 1;        ///< I2C Module Enable
        __IO uint32_t           : 24;
    } CONTROL_1;                            ///< I2C Control 1 Register, offset: 0x10
    struct {
        __IO uint32_t STREN     : 1;        ///< Slave SCL Stretch Enable
        __IO uint32_t           : 2;        ///< Reserved
        __IO uint32_t ARBEN     : 1;        ///< Master Arbitration Enable
        __IO uint32_t SYNCEN    : 1;        ///< Master SCL Sync Enable
        __IO uint32_t           : 1;        ///< Reserved
        __IO uint32_t ADEXT     : 1;        ///< Slave Address Extension
        __IO uint32_t GCAEN     : 1;        ///< Salve General Call Enable
        __IO uint32_t           : 24;       ///< Reserved
    } CONTROL_2;                            ///< I2C Control 2 Register, offset: 0x14
    struct {
        __IO uint32_t MNTEN     : 1;        ///< Slave Monitor Function Enable
        __IO uint32_t NACKIE    : 1;        ///< NACK Get Interrupt Enable
        __IO uint32_t           : 1;        ///< Reserved
        __IO uint32_t STRRLS    : 1;        ///< NACK Get Interrupt Enable
        __IO uint32_t TXEIE     : 1;        ///< Slave TX Buffer Empty Interrupt Enable
        __IO uint32_t RXFIE     : 1;        ///< Slave RX Buffer Full Interrupt Enable
        __IO uint32_t TXUFIE    : 1;        ///< Slave TX Buffer Underflow Error Interrupt Enable
        __IO uint32_t RXOFIE    : 1;        ///< Slave RX Buffer Overflow Error Interrupt Enable
        __IO uint32_t           : 24;       ///< Reserved
    } CONTROL_3;                            ///< I2C Control 3 Register, offset: 0x18
    struct {
        __IO uint32_t DMATXEN   : 1;        ///< DMA RX Enable
        __IO uint32_t DMARXEN   : 1;        ///< DMA TX Enable
        __IO uint32_t           : 1;        ///< Reserved
        __IO uint32_t           : 4;        ///< Reserved
        __IO uint32_t           : 1;        ///< Reserved
        __IO uint32_t           : 24;       ///< Reserved
    } CONTROL_4;                            ///< I2C Control 4 Register, offset: 0x1C
    union {
        struct {
            __IO uint32_t RACK      : 1;    ///< Acknowledge Received
            __IO uint32_t           : 1;    ///< Reserved
            __IO uint32_t SRW       : 1;    ///< Slave Read/Write Direction
            __IO uint32_t READY     : 1;    ///< Internal Hardware Core Is Ready For New Command
            __IO uint32_t ARBLOST   : 1;    ///< Arbitration Lost Flag
            __IO uint32_t BUSY      : 1;    ///< BUS Busy
            __IO uint32_t DEVHIT    : 1;    ///< Slave Address Match Flag
            __IO uint32_t TCF       : 1;    ///< Byte End Flag
            __IO uint32_t           : 24;   ///< Reserved
        } STATUS_1_Bit;
        __IO uint32_t STATUS_1_Byte;
    } STATUS_1;                             ///< I2C Status 1 Register, offset: 0x20
    union {
        struct {
            __IO uint32_t TXEF  : 1;        ///< Slave TX Buffer Empty Flag
            __IO uint32_t RXFF  : 1;        ///< Slave RX Buffer Full Flag
            __IO uint32_t TXUF  : 1;        ///< Slave TX Buffer Underflow Flag
            __IO uint32_t RXOF  : 1;        ///< Slave RX Buffer Overflow Flag
            __IO uint32_t       : 28;       ///< Reserved
        } STATUS_2_Bit;
        __IO uint32_t STATUS_2_Byte;
    } STATUS_2;                             ///< I2C Status 2 Register, offset: 0x24
    union {
        struct {
            __IO uint32_t DGL_CNT   : 4;    ///< Deglitch Counter
            __IO uint32_t STARTF    : 1;    ///< Bus START Flag
            __IO uint32_t SSIE      : 1;    ///< Bus STOP Or START Interrupt  Enable
            __IO uint32_t STOPF     : 1;    ///< Bus STOP  Flag
            __IO uint32_t DGLEN     : 1;    ///< Deglitch Filter Enable
            __IO uint32_t           : 24;   ///< Reserved
        } DGL_CFG_Bit;
        __IO uint32_t DGL_CFG_Byte;
    } DGL_CFG;                              ///< I2C Deglitch Configure Register , offset: 0x28
    __IO uint32_t DATA;                     ///< I2C Data Register, offset: 0x2C
    struct {
        __IO uint32_t START   : 1;          ///< Master START Trig
        __IO uint32_t STOP    : 1;          ///< Master STOP Trig
        __IO uint32_t         : 30;         ///< Reserved
    } START_STOP;                           ///< I2C Start Stop Register, offset: 0x30
    __IO uint32_t SCL_ADJ;                  ///< I2C SCL Adjust Register, offset: 0x34
    __I  uint32_t reserved1;                ///< I2C Reserved Register, offset: 0x38
    __I  uint32_t reserved2;                ///< I2C Reserved Register, offset: 0x3C
    struct {
        __IO uint32_t READ_TIME     : 4;    ///< Master Data Read Time
        __IO uint32_t               : 3;    ///< Reserved
        __IO uint32_t DRD_ADJ_EN    : 1;    ///< Master Data Read Time Adjust Enable
        __IO uint32_t               : 24;   ///< Reserved
    } DRD_ADJ;                              ///< I2C Data Read Adjust Register, offset: 0x40
} I2C_Type;
/* ----------------------------------------------------------------------------
   -- I2C Register Masks
   ---------------------------------------------------------------------------- */
///< ADDR1 Bit Fields
#define I2C_ADDR1_AD_MASK                           0xFEu
#define I2C_ADDR1_AD_SHIFT                          1
#define I2C_ADDR1_AD(x)                             (((uint32_t)(((uint32_t)(x))<<I2C_ADDR1_AD_SHIFT))&I2C_ADDR1_AD_MASK)
///< ADDR2 Bit Fields
#define I2C_ADDR2_SAD_MASK                          0x07u
#define I2C_ADDR2_SAD_SHIFT                         1
#define I2C_ADDR2_SAD(x)                            (((uint32_t)(((uint32_t)(x))<<I2C_ADDR2_SAD_SHIFT))&I2C_ADDR2_SAD_MASK)
///< SAMPLE_CNT Bit Fields
#define I2C_SAMPLE_CNT_DIV_MASK                     0xFFu
#define I2C_SAMPLE_CNT_DIV_SHIFT                    0
#define I2C_SAMPLE_CNT_DIV(x)                       (((uint32_t)(((uint32_t)(x))<<I2C_SAMPLE_CNT_DIV_SHIFT))&I2C_SAMPLE_CNT_DIV_MASK)
///< STEP_CNT Bit Fields
#define I2C_STEP_CNT_DIV_MASK                       0xFFu
#define I2C_STEP_CNT_DIV_SHIFT                      0
#define I2C_STEP_CNT_DIV(x)                         (((uint32_t)(((uint32_t)(x))<<I2C_STEP_CNT_DIV_SHIFT))&I2C_STEP_CNT_DIV_MASK)
///< CONTROL_1 Bit Fields
#define I2C_CONTROL_1_SWRST_MASK                    0x1u
#define I2C_CONTROL_1_SWRST_SHIFT                   0
#define I2C_CONTROL_1_WAKEUP_EN_MASK                0x4u
#define I2C_CONTROL_1_WAKEUP_EN_SHIFT               2
#define I2C_CONTROL_1_TACK_MASK                     0x8u
#define I2C_CONTROL_1_TACK_SHIFT                    3
#define I2C_CONTROL_1_TX_MASK                       0x10u
#define I2C_CONTROL_1_TX_SHIFT                      4
#define I2C_CONTROL_1_MSTR_MASK                     0x20u
#define I2C_CONTROL_1_MSTR_SHIFT                    5
#define I2C_CONTROL_1_IICIE_MASK                    0x40u
#define I2C_CONTROL_1_IICIE_SHIFT                   6
#define I2C_CONTROL_1_IICEN_MASK                    0x80u
#define I2C_CONTROL_1_IICEN_SHIFT                   7
///< CONTROL_2 Bit Fields
#define I2C_CONTROL_2_STR_EN_MASK                   0x1u
#define I2C_CONTROL_2_STR_EN_SHIFT                  0
#define I2C_CONTROL_2_ARB_EN_MASK                   0x8u
#define I2C_CONTROL_2_ARB_EN_SHIFT                  3
#define I2C_CONTROL_2_SYNC_EN_MASK                  0x10u
#define I2C_CONTROL_2_SYNC_EN_SHIFT                 4
#define I2C_CONTROL_2_ADEXT_MASK                    0x40u
#define I2C_CONTROL_2_ADEXT_SHIFT                   6
#define I2C_CONTROL_2_GCA_EN_MASK                   0x80u
#define I2C_CONTROL_2_GCA_EN_SHIFT                  7
///< CONTROL_3 Bit Fields
#define I2C_CONTROL_3_MNTEN_MASK                    0x1u
#define I2C_CONTROL_3_MNTEN_SHIFT                   0
#define I2C_CONTROL_3_MNTIE_MASK                    0x2u
#define I2C_CONTROL_3_MNTIE_SHIFT                   1
#define I2C_CONTROL_3_MNTACT_MASK                   0x4u
#define I2C_CONTROL_3_MNTACT_SHIFT                  2
#define I2C_CONTROL_3_STRRLS_MASK                   0x8u
#define I2C_CONTROL_3_STRRLS_SHIFT                  3
#define I2C_CONTROL_3_TXEMIE_MASK                   0x10u
#define I2C_CONTROL_3_TXEMIE_SHIFT                  4
#define I2C_CONTROL_3_RXFIE_MASK                    0x20u
#define I2C_CONTROL_3_RXFIE_SHIFT                   5
#define I2C_CONTROL_3_TXUFIE_MASK                   0x40u
#define I2C_CONTROL_3_TXUFIE_SHIFT                  6
#define I2C_CONTROL_3_RXOFIE_MASK                   0x80u
#define I2C_CONTROL_3_RXOFIE_SHIFT                  7
///< CONTROL_4 Bit Fields
#define I2C_CONTROL_4_DMA_RX_EN_MASK                0x1u
#define I2C_CONTROL_4_DMA_RX_EN_SHIFT               0
#define I2C_CONTROL_4_DMA_TX_EN_MASK                0x2u
#define I2C_CONTROL_4_DMA_TX_EN_SHIFT               1
#define I2C_CONTROL_4_DMA_EN_MASK                   0x4u
#define I2C_CONTROL_4_DMA_EN_SHIFT                  2
///< STATUS_1 Bit Fields
#define I2C_STATUS_1_RACK_MASK                      0x1u
#define I2C_STATUS_1_RACK_SHIFT                     0
#define I2C_STATUS_1_SRW_MASK                       0x4u
#define I2C_STATUS_1_SRW_SHIFT                      2
#define I2C_STATUS_1_READY_MASK                     0x8u
#define I2C_STATUS_1_READY_SHIFT                    3
#define I2C_STATUS_1_ARBLOST_MASK                   0x10u
#define I2C_STATUS_1_ARBLOST_SHIFT                  4
#define I2C_STATUS_1_BUSY_MASK                      0x20u
#define I2C_STATUS_1_BUSY_SHIFT                     5
#define I2C_STATUS_1_DEV_HIT_MASK                   0x40u
#define I2C_STATUS_1_DEV_HIT_SHIFT                  6
#define I2C_STATUS_1_TCF_MASK                       0x80u
#define I2C_STATUS_1_TCF_SHIFT                      7
///< STATUS_2 Bit Fields
#define I2C_STATUS_2_TXEF_MASK                      0x1u
#define I2C_STATUS_2_TXEF_SHIFT                     0
#define I2C_STATUS_2_RXFF_MASK                      0x2u
#define I2C_STATUS_2_RXFF_SHIFT                     1
#define I2C_STATUS_2_TXUF_MASK                      0x4u
#define I2C_STATUS_2_TXUF_SHIFT                     2
#define I2C_STATUS_2_RXOF_MASK                      0x8u
#define I2C_STATUS_2_RXOF_SHIFT                     3
///< DGL_CFG Bit Fields
#define I2C_DGL_DGL_CNT_MASK                        0xFu
#define I2C_DGL_DGL_CNT_SHIFT                       0
#define I2C_DGL_DGL_CNT(x)                          (((uint32_t)(((uint32_t)(x))<<I2C_DGL_DGL_CNT_SHIFT))&I2C_DGL_DGL_CNT_MASK)
#define I2C_DGL_STARTF_MASK                         0x10u
#define I2C_DGL_STARTF_SHIFT                        4
#define I2C_DGL_SSIE_MASK                           0x20u
#define I2C_DGL_SSIE_SHIFT                          5
#define I2C_DGL_STOPF_MASK                          0x40u
#define I2C_DGL_STOPF_SHIFT                         6
#define I2C_DGL_DGLEN_MASK                          0x80u
#define I2C_DGL_DGLEN_SHIFT                         7
///< DATA Bit Fields
#define I2C_DATA_DATA_MASK                          0xFFu
#define I2C_DATA_DATA_SHIFT                         0
#define I2C_DATA_DATA(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_DATA_DATA_SHIFT))&I2C_DATA_DATA_MASK)
///< START_STOP Bit Fields
#define I2C_START_STOP_START_MASK                   0x1u
#define I2C_START_STOP_START_SHIFT                  0
#define I2C_START_STOP_STOP_MASK                    0x2u
#define I2C_START_STOP_STOP_SHIFT                   1
///< SCL_ADJ Bit Fields
#define I2C_SCL_ADJ_TXEF_MASK                       0x7u
#define I2C_SCL_ADJ_TXEF_SHIFT                      0
#define I2C_SCL_ADJ_RXFF_MASK                       0x8u
#define I2C_SCL_ADJ_RXFF_SHIFT                      3

// I2C - Peripheral instance base addresses
///< Peripheral I2C1 base address
#define I2C1_BASE                                   (0x4000e000u)
///< Peripheral I2C2 base address
#define I2C2_BASE                                   (0x4000f000u)
// Peripheral I2C2 base pointer
///<  Array initializer of I2C peripheral base pointers
#define I2C_BASES                                   { I2C1, I2C2 }
//******************************************************************************
#define I2C_READY_STATUS_TIMEOUT        400000          ///< I2C timeout value

#define I2C_READ                        0x01			///< I2C read
#define I2C_WRITE                       0x0  			///< I2C write
#define I2C_SEND_ACK                    0				///< I2C send ACK
#define I2C_SEND_NACK                   1				///< I2C send NACK

#define I2C_ERROR_NULL                  0x00			///< I2C sucess
#define I2C_ERROR_NO_WAIT_TCF_FLAG      0x01			///< I2C wait TCF overtime
#define I2C_ERROR_NO_WAIT_IICIF_FLAG    0x02			///< I2C wait IICIF overtime
#define I2C_ERROR_NO_GET_ACK            0x04			///< I2C no get ACK
#define I2C_ERROR_START_NO_BUSY_FLAG    0x10			///< I2C fail to send start signals
#define I2C_ERROR_STOP_BUSY_FLAG        0x20			///< I2C fail to send stop signal
#define I2C_ERROR_BUS_BUSY              0x80			///< I2C bus busy error
#define I2C_ERROR_DMA_LENGTH_UNEQUAL    0x100			///< I2C dma transferred length unmatch
#define I2C_ERROR_DMA_MASTER_TIMEOUT    0x200			///< I2C dma master timeout
#define I2C_ERROR_DMA_SLAVE_TIMEOUT     0x400			///< I2C dma slave timeout

typedef struct
{
    uint32_t pointer;               ///< The tail pointer of the transmitted data
    uint32_t length;                ///< send buffer length
    uint8_t *sendBuff;              ///< send buffer pointer
} I2C_MasterSendType;

typedef struct
{
    uint32_t pointer;               ///< The final point to the data that has been receive
    uint32_t length;                ///< receive buffer length
    uint8_t *receiveBuff;           ///< receive buffer pointer
} I2C_MasterReceiveType;

typedef struct
{
    uint32_t head;                  ///< slave receive buffer head pointer
    uint32_t tail;                  ///< slave receive buffer tail pointer
    uint32_t freeLength;            ///< slave receive buffer FreeLength
    uint8_t *receiveBuff;           ///< slave receive buffer pointer
} I2C_SlaveReceiveType;

typedef struct
{
    uint32_t pointer;               ///< The final point to the data that has been receive
    uint32_t length;                ///< receive buffer length
    uint8_t *sendBuff;              ///< receive buffer pointer
} I2C_SlaveSendType;

typedef struct
{
    I2C_Type *I2Cx;                 ///< I2C Base Type pointer
    IRQn_Type I2Cx_IRQn;            ///< I2C IRQ Num
    CLK_MODULE CKGEN_I2Cx;          ///< I2C CKGEN
    SRST_MODULE SRST_I2Cx;          ///< I2C Soft Reset
} I2C_INFO;

typedef struct
{
    DMA_Type* txChannelNum;         ///< I2C TX Channel Num
    DMA_Type* rxChannelNum;         ///< I2C RX Channel Num
    IRQn_Type   txDMAIRQn;          ///< I2C TX Channel IRQ Num
    IRQn_Type   rxDMAIRQn;          ///< I2C RX Channel IRQ Num
} I2C_DMA_INFO;

/******************************************************************************
* I2C API list
*******************************************************************************/

/**
* I2C_Enable
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Enable I2C peripheral
*/
__STATIC_INLINE void I2C_Enable(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_1.IICEN = 1;
}

/**
* I2C_Disable
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Disable I2C peripheral
*/
__STATIC_INLINE void I2C_Disable(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_1.IICEN = 0;
}

/**
* I2C_TxEn
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Change the direction of I2C transmit to send
*/
__STATIC_INLINE void I2C_TxEn(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_1.TX = 1;
}

/**
* I2C_RxEn
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Change the direction of I2C transmit to receive
*/
__STATIC_INLINE void I2C_RxEn(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_1.TX = 0;
}

/**
* I2C_SendAck
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  I2C send ACK signal
*/
__STATIC_INLINE void I2C_SendAck(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_1.TACK = 0;
}

/**
* I2C_SendNack
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  I2C send NACK signal
*/
__STATIC_INLINE void I2C_SendNack(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_1.TACK = 1;
}

/**
* I2C_SetMSTR
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  I2C peripheral act as I2C Master
*/
__STATIC_INLINE void I2C_SetMSTR(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_1.MSTR = 1;
}

/**
* I2C_ClrMSTR
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  I2C peripheral cancel as I2C Master
*/
__STATIC_INLINE void I2C_ClrMSTR(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_1.MSTR = 0;
}

/**
* I2C_WriteDataReg
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] dataBuff: the data write into I2C data register
* @return none
*
* @brief  Write data into I2C DATA register
*/
__STATIC_INLINE void I2C_WriteDataReg(I2C_Type *I2Cx, uint8_t dataBuff)
{
    I2Cx->DATA = dataBuff;
}

/**
* I2C_ReadDataReg
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return the data read out from I2C data register
*
* @brief  Read data from DATA register
*/
__STATIC_INLINE uint8_t I2C_ReadDataReg(I2C_Type *I2Cx)
{
    return (I2Cx->DATA);
}

/**
* I2C_SendStart
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  I2C Master send start signal
*/
__STATIC_INLINE void I2C_SendStart(I2C_Type *I2Cx)
{
    I2Cx->START_STOP.START = 1;
}

/**
* I2C_SendStop
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  I2C Master send stop signal
*/
__STATIC_INLINE void I2C_SendStop(I2C_Type *I2Cx)
{
    I2Cx->START_STOP.STOP = 1;
}

/**
* I2C_IsTx
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return 0: I2C is Rx. 1: I2C is Tx
*
* @brief  get I2C peripheral direction
*/
__STATIC_INLINE uint32_t I2C_IsTx(I2C_Type *I2Cx)
{
    return (I2Cx->CONTROL_1.TX);
}

/**
* I2C_IsBusy
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return 0: bus is idle. 1: bus is busy
*
* @brief  get I2C bus busy status
*/
__STATIC_INLINE uint32_t I2C_IsBusy(I2C_Type *I2Cx)
{
    return (I2Cx->STATUS_1.STATUS_1_Bit.BUSY);
}

/**
* I2C_IsReady
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return 0: HW is not ready. 1: HW is ready
*
* @brief  check whether the I2C module is ready
*/
__STATIC_INLINE uint32_t I2C_IsReady(I2C_Type *I2Cx)
{
    return (I2Cx->STATUS_1.STATUS_1_Bit.READY);
}

/**
* I2C_IsMaster
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return 0: I2C is slave mode. 1: I2C is master mode
*
* @brief  check whether I2C peripheral is master or not
*/
__STATIC_INLINE uint32_t I2C_IsMaster(I2C_Type *I2Cx)
{
    return (I2Cx->CONTROL_1.MSTR);
}


/**
* I2C_IsStop
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return 0: STOP is not detected. 1: STOP is detected
*
* @brief  check whether STOP is detected or not
*/
__STATIC_INLINE uint32_t I2C_IsStop(I2C_Type *I2Cx)
{
    return (I2Cx->DGL_CFG.DGL_CFG_Bit.STOPF);
}

/**
* I2C_IsStart
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return 0: start is not detected. 1: start is detected
*
* @brief  check whether START is detected or not
*/
__STATIC_INLINE uint32_t I2C_IsStart(I2C_Type *I2Cx)
{
    return (I2Cx->DGL_CFG.DGL_CFG_Bit.STARTF);
}

/**
* I2C_GetStatus1
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return status_1 reg value
*
* @brief  get I2C peripheral status_1
*/
__STATIC_INLINE uint32_t I2C_GetStatus1(I2C_Type *I2Cx)
{
    return (I2Cx->STATUS_1.STATUS_1_Byte);
}

/**
* I2C_GetStatus2
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return status_2 reg value
*
* @brief  get I2C peripheral status_2
*/
__STATIC_INLINE uint32_t I2C_GetStatus2(I2C_Type *I2Cx)
{
    return (I2Cx->STATUS_2.STATUS_2_Byte);
}

/**
* I2C_ClrStatus1
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] clearFlag: Flag in the status1 needed to be clear
* @return none
*
* @brief  clear I2C peripheral status_1
*/
__STATIC_INLINE void I2C_ClrStatus1(I2C_Type *I2Cx, uint32_t clearFlag)
{
    I2Cx->STATUS_1.STATUS_1_Byte = clearFlag;
}

/**
* I2C_ClrStatus2
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] clearFlag: Flag in the status2 needed to be clear
* @return none
*
* @brief  clear I2C peripheral status_2
*/
__STATIC_INLINE void I2C_ClrStatus2(I2C_Type *I2Cx, uint32_t clearFlag)
{
    I2Cx->STATUS_2.STATUS_2_Byte = clearFlag;
}

/**
* I2C_SetSlaveAddr
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] slaveAddr: I2C Slave address
* @return none
*
* @brief  config I2C Slave address
*/
__STATIC_INLINE void I2C_SetSlaveAddr(I2C_Type *I2Cx, uint32_t slaveAddr)
{
    I2Cx->ADDR1 = (uint8_t)slaveAddr << 1;
    I2Cx->ADDR2 = (uint8_t)(slaveAddr >> 7) & 0x07;
}

/**
* I2C_SetSampleStep
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] sampleCnt: Sample_CNT,sample_width = (sample_cnt_div +1) * Bus_clk_period
* @param[in] stepCnt: Step_CNT, half_pulse_width = (step_cnt_div +1) * sample_width
* @return none
*
* @brief  config I2C baudrate
*/
__STATIC_INLINE void I2C_SetSampleStep(I2C_Type *I2Cx, uint8_t sampleCnt, uint8_t stepCnt)
{
    I2Cx->SAMPLE_CNT = sampleCnt;
    I2Cx->STEP_CNT = stepCnt;
}

/**
* I2C_EnableInt
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Enable I2C peripheral Interrupt
*/
__STATIC_INLINE void I2C_EnableInt(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_1.IICIE = 1;
}

/**
* I2C_DisableInt
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Disable I2C peripheral Interrupt
*/
__STATIC_INLINE void I2C_DisableInt(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_1.IICIE = 0;
}

/**
* I2C_EnableWakeUp
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Enable I2C Slave wakeup
*/
__STATIC_INLINE void I2C_EnableWakeUp(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_1.WUEN = 1;
}

/**
* I2C_DisableWakeUp
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Disable I2C Slave wakeup
*/
__STATIC_INLINE void I2C_DisableWakeUp(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_1.WUEN = 0;
}

/**
* I2C_EnableSTR
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Enable I2C Slave SCL stretch
*/
__STATIC_INLINE void I2C_EnableSTR(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_2.STREN = 1;
}

/**
* I2C_DisableSTR
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Disable I2C Slave SCL stretch
*/
__STATIC_INLINE void I2C_DisableSTR(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_2.STREN = 0;
}

/**
* I2C_EnableARB
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Enable I2C Master arbitration
*/
__STATIC_INLINE void I2C_EnableARB(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_2.ARBEN = 1;
}

/**
* I2C_DisableARB
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Disable I2C Master arbitration
*/
__STATIC_INLINE void I2C_DisableARB(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_2.ARBEN = 0;
}

/**
* I2C_EnableSync
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Enable I2C Master SCL synchronization
*/
__STATIC_INLINE void I2C_EnableSync(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_2.SYNCEN = 1;
}

/**
* I2C_DisableSync
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Disable I2C Master SCL synchronization
*/
__STATIC_INLINE void I2C_DisableSync(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_2.SYNCEN = 0;
}

/**
* I2C_EnableADEXT
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Enable I2C Slave address extension
*/
__STATIC_INLINE void I2C_EnableADEXT(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_2.ADEXT = 1;
}

/**
* I2C_DisableADEXT
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Disable I2C Slave address extension
*/
__STATIC_INLINE void I2C_DisableADEXT(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_2.ADEXT = 0;
}

/**
* I2C_EnableGCA
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Enable I2C Slave SCL general call
*/
__STATIC_INLINE void I2C_EnableGCA(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_2.GCAEN = 1;
}

/**
* I2C_DisableGCA
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Disable I2C Slave SCL general call
*/
__STATIC_INLINE void I2C_DisableGCA(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_2.GCAEN = 0;
}

/**
* I2C_EnableDMATx
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Enable I2C DMA send
*/
__STATIC_INLINE void I2C_EnableDMATx(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_4.DMATXEN = 1;
}

/**
* I2C_DisableDMATx
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Disable I2C DMA send
*/
__STATIC_INLINE void I2C_DisableDMATx(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_4.DMATXEN = 0;
}

/**
* I2C_EnableDMARx
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Enable I2C DMA receive
*/
__STATIC_INLINE void I2C_EnableDMARx(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_4.DMARXEN = 1;
}

/**
* I2C_DisableDMARx
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Disable I2C DMA receive
*/
__STATIC_INLINE void I2C_DisableDMARx(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_4.DMARXEN = 0;
}

/**
* I2C_IsDMATxEnable
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return 0 : dma tx is disable,1: dma tx is enable
*
* @brief  check whether i2c dma tx is enable
*/
__STATIC_INLINE uint32_t I2C_IsDMATxEnable(I2C_Type *I2Cx)
{
    return (I2Cx->CONTROL_4.DMATXEN);
}

/**
* I2C_IsDMARx_Enable
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return 0 : dma rx is disable,1: dma rx is enable
*
* @brief  check whether i2c dma receive is enable
*/
__STATIC_INLINE uint32_t I2C_IsDMARxEnable(I2C_Type *I2Cx)
{
    return (I2Cx->CONTROL_4.DMARXEN);
}

/**
* I2C_SWRST
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Reset I2C module
*/
__STATIC_INLINE void I2C_SWRST(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_1.SWRST = 1;
}

/**
* I2C_EnableMNT
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Enable I2C slave Monitor
*/
__STATIC_INLINE void I2C_EnableMNT(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_3.MNTEN = 1;
}

/**
* I2C_DisableMNT
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Disable I2C slave Monitor
*/
__STATIC_INLINE void I2C_DisableMNT(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_3.MNTEN = 0;
}

/**
* I2C_ReleaseSTR
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Release I2C slave SCL stretch
*/
__STATIC_INLINE void I2C_ReleaseSTR(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_3.STRRLS = 1;
}

/**
* I2C_EnableTxEInt
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Enable I2C Tx Empty Interrupt
*/
__STATIC_INLINE void I2C_EnableTxEInt(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_3.TXEIE = 1;
}

/**
* I2C_DisableTxEInt
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Disable I2C Tx Empty Interrupt
*/
__STATIC_INLINE void I2C_DisableTxEInt(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_3.TXEIE = 0;
}

/**
* I2C_EnableRxFInt
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Enable I2C Rx Full Interrupt
*/
__STATIC_INLINE void I2C_EnableRxFInt(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_3.RXFIE = 1;
}

/**
* I2C_DisableRxFInt
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Disable I2C Rx Full Interrupt
*/
__STATIC_INLINE void I2C_DisableRxFInt(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_3.RXFIE = 0;
}

/**
* I2C_EnableTxUFInt
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Enable I2C Tx Underflow Interrupt
*/
__STATIC_INLINE void I2C_EnableTxUFInt(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_3.TXUFIE = 1;
}

/**
* I2C_DisableTxUFInt
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Disable I2C Tx Underflow Interrupt
*/
__STATIC_INLINE void I2C_DisableTxUFInt(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_3.TXUFIE = 0;
}

/**
* I2C_EnableRxOFInt
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Enable I2C Rx Overflow Interrupt
*/
__STATIC_INLINE void I2C_EnableRxOFInt(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_3.RXOFIE = 1;
}

/**
* I2C_DisableRxOFInt
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Disable I2C Rx Overflow Interrupt
*/
__STATIC_INLINE void I2C_DisableRxOFInt(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_3.RXOFIE = 0;
}

/**
* I2C_EnableNackInt
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Enable I2C NACK Interrupt
*/
__STATIC_INLINE void I2C_EnableNackInt(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_3.NACKIE = 1;
}

/**
* I2C_DisableNackInt
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Disable I2C NACK Interrupt
*/
__STATIC_INLINE void I2C_DisableNackInt(I2C_Type *I2Cx)
{
    I2Cx->CONTROL_3.NACKIE = 0;
}

/**
* I2C_ClearStartFlag
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Clear I2C Start flag
*/
__STATIC_INLINE void I2C_ClearStartFlag(I2C_Type *I2Cx)
{
    uint32_t tmpDGLConfig = 0;

    tmpDGLConfig = I2Cx->DGL_CFG.DGL_CFG_Byte;
    tmpDGLConfig &= ~I2C_DGL_STOPF_MASK;          // Make sure write 0 into STOP Flag bit
    tmpDGLConfig |= I2C_DGL_STARTF_MASK;          // Write 1 to clear
    I2Cx->DGL_CFG.DGL_CFG_Byte = tmpDGLConfig;
}

/**
* I2C_ClearStopFlag
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Clear I2C Stop flag
*/
__STATIC_INLINE void I2C_ClearStopFlag(I2C_Type *I2Cx)
{
    uint32_t tmpDGLConfig = 0;

    tmpDGLConfig = I2Cx->DGL_CFG.DGL_CFG_Byte;
    tmpDGLConfig &= ~I2C_DGL_STARTF_MASK ;        // Make sure write 0 into START Flag bit
    tmpDGLConfig |= I2C_DGL_STOPF_MASK;           // Write 1 to clear
    I2Cx->DGL_CFG.DGL_CFG_Byte = tmpDGLConfig;
}

/**
* I2C_EnableSSInt
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Enable I2C Start & Stop Interrupt
*/
__STATIC_INLINE void I2C_EnableSSInt(I2C_Type *I2Cx)
{
    uint32_t tmpDGLConfig = 0;

    tmpDGLConfig = I2Cx->DGL_CFG.DGL_CFG_Byte;
    tmpDGLConfig &= ~I2C_DGL_STARTF_MASK ;        // Make sure write 0 into START Flag bit
    tmpDGLConfig &= ~I2C_DGL_STOPF_MASK;          // Make sure write 0 into STOP Flag bit
    tmpDGLConfig |= I2C_DGL_SSIE_MASK;            // Write 1 to set
    I2Cx->DGL_CFG.DGL_CFG_Byte = tmpDGLConfig;
}

/**
* I2C_DisableSSInt
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Disable I2C Start & Stop Interrupt
*/
__STATIC_INLINE void I2C_DisableSSInt(I2C_Type *I2Cx)
{
    uint32_t tmpDGLConfig = 0;

    tmpDGLConfig = I2Cx->DGL_CFG.DGL_CFG_Byte;
    tmpDGLConfig &= ~I2C_DGL_STARTF_MASK ;        // Make sure write 0 into START Flag bit
    tmpDGLConfig &= ~I2C_DGL_STOPF_MASK;          // Make sure write 0 into STOP Flag bit
    tmpDGLConfig &= ~I2C_DGL_SSIE_MASK;           // Write 0 to clear
    I2Cx->DGL_CFG.DGL_CFG_Byte = tmpDGLConfig;
}

/**
* I2C_EnableDGL
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Enable I2C DGL
*/
__STATIC_INLINE void I2C_EnableDGL(I2C_Type *I2Cx)
{
    uint32_t tmpDGLConfig = 0;

    tmpDGLConfig = I2Cx->DGL_CFG.DGL_CFG_Byte;
    tmpDGLConfig &= ~I2C_DGL_STARTF_MASK ;        // Make sure write 0 into START Flag bit
    tmpDGLConfig &= ~I2C_DGL_STOPF_MASK;          // Make sure write 0 into STOP Flag bit
    tmpDGLConfig |= I2C_DGL_DGLEN_MASK;           // Write 1 to set
    I2Cx->DGL_CFG.DGL_CFG_Byte = tmpDGLConfig;
}

/**
* I2C_DisableDGL
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return none
*
* @brief  Disable I2C DGL
*/
__STATIC_INLINE void I2C_DisableDGL(I2C_Type *I2Cx)
{
    uint32_t tmpDglitchConfig = 0;

    tmpDglitchConfig = I2Cx->DGL_CFG.DGL_CFG_Byte;
    tmpDglitchConfig &= ~I2C_DGL_STARTF_MASK ;        // Make sure write 0 into START Flag bit
    tmpDglitchConfig &= ~I2C_DGL_STOPF_MASK;          // Make sure write 0 into STOP Flag bit
    tmpDglitchConfig &= ~I2C_DGL_DGLEN_MASK;          // Write 0 to clear
    I2Cx->DGL_CFG.DGL_CFG_Byte = tmpDglitchConfig;
}

/**
* I2C_SetDGLCnt
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] DGLCnt: DGL_CNT value
* @return none
*
* @brief  config I2C DGL Cnt
*/
__STATIC_INLINE void I2C_SetDGLCnt(I2C_Type *I2Cx, uint32_t DGLCnt)
{
    uint32_t tmpDglitchConfig = 0;

    tmpDglitchConfig = I2Cx->DGL_CFG.DGL_CFG_Byte;
    tmpDglitchConfig &= ~I2C_DGL_STARTF_MASK ;        // Make sure write 0 into START Flag bit
    tmpDglitchConfig &= ~I2C_DGL_STOPF_MASK;          // Make sure write 0 into STOP Flag bit
    tmpDglitchConfig &= ~I2C_DGL_DGL_CNT_MASK;        // Clear DGL_CNT first
    tmpDglitchConfig |= (DGLCnt & 0xF);
    I2Cx->DGL_CFG.DGL_CFG_Byte = tmpDglitchConfig;
}

/******************************************************************************
* Global functions
******************************************************************************/
void I2C_Enable(I2C_Type *I2Cx);
void I2C_Disable(I2C_Type *I2Cx);
void I2C_TxEn(I2C_Type *I2Cx);
void I2C_RxEn(I2C_Type *I2Cx);
void I2C_SendAck(I2C_Type *I2Cx);
void I2C_SendNack(I2C_Type *I2Cx);
void I2C_SetMSTR(I2C_Type *I2Cx);
void I2C_ClrMSTR(I2C_Type *I2Cx);
void I2C_WriteDataReg(I2C_Type *I2Cx, uint8_t dataBuff);
uint8_t I2C_ReadDataReg(I2C_Type *I2Cx);
void I2C_SendStart(I2C_Type *I2Cx);
void I2C_SendStop(I2C_Type *I2Cx);
uint32_t I2C_IsTx(I2C_Type *I2Cx);
uint32_t I2C_IsBusy(I2C_Type *I2Cx);
uint32_t I2C_IsReady(I2C_Type *I2Cx);
uint32_t I2C_IsMaster(I2C_Type *I2Cx);
uint32_t I2C_IsStop(I2C_Type *I2Cx);
uint32_t I2C_IsStart(I2C_Type *I2Cx);
uint32_t I2C_GetStatus1(I2C_Type *I2Cx);
uint32_t I2C_GetStatus2(I2C_Type *I2Cx);
void I2C_ClrStatus1(I2C_Type *I2Cx, uint32_t clearFlag);
void I2C_ClrStatus2(I2C_Type *I2Cx, uint32_t clearFlag);
void I2C_SetSlaveAddr(I2C_Type *I2Cx, uint32_t slaveAddr);
void I2C_SetSampleStep(I2C_Type *I2Cx, uint8_t sampleCnt, uint8_t stepCnt);
void I2C_EnableInt(I2C_Type *I2Cx);
void I2C_DisableInt(I2C_Type *I2Cx);
void I2C_EnableTxEInt(I2C_Type *I2Cx);
void I2C_DisableTxEInt(I2C_Type *I2Cx);
void I2C_EnableRxFInt(I2C_Type *I2Cx);
void I2C_DisableRxFInt(I2C_Type *I2Cx);
void I2C_EnableTxUFInt(I2C_Type *I2Cx);
void I2C_DisableTxUFInt(I2C_Type *I2Cx);
void I2C_EnableRxOFInt(I2C_Type *I2Cx);
void I2C_DisableRxOFInt(I2C_Type *I2Cx);
void I2C_EnableWakeUp(I2C_Type *I2Cx);
void I2C_DisableWakeUp(I2C_Type *I2Cx);
void I2C_EnableSTR(I2C_Type *I2Cx);
void I2C_DisableSTR(I2C_Type *I2Cx);
void I2C_EnableARB(I2C_Type *I2Cx);
void I2C_DisableARB(I2C_Type *I2Cx);
void I2C_EnableSync(I2C_Type *I2Cx);
void I2C_DisableSync(I2C_Type *I2Cx);
void I2C_EnableADEXT(I2C_Type *I2Cx);
void I2C_DisableADEXT(I2C_Type *I2Cx);
void I2C_EnableGCA(I2C_Type *I2Cx);
void I2C_DisableGCA(I2C_Type *I2Cx);
void I2C_EnableDMATx(I2C_Type *I2Cx);
void I2C_DisableDMATx(I2C_Type *I2Cx);
void I2C_EnableDMARx(I2C_Type *I2Cx);
void I2C_DisableDMARx(I2C_Type *I2Cx);
uint32_t I2C_IsDMARxEnable(I2C_Type *I2Cx);
uint32_t I2C_IsDMATxEnable(I2C_Type *I2Cx);
void I2C_SWRST(I2C_Type *I2Cx);
void I2C_EnableNackInt(I2C_Type *I2Cx);
void I2C_DisableNackInt(I2C_Type *I2Cx);
void I2C_EnableMNT(I2C_Type *I2Cx);
void I2C_DisableMNT(I2C_Type *I2Cx);
void I2C_ReleaseSTR(I2C_Type *I2Cx);
void I2C_ClearStartF(I2C_Type *I2Cx);
void I2C_ClearStopF(I2C_Type *I2Cx);
void I2C_EnableSSInt(I2C_Type *I2Cx);
void I2C_DisableSSInt(I2C_Type *I2Cx);
void I2C_EnableDGL(I2C_Type *I2Cx);
void I2C_DisableDGL(I2C_Type *I2Cx);
void I2C_SetDGLCnt(I2C_Type *I2Cx, uint32_t DGLCnt);
//***************************************************************
uint8_t I2C_Start(I2C_Type *I2Cx);
uint8_t I2C_Stop(I2C_Type *I2Cx);
uint8_t I2C_Restart(I2C_Type *I2Cx);
uint8_t I2C_WriteOneByte(I2C_Type *I2Cx, uint8_t wrBuff);
uint8_t I2C_ReadOneByte(I2C_Type *I2Cx, uint8_t *rdBuff, uint8_t nack);
uint8_t I2C_ReadLastOneByte(I2C_Type *I2Cx, uint8_t *rdBuff, uint8_t nack);
void I2C1_IRQHandler(void);
void I2C2_IRQHandler(void);

void I2C_MasterIntHandler(I2C_Type *I2Cx, uint32_t wparam, uint32_t lparam);
void I2C_SlaveIntHandler(I2C_Type *I2Cx, uint32_t wparam, uint32_t lparam);
void I2C_MasterDMAHandler(I2C_Type *I2Cx, uint32_t wparam, uint32_t lparam);
void I2C_SlaveDMAHandler(I2C_Type *I2Cx, uint32_t wparam, uint32_t lparam);

#ifdef __cplusplus
}
#endif

#endif
