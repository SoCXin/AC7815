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

#ifndef AC78XX_RTC_REG_H_
#define AC78XX_RTC_REG_H_
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

#include <stdint.h>

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
    struct {
        __IO uint32_t           : 4;    ///< Reserved
        __IO uint32_t RTCO      : 1;    ///< Real-Time Counter output
        __IO uint32_t           : 1;    ///< Reserved
        __IO uint32_t RTIE      : 1;    ///< Real-Time Interrupt Enable
        __IO uint32_t RTIF      : 1;    ///< Real-Time Interrupt Flag
        __IO uint32_t           : 6;    ///< Reserved
        __IO uint32_t RTCLKS    : 2;    ///< Real-Time Clock Source Select
        __IO uint32_t RPIE      : 1;    ///< Real-Time Prescaler Interrupt Enable
        __IO uint32_t RPIF      : 1;    ///< Real-Time Prescaler Interrupt Flag
        __IO uint32_t           : 14;   ///< Reserved
    } SC;                               ///< RTC Status and Control Register
    __IO uint32_t MOD;                  ///< RTC Modulo Register
    __I  uint32_t CNT;                  ///< RTC Counter Register
    __IO uint32_t RTCPS;                ///< RTC Real Time Prescaler Register
    __I  uint32_t PSCNT;                ///< RTC Prescaler Counter Register
    __I  uint32_t Reserved1;            ///< RTC reserved Register
    __I  uint32_t Reserved2;            ///< RTC reserved Register
    __I  uint32_t Reserved3;            ///< RTC reserved Register
    struct {
        __IO uint32_t TPE       : 1;    ///< Tamper Pin Enable
        __IO uint32_t TPAL      : 1;    ///< Tamper Pin Active Level
        __IO uint32_t           : 30;   ///< Reserved
    } BKP_CR;                           ///< Backup Control Register
    struct {
        __IO uint32_t CTE       : 1;    ///< Clear Tamper Event
        __IO uint32_t CTI       : 1;    ///< Clear Tamper Interrupt
        __IO uint32_t TPIE      : 1;    ///< Tamper Pin Interrupt Enable
        __IO uint32_t           : 5;    ///< Reserved
        __IO uint32_t TEF       : 1;    ///< Tamper Event Flag
        __IO uint32_t TIF       : 1;    ///< Tamper Interrupt Flag
        __IO uint32_t           : 22;   ///< Reserved
    } BKP_CSR;                          ///< Backup Control Status Register
    __IO uint32_t BKP_DR1;              ///< Backup Data Register 1
    __IO uint32_t BKP_DR2;              ///< Backup Data Register 2
    struct {
        __IO uint32_t RTCAL     : 7;    ///< RTC Calibration value
        __IO uint32_t RTCCO     : 1;    ///< RTC Calibration Clock output
        __IO uint32_t           : 24;   ///< Reserved
    } CALIB;                            ///< RTC Calibration Register 8, offset: 0x48
} RTC_Type;

// RTC - Peripheral instance base addresses
///< Peripheral RTC base address
#define RTC_BASE                                 (0x40008400u)
///< Peripheral RTC base pointer
#define RTC                                      ((RTC_Type *)RTC_BASE)
///< Array initializer of RTC peripheral base pointers
#define RTC_BASES                                { RTC }
//****************************************************************************


/******************************************************************************
* RTC API list
*******************************************************************************/

/**
* RTC_EnableRTIE
*
* @param[in] none
* @return none
*
* @brief  Enable RTC real-time interrupt
*/
__STATIC_INLINE void RTC_EnableRTIE(void)
{
    RTC->SC.RTIE = 1;
}


/**
* RTC_DisableRTIE
*
* @param[in] none
* @return none
*
* @brief  Disable RTC real-time interrupt
*/
__STATIC_INLINE void RTC_DisableRTIE(void)
{
    RTC->SC.RTIE = 0;
}

/**
 * RTC_EnableRPIE
 *
 * @param[in] none
 * @return none
 *
 * @brief  Enable RTC prescaler interrupt
 */
__STATIC_INLINE void RTC_EnableRPIE(void)
{
    RTC->SC.RPIE = 1;
}

/**
* RTC_DisableRPIE
*
* @param[in] none
* @return none
*
* @brief  Disable RTC prescaler interrupt
*/
__STATIC_INLINE void RTC_DisableRPIE(void)
{
    RTC->SC.RPIE = 0;
}

/**
* RTC_SetModulo
*
* @param[in]  modValue: 32bit RTC modulo value
* @return none
*
* @brief  Set RTC modulo value
*/
__STATIC_INLINE void RTC_SetModulo(uint32_t modValue)
{
    RTC->MOD = modValue;
}

/**
* RTC_getModulo
*
* @param[in] none
* @return none
*
* @brief  Get RTC modulo value
*/
__STATIC_INLINE uint32_t RTC_getModulo(void)
{
    return (RTC->MOD);
}
/**
* RTC_getCNT
*
* @param[in] none
* @return none
*
* @brief  Get RTC cnt value
*/
__STATIC_INLINE uint32_t RTC_getCNT(void)
{
    return (RTC->CNT);
}

/**
* RTC_SetClkSource
*
* @param[in] clockNumber: 0:bus clk; 1:internal 32KHz; 2:external osciallator; 3: internal 8M osciallator
* @return none
*
* @brief  Set RTC clock source
*/
__STATIC_INLINE void RTC_SetClkSource(uint32_t clockNumber)
{
    RTC->SC.RTCLKS = clockNumber;
}

/**
* RTC_SetPres
*
* @param[in]  presalcer: 20bit RTC prescaler value
* @return none
*
* @brief  Set RTC prescaler value
*/
__STATIC_INLINE void RTC_SetPres(uint32_t prescaler)
{
    RTC->RTCPS = prescaler;
}

/**
* RTC_SetRTCAL
*
* @param[in]  RTCAL: calibration value
* @return none
*
* @brief  Set RTC calibration value
*/
__STATIC_INLINE void RTC_SetRTCAL(uint32_t RTCAL)
{
    RTC->CALIB.RTCAL = RTCAL;
}

/**
* RTC_SetRTCO
*
* @param[in] RTCO: 0:disable; 1:enable
* @return none
*
* @brief  Set RTC counter output
*/
__STATIC_INLINE void RTC_SetRTCO(uint32_t RTCO)
{
    RTC->SC.RTCO = RTCO;
}

/**
* RTC_SetRTCCO
*
* @param[in] RTCCO: 0:disable; 1:enable
* @return none
*
* @brief  enable RTC calibration clock output
*/
__STATIC_INLINE void RTC_SetRTCCO(uint32_t RTCCO)
{
    RTC->CALIB.RTCCO = RTCCO;
}

/**
* RTC_GetRTIF
*
* @param[in]  none
* @return 0: RTC counter has not reached the value in the RTC modulo register
*         1: RTC counter has reached the value in the RTC modulo register.
*
* @brief  Get RTC interrupt flag
*/
__STATIC_INLINE uint32_t RTC_GetRTIF(void)
{
    return (RTC->SC.RTIF);
}


/**
* RTC_ClrRTIF
*
* @param[in]  none
* @return none
*
* @brief  Clear RTC interrupt flag
*/
__STATIC_INLINE void RTC_ClrRTIF(void)
{
    RTC->SC.RTIF = 1;         // Write 1 to clear
}

/**
* RTC_GetRPIF
*
* @param[in]  none
* @return 0: RTC Prescaler counter has not reached the value in the RTC prescaler divider register.
*         1: RTC Prescaler counter has reached the value in the RTC prescaler divider register.
*
* @brief  Get RTC prescaler interrupt flag
*/
__STATIC_INLINE uint32_t RTC_GetRPIF(void)
{
    return (RTC->SC.RPIF);
}

/**
* RTC_ClrRPIF
*
* @param[in]  none
* @return none
*
* @brief  Clear RTC prescaler interrupt flag
*/
__STATIC_INLINE void RTC_ClrRPIF(void)
{
    RTC->SC.RPIF = 1;               // Write 1 to clear
}

/**
* BKP_EnableTPE
*
* @param[in]  none
* @return none
*
* @brief  Enable BKP Tamper pin
*/
__STATIC_INLINE void BKP_EnableTPE(void)
{
    RTC->BKP_CR.TPE = 1;
}

/**
* BKP_DisableTPE
*
* @param[in]  none
* @return none
*
* @brief  Disable BKP Tamper pin
*/
__STATIC_INLINE void BKP_DisableTPE(void)
{
    RTC->BKP_CR.TPE = 0;
}

/**
* BKP_SetTPAL
*
* @param[in]  TPAL: 0: a high level; 1: a low level
* @return none
*
* @brief  Set BKP Tamper pin active level
*/
__STATIC_INLINE void BKP_SetTPAL(uint32_t TPAL)
{
    RTC->BKP_CR.TPAL = TPAL;
}

/**
* BKP_CTE
*
* @param[in]  none
* @return none
*
* @brief  Clear BKP Tamper event
*/
__STATIC_INLINE void BKP_CTE(void)
{
    RTC->BKP_CSR.CTE = 1;
}

/**
* BKP_CTI
*
* @param[in]  none
* @return none
*
* @brief  Clear BKP Tamper interrupt
*/
__STATIC_INLINE void BKP_CTI(void)
{
    RTC->BKP_CSR.CTI = 1;
}

/**
* BKP_EnableTPI
*
* @param[in]  none
* @return none
*
* @brief  Enable BKP Tamper pin interrupt
*/
__STATIC_INLINE void BKP_EnableTPI(void)
{
    RTC->BKP_CSR.TPIE = 1;
}

/**
* BKP_DisableTPI
*
* @param[in]  none
* @return none
*
* @brief  Disable BKP Tamper pin interrupt
*/
__STATIC_INLINE void BKP_DisableTPI(void)
{
    RTC->BKP_CSR.TPIE = 0;
}

/**
* BKP_IsTEF
*
* @param[in]  none
* @return 0: no Tamper event,1: a Tamper event occurred
*
* @brief  check BKP Tamper pin event flag
*/
__STATIC_INLINE uint32_t BKP_IsTEF(void)
{
    return (RTC->BKP_CSR.TEF);
}

/**
* BKP_ClrTEF
*
* @param[in]  none
* @return none
*
* @brief  Clear BKP Tamper pin event flag
*/
__STATIC_INLINE void BKP_ClrTEF(void)
{
    RTC->BKP_CSR.CTE = 1;
}

/**
* BKP_IsTIF
*
* @param[in]  none
* @return 0: no Tamper interrupt,1: a Tamper interrupt occurred
*
* @brief  check BKP Tamper pin interrupt flag
*/
__STATIC_INLINE uint32_t BKP_IsTIF(void)
{
    return (RTC->BKP_CSR.TIF);
}

/**
* BKP_ClrTIF
*
* @param[in]  none
* @return none
*
* @brief  Clear BKP Tamper pin interrupt flag
*/
__STATIC_INLINE void BKP_ClrTIF(void)
{
    RTC->BKP_CSR.CTI = 1;
}

/******************************************************************************
* Global functions
******************************************************************************/
void RTC_EnableRTIE(void);
void RTC_DisableRTIE(void);
void RTC_EnableRPIE(void);
void RTC_DisableRPIE(void);
void RTC_SetModulo(uint32_t modValue);
uint32_t RTC_getModulo(void);
uint32_t RTC_getCNT(void);
void RTC_SetClkSource(uint32_t clockNumber);
void RTC_SetPres(uint32_t prescaler);
void RTC_SetRTCAL(uint32_t RTCAL);
void RTC_SetRTCO(uint32_t RTCO);
void RTC_SetRTCCO(uint32_t RTCCO);
uint32_t RTC_GetRTIF(void);
void RTC_ClrRTIF(void);
uint32_t RTC_GetRPIF(void);

void RTC_ClrRPIF(void);
void BKP_EnableTPE(void);
void BKP_DisableTPE(void);
void BKP_SetTPAL(uint32_t TPAL);
void BKP_CTE(void);
void BKP_CTI(void);
void BKP_EnableTPI(void);
void BKP_DisableTPI(void);
uint32_t BKP_IsTEF(void);
void BKP_ClrTEF(void);
uint32_t BKP_IsTIF(void);
void BKP_ClrTIF(void);

#ifdef __cplusplus
}
#endif

#endif
