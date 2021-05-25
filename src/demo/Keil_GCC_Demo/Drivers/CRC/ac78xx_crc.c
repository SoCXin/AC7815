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

#include "ac78xx_crc.h"
#include "ac78xx.h"

/**
* CRC_Initialize
*
* @param[in] config: CRC configuration struct pointer
* @return 0: success, other: error value
*
* @brief  Initialize CRC module
*/
int32_t CRC_Initialize(CRC_ConfigType *config)
{
    CKGEN_Enable(CLK_CRC, 1);
    CKGEN_SoftReset(SRST_CRC, 1);
    CKGEN_SoftReset(SRST_DMA_AHB, 1);
    CRC0->CTRL_8BIT.TCRC = config->CRCType;
    CRC0->CTRL_8BIT.TOTR = config->transposeReadType;
    CRC0->CTRL_8BIT.TOTW = config->transposeWriteType;
    CRC0->CTRL_8BIT.FXOR = config->finalXOR;

    if (config->CRCType)
    {
        CRC0->GPOLY = config->poly;
    }
    else
    {
        CRC0->GPOLY_16BIT.GPOLYL = config->poly;
    }

    return 0;
}

/**
* CRC_Uninitialize
*
* @param[in] none
* @return 0:success, other: error value
*
* @brief  Uninitialize CRC module
*/
int32_t CRC_Uninitialize(void)
{
    CKGEN_Enable(CLK_CRC, 0);
    CKGEN_SoftReset(SRST_CRC, 0);

    return 0;
}

/**
* CRC_Cal16
*
* @param[in] seed: CRC seed
* @param[in] msg: the pointer of CRC data
* @param[in] sizeBytes: data length
* @return CRC result
*
* @brief  Calculate CRC-16
*/
uint32_t CRC_Cal16(uint32_t seed, const uint8_t *msg, uint32_t sizeBytes)
{
    uint32_t dataOut = 0;
    uint8_t  *CRCBytes = NULL;
    uint32_t sizeDWords = 0;
    uint32_t i = 0, j = 0;

#if defined(BYTE_ENABLES_2) || defined(BYTE_ENABLES_4)
    uint32_t dataIn = 0;
#endif

    CRC0->CTRL_8BIT.WAS  = 1;                       //Set WAS=1 to input seed
    CRC0->DATA_16BIT.DATAL = seed;

    CRC0->CTRL_8BIT.WAS  = 0;                       // Set WAS=0 to input data
#if (!defined(BYTE_ENABLES_2)) && (!defined(BYTE_ENABLES_4))
    sizeDWords = sizeBytes >> 2;
    // write one byte
    CRCBytes = (uint8_t*)(&CRC0->DATA_8BIT.DATA0);
    for (; i < sizeDWords; i++)
    {
        *CRCBytes = msg[j];
        *(CRCBytes + 1) = msg[j + 1];
        *(CRCBytes + 2) = msg[j + 2];
        *(CRCBytes + 3) = msg[j + 3];
        j = j + 4;
    }
    for (; j < sizeBytes;)
    {
        CRCBytes = (uint8_t*)(&CRC0->DATA_8BIT.DATA0);
        *CRCBytes = msg[j++];
    }
#elif defined(BYTE_ENABLES_2)
    sizeDWords = sizeBytes >> 2;
    for (i = 0; i < sizeDWords; i++)
    {
        dataIn = (msg[j] << 8) | (msg[j + 1]);
        j += 2;
        CRC0->DATA_16BIT.DATAL = dataIn;
        dataIn = (msg[j] << 8) | (msg[j + 1]);
        j += 2;
        CRC0->DATA_16BIT.DATAH = dataIn;
    }
    if((sizeBytes - j) >= 2 )
    {
        dataIn = (msg[j] << 8) | (msg[j + 1]);
        j += 2;
        CRC0->DATA_16BIT.DATAH = dataIn;
    }
    for (; j < sizeBytes;)
    {
        CRCBytes = (uint8_t*)(&CRC0->DATA_8BIT.DATA0);
        *CRCBytes = msg[j++];
    }
#elif defined(BYTE_ENABLES_4)
    sizeDWords = sizeBytes >> 2;
    for (i = 0; i < sizeDWords; i++)
    {
        dataIn = msg[j + 3] | (msg[j + 2] << 8) | (msg[j + 1] << 16) | (msg[j] << 24);
        j += 4;
        CRC0->DATA = dataIn;
    }
    for (; j < sizeBytes;)
    {
        CRCBytes = (uint8_t*)(&CRC0->DATA_8BIT.DATA0);
        *CRCBytes = msg[j++];
    }
#endif
    dataOut = CRC0->DATA_16BIT.DATAL;

    return dataOut;
}

/**
* CRC_Cal32
*
* @param[in] seed: CRC seed
* @param[in] msg: the pointer of CRC data
* @param[in] sizeBytes: data length
* @return CRC result
*
* @brief  Calculate CRC-32
*/
uint32_t CRC_Cal32(uint32_t seed, const uint8_t *msg, uint32_t sizeBytes)
{
    uint32_t dataOut = 0;
    uint8_t  *CRCBytes = NULL;
    uint32_t sizeDWords = 0;
    uint32_t i = 0, j = 0;

#if defined(BYTE_ENABLES_2) || defined(BYTE_ENABLES_4)
    uint32_t dataIn = 0;
#endif

    // Set WAS=1 to input seed
    CRC0->CTRL_8BIT.WAS = 1;
    CRC0->DATA = seed;

    // Set WAS=0 to input data
    CRC0->CTRL_8BIT.WAS = 0;

#if (!defined(BYTE_ENABLES_2)) && (!defined(BYTE_ENABLES_4))
    sizeDWords = sizeBytes >> 2;
    // write one byte
    CRCBytes = (uint8_t*)(&CRC0->DATA_8BIT.DATA0);
    for (; i < sizeDWords; i++)
    {
        *CRCBytes = msg[j];
        *(CRCBytes + 1) = msg[j + 1];
        *(CRCBytes + 2) = msg[j + 2];
        *(CRCBytes + 3) = msg[j + 3];
        j = j + 4;
    }
    for (; j < sizeBytes;)
    {
        CRCBytes = (uint8_t*)(&CRC0->DATA_8BIT.DATA0);
        *CRCBytes = msg[j++];
    }
#elif defined(BYTE_ENABLES_2)
    sizeDWords = sizeBytes >> 2;
    for (i = 0; i < sizeDWords; i++)
    {
        dataIn = (msg[j] << 8) | (msg[j + 1]);
        j += 2;
        CRC0->DATA_16BIT.DATAL = dataIn;
        dataIn = (msg[j] << 8) | (msg[j + 1]);
        j += 2;
        CRC0->DATA_16BIT.DATAH = dataIn;
    }
    if((sizeBytes - j) >= 2 )
    {
        dataIn = (msg[j] << 8) | (msg[j + 1]);
        j += 2;
        CRC0->DATA_16BIT.DATAH = dataIn;
    }
    for (; j < sizeBytes;)
    {
        CRCBytes = (uint8_t*)(&CRC0->DATA_8BIT.DATA0);
        *CRCBytes = msg[j++];
    }
#elif defined(BYTE_ENABLES_4)
    sizeDWords = sizeBytes >> 2;
    for (i = 0; i < sizeDWords; i++)
    {
        dataIn = msg[j + 3] | (msg[j + 2] << 8) | (msg[j + 1] << 16) | (msg[j] << 24);
        j += 4;
        CRC0->DATA = dataIn;
    }
    for (; j < sizeBytes;)
    {
        CRCBytes = (uint8_t*)(&CRC0->DATA_8BIT.DATA0);
        *CRCBytes = msg[j++];
    }
#endif
    dataOut = CRC0->DATA;

    return dataOut;
}
