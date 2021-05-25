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

#ifndef AC78XX_DMA_H
#define AC78XX_DMA_H
#ifdef __cplusplus
extern "C" {
#endif

#include "ac78xx_dma_reg.h"

#define DMA1                                     ((DMA_Type *)DMA1_BASE)
#define DMA2                                     ((DMA_Type *)DMA2_BASE)
#define DMA3                                     ((DMA_Type *)DMA3_BASE)
#define DMA4                                     ((DMA_Type *)DMA4_BASE)
#define DMA5                                     ((DMA_Type *)DMA5_BASE)
#define DMA6                                     ((DMA_Type *)DMA6_BASE)
#define DMA7                                     ((DMA_Type *)DMA7_BASE)
#define DMA8                                     ((DMA_Type *)DMA8_BASE)
#define DMA9                                     ((DMA_Type *)DMA9_BASE)
#define DMA10                                    ((DMA_Type *)DMA10_BASE)
#define DMA11                                    ((DMA_Type *)DMA11_BASE)
#define DMA12                                    ((DMA_Type *)DMA12_BASE)

/* CHANNELx_STATUS Bit Fields */
#define DMA_CHANNELX_STATUS_FINISH_MASK             0x1u
#define DMA_CHANNELX_STATUS_FINISH_SHIFT            0
#define DMA_CHANNELX_STATUS_HALF_FINISH_MASK        0x2u
#define DMA_CHANNELX_STATUS_HALF_FINISH_SHIFT       1
#define DMA_CHANNELX_STATUS_TRANS_ERROR_MASK        0x4u
#define DMA_CHANNELX_STATUS_TRANS_ERROR_SHIFT       2

//Callback function can get DMA channel's status(Finish, Half Finish and Error Flags) by parameter "wparam"
typedef int32_t (*DMA_EventCallback)(DMA_Type *DMAx, uint32_t wparam, uint32_t lparam);

typedef struct
{
    uint32_t finishIntEn                : 1;    ///< 1:enable finish interrupt
    uint32_t halfFinishIntEn            : 1;    ///< 1:enable half finish interrupt
    uint32_t errorIntEn                 : 1;    ///< 1:enable error interrupt
    uint32_t channelEn                  : 1;    ///< 1:enable DMA channel
    uint32_t MEM2MEM                    : 1;    ///< 0:DMA mode between memory and peripheral device; 1: DMA mode between memory and memory
    uint32_t channelPriority            : 2;    ///< 0:low; 1:medium; 2:high; 3: very high
    uint32_t memSize                    : 2;    ///< 2:32-bit, right now only support 32-bit
    uint32_t periphSize                 : 2;    ///< 0:8-bit; 1:16-bit; 2:32-bit; 3:reserved, if PERIPH_INCREMENT is fixed, it will be 32-bit
    uint32_t memIncrement               : 1;    ///< 0:MEM address is fixed; 1: MEM address increment
    uint32_t periphIncrement            : 1;    ///< 0:Peripheral address is fixed; 1: Peripheral address increment
    uint32_t circular                   : 1;    ///< 1:enable circular mode
    uint32_t direction                  : 1;    ///< 0:Write to memory; 1: Write to peripheral device
    uint32_t memByteMode                : 2;    ///< 0:32-bit; 1:16-bit[15:0]; 2:16-bit[23:16],[7:0]; 3:8-bit
    uint32_t transferNum                : 15;   ///< transfer total numbers
}DMA_SettingType;

typedef struct
{
    DMA_SettingType setting;                    ///< DMA setting parameter
    uint32_t memStartAddr;                      ///< memory start address
    uint32_t memEndAddr;                        ///< memory end address
    uint32_t periphStartAddr;                   ///< peripheral address in memory
}DMA_ConfigType, *DMA_ConfigPtr;

void DMA_Initialize(DMA_Type *DMAx, DMA_ConfigType *config);
void DMA_Uninitialize(DMA_Type *DMAx);

void DMA_EnableChannel(DMA_Type *DMAx);
void DMA_DisableChannel(DMA_Type *DMAx);

uint32_t DMA_GetTransmissionLength(DMA_Type *DMAx);
uint32_t DMA_GetTransferedDataNum(DMA_Type *DMAx);
void DMA_SetEventCallback(const DMA_Type *DMAx, const DMA_EventCallback callback);

// For DMA timeout condition, use DMA_ChannelFlush to get the data left in the internal FIFO
uint32_t DMA_GetInterFIFODataLeftNum(DMA_Type *DMAx);
void DMA_ChannelFlush(DMA_Type *DMAx);


#ifdef __cplusplus
}
#endif

#endif
