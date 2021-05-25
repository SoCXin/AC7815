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
 * INCORPORATED IN, OR S.UPPLIED WITH THE AUTOCHIPS SOFTWARE, AND RECEIVER AGREES
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

#include "ac78xx_i2c.h"

I2C_EventCallback g_i2cCallbackArray[2] = {(I2C_EventCallback)NULL}; ///< I2C initial callback
I2C_MasterSendType g_i2cMasterSendInfo[2] = {0};                     ///< I2C master initial sendinfo
I2C_MasterReceiveType g_i2cMasterReceiveInfo[2] = {0};               ///< I2C master initial receiveinfo
I2C_SlaveSendType g_i2cSlaveSendInfo[2] = {0};                       ///< I2C slave initial sendinfo
I2C_SlaveReceiveType g_i2cSlaveReceiveInfo[2] = {0};                 ///< I2C slave initial receiveinfo
uint32_t g_i2cStatus[2] = {0};

///< For I2C interrupt
uint32_t g_i2cMasterSendBufferLength[2] = {16, 16};                         ///< I2C master initial send buffer length
uint32_t g_i2cMasterReceiveBufferLength[2] = {16, 16};                      ///< I2C master initial receive buffer length
uint32_t g_i2cSlaveSendBufferLength[2] = {16, 16};                          ///< I2C slave initial send buffer length
uint32_t g_i2cSlaveReceiveBufferLength[2] = {16, 16};                      ///< I2C slave initial receive buffer length

const I2C_INFO g_i2cInfoPool[] =
{
    {I2C1, I2C1_IRQn, CLK_I2C1, SRST_I2C1},   ///< I2C1
    {I2C2, I2C2_IRQn, CLK_I2C2, SRST_I2C2},   ///< I2C2
};

const I2C_DMA_INFO g_i2cDMAChannel[] =
{
    {DMA11, DMA12, DMA11_IRQn, DMA12_IRQn}, ///< I2C1
    {DMA9, DMA10, DMA9_IRQn, DMA10_IRQn},   ///< I2C2
};

/**
* I2C_Initialize
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] config: pointer to a I2C_ConfigType structure contains I2C configuration information.
* @return 0: success, other: error value.
*
* @brief  Initialize I2C peripheral according to the I2C_ConfigType structure
*/
int32_t I2C_Initialize(I2C_Type *I2Cx, I2C_ConfigType *config)
{
    uint8_t  index = ((uint32_t)I2Cx - (uint32_t)I2C1) >> 12;

    CKGEN_Enable(g_i2cInfoPool[index].CKGEN_I2Cx, 1);     /* Enable I2C clock */
    CKGEN_SoftReset(g_i2cInfoPool[index].SRST_I2Cx, 1);   /* Inactive I2C reset */

    if (config->setting.master)
    {
        I2C_SetMSTR(I2Cx);              /* Master */
        if (config->setting.syncEn)
        {
            I2C_EnableSync(I2Cx);       /* Enable SCL Synchronization mode */
        }
        if (config->setting.arbEn)
        {
            I2C_EnableARB(I2Cx);        /* Enable SDA Arbitration mode */
        }
    }
    else
    {
        I2C_ClrMSTR(I2Cx);              /* Slave */
        if (config->setting.mntEn)
        {
            I2C_EnableMNT(I2Cx);        /* Enable Monitor mode */
        }
        if (config->setting.strEn)
        {
            I2C_EnableSTR(I2Cx);        /* Enable SCL Stretch mode */
        }
        if (config->setting.gcaEn)
        {
            I2C_EnableGCA(I2Cx);        /* Enable General Call Address mode */
        }
        if (config->setting.addressExt)
        {
            I2C_EnableADEXT(I2Cx);       /* Slave uses 10-bit address */
        }
        if (config->setting.wakeUpEn)
        {
            I2C_EnableWakeUp(I2Cx);      /* Enable Slave wakeup */
        }
    }
    if (config->setting.intEn)
    {
        NVIC_EnableIRQ(g_i2cInfoPool[index].I2Cx_IRQn);
        I2C_EnableInt(I2Cx);
    }
    else
    {
        NVIC_DisableIRQ(g_i2cInfoPool[index].I2Cx_IRQn);
        I2C_DisableInt(I2Cx);
    }
    if (config->setting.rxOFIntEn)
    {
        I2C_EnableRxOFInt(I2Cx);
    }
    if (config->setting.txUFIntEn)
    {
        I2C_EnableTxUFInt(I2Cx);
    }
    if (config->setting.nackIntEn)
    {
        I2C_EnableNackInt(I2Cx);
    }
    if (config->setting.dmaRxEn)
    {
        I2C_EnableDMARx(I2Cx);
    }
    else
    {
        I2C_DisableDMARx(I2Cx);
    }
    if (config->setting.dmaTxEn)
    {
        I2C_EnableDMATx(I2Cx);
    }
    else
    {
        I2C_DisableDMATx(I2Cx);
    }
    if (config->setting.SSIE)
    {
        I2C_EnableSSInt(I2Cx);
    }
    I2C_SetSlaveAddr(I2Cx, config->addr1);
    I2C_SetSampleStep(I2Cx, config->sampleCNT, config->stepCNT);
    if (config->setting.i2cEn)
    {
        I2C_Enable(I2Cx);
    }
    else
    {
        I2C_Disable(I2Cx);
    }
    return 0;
}

/**
* I2C_Uninitialize
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return 0: success, other: error value
*
* @brief  Uninitialize I2C peripheral by disbale IRQ, reset peripheral and disable CLK. 
*/
int32_t I2C_Uninitialize(I2C_Type *I2Cx)
{
    uint8_t  index = ((uint32_t)I2Cx - (uint32_t)I2C1) >> 12;

    NVIC_DisableIRQ(g_i2cInfoPool[index].I2Cx_IRQn);
	CKGEN_SoftReset(g_i2cInfoPool[index].SRST_I2Cx, 0);
    CKGEN_Enable(g_i2cInfoPool[index].CKGEN_I2Cx, 0);
    return 0;
}

/**
* I2C_SetEventCallback
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] callback: user-defined callback interface function
* @return 0: success, other: error value
*
* @brief  specify I2C event callback function
*/
int32_t I2C_SetEventCallback(I2C_Type *I2Cx, I2C_EventCallback callback)
{
    uint8_t  index = ((uint32_t)I2Cx - (uint32_t)I2C1) >> 12;

    g_i2cCallbackArray[index] = callback;

    return 0;
}


/**
* I2C1_IRQHandler
*
* @param[in] none
* @return none
*
* @brief  override the I2C1_IRQHandler
*/
void I2C1_IRQHandler(void)
{
    I2C_ClrStatus1(I2C1, I2C_STATUS_1_TCF_MASK);  /* Write 1 to clear TCF */
    if (g_i2cCallbackArray[0])
    {
        g_i2cCallbackArray[0](I2C1, 0, 0);
    }
}

/**
* I2C2_IRQHandler
*
* @param[in] none
* @return none
*
* @brief  override the I2C2_IRQHandler
*/
void I2C2_IRQHandler(void)
{
    I2C_ClrStatus1(I2C2, I2C_STATUS_1_TCF_MASK);  /* Write 1 to clear TCF */
    if (g_i2cCallbackArray[1])
    {
        g_i2cCallbackArray[1](I2C2, 0, 0);
    }
}

/**
* I2C_Callback
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] wparam: reserved for user-defined transfer parameters
* @param[in] lparam: reserved for user-defined transfer parameters
* @return 0: success, other value: fail
*
* @brief I2C callback function which handles Tx and Rx in interrupt
*/
int32_t I2C_Callback(I2C_Type *I2Cx, uint32_t wparam, uint32_t lparam)
{
    uint32_t ret = 0;
    if (I2C_GetStatus1(I2Cx) & I2C_STATUS_1_ARBLOST_MASK)
    {
        I2C_ClrStatus1(I2Cx, I2C_STATUS_1_ARBLOST_MASK);
        if (!(I2C_GetStatus1(I2Cx) & I2C_STATUS_1_DEV_HIT_MASK))
        {
            //DEV_HIT is 0
            ret = 1;
        }
        ret = 1;
    }
    if (I2C_GetStatus2(I2Cx) & I2C_STATUS_2_RXOF_MASK)
    {
        I2C_ClrStatus2(I2Cx, I2C_STATUS_2_RXOF_MASK);
        ret = 1;
    }
    if (I2C_GetStatus2(I2Cx) & I2C_STATUS_2_TXUF_MASK)
    {
        I2C_ClrStatus2(I2Cx, I2C_STATUS_2_TXUF_MASK);
        ret = 1;
    }

    if(!ret)
    {
        if (I2C_IsMaster(I2Cx))
        {
            I2C_MasterIntHandler(I2Cx, 0, 0);
        }
        else
        {
        I2C_SlaveIntHandler(I2Cx, 0, 0);
        }
    }

    return 0;
}

/**
* I2C_DMACallback
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] wparam: reserved for user-defined transfer parameters
* @param[in] lparam: reserved for user-defined transfer parameters
* @return 0: success, other value: fail
*
* @brief I2C DMA callback function which handles DMA Tx and Rx Enable in interrupt
*/
int32_t I2C_DMACallback(I2C_Type *I2Cx, uint32_t wparam, uint32_t lparam)
{
    if (I2C_IsMaster(I2Cx))
    {
        I2C_MasterDMAHandler(I2Cx, 0, 0);
    }
    else
    {
        I2C_SlaveDMAHandler(I2Cx, 0, 0);
    }

    return 0;
}

/**
* I2C_MasterDMAHandler
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] wparam: reserved for user-defined transfer parameters
* @param[in] lparam: reserved for user-defined transfer parameters
* @return none
*
* @brief I2C Master DMA callback function which handles DMA Tx and Rx Enable in interrupt
*/
void I2C_MasterDMAHandler(I2C_Type *I2Cx, uint32_t wparam, uint32_t lparam)
{

    if (I2C_GetStatus1(I2Cx) & I2C_STATUS_1_RACK_MASK)
    {
        I2C_DisableDMATx(I2Cx);                       /* Disable I2C's OWN DMATXEN bit */
        I2C_ClrStatus1(I2Cx, I2C_STATUS_1_TCF_MASK);  /* Write 1 to clear TCF */
        I2C_ClrStatus1(I2Cx, I2C_STATUS_1_RACK_MASK);
    }
    if (I2C_GetStatus2(I2Cx) & I2C_STATUS_2_TXUF_MASK)
    {
        I2C_DisableDMATx(I2Cx);                       /* Disable I2C's OWN DMATXEN bit */
        I2C_ClrStatus2(I2Cx, I2C_STATUS_2_TXUF_MASK);
    }
    if (I2C_GetStatus2(I2Cx) & I2C_STATUS_2_RXOF_MASK)
    {
        I2C_DisableDMARx(I2Cx);                      /* Disable I2C's OWN DMARXEN bit */
        I2C_ClrStatus2(I2Cx, I2C_STATUS_2_RXOF_MASK);
    }
    if (I2C_GetStatus1(I2Cx) & I2C_STATUS_1_ARBLOST_MASK)
    {
        I2C_ClrStatus1(I2Cx, I2C_STATUS_1_ARBLOST_MASK);
        if (!(I2C_GetStatus1(I2Cx) & I2C_STATUS_1_DEV_HIT_MASK))
        {
            //DEV_HIT is 0
        }
    }
    I2C_ClrStatus1(I2Cx, I2C_STATUS_1_TCF_MASK);  /* Write 1 to clear TCF */
}

/**
* I2C_SlaveDMAHandler
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] wparam: reserved for user-defined transfer parameters
* @param[in] lparam: reserved for user-defined transfer parameters
* @return none
*
* @brief I2C Slave DMA callback function which handles DMA Tx and Rx Enable in interrupt
*/
void I2C_SlaveDMAHandler(I2C_Type *I2Cx, uint32_t wparam, uint32_t lparam)
{
    uint8_t  index = ((uint32_t)I2Cx - (uint32_t)I2C1) >> 12;

    if (I2C_GetStatus1(I2Cx) & I2C_STATUS_1_DEV_HIT_MASK)  /* only START + DEVICE_ADDRESS match will set I2C_STATUS_1_DEV_HIT_MASK */
    {
        I2C_ClrStatus1(I2Cx, I2C_STATUS_1_DEV_HIT_MASK);    /* Clear Flag */
    }
    if (I2C_GetStatus1(I2Cx) & I2C_STATUS_1_RACK_MASK)
    {
        DMA_ChannelWarmRst(g_i2cDMAChannel[index].txChannelNum);         /* Reset I2C 1 Tx DMA channel */
        I2C_DisableDMATx(I2Cx);                                         /* Disable I2C's OWN DMATXEN bit */
        I2C_ClrStatus1(I2Cx, I2C_STATUS_1_TCF_MASK);                    /* Write 1 to clear TCF */
        I2C_ClrStatus1(I2Cx, I2C_STATUS_1_RACK_MASK);
        I2C_DisableSTR(I2Cx);                                           /* Disable Slave SCL stretch to release SCL */
    }
    if (I2C_GetStatus2(I2Cx) & I2C_STATUS_2_TXUF_MASK)
    {
        I2C_DisableDMATx(I2Cx);                                         /* Disable I2C's OWN DMATXEN bit */
        I2C_ClrStatus2(I2Cx, I2C_STATUS_2_TXUF_MASK);
    }
    if (I2C_GetStatus2(I2Cx) & I2C_STATUS_2_RXOF_MASK)
    {
        I2C_DisableDMARx(I2Cx);                                         /* Disable I2C's OWN DMARXEN bit */
        I2C_ClrStatus2(I2Cx, I2C_STATUS_2_RXOF_MASK);
    }
    I2C_ClrStatus1(I2Cx, I2C_STATUS_1_TCF_MASK);                        /* Write 1 to clear TCF */
}

/**
* I2C_InitCallback
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] wrBuff: user-defined send buffer
* @param[in] rdBuff: user-defined receive buffer
* @param[in] buffSize: user-defined send buffer size
* @return 0: success, other value: error value
*
* @brief  initial I2C callback settings
*/
int32_t I2C_InitCallback(I2C_Type *I2Cx, uint8_t * wrBuff, uint8_t *rdBuff, uint32_t buffSize)
{
    uint8_t  index = ((uint32_t)I2Cx - (uint32_t)I2C1) >> 12;

    g_i2cMasterSendBufferLength[index] = buffSize;
    g_i2cMasterReceiveBufferLength[index] = buffSize;
    g_i2cSlaveSendBufferLength[index] = buffSize;
    g_i2cSlaveReceiveBufferLength[index] = buffSize;

    g_i2cStatus[index] = I2C_STATUS_IDLE;
    g_i2cSlaveReceiveInfo[index].freeLength = g_i2cSlaveReceiveBufferLength[index];
    g_i2cMasterSendInfo[index].sendBuff = wrBuff;
    g_i2cMasterReceiveInfo[index].receiveBuff = rdBuff;
    g_i2cSlaveSendInfo[index].sendBuff = wrBuff;
    g_i2cSlaveReceiveInfo[index].receiveBuff = rdBuff;

    I2C_SetEventCallback(I2Cx, I2C_Callback);   /* I2C1_CallBack handles Tx and Rx in interrupt */

    return 0;
}

/**
* I2C_GetTransferStatus
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return I2C peripheral transfer status
*
* @brief  Get I2C transfer status
*/
int32_t I2C_GetTransferStatus(I2C_Type *I2Cx)
{
    uint8_t  index = ((uint32_t)I2Cx - (uint32_t)I2C1) >> 12;

    return g_i2cStatus[index];
}

/**
* I2C_ResetTransferStatus
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return 0: success, other: error value
*
* @brief  Manually reset I2C transfer status to IDLE
*/
int32_t I2C_ResetTransferStatus(I2C_Type *I2Cx)
{
    uint8_t  index = ((uint32_t)I2Cx - (uint32_t)I2C1) >> 12;

    g_i2cStatus[index] = I2C_STATUS_IDLE;

    return 0;
}

/**
* I2C_Start
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return 0: success, other: error value
*
* @brief  I2C peripheral send start signal
*/
uint8_t I2C_Start(I2C_Type *I2Cx)
{
    uint32_t timeout = 0;
    uint8_t errorStatus = 0;

    I2C_TxEn(I2Cx);
    I2C_SendStart(I2Cx);

    /* Wait BUSY and READY both are 1 */
    while (((!I2C_IsBusy(I2Cx)) || (!I2C_IsReady(I2Cx)))
            && (timeout < I2C_READY_STATUS_TIMEOUT))
    {
        timeout++;
    }
    if (timeout == I2C_READY_STATUS_TIMEOUT)
    {
        errorStatus |= I2C_ERROR_START_NO_BUSY_FLAG;
    }

    return errorStatus;
}

/**
* I2C_Stop
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return 0: success, other: error value
*
* @brief  I2C peripheral send stop signal
*/
uint8_t I2C_Stop(I2C_Type *I2Cx)
{
    uint32_t timeout = 0;
    uint8_t errorStatus = 0;

    I2C_TxEn(I2Cx);
    I2C_SendStop(I2Cx);

    /* Wait BUSY = 0 , BUSY will be cleaned when send STOP */
    while ((I2C_IsBusy(I2Cx) || (!I2C_IsReady(I2Cx)))
            && (timeout < I2C_READY_STATUS_TIMEOUT))
    {
        timeout++;
    }
    if (timeout == I2C_READY_STATUS_TIMEOUT)
    {
        errorStatus |= I2C_ERROR_STOP_BUSY_FLAG;
    }

    return errorStatus;
}

/**
* I2C_Restart
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @return 0: success, other: error value
*
* @brief  I2C peripheral send restart signal
*/
uint8_t I2C_Restart(I2C_Type *I2Cx)
{
    uint32_t timeout = 0;
    uint8_t errorStatus = 0;

    I2C_SendStart(I2Cx);

    /* Wait BUSY and WAIT both are 1 */
    while ((!(I2C_IsBusy(I2Cx) && I2C_IsReady(I2Cx)))
            && (timeout < I2C_READY_STATUS_TIMEOUT))
    {
        timeout++;
    }

    if (timeout == I2C_READY_STATUS_TIMEOUT)
    {
        errorStatus |= I2C_ERROR_START_NO_BUSY_FLAG;
    }

    return errorStatus;
}

/**
* I2C_WriteOneByte
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] wrBuff: the onebyte to be write by I2C peripheral.
* @return 0: success, other: error value
*
* @brief  I2C peripheral write one byte data
*/
uint8_t I2C_WriteOneByte(I2C_Type *I2Cx, uint8_t wrBuff)
{
    uint32_t timeOut = 0;
    uint8_t errorStatus = 0;

    I2C_TxEn(I2Cx);
    I2C_WriteDataReg(I2Cx, wrBuff);
    if (!I2C_IsDMATxEnable(I2Cx))
    {
        while (((I2C_GetStatus1(I2Cx)&I2C_STATUS_1_TCF_MASK) !=  I2C_STATUS_1_TCF_MASK)
                && (timeOut < I2C_READY_STATUS_TIMEOUT))
        {
            timeOut++;
        }
        if (timeOut >= I2C_READY_STATUS_TIMEOUT)
        {
            errorStatus |= I2C_ERROR_NO_WAIT_TCF_FLAG;
        }

        if (I2C_GetStatus1(I2Cx) & I2C_STATUS_1_RACK_MASK)
        {
            errorStatus |= I2C_ERROR_NO_GET_ACK;
        }
    }

    return errorStatus;
}

/**
* I2C_ReadOneByte
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] rdBuff: pointer to the onebyte read by I2C peripheral.
* @param[in] nack: whether to send a response, 0: ACK, 1: NACK.
* @return 0: success, other: error value
*
* @brief  I2C peripheral read one byte data with ack signal
*/
uint8_t I2C_ReadOneByte(I2C_Type *I2Cx, uint8_t *rdBuff, uint8_t nack)
{
    uint32_t timeout = 0;
    uint8_t errorStatus = 0;

    I2C_RxEn(I2Cx);
    if (nack)
    {
        I2C_SendNack(I2Cx);
    }
    else
    {
        I2C_SendAck(I2Cx);
    }
    *rdBuff = I2C_ReadDataReg(I2Cx);

    while (((I2C_GetStatus1(I2Cx)&I2C_STATUS_1_TCF_MASK) !=  I2C_STATUS_1_TCF_MASK)
            && (timeout < I2C_READY_STATUS_TIMEOUT))
    {
        timeout++;
    }
    if (timeout >= I2C_READY_STATUS_TIMEOUT)
    {
        errorStatus |= I2C_ERROR_NO_WAIT_TCF_FLAG;
    }

    return errorStatus;
}

/**
* I2C_ReadLastOneByte
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] rdBuff: pointer to the onebyte read by I2C peripheral.
* @param[in] nack: whether to send a response, 0: ACK, 1: NACK.
* @return 0: success, other: error value
*
* @brief  I2C peripheral read last one byte data with ack signal
*/
uint8_t I2C_ReadLastOneByte(I2C_Type *I2Cx, uint8_t *rdBuff, uint8_t nack)
{
    uint8_t errorStatus = 0;

    I2C_TxEn(I2Cx);             /* Make sure slave stop sending data */
    if (nack)
    {
        I2C_SendNack(I2Cx);
    }
    else
    {
        I2C_SendAck(I2Cx);
    }
    *rdBuff = I2C_ReadDataReg(I2Cx);
    I2C_ClrStatus1(I2Cx, I2C_STATUS_1_TCF_MASK);    /* Clear TCF by w1c, since when TxEn, ReadDataReg cannot clear TCF */

    return errorStatus;
}

/**
* I2C_MasterWrite
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] slaveAddress: I2C slave peripheral address.
* @Param[in] wrBuff: pointer to the user-defined send buffer array.
* @Param[in] dataLength: the user-defined send buffer length.
* @return 0: success, other: error value
*
* @brief  I2C Master send a complete transmission sequence: "start + address + data0~dataN + stop"
*/
int32_t I2C_MasterWrite(I2C_Type *I2Cx, uint32_t slaveAddress, uint8_t *wrBuff, uint32_t dataLength)
{
    uint32_t i = 0,timeout = 0;
    uint32_t errorStatus = 0;

    while (((I2Cx->STATUS_1.STATUS_1_Byte & 0x28) != I2C_STATUS_1_READY_MASK) && (timeout < I2C_READY_STATUS_TIMEOUT))
    {
        timeout ++;
    }
    if (timeout >= I2C_READY_STATUS_TIMEOUT)
    {
        errorStatus |= I2C_ERROR_START_NO_BUSY_FLAG;
    }
    errorStatus |= I2C_Start(I2Cx);
    errorStatus |= I2C_WriteOneByte(I2Cx, ((uint8_t)slaveAddress << 1) | I2C_WRITE);
    if (errorStatus == I2C_ERROR_NULL)
    {
        for (i = 0; i < dataLength; i++)
        {
            errorStatus |= I2C_WriteOneByte(I2Cx, wrBuff[i]);
            if (errorStatus != I2C_ERROR_NULL)
            {
                break;
            }
        }
    }

    errorStatus |= I2C_Stop(I2Cx);

    return errorStatus;
}

/**
* I2C_MasterRead
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] slaveAddress: I2C slave peripheral address.
* @Param[in] rdBuff: pointer to the user-defined receive buffer array.
* @Param[in] dataLength: the user-determined receive bytes counts.
* @return 0: success, other: error value
*
* @brief  I2C Master start a complete receive sequence: "start + address + data0~dataN + stop"
*/
int32_t I2C_MasterRead(I2C_Type *I2Cx, uint32_t slaveAddress, uint8_t *rdBuff, uint32_t dataLength)
{
    uint32_t i = 0,timeout = 0;
    uint32_t errorStatus = 0;

    while (((I2Cx->STATUS_1.STATUS_1_Byte & 0x28) != I2C_STATUS_1_READY_MASK) && (timeout < I2C_READY_STATUS_TIMEOUT))
    {
        timeout ++;
    }
    if (timeout >= I2C_READY_STATUS_TIMEOUT)
    {
        errorStatus |= I2C_ERROR_START_NO_BUSY_FLAG;
    }
    errorStatus |= I2C_Start(I2Cx);
    errorStatus |= I2C_WriteOneByte(I2Cx, ((uint8_t)slaveAddress << 1) | I2C_READ);
    //dummy read one byte to switch to Rx mode */
    if (dataLength == 1)
    {
        I2C_ReadOneByte(I2Cx, &rdBuff[0], I2C_SEND_NACK);   /* NACK will influence next transmission. */
    }
    else
    {
        I2C_ReadOneByte(I2Cx, &rdBuff[0], I2C_SEND_ACK);
    }
    if (errorStatus == I2C_ERROR_NULL)
    {
        if (dataLength == 1)
        {
            errorStatus |= I2C_ReadLastOneByte(I2Cx, &rdBuff[0], I2C_SEND_NACK);
        }
        else
        {
            for (i = 0; i < dataLength - 2; i++)
            {
                errorStatus |= I2C_ReadOneByte(I2Cx, &rdBuff[i], I2C_SEND_ACK);
                if (errorStatus != I2C_ERROR_NULL)
                {
                    break;
                }
            }
            errorStatus |= I2C_ReadOneByte(I2Cx, &rdBuff[i++], I2C_SEND_NACK);
            errorStatus |= I2C_ReadLastOneByte(I2Cx, &rdBuff[i], I2C_SEND_NACK);
        }


    }
    errorStatus |= I2C_Stop(I2Cx);

    return errorStatus;
}

/**
* I2C_MasterWriteDMA
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] slaveAddress: I2C slave peripheral address.
* @Param[in] dataLength: the user-determined send bytes length.
* @return 0: success, other: error value
*
* @brief  I2C Master start a send sequence by DMA channel
*/
int32_t I2C_MasterWriteDMA(I2C_Type *I2Cx, uint32_t slaveAddress, uint32_t dataLength)
{
    uint8_t  index = ((uint32_t)I2Cx - (uint32_t)I2C1) >> 12;
    uint32_t errorStatus = 0, tmpTimeout = 0;

    if (DMA_GetTransmissionLength(g_i2cDMAChannel[index].txChannelNum) != dataLength)
    {
        errorStatus = I2C_ERROR_DMA_LENGTH_UNEQUAL;
    }
    else
    {
        I2C_EnableInt(I2Cx);
        I2C_EnableDMATx(I2Cx);
        while (((I2Cx->STATUS_1.STATUS_1_Byte & 0x28) != I2C_STATUS_1_READY_MASK) && (tmpTimeout < I2C_READY_STATUS_TIMEOUT))
        {
            tmpTimeout ++;
        }
        if (tmpTimeout >= I2C_READY_STATUS_TIMEOUT)
        {
            errorStatus |= I2C_ERROR_START_NO_BUSY_FLAG;
        }
        errorStatus |= I2C_Start(I2Cx);
        errorStatus |= I2C_WriteOneByte(I2Cx, ((uint8_t)slaveAddress << 1) | I2C_WRITE);
        if (errorStatus == I2C_ERROR_NULL)
        {
            while ((DMA_GetTransferedDataNum(g_i2cDMAChannel[index].txChannelNum) < dataLength)
                    && (tmpTimeout < I2C_READY_STATUS_TIMEOUT))
            {
                tmpTimeout++;
            }
            if (tmpTimeout >= I2C_READY_STATUS_TIMEOUT)
            {
                errorStatus |= I2C_ERROR_DMA_MASTER_TIMEOUT;
            }
            tmpTimeout = 0;

            /* Make sure last TCF has been cleaned */
            while ((I2C_GetStatus1(I2Cx)&I2C_STATUS_1_TCF_MASK) !=  I2C_STATUS_1_TCF_MASK
                    && (tmpTimeout < I2C_READY_STATUS_TIMEOUT))
            {
                tmpTimeout++;
            }
            if (tmpTimeout >= I2C_READY_STATUS_TIMEOUT)
            {
                errorStatus |= I2C_ERROR_NO_WAIT_TCF_FLAG;
            }
            I2C_ClrStatus1(I2Cx, I2C_STATUS_1_TCF_MASK);
            I2C_DisableDMATx(I2Cx);

        }
        I2C_ClrStatus1(I2Cx, I2C_STATUS_1_TCF_MASK);
        I2C_DisableInt(I2Cx);
        I2C_DisableDMATx(I2Cx);
        errorStatus |= I2C_Stop(I2Cx);
    }

    return errorStatus;
}

/**
* I2C_MasterReadDMA
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] slaveAddress: I2C slave peripheral address.
* @Param[in] dataLength: the user-determined receive bytes counts.
* @return 0: success, other: error value
*
* @brief  I2C Master start a receive sequence by DMA channel
*/
int32_t I2C_MasterReadDMA(I2C_Type *I2Cx, uint32_t slaveAddress, uint32_t dataLength)
{
    uint8_t  index = ((uint32_t)I2Cx - (uint32_t)I2C1) >> 12;
    uint32_t errorStatus = 0;
	uint32_t tmpTimeout = 0;
    uint8_t tmpBuffer = 0;

    if (DMA_GetTransmissionLength(g_i2cDMAChannel[index].rxChannelNum) != dataLength)
    {
        errorStatus = I2C_ERROR_DMA_LENGTH_UNEQUAL;
    }
    else
    {
        /* Master will genenrate TCF after sending device_address, so need to turn off interrupt first */
        I2C_DisableInt(I2Cx);
        /* Disable DMATx for avoiding DMA req after sent slave address */
        I2C_DisableDMATx(I2Cx);
        while (((I2Cx->STATUS_1.STATUS_1_Byte & 0x28) != I2C_STATUS_1_READY_MASK) && (tmpTimeout < I2C_READY_STATUS_TIMEOUT))
        {
            tmpTimeout ++;
        }
        if (tmpTimeout >= I2C_READY_STATUS_TIMEOUT)
        {
            errorStatus |= I2C_ERROR_START_NO_BUSY_FLAG;
        }
        errorStatus |= I2C_Start(I2Cx);
        errorStatus |= I2C_WriteOneByte(I2Cx, ((uint8_t)slaveAddress << 1) | I2C_READ);
        I2C_ClrStatus1(I2Cx, I2C_STATUS_1_TCF_MASK);
        if (errorStatus == I2C_ERROR_NULL)
        {
            /* Dummy read for changing Tx to Rx */
            if (dataLength == 1)
            {
                I2C_ReadOneByte(I2Cx, &tmpBuffer, I2C_SEND_NACK);    /* Dummy read for changing Tx to RxNACK will influence next transmission. */
            }
            else
            {
                I2C_EnableDMARx(I2Cx);
                I2C_EnableInt(I2Cx);        /* Dummy read for changing Tx to Rx Can be disabled */
                I2C_ReadOneByte(I2Cx, &tmpBuffer, I2C_SEND_ACK);
            }
            if (errorStatus == I2C_ERROR_NULL)
            {
                if (dataLength != 1)
                {
                    while ((DMA_GetTransferedDataNum(g_i2cDMAChannel[index].rxChannelNum) < dataLength)
                            && (tmpTimeout < I2C_READY_STATUS_TIMEOUT))
                    {
                        tmpTimeout++;
                    }
                    if (tmpTimeout >= I2C_READY_STATUS_TIMEOUT)
                    {
                        errorStatus |= I2C_ERROR_DMA_MASTER_TIMEOUT;
                    }
                    /* DMA has transfered all data */

                    I2C_ClrStatus1(I2Cx, I2C_STATUS_1_TCF_MASK);
                    I2C_DisableDMARx(I2Cx);
                }
            }
        }
        I2C_ClrStatus1(I2Cx, I2C_STATUS_1_TCF_MASK);
        I2C_DisableInt(I2Cx);
        I2C_DisableDMARx(I2Cx);
        errorStatus |= I2C_Stop(I2Cx);
    }
    return errorStatus;
}

/**
* I2C_MasterWriteExt
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] slaveAddress: 10bit I2C slave address.
* @Param[in] wrBuff: pointer to the user-defined send buffer array.
* @param[in] dataLength: the user-determined send bytes length.
* @return 0: success, other: error value.
*
* @brief  I2C Master send a complete transmission sequence: "start + address(10bit) + data0~dataN + stop".
*/
int32_t I2C_MasterWriteExt(I2C_Type *I2Cx, uint32_t slaveAddress, uint8_t *wrBuff, uint32_t dataLength)
{
    uint32_t i = 0,timeout = 0;
    uint32_t errorStatus = 0;

    while (((I2Cx->STATUS_1.STATUS_1_Byte & 0x28) != I2C_STATUS_1_READY_MASK) && (timeout < I2C_READY_STATUS_TIMEOUT))
    {
        timeout ++;
    }
    if (timeout >= I2C_READY_STATUS_TIMEOUT)
    {
        errorStatus |= I2C_ERROR_START_NO_BUSY_FLAG;
    }
    errorStatus |= I2C_Start(I2Cx);
    errorStatus |= I2C_WriteOneByte(I2Cx, ((0xF8 + (slaveAddress >> 8)) << 1) | I2C_WRITE);
    errorStatus |= I2C_WriteOneByte(I2Cx, (uint8_t)slaveAddress);
    if (errorStatus == I2C_ERROR_NULL)
    {
        for (i = 0; i < dataLength; i++)
        {
            errorStatus = I2C_WriteOneByte(I2Cx, wrBuff[i]);
            if (errorStatus != I2C_ERROR_NULL)
            {
                break;
            }
        }
    }
    errorStatus |= I2C_Stop(I2Cx);

    return errorStatus;
}

/**
* I2C_MasterReadExt
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] slaveAddress: 10bit I2C slave address.
* @Param[in] rdBuff: pointer to the user-defined receive buffer array.
* @param[in] dataLength: the user-determined receive bytes length.
* @return 0: success, other: error value
*
* @brief  I2C Master start a complete receive sequence: "start + address(10bit) + data0~dataN + stop"
*/
int32_t I2C_MasterReadExt(I2C_Type *I2Cx, uint32_t slaveAddress, uint8_t *rdBuff, uint32_t dataLength)
{
    uint32_t i = 0;
    uint32_t errorStatus = 0;
    uint32_t timeout = 0;

    while (((I2Cx->STATUS_1.STATUS_1_Byte & 0x28) != I2C_STATUS_1_READY_MASK) && (timeout < I2C_READY_STATUS_TIMEOUT))
    {
        timeout ++;
    }
    if (timeout >= I2C_READY_STATUS_TIMEOUT)
    {
        errorStatus |= I2C_ERROR_START_NO_BUSY_FLAG;
    }
    errorStatus |= I2C_Start(I2Cx);
    errorStatus |= I2C_WriteOneByte(I2Cx, ((0xF8 + (slaveAddress >> 8)) << 1) | I2C_WRITE);
    errorStatus |= I2C_WriteOneByte(I2Cx, (uint8_t)slaveAddress);

    errorStatus |= I2C_Start(I2Cx);
    errorStatus |= I2C_WriteOneByte(I2Cx, ((0xF8 + (slaveAddress >> 8)) << 1) | I2C_READ);
    /* dummy read one byte to switch to Rx mode */
    if (dataLength == 1)
    {
        I2C_ReadOneByte(I2Cx, &rdBuff[0], I2C_SEND_NACK);   /* NACK will influence next transmission. */
    }
    else
    {
        I2C_ReadOneByte(I2Cx, &rdBuff[0], I2C_SEND_ACK);
    }
    if (errorStatus == I2C_ERROR_NULL)
    {
        if (dataLength == 1)
        {
            errorStatus |= I2C_ReadLastOneByte(I2Cx, &rdBuff[0], I2C_SEND_NACK);
        }
        else
        {
            for (i = 0; i < dataLength - 2; i++)
            {
                errorStatus |= I2C_ReadOneByte(I2Cx, &rdBuff[i], I2C_SEND_ACK);
                if (errorStatus != I2C_ERROR_NULL)
                {
                    break;
                }
            }
            if (errorStatus == I2C_ERROR_NULL)
            {
                errorStatus |= I2C_ReadOneByte(I2Cx, &rdBuff[i++], I2C_SEND_NACK);
                errorStatus |= I2C_ReadLastOneByte(I2Cx, &rdBuff[i], I2C_SEND_NACK);
            }
        }
    }
    errorStatus |= I2C_Stop(I2Cx);

    return errorStatus;
}

/**
* I2C_MasterIntHandler
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] wparam: reserved for user-defined transmit parameters.
* @param[in] lparam: reserved for user-defined transmit parameters.
* @return none
*
* @brief  I2C Master interrupt handler function
*/
void I2C_MasterIntHandler(I2C_Type *I2Cx, uint32_t wparam, uint32_t lparam)
{
    uint32_t index = ((uint32_t)I2Cx - (uint32_t)I2C1) >> 12;

    if (I2C_IsTx(I2Cx))
    {
        if (g_i2cMasterSendInfo[index].pointer < g_i2cMasterSendInfo[index].length)
        {
            I2C_WriteDataReg(I2Cx, g_i2cMasterSendInfo[index].sendBuff[g_i2cMasterSendInfo[index].pointer++]);
        }
        else
        {
            g_i2cStatus[index] |= I2C_STATUS_TX_FINISH;
            I2Cx->STATUS_1.STATUS_1_Byte = I2C_STATUS_1_TCF_MASK;   /* Write 1 to clear TCF */
            I2C_Stop(I2Cx);
        }
    }
    else
    {
        if (g_i2cMasterReceiveInfo[index].pointer < (g_i2cMasterReceiveInfo[index].length - 2))
        {
            I2C_SendAck(I2Cx);
            g_i2cMasterReceiveInfo[index].receiveBuff[g_i2cMasterReceiveInfo[index].pointer++] = I2C_ReadDataReg(I2Cx);
        }
        else if (g_i2cMasterReceiveInfo[index].pointer == (g_i2cMasterReceiveInfo[index].length - 2))
        {
            I2C_SendNack(I2Cx);
            g_i2cMasterReceiveInfo[index].receiveBuff[g_i2cMasterReceiveInfo[index].pointer++] = I2C_ReadDataReg(I2Cx);
        }
        else
        {
            g_i2cStatus[index] |= I2C_STATUS_RX_FINISH;
            I2C_Stop(I2Cx);
            I2C_TxEn(I2Cx);         /* Make sure slave stop sending data */
            g_i2cMasterReceiveInfo[index].receiveBuff[g_i2cMasterReceiveInfo[index].pointer++] = I2C_ReadDataReg(I2Cx);
            I2C_ClrStatus1(I2Cx, I2C_STATUS_1_TCF_MASK);    /* Clear TCF by write1 , since when TxEn, ReadDataReg cannot clear TCF */
        }
    }
}

/**
* I2C_SlaveIntHandler
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] wparam: reserved for user-defined transmit parameters.
* @param[in] lparam: reserved for user-defined transmit parameters.
* @return none
*
* @brief  I2C Slave interrupt handler function
*/
void I2C_SlaveIntHandler(I2C_Type *I2Cx, uint32_t wparam, uint32_t lparam)
{
    uint8_t index = ((uint32_t)I2Cx - (uint32_t)I2C1) >> 12;

    if (I2C_GetStatus1(I2Cx) & I2C_STATUS_1_DEV_HIT_MASK)   /* only START + DEVICE_ADDRESS match will set I2C_STATUS_1_DEV_HIT_MASK */
    {
        I2C_ClrStatus1(I2Cx, I2C_STATUS_1_DEV_HIT_MASK);    /* Clear Flag */
        if (I2C_GetStatus1(I2Cx)& I2C_STATUS_1_SRW_MASK)
        {
            g_i2cSlaveSendInfo[index].pointer = 0;
            I2C_WriteDataReg(I2Cx, g_i2cSlaveSendInfo[index].sendBuff[g_i2cSlaveSendInfo[index].pointer++]);
        }
        else
        {
            I2Cx->STATUS_1.STATUS_1_Byte = I2C_STATUS_1_TCF_MASK;   /* Write 1 to clear TCF */
        }
    }
    else
    {
        if (I2C_GetStatus1(I2Cx) & I2C_STATUS_1_SRW_MASK)
        {
            /* It requires ACK from master */
            if (I2C_GetStatus1(I2Cx) & I2C_STATUS_1_RACK_MASK)
            {
                /* Last byte data, receives NACK */
                I2Cx->STATUS_1.STATUS_1_Byte = I2C_STATUS_1_TCF_MASK;   /* Write 1 to clear TCF */
                g_i2cStatus[index] |= I2C_STATUS_NACK;
            }
            else
            {
                if (g_i2cSlaveSendInfo[index].pointer < g_i2cSlaveSendInfo[index].length)
                {
                    I2C_WriteDataReg(I2Cx, g_i2cSlaveSendInfo[index].sendBuff[g_i2cSlaveSendInfo[index].pointer++]);
                }
                else
                {
                    /* Tx buff is underflow, Slave clock streching or write 0xff to master. */
                }
            }
        }
        else
        {
            if (g_i2cSlaveReceiveInfo[index].freeLength != 0)
            {
                g_i2cSlaveReceiveInfo[index].receiveBuff[g_i2cSlaveReceiveInfo[index].tail++] = I2C_ReadDataReg(I2Cx);
                if (g_i2cSlaveReceiveInfo[index].tail >= g_i2cSlaveReceiveBufferLength[index])
                {
                    g_i2cSlaveReceiveInfo[index].tail = 0;
                }
                g_i2cSlaveReceiveInfo[index].freeLength--;
            }
            else
            {
                /* Rx buff is overflow, Slave clock streching or dummy read. */
            }

        }
    }
}

/**
* I2C_SlaveWrite
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @Param[in] wrBuff: pointer to the user-defined send buffer array.
* @param[in] length: the user-defined send bytes length.
* @return 1: success, 0: send too many data at a time.
*
* @brief  I2C write function when act as a slave
*/
int32_t I2C_SlaveWrite(I2C_Type *I2Cx, uint8_t *wrBuff, uint32_t length)
{
    uint8_t index = ((uint32_t)I2Cx - (uint32_t)I2C1) >> 12;
    uint8_t errorStatus = 0;

    if (length > g_i2cSlaveSendBufferLength[index])
    {
        errorStatus = 0;
    }
    else
    {
        I2C_DisableInt(I2Cx);
        g_i2cSlaveSendInfo[index].length = length;
        g_i2cSlaveSendInfo[index].sendBuff = wrBuff;
        I2C_EnableInt(I2Cx);
        errorStatus = 1;
    }

    return errorStatus;
}

/**
* I2C_SlaveRead
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @Param[in] rdBuff: pointer to the user-defined receive buffer array.
* @param[in] length: the user-defined receive bytes length.
* @return 0: success, other: error value
*
* @brief  I2C read function when act as a slave
*/
int32_t I2C_SlaveRead(I2C_Type *I2Cx, uint8_t *rdBuff, uint32_t *length)
{
    uint32_t tmpReadDataLength = 0;
    uint8_t index = ((uint32_t)I2Cx - (uint32_t)I2C1) >> 12;

    I2C_DisableInt(I2Cx);
    while (g_i2cSlaveReceiveInfo[index].freeLength < g_i2cSlaveReceiveBufferLength[index])
    {
        rdBuff[tmpReadDataLength++] = g_i2cSlaveReceiveInfo[index].receiveBuff[g_i2cSlaveReceiveInfo[index].head++];
        if (g_i2cSlaveReceiveInfo[index].head >= g_i2cSlaveReceiveBufferLength[index])
        {
            g_i2cSlaveReceiveInfo[index].head = 0;
        }
        g_i2cSlaveReceiveInfo[index].freeLength++;
    }
    I2C_EnableInt(I2Cx);
    *length = tmpReadDataLength;

    return 0;
}

/**
* I2C_MasterWriteInt
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] slaveAddress: I2C slave peripheral address.
* @param[in] wrBuff: pointer to the user-defined send buffer array.
* @param[in] dataLength: the user-defined send buffer length.
* @return 0: success, other: error value
*
* @brief  I2C Master start a complete send sequence by interrupt: "start + address + data0~dataN + stop"
*/
int32_t I2C_MasterWriteInt(I2C_Type *I2Cx, uint32_t slaveAddress, uint8_t *wrBuff, uint32_t dataLength)
{
    uint32_t errorStatus = 0;
    uint8_t index = ((uint32_t)I2Cx - (uint32_t)I2C1) >> 12;
    uint32_t timeout = 0;

    if (I2C_IsBusy(I2Cx))
    {
        errorStatus = I2C_ERROR_BUS_BUSY;
    }
    else
    {
        I2C_DisableInt(I2Cx);
        g_i2cMasterSendInfo[index].pointer = 0;
        g_i2cMasterSendInfo[index].length = dataLength;
        while (((I2Cx->STATUS_1.STATUS_1_Byte & 0x28) != I2C_STATUS_1_READY_MASK) && (timeout < I2C_READY_STATUS_TIMEOUT))
        {
            timeout ++;
        }
        if (timeout >= I2C_READY_STATUS_TIMEOUT)
        {
            errorStatus |= I2C_ERROR_START_NO_BUSY_FLAG;
        }
        errorStatus |= I2C_Start(I2Cx);
        errorStatus |= I2C_WriteOneByte(I2Cx, ((uint8_t)slaveAddress << 1) | I2C_WRITE);
        if (errorStatus == I2C_ERROR_NULL)
        {
            memcpy((void *)&g_i2cMasterSendInfo[index].sendBuff[0],
                   (void *)wrBuff, dataLength);
        }
        else
        {
            g_i2cStatus[index] |= I2C_STATUS_TX_FINISH;
            I2C_Stop(I2Cx);
        }
        I2C_EnableInt(I2Cx);
    }

    return errorStatus;
}

/**
* I2C_MasterReadInt
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] slaveAddress: I2C slave peripheral address.
* @param[in] rdBuff: pointer to the user-defined receive buffer array.
* @param[in] dataLength: the user-defined receive buffer length.
* @return 0: success, other: error value
*
* @brief  I2C Master start a complete receive sequence by interrupt: "start + address + data0~dataN + stop"
*/
int32_t I2C_MasterReadInt(I2C_Type *I2Cx, uint32_t slaveAddress, uint8_t *rdBuff, uint32_t dataLength)
{
    uint32_t errorStatus = 0;
    uint8_t index = ((uint32_t)I2Cx - (uint32_t)I2C1) >> 12;
    uint32_t timeout = 0;

    if (I2C_IsBusy(I2Cx))
    {
        errorStatus = I2C_ERROR_BUS_BUSY;
    }
    else
    {
        I2C_DisableInt(I2Cx);
        g_i2cMasterReceiveInfo[index].pointer = 0;
        g_i2cMasterReceiveInfo[index].length = dataLength;
        while (((I2Cx->STATUS_1.STATUS_1_Byte & 0x28) != I2C_STATUS_1_READY_MASK) && (timeout < I2C_READY_STATUS_TIMEOUT))
        {
            timeout ++;
        }
        if (timeout >= I2C_READY_STATUS_TIMEOUT)
        {
            errorStatus |= I2C_ERROR_START_NO_BUSY_FLAG;
        }
        errorStatus = I2C_Start(I2Cx);
        errorStatus = I2C_WriteOneByte(I2Cx, ((uint8_t)slaveAddress << 1) | I2C_READ);
        /* dummy read one byte to switch to Rx mode */
        if (dataLength == 1)
        {
            I2C_ReadOneByte(I2Cx, &rdBuff[0], I2C_SEND_NACK);   /* NACK will influence next transmission. */
        }
        else
        {
            I2C_ReadOneByte(I2Cx, &rdBuff[0], I2C_SEND_ACK);
        }
        if (errorStatus == I2C_ERROR_NULL)
        {
            if (dataLength == 1)
            {
                g_i2cStatus[index] |= I2C_STATUS_RX_FINISH;
                errorStatus = I2C_ReadLastOneByte(I2Cx, &rdBuff[0], I2C_SEND_NACK);
                errorStatus = I2C_Stop(I2Cx);
            }
        }
        else
        {
            g_i2cStatus[index] |= I2C_STATUS_RX_FINISH;
            I2C_Stop(I2Cx);
        }
        I2C_EnableInt(I2Cx);
    }

    return errorStatus;
}

/**
* I2C_MasterCheckReadLength
*
* @param[in] I2Cx: x should be 1 or 2 to select the I2C peripheral.
* @param[in] rdBuff: pointer to the user-defined receive buffer array.
* @return 0: no data, other: pointer to the Master receive buffer array.
*
* @brief  check I2C Master read length by interrupt
*/
int32_t I2C_MasterCheckReadLength(I2C_Type *I2Cx, uint8_t *rdBuff)
{
    int32_t tmpPointer = 0;
    uint8_t index = ((uint32_t)I2Cx - (uint32_t)I2C1) >> 12;

    if (g_i2cMasterReceiveInfo[index].pointer != 0)
    {
        memcpy((void *) rdBuff,
               (void *)&g_i2cMasterReceiveInfo[index].receiveBuff[0],
               g_i2cMasterReceiveInfo[index].pointer);
        tmpPointer = g_i2cMasterReceiveInfo[index].pointer;
        g_i2cMasterReceiveInfo[index].pointer = 0;
    }
    else
    {
        /* don't receive all required data */
        tmpPointer =  0;
    }

    return tmpPointer;
}
