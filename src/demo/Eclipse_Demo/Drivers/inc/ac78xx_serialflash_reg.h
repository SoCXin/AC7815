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

#ifndef _AC78XX_SFLASH_REG_H_
#define _AC78XX_SFLASH_REG_H_
#ifdef __cplusplus
extern "C" {
#endif
  
#if defined(__CC_ARM)
  #pragma anon_unions
#elif defined(CCARM__)
  #pragma language=extended
#elif defined (__ICCARM__)
/* anonymous unions are enabled by default */
#elif defined(__GNUC__)
/* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif
	
#define __IO    volatile
#define __I     volatile const

#if defined ( __ICCARM__ )
#define __STATIC_INLINE static inline
#elif defined ( __GNUC__)
#define __STATIC_INLINE static inline
#elif defined (__CC_ARM)
#define __STATIC_INLINE static __inline
#endif


typedef struct {
    __IO uint32_t REG_SF_CMD;           ///< serial flash command register,                                       offset: 0x00
    __IO uint32_t REG_SF_CNT;           ///< Bit count to transfer by PRG command,                                offset: 0x04
    __IO uint32_t REG_SF_RDSR;          ///< Read back Status Register by RDSR command,                           offset: 0x08
    __IO uint32_t REG_SF_RDATA;         ///< Read back Flash Data by RD command,                                  offset: 0x0C
    __IO uint32_t REG_SF_RADR0;         ///< Read or Write address for Read command or Write command,             offset: 0x10
    __IO uint32_t REG_SF_RADR1;         ///< Read or Write address for Read command or Write command,             offset: 0x14
    __IO uint32_t REG_SF_RADR2;         ///< Read or Write address for Read command or Write command,             offset: 0x18
    __IO uint32_t REG_SF_WDATA;         ///< The serial flash write data used by the Write Command,               offset: 0x1C
    __IO uint32_t REG_SF_PRGDATA0;      ///< The serial flash program shift data used by the PRG Command,         offset: 0x20
    __IO uint32_t REG_SF_PRGDATA1;      ///< The serial flash program shift data used by the PRG Command,         offset: 0x24
    __IO uint32_t REG_SF_PRGDATA2;      ///< The serial flash program shift data used by the PRG Command,         offset: 0x28
    __IO uint32_t REG_SF_PRGDATA3;      ///< The serial flash program shift data used by the PRG Command,         offset: 0x2C
    __IO uint32_t REG_SF_PRGDATA4;      ///< The serial flash program shift data used by the PRG Command,         offset: 0x30
    __IO uint32_t REG_SF_PRGDATA5;      ///< The serial flash program shift data used by the PRG Command,         offset: 0x34
    __IO uint32_t REG_SF_SHREG0;        ///< The shift register of serial flash interface. For debug only,        offset: 0x38
    __IO uint32_t REG_SF_SHREG1;        ///< The shift register of serial flash interface. For debug only,        offset: 0x3C
    __IO uint32_t REG_SF_SHREG2;        ///< The shift register of serial flash interface. For debug only,        offset: 0x40
    __IO uint32_t REG_SF_SHREG3;        ///< The shift register of serial flash interface. For debug only,        offset: 0x44
    __IO uint32_t REG_SF_SHREG4;        ///< The shift register of serial flash interface. For debug only,        offset: 0x48
    __IO uint32_t REG_SF_SHREG5;        ///< The shift register of serial flash interface. For debug only,        offset: 0x4C
    __IO uint32_t REG_SF_SHREG6;        ///< The shift register of serial flash interface. For debug only,        offset: 0x50
    __IO uint32_t REG_SF_SHREG7;        ///< The shift register of serial flash interface. For debug only,        offset: 0x54
    __IO uint32_t REG_SF_SHREG8;        ///< The shift register of serial flash interface. For debug only,        offset: 0x58
    __IO uint32_t REG_SF_SHREG9;        ///< The shift register of serial flash interface. For debug only,        offset: 0x5C
    __IO uint32_t REG_SF_CFG1;          ///< module Configure register 1,                                         offset: 0x60
    __IO uint32_t REG_SF_CFG2;          ///< module Configure register 2,                                         offset: 0x64
    __IO uint32_t REG_SF_SHREG10;       ///< The shift register of serial flash interface. For debug only,        offset: 0x68
    __IO uint32_t REG_FL_STATUS;        ///< Flash condition register,                                            offset: 0x6C
    __IO uint32_t REG_FL_STATUS0;       ///< Flash status register 0,                                             offset: 0x70
    __IO uint32_t REG_FL_STATUS1;       ///< Flash status register 1,                                             offset: 0x74
    __IO uint32_t REG_FL_STATUS2;       ///< Flash status register 2,                                             offset: 0x78
    __IO uint32_t REG_FL_STATUS3;       ///< Flash status register 3,                                             offset: 0x7C
    __IO uint32_t RREG_FLASH_TIME;      ///< mSerial flash access timing register. (RISC R/W only),               offset: 0x80
    __IO uint32_t RREG_FLASH_CFG;       ///< flash configure register. (RISC R/W only),                           offset: 0x84
    __IO uint32_t REG_QSPI_CFG;         ///< QSPI Configuration register,                                         offset: 0x88
    __IO uint32_t REG_SF_PRGDATA6;      ///< The serial flash program shift data used by the PRG Command,,        offset: 0x8C
    __IO uint32_t SESERVE1;             ///< reserve,                                                             offset: 0x90
    __IO uint32_t RREG_SFLASH_TIME;     ///< CS active or inactive clock cycle control register. (RISC R/W only), offset: 0x94
    __IO uint32_t REG_SF_PP_DW_DATA;    ///< Flash page program data register,                                    offset: 0x98
    __IO uint32_t REG_DIFF_WHEN_WR;     ///< The difference between flash read address and cache data  address,   offset: 0x9C
    __IO uint32_t REG_SF_DELSEL0;       ///< Serial flash interface port delay select register 0,                 offset: 0xA0
    __IO uint32_t REG_SF_DELSEL1;       ///< Serial flash interface port delay select register 1,                 offset: 0xA4
    __IO uint32_t REG_SF_INTRSTUS;      ///< Interrupt register,                                                  offset: 0xA8
    __IO uint32_t REG_SF_INTREN;        ///< Interrupt Enable register,                                           offset: 0xAC
    __IO uint32_t REG_SF_PP_CTL;        ///< Page programming control register,                                   offset: 0xB0
    __IO uint32_t REG_SF_CFG3;          ///< module Configure register 3,                                         offset: 0xB4
    __IO uint32_t REG_FL_CHKSUM_CTL;    ///< flash check sum control register,                                    offset: 0xB8
    __IO uint32_t REG_FL_CHKSUM;        ///< Check sum output register,                                           offset: 0xBC
    __IO uint32_t REG_SF_AAICMD;        ///< AAI programming command enable register,                             offset: 0xC0
    __IO uint32_t REG_SF_WRPROT;        ///< Write command enable register,                                       offset: 0xC4
    __IO uint32_t REG_SF_RADR3;         ///< Read or Write address for Read command or Write command,             offset: 0xC8
    __IO uint32_t REG_SF_DUAL;          ///< Serial flash dual mode configure register,                           offset: 0xCC
    __IO uint32_t REG_SF_DELSEL2;       ///< Serial flash interface port delay select register 2,                 offset: 0xD0
    __IO uint32_t REG_SF_DELSEL3;       ///< Serial flash interface port delay select register 3,                 offset: 0xD4
    __IO uint32_t REG_SF_DELSEL4;       ///< Serial flash interface port delay select register 4,                 offset: 0xD8
    __IO uint32_t SESERVE2;             ///< reserve,                                                             offset: 0xDC
    __IO uint32_t REG_DUMMY_CFG;        ///< Configuration of dummy cycle for QSPI read command,                  offset: 0xE0
    __IO uint32_t REG_DUMMY_CFG2;       ///< Configuration 2 of dummy cycle for QSPI read command,                offset: 0xE4

} SFLASH_Type;

#define SFLASH_BASE (0x40010000u)               ///< SFlash Peripheral instance base addresses
#define SFLASH  ((SFLASH_Type *)SFLASH_BASE)    ///< Peripheral SFlash base pointer
#define SFLASH_BASES    { SFLASH }              ///< Array initializer of SFlash peripheral base pointers

#define SFLASH_WREG8(_reg_, _val_)      (*((volatile uint8_t*)(_reg_)) = (_val_))
#define SFLASH_RREG8(_reg_)             (*((volatile uint8_t*)(_reg_)))
#define SFLASH_WREG32(_reg_, _val_)     (*((volatile uint32_t*)(_reg_)) = (_val_))
#define SFLASH_RREG32(_reg_)            (*((volatile uint32_t*)(_reg_)))

#define LO_WORD(d)      ((uint16_t)(d & 0x0000ffffL))
#define HI_WORD(d)      ((uint16_t)((d >> 16) & 0x0000ffffL))
#define LO_BYTE(w)      ((uint8_t)(w & 0x00ff))
#define HID_BYTE(w)     ((uint8_t)((w >> 8) & 0x00ff))
#define MID_WORD(d)     ((uint16_t)((d >>8) & 0x00ffff))

/******************************************************************************
* SFLASH Reg API list
*******************************************************************************/
/**
 * SFLASH_SetSFCMDReg
 *
 * @param[in] commandValue: command value
 * @return : none
 *
 * @brief  Set serial flash command
 */
__STATIC_INLINE void SFLASH_SetSFCMDReg(uint32_t commandValue)
{
   SFLASH->REG_SF_CMD = commandValue;
}

/**
 * SFLASH_GetSFCMDReg
 *
 * @param[in]: none
 * @return : command reg value
 *
 * @brief  trigger read data command
 */
__STATIC_INLINE int32_t SFLASH_GetSFCMDReg(void)
{
    return (SFLASH->REG_SF_CMD);
}

 /**
 * SFLASH_SetPrgBitCountReg
 *
 * @param[in] prgCountValue: bit count,Maximum 48 bits
 * @return : none
 *
 * @brief  Set bit count to transfer by PRG command
 */
__STATIC_INLINE void SFLASH_SetPrgBitCountReg(uint8_t prgCountValue)
{
    SFLASH->REG_SF_CNT = prgCountValue;
}

 /**
 * SFLASH_ReadBackStatusReg
 *
 * @param[in]:  none
 * @return : Status data
 *
 * @brief  Read back Status Register by RDSR command
 */
__STATIC_INLINE uint8_t SFLASH_ReadBackStatusReg(void)
{
    return (SFLASH->REG_SF_RDSR);
}

 /**
 * SFLASH_ReadFlashDataReg
 *
 * @param[in] :  none
 * @return : Flash data
 *
 * @brief  Read back Status Register by RDSR command
 */
__STATIC_INLINE uint8_t SFLASH_ReadFlashDataReg(void)
{
    return (SFLASH->REG_SF_RDATA);
}

 /**
 * SFLASH_SetReadWritAddr0Reg
 *
 * @param[in] addrValue:  Flash address 0
 * @return             : none
 *
 * @brief  Read or Write address 0 for Read command or Write command
 */
__STATIC_INLINE void SFLASH_SetReadWritAddr0Reg(uint32_t addrValue)
{
    SFLASH->REG_SF_RADR0 = addrValue;
}

 /**
 * SFLASH_SetReadWritAddr1Reg
 *
 * @param[in]  addrValue: Flash address 1
 * @return : none
 *
 * @brief  Read or Write address 1 for Read command or Write command
 */
__STATIC_INLINE void SFLASH_SetReadWritAddr1Reg(uint32_t addrValue)
{
    SFLASH->REG_SF_RADR1 = addrValue;
}

 /**
 * SFLASH_SetReadWritAddr2Reg
 *
 * @param[in] addrValue:Flash address 2
 * @return : none
 *
 * @brief  Read or Write address 2 for Read command or Write command
 */
__STATIC_INLINE void SFLASH_SetReadWritAddr2Reg(uint32_t addrValue)
{
    SFLASH->REG_SF_RADR2 = addrValue;
}

 /**
 * SFLASH_WriteFlashDataReg
 *
 * @param  Flash write data
 * @return : none
 *
 * @brief The serial flash write data used by the Write Command
 */
__STATIC_INLINE void SFLASH_WriteFlashDataReg(uint32_t writeDataValue)
{
    SFLASH->REG_SF_WDATA = writeDataValue;
}


 /**
 * SFLASH_SetProgramData0Reg
 *
 * @param[in] programDataValue: The serial flash program shift data
 * @return : none
 *
 * @brief The serial flash program shift data 0 used by the PRG Command.
 */
__STATIC_INLINE void SFLASH_SetProgramData0Reg(uint32_t programDataValue)
{
    SFLASH->REG_SF_PRGDATA0 = programDataValue;
}

 /**
 * SFLASH_SetProgramData1Reg
 *
 * @param[in] programDataValue:The serial flash program shift data
 * @return : none
 *
 * @brief The serial flash program shift data 1 used by the PRG Command.
 */
__STATIC_INLINE void SFLASH_SetProgramData1Reg(uint32_t programDataValue)
{
    SFLASH->REG_SF_PRGDATA1 = programDataValue;
}

 /**
 * SFLASH_SetProgramData2Reg
 *
 * @param[in] programDataValue:The serial flash program shift data
 * @return : none
 *
 * @brief The serial flash program shift data 1 used by the PRG Command.
 */
__STATIC_INLINE void SFLASH_SetProgramData2Reg(uint32_t programDataValue)
{
    SFLASH->REG_SF_PRGDATA2 = programDataValue;
}

 /**
 * SFLASH_SetProgramData3Reg
 *
 * @param[in] programDataValue:The serial flash program shift data
 * @return : none
 *
 * @brief The serial flash program shift data 1 used by the PRG Command.
 */
__STATIC_INLINE void SFLASH_SetProgramData3Reg(uint32_t programDataValue)
{
    SFLASH->REG_SF_PRGDATA3 = programDataValue;
}

/**
 * SFLASH_SetProgramData4Reg
 *
 * @param[in] programDataValue:The serial flash program shift data
 * @return : none
 *
 * @brief The serial flash program shift data 1 used by the PRG Command.
 */
__STATIC_INLINE void SFLASH_SetProgramData4Reg(uint32_t programDataValue)
{
    SFLASH->REG_SF_PRGDATA4 = programDataValue;
}

 /**
 * SFLASH_SetProgramData5Reg
 *
 * @param[in] programDataValue:The serial flash program shift data
 * @return : none
 *
 * @brief The serial flash program shift data 1 used by the PRG Command.
 */
__STATIC_INLINE void SFLASH_SetProgramData5Reg(uint32_t programDataValue)
{
    SFLASH->REG_SF_PRGDATA5 = programDataValue;
}

/**
 * SFLASH_SetCFG1Reg
 *
 * @param[in] cfgValue:confige value
 * @return : none
 *
 * @brief  Set smodule Configure 1 register
 */
__STATIC_INLINE void SFLASH_SetCFG1Reg(uint32_t cfgValue)
{
    SFLASH->REG_SF_CFG1 = cfgValue;
}

/**
 * SFLASH_GetCFG1Reg
 *
 * @param :  none
 * @return : config 1 value
 *
 * @brief  Get smodule Configure 1 register
 */
__STATIC_INLINE int32_t SFLASH_GetCFG1Reg(void)
{
    return (SFLASH->REG_SF_CFG1);
}

 /**
 * SFLASH_SetCFG2Reg
 *
 * @param[in] cfgValue:confige value
 * @return : none
 *
 * @brief  Set smodule Configure 2 register
 */
__STATIC_INLINE void SFLASH_SetCFG2Reg(uint32_t cfgValue)
{
   SFLASH->REG_SF_CFG2 = cfgValue;
}

/**
 * SFLASH_GetCFG2Reg
 *
 * @param :  none
 * @return : config 2 value
 *
 * @brief  Get smodule Configure 2 register
 */
__STATIC_INLINE int32_t SFLASH_GetCFG2Reg(void)
{
    return (SFLASH->REG_SF_CFG2);
}

 /**
 * SFLASHHW_WRProtectReg
 *
 * @param[in]:  Write command enable value
 *          1: turn on write protection
 *          0: turn off write protection
 * @return : none
 *
 * @brief Write command enable register.
 */
__STATIC_INLINE void SFLASHHW_WRProtectReg(uint32_t isProtect)
{
    if (isProtect == 1)
    {
        SFLASH->REG_SF_WRPROT = 0x85;
    }
    else
    {
        SFLASH->REG_SF_WRPROT = 0x30;
    }
}

 /**
 * SFLASH_SetDualReg
 *
 * @param[in] dualValue:dual register value
 * @return : none
 *
 * @brief  set dual mode
 */
__STATIC_INLINE void SFLASH_SetDualReg(uint32_t dualValue)
{
    SFLASH->REG_SF_DUAL = dualValue;
}

 /**
 * SFLASH_GetDualReg
 *
 * @param none
 * @return : dual register value
 *
 * @brief  get dual mode
 */
__STATIC_INLINE uint8_t SFLASH_GetDualReg(void)
{
    return (SFLASH->REG_SF_DUAL);
}

 /**
 * SFLASH_SetProDataReg
 *
 * @param[in]  pageProgramData:Program data
 * @return : none
 *
 * @brief  Flash page program data register
 */
__STATIC_INLINE void SFLASH_SetProDataReg(uint32_t pageProgramData)
{
    SFLASH->REG_SF_PP_DW_DATA = pageProgramData;
}

 /**
 * SFLASH_SetWriteDataReg
 *
 * @param[in] writeData:write data
 * @return : none
 *
 * @brief  The serial flash write data used by the Write Command
 */
__STATIC_INLINE void SFLASH_SetWriteDataReg(uint32_t writeData)
{
    SFLASH->REG_SF_WDATA = writeData;
}

 /**
 * SFLASH_SetAAICMDReg
 *
 * @param[in] aaiCmd:aai comand data
 * @return : none
 *
 * @brief  Set AAI programming command enable register
 */
__STATIC_INLINE void SFLASH_SetAAICMDReg(uint32_t aaiCmd)
{
   SFLASH->REG_SF_AAICMD = aaiCmd;
}

 /**
 * SFLASH_ClearIntrstusReg
 *
 * @param[in] interruptStatus:interrupt status value
 * @return : none
 *
 * @brief  clear interrupt status bit
 */
__STATIC_INLINE void SFLASH_ClearIntrstusReg(uint8_t interruptStatus)
{
    SFLASH->REG_SF_INTRSTUS = interruptStatus;
}

 /**
 * SFLASH_GetIntrstusReg
 *
 * @param :none
 * @return : interrupt status
 *
 * @brief  get interrupt status
 */
__STATIC_INLINE uint8_t SFLASH_GetIntrstusReg(void)
{
return (SFLASH->REG_SF_INTRSTUS);
}

 /**
 * SFLASH_SetIntrEnReg
 *
 * @param[in] interruptStatus:interrupt enable value
 * @return : none
 *
 * @brief  Set interrup enable bit
 */
__STATIC_INLINE void SFLASH_SetIntrEnReg(uint8_t interruptEnable)
{
    SFLASH->REG_SF_INTREN = interruptEnable;
}

 /**
 * SFLASH_GetIntrEnReg
 *
 * @param :none
 * @return : interrupt enable value
 *
 * @brief  get interrup enable bit
 */
__STATIC_INLINE uint8_t SFLASH_GetIntrEnReg(void)
{
    return (SFLASH->REG_SF_INTREN);
}

/**
 * SFLASH_SetQSPIReg
 *
 * @param[in] qspiValue:QSPI value
 * @return : none
 *
 * @brief  Set QSPI config register
 */
__STATIC_INLINE void SFLASH_SetQSPIReg(uint8_t qspiValue)
{
    SFLASH->REG_QSPI_CFG = qspiValue;
}

/**
 * SFLASH_GetQSPIReg
 *
 * @param none
 * @return : QSPI config value
 *
 * @brief  Gest QSPI config register
 */
__STATIC_INLINE uint8_t SFLASH_GetQSPIReg(void)
{
    return (SFLASH->REG_QSPI_CFG);
}

/******************************************************************************
* Global functions
******************************************************************************/
void SFLASH_SetSFCMDReg(uint32_t commandValue);
int32_t SFLASH_GetSFCMDReg(void);
void SFLASH_SetPrgBitCountReg(uint8_t prgCountValue);
void SFLASHHW_WRProtectReg(uint32_t isProtect);
void SFLASH_SetControllerFastRead(uint32_t fastReadValue);
void SFLASH_GetControllerFastRead(void);
void SFLASH_SetReadWritAddr0Reg(uint32_t addrValue);
void SFLASH_SetReadWritAddr1Reg(uint32_t addrValue);
void SFLASH_SetReadWritAddr2Reg(uint32_t addrValue);
uint8_t SFLASH_ReadFlashDataReg(void);
void SFLASH_SetCFG2Reg(uint32_t commandValue);
int32_t SFLASH_GetCFG2Reg(void);
void SFLASH_SetProgramData5Reg(uint32_t programDataValue);
void SFLASH_SetProgramData4Reg(uint32_t programDataValue);
void SFLASH_SetProgramData3Reg(uint32_t programDataValue);
void SFLASH_SetProgramData2Reg(uint32_t programDataValue);
void SFLASH_SetProgramData1Reg(uint32_t programDataValue);
uint8_t SFLASH_ReadBackStatusReg(void);
void SFLASH_SetWriteDataReg(uint32_t writeData);
void SFLASH_SetProDataReg(uint32_t pageProgramData);
void SFLASH_ClearIntrstusReg(uint8_t interruptStatus);
uint8_t SFLASH_GetIntrstusReg(void);
void SFLASH_SetIntrEnReg(uint8_t interruptEnable);
uint8_t SFLASH_GetIntrEnReg(void);
void SFLASH_SetQSPIReg(uint8_t qspiValue);
uint8_t SFLASH_GetQSPIReg(void);

#ifdef __cplusplus
}
#endif
#endif
