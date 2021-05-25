/* Copyright Statement:
 *
 * This software/firmware and related documentation "Autochips Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to Autochips Inc. and/or its licensors.
 * Without the prior written permission of Autochips inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of Autochips Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * Copyright(C) 2016, Autochips ( All rights reserved. )
 *
 * BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("Autochips SOFTWARE")
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
#include "ac78xx.h"
#include "ac78xx_eflash.h"

/**
 * EFLASH_CheckUserAddress
 *
 * @param[in] eflashAddress: Address of eflash user arear
 * @return EFLASH STATUS: eflash operation status
 *
 * @brief  Check eflash user arear address
 */
EFLASH_STATUS EFLASH_CheckUserAddress(uint32_t eflashAddress)
{
    EFLASH_STATUS statusRes = EFLASH_STATUS_SUCCESS;

    if ((eflashAddress < EFLASH_ADDRESS_BASE) || (eflashAddress > EFLASH_ADDRESS_END))
    {        
        statusRes = EFLASH_STATUS_ADDRESS_ERROR;
    }
    else
    {
        //To do
    }  

    return statusRes;
}

/**
 * EFLASH_CheckOptionPageAddress
 *
 * @param[in] eflashAddress: Address of eflash option page arear
 * @return EFLASH STATUS: eflash operation status
 *
 * @brief  : Check option page address
 */
EFLASH_STATUS EFLASH_CheckOptionPageAddress(uint32_t eflashAddress)
{
    EFLASH_STATUS statusRes = EFLASH_STATUS_SUCCESS;
  
    if ((eflashAddress < OPTION_BASE) || (eflashAddress > OPTION_END))
    {        
        statusRes = EFLASH_STATUS_ADDRESS_ERROR;
    }
    else
    {
        //To do
    }    

    return statusRes;
}

/**
 * EFLASH_UnlockCtrl
 *
 * @param[in] none
 * @return   EFLASH STATUS: eflash operation status
 *
 * @brief  Unlock the eflash control
 */
EFLASH_STATUS EFLASH_UnlockCtrl(void)
{
    EFLASH_STATUS statusRes = EFLASH_STATUS_SUCCESS;
    uint8_t ctrlLockBit = 0;
    uint32_t timeoutCount = 0;
    ctrlLockBit = EFLASH_GetCrlLockBitReg();
    while (ctrlLockBit == 1)
    {
        EFLASH_SetKeyReg(EFLSH_UNLOCK_KEY1);
        EFLASH_SetKeyReg(EFLSH_UNLOCK_KEY2);

        if (100 < timeoutCount)
        {
            statusRes = EFLASH_STATUS_TIMEOUT;
            break;
        }
        ctrlLockBit = EFLASH_GetCrlLockBitReg();
        timeoutCount++;
    }
    return statusRes;
}

/**
 * EFLASH_LockCtrl
 *
 * @param[in] none
 * @return   EFLASH STATUS: eflash operation status
 *
 * @brief  Lock the eflash control
 */
EFLASH_STATUS EFLASH_LockCtrl(void)
{
    EFLASH_STATUS statusRes = EFLASH_STATUS_SUCCESS;

    EFLASH_LockCtrlReg();

    return statusRes;
}

/**
 * EFLASH_WaitForLastOperation
 *
 * @param[in] timeout: Time out value
 * @return  EFLASH STATUS: eflash operation status
 *
 * @brief  Waiting for the end of all operation
 */
EFLASH_STATUS EFLASH_WaitForLastOperation(uint32_t timeout)
{
    EFLASH_STATUS statusRes = EFLASH_STATUS_SUCCESS;

    while ((EFLASH_GetAnyBusySTReg() == 1) && (timeout != 0x00))
    {
        timeout--;
    }
    if (timeout == 0x00)
    {
        statusRes = EFLASH_STATUS_TIMEOUT;
    }
    return statusRes;
}

/**
 * EFLASH_WaitEop
 *
 * @param[in] timeout: Time out
 * @return EFLASH STATUS: eflash operation status
 *
 * @brief  Waiting for the end of the operation
 */
EFLASH_STATUS EFLASH_WaitEop(uint32_t timeout)
{
    EFLASH_STATUS statusRes = EFLASH_STATUS_SUCCESS;
   
   while ((EFLASH_GetEopReg() != 1) && (timeout != 0x00))
    {
        timeout--;
    }
    if (timeout == 0x00)
    {
        statusRes = EFLASH_STATUS_TIMEOUT;
    }
    return statusRes;
}

/**
 * EFLASH_ReadDWord
 *
 * @param[in]  eflashAddr: Specified address
 * @return  EFLASH STATUS: eflash operation status
 *
 * @brief  Read double word from the flash specified address
 */
uint32_t EFLASH_ReadDWord(uint32_t eflashAddr)
{
    return *(uint32_t*)eflashAddr;
}

/**
 * EFLASH_Read
 *
 * @param[in]   readAddr: Eflash address
 * @param[in]    dataBuffer: Data buffer
 * @param[in] numbToRead: Number of DWORD
 *
 * @return EFLASH STATUS: eflash operation status
 *
 * @brief  Read a certain amount of data from the flash specified address
 */
EFLASH_STATUS EFLASH_Read(uint32_t readAddr, uint32_t *dataBuffer, uint32_t numbToRead)
{
    EFLASH_STATUS statusRes = EFLASH_STATUS_SUCCESS;
    uint32_t i;

    for (i = 0; i < numbToRead; i++)
    {
        dataBuffer[i] = EFLASH_ReadDWord(readAddr);
        readAddr += 4;
    }

    return statusRes;
}

/**
 * EFLASH_PageErase
 *
 * @param[in] pageAddress: Specified eflash addrees to be erased
 * @return EFLASH STATUS: eflash operation status
 *
 * @brief  Erase specified eflash user area address
 */
EFLASH_STATUS EFLASH_PageErase(uint32_t pageAddress)
{
    EFLASH_STATUS statusRes = EFLASH_STATUS_SUCCESS;
    uint32_t cmdValue = 0x0;

    /* check eflash address */
    statusRes = EFLASH_CheckUserAddress(pageAddress);
    if (statusRes == EFLASH_STATUS_SUCCESS)
    {
        /* Wait for last operation to be completed */
        statusRes = EFLASH_WaitForLastOperation(PageEraseTimeout);
        if (statusRes == EFLASH_STATUS_SUCCESS)
        {
            /* Configure start address */             
            EFLASH_SetStartAddressReg(pageAddress);

            /* Configure command and CMD_ST goes back to 0 */
            cmdValue = EFLSH_CTRL1_EOPIE_MSK | EFLASH_CMD_PAGERASE;  //Normal operation
            EFLASH_SetCtlReg1(cmdValue);
                
            /* Trigger to start */
            EFLASH_TrigCtlCmdReg();
                
            /* Check whether the command is finished */
            statusRes = EFLASH_WaitForLastOperation(PageEraseTimeout);
            if (statusRes == EFLASH_STATUS_SUCCESS)
            {
                statusRes = EFLASH_WaitForLastOperation(PageEraseTimeout);
                if (statusRes == EFLASH_STATUS_SUCCESS)
                {
                    /* Cleare status */
                    EFLASH_ClearEopReg();
    
                    /* Check error */
                    if (EFLASH_GetStatusReg() & EFLSH_SR1_ERAER_MSK)
                    {
                        statusRes = EFLASH_STATUS_ERAER_ERROR;
                    }
                    else
                    {
                        /* Erase page success now */
                        statusRes = EFLASH_STATUS_SUCCESS;
                    }
                }
                else
                {
                    statusRes = EFLASH_STATUS_BUSY;
                }
            }
        }
        else
        {
            statusRes = EFLASH_STATUS_BUSY;
        }
    }
    return statusRes;
}

/**
 * EFLASH_MassErase
 *
 * @param[in] none
 * @return  EFLASH STATUS: eflash operation status
 *
 * @brief   Mass erase elfash user area
 */
EFLASH_STATUS EFLASH_MassErase(void)
{
    EFLASH_STATUS statusRes = EFLASH_STATUS_SUCCESS;
    uint32_t cmdValue = 0x0;

    /* Wait for last operation to be completed */
    statusRes = EFLASH_WaitForLastOperation(PageEraseTimeout);
    if (statusRes == EFLASH_STATUS_SUCCESS)
    {
        /* Configure command and CMD_ST goes back to 0 */
        cmdValue = EFLSH_CTRL1_EOPIE_MSK | EFLASH_CMD_MASSRASE;
        EFLASH_SetCtlReg1(cmdValue);

        /* Trigger to start */
        EFLASH_TrigCtlCmdReg();

        /* Check whether the command is finished */
        statusRes = EFLASH_WaitForLastOperation(PageEraseTimeout);
        if (statusRes == EFLASH_STATUS_SUCCESS)
        {
            statusRes =  EFLASH_WaitEop(PageEraseTimeout);
            if (statusRes == EFLASH_STATUS_SUCCESS)
            {
                /* Cleare status */
                EFLASH_ClearEopReg();

                /* Check error */
                if (EFLASH_GetStatusReg() & EFLSH_SR1_ERAER_MSK)
                {
                    statusRes = EFLASH_STATUS_ERAER_ERROR;
                }
                else
                {
                   /* Erase page success now */
                   statusRes = EFLASH_STATUS_SUCCESS;
                }
            }
            else
            {
                statusRes = EFLASH_STATUS_BUSY;
            }
        }
    }
    else
    {
        statusRes = EFLASH_STATUS_BUSY;
    }

    return statusRes;
}

/**
 * EFLASH_PageProgram
 *
 * @param[in]  pageAddress  : Specified eflash addrees to be programed
 * @param[in]  dataBuffer      : Data buffer to be programed
 * @param[in]  dataLength   : Data length to be programed
 * @return EFLASH STATUS: eflash operation status
 *
 * @brief  : User page erase
 */
EFLASH_STATUS EFLASH_PageProgram(uint32_t pageAddress, uint32_t *dataBuffer, uint32_t dataLength)
{
    EFLASH_STATUS statusRes = EFLASH_STATUS_SUCCESS;
    uint32_t cmdValue = 0x0;
    uint32_t dataCount = 0x0;
    
    /* check eflash address */
    statusRes = EFLASH_CheckUserAddress(pageAddress);
    if (statusRes == EFLASH_STATUS_SUCCESS)
    {
        /* check program length,Max length is 512 Dword */
        if (512 < dataLength)
        {
            return EFLASH_STATUS_PARAMETER_ERROR;
        }      
        
        /* Wait for last operation to be completed */
        statusRes = EFLASH_WaitForLastOperation(PageEraseTimeout);
        if (statusRes == EFLASH_STATUS_SUCCESS)
        {
            /* Configure start address */   
            EFLASH_SetStartAddressReg(pageAddress);

            /* Configure command and CMD_ST goes back to 0 */
            cmdValue = (dataLength << EFLSH_CTRL1_PROG_LENGTH_POS) | EFLSH_CTRL1_EOPIE_MSK | EFLASH_CMD_PAGEPROGRAM;     
            EFLASH_SetCtlReg1(cmdValue);

            /* Trigger to start */
            EFLASH_TrigCtlCmdReg();

            /*program data */
            for (dataCount = 0; dataCount < dataLength; dataCount++)       
            {
                *(uint32_t *)pageAddress = dataBuffer[dataCount];
                pageAddress += 4;
            }

            /* Check whether the command is finished */
            statusRes = EFLASH_WaitForLastOperation(PageEraseTimeout);           
            if (statusRes == EFLASH_STATUS_SUCCESS)
            {
                statusRes =  EFLASH_WaitEop(PageEraseTimeout);
                if (statusRes == EFLASH_STATUS_SUCCESS)
                {
                    /* Cleare status */
                    EFLASH_ClearEopReg();

                    /* Check error */
                    if (EFLASH_GetStatusReg() & EFLSH_SR1_PPADRERR_MSK)
                    {
                        statusRes = EFLASH_STATUS_PPADRER_ERROR;
                    }
                    else
                    {
                        /* Progeam page success now */
                        statusRes = EFLASH_STATUS_SUCCESS;
                    }
                }
                else
                {
                    statusRes = EFLASH_STATUS_BUSY;
                }
            }
            else
            {
                statusRes = EFLASH_STATUS_BUSY;
            }
        }
        else
        {
            statusRes = EFLASH_STATUS_BUSY;
        }
    }
    else
    {
        statusRes = EFLASH_STATUS_ADDRESS_ERROR;
    }
    return statusRes;
}

/**
 * EFLASH_PageVerify
 *
 * @param[in] pageAddress : Specified eflash addrees to be verified
 * @return EFLASH STATUS: eflash operation status
 *
 * @brief  : Verify whether the page erase operation is performed successfully
 */
EFLASH_STATUS EFLASH_PageEraseVerify(uint32_t pageAddress)
{
    EFLASH_STATUS statusRes = EFLASH_STATUS_SUCCESS;
    uint32_t cmdValue = 0x0;
    
    /* Check the eflash address */
    statusRes = EFLASH_CheckUserAddress(pageAddress);
    if (statusRes == EFLASH_STATUS_SUCCESS)
    {
        /* Wait for last operation to be completed */
        statusRes = EFLASH_WaitForLastOperation( PageEraseTimeout );
        if (statusRes == EFLASH_STATUS_SUCCESS)
        {
            /* Configure start address */
           /// pageAddress = ((pageAddress - EFLASH_ADDRESS_BASE) / EFLASH_PAGE_SIZE) * 8;
            EFLASH_SetStartAddressReg(pageAddress);
            
            /* Configure command and CMD_ST goes back to 0 */
            cmdValue = EFLSH_CTRL1_EOPIE_MSK | EFLASH_CMD_PAGERASEVERIFY;
            EFLASH_SetCtlReg1(cmdValue);
            
            /* Trigger to start */
            EFLASH_TrigCtlCmdReg();

            /* Check whether the command is finished */
            statusRes = EFLASH_WaitForLastOperation(PageEraseTimeout);
            if (statusRes == EFLASH_STATUS_SUCCESS)
            {
                if (EFLASH_GetEopReg() == 1)
                {
                    /* Check verify result */                  
                    if (EFLASH_GetStatusReg() & EFLSH_SR1_VRER_MSK)
                    {
                        statusRes = EFLASH_STATUS_VRER_ERROR;
                    }
                    /* Cleare status */
                    EFLASH_ClearEopReg();
                }
                else
                {
                    statusRes = EFLASH_STATUS_BUSY;
                }
            }
        }
        else
        {
            statusRes = EFLASH_STATUS_BUSY;
        }
    }

    return statusRes;
}

/**
 * EFLASH_MassEraseVerify
 *
 * @param[in] none
 * @return EFLASH STATUS: eflash operation status
 *
 * @brief  : Verify whether the mass erase operation is performed successfully
 */

EFLASH_STATUS EFLASH_MassEraseVerify(void)
{
    EFLASH_STATUS statusRes = EFLASH_STATUS_SUCCESS;
    uint32_t cmdValue = 0x0;
    
    /* Wait for last operation to be completed */
    statusRes = EFLASH_WaitForLastOperation( PageEraseTimeout );
    if (statusRes == EFLASH_STATUS_SUCCESS)
    {
        /* Configure command and CMD_ST goes back to 0 */
        cmdValue = EFLSH_CTRL1_EOPIE_MSK | EFLASH_CMD_MASSRASEVERIFY;
        EFLASH_SetCtlReg1(cmdValue);

        /* Trigger to start */
        EFLASH_TrigCtlCmdReg();

        /* Check whether the command is finished */
        statusRes = EFLASH_WaitForLastOperation(PageEraseTimeout);
        if (statusRes == EFLASH_STATUS_SUCCESS)
        {
            if (EFLASH_GetEopReg() == 1)
            {
                /* Check verify result */
                if (EFLASH_GetStatusReg() & EFLSH_SR1_VRER_MSK)
                {
                    statusRes = EFLASH_STATUS_VRER_ERROR;
                }

                /* Cleare status */
                EFLASH_ClearEopReg();

            }
            else
            {
                statusRes = EFLASH_STATUS_BUSY;
            }
        }
    }
    else
    {
        statusRes = EFLASH_STATUS_BUSY;
    }
    return statusRes;
}

/**
 * EFLASH_OptionPageErase
 *
 * @param[in] optPageAddress: Specified option addrees to erase
 * @return  EFLASH STATUS: eflash operation status
 *
 * @brief  Option page erase
 */
EFLASH_STATUS EFLASH_OptionPageErase(uint32_t optPageAddress)
{
    EFLASH_STATUS statusRes = EFLASH_STATUS_SUCCESS;
    uint32_t cmdValue = 0x0;

    /* Wait for last operation to be completed */
    statusRes = EFLASH_WaitForLastOperation(PageEraseTimeout);
    if (statusRes == EFLASH_STATUS_SUCCESS)
    {
        /* Configure start address */
        EFLASH_SetStartAddressReg(optPageAddress);
        
        /* Configure command and CMD_ST goes back to 0 */
        cmdValue = EFLSH_CTRL1_OPT_CMD_EN_MSK | EFLSH_CTRL1_EOPIE_MSK | EFLASH_CMD_PROTECTERASE;
        EFLASH_SetCtlReg1(cmdValue);
        
        /* Trigger to start */
        EFLASH_TrigCtlCmdReg();

        /* Check whether the command is finished */
        statusRes = EFLASH_WaitForLastOperation(PageEraseTimeout);
        if (statusRes == EFLASH_STATUS_SUCCESS)
        {
            statusRes =  EFLASH_WaitEop(PageEraseTimeout);
            if (statusRes == EFLASH_STATUS_SUCCESS)
            {
                /* Cleare status */
                EFLASH_ClearEopReg();

                /* Check error */

                /* Erase option page success now */

            }
            else
            {
                statusRes = EFLASH_STATUS_BUSY;
            }
        }
    }
    else
    {
        statusRes = EFLASH_STATUS_BUSY;
    }

    return statusRes;
}

/**
 * EFLASH_OptionPageProgram
 *
 * @param[in] pageAddress: Specified option addrees
 * @param[in]    *dataBuffer: Point to the data to be programed
 * @param[in]    dataSize: Data length to be programmed
 * @return EFLASH STATUS: eflash operation status
 *
 * @brief  Programs data to specified option page address
 */
EFLASH_STATUS EFLASH_OptionPageProgram(uint32_t pageAddress, uint32_t *dataBuffer, uint32_t dataLength)
{
    EFLASH_STATUS statusRes = EFLASH_STATUS_SUCCESS;
    uint32_t cmdValue = 0x0;
    uint32_t dataCount = 0x0;

    if (EFLASH_CheckOptionPageAddress(pageAddress) != EFLASH_STATUS_SUCCESS)
    {
        return EFLASH_STATUS_ADDRESS_ERROR;
    }
    /* Wait for last operation to be completed */
    statusRes = EFLASH_WaitForLastOperation(PageEraseTimeout);
    if (statusRes == EFLASH_STATUS_SUCCESS)
    {
        EFLASH_SetStartAddressReg(pageAddress);
       
        /* Configure command and CMD_ST goes back to 0 */
        cmdValue = (dataLength << EFLSH_CTRL1_PROG_LENGTH_POS) | EFLSH_CTRL1_OPT_CMD_EN_MSK \
                   | EFLSH_CTRL1_EOPIE_MSK | EFLASH_CMD_PROTECTROGRAM;
        EFLASH_SetCtlReg1(cmdValue);

        /* Trigger to start */
        EFLASH_TrigCtlCmdReg();

        /* user program data */
        for (dataCount = 0; dataCount < dataLength; dataCount++)
        {
            *(uint32_t *)pageAddress = dataBuffer[dataCount];
            pageAddress += 4;
        }

        /* Check whether the command is finished */
        statusRes = EFLASH_WaitForLastOperation(PageEraseTimeout);
        if (statusRes == EFLASH_STATUS_SUCCESS)
        {
            statusRes =  EFLASH_WaitEop(PageEraseTimeout);
            if (statusRes == EFLASH_STATUS_SUCCESS)
            {
                /* Cleare status */
                EFLASH_ClearEopReg();

                /* Check error */

                /* Erase page success now */
            }
            else
            {
                statusRes = EFLASH_STATUS_BUSY;
            }
        }
        else
        {
            statusRes = EFLASH_STATUS_BUSY;
        }
    }
    else
    {
        statusRes = EFLASH_STATUS_BUSY;
    }

    return statusRes;
}

/**
 * EFLASH_EnableReadOut
 *
 * @param[in] none
 * @return EFLASH STATUS: eflash operation status
 *
 * @brief Set read out protect
 */
EFLASH_STATUS EFLASH_EnableReadOut(void)
{
    EFLASH_STATUS statusRes = EFLASH_STATUS_SUCCESS;
    uint32_t optBuffer[12] = {0};

    //if (EFLASH_GetReadProtectReg() == 1)
    {
        EFLASH_Read(OPTION_BASE, optBuffer, 12);
        statusRes = EFLASH_OptionPageErase(OPTION_BASE);
        optBuffer[0] &= 0xFFFF0000;
        optBuffer[0] = 0x5AA55AA5;
        statusRes = EFLASH_OptionPageProgram(OPTION_BASE, optBuffer, 12);

    }
    return statusRes;
}

/**
 * EFLASH_SetWriteProtect
 *
 * @param[in] pageNumber: Page to be changed write protect
 * @param[in]  wrProFlag: write protect flag
 *                       1: Enable write protect
 *                       0: Unable write protect
 *
 * @return EFLASH STATUS: eflash operation status
 *
 * @brief Set write protect
 */
EFLASH_STATUS EFLASH_SetWriteProtect(uint32_t pageNumber, uint8_t wrProFlag)
{

    EFLASH_STATUS statusRes = EFLASH_STATUS_SUCCESS;
    uint32_t optBuffer[12] = {0};
    uint32_t i = 0;

    EFLASH_Read(OPTION_BASE, optBuffer, 12);
    statusRes = EFLASH_OptionPageErase(OPTION_BASE);
    if (statusRes == EFLASH_STATUS_SUCCESS)
    {       
        for (i = 2; i<10; i++)
        {
              optBuffer[i] = 0x0;

        }    
        statusRes = EFLASH_OptionPageProgram(OPTION_BASE, optBuffer, 12);
        if (statusRes != EFLASH_STATUS_SUCCESS)
        {
            statusRes = EFLASH_STATUS_OPTER_ERROR;
        }
    }
    else
    {
        statusRes = EFLASH_STATUS_ERAER_ERROR;
    }
    return statusRes;
}

/**
 * EFLASH_DisableReadOut
 *
 * @param[in] none
 * @return EFLASH STATUS: eflash operation status
 *
 * @brief Set read out protect
 */
EFLASH_STATUS EFLASH_DisableReadOut(void)
{
    EFLASH_STATUS statusRes = EFLASH_STATUS_SUCCESS;
    uint32_t optBuffer[12] = {0};

    //if (EFLASH_GetReadProtectReg() != 1)  //For debug
    {
        EFLASH_Read(OPTION_BASE, optBuffer, 12);		
        statusRes = EFLASH_OptionPageErase(OPTION_BASE);
        if (statusRes != EFLASH_STATUS_SUCCESS)
        {
            statusRes = EFLASH_STATUS_ERAER_ERROR;
        }
        else				
        {
            optBuffer[0] = 0xFFFFFFAC;
            statusRes = EFLASH_OptionPageProgram(OPTION_BASE, optBuffer, 12);
            if (statusRes != EFLASH_STATUS_SUCCESS)
            {
                statusRes = EFLASH_STATUS_PPADRER_ERROR;
            }
        }
    }

    return statusRes;
}

/**
* EFLASH_ConfigWdg
*
* @param[in] cofigValue: 1:enalbe hardware watchdgo 0:disable hardware watchdog.
* @return EFLASH STATUS: eflash operation status.
*
* @brief config hardware watch.
*/
EFLASH_STATUS EFLASH_ConfigWdg(uint8_t cofigValue)
{
    EFLASH_STATUS statusRes = EFLASH_STATUS_SUCCESS;
    uint32_t optBuffer[12] = {0};
    
    EFLASH_UnlockCtrl();
    EFLASH_Read(OPTION_BASE, optBuffer, 12);
    statusRes = EFLASH_OptionPageErase(OPTION_BASE);
    if (statusRes == EFLASH_STATUS_SUCCESS)
    {
        if (cofigValue == 0x1)
        {
            optBuffer[1] = 0xFFFFFFCC;  
        }
        else
        {
            optBuffer[1] = 0xFFFFFFFF; 
        }    
        statusRes = EFLASH_OptionPageProgram(OPTION_BASE, optBuffer, 12);
        if (statusRes != EFLASH_STATUS_SUCCESS)
        {
            statusRes = EFLASH_STATUS_OPTER_ERROR;
        }
    }
    else
    {
        statusRes = EFLASH_STATUS_ERAER_ERROR;
    }
    EFLASH_LockCtrl();

    return statusRes;
}

/**
 * EFLASH_GetStatus
 *
 * @param[in] none
 * @return  EFLASH STATUS: eflash operation status
 *
 * @brief Get eflash status
 */
EFLASH_STATUS EFLASH_GetStatus(void)
{
    EFLASH_STATUS statusRes = EFLASH_STATUS_SUCCESS;

    if (EFLASH_GetAnyBusySTReg())
    {
        statusRes = EFLASH_STATUS_BUSY;
    }
    else
    {
        if (EFLASH_GetStatusReg() == 1)
        {  
            //To do  
        }
        else
        {
            //To do
        }
    }

    return statusRes;
}
