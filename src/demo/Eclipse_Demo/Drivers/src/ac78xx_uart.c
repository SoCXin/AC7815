/* Copyright Statement:
*
* This software/firmware and related documentation ("Autochips Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to Autochips Inc. and/or its licensors.
* Without the prior written permission of Autochips inc. and/or its licensors,
* any reproduction, modification, use or disclosure of Autochips Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*
* Copyright(C) 2016, Autochips ( All rights reserved. )
*
* BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("AUTOCHIPS SOFTWARE")
* RECEIVED FROM Autochips AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
* AN "AS-IS" BASIS ONLY. Autochips EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES Autochips PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE Autochips SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. Autochips SHALL ALSO
* NOT BE RESPONSIBLE FOR ANY Autochips SOFTWARE RELEASES MADE TO BUYER'S
* SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
* BUYER'S SOLE AND EXCLUSIVE REMEDY AND Autochips'S ENTIRE AND CUMULATIVE
* LIABILITY WITH RESPECT TO THE Autochips SOFTWARE RELEASED HEREUNDER WILL BE,
* AT Autochips'S OPTION, TO REVISE OR REPLACE THE Autochips SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*
* Autochips FOR SUCH Autochips SOFTWARE AT ISSUE.
*
* THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
* WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
* LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
* RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
* THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*****************************************************************************/

#include "ac78xx_uart.h"

static UART_Event_Callback s_uartCallback[UART_NUM] = {0};


static const UART_Type * const s_uartCtrlMap[UART_NUM] =
{UART1, UART2, UART3, UART4, UART5, UART6};


const UART_DMA_INFO g_uartDMAChannel[UART_NUM] =
{
    {DMA4,  DMA5,  DMA4_IRQn,  DMA5_IRQn},  //UART1
    {DMA6,  DMA7,  DMA6_IRQn,  DMA7_IRQn},  //UART2
    {DMA2,  DMA3,  DMA2_IRQn,  DMA3_IRQn},  //UART3
    {DMA8,  DMA9,  DMA8_IRQn,  DMA9_IRQn},  //UART4
    {DMA10, DMA11, DMA10_IRQn, DMA11_IRQn}, //UART5
    {DMA12, DMA1,  DMA12_IRQn, DMA1_IRQn},  //UART6
};



/**
* UART_GetDMAInfo
*
* @param[in] uartIndex: UART index, value can be 0 to 5
* @return    DMA info pointer
*
* @brief  Get UART DMA Info
*/
const UART_DMA_INFO * UART_GetDMAInfo(uint8_t uartIndex)
{
    const UART_DMA_INFO * dmaInfo = 0;

    if (uartIndex < UART_NUM)
    {
        dmaInfo = &g_uartDMAChannel[uartIndex];
    }

    return dmaInfo;
}


/**
* UART_SetBaud
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @param[in] baudrate: UART baudrate
* @param[in] sampleCounter: Division factor for bus clock, value can be
*                         - RATE_STEP_2:
*                         - RATE_STEP_1:
*                         - RATE_STEP_0:
* @return    none
*
* @brief  Set UART baudrate
*/
void UART_SetBaudrate(UART_Type *UARTx, uint32_t baudrate, uint8_t sampleCounter)
{
    float divisor = 0;
    uint8_t div = SAMPLE_COUNTER_16;

    switch (sampleCounter)
    {
    case RATE_STEP_2:
        div = SAMPLE_COUNTER_4;
        break;
    case RATE_STEP_1:
        div = SAMPLE_COUNTER_8;
        break;
    default:
        div = SAMPLE_COUNTER_16;
        break;
    }

    UART_SetSampleCounter(UARTx, sampleCounter);
    divisor = (float)UART_BUSCLK / div / baudrate;
    UART_SetDivisor(UARTx, divisor);
    UART_SetGuard(UARTx, GUARDCNT_DEF);
}


/**
* UART_Init
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @param[in] uartSetting: uart setting type pointer which contains the configuration
*                         information for the specified UART.
* @return    always 0
*
* @brief  UART initialize
*/
int32_t UART_Init(UART_Type *UARTx, UART_SettingType *uartSetting)
{
    if (UARTx && uartSetting)
    {
        switch ((uint32_t)UARTx)
        {
        case UART1_BASE:
            CKGEN_Enable(CLK_UART1, 1);
            CKGEN_SoftReset(SRST_UART1, 1);
            break;

        case UART2_BASE:
            CKGEN_Enable(CLK_UART2, 1);
            CKGEN_SoftReset(SRST_UART2, 1);
            break;

        case UART3_BASE:
            CKGEN_Enable(CLK_UART3, 1);
            CKGEN_SoftReset(SRST_UART3, 1);
            break;

        case UART4_BASE:
            CKGEN_Enable(CLK_UART4, 1);
            CKGEN_SoftReset(SRST_UART4, 1);
            break;

        case UART5_BASE:
            CKGEN_Enable(CLK_UART5, 1);
            CKGEN_SoftReset(SRST_UART5, 1);
            break;

        case UART6_BASE:
            CKGEN_Enable(CLK_UART6, 1);
            CKGEN_SoftReset(SRST_UART6, 1);
            break;

        default:
            break;
        }

        UART_SetDataBits(UARTx, uartSetting->dataBits);
        UART_SetParity(UARTx, uartSetting->parity);
        UART_SetBaudrate(UARTx, uartSetting->baudrate, uartSetting->rateStep);
        UART_SetStopBit(UARTx, uartSetting->stopBits);

        if (uartSetting->dmaEn)
        {
            uartSetting->fifoByte = 1;
        }

        UART_Set2ByteFIFO(UARTx, uartSetting->fifoByte);
        UART_EnableDMA(UARTx, uartSetting->dmaEn);
        UART_EnableTX(UARTx, 1);
        UART_EnableRX(UARTx, 1);
    }

    return 0;
}


/**
* UART_Uninit
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @return    always 0
*
* @brief  UART uninitialize
*/
int32_t UART_Uninit(UART_Type *UARTx)
{
    if (UARTx)
    {
        switch ((uint32_t)UARTx)
        {
        case UART1_BASE:
            NVIC_DisableIRQ(UART1_IRQn);
            CKGEN_SoftReset(SRST_UART1, 0);
            CKGEN_Enable(CLK_UART1, 0);
            break;

        case UART2_BASE:
            NVIC_DisableIRQ(UART2_IRQn);
            CKGEN_SoftReset(SRST_UART2, 0);
            CKGEN_Enable(CLK_UART2, 0);
            break;

        case UART3_BASE:
            NVIC_DisableIRQ(UART3_IRQn);
            CKGEN_SoftReset(SRST_UART3, 0);
            CKGEN_Enable(CLK_UART3, 0);
            break;

        case UART4_BASE:
            NVIC_DisableIRQ(UART4_IRQn);
            CKGEN_SoftReset(SRST_UART4, 0);
            CKGEN_Enable(CLK_UART4, 0);
            break;

        case UART5_BASE:
            NVIC_DisableIRQ(UART5_IRQn);
            CKGEN_SoftReset(SRST_UART5, 0);
            CKGEN_Enable(CLK_UART5, 0);
            break;

        case UART6_BASE:
            NVIC_DisableIRQ(UART6_IRQn);
            CKGEN_SoftReset(SRST_UART6, 0);
            CKGEN_Enable(CLK_UART6, 0);
            break;

        default:
            break;
        }
    }
    return 0;
}



/**
* UART_SetCallback
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @param[in] Callback: UART Callback function which will be called in UARTx_IRQHandler.
* @return    0:Success   1:Fail
*
* @brief  Set UART call back
*/
int32_t UART_SetEventCallback(UART_Type *UARTx, UART_Event_Callback callback)
{
    int32_t erro = 1;
    uint8_t uartIndex = 0;

    for (uartIndex = 0; uartIndex < UART_NUM; uartIndex++)
    {
        if (s_uartCtrlMap[uartIndex] == UARTx)
        {
            s_uartCallback[uartIndex] = callback;
            erro = 0;
            break;
        }
    }

    return erro;
}


/**
* UART_InterruptHandler
*
* @param[in] uartIndex: Uart index, value can be 1 to 6
* @return    none
*
* @brief  UART Interrupt Handler
*/
static void UART_InterruptHandler(uint8_t uartIndex)
{
    if ((uartIndex - 1) < UART_NUM)
    {
        UART_Type *UARTx = (UART_Type *)s_uartCtrlMap[uartIndex - 1];
        uint32_t lsr0 = UARTx->Ux_LSR0;
        uint32_t lsr1 = UARTx->Ux_LSR1;

        UARTx->Ux_LSR0 = lsr0;
        UARTx->Ux_LSR1 = lsr1;

        if (0 == UARTx->UARTn_IER.ERXNE)
        {
            lsr0 &= ~LSR0_DR;
        }

        if (s_uartCallback[uartIndex - 1])
        {
            s_uartCallback[uartIndex - 1](uartIndex, lsr0, lsr1);
        }
    }
}


/**
* UART1_IRQHandler
*
* @param[in]  none
* @return     none
*
* @brief  UART1 Interrupt Handler
*/
void UART1_IRQHandler(void)
{
    UART_InterruptHandler(PORT1);
}


/**
* UART2_IRQHandler
*
* @param[in]  none
* @return     none
*
* @brief  UART2 Interrupt Handler
*/
#ifndef DEBUG_CMD_INTERRUPT
void UART2_IRQHandler(void)
{
    UART_InterruptHandler(PORT2);
}
#endif

/**
* UART3_IRQHandler
*
* @param[in]  none
* @return     none
*
* @brief  UART3 Interrupt Handler
*/
void UART3_IRQHandler(void)
{
    UART_InterruptHandler(PORT3);
}


/**
* UART4_IRQHandler
*
* @param[in]  none
* @return     none
*
* @brief  UART4 Interrupt Handler
*/
void UART4_IRQHandler(void)
{
    UART_InterruptHandler(PORT4);
}

/**
* UART5_IRQHandler
*
* @param[in]  none
* @return     none
*
* @brief  UART5 Interrupt Handler
*/
void UART5_IRQHandler(void)
{
    UART_InterruptHandler(PORT5);
}


/**
* UART6_IRQHandler
*
* @param[in]  none
* @return     none
*
* @brief  UART6 Interrupt Handler
*/
#ifndef UART_LIN
void UART6_IRQHandler(void)
{
    UART_InterruptHandler(PORT6);
}
#endif

/**
* UART_StartDMATransmit
*
* @param[in] uartIndex: UART index, value can be 1 to 6
* @param[in] dataBits: Transfer bits select, value can be 8 or 9
* @param[in] memStartAddr: point to the send data
* @param[in] txTransferNum: Transfer data numbers
* @param[in] callback: point to DMA callback function
* @return    0:Success,  -1:Fail
*
* @brief  UART DMA transmit data
*/
int32_t UART_StartDMATransmit(uint8_t uartIndex, uint8_t dataBits, uint32_t memStartAddr, uint32_t txTransferNum, DMA_EventCallback callback)
{
    int32_t erro = -1;
    DMA_ConfigType dmaConfig = {0};

    if ((uartIndex - 1) < UART_NUM)
    {
        dmaConfig.memStartAddr = memStartAddr;
        dmaConfig.periphStartAddr = (uint32_t)(&(s_uartCtrlMap[uartIndex - 1]->UARTn_RBR_THR));
        dmaConfig.setting.channelEn = 1;
        dmaConfig.setting.finishIntEn = 1;
        dmaConfig.setting.halfFinishIntEn = 1;
        dmaConfig.setting.errorIntEn = 1;
        dmaConfig.setting.channelPriority = 3;
        dmaConfig.setting.circular = 0;
        dmaConfig.setting.direction = 1;
        dmaConfig.setting.MEM2MEM = 0;
        dmaConfig.setting.memIncrement = 1;
        dmaConfig.setting.periphIncrement = 0;
        dmaConfig.setting.memSize = 2;
        dmaConfig.setting.periphSize = 0;
        dmaConfig.setting.transferNum = txTransferNum;

        if (dataBits == 9)
        {
            dmaConfig.memEndAddr = memStartAddr + txTransferNum * 2;
            dmaConfig.setting.memByteMode = 1;
        }
        else
        {
            dmaConfig.memEndAddr = memStartAddr + txTransferNum;
            dmaConfig.setting.memByteMode = 3;
        }

        NVIC_EnableIRQ(g_uartDMAChannel[uartIndex - 1].txDMAIRQ);
        DMA_Uninitialize(g_uartDMAChannel[uartIndex - 1].txCH);
        DMA_SetEventCallback(g_uartDMAChannel[uartIndex - 1].txCH, callback);
        DMA_Initialize(g_uartDMAChannel[uartIndex - 1].txCH, &dmaConfig);
        erro = 0;
    }

    return erro;
}


/**
* UART_StartDMAReceive
*
* @param[in] uartIndex: UART index, value can be 1 to 6
* @param[in] dataBits: Receive bits select, value can be 8 or 9
* @param[in] memStartAddr: point to the receive buffer
* @param[in] rxTransferNum: Receive data numbers
* @param[in] callback: point to DMA callback function
* @return    0:Success,  -1:Fail
*
* @brief  UART DMA receive data
*/
int32_t UART_StartDMAReceive(uint8_t uartIndex, uint8_t dataBits, uint32_t memStartAddr, uint32_t rxTransferNum, DMA_EventCallback callback)
{
    int32_t erro = -1;
    DMA_ConfigType dmaConfig = {0};

    if ((uartIndex - 1) < UART_NUM)
    {
        dmaConfig.memStartAddr = memStartAddr;
        dmaConfig.periphStartAddr = (uint32_t)(&(s_uartCtrlMap[uartIndex - 1]->UARTn_RBR_THR));
        dmaConfig.setting.channelEn = 1;
        dmaConfig.setting.finishIntEn = 1;
        dmaConfig.setting.halfFinishIntEn = 1;
        dmaConfig.setting.errorIntEn = 1;
        dmaConfig.setting.channelPriority = 3;
        dmaConfig.setting.circular = 1;
        dmaConfig.setting.direction = 0;
        dmaConfig.setting.MEM2MEM = 0;
        dmaConfig.setting.memIncrement = 1;
        dmaConfig.setting.periphIncrement = 0;
        dmaConfig.setting.memSize = 2;
        dmaConfig.setting.periphSize = 0;
        dmaConfig.setting.transferNum = rxTransferNum;

        if (dataBits == 9)
        {
            dmaConfig.memEndAddr = memStartAddr + rxTransferNum * 2;
            dmaConfig.setting.memByteMode = 1;
        }
        else
        {
            dmaConfig.memEndAddr = memStartAddr + rxTransferNum;
            dmaConfig.setting.memByteMode = 3;
        }

        NVIC_EnableIRQ(g_uartDMAChannel[uartIndex - 1].rxDMAIRQ);
        DMA_Uninitialize(g_uartDMAChannel[uartIndex - 1].rxCH);
        DMA_SetEventCallback(g_uartDMAChannel[uartIndex - 1].rxCH, callback);
        DMA_Initialize(g_uartDMAChannel[uartIndex - 1].rxCH, &dmaConfig);

        erro = 0;
    }

    return erro;
}


/**
* UART_StopDAMReceive
*
* @param[in] uartIndex: UART index, value can be 1 to 6
* @return    0:Success,  -1:Fail
*
* @brief  UART DMA stop receive
*/
int32_t UART_StopDAMReceive(uint8_t uartIndex)
{
    int32_t erro = -1;

    if ((uartIndex - 1) < UART_NUM)
    {
        DMA_Uninitialize(g_uartDMAChannel[uartIndex - 1].rxCH);
        erro = 0;
    }

    return erro;
}


/**
* UART_StopDMATransmit
*
* @param[in] uartIndex: UART index, value can be 1 to 6
* @return    0:Success,  -1:Fail
*
* @brief  UART DMA stop transfer
*/
int32_t UART_StopDMATransmit(uint8_t uartIndex)
{
    int32_t erro = -1;

    if ((uartIndex - 1) < UART_NUM)
    {
        DMA_Uninitialize(g_uartDMAChannel[uartIndex - 1].txCH);
        erro = 0;
    }

    return erro;
}


/**
* UART_GetDMAReceiveCount
*
* @param[in] uartIndex: UART index, value can be 1 to 6
* @return    DMA received num
*
* @brief  Get UART DMA received num
*/
uint32_t UART_GetDMAReceiveCount(uint8_t uartIndex)
{
    uint32_t count = 0;

    if ((uartIndex - 1) < UART_NUM)
    {
        count = DMA_GetTransferedDataNum(g_uartDMAChannel[uartIndex - 1].rxCH);
    }

    return count;
}


/**
* UART_GetUARTCtrl
*
* @param[in] uartIndex: UART index, value can be 1 to 6
* @return    UART type pointer
*
* @brief  Get UART type pointer
*/
UART_Type* UART_GetUARTCtrl(uint8_t uartIndex)
{
    UART_Type* UARTx = 0;

    if ((uartIndex - 1) < UART_NUM)
    {
        UARTx = (UART_Type*)s_uartCtrlMap[uartIndex - 1];
    }

    return UARTx;
}


