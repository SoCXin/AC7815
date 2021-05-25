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

#ifndef __AC78XX_SPI_H
#define __AC78XX_SPI_H
#ifdef __cplusplus
extern "C" {
#endif

#include "ac78xx_spi_reg.h"

#define SPI_INT_USE_CALLBACK                   ///< SPI Interrupt Handle Use Callback or Not

#define SPI1                                     ((SPI_Type *)SPI1_BASE)
#define SPI2                                     ((SPI_Type *)SPI2_BASE)

#define SPI_STATUS_IDLE           0x00
#define SPI_STATUS_RX_OVERFLOW    0x01
#define SPI_STATUS_TX_UNDERFLOW   0x02
#define SPI_STATUS_BUSY           0x80

typedef int32_t (*SPI_EventCallBack)(SPI_Type *SPIx,uint32_t wparam, uint32_t lparam );

///< refer to spi register map(spec)
typedef struct
{
    uint32_t csIdle                     :8;        ///< CS Idle Time
    uint32_t txEmptyIntEn               :1;
    uint32_t rxFullIntEn                :1;
    uint32_t txUnderflowIntEn           :1;
    uint32_t rxOverflowIntEn            :1;
    uint32_t master                     :1;        ///< 1:Master 0:Slave
    uint32_t modeErrorIntEn             :1;
    uint32_t dmaTxEn                    :1;
    uint32_t dmaRxEn                    :1;
    uint32_t cpol                       :1;
    uint32_t cpha                       :1;
    uint32_t txMsbFirst                 :1;        ///< TX MSB First
    uint32_t rxMsbFirst                 :1;        ///< RX MSB First
    uint32_t frmSize                    :4;
    uint32_t csOutputEn                 :1;        ///< CS Hardware Output Enable
    uint32_t modeFaultEn                :1;
    uint32_t continuousCSEn             :1;	       ///< CS Continuous Output Enable
    uint32_t wakeUpEn                   :1;
    uint32_t spiEn                      :1;
    uint32_t swReset                    :1;
    uint32_t intEn                      :1;
    uint32_t                            :1;
}SPI_SettingType;

///< refer to SPI configuration register 0
typedef struct
{
    SPI_SettingType setting;
    uint8_t sckHigh;
    uint8_t sckLow;
    uint8_t csHold;
    uint8_t csSetup;
} SPI_ConfigType, *SPI_ConfigPtr;

extern uint16_t g_spiRxBuffWrPointer[2];
extern uint16_t g_spiTxBuffRdPointer[2];
extern uint32_t g_spiBuffSize[2];
extern const SPI_INFO g_spiInfoPool[];
extern uint32_t g_spiStatus[];
extern uint16_t *g_spiRxBuf[];
extern uint16_t *g_spiTxBuf[];

int32_t SPI_Initialize(SPI_Type *SPIx, SPI_ConfigType *config);
int32_t SPI_Uninitialize(SPI_Type *SPIx);

int32_t SPI_WriteInt(SPI_Type *SPIx, uint16_t * wrBuff,uint32_t length);
int32_t SPI_ReadInt(SPI_Type *SPIx, uint16_t* rdBuff,uint32_t length);

int32_t SPI_WritePoll(SPI_Type *SPIx, uint16_t *wrBuff,uint32_t length);
int32_t SPI_ReadPoll(SPI_Type *SPIx, uint16_t *rdBuff,uint32_t length);
int32_t SPI_ReadPollInRxOnlyMode(SPI_Type *SPIx, uint16_t *rdBuff,uint32_t length);

int32_t SPI_TransferInt(SPI_Type *SPIx, uint16_t* rdBuff, uint16_t * wrBuff,uint32_t length);
int32_t SPI_CheckTransferIntStatus(SPI_Type *SPIx);
int32_t SPI_TransferPoll(SPI_Type *SPIx, uint16_t *rdBuff, uint16_t *wrBuff,uint32_t length);
int32_t SPI_MasterReleaseCS(SPI_Type *SPIx);


int32_t SPI_GetTransferStatus( SPI_Type *SPIx );
int32_t SPI_ResetTransferStatus( SPI_Type *SPIx );

///< Callback function settings for SPI Interrupt
int32_t SPI_Callback(SPI_Type *SPIx, uint32_t wparam, uint32_t lparam);
#ifdef SPI_INT_USE_CALLBACK
int32_t SPI_SetEventCallback(SPI_Type *SPIx,SPI_EventCallBack callback);
#endif
int32_t SPI_InitCallback(SPI_Type *SPIx);
int32_t SPI_RxOnlyModeInt(SPI_Type *SPIx, uint16_t* rdBuff, uint16_t * wrBuff, uint32_t length);



#ifdef __cplusplus
}
#endif

#endif
