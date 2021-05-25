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

#include "ac78xx_dma.h"
#include "ac78xx.h"

#define DMA_NUM 13    ///< Total number of DMA channels,DMA 0 is the top of the other 12

DMA_EventCallback g_dmaCallbackArray[DMA_NUM] = {(DMA_EventCallback)NULL};

typedef struct
{
    DMA_Type*    channelNum;    ///< DMA channel number
    IRQn_Type    dmaIRQn;       ///< DMA IRQ number
}DMA_INFO;

const DMA_INFO g_dmaChannel[] =
{
    {DMA1,  DMA1_IRQn},  //DMA1
    {DMA2,  DMA2_IRQn},  //DMA2
    {DMA3,  DMA3_IRQn},  //DMA3
    {DMA4,  DMA4_IRQn},  //DMA4
    {DMA5,  DMA5_IRQn},  //DMA5
    {DMA6,  DMA6_IRQn},  //DMA6
    {DMA7,  DMA7_IRQn},  //DMA7
    {DMA8,  DMA8_IRQn},  //DMA8
    {DMA9,  DMA9_IRQn},  //DMA9
    {DMA10, DMA10_IRQn}, //DMA10
    {DMA11, DMA11_IRQn}, //DMA11
    {DMA12, DMA12_IRQn}, //DMA12
};

 /**
 * DMA_Initialize
 *
 * @param[in] DMAx:DMA type pointer
 * @param[in] config:DMA config type pointer
 * @return    none
 *
 * @brief  Initialize DMA channel
 */
void DMA_Initialize(DMA_Type *DMAx, DMA_ConfigType *config)
{
    uint8_t  dmaIndex = ((uint32_t)DMAx-(uint32_t)DMA0)>>6; /* dmaIndex in range[1:12] */

    CKGEN_Enable(CLK_DMA_AHB,1);        /* Enable DMA AHB clock */
    CKGEN_Enable(CLK_DMA_APB,1);        /* Enable DMA APB clock */
    CKGEN_SoftReset(SRST_DMA_AHB,1);    /* Inactive DMA_AHB reset */
    CKGEN_SoftReset(SRST_DMA_APB,1);    /* Inactive DMA_APB reset */

    DMA_ChannelHardRst(g_dmaChannel[dmaIndex - 1].channelNum);   /* Reset DMA channel */
    DMA_ChannelMemStartAddr(DMAx, config->memStartAddr);
    DMA_ChannelMemEndAddr(DMAx, config->memEndAddr);
    DMA_ChannelPeriphAddr(DMAx, config->periphStartAddr);
    if (config->setting.finishIntEn)
    {
        NVIC_EnableIRQ(g_dmaChannel[dmaIndex - 1].dmaIRQn);
        DMA_EnableFinishInt(DMAx);
    }
    if (config->setting.halfFinishIntEn)
    {
        NVIC_EnableIRQ(g_dmaChannel[dmaIndex - 1].dmaIRQn);
        DMA_EnableHalfFinishInt(DMAx);
    }
    if (config->setting.errorIntEn)
    {
        NVIC_EnableIRQ(g_dmaChannel[dmaIndex - 1].dmaIRQn);
        DMA_EnableTransferErrorInt(DMAx);
    }
    DMA_ChannelPriority(DMAx, config->setting.channelPriority);
    DMA_ChannelCircular(DMAx, config->setting.circular);
    DMA_ChannelDir(DMAx, config->setting.direction);
    DMA_ChannelM2M(DMAx, config->setting.MEM2MEM);
    DMA_ChannelMemByteMode(DMAx, config->setting.memByteMode);
    DMA_ChannelMemIncrement(DMAx, config->setting.memIncrement);
    DMA_ChannelPeriphIncrement(DMAx, config->setting.periphIncrement);
    DMA_ChannelMemSize(DMAx, config->setting.memSize);
    DMA_ChannelPeriphSize(DMAx, config->setting.periphSize);
    DMA_ChannelSetLength(DMAx, config->setting.transferNum);
    if (config->setting.channelEn)
    {
        DMA_EnableChannel(DMAx);
    }
}

 /**
 * DMA_Uninitialize
 *
 * @param[in] DMAx:DMA type pointer
 * @return    none
 *
 * @brief  Uninitialize DMA channel
 */
void DMA_Uninitialize(DMA_Type *DMAx)
{
    uint8_t  dmaIndex = ((uint32_t)DMAx-(uint32_t)DMA0)>>6; /* dmaIndex in range[1:12] */

    NVIC_DisableIRQ(g_dmaChannel[dmaIndex - 1].dmaIRQn);
    DMA_ChannelHardRst(g_dmaChannel[dmaIndex - 1].channelNum);
}

/**
 * DMA_GetTransmissionLength
 *
 * @param[in] DMAx:DMA type pointer
 *
 * @return    DMA channel transfer length
 *
 * @brief  Get DMA channel transmission length
 */
uint32_t DMA_GetTransmissionLength(DMA_Type *DMAx)
{
    return (DMAx->CHANNELx_CHAN_LENGTH.CHAN_LENGTH);
}

/**
 * DMA_GetTransferedDataNum
 *
 * @param[in] DMAx:DMA type pointer
 *
 * @return    DMA channel transfered num
 *
 * @brief  Get DMA channel transfered data num
 */
uint32_t DMA_GetTransferedDataNum(DMA_Type *DMAx)
{
    return (DMAx->CHANNELx_DATA_TRANS_NUM.DATA_TRANS_NUM);
}

/**
 * DMA_EnableChannel
 *
 * @param[in] DMAx:DMA type pointer
 *
 * @return    none
 *
 * @brief  Enable DMA channel
 */
void DMA_EnableChannel(DMA_Type *DMAx)
{
    DMAx->CHANNELx_CHAN_ENABLE.CHAN_ENABLE = 1;
}

/**
 * DMA_DisableChannel
 *
 * @param[in] DMAx:DMA type pointer
 *
 * @return    none
 *
 * @brief  Disable DMA channel
 */
void DMA_DisableChannel(DMA_Type *DMAx)
{
    DMAx->CHANNELx_CHAN_ENABLE.CHAN_ENABLE = 0;
}

/**
 * DMA_SetEventCallback
 *
 * @param[in] DMAx:DMA type pointer
 * @param[in] callback:DMA_EventCallBack
 * @return    none
 *
 * @brief  set DAM event callback function
 */
void DMA_SetEventCallback(const DMA_Type *DMAx, const DMA_EventCallback callback )
{
    uint8_t  dmaIndex = ((uint32_t)DMAx-(uint32_t)DMA0)>>6;

    g_dmaCallbackArray[dmaIndex] = callback;
}

/**
 * DMA_ChannelFlush
 *
 * @param[in] DMAx:DMA type pointer
 * @return    none
 *
 * @brief  Flush DMA channel data
 */
void DMA_ChannelFlush(DMA_Type *DMAx)
{
    DMAx->CHANNELx_RST.FLUSH = 1;
}

/**
 * DMA_GetInterFIFODataLeftNum
 *
 * @param[in] DMAx:DMA type pointer
 * @return    left data number
 *
 * @brief  Get the number of the data left in the DMA channel's internal FIFO
 */
uint32_t DMA_GetInterFIFODataLeftNum(DMA_Type *DMAx)
{
    return (DMAx->CHANNELx_INTER_FIFO_DATA_LEFT_NUM.INTER_FIFO_DATA_LEFT_NUM);
}

/**
 * DMA_ClearFlag
 *
 * @param[in] DMAx:DMA type pointer
 * @return    DMA channel's interrupt flags
 *
 * @brief clear DMA Finish, Half Finish and Error Flags
 */
int32_t DMA_ClearFlag(DMA_Type *DMAx)
{
    uint32_t tmpDMAStatus = DMAx->CHANNELx_STATUS.CHANNELx_STATUS_Byte;

    if (tmpDMAStatus & DMA_CHANNELX_STATUS_TRANS_ERROR_MASK)
    {
        DMA_ChannelHardRst(DMAx);                                    /* When AHB error, reset DMA channel */
    }
    DMAx->CHANNELx_STATUS.CHANNELx_STATUS_Byte &= ~tmpDMAStatus;     /* Write 0 to clear */

    return tmpDMAStatus;
}

/**
 * DMA1_IRQHandler
 *
 * @param[in] none
 * @return    none
 *
* @brief  CallBack the DMA1 Interrupt Handler
 */
void DMA1_IRQHandler(void)
{
    uint32_t dmaChannelStatus = DMA_ClearFlag(DMA1);

    if (g_dmaCallbackArray[1])
    {
        g_dmaCallbackArray[1](DMA1, dmaChannelStatus, 0);
    }
}

/**
 * DMA2_IRQHandler
 *
 * @param[in] none
 * @return    none
 *
* @brief  CallBack the DMA2 Interrupt Handler
 */
void DMA2_IRQHandler(void)
{
    uint32_t dmaChannelStatus = DMA_ClearFlag(DMA2);

    if (g_dmaCallbackArray[2])
    {
        g_dmaCallbackArray[2](DMA2, dmaChannelStatus, 0);
    }
}

/**
 * DMA3_IRQHandler
 *
 * @param[in] none
 * @return    none
 *
* @brief  CallBack the DMA3 Interrupt Handler
 */
void DMA3_IRQHandler(void)
{
    uint32_t dmaChannelStatus = DMA_ClearFlag(DMA3);

    if (g_dmaCallbackArray[3])
    {
        g_dmaCallbackArray[3](DMA3, dmaChannelStatus, 0);
    }
}

/**
 * DMA4_IRQHandler
 *
 * @param[in] none
 * @return    none
 *
* @brief  CallBack the DMA4 Interrupt Handler
 */
void DMA4_IRQHandler(void)
{
    uint32_t dmaChannelStatus = DMA_ClearFlag(DMA4);

    if (g_dmaCallbackArray[4])
    {
        g_dmaCallbackArray[4](DMA4, dmaChannelStatus, 0);
    }
}

/**
 * DMA5_IRQHandler
 *
 * @param[in] none
 * @return    none
 *
* @brief  CallBack the DMA5 Interrupt Handler
 */
void DMA5_IRQHandler(void)
{
    uint32_t dmaChannelStatus = DMA_ClearFlag(DMA5);

    if (g_dmaCallbackArray[5])
    {
        g_dmaCallbackArray[5](DMA5, dmaChannelStatus, 0);
    }
}

/**
 * DMA6_IRQHandler
 *
 * @param[in] none
 * @return    none
 *
* @brief  CallBack the DMA6 Interrupt Handler
 */
void DMA6_IRQHandler(void)
{
    uint32_t dmaChannelStatus = DMA_ClearFlag(DMA6);

    if (g_dmaCallbackArray[6])
    {
        g_dmaCallbackArray[6](DMA6, dmaChannelStatus, 0);
    }
}

/**
 * DMA7_IRQHandler
 *
 * @param[in] none
 * @return    none
 *
* @brief  CallBack the DMA7 Interrupt Handler
 */
void DMA7_IRQHandler(void)
{
    uint32_t dmaChannelStatus = DMA_ClearFlag(DMA7);

    if (g_dmaCallbackArray[7])
    {
        g_dmaCallbackArray[7](DMA7, dmaChannelStatus, 0);
    }
}

/**
 * DMA8_IRQHandler
 *
 * @param[in] none
 * @return    none
 *
* @brief  CallBack the DMA8 Interrupt Handler
 */
void DMA8_IRQHandler(void)
{
    uint32_t dmaChannelStatus = DMA_ClearFlag(DMA8);

    if (g_dmaCallbackArray[8])
    {
        g_dmaCallbackArray[8](DMA8, dmaChannelStatus, 0);
    }
}

/**
 * DMA9_IRQHandler
 *
 * @param[in] none
 * @return    none
 *
* @brief  CallBack the DMA9 Interrupt Handler
 */
void DMA9_IRQHandler(void)
{
    uint32_t dmaChannelStatus = DMA_ClearFlag(DMA9);

    if (g_dmaCallbackArray[9])
    {
        g_dmaCallbackArray[9](DMA9, dmaChannelStatus, 0);
    }
}

/**
 * DMA10_IRQHandler
 *
 * @param[in] none
 * @return    none
 *
* @brief  CallBack the DMA10 Interrupt Handler
 */
void DMA10_IRQHandler(void)
{
    uint32_t dmaChannelStatus = DMA_ClearFlag(DMA10);

    if (g_dmaCallbackArray[10])
    {
        g_dmaCallbackArray[10](DMA10, dmaChannelStatus, 0);
    }
}

/**
 * DMA11_IRQHandler
 *
 * @param[in] none
 * @return    none
 *
* @brief  CallBack the DMA11 Interrupt Handler
 */
void DMA11_IRQHandler(void)
{
    uint32_t dmaChannelStatus = DMA_ClearFlag(DMA11);

    if (g_dmaCallbackArray[11])
    {
        g_dmaCallbackArray[11](DMA11, dmaChannelStatus, 0);
    }
}

/**
 * DMA12_IRQHandler
 *
 * @param[in] none
 * @return    none
 *
* @brief  CallBack the DMA12 Interrupt Handler
 */
void DMA12_IRQHandler(void)
{
    uint32_t dmaChannelStatus = DMA_ClearFlag(DMA12);

    if (g_dmaCallbackArray[12])
    {
        g_dmaCallbackArray[12](DMA12, dmaChannelStatus, 0);
    }
}

