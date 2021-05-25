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

#ifdef __cplusplus
extern "C" {
#endif
#include "stdint.h"
#include "stdio.h"
#include "ac78xx_eflash_reg.h"

typedef enum
{
    EFLASH_CMD_IDLE = 0,        ///< Idle command.
    EFLASH_CMD_PAGERASE,        ///< Page erase command.
    EFLASH_CMD_MASSRASE,        ///< Mass erase command. 
    EFLASH_CMD_PAGEPROGRAM,     ///< Page program command.
    EFLASH_CMD_PAGERASEVERIFY,  ///< Page erase verify command.
    EFLASH_CMD_MASSRASEVERIFY,  ///< Mass erase verify command.
    EFLASH_CMD_PROTECTERASE,    ///< Protect byte page erase command.
    EFLASH_CMD_PROTECTROGRAM,   ///< Protect byte page program command.
    EFLASH_CMD_INVALID,         ///< Invalid command.             
}EFLASH_CMD;  // eflash command 

typedef enum
{
    EFLASH_STATUS_ACK = 1,              ///< Acknowledge status.
    EFLASH_STATUS_SUCCESS,              ///< Success status.
    EFLASH_STATUS_CMD_INVALID,          ///< Invalid command status.
    EFLASH_STATUS_BUSY,                 ///< Error status for busy.
    EFLASH_STATUS_READOUT_PROTECT,      ///< Error status for read protect.
    ELFASH_STATUS_WRITE_PROTECT,        ///< Error status for write protect.
    EFLASH_STATUS_PARAMETER_ERROR,      ///< Error status for parameter.
    EFLASH_STATUS_WRER_ERROR,           ///< Error status for the operation violates the write protection rules.
    EFLASH_STATUS_RDER_ERROR,           ///< Error status for the operation violates the read protection rules.
    EFLASH_STATUS_PPERER_ERROR,         ///< Error status for permission error of commands operation.
    EFLASH_STATUS_PPADRER_ERROR,        ///< Error status for the page program command operation.
    EFLASH_STATUS_ERAER_ERROR,          ///< Error status for the erase command operation.
    EFLASH_STATUS_VRER_ERROR,           ///< Error status for verify command operation.
    EFLASH_STATUS_OPTER_ERROR,          ///< Error status for option byte.
    EFLASH_STATUS_ALLOCMM_ERROR,        ///< Error status for allocate memory.
    EFLASH_STATUS_TIMEOUT,              ///< Error status for time.
    EFLASH_STATUS_ADDRESS_ERROR,        ///< Error status for eflash address.
    EFLASH_STATUS_INVALID,              ///< Invalid status.
} EFLASH_STATUS;  ///< eflash status.

#define PageEraseTimeout          ((uint32_t)0x00A00000) ///< eflash page ease time out.
#define MassEraseTimeout          ((uint32_t)0x00A00000) ///< eflash mass ease time out.
#define PageProgramTimeout        ((uint32_t)0x00004000) ///< eflash page program time out.

EFLASH_STATUS EFLASH_UnlockCtrl(void);
EFLASH_STATUS EFLASH_LockCtrl(void);
EFLASH_STATUS EFLASH_WaitForLastOperation(uint32_t timeout);
EFLASH_STATUS EFLASH_WaitEop(uint32_t timeout);
uint32_t EFLASH_ReadDWord(uint32_t eflashAddr);
EFLASH_STATUS EFLASH_Read(uint32_t readAddr, uint32_t *dataBuffer, uint32_t numbToRead);
EFLASH_STATUS EFLASH_MassErase(void);
EFLASH_STATUS EFLASH_PageProgram(uint32_t pageAddress, uint32_t *dataBuffer, uint32_t dataLength);
EFLASH_STATUS EFLASH_OptionPageErase(uint32_t optPageAddress);
EFLASH_STATUS EFLASH_OptionPageProgram(uint32_t pageAddress, uint32_t *dataBuffer, uint32_t dataLength);
EFLASH_STATUS EFLASH_SetWriteProtect(uint32_t pageNumber, uint8_t wrProFlag);
EFLASH_STATUS EFLASH_SetReadProtect(uint8_t readProFlag);
EFLASH_STATUS EFLASH_GetStatus(void);
EFLASH_STATUS EFLASH_ConfigWdg(uint8_t cofigValue);
EFLASH_STATUS EFLASH_EnableReadOut(void);
EFLASH_STATUS EFLASH_MassEraseVerify(void);
EFLASH_STATUS EFLASH_PageEraseVerify(uint32_t pageAddress);
EFLASH_STATUS EFLASH_PageErase(uint32_t pageAddress);
EFLASH_STATUS EFLASH_DisableReadOut(void);
void EFLSH_INTERRUP_INIT(void);

#ifdef __cplusplus
}
#endif
