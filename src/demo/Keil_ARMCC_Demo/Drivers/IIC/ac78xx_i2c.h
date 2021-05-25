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

#ifndef _AC78XX_I2C_H_
#define _AC78XX_I2C_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "ac78xx_i2c_reg.h"

#define I2C1                            ((I2C_Type *)I2C1_BASE)
#define I2C2                            ((I2C_Type *)I2C2_BASE)

#define I2C_STATUS_IDLE                 0x00      
#define I2C_STATUS_TX_FINISH            0x01
#define I2C_STATUS_RX_FINISH            0x02
#define I2C_STATUS_NACK                 0x04
#define I2C_STATUS_STOP                 0x08
#define I2C_STATUS_DMA_TX_FINISH        0x10
#define I2C_STATUS_DMA_RX_FINISH        0x20

extern const I2C_INFO g_i2cInfoPool[];
extern const I2C_DMA_INFO g_i2cDMAChannel[];

typedef int32_t (*I2C_EventCallback)(I2C_Type *I2Cx, uint32_t wparam, uint32_t lparam);
typedef struct
{
    uint32_t i2cEn          : 1;     			///< 1: enable I2C module
    uint32_t intEn          : 1;    			///< 1: enable I2C interrupt, need to be enabled if use other interrupts 
    uint32_t master         : 1;    			///< 1: set I2C as Master; 0:set I2C as Slave 
    uint32_t wakeUpEn       : 1;     			///< 1: enable I2C wake up 
    uint32_t swRst          : 1;     			///< I2C SW/HW reset
    uint32_t gcaEn          : 1;     			///< 1: enable I2C Slave general call address 
    uint32_t addressExt     : 1;     			///< 1: enable I2C Slave extertion address selection 
    uint32_t syncEn         : 1;     			///< 1: enable SCL Sync 
    uint32_t arbEn          : 1;     			///< 1: enable Master arbitration(need to enable SCL sync first) 
    uint32_t strEn          : 1;     			///< 1: enable Slave SCL stretch 
    uint32_t mntEn          : 1;    			///< 1: enable Slave monitor 
    uint32_t mntIE          : 1;                ///< 1: enable monitor interrupt 
    uint32_t dmaRxEn        : 1;				///< 1: enable I2C DMA Rx 
    uint32_t dmaTxEn        : 1;				///< 1: enable I2C DMA Tx 
    uint32_t SSIE           : 1;				///< 1: enable I2C Start Stop Interrupt 
    uint32_t rxOFIntEn      : 1;    			///< 1: enable I2C Rx overflow interrupt 
    uint32_t txUFIntEn      : 1;    			///< 1: enable I2C Tx underflow interrupt 
    uint32_t nackIntEn      : 1;    			///< 1: enable I2C NACK interrupt 
    uint32_t                : 14;               ///< Reserved 
} I2C_SettingType;

typedef struct
{
    I2C_SettingType setting;
    uint32_t addr1;             ///< slave address 
    uint32_t sampleCNT;         ///< sample_width = (sampleCNT + 1)*Bus_clk_period 
    uint32_t stepCNT;           ///< half_baud_width = (stepCNT + 1)*sample_width 
    uint32_t sclAdj;            ///< SCL low/high adjust

} I2C_ConfigType, *I2C_ConfigPtr;

extern I2C_MasterSendType g_i2cMasterSendInfo[];
extern I2C_MasterReceiveType g_i2cMasterReceiveInfo[];
extern I2C_SlaveSendType g_i2cSlaveSendInfo[];
extern I2C_SlaveReceiveType g_i2cSlaveReceiveInfo[];
extern uint32_t g_i2cStatus[];
///< For I2C interrupt 
extern uint32_t g_i2cMasterSendBufferLength;
extern uint32_t g_i2cMasterReceiveBufferLength;
extern uint32_t g_i2cSlaveSendBufferLength;
extern uint32_t g_i2cSlaveReceiveBufferLength;

///< Initialization of I2C module by configure I2C_ConfigType struct 
int32_t I2C_Initialize(I2C_Type *I2Cx, I2C_ConfigType *config);
int32_t I2C_Uninitialize(I2C_Type *I2Cx);

///< Master operations for 7-bit address by polling 
int32_t I2C_MasterWrite(I2C_Type *I2Cx, uint32_t slaveAddress, uint8_t *wrBuff, uint32_t dataLength);
int32_t I2C_MasterRead(I2C_Type *I2Cx, uint32_t slaveAddress, uint8_t *rdBuff, uint32_t dataLength);

///< Master operations for 7-bit address by interrupt 
int32_t I2C_MasterWriteInt(I2C_Type *I2Cx, uint32_t slaveAddress, uint8_t *wrBuff, uint32_t dataLength);
int32_t I2C_MasterReadInt(I2C_Type *I2Cx, uint32_t slaveAddress, uint8_t *rdBuff, uint32_t dataLength);
int32_t I2C_MasterCheckReadLength(I2C_Type *I2Cx, uint8_t *rdBuff);

///< Master operations for 10-bit address by polling
int32_t I2C_MasterWriteExt(I2C_Type *I2Cx, uint32_t slaveAddress, uint8_t *wrBuff, uint32_t dataLength);
int32_t I2C_MasterReadExt(I2C_Type *I2Cx, uint32_t slaveAddress, uint8_t *rdBuff, uint32_t dataLength);

///< Slave operations by interrupt
int32_t I2C_SlaveWrite(I2C_Type *I2Cx, uint8_t *wrBuff, uint32_t length);
int32_t I2C_SlaveRead(I2C_Type *I2Cx, uint8_t *rdBuff, uint32_t *length);
///< Get I2C interrupt transfer status
int32_t I2C_GetTransferStatus( I2C_Type *I2Cx );
int32_t I2C_ResetTransferStatus( I2C_Type *I2Cx );

///< Callback function settings for I2C Interrupt
int32_t I2C_Callback(I2C_Type *I2Cx, uint32_t wparam, uint32_t lparam);
int32_t I2C_DMACallback(I2C_Type *I2Cx, uint32_t wparam, uint32_t lparam);
int32_t I2C_SetEventCallback(I2C_Type *I2Cx, I2C_EventCallback callback );
int32_t I2C_InitCallback(I2C_Type *I2Cx, uint8_t * wrBuff, uint8_t *rdBuff, uint32_t buffSize); /*wrBuff and rdBuff are local buffer for I2C interrupt */

///< Master DMA operations for DMA by polling 
int32_t I2C_MasterWriteDMA(I2C_Type *I2Cx, uint32_t slaveAddress, uint32_t dataLength);
int32_t I2C_MasterReadDMA(I2C_Type *I2Cx, uint32_t slaveAddress, uint32_t dataLength);

#ifdef __cplusplus
}
#endif

#endif
