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
#include "ac78xx.h"
#include "ac78xx_serialflash.h"

static SFLASH_CFG_T s_sflashConfig;   ///< Serial flash configuration

///< Define serial flash feature
static SFLASHHW_VENDOR_T s_aVendorFlash[] =
{
    { 0x200000, 0x10000, 0x20, 0x20, 0x15, 0x03, 0x0B, 0x9F, 0xD8, 0xC7, 0x02, 0x00, 0x00, 0x00, 0x00,0x00,0x00, "ST(M25P16)" },
    { 0x1000000,0x10000, 0xC2, 0x20, 0x18, 0x03, 0x0B, 0x9F, 0xD8, 0xC7, 0x02, 0x00,0xBB,  0x00, 0x38,0xEB,0x6B, "MXIC(25L1280)" },
    { 0x400000, 0x10000, 0x1C, 0x30, 0x16, 0x03, 0x0B, 0x9F, 0xD8, 0xC7, 0x02, 0x00, 0x00, 0x00, 0x00,0xEB,0x00, "EON(EN25Q32)" },
    { 0x200000, 0x10000, 0x8C, 0x20, 0x15, 0x03, 0x0B, 0x9F, 0xD8, 0xC7, 0x02, 0xAD, 0x00, 0x00, 0x00,0x00,0x00, "ESMT(F25L16PA)" },
    { 0x200000, 0x10000, 0xEF, 0x40, 0x15, 0x03, 0x0B, 0x9F, 0xD8, 0xC7, 0x02, 0x00, 0x00, 0x3B, 0x00,0x00,0x00, "WINBOND(W25Q16)" },
    { 0x000000, 0x00000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,0x00,0x00,  "NULL Device" },
};

/**
* SFLASH_GetValidFlashInfoDrv
*
* @param[in]: none
* @return : Serial flash configuration
*
* @brief  get serial flash configuration
*/
SFLASH_CFG_T * SFLASH_GetValidFlashInfoDrv(void)
{
    return &s_sflashConfig;
}

/**
* SFLASH_PollingRegDrv
*
* @param[in] regAddr: Polling register address
* @param[in] compareValue: Compare register value
* @param[in] pollingValue: Polling value
* @return 0: polling fail, 1:polling success
*
* @brief  Polling register to confirm write register success
*/
int32_t SFLASH_PollingRegDrv(uint32_t regAddr, uint32_t compareValue, uint8_t pollingValue)
{
    uint32_t polling = 0;
    uint8_t  regValue = 0;

    while (1)
    {
        regValue = SFLASH_RREG32(regAddr);
        if (pollingValue == (regValue & compareValue))
        {
            break;
        }
        polling++;
        if (polling > SFLASH_POLLINGREG_COUNT)
        {
            return 0;
        }
    }
    return 1;
}

/**
* SFLASH_WriteFlashCmdDrv
*
* @param[in] commandValue: Comand value
* @param[in] pollingValue: Polling value
* @return 0: write command fail, 1:write command success
*
* @brief  Write command to serial flash controler
*/
int32_t SFLASH_WriteFlashCmdDrv(uint8_t commandValue, uint8_t pollingValue)
{
    uint32_t cmdAddrReg = 0;

    if (commandValue == 0x01)
    {
        SFLASH_SetAAICMDReg(commandValue);
        cmdAddrReg = (uint32_t)(&(SFLASH->REG_SF_AAICMD));
    }
    else
    {
        SFLASH_SetSFCMDReg(commandValue);
        cmdAddrReg = (uint32_t)(&(SFLASH->REG_SF_CMD));

    }
    if (SFLASH_PollingRegDrv(cmdAddrReg, pollingValue, 0) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/**
* SFLASH_GetIDDrv
*
* @param[in] *menuID: Point to serial flash manufacturer identification
* @param[in] *deviceID1: Point to serial flash device identification 1
* @param[in] *deviceID2: Point to serial flash device identification 2
* @return 0: read ID fail, 1:read ID success
*
* @brief  Read serial flash identification
*/
int32_t SFLASH_GetIDDrv(uint8_t *menuID, uint8_t *deviceID1, uint8_t *deviceID2)
{

    SFLASH_SetProgramData5Reg(SFLAHS_READID_CMD);
    SFLASH_SetProgramData4Reg(0x00);
    SFLASH_SetProgramData3Reg(0x00);
    SFLASH_SetProgramData2Reg(0x00);
    SFLASH_SetPrgBitCountReg(32);

    if (SFLASH_WriteFlashCmdDrv(0x04, 0x04) == 0)
    {
        return 0;
    }

    if ((menuID == NULL) ||
            (deviceID1 == NULL) ||
            (deviceID2 == NULL))
    {
        return 0;
    }
    if (deviceID2 != NULL)
    {
        *deviceID2 = SFLASH_RREG8(&SFLASH->REG_SF_SHREG0);
    }

    if (deviceID1 != NULL)
    {
        *deviceID1 = SFLASH_RREG8(&SFLASH->REG_SF_SHREG1);
    }

    if (menuID != NULL)
    {
        *menuID = SFLASH_RREG8(&SFLASH->REG_SF_SHREG2);
    }
    return 1;
}

/**
* SFLASH_DetectDrv
*
* @param[in] : none
* @return 0: detect serial flash fail, 1:detect serial flash success
*
* @brief  Detect serial flash
*/
int32_t SFLASH_DetectDrv(void)
{
    uint32_t tableIndex = 0;
    uint8_t menuID = 0, devID1 = 0, devID2 = 0;

    s_sflashConfig.FlashCount = 0;
    s_sflashConfig.ValidFlash[0] = 0;
    if (SFLASH_GetIDDrv(&menuID, &devID1, &devID2) == 0)
    {
        return 0;
    }

    while (s_aVendorFlash[tableIndex].menuID != (uint8_t)0x0)
    {
        if ((s_aVendorFlash[tableIndex].menuID == menuID) &&
                (s_aVendorFlash[tableIndex].devID1 == devID1) &&
                (s_aVendorFlash[tableIndex].devID2 == devID2))
        {
            s_sflashConfig.ValidFlash[0] = &(s_aVendorFlash[tableIndex]);
            s_sflashConfig.FlashCount++;
            break;
        }
        tableIndex++;
    }
    return 1;
}

/**
* SFLASHHW_SetFlashQuadEnable
*
* @param[in]  none
* @return 0: fail, 1: success
*
* @brief set enable quad mode
*/
int32_t SFLASHHW_SetFlashQuadEnable(void)
{
    
    SFLASH_SetProgramData5Reg(0x06);
    SFLASH_SetPrgBitCountReg(8);
    
    if (SFLASH_WriteFlashCmdDrv(0x04, 0x04) == 0)
    {
        return 0;
    }
    
    SFLASH_SetProgramData5Reg(0x01);
    SFLASH_SetProgramData4Reg(0x40);
    SFLASH_SetPrgBitCountReg(0x10);

    if (SFLASH_WriteFlashCmdDrv(0x04, 0x04) == 0)
    {
        return 0;
    }	
    if (SFLASH_WaitForWriteBusyDrv(SFLASH_WRITEBUSY_TIMEOUT) == 0)
    {	
        return 0;
    }
    
    return 1;
}

/**
* SFLASHHW_ReadDrv
*
* @param[in] sflashAddr: specifies the serial flash address to be readed
* @param[in] length: specifies the data length to readed
* @param[in] * dataBuffer: point to data buffer
* @return 0: read fail, 1:read success
*
* @brief  normal read data from serial flash
*/
int32_t SFLASHHW_ReadDrv(uint32_t sflashAddr, uint32_t length, uint8_t* dataBuffer)
{
    uint32_t readCount = 0;

    if (dataBuffer == NULL)
    {
        return 0;
    }

    SFLASH_SetCFG2Reg(0x0C);
    SFLASH_SetReadWritAddr2Reg(LO_BYTE(HI_WORD(sflashAddr)));
    SFLASH_SetReadWritAddr1Reg(HID_BYTE(LO_WORD(sflashAddr)));
    SFLASH_SetReadWritAddr0Reg(LO_BYTE(LO_WORD(sflashAddr)));

    for (readCount = 0; readCount < length; readCount++)
    {
        if (SFLASH_WriteFlashCmdDrv(0x81, 0x1) == 0)
        {
            return 0;
        }
        dataBuffer[readCount] = SFLASH_ReadFlashDataReg();
    }
    return 1;
}

/**
* SFLASHHW_FReadDrv
*
* @param[in] sflashAddr: specifies the serial flash address to be readed
* @param[in] length: specifies the data length to readed
* @param[in] * dataBuffer: point to data buffer
* @return 0: read fail, 1:read success
*
* @brief  fast read data from serial flash
*/
int32_t SFLASHHW_FReadDrv(uint32_t sflashAddr, uint32_t length, uint8_t* dataBuffer)
{
    uint8_t cfgValue = 0;
    int32_t opSuccess = 0;

    cfgValue = SFLASH_GetCFG1Reg();
    cfgValue |= 0x01;
    SFLASH_SetCFG1Reg(cfgValue);

    if (SFLASHHW_ReadDrv(sflashAddr, length, dataBuffer) != 0)
    {
        opSuccess = 1;
    }
    else
    {
        opSuccess = 0;
    }

    cfgValue &= 0xFE;
    SFLASH_SetCFG1Reg(cfgValue);
    return opSuccess;
}

/**
* SFLASHHW_DualReadDrv
*
* @param[in] sflashAddr: specifies the serial flash address to be readed
* @param[in] length: specifies the data length to readed
* @param[in] * dataBuffer: point to data buffer
* @return 0: read fail, 1:read success
*
* @brief  dual read data from serial flash
*/
int32_t SFLASHHW_DualReadDrv(uint32_t sflashAddr, uint32_t length, uint8_t* dataBuf)
{
    uint8_t uDualReg;
    int32_t opSuccess = 0;

    uDualReg = SFLASH_GetDualReg();
   
    SFLASH_SetDualReg(0x01);
    SFLASH_SetProgramData3Reg(0x3B);
    
    if (SFLASHHW_ReadDrv(sflashAddr, length, dataBuf) != 0)
    {
        opSuccess = 1;
    }
    else
    {	
        opSuccess = 0;
    }
    SFLASH_SetDualReg(uDualReg);    

    return opSuccess;
}

/**
* SFLASHHW_QuadReadDrv
*
* @param[in] sflashAddr: specifies the serial flash address to be readed
* @param[in] length: specifies the data length to readed
* @param[in] * dataBuffer: point to data buffer
* @return 0: read fail, 1:read success
*
* @brief  quad read data from serial flash
*/
int32_t SFLASHHW_QuadReadDrv(uint32_t sflashAddr, uint32_t length, uint8_t* dataBuf)
{
    uint8_t uDualReg;
    int32_t opSuccess = 0;

    uDualReg = SFLASH_GetDualReg();
    
    if (SFLASHHW_SetFlashQuadEnable() == 0)
    {	
        return 0;
    }
    SFLASH_SetDualReg(0x04);        
    SFLASH_SetProgramData4Reg(0x6B);
    if (SFLASHHW_ReadDrv(sflashAddr, length, dataBuf) != 0)
    {
        opSuccess = 1;
    }
    else
    {	
        opSuccess = 0;
    }
    SFLASH_SetDualReg(uDualReg);    

    return opSuccess;
}

/**
* SFLASHHW_4IOReadDrv
*
* @param[in] sflashAddr: specifies the serial flash address to be readed
* @param[in] length: specifies the data length to readed
* @param[in] * dataBuffer: point to data buffer
* @return 0: read fail, 1:read success
*
* @brief  four IO read data from serial flash
*/
int32_t SFLASHHW_4IOReadDrv(uint32_t sflashAddr, uint32_t length, uint8_t* dataBuf)
{

    uint8_t uDualReg;
    int32_t opSuccess = 0;

    uDualReg = SFLASH_GetDualReg();
    
    if (SFLASHHW_SetFlashQuadEnable() == 0)
    {	
        return 0;
    }
    
    SFLASH_SetDualReg(0x0C);
    SFLASH_SetProgramData4Reg(0xEB);
    if (SFLASHHW_ReadDrv(sflashAddr, length, dataBuf) != 0)
    {
        opSuccess = 1;
    }
    else
    {	
        opSuccess = 0;
    }
    SFLASH_SetDualReg(uDualReg);    

    return opSuccess;
}

/**
* SFLASHHW_EraseSectorDrv
*
* @param[in] sflashAddr: specifies the serial flash address to be erased
* @return 0: erase fail, 1:erase success
*
* @brief erases a specified serial flash page.
*/
int32_t SFLASHHW_EraseSectorDrv(uint32_t sflashAddr)
{
    if (SFLASH_WaitForWriteBusyDrv(SFLASH_WRITEBUSY_TIMEOUT) == 0)
    {
        return 0;
    }

    if (SFLASHHW_SetFlashWriteEnableDrv() == 0)
    {
        return 0;
    }

    // Execute sector erase command
    SFLASH_SetProgramData5Reg(SFLAHS_SECTOR_ERASE_CMD);
    SFLASH_SetProgramData4Reg(LO_BYTE(HI_WORD(sflashAddr)));
    SFLASH_SetProgramData3Reg(HID_BYTE(LO_WORD(sflashAddr)));
    SFLASH_SetProgramData2Reg(LO_BYTE(LO_WORD(sflashAddr)));
    SFLASH_SetPrgBitCountReg(32);

    if (SFLASH_WriteFlashCmdDrv(0x04, 0x04) == 0)
    {
        return 0;
    }

    // Can not use ISR mode, because there is not erase sector interrupt
    if (SFLASH_WaitForWriteBusyDrv(SFLASH_ERASESECTOR_TIMEOUT) == 0)
    {
        return 0;
    }
    return 1;
}

/**
* SFLASHHW_EraseChipDrv
*
* @param[in] none
* @return 0: erase fail, 1:erase success
*
* @brief erases whole serial flash page.
*/
int32_t SFLASHHW_EraseChipDrv(void)
{
    if (SFLASH_WaitForWriteBusyDrv(SFLASH_WRITEBUSY_TIMEOUT) == 0)
    {
        return 0;
    }

    if (SFLASHHW_SetFlashWriteEnableDrv() == 0)
    {
        return 0;
    }

    // Execute bulk erase command
    SFLASH_SetProgramData5Reg(SFLAHS_CHIP_ERASE_CMD);
    SFLASH_SetPrgBitCountReg(8);

    if (SFLASH_WriteFlashCmdDrv(0x04, 0x04) == 0)
    {
        return 0;
    }

    // Can not use ISR mode, because there is not erase sector interrupt
    if (SFLASH_WaitForWriteBusyDrv(SFLASH_ERASECHIP_TIMEOUT) == 0)
    {
        return 0;
    }
    return 1;
}

/**
* SFLASHHW_SetFlashWriteEnableDrv
*
* @param[in] none
* @return 0: fail, 1: success
*
* @brief enalbe serial flash to be configured.
*/
int32_t SFLASHHW_SetFlashWriteEnableDrv(void)
{
    SFLASH_SetProgramData5Reg(0x06);
    SFLASH_SetPrgBitCountReg(8);

    if (SFLASH_WriteFlashCmdDrv(0x04, 0x04) == 0)
    {
        return 0;
    }

    SFLASH_SetProgramData5Reg(0x01);
    SFLASH_SetProgramData4Reg(0x02);
    SFLASH_SetPrgBitCountReg(16);

    if (SFLASH_WriteFlashCmdDrv(0x04, 0x04) == 0)
    {
        return 0;
    }
    if (SFLASH_WaitForWriteBusyDrv(SFLASH_WRITEBUSY_TIMEOUT) == 0)
    {
        return 0;
    }

    SFLASH_SetProgramData5Reg(0x06);
    SFLASH_SetPrgBitCountReg(8);

    if (SFLASH_WriteFlashCmdDrv(0x04, 0x04) == 0)
    {
        return 0;
    }
    return 1;
}

/**
* SFLASH_WaitForWriteBusyDrv
*
* @param[in] timeoutValue:wait time out value
* @return 0: serial flash is busy, 1: serial flash is free
*
* @brief waiting for serial flash freee
*/
int32_t SFLASH_WaitForWriteBusyDrv(uint32_t timeoutValue)
{
    uint32_t realLength;
    uint8_t regValue;

    realLength = 0;
    while (1)
    {
        if (SFLASHHW_ReadFlashStatusDrv(&regValue) == 0)
        {
            return 0;
        }

        if (0 == (regValue & 0x1))
        {
            break;
        }

        realLength++;
        if (realLength > timeoutValue)
        {
            return 0;
        }
    }
    return 1;
}

/**
* SFLASHHW_ReadFlashStatusDrv
*
* @param[in] *sflashStatusl:point to flash status
* @return 0: read status fail, 1: read status success
*
* @brief read serial status
*/
int32_t SFLASHHW_ReadFlashStatusDrv(uint8_t *sflashStatusl)
{
    if (sflashStatusl == NULL)
    {
        return 0;
    }

    if (SFLASH_WriteFlashCmdDrv(0x02, 0x02) == 0)
    {
        return 0;
    }

    *sflashStatusl = SFLASH_ReadBackStatusReg();

    return 1;
}

/**
* SFLASHHW_PrefetchWriteDrv
*
* @param[in]  sflashAddr: specifies the serial flash address to be programed
* @param[in]      length: specifies the data length to be programed
* @param[in]    * dataBuffer: point to  the data buffer to be programed
* @return 0: program fail, 1: program success
*
* @brief  program serial flash with prefetch mode
*/
int32_t SFLASHHW_PrefetchWriteDrv(uint32_t sflashAddr, uint32_t length, const uint8_t* dataBuffer)
{
    uint32_t  realLength;
    uint32_t cmdAddrReg = 0;

    if (length == 0)
    {
        return 0;
    }

    if ((length & 0x03) != 0)
    {
        return 0;
    }

    if (dataBuffer == NULL)
    {
        return 0;
    }

    SFLASH_SetCFG2Reg(0x01);
    cmdAddrReg = (uint32_t)(&(SFLASH->REG_SF_CFG2));
    if (SFLASH_PollingRegDrv(cmdAddrReg, 0x01, 1) == 0)
    {
        return 0;
    }

    while (length > 0)
    {
        if (length >= SFLASH_WRBUF_SIZE)
        {
            realLength = SFLASH_WRBUF_SIZE;
        }
        else
        {
            realLength = length;
        }

        if (SFLASH_WriteBufferDrv(sflashAddr, realLength, dataBuffer) == 0)
        {
            SFLASH_SetCFG2Reg(0x0);
            cmdAddrReg = (uint32_t)(&(SFLASH->REG_SF_CFG2));
            if (SFLASH_PollingRegDrv(cmdAddrReg, 0x01, 0) == 0)
            {
                return 0;
            }
            return 0;
        }
        if (SFLASH_WriteFlashCmdDrv(0x10, 0x10) == 0)
        {
            return 0;
        }

        if (SFLASH_WaitForWriteBusyDrv(SFLASH_WRITEBUSY_TIMEOUT) == 0)
        {
            return 0;
        }
        sflashAddr += realLength;
        dataBuffer += realLength;
        length -= realLength;
    }

    SFLASH_SetCFG2Reg(0x0);
    cmdAddrReg = (uint32_t)(&(SFLASH->REG_SF_CFG2));
    if (SFLASH_PollingRegDrv(cmdAddrReg, 0x01, 0) == 0)
    {
        return 0;
    }
    return 1;
}

/**
 * SFLASHHW_SWriteDrv
 *
 * @param[in] sflashAddr: specifies the serial flash address to be programed
 * @param[in]      length: specifies the data length to be programed
 * @param[in]    * dataBuffer: point to  the data buffer to be programed
 * @return 0: program fail, 1: program success
 *
 * @brief  program serial flash with single byte mode
 */
int32_t SFLASHHW_SWriteDrv(uint32_t sflashAddr, uint32_t length, const uint8_t* dataBuffer)
{
    uint32_t counti = 0;

    if (length == 0)
    {
        return 0;
    }

    if (dataBuffer == NULL)
    {
        return 0;
    }

    for (counti = 0; counti < length; counti++)
    {
        if (SFLASH_WriteSingleByteDrv(sflashAddr + counti, dataBuffer[counti]) == 0)
        {
            return 0;
        }
    }
    return 1;
}

/**
 * SFLASHHW_AAIWriteDrv
 *
 * @param[in] sflashAddr: specifies the serial flash address to be programed
 * @param[in] length: specifies the data length to be programed
 * @param[in] * dataBuffer: point to  the data buffer to be programed
 * @return 0: program fail, 1: program success
 *
 * @brief  program serial flash with Auto Address Increment program mode
 */
int32_t SFLASHHW_AAIWriteDrv(uint32_t sflashAddr, uint32_t length, const uint8_t* dataBuffer)
{
    uint32_t realLength = 0;
    uint32_t cmdAddrReg = 0;

    if (length == 0)
    {
        return 0;
    }

    if ((length & 0x03) != 0)
    {
        return 0;
    }

    if (dataBuffer == NULL)
    {
        return 0;
    }

    SFLASH_SetCFG2Reg(0x41);
    cmdAddrReg = (uint32_t)(&(SFLASH->REG_SF_CFG2));
    if (SFLASH_PollingRegDrv(cmdAddrReg, 0x01, 1) == 0)
    {
        return 0;
    }

    while (length > 0)
    {
        if (length >= SFLASH_WRBUF_SIZE)
        {
            realLength = SFLASH_WRBUF_SIZE;
        }
        else
        {
            realLength = length;
        }

        if (SFLASH_WriteBufferDrv(sflashAddr, realLength, dataBuffer) == 0)
        {
            SFLASH_SetCFG2Reg(0x0);
            cmdAddrReg = (uint32_t)(&(SFLASH->REG_SF_CFG2));
            if (SFLASH_PollingRegDrv(cmdAddrReg, 0x0f, 0) == 0)
            {
                return 0;
            }
            return 0;
        }
        if (SFLASH_WriteFlashCmdDrv(0x01, 0x40) == 0)
        {
            return 0;
        }
        if (SFLASH_WaitForWriteBusyDrv(SFLASH_WRITEBUSY_TIMEOUT) == 0)
        {
            return 0;
        }
        sflashAddr += realLength;
        dataBuffer += realLength;
        length -= realLength;
    }
    SFLASH_SetCFG2Reg(0x0);
    cmdAddrReg = (uint32_t)(&(SFLASH->REG_SF_CFG2));
    if (SFLASH_PollingRegDrv(cmdAddrReg, 0x0f, 0) == 0)
    {
        return 0;
    }
    return 1;
}

/**
 * SFLASH_WriteBufferDrv
 *
 * @param[in] sflashAddr: specifies the serial flash address to be programed
 * @param[in] length: specifies the data length to be programed
 * @param[in] * dataBuffer: point to  the data buffer to be programed
 * @return 0: program fail, 1: program success
 *
 * @brief  program data buffer to serial flash
 */
int32_t SFLASH_WriteBufferDrv(uint32_t sflashAddr, uint32_t length, const uint8_t* dataBuffer)
{
    uint32_t counti = 0, countj = 0;
    uint32_t bufIndex = 0, writeData = 0;

    if (dataBuffer == NULL)
    {
        return 0;
    }

    SFLASH_SetReadWritAddr2Reg(LO_BYTE(HI_WORD(sflashAddr)));
    SFLASH_SetReadWritAddr1Reg(HID_BYTE(LO_WORD(sflashAddr)));
    SFLASH_SetReadWritAddr0Reg(LO_BYTE(LO_WORD(sflashAddr)));

    bufIndex = 0;
    for (counti = 0; counti < length; counti += 4)
    {
        for (countj = 0; countj < 4; countj++)
        {
            (*((uint8_t *)&writeData + countj)) = dataBuffer[bufIndex];
            bufIndex++;
        }
        SFLASH_SetProDataReg(writeData);
    }
    return 1;
}

/**
 * SFLASH_WriteSingleByteDrv
 *
 * @param[in] sflashAddr: specifies the serial flash address to be programed
 * @param[in] writeData: the data length to be programed
 * @return 0: program fail, 1: program success
 *
 * @brief program a single byte to serial flash
 */
int32_t SFLASH_WriteSingleByteDrv(uint32_t sflashAddr, int32_t writeData)
{
    SFLASH_SetReadWritAddr2Reg(LO_BYTE(HI_WORD(sflashAddr)));
    SFLASH_SetReadWritAddr1Reg(HID_BYTE(LO_WORD(sflashAddr)));
    SFLASH_SetReadWritAddr0Reg(LO_BYTE(LO_WORD(sflashAddr)));

    SFLASH_SetWriteDataReg(writeData);

    if (SFLASH_WriteFlashCmdDrv(0x10, 0x10) == 0)
    {
        return 0;
    }

    if (SFLASH_WaitForWriteBusyDrv(SFLASH_WRITEBUSY_TIMEOUT) == 0)
    {
        return 0;
    }
    return 1;
}


/**
 * SFLASHHW_4IOWriteDrv
 *
 * @param[in] sflashAddr: specifies the serial flash address to be programed
 * @param[in] writeData: the data length to be programed
 * @return 0: program fail, 1: program success
 *
 * @brief 4 IO prefetch program to serial flash
 */
int32_t SFLASHHW_4IOWriteDrv(uint32_t sflashAddr, uint32_t length,const uint8_t* dataBuffer)
{
    uint32_t  realLength;
    uint32_t cmdAddrReg = 0;
    uint8_t qspiConfig = 0x0;

    if (length == 0)
    {
        return 0;
    }

    if ((length & 0x03) != 0)
    {
        return 0;
    }

    if (dataBuffer == NULL)
    {
        return 0;
    }
    if (SFLASHHW_SetFlashQuadEnable() == 0)
    {	
        return 0;
    }
    qspiConfig = SFLASH_GetQSPIReg();
    SFLASH_SetQSPIReg(0x06);
    SFLASH_SetCFG2Reg(0x11);//MXIC
    SFLASH_SetProgramData0Reg(0x38);//MXIC(25L1280)

    cmdAddrReg = (uint32_t)(&(SFLASH->REG_SF_CFG2));
    if (SFLASH_PollingRegDrv(cmdAddrReg, 0x01, 0x01) == 0)
    {
        return 0;
    }

    while (length > 0)
    {
        if (length >= SFLASH_WRBUF_SIZE)
        {
            realLength = SFLASH_WRBUF_SIZE;
        }
        else
        {
            realLength = length;
        }

        if (SFLASH_WriteBufferDrv(sflashAddr, realLength, dataBuffer) == 0)
        {
            SFLASH_SetCFG2Reg(0x0);
            cmdAddrReg = (uint32_t)(&(SFLASH->REG_SF_CFG2));
            if (SFLASH_PollingRegDrv(cmdAddrReg, 0x01, 0) == 0)
            {
                return 0;
            }
            return 0;
        }
        if (SFLASH_WriteFlashCmdDrv(0x10, 0x10) == 0)
        {
            return 0;
        }

        if (SFLASH_WaitForWriteBusyDrv(SFLASH_WRITEBUSY_TIMEOUT) == 0)
        {
            return 0;
        }
        sflashAddr += realLength;
        dataBuffer += realLength;
        length -= realLength;
    }
  
    SFLASH_SetQSPIReg(qspiConfig);    
    SFLASH_SetCFG2Reg(0x0);
    cmdAddrReg = (uint32_t)(&(SFLASH->REG_SF_CFG2));
    if (SFLASH_PollingRegDrv(cmdAddrReg, 0x01, 0) == 0)
    {		
        return 0;
    }
    return 1;
}
