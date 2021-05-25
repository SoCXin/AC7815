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

#ifdef __cplusplus
extern "C" {
#endif
#include "stdint.h"
#include "stdio.h"	
#include "ac78xx_serialflash_reg.h"
	

typedef enum
{
    SFLASH_INVALID_READ = 0,    ///< Invalid read mode
    SFLASH_NORMAL_READ = 1,     ///< Normal read mode
    SFLASH_FAST_READ = 2,       ///< Fast read mode
    SFLASH_DUAL_READ = 3,       ///< Dual read mode
    SFLASH_FOUR_IO_READ = 4,    ///< Four IO read mode
    SFLASH_QUAD_READ = 5,       ///< Quad data read mode 
    SFLASH_MAX_READ = 6         ///< Max read mode
}SFLASH_READMODE_T;

typedef enum
{
    SFLASH_INVALID_WRITE = 0,        ///< Invalid program mode
    SFLASH_BYTE_WRITE = 1,           ///< Byte program mode
    SFLASH_AAI_WRITE = 2,            ///< Auto Address Increment program mode
    SFLASH_PREFETCHBUFFER_WRITE = 3, ///< Prefetch program mode
    SFLASH_SINGLE_WRITE = 4,         ///< Single program mode
    SFLASH_QUAD_WRITE = 5,           ///< Quad program mode
    SFLASH_MAX_WRITE = 6            ///< Max program mode
}SFLASH_WRITEMODE_T;

typedef struct
{
    uint32_t  chipSize;                     ///< Total chip size Serial flash
    uint32_t  secSize;                      ///< Sector size of Serial flash
    uint8_t   menuID;                       ///< The manufacturer identification
    uint8_t   devID1;                       ///< The device identification 1
    uint8_t   devID2;                       ///< The device identification 2
    uint8_t   readCommand;                  ///< Serial flash normal read  command
    uint8_t   fastReadCommand;              ///< Serial flash fast read data command
    uint8_t   readIDCommand;                ///< Serial flash fast read identification command
    uint8_t   sectorEraseCommand;           ///< Serial flash sector erase command
    uint8_t   chipEraseCommand;             ///< Serial flash chip erase command
    uint8_t   pageProgramCommand;           ///< Serial flash normal page program command
    uint8_t   AAIProgramCommand;            ///< Serial flash AAI page program command
    uint8_t   dualReadCommand;              ///< Serial flash dual read  command
    uint8_t   dualDataReadCommand;          ///< Serial flash dual data read  command
    uint8_t   fourIOProgramCmd;             ///< Serial flash four IO program command 
    uint8_t   fourIOReadCmd;                ///< Serial flash four IO read command 
    uint8_t   quadReadCmd;                  ///< Serial flash quad read command 
    uint8_t   flashNameStr[48];             ///< Serial flash name
} SFLASHHW_VENDOR_T;                    

typedef struct
{
   uint8_t flashID;                         ///< Serial flash identification
   SFLASH_READMODE_T     rdMode;            ///< Serial flash read mode
   SFLASH_WRITEMODE_T    wrMode;            ///< Serial flash write mode
   uint32_t flashOffset;                    ///< Serial flash offset for test
   uint8_t *goldenBuffer;                   ///< Buffer for storing golden data
   uint8_t *testBuffer;                     ///< Buffer for storing test data
   uint32_t sectorSize;                     ///< Serial flash sector size
}SFLASH_SECTORTEST_T;

typedef struct
{
    uint32_t FlashCount;                    ///< Serial flash number
    SFLASHHW_VENDOR_T * ValidFlash[1];      ///< Serial flash feature
}SFLASH_CFG_T;


#define SFLASH_POLLINGREG_COUNT     50000       ///< Try times when fail  
#define SFLASH_ERASESECTOR_TIMEOUT  500000      ///< Time out when sector erase
#define SFLASH_ERASECHIP_TIMEOUT  	500000      ///< Time out when whole chip erase
#define SFLASH_WRITEBUSY_TIMEOUT    500000      ///< Time out when serial flash busy
#define SFLASH_WRBUF_SIZE           128         ///< Ttest buffer size

#define SFLAHS_READID_CMD           0x9F        ///<  Read identification command
#define SFLAHS_SECTOR_ERASE_CMD     0xD8        ///<  Erase sector command
#define SFLAHS_CHIP_ERASE_CMD       0xC7        ///<  Chip sector command

SFLASH_CFG_T * SFLASH_GetValidFlashInfoDrv(void);
int32_t SFLASH_DetectDrv(void);
int32_t SFLASHHW_SetFlashQuadEnable(void);
int32_t SFLASH_WriteFlashCmdDrv(int8_t commandValue, uint8_t pollingValue);
int32_t SFLASHHW_ReadDrv(uint32_t sflashAddr, uint32_t length, uint8_t* dataBuffer);
int32_t SFLASHHW_FReadDrv(uint32_t u4Addr, uint32_t length, uint8_t* dataBuffer);
int32_t SFLASHHW_DualReadDrv(uint32_t sflashAddr, uint32_t length, uint8_t* dataBuf);
int32_t SFLASHHW_QuadReadDrv(uint32_t sflashAddr, uint32_t length, uint8_t* dataBuf);
int32_t SFLASHHW_4IOReadDrv(uint32_t sflashAddr, uint32_t length, uint8_t* dataBuf);
int32_t SFLASHHW_EraseSectorDrv(uint32_t sflashAddr);
int32_t SFLASHHW_EraseChipDrv(void);
int32_t SFLASHHW_SetFlashWriteEnableDrv(void);
int32_t SFLASH_WaitForWriteBusyDrv(uint32_t timeoutValue);
int32_t SFLASHHW_ReadFlashStatusDrv(uint8_t *sflashStatusl);
int32_t SFLASHHW_PrefetchWriteDrv(uint32_t sflashAddr, uint32_t length, const uint8_t* dataBuffer);
int32_t SFLASHHW_SWriteDrv(uint32_t sflashAddr, uint32_t length, const uint8_t* dataBuffer);
int32_t SFLASHHW_AAIWriteDrv(uint32_t sflashAddr, uint32_t length, const uint8_t* dataBuffer);
int32_t SFLASH_PollingRegDrv(uint32_t regAddr, uint32_t compareValue, uint8_t pollingValue);
int32_t SFLASH_WriteBufferDrv(int32_t sflashAddr, int32_t length, const uint8_t* dataBuffer);
int32_t SFLASH_WriteSingleByteDrv(uint32_t sflashAddr, int32_t writeData);
int32_t SFLASHHW_4IOWriteDrv(uint32_t sflashAddr, uint32_t length,const uint8_t* dataBuffer);


#ifdef __cplusplus
}
#endif
