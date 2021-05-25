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

#ifndef __AC78XX_CAN_REG_H__
#define __AC78XX_CAN_REG_H__

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

#include "ac78xx.h"

#define __IO    volatile                    //All drivers need this type
#define __I     volatile const

#if defined ( __ICCARM__ )
#define __STATIC_INLINE static inline
#elif defined ( __GNUC__)
#define __STATIC_INLINE static inline
#elif defined (__CC_ARM)
#define __STATIC_INLINE static __inline
#endif

#define CAN_BUF_LENGTH (64 / 4)                 ///< CAN buffer length (only use 8 Bytes)

///< CAN receive buffer register define structure
typedef volatile struct
{
    uint32_t ID                     : 29;   ///< Identifier
    uint32_t                        : 2;    ///< Reserved
    uint32_t                        : 1;    ///< Reserved
    uint32_t DLC                    : 4;    ///< Data length code
    uint32_t                        : 1;    ///< Reserved
    uint32_t                        : 1;    ///< Reserved
    uint32_t RTR                    : 1;    ///< Remote transmission request
    uint32_t IDE                    : 1;    ///< Identifier extension
    uint32_t CYCLE_TIME             : 16;   ///< Cycle time for TTCAN
    uint32_t                        : 8;    ///< Reserved
    uint32_t Data[CAN_BUF_LENGTH];          ///< Buffer data
    uint32_t RTS[2];                        ///< Receive time stamps
} CAN_RBUF_TYPE;

///< CAN transmit buffer register define structure
typedef volatile struct
{
    uint32_t ID                  : 29;      ///< Identifier
    uint32_t                     : 3;       ///< Reserved
    uint32_t DLC                 : 4;       ///< Data length code
    uint32_t                     : 1;       ///< Reserved
    uint32_t                     : 1;       ///< Reserved
    uint32_t RTR                 : 1;       ///< Remote transmission request
    uint32_t IDE                 : 1;       ///< Identifier extension
    uint32_t                     : 24;      ///< Reserved
    uint32_t Data[CAN_BUF_LENGTH];          ///< Buffer data
    uint32_t TTS[2];                        ///< Transmission Time Stamp
} CAN_TBUF_TYPE;

enum {
    BUSOFF                           = 0x01,    ///< bus off status
    TACTIVE                          = 0x02,    ///< transmission active status
    RACTIVE                          = 0x04,    ///< reception active status
    TSSS                             = 0x08,    ///< transmit STB - single shot mode
    TPSS                             = 0x10,    ///< transmit PTB - single shot mode
    LBMI                             = 0x20,    ///< loop-back mode: internal
    LBME                             = 0x40,    ///< loop-back mode: external
    RESET                            = 0x80,    ///< software reset
};

enum {
    TSA                              = 0x01,    ///< transmit secondary abort
    TSALL                            = 0x02,    ///< transmit secondary enable - all messages
    TSONE                            = 0x04,    ///< transmit secondary enable - one message
    TPA                              = 0x08,    ///< transmit primary abort
    TPE                              = 0x10,    ///< transmit primary enable
    STBY                             = 0x20,    ///< transceiver standby mode
    LOM                              = 0x40,    ///< listen-only mode
    TBSEL                            = 0x80,    ///< transmit buffer selector (0 for PTB, 1 for STB)
};

enum {
    TTTBM                            = 0x10,    ///< TTCAN Transmit Buffer Mode
    TSMODE                           = 0x20,    ///< transmit secondary: operation mode (FIFO (0) or priority decision (1))
    TSNEXT                           = 0x40,    ///< transmit secondary: next message slot
};

enum {
    RREL                             = 0x10,    ///< reception buffer message slot release
    ROV                              = 0x20,    ///< reception buffer overflow
    ROM                              = 0x40,    ///< reception buffer overflow mode
};

enum {
    TSFF                             = 0x01,    ///< transmit seconadary full flag
    EIE                              = 0x02,    ///< error interrupt enable
    TSIE                             = 0x04,    ///< transmit secondary interrupt enable
    TPIE                             = 0x08,    ///< transmit primary interrupt enable
    RAFIE                            = 0x10,    ///< receive buffer almost full interrupt enable
    RFIE                             = 0x20,    ///< receive buffer full interrupt enable
    ROIE                             = 0x40,    ///< receive buffer overflow interrupt enable
    RIE                              = 0x80,    ///< receive buffer interrupt enable
};

enum {
    AIF                              = 0x01,    ///< abort interrupt flag
    EIF                              = 0x02,    ///< error interrupt flag
    TSIF                             = 0x04,    ///< transmit secondary interrupt flag
    TPIF                             = 0x08,    ///< transmit primary interrupt flag
    RAFIF                            = 0x10,    ///< receive buffer almost full interrupt flag
    RFIF                             = 0x20,    ///< receive buffer full interrupt flag
    ROIF                             = 0x40,    ///< receive buffer overflow interrupt flag
    RIF                              = 0x80,    ///< receive buffer interrupt flag
};

enum {
    BEIF                             = 0x01,    ///< bus error interrupt flag
    BEIE                             = 0x02,    ///< bus error interrupt enable
    ALIF                             = 0x04,    ///< arbitration lost interrupt flag
    ALIE                             = 0x08,    ///< arbitration lost interrupt enable
    EPIF                             = 0x10,    ///< error passive interrupt flag
    EPIE                             = 0x20,    ///< error passive interrupt enable
    EPASS                            = 0x40,    ///< error passive mode
    EWARN                            = 0x80,    ///< error warning limit reached
};

enum {
    NOERROR                          = 0x00,    ///< no error flag
    BIT_ERROR                        = 0x01,    ///< bit error flag
    FORM_ERROR                       = 0x02,    ///< form error flag
    STUFF_ERROR                      = 0x03,    ///< stuff error flag
    ACK_ERROR                        = 0x04,    ///< acknowledgement error flag
    CRC_ERROR                        = 0x05,    ///< crc error flag
    OTHER_ERROR                      = 0x06,    ///< other error flag(dominant bits after own error flag, received active Error Flag too long,
                                                //dominant bit during Passive-Error-Flag after ACK error)
};

enum {
    SELMASK                          = 0x20,    ///< select acceptance mask (1) or code (0)
};

enum {
    TTEN                             = 0x01,    ///< TTCAN: enable
    TTIF                             = 0x08,    ///< TTCAN: time trigger interrupt flag
    TTIE                             = 0x10,    ///< TTCAN: time trigger interrupt enable
    TEIF                             = 0x20,    ///< TTCAN: trigger error interrupt flag
    WTIF                             = 0x40,    ///< TTCAN: watch trigger interrupt flag
    WTIE                             = 0x80,    ///< TTCAN: watch trigger interrupt enable
};

//#pragma anon_unions
///< CAN register define structure
typedef volatile struct
{
    CAN_RBUF_TYPE        RBUF;                  ///<  Receive buffer
    CAN_TBUF_TYPE        TBUF;                  ///<  Transmit buffer
    union {
        struct {
            uint32_t CFG_STAT    : 8;       ///< Configuration and Status Register
            uint32_t TCMD        : 8;       ///< Command Register
            uint32_t TCTRL       : 8;       ///< Transmit Control Register
            uint32_t RCTRL       : 8;       ///< Receive Control Register
            uint32_t RTIE        : 8;       ///< Receive and Transmit Interrupt Enable Register
            uint32_t RTIF        : 8;       ///< Receive and Transmit Interrupt Flag Register
            uint32_t ERRINT      : 8;       ///< Error Interrupt Enable and Flag Register
            uint32_t LIMIT       : 8;       ///< Warning Limits Register
            uint32_t S_Seg_1     : 8;       ///< Bit Timing Register 1
            uint32_t S_Seg_2     : 8;       ///< Bit Timing Register 2
            uint32_t S_SJW       : 8;       ///< Synchronization Jump Width
            uint32_t S_PRESC     : 8;       ///< Prescaler
            uint32_t             : 8;       ///< Reserved
            uint32_t             : 8;       ///< Reserved
            uint32_t             : 8;       ///< Reserved
            uint32_t             : 8;       ///< Reserved
            uint32_t EALCAP      : 8;       ///< Error and Arbitration Lost Capture Register
            uint32_t TDC         : 8;       ///< Reserved
            uint32_t RECNT       : 8;       ///< Receive Error Count
            uint32_t TECNT       : 8;       ///< Transmit Error Count
            uint32_t ACFCTRL     : 8;       ///< Acceptance Filter Control Register
            uint32_t             : 8;       ///< Reserved
            uint32_t ACF_EN_0    : 8;       ///< Acceptance Filter Enable
            uint32_t ACF_EN_1    : 8;       ///< Acceptance Filter Enable
            uint32_t ACF_0       : 8;       ///< Acceptance CODE Register
            uint32_t ACF_1       : 8;       ///< Acceptance CODE Register
            uint32_t ACF_2       : 8;       ///< Acceptance CODE Register
            uint32_t ACF_3       : 8;       ///< Acceptance CODE Register
            uint32_t VER_0       : 8;       ///< Version
            uint32_t VER_1       : 8;       ///< Version
            uint32_t TBSLOT      : 8;       ///< TB Slot Pointer
            uint32_t TTCFG       : 8;       ///< Time Trigger Configuration
            uint32_t REF_MSG_0   : 8;       ///< Reference message
            uint32_t REF_MSG_1   : 8;       ///< Reference message
            uint32_t REF_MSG_2   : 8;       ///< Reference message
            uint32_t REF_MSG_3   : 8;       ///< Reference message
            uint32_t TRIG_CFG    : 32;      ///< trigger configuration
            //uint32_t TRIG_CFG_0  : 8;       ///< Trigger Configuration
            //uint32_t TRIG_CFG_1  : 8;       ///< Trigger Configuration
            //uint32_t TT_TRIG_0   : 8;       ///< Trigger Time
            //uint32_t TT_TRIG_1   : 8;       ///< Trigger Time
            uint32_t TT_WTRIG_0  : 8;       ///< Watch Trigger Time
            uint32_t TT_WTRIG_1  : 8;       ///< Watch Trigger Time
            uint32_t             : 16;      ///< Reserved
        } REG;
        struct {
            //CAN_CFG_STAT_TYPE    CFG_STAT;    //(CAN_BASE + 0xa0)
            uint32_t BUSOFF      : 1;       ///< Bus off status
            uint32_t TACTIVE     : 1;       ///< Transmission active status
            uint32_t RACTIVE     : 1;       ///< Reception active status
            uint32_t TSSS        : 1;       ///< Transmit STB - single shot mode
            uint32_t TPSS        : 1;       ///< Transmit PTB - single shot mode
            uint32_t LBMI        : 1;       ///< Loop-back mode: internal
            uint32_t LBME        : 1;       ///< Loop-back mode: external
            uint32_t RESET       : 1;       ///< Software reset

            //CAN_TCMD_TYPE        TCMD;        //(CAN_BASE + 0xa1)
            uint32_t TSA         : 1;       ///< Transmit secondary abort
            uint32_t TSALL       : 1;       ///< Transmit secondary enable - all messages
            uint32_t TSONE       : 1;       ///< Transmit secondary enable - one message
            uint32_t TPA         : 1;       ///< Transmit primary abort
            uint32_t TPE         : 1;       ///< Transmit primary enable
            uint32_t STBY        : 1;       ///< Transceiver standby mode
            uint32_t LOM         : 1;       ///< Listen-only mode
            uint32_t TBSEL       : 1;       ///< Transmit buffer selector (0 for PTB, 1 for STB)

            //CAN_TCTRL_TYPE       TCTRL;       //(CAN_BASE + 0xa2)
            uint32_t TSSTAT      : 2;       ///< Transmit secondary status
            uint32_t             : 2;       ///< Reserved
            uint32_t TTTBM       : 1;       ///< TTCAN Transmit Buffer Mode
            uint32_t TSMODE      : 1;       ///< Transmit secondary: operation mode (FIFO (0) or priority decision (1))
            uint32_t TSNEXT      : 1;       ///< Transmit secondary: next message slot
            uint32_t             : 1;       ///< Reserved

            //CAN_RCTRL_TYPE       RCTRL;       //(CAN_BASE + 0xa3)
            uint32_t RSTAT       : 2;       ///< Receiver status
            uint32_t             : 2;       ///< Reserved
            uint32_t RREL        : 1;       ///< Reception buffer message slot release
            uint32_t ROV         : 1;       ///< Reception buffer overflow
            uint32_t ROM         : 1;       ///< Reception buffer overflow mode
            uint32_t             : 1;       ///< Reserved

            //CAN_RTIE_TYPE        RTIE;        //(CAN_BASE + 0xa4)
            uint32_t TSFF        : 1;       ///< Transmit seconadary full flag
            uint32_t EIE         : 1;       ///< Error interrupt enable
            uint32_t TSIE        : 1;       ///< Transmit secondary interrupt enable
            uint32_t TPIE        : 1;       ///< Transmit primary interrupt enable
            uint32_t RAFIE       : 1;       ///< Receive buffer almost full interrupt enable
            uint32_t RFIE        : 1;       ///< Receive buffer full interrupt enable
            uint32_t ROIE        : 1;       ///< Receive buffer overflow interrupt enable
            uint32_t RIE         : 1;       ///< Receive buffer interrupt enable

            //CAN_RTIF_TYPE        RTIF;        //(CAN_BASE + 0xa5)
            uint32_t AIF         : 1;       ///< Abort interrupt flag
            uint32_t EIF         : 1;       ///< Error interrupt flag
            uint32_t TSIF        : 1;       ///< Transmit secondary interrupt flag
            uint32_t TPIF        : 1;       ///< Transmit primary interrupt flag
            uint32_t RAFIF       : 1;       ///< Receive buffer almost full interrupt flag
            uint32_t RFIF        : 1;       ///< Receive buffer full interrupt flag
            uint32_t ROIF        : 1;       ///< Receive buffer overflow interrupt flag
            uint32_t RIF         : 1;       ///< Receive buffer interrupt flag

            //CAN_ERRINT_TYPE      ERRINT;      //(CAN_BASE + 0xa6)
            uint32_t BEIF        : 1;       ///< Bus error interrupt flag
            uint32_t BEIE        : 1;       ///< Bus error interrupt enable
            uint32_t ALIF        : 1;       ///< Arbitration lost interrupt flag
            uint32_t ALIE        : 1;       ///< Arbitration lost interrupt enable
            uint32_t EPIF        : 1;       ///< Error passive interrupt flag
            uint32_t EPIE        : 1;       ///< Error passive interrupt enable
            uint32_t EPASS       : 1;       ///< Error passive mode
            uint32_t EWARN       : 1;       ///< Error warning limit reached

            //CAN_LIMIT_TYPE       LIMIT;       //(CAN_BASE + 0xa7)
            uint32_t EWL         : 4;       ///< Error warning limit
            uint32_t AFWL        : 4;       ///< Almost full warning limit

            //CAN_S_CONFIG_TYPE    BIT_CONFIG;  //(CAN_BASE + 0xa8)
            uint32_t S_SEG_1     : 8;       ///< Bit Timing Segment 1
            uint32_t S_SEG_2     : 7;       ///< Bit Timing Segment 2
            uint32_t             : 1;       ///< Reserved
            uint32_t S_SJW       : 7;       ///< Synchronization Jump Width
            uint32_t             : 1;       ///< Reserved
            uint32_t S_PRESC     : 8;       ///< Prescaler

            uint32_t             : 32;      ///< Reserved (CAN_BASE + 0xac)

            //CAN_EALCAP_TYPE      EALCAP;      //(CAN_BASE + 0xb0)
            uint32_t ALC         : 5;       ///< Arbitration lost capture
            uint32_t KOER        : 3;       ///< Kind of error

            uint32_t             : 8;       ///< Reserved (CAN_BASE + 0xb1)

            //CAN_ERROR_COUNT_TYPE  ECNT;       //(CAN_BASE + 0xb2)
            uint32_t RECNT       : 8;       ///< Receive Error Count
            uint32_t TECNT       : 8;       ///< Transmit Error Count

            //CAN_ACFCTRL_TYPE     ACFCTRL;     //(CAN_BASE + 0xb4)
            uint32_t ACFADR      : 4;       ///< Acceptance filter address
            uint32_t             : 1;       ///< Reserved
            uint32_t SELMASK     : 1;       ///< Select acceptance mask (1) or code (0)
            uint32_t             : 2;       ///< Reserved
            uint32_t             : 1;       ///< Reserved
            uint32_t             : 1;       ///< Reserved
            uint32_t             : 6;       ///< Reserved
            uint32_t ACF_EN      : 16;      ///< Acceptance filter enable

            //CAN_ACF_CONFIG_TYPE  ACF;         //(CAN_BASE + 0xb8)
            uint32_t ACF         : 31;      ///< Filter data (code or mask) + AIDE + AIDEE
            //uint32_t ACF       : 29;      ///< Filter data (code or mask) 29 bit
            //uint32_t AIDE      : 1;       ///< Acceptance mask IDE bit value
            //uint32_t AIDEE     : 1;       ///< Acceptance mask IDE bit check enable
            uint32_t             : 1;       ///< Reserved

            //CAN_VER_TYPE         VER;         //(CAN_BASE + 0xbc)
            uint32_t VERSION     : 16;      ///< CAN version

            //CAN_TBSLOT_TYPE      TBSLOT;      //(CAN_BASE + 0xbe)
            uint32_t TBPTR       : 6;       ///< TB slot pointer
            uint32_t TBF         : 1;       ///< Set TB slot to "filled"
            uint32_t TBE         : 1;       ///< Set TB slot to "empty"

            //CAN_TTCFG_TYPE       TTCFG;       //(CAN_BASE + 0xbf)
            uint32_t TTEN        : 1;       ///< TTCAN: enable
            uint32_t T_PRESC     : 2;       ///< TTCAN: timer prescaler
            uint32_t TTIF        : 1;       ///< TTCAN: time trigger interrupt flag
            uint32_t TTIE        : 1;       ///< TTCAN: time trigger interrupt enable
            uint32_t TEIF        : 1;       ///< TTCAN: trigger error interrupt flag
            uint32_t WTIF        : 1;       ///< TTCAN: watch trigger interrupt flag
            uint32_t WTIE        : 1;       ///< TTCAN: watch trigger interrupt enable

            //CAN_REF_MSG_TYPE     REF_MSG;     //(CAN_BASE + 0xc0)
            uint32_t REF_MSG     : 32;      ///< TTCAN: Reference message
            //uint32_t REF_ID    : 29;      ///< TTCAN: Reference message IDentifier
            //uint32_t           : 2;       ///< Reserved
            //uint32_t REF_IDE   : 1;       ///< TTCAN: Reference message IDE bit

            //CAN_TRIG_CFG_TYPE    TRIG_CFG;    //(CAN_BASE + 0xc4)
            uint32_t TTPTR       : 6;       ///< TTCAN: trigger pointer to TB slot
            uint32_t             : 2;       ///< Reserved
            uint32_t TTYPE       : 3;       ///< TTCAN: Trigger Type
            uint32_t             : 1;       ///< Reserved
            uint32_t TEW         : 4;       ///< TTCAN: Transmit Enable Window

            //CAN_TT_TRIG_TYPE     TT_TRIG;     //(CAN_BASE + 0xc6)
            uint32_t TT_TRIG     : 16;      ///< TTCAN: Trigger Time

            //CAN_TT_WTRIG_TYPE    TT_WTRIG;    //(CAN_BASE + 0xc8)
            uint32_t TT_WTRIG    : 16;      ///< TTCAN: Watch Trigger Time
            uint32_t             : 16;      ///< Reserved
        } BIT;
    };
} CAN_Type;

typedef enum
{
    TRANSMIT_PRIMARY = 0,          ///< Transmit promary mode
    TRANSMIT_SECONDARY,            ///< Transmit secondary mode
} TRANSMIT_TYPE;

enum
{
    CAN_INDEX1 = 0,                ///< CAN 1
    CAN_INDEX2,                    ///< CAN 2
    CAN_NUM,
};

#define CAN1_BASE        (0x40007800)           ///< CAN1 module base address
#define CAN2_BASE        (0x40007C00)           ///< CAN2 module base address
#define CAN1  ((CAN_Type *) (CAN1_BASE))        ///< CAN1 address
#define CAN2  ((CAN_Type *) (CAN2_BASE))        ///< CAN2 address

#define CAN_RECEIVE_FIFO_COUNT       9          ///< CAN receive fifo count
#define CAN_TRANSMIT_FIFO_COUNT      6          ///< CAN transmit fifo count (1 PTB + 5 STB)
#define CAN_ERROR_WARNING_LIMIT      0xB        ///< Error Warning Limit = (EWL+1)*8
#define CAN_MAX_FILTER_NUM           16         ///< CAN max filter number

//#define TTCAN                                 ///< Enable TTCAN

/**
 * GetCanIndex
 *
 * @param[in]  CANx: CAN type pointer
 * @return     0: CAN_INDEX0, 1: CAN_INDEX1
 *
 * @brief  Get CAN index
 */
__STATIC_INLINE uint8_t GetCanIndex(CAN_Type *CANx)
{
    if (CANx == CAN2)
    {
        return CAN_INDEX2;
    }
    else
    {
        return CAN_INDEX1;
    }
}

/**
 * CAN_Reset
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  reset: CAN reset value
 * @return : none
 *
 * @brief  Reset CANx
 */
__STATIC_INLINE void CAN_Reset(CAN_Type *CANx, uint8_t reset)
{
    CANx->BIT.RESET = reset;
}

/**
 * CAN_Standby
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  enable: enable
 * @return     0: no error, 1: standby error
 *
 * @brief  Make CAN standby GPIO to high or low, connect to STB pin of transceiver
 */
__STATIC_INLINE int32_t CAN_Standby(CAN_Type *CANx, uint8_t enable)
{
    int32_t err = 0;

    // Using CAN standby mode or using other GPIO
    if (enable)
    {
        // If there is any transmission, can not entry standby mode
        if (CANx->BIT.TPE != 1 && CANx->BIT.TSONE != 1 && CANx->BIT.TSALL != 1)
        {
            CANx->BIT.STBY = 1;
        }
        else
        {
            err = 1;
        }
    }
    else
    {
        CANx->BIT.STBY = 0;
    }

    return err;
}

/**
 * CAN_IsMsgInReceiveBuf
 *
 * @param[in]  CANx: CAN type pointer
 * @return : Receive buffer status
 *
 * @brief  Get receive buffer status
 */
__STATIC_INLINE int32_t CAN_IsMsgInReceiveBuf(CAN_Type *CANx)
{
    return CANx->BIT.RSTAT;
}

/**
 * CAN_StartTransmission
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  type: CAN transmit type
 * @param[in]  mode: Transmit Secondary ALL or ONE frames
 * @return 0 : success 1: error
 *
 * @brief CAN start transmission
 */
__STATIC_INLINE int32_t CAN_StartTransmission(CAN_Type *CANx, TRANSMIT_TYPE type, uint8_t mode)
{
    // Can't send message when CAN is in standby mode(return or delay)
    if (CANx->BIT.STBY)
    {
        return 1;
    }

    if (TRANSMIT_PRIMARY == type)
    {
        CANx->BIT.TPE = 1;
    }
    else
    {
        if (mode)
        {
            CANx->BIT.TSONE = 1;    // Send one message only
        }
        else
        {
            CANx->BIT.TSALL = 1;    // Send all messages
        }
    }

    return 0;
}

/**
 * CAN_AbortTransmission
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  type: CAN transmit type
 * @return : none
 *
 * @brief CAN Abort transmission
 */
__STATIC_INLINE void CAN_AbortTransmission(CAN_Type *CANx, TRANSMIT_TYPE type)
{
    if (TRANSMIT_PRIMARY == type)
    {
        CANx->BIT.TPA = 1;
    }
    else
    {
        CANx->BIT.TSA = 1;
    }
}

/**
 * CAN_IsTransmitBusy
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  type: CAN transmit type
 * @return : Transmit busy flag (0: not busy, 1: busy)
 *
 * @brief Check transmission is busy
 */
__STATIC_INLINE int32_t CAN_IsTransmitBusy(CAN_Type *CANx, TRANSMIT_TYPE type)
{
    if (TRANSMIT_PRIMARY == type)
    {
        return (CANx->BIT.TPE == 1);    // Transmitting is not successful
    }
    else
    {
        return (CANx->BIT.TSSTAT == 3);    // Transmission buffers are full
    }
}

/**
 * CAN_IsTransmitIdle
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  type: CAN transmit type
 * @return : Transmit idle flag (0: busy, 1: idle)
 *
 * @brief Check transmission is idle
 */
__STATIC_INLINE int32_t CAN_IsTransmitIdle(CAN_Type *CANx, TRANSMIT_TYPE type)
{
    if (TRANSMIT_PRIMARY == type)
    {
        return (CANx->BIT.TPE == 0);    // PTB is empty
    }
    else
    {
        return (CANx->BIT.TSSTAT == 0);    // STB are empty
    }
}

/**
 * CAN_SetIntEnable
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  intEn: CAN interrupt enable
 * @param[in]  errIntEn: CAN error interrupt enable
 * @return : none
 *
 * @brief Set CAN interrupt enable
 */
__STATIC_INLINE void CAN_SetIntEnable(CAN_Type *CANx, uint8_t intEn, uint8_t errIntEn)
{
    CANx->REG.RTIE = intEn;
    CANx->REG.ERRINT = errIntEn;
}

/**
 * CAN_SetEwl
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  ewl: error warning limit(0-15)
 * @return : none
 *
 * @brief Set CAN error warning limit
 */
__STATIC_INLINE void CAN_SetEwl(CAN_Type *CANx, uint8_t ewl)
{
    CANx->BIT.EWL = ewl & 0xF;
}

#ifdef TTCAN
/**
 * TTCAN_Enable
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  enable: TTCAN enable or disable
 * @return : none
 *
 * @brief TTCAN enable or disable
 */
__STATIC_INLINE void TTCAN_Enable(CAN_Type *CANx, uint8_t enable)
{
    CANx->BIT.TTEN = enable;
}

/**
 * TTCAN_SetPresc
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  presc: TTCAN timer prescaler
 * @return : none
 *
 * @brief Set TTCAN timer prescaler
 */
__STATIC_INLINE void TTCAN_SetPresc(CAN_Type *CANx, uint8_t presc)
{
    CANx->BIT.T_PRESC = presc;
}

/**
 * TTCAN_SetBufMode
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  mode: TTCAN transmit buffer mode
 * @return : none
 *
 * @brief Set TTCAN transmit buffer mode
 */
__STATIC_INLINE void TTCAN_SetBufMode(CAN_Type *CANx, uint8_t mode)
{
    CANx->BIT.TTTBM = mode;
}

/**
 * TTCAN_EnableTimeInt
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  enable: Time trigger interrupt enable or disable
 * @return : none
 *
 * @brief Time trigger interrupt enable or disable
 */
__STATIC_INLINE void TTCAN_EnableTimeInt(CAN_Type *CANx, uint8_t enable)
{
    CANx->BIT.TTIE = enable;
}

/**
 * TTCAN_EnableWatchInt
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  enable: Watch trigger interrupt enable or disable
 * @return : none
 *
 * @brief Watch trigger interrupt enable or disable
 */
__STATIC_INLINE void TTCAN_EnableWatchInt(CAN_Type *CANx, uint8_t enable)
{
    CANx->BIT.WTIE = enable;
}

/**
 * TTCAN_SetTriggerConfig
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  type: Trigger type
 * @param[in]  tew: Transmit enable window
 * @param[in]  ttptr: Transmit trigger TB slot pointer
 * @param[in]  time: Trigger time
 * @return : none
 *
 * @brief Set trigger configuration and trigger time
 */
__STATIC_INLINE void TTCAN_SetTriggerConfig(CAN_Type *CANx, uint8_t type, uint8_t tew, uint8_t ttptr, uint16_t time)
{
    CANx->REG.TRIG_CFG = (time << 16) | (tew << 12) | (type << 8) | ttptr;
}

/**
 * TTCAN_GetTriggerType
 *
 * @param[in]  CANx: CAN type pointer
 * @return : none
 *
 * @brief Set trigger configuration and trigger time
 */
__STATIC_INLINE uint8_t TTCAN_GetTriggerType(CAN_Type *CANx)
{
    return CANx->BIT.TTYPE;
}

/**
 * TTCAN_SetWatchTrigger
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  time: Watch Trigger Time
 * @return : none
 *
 * @brief Set watch trigger time
 */
__STATIC_INLINE void TTCAN_SetWatchTrigger(CAN_Type *CANx, uint16_t time)
{
    CANx->BIT.TT_WTRIG = time;
}

/**
 * TTCAN_SetTbptr
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  point: Transmit trigger TB slot pointer
 * @return : none
 *
 * @brief Watch trigger interrupt enable or disable
 */
__STATIC_INLINE void TTCAN_SetTbptr(CAN_Type *CANx, uint8_t point)
{
    CANx->BIT.TBPTR = point;
}

/**
 * TTCAN_SetTb
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  state: TB slot 0 -> "Empty" or 1 -> "Filled"
 * @return : none
 *
 * @brief Set TB slot to "Empty" or "Filled"
 */
__STATIC_INLINE void TTCAN_SetTb(CAN_Type *CANx, uint8_t state)
{
    if (state)
    {
        CANx->BIT.TBF = 1;
    }
    else
    {
        CANx->BIT.TBE = 1;
    }
}

/**
 * TTCAN_SetRefMsg
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  refId: reference message
 * @param[in]  refIde: reference message IDE
 * @return : none
 *
 * @brief Set reference message
 */
__STATIC_INLINE void TTCAN_SetRefMsg(CAN_Type *CANx, uint32_t refId, uint8_t refIde)
{
    CANx->BIT.REF_MSG = refId | (refIde << 31);
}
#endif

#endif
