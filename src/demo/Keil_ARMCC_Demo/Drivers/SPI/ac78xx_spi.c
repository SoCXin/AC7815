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

#include "ac78xx_spi.h"
#include "ac78xx.h"


#define SPI_NUM 2

uint16_t *g_spiRxBuf[SPI_NUM] = {NULL};                 ///< SPIx Rx buffer pointer
uint16_t *g_spiTxBuf[SPI_NUM] = {NULL};                 ///< SPIx Tx buffer pointer
uint16_t g_spiRxBuffWrPointer[SPI_NUM] = {0};           ///< SPIx buffer receive pointer
uint16_t g_spiTxBuffRdPointer[SPI_NUM] = {0};           ///< SPIx buffer transmit pointer
uint32_t g_spiBuffSize[SPI_NUM] = {0};                  ///< SPIx buffer size data
uint32_t g_spiStatus[SPI_NUM] = {0};                    ///< SPIx work status

#ifdef SPI_INT_USE_CALLBACK
///< SPI Interrupt callback
SPI_EventCallBack g_spiCallbackArray[SPI_NUM] = {(SPI_EventCallBack)NULL};
#endif


const SPI_INFO g_spiInfoPool[] =
{
    {SPI1, SPI1_IRQn, CLK_SPI1, SRST_SPI1},
    {SPI2, SPI2_IRQn, CLK_SPI2, SRST_SPI2},
};

/**
* SPI_Initialize
*
* @param[in] SPIx: SPI type pointer
* @param[in] config: SPI configuration structure pointer
* @return    0: success, other: error value
*
* @brief  Initialize SPI module
*/
int32_t SPI_Initialize(SPI_Type *SPIx, SPI_ConfigType *config)
{
    uint8_t  spiIndex = ((uint32_t)SPIx - (uint32_t)SPI1) >> 12;

    CKGEN_Enable(g_spiInfoPool[spiIndex].CKGEN_SPIx, 1);       /* Enable SPI clock */
    CKGEN_SoftReset(g_spiInfoPool[spiIndex].SRST_SPIx, 1);     /* Reset SPI Module */

    if (config->setting.master == 1)
    {
        SPI_SetMSTR(SPIx);
    }
    else
    {
        SPI_ClrMSTR(SPIx);
    }

    if (config->setting.intEn)
    {
        NVIC_EnableIRQ(g_spiInfoPool[spiIndex].SPIx_IRQn);
    }
    else
    {
        NVIC_DisableIRQ(g_spiInfoPool[spiIndex].SPIx_IRQn);
    }

    SPI_SetBaud(SPIx, config->sckLow, config->sckHigh);   /* prescale is low + high + 2 */

    if (config->csHold)
    {
        SPI_CSHold(SPIx, config->csHold);
    }
    if (config->csSetup)
    {
        SPI_CSSetup(SPIx, config->csSetup);
    }
    if (config->setting.csIdle)
    {
        SPI_CSIdle(SPIx, config->setting.csIdle);
    }
    if (config->setting.frmSize)
    {
        SPI_SetFRMSize(SPIx, config->setting.frmSize);
    }
    if (config->setting.dmaRxEn)
    {
        SPI_EnableDMARx(SPIx);
    }
    if (config->setting.dmaTxEn)
    {
        SPI_EnableDMATx(SPIx);
    }

    SPI_SetCPHA(SPIx, config->setting.cpha);
    SPI_SetCPOL(SPIx, config->setting.cpol);
    SPI_SetTMSBF(SPIx, config->setting.txMsbFirst);
    SPI_SetRMSBF(SPIx, config->setting.rxMsbFirst);

    if (config->setting.csOutputEn)
    {
        SPI_SetCSOE(SPIx, config->setting.csOutputEn);
    }

    SPI_SetCS(SPIx, config->setting.continuousCSEn);
    SPI_SetModeFaultEnable(SPIx, config->setting.modeFaultEn);
    SPI_SetWakeupEnable(SPIx, config->setting.wakeUpEn);

    if (config->setting.spiEn)
    {
        SPI_Enable(SPIx);
    }
    else
    {
        SPI_Disable(SPIx);
    }

    return 0;
}

/**
* SPI_Uninitialize
*
* @param[in] SPIx: SPI type pointer
* @return    0: success, other: error value
*
* @brief  Uninitialize SPI module
*/
int32_t SPI_Uninitialize(SPI_Type *SPIx)
{
    uint8_t  spiIndex = ((uint32_t)SPIx - (uint32_t)SPI1) >> 12;

    NVIC_DisableIRQ(g_spiInfoPool[spiIndex].SPIx_IRQn);
    CKGEN_SoftReset(g_spiInfoPool[spiIndex].SRST_SPIx, 0);
    CKGEN_Enable(g_spiInfoPool[spiIndex].CKGEN_SPIx, 0);

    return 0;
}

/**
* SPI_InitCallback
*
* @param[in] SPIx: SPI type pointer
* @return    0: success, other: error value
*
* @brief  Initialize SPI slave callback settings
*/
int32_t SPI_InitCallback(SPI_Type *SPIx)
{
    uint8_t  spiIndex = ((uint32_t)SPIx - (uint32_t)SPI1) >> 12;

#ifdef SPI_INT_USE_CALLBACK
    SPI_SetEventCallback(SPIx, SPI_Callback);
#endif

    g_spiRxBuf[spiIndex] = NULL;
    g_spiTxBuf[spiIndex] = NULL;
    g_spiRxBuffWrPointer[spiIndex] = 0;
    g_spiTxBuffRdPointer[spiIndex] = 0;
    g_spiStatus[spiIndex] = SPI_STATUS_IDLE;

    return 0;
}

/**
* SPI_GetTransferStatus
*
* @param[in] SPIx: SPI type pointer
* @return    SPI transfer status
*
* @brief  Get SPI slave transfer status
*/
int32_t SPI_GetTransferStatus(SPI_Type *SPIx)
{
    uint8_t  spiIndex = ((uint32_t)SPIx - (uint32_t)SPI1) >> 12;

    return g_spiStatus[spiIndex];
}
/**
* SPI_ResetTransferStatus
*
* @param[in] SPIx: SPI type pointer
* @return    0: success, other: error value
*
* @brief  Reset SPI transfer status
*/
int32_t SPI_ResetTransferStatus(SPI_Type *SPIx)
{
    uint8_t  spiIndex = ((uint32_t)SPIx - (uint32_t)SPI1) >> 12;

    g_spiStatus[spiIndex] = SPI_STATUS_IDLE;

    return 0;
}

#ifdef SPI_INT_USE_CALLBACK

/**
* SPI_SetEventCallback
*
* @param[in] SPIx: SPI type pointer
* @param[in] callback: SPI callback type function pointer
* @return    0: success, other: error value
*
* @brief  Set SPI callback function
*/
int32_t SPI_SetEventCallback(SPI_Type *SPIx, SPI_EventCallBack callback)
{
    uint8_t  spiIndex = ((uint32_t)SPIx - (uint32_t)SPI1) >> 12;

    g_spiCallbackArray[spiIndex] = callback;

    return 0;
}
#endif

/**
 * SPI_Callback
 *
 * @param[in] SPIx:SPI type pointer
 * @param[in] wparam:reserved for customers' callback fucntion
 * @param[in] lparam:reserved for customers' callback fucntion
 * @return    0: success; other: error
 *
 * @brief SPI callback function which handles Tx and Rx in interrupt
 */
int32_t SPI_Callback(SPI_Type *SPIx, uint32_t wparam, uint32_t lparam)
{
    if (SPI_IsMaster(SPIx))
    {
        SPI_MasterIntHandler(SPIx, wparam, lparam);
    }
    else
    {
        SPI_SlaveIntHandler(SPIx, wparam, lparam);
    }

    return 0;

}

/**
* SPI_MasterIntHandler
*
* @param[in] SPIx: SPI type pointer
* @param[in] wparam: reserved for customers' callback fucntion
* @param[in] lparam: reserved for customers' callback fucntion
* @return    0: success, other: error value
*
* @brief  Set SPI master callback function
*/
int32_t SPI_MasterIntHandler(SPI_Type *SPIx, uint32_t wparam, uint32_t lparam)
{
    uint8_t  spiIndex = ((uint32_t)SPIx - (uint32_t)SPI1) >> 12;

    if (SPI_IsTxUF(SPIx))
    {
        SPIx->STATUS.TXUF = 1;
        g_spiStatus[spiIndex] |= SPI_STATUS_TX_UNDERFLOW;
    }

    if (SPI_IsRxOF(SPIx))
    {
        SPIx->STATUS.RXOF = 1;
        g_spiStatus[spiIndex] |= SPI_STATUS_RX_OVERFLOW;
    }

    if (SPI_IsRxFF(SPIx))
    {
        if (g_spiRxBuffWrPointer[spiIndex] < g_spiBuffSize[spiIndex])
        {
            g_spiRxBuf[spiIndex][g_spiRxBuffWrPointer[spiIndex]++] = SPI_ReadDataReg(SPIx);
        }

        if (g_spiRxBuffWrPointer[spiIndex] >= g_spiBuffSize[spiIndex])
        {
            SPI_DisableRxFInt(SPIx);
            SPI_ReadDataReg(SPIx);
            g_spiStatus[spiIndex] |= SPI_STATUS_RX_OVERFLOW;
        }
    }

    if (SPI_IsTxEF(SPIx))
    {
        if (g_spiTxBuffRdPointer[spiIndex] < g_spiBuffSize[spiIndex])
        {
            SPI_WriteDataReg(SPIx, g_spiTxBuf[spiIndex][g_spiTxBuffRdPointer[spiIndex]++]);
        }

        if (g_spiTxBuffRdPointer[spiIndex] >= g_spiBuffSize[spiIndex])
        {
            SPI_DisableTxEInt(SPIx);
            g_spiStatus[spiIndex] |= SPI_STATUS_TX_UNDERFLOW;
        }
    }

    if (SPI_IsModeFault(SPIx))
    {
        SPI_SoftwareReset(SPIx);
        g_spiStatus[spiIndex] |= SPI_STATUS_RX_OVERFLOW;
    }

    return 0;
}

/**
* SPI_SlaveIntHandler
*
* @param[in] SPIx: SPI type pointer
* @param[in] wparam: reserved for customers' callback fucntion
* @param[in] lparam: reserved for customers' callback fucntion
* @return    0: success, other: error value
*
* @brief  Set SPI slave callback function
*/
int32_t SPI_SlaveIntHandler(SPI_Type *SPIx, uint32_t wparam, uint32_t lparam)
{
    uint8_t  spiIndex = ((uint32_t)SPIx - (uint32_t)SPI1) >> 12;

    if (SPI_IsTxUF(SPIx))
    {
        SPIx->STATUS.TXUF = 1;
        SPI_DisableTxEInt(SPIx);
        g_spiStatus[spiIndex] |= SPI_STATUS_TX_UNDERFLOW;
    }

    if (SPI_IsRxOF(SPIx))
    {
        SPIx->STATUS.RXOF = 1;
        SPI_DisableRxFInt(SPIx);
        g_spiStatus[spiIndex] |= SPI_STATUS_RX_OVERFLOW;
    }

    if (SPI_IsRxFF(SPIx))
    {
        if (g_spiRxBuffWrPointer[spiIndex] < g_spiBuffSize[spiIndex])
        {
            g_spiRxBuf[spiIndex][g_spiRxBuffWrPointer[spiIndex]++] = SPI_ReadDataReg(SPIx);
        }

        if (g_spiRxBuffWrPointer[spiIndex] >= g_spiBuffSize[spiIndex])
        {
            SPI_DisableRxFInt(SPIx);
            SPI_ReadDataReg(SPIx);
            g_spiStatus[spiIndex] |= SPI_STATUS_RX_OVERFLOW;
        }
    }

    if (SPI_IsTxEF(SPIx))
    {
        if (g_spiTxBuffRdPointer[spiIndex] < g_spiBuffSize[spiIndex])
        {
            SPI_WriteDataReg(SPIx, g_spiTxBuf[spiIndex][g_spiTxBuffRdPointer[spiIndex]++]);
        }
        if (g_spiTxBuffRdPointer[spiIndex] >= g_spiBuffSize[spiIndex])
        {
            SPI_DisableTxEInt(SPIx);
            g_spiStatus[spiIndex] |= SPI_STATUS_TX_UNDERFLOW;
        }
    }

    return 0;
}

#ifdef SPI_INT_USE_CALLBACK

/**
 * SPI1_IRQHandler
 *
 * @param[in]  none
 * @return     none
 *
 * @brief  override the SPI1_IRQHandler
 */
void SPI1_IRQHandler(void)
{
    if (g_spiCallbackArray[0])
    {
        g_spiCallbackArray[0](SPI1, 0, 0);
    }
}

/**
 * SPI2_IRQHandler
 *
 * @param[in] none
 * @return    none
 *
 * @brief  override the SPI2_IRQHandler
 */
void SPI2_IRQHandler(void)
{
    if (g_spiCallbackArray[1])
    {
        g_spiCallbackArray[1](SPI2, 0, 0);
    }
}

#endif

/**
* SPI_TransferPoll
*
* @param[in] SPIx: SPI type pointer
* @param[in] rdBuff: Read buffer pointer
* @param[in] wrBuff: Write buffer pointer
* @param[in] length: Data length
* @return    0: success, other: error value
*
* @brief  SPI transmission by polling
*/
int32_t SPI_TransferPoll(SPI_Type *SPIx, uint16_t *rdBuff, uint16_t *wrBuff, uint32_t length)
{
    uint32_t  i = 0;

    if (!length)
    {
        return 1;
    }

    for (i = 0; i < length; i++)
    {
        while (!SPI_IsTxEF(SPIx));
        SPI_WriteDataReg(SPIx, wrBuff[i]);
        while (!SPI_IsRxFF(SPIx));
        rdBuff[i] = SPI_ReadDataReg(SPIx);
    }

    while ((SPI_IsBusy(SPIx)));
    SPI_CSRelease(SPIx);

    return 0;
}

/**
* SPI_RxOnlyModeInt
*
* @param[in] SPIx: SPI type pointer
* @param[in] rdBuff: Read buffer pointer
* @param[in] wrBuff: Write buffer pointer
* @param[in] length: Data length
* @return    0: success, other: error value
*
* @brief  SPI Receive in rx only mode by interrupt
*/
int32_t SPI_RxOnlyModeInt(SPI_Type *SPIx, uint16_t* rdBuff, uint16_t * wrBuff, uint32_t length)
{
    uint8_t  spiIndex = ((uint32_t)SPIx - (uint32_t)SPI1) >> 12;

    if (!length)
    {
        return 1;
    }

    g_spiBuffSize[spiIndex] = length;
    g_spiRxBuf[spiIndex] = rdBuff;
    g_spiTxBuf[spiIndex] = wrBuff;
    g_spiRxBuffWrPointer[spiIndex] = 0;
    g_spiTxBuffRdPointer[spiIndex] = length - 1;
    g_spiStatus[spiIndex] = SPI_STATUS_BUSY;
    SPI_EnableTxUInt(SPIx);
    SPI_EnableRxOInt(SPIx);
    SPI_EnableRxFInt(SPIx);
    SPI_EnableModeEIEInt(SPIx);

    return 0;
}

/**
* SPI_TransferInt
*
* @param[in] SPIx: SPI type pointer
* @param[in] rdBuff: Read buffer pointer
* @param[in] wrBuff: Write buffer pointer
* @param[in] length: Data length
* @return    0: success, other: error value
*
* @brief  SPI transmission by interrupt
*/
int32_t SPI_TransferInt(SPI_Type *SPIx, uint16_t* rdBuff, uint16_t * wrBuff, uint32_t length)
{
    uint8_t  spiIndex = ((uint32_t)SPIx - (uint32_t)SPI1) >> 12;

    if (!length)
    {
        return 1;
    }

    g_spiBuffSize[spiIndex] = length;
    g_spiRxBuf[spiIndex] = rdBuff;
    g_spiTxBuf[spiIndex] = wrBuff;
    g_spiRxBuffWrPointer[spiIndex] = 0;
    g_spiTxBuffRdPointer[spiIndex] = 0;
    g_spiStatus[spiIndex] = SPI_STATUS_BUSY;
    SPI_EnableTxUInt(SPIx);
    SPI_EnableRxOInt(SPIx);
    SPI_EnableRxFInt(SPIx);
    SPI_EnableTxEInt(SPIx);
    SPI_EnableModeEIEInt(SPIx);

    return 0;
}

/**
* SPI_CheckTransferIntStatus
*
* @param[in] SPIx: SPI type pointer
* @return    0: success, -1: timeout error
*
* @brief  Check SPI transmission by interrupt
*/
int32_t SPI_CheckTransferIntStatus(SPI_Type *SPIx)
{
    uint32_t timer = 0;

    while (!(SPI_GetTransferStatus(SPIx) & SPI_STATUS_RX_OVERFLOW))
    {
        timer++;
        if (timer > 0xFFFFFFF)
        {
            SPI_ResetTransferStatus(SPIx);
            return -1;
        }
    }

    SPI_ResetTransferStatus(SPIx);

    return 0;
}

/**
* SPI_MasterReleaseCS
*
* @param[in] SPIx: SPI type pointer
* @return    0: success, other: error value
*
* @brief  Release SPI Master CS to stop continuous selection of Slave
*/
int32_t SPI_MasterReleaseCS(SPI_Type *SPIx)
{
    while ((SPI_IsBusy(SPIx)));
    SPI_CSRelease(SPIx);

    return 0;
}

/**
* SPI_WriteInt
*
* @param[in] SPIx: SPI type pointer
* @param[in] wrBuff: Write buffer pointer
* @param[in] length: Data length
* @return    0: success, other: error value
*
* @brief  SPI write by interrupt, ignore read
*/
int32_t SPI_WriteInt(SPI_Type *SPIx, uint16_t * wrBuff, uint32_t length)
{
    uint8_t  spiIndex = ((uint32_t)SPIx - (uint32_t)SPI1) >> 12;

    if (!length)
    {
        return 1;
    }

    g_spiBuffSize[spiIndex] = length;
    g_spiTxBuf[spiIndex] = wrBuff;
    g_spiTxBuffRdPointer[spiIndex] = 0;
    g_spiStatus[spiIndex] = SPI_STATUS_BUSY;
    SPI_EnableTxUInt(SPIx);
    SPI_EnableTxEInt(SPIx);

    return 0;
}

/**
* SPI_ReadInt
*
* @param[in] SPIx: SPI type pointer
* @param[in] rdBuff: Read buffer pointer
* @param[in] length: Data length
* @return    0: success, other: error value
*
* @brief  SPI read by interrupt, ignore write
*/
int32_t SPI_ReadInt(SPI_Type *SPIx, uint16_t * rdBuff, uint32_t length)
{
    uint8_t  spiIndex = ((uint32_t)SPIx - (uint32_t)SPI1) >> 12;

    if (!length)
    {
        return 1;
    }

    g_spiBuffSize[spiIndex] = length;
    g_spiRxBuf[spiIndex] = rdBuff;
    g_spiRxBuffWrPointer[spiIndex] = 0;
    g_spiStatus[spiIndex] = SPI_STATUS_BUSY;
    SPI_EnableRxOInt(SPIx);
    SPI_EnableRxFInt(SPIx);

    return 0;
}

/**
* SPI_WritePoll
*
* @param[in] SPIx: SPI type pointer
* @param[in] wrBuff: Write buffer pointer
* @param[in] length: Data length
* @return    0: success, other: error value
*
* @brief  SPI write by polling, ignore read
*/
int32_t SPI_WritePoll(SPI_Type *SPIx, uint16_t *wrBuff, uint32_t length)
{
    uint32_t  i;

    if (!length)
    {
        return 1;
    }

    for (i = 0; i < length; i++)
    {
        while (!SPI_IsTxEF(SPIx));
        SPI_WriteDataReg(SPIx, wrBuff[i]);
    }

    while ((SPI_IsBusy(SPIx)));
    SPI_CSRelease(SPIx);

    return 0;
}

/**
* SPI_ReadPoll
*
* @param[in] SPIx: SPI type pointer
* @param[in] rdBuff: Read buffer pointer
* @param[in] Length: Data length
* @return    0: success, other: error value
*
* @brief  SPI read by polling, ignore write
*/
int32_t SPI_ReadPoll(SPI_Type *SPIx, uint16_t *rdBuff, uint32_t length)
{
    uint32_t  i;

    if (!length)
    {
        return 1;
    }
    for (i = 0; i < length; i++)
    {
        while (!SPI_IsRxFF(SPIx));
        rdBuff[i] = SPI_ReadDataReg(SPIx);
    }

    while ((SPI_IsBusy(SPIx)));
    SPI_CSRelease(SPIx);

    return 0;
}

/**
 * SPI_ReadPollInRxOnlyMode
 *
 * @param[in] SPIx: SPI type pointer
 * @param[in] rdBuff: Read buffer pointer
 * @param[in] Length: Data length
 * @return    0: success, other: error value
 *
 * @brief  SPI read by polling, in rx only mode.
 */
int32_t SPI_ReadPollInRxOnlyMode(SPI_Type *SPIx, uint16_t *rdBuff, uint32_t length)
{
    uint32_t  i;

    if (!length)
    {
        return 1;
    }

    SPI_RxOnlyEnable(SPIx);
    SPI_RxOnlyModeTrig(SPIx);

    for (i = 0; i < length; i++)
    {
        if (i == (length - 1))
        {
            SPI_RxOnlyDisable(SPIx);
        }

        while (!SPI_IsRxFF(SPIx));
        rdBuff[i] = SPI_ReadDataReg(SPIx);
    }

    while ((SPI_IsBusy(SPIx)));
    SPI_CSRelease(SPIx);

    return 0;
}


