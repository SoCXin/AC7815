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

#ifndef _AC78XX_EFLASH_REG_H_
#define _AC78XX_EFLASH_REG_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "stdio.h"

#define __IO    volatile                    
#define __I     volatile const 
//#define __STATIC_INLINE static __inline

typedef struct {
    __IO uint32_t REG_EFLASH_KEY;           ///< Key sequence register,                   offset: 0x00 	
    __IO uint32_t REG_EFLASH_INFO;          ///< Chip information,                        offset: 0x04 
    __IO uint32_t REG_EFLASH_ADR_CMD;       ///< Erase start address,                     offset: 0x08 
    __IO uint32_t REG_EFLASH_CTRL1;         ///< Control register 1,                      offset: 0x0C         
    __IO uint32_t REG_EFLASH_SR1;           ///< Status register 1,                       offset: 0x10 
    __IO uint32_t REG_EFLASH_CTRL2;         ///< Control register 2,                      offset: 0x14 
    __IO uint32_t REG_EFLASH_PRT1;          ///< Write protect 1,                         offset: 0x18 
    __IO uint32_t REG_EFLASH_PRT2;          ///< Write protect 2,                         offset: 0x1C 
    __IO uint32_t REG_EFLASH_CHIP_NAME;     ///< Chip name,                               offset: 0x20    
    __IO uint32_t REG_EFLASH_CHIP_ID1;      ///< Chip ID 1,                               offset: 0x24         
    __IO uint32_t REG_EFLASH_CHIP_ID2;      ///< Chip ID 2,                               offset: 0x28         
    __IO uint32_t REG_EFLASH_CHIP_ID3;      ///< Chip ID 3,                               offset: 0x2C         
    __IO uint32_t REG_EFLASH_CHIP_ID4;      ///< Chip ID 4,                               offset: 0x30         
    __IO uint32_t REG_EFLASH_CALI1;         ///< Calibration and enable information 1,    offset: 0x34         		
    __IO uint32_t REG_EFLASH_CALI2;         ///< Calibration and enable information 2,    offset: 0x38 
    __IO uint32_t REG_EFLASH_SW;            ///< Software usage,                          offset: 0x3C 
    __IO uint32_t REG_EFLASH_GRPRW;         ///< Test signal group control,               offset: 0x40 
    __IO uint32_t REG_EFLASH_CALI3;         ///< Calibration and enable information 3,    offset: 0x44 
} EFLASH_Type;

typedef struct {
    uint32_t RDP_WDT;      
    uint32_t PRT_S1;
    uint32_t PRT_S2;
    uint32_t PRT_S3;
    uint32_t PRT_S4;
}OPTION_TYPE;  

#define EFLASH_BASE (0x40002000u)               ///< eFlash - Peripheral instance base addresses  
#define EFLASH  ((EFLASH_Type *)EFLASH_BASE)    ///< Peripheral EFlash base pointer 
#define EFLASH_BASES    { EFLASH }              ///< Array initializer of EFlash peripheral base pointers 

#define OPTION_BASE (0x08040000u)               ///< eFlash - Optoion byte base addresses  
#define OPTION_END  (0x08040020u)               ///< eFlash - Optoion byte end addresses  
#define OPTION  ((OPTION_TYPE *)OPTION_BASE)    ///< Option byte base pointer 
#define OPTION_BASES    { OPTION }              ///< Array initializer of option byte base pointers 

#define EFLASH_ADDRESS_BASE (0x08000000u)   ///< Based address of eflash user area
#define EFLASH_SIZE         (0x00040000u)   ///< Total size for eflash user area
#define EFLASH_PAGE_SIZE    (0x00000800u)   ///< eflash page size
#define EFLASH_ADDRESS_END  (EFLASH_ADDRESS_BASE+EFLASH_SIZE)

// EFLASH Register Masks
#define EFLSH_INFO_RD_PDR_POS           0                                               ///< EFLSH_INFO: RD_PDR Position                  
#define EFLSH_INFO_RD_PDR_MSK           (0x01UL << EFLSH_INFO_RD_PDR_POS)               ///< EFLSH_INFO: RD_PDR Mask                      
#define EFLSH_INFO_WDTEN_POS            1                                               ///< EFLSH_INFO: WDT_EN Position                 
#define EFLSH_INFO_WDTEN_MSK            (0x01UL << EFLSH_INFO_WDTEN_POS)                ///< EFLSH_INFO: WDT_EN Mask                     
#define EFLSH_INFO_SG_WREN_POS          2                                               ///< EFLSH_INFO: SG_WR_EN Position              
#define EFLSH_INFO_SG_WREN_MSK          (0x01UL << EFLSH_INFO_SG_WREN_POS)              ///< EFLSH_INFO: SG_WR_EN Mask                  
#define EFLSH_INFO_SRAMSZ_POS           4                                               ///< EFLSH_INFO: SRAM_SIZE Position              
#define EFLSH_INFO_SRAMSZ_MSK           (0x0FUL << EFLSH_INFO_SRAMSZ_POS)               ///< EFLSH_INFO: SRAM_SIZE Mask                  
#define EFLSH_INFO_EFLASHSZ_POS         8                                               ///< EFLSH_INFO: EFLASH_SIZE Position            
#define EFLSH_INFO_EFLASHSZ_MSK         (0x0FUL << EFLSH_INFO_EFLASHSZ_POS)             ///< EFLSH_INFO: EFLASH_SIZE Mask               
#define EFLSH_INFO_PKGIF_POS            12                                              ///< EFLSH_INFO: PKG_INFO Position              
#define EFLSH_INFO_PKGIF_MSK            (0xFFFUL << EFLSH_INFO_PKGIF_POS)               ///< EFLSH_INFO: PKG_INFO  Mask                 
#define EFLSH_INFO_CANX_EN_POS          24                                              ///< EFLSH_INFO: CANx_EN Position               
#define EFLSH_INFO_CANX_EN_MSK          (0x0FUL << EFLSH_INFO_CANX_EN_POS)              ///< EFLSH_INFO: CANx_EN Mask                   
#define EFLSH_INFO_LOCKIF_POS           28                                              ///< EFLSH_INFO: LOCKST Position                
#define EFLSH_INFO_LOCKIF_MSK           (0x01UL << EFLSH_INFO_LOCKIF_POS)               ///< EFLSH_INFO: LOCKST Mask                    
#define EFLSH_INFO_LOCK_POS             31                                              ///< EFLSH_INFO: LOCK Position                  
#define EFLSH_INFO_LOCK_MSK             (0x01UL << EFLSH_INFO_LOCK_POS)                 ///< EFLSH_INFO: LOCK Mask                      

// EFLSH_CTRL1
#define EFLSH_CTRL1_CMD_CTL_POS         0                                               ///< EFLSH_CTRL1: CMD_CTL Position                  
#define EFLSH_CTRL1_CMD_CTL_MSK         (0x0FUL << EFLSH_CTRL1_CMD_CTL_POS)             ///< EFLSH_CTRL1: CMD_CTL Mask                      
#define EFLSH_CTRL1_CMD_ST_POS          4                                               ///< EFLSH_CTRL1: CMD_ST Position                 
#define EFLSH_CTRL1_CMD_ST_MSK          (0x01UL << EFLSH_CTRL1_CMD_ST_POS)              ///< EFLSH_CTRL1: CMD_ST Mask                     
#define EFLSH_CTRL1_EOPIE_POS           8                                               ///< EFLSH_CTRL1: EOPIE Position              
#define EFLSH_CTRL1_EOPIE_MSK           (0x01UL << EFLSH_CTRL1_EOPIE_POS)               ///< EFLSH_CTRL1: EOPIE Mask                  
#define EFLSH_CTRL1_RDRTIE_POS          9                                               ///< EFLSH_CTRL1: RDRTIE Position              
#define EFLSH_CTRL1_RDRTIE_MSK          (0x01UL << EFLSH_CTRL1_RDRTIE_POS)              ///< EFLSH_CTRL1: RDRTIE Mask                  
#define EFLSH_CTRL1_WRPTIE_POS          10                                               ///< EFLSH_CTRL1: WRPTIE Position              
#define EFLSH_CTRL1_WRPTIE_MSK          (0x01UL << EFLSH_CTRL1_WRPTIE_POS)              ///< EFLSH_CTRL1: WRPTIE Mask                  
#define EFLSH_CTRL1_OPT_CMD_EN_POS      12                                              ///< EFLSH_CTRL1: OPT_CMD_EN Position              
#define EFLSH_CTRL1_OPT_CMD_EN_MSK      (0x01UL << EFLSH_CTRL1_OPT_CMD_EN_POS)          ///< EFLSH_CTRL1: OPT_CMD_EN Mask                  
#define EFLSH_CTRL1_PROG_LENGTH_POS     16                                              ///< EFLSH_CTRL1: PROG_LENGTH Position            
#define EFLSH_CTRL1_PROG_LENGTH_MSK     (0x03FFUL << EFLSH_CTRL1_PROG_LENGTH_POS)       ///< EFLSH_CTRL1: PROG_LENGTH Mask               
#define EFLSH_CTRL1_HDFEN_POS           31                                              ///< EFLSH_CTRL1: Hardfault  interrupt enable Position            
#define EFLSH_CTRL1_HDFEN_MSK           (0x01UL << EFLSH_CTRL1_HDFEN_POS)               ///< EFLSH_CTRL1: Hardfault  interrupt enable Mask               

// EFLSH_CTRL2
#define EFLSH_CTRL2_CKDIV_POS           0                                               ///< EFLSH_CTRL2: CKDIV Position                  
#define EFLSH_CTRL2_CKDIV_MSK           (0x7FUL << EFLSH_CTRL2_CKDIV_POS)               ///< EFLSH_CTRL2: CKDIV Mask                      
#define EFLSH_CTRL2_CKDIV_LOCK_POS      8                                               ///< EFLSH_CTRL2: CKDIV_LOCK Position                 
#define EFLSH_CTRL2_CKDIV_LOCK_MSK      (0x01UL << EFLSH_CTRL2_CKDIV_LOCK_POS)          ///< EFLSH_CTRL2: CKDIV_LOCK Mask                     
#define EFLSH_CTRL2_SPEED_LATENCY_POS   12                                              ///< EFLSH_CTRL2: SPEED_LATENCY Position              
#define EFLSH_CTRL2_SPEED_LATENCY_MSK   (0x03UL << EFLSH_CTRL2_SPEED_LATENCY_POS)               ///< EFLSH_CTRL2: SPEED_LATENCY Mask                  

#define EFLSH_SR1_CMD_BSY_POS           0                                               ///< EFLSH_SR1: CMD_BSY Position                  
#define EFLSH_SR1_CMD_BSY_MSK           (0x01UL << EFLSH_SR1_CMD_BSY_POS)               ///< EFLSH_SR1: CMD_BSY Mask                      
#define EFLSH_SR1_EOP_POS               1                                               ///< EFLSH_SR1: OPR_EOP Position                 
#define EFLSH_SR1_EOP_MSK               (0x01UL << EFLSH_SR1_EOP_POS)               ///< EFLSH_SR1: OPR_EOP Mask                     
#define EFLSH_SR1_WRER_POS              2                                               ///< EFLSH_SR1: WRER Position              
#define EFLSH_SR1_WRER_MSK              (0x01UL << EFLSH_SR1_WRER_POS)                  ///< EFLSH_SR1: WRER Mask 
#define EFLSH_SR1_RDER_POS              3                                               ///< EFLSH_SR1: RDER Position              
#define EFLSH_SR1_RDER_MSK              (0x01UL << EFLSH_SR1_RDER_POS)                  ///< EFLSH_SR1: RDER Mask                  
#define EFLSH_SR1_PPERER_POS            4                                               ///< EFLSH_SR1: PPERER Position              
#define EFLSH_SR1_PPERER_MSK            (0x01UL << EFLSH_SR1_PPERER_POS)                ///< EFLSH_SR1: PPERER Mask
#define EFLSH_SR1_PPADRER_POS           5                                               ///< EFLSH_SR1: PPADRER Position            
#define EFLSH_SR1_PPADRERR_MSK          (0x01UL << EFLSH_SR1_PPADRER_POS)               ///< EFLSH_SR1: PPADRER Mask 
#define EFLSH_SR1_ERAER_POS             6                                               ///< EFLSH_SR1: ERAER Position            
#define EFLSH_SR1_ERAER_MSK             (0x01UL << EFLSH_SR1_ERAER_POS)                 ///< EFLSH_SR1: ERAER Mask
#define EFLSH_SR1_VRER_POS              7                                               ///< EFLSH_SR1: VRER Position            
#define EFLSH_SR1_VRER_MSK              (0x01UL << EFLSH_SR1_VRER_POS)                  ///< EFLSH_SR1: VRER Mask                     
#define EFLSH_SR1_OPTER_POS             8                                               ///< EFLSH_SR1: OPTER Position            
#define EFLSH_SR1_OPTER_MSK             (0x0FUL << EFLSH_SR1_OPTER_POS)                 ///< EFLSH_SR1: OPTER Mask               
#define EFLSH_SR1_FLUSH_POS             12                                              ///< EFLSH_SR1: FLUSH Position               
#define EFLSH_SR1_FLUSH_MSK             (0x01UL << EFLSH_SR1_FLUSH_POS)                 ///< EFLSH_SR1: FLUSH Mask                   
#define EFLSH_SR1_EFLASH_IRQ_POS        20                                              ///< EFLSH_SR1: EFLASH_IRQ Position                
#define EFLSH_SR1_EFLASH_IRQ_MSK        (0xFFUL << EFLSH_SR1_EFLASH_IRQ_POS)            ///< EFLSH_SR1: EFLASH_IRQ Mask                    
#define EFLSH_SR1_ERROR_MSK             0x7FFFC                                         ///< EFLSH_SR1: EFLASH all error Mask

// EFLSH_PRT1
#define EFLSH_PRT1_S1_ST_POS            0                                               ///< EFLSH_PRT1: S1_ST Position                  
#define EFLSH_PRT1_S1_ST_MSK            (0xEFUL << EFLSH_PRT1_S1_ST_POS)                ///< EFLSH_PRT1: S1_ST Mask                      
#define EFLSH_PRT1_S1_LEN_POS           8                                               ///< EFLSH_PRT1: S1_LEN Position                 
#define EFLSH_PRT1_S1_LEN_MSK           (0xEFUL << EFLSH_PRT1_S1_LEN_POS)               ///< EFLSH_PRT1: S1_LEN Mask                     
#define EFLSH_PRT1_S1_EN_POS            15                                              ///< EFLSH_PRT1: S1_EN Position                 
#define EFLSH_PRT1_S1_EN_MSK            (0x01UL << EFLSH_PRT1_S1_EN_POS)                ///< EFLSH_PRT1: S1_EN Mask                     
#define EFLSH_PRT1_S2_ST_POS            16                                              ///< EFLSH_PRT1: S2_ST Position                  
#define EFLSH_PRT1_S2_ST_MSK            (0xEFUL << EFLSH_PRT1_S2_ST_POS)                ///< EFLSH_PRT1: S2_ST Mask                      
#define EFLSH_PRT1_S2_LEN_POS           24                                              ///< EFLSH_PRT1: S2_LEN Position                 
#define EFLSH_PRT1_S2_LEN_MSK           (0xEFUL << EFLSH_PRT1_S2_LEN_POS)               ///< EFLSH_PRT1: S2_LEN Mask                     
#define EFLSH_PRT1_S2_EN_POS            31                                              ///< EFLSH_PRT1: S2_EN Position                 
#define EFLSH_PRT1_S2_EN_MSK            (0x01UL << EFLSH_PRT1_S2_EN_POS)                ///< EFLSH_PRT1: S2_EN Mask                     

//  EFLSH_PRT2
#define EFLSH_PRT2_S3_ST_POS            0                                               ///< EFLSH_PRT2: S3_ST Position                  
#define EFLSH_PRT2_S3_ST_MSK            (0xEFUL << EFLSH_PRT2_S3_ST_POS)                ///< EFLSH_PRT2: S3_ST Mask                      
#define EFLSH_PRT2_S3_LEN_POS           8                                               ///< EFLSH_PRT2: S3_LEN Position                 
#define EFLSH_PRT2_S3_LEN_MSK           (0xEFUL << EFLSH_PRT2_S3_LEN_POS)               ///< EFLSH_PRT2: S3_LEN Mask                     
#define EFLSH_PRT2_S3_EN_POS            15                                              ///< EFLSH_PRT2: S3_EN Position                 
#define EFLSH_PRT2_S3_EN_MSK            (0x01UL << EFLSH_PRT2_S3_EN_POS)                ///< EFLSH_PRT2: S3_EN Mask                     
#define EFLSH_PRT2_S4_ST_POS            16                                              ///< EFLSH_PRT2: S4_ST Position                  
#define EFLSH_PRT2_S4_ST_MSK            (0xEFUL << EFLSH_PRT2_S4_ST_POS)                ///< EFLSH_PRT2: S4_ST Mask                      
#define EFLSH_PRT2_S4_LEN_POS           24                                              ///< EFLSH_PRT2: S4_LEN Position                 
#define EFLSH_PRT2_S4_LEN_MSK           (0xEFUL << EFLSH_PRT2_S4_LEN_POS)               ///< EFLSH_PRT2: S4_LEN Mask                     
#define EFLSH_PRT2_S4_EN_POS            31                                              ///< EFLSH_PRT2: S4_EN Position                 
#define EFLSH_PRT2_S4_EN_MSK            (0x01UL << EFLSH_PRT2_S4_EN_POS)                ///< EFLSH_PRT2: S4_EN Mask                     

//eflash unlcok key value
#define EFLSH_UNLOCK_KEY1   0xac7811UL      ///< eflash controler ulock key 1
#define EFLSH_UNLOCK_KEY2   0x01234567UL    ///< eflash controler ulock key 2


#define EFLASH_WREG8(_reg_, _val_)              (*((volatile uint8_t*)(_reg_)) = (_val_))
#define EFLASH_RREG8(_reg_)                     (*((volatile uint8_t*)(_reg_)))

#define EFLASH_WREG32(_reg_, _val_)             (*((volatile uint32_t*)(_reg_)) = (_val_))
#define EFLASH_RREG32(_reg_)                    (*((volatile uint32_t*)(_reg_)))

#define LoWord(d)                               ((uint16_t)(d & 0x0000ffffL))
#define HiWord(d)                               ((uint16_t)((d >> 16) & 0x0000ffffL))
#define LoByte(w)                               ((uint8_t)(w & 0x00ff))
#define HiByte(w)                               ((uint8_t)((w >> 8) & 0x00ff))
#define MidWord(d)                              ((uint16_t)((d >>8) & 0x00ffff))

/**
 * EFLASH_SetKeyReg
 *
 * @param[in]  keyValue: unlock eflash controler key value 
 * @return  none
 *
 * @brief  : Set eflash key sequence register                                                 
 */
__STATIC_INLINE void EFLASH_SetKeyReg(uint32_t keyValue)
{
   EFLASH->REG_EFLASH_KEY = keyValue;
} 

/**
 * EFLASH_GetReadProtectReg
 *
 * @param[in] none 
 * @return 0: not in read protection, 1: in read protection
 *
 * @brief  Get protect status
 */
__STATIC_INLINE uint8_t EFLASH_GetReadProtectReg(void)
{  
    return (EFLASH->REG_EFLASH_INFO & EFLSH_INFO_RD_PDR_MSK);
} 

 /**
 * EFLASH_GetCrlLockBitReg
 *
 * param[in] none 
 * @return 0: eFlash control is unlocked, 1: eFlash control is locked
 *
 * @brief  Get the can eflash controler lock bit
 */
__STATIC_INLINE uint16_t EFLASH_GetCrlLockBitReg(void)
{
   return (EFLASH->REG_EFLASH_INFO & EFLSH_INFO_LOCK_MSK) >> EFLSH_INFO_LOCK_POS;
}

 /**
 * EFLASH_LockCtrlReg
 *
 * @param[in] none 
 * @return  none
 *
 * @brief  Lock eflash controler
 */
__STATIC_INLINE void EFLASH_LockCtrlReg(void)
{
    EFLASH->REG_EFLASH_INFO |= EFLSH_INFO_LOCK_MSK;
}

 /**
 * EFLASH_SetStartAddressReg
 *
 * @param[in]  startAddress: start address 
 * @return  none
 *
 * @brief  Set program or erase start address
 */
__STATIC_INLINE void EFLASH_SetStartAddressReg(uint32_t startAddress)
{
    EFLASH->REG_EFLASH_ADR_CMD = (0x000FFFFF & startAddress);
}

 /**
 * EFLASH_SetCtlReg1
 *
 * @param[in]  ctrl1Value: Command
 * @return  none
 *
 * @brief  Set eflash conrtol register 1 
 */
__STATIC_INLINE void EFLASH_SetCtlReg1(uint32_t ctrl1Value)
{
    EFLASH->REG_EFLASH_CTRL1 = ctrl1Value;
}


 /**
 * EFLASH_SetCtlCmdReg
 *
 * @param[in]  cmdValue: Command
 * @return  none
 *
 * @brief  Set eflash ommand 
 */
__STATIC_INLINE void EFLASH_SetCtlCmdReg(uint8_t cmdValue)
{
    EFLASH->REG_EFLASH_CTRL1 &=~ EFLSH_CTRL1_CMD_CTL_MSK;
    EFLASH->REG_EFLASH_CTRL1 |= cmdValue << EFLSH_CTRL1_CMD_CTL_POS;
}

 /**
 * EFLASH_TrigCtlCmdReg
 *
 * @param[in] none 
 * @return  none
 *
 * @brief  Trigger the command to start
 */
__STATIC_INLINE void EFLASH_TrigCtlCmdReg(void)
{
    EFLASH->REG_EFLASH_CTRL1 |= EFLSH_CTRL1_CMD_ST_MSK;
}

 /**
 * EFLASH_EnableCtlHardfault
 *
 * @param[in] none 
 * @return  none
 *
 * @brief  Hardfault  interrupt enable
 */
__STATIC_INLINE void EFLASH_EnableCtlHardfault(void)
{
    EFLASH->REG_EFLASH_CTRL1 |= EFLSH_CTRL1_HDFEN_MSK;
}

__STATIC_INLINE void EFLASH_Flushflash(void)
{
    EFLASH->REG_EFLASH_SR1 |= EFLSH_SR1_FLUSH_MSK;
}


/**
 * EFLASH_GetEopReg
 *
 * @param[in] none 
 * @return 0: not finished,1: finished
 *
 * @brief  Get status that indicate whether command operation is finished   
 */
__STATIC_INLINE uint8_t EFLASH_GetEopReg(void)
{
    return ((EFLASH->REG_EFLASH_SR1 & EFLSH_SR1_EOP_MSK) >> EFLSH_SR1_EOP_POS);
}

 /**
 * EFLASH_ClearEopReg
 *
 * @param   none 
 * @return  none
 *
 * @brief  Get status that indicate whether command operation is finished   
 */
__STATIC_INLINE void EFLASH_ClearEopReg(void)
{
    EFLASH->REG_EFLASH_SR1 |= EFLSH_SR1_EOP_MSK; 
}

 /**
 * EFLASH_GetAnyBusySTReg
 *
 * @param[in] none 
 * @return : 
    0: all operations are not in process
    1: at least one operation in process
 *
 * @brief  Get status that indicate whether any of the command operations is in process  
 */
__STATIC_INLINE uint8_t EFLASH_GetAnyBusySTReg(void)
{
    return ((EFLASH->REG_EFLASH_SR1 & EFLSH_SR1_CMD_BSY_MSK) >> EFLSH_SR1_CMD_BSY_POS);
}

 /**
 * EFLASH_GetStatusReg
 *
 * @param[in] none 
 * @return :  status value 
 *
 * @brief  Get the error status for  main memory   
 */
__STATIC_INLINE uint32_t EFLASH_GetStatusReg(void)
{
    return (EFLASH->REG_EFLASH_SR1);
}

 /**
 * EFLASH_FlushOperation
 *
 * @param   none 
 * @return  none
 *
 * @brief fore the program command operation to be finished  
 */
__STATIC_INLINE void EFLASH_FlushOperation(void)
{
    EFLASH->REG_EFLASH_SR1 |= EFLSH_SR1_FLUSH_MSK; 
}

 /**
 * EFLASH_SetCtrl2Reg
 *
 * @param  ctrlValue: Controler register 2 value 
 * @return  none
 *
 * @brief  Set controler register 2
 */
__STATIC_INLINE void EFLASH_SetCtrl2Reg(uint32_t ctrlValue )
{
    EFLASH->REG_EFLASH_CTRL2 = ctrlValue;
}

 /**
 * EFLASH_GetCtrl2Reg
 *
 * @param  ctrlValue: Controler register 2 value 
 * @return  none
 *
 * @brief  Set controler register 2
 */
__STATIC_INLINE uint32_t EFLASH_GetCtrl2Reg(void)
{
    return (EFLASH->REG_EFLASH_CTRL2);
}

 /**
 * EFLASH_GetWriteProReg1
 *
 * @param[in] none  
 * @return : Write protect register 1 value
 *
 * @brief  Get Write protect register 1 value 
 */
__STATIC_INLINE uint32_t EFLASH_GetWriteProReg1(void)
{
    return (EFLASH->REG_EFLASH_PRT1);
}

 /**
 * EFLASH_GetWriteProteReg2
 *
 * @param[in] none 
 * @return : Write protect register 2 value
 *
 * @brief  Get Write protect register 2 value 
 */
__STATIC_INLINE uint32_t EFLASH_GetWriteProReg2(void)
{
    return (EFLASH->REG_EFLASH_PRT2);
}

#ifdef __cplusplus
}
#endif
#endif
