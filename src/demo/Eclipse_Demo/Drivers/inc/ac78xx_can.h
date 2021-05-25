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

#ifndef AC78XX_CAN_H
#define AC78XX_CAN_H

#include <stdint.h>
#include "ac78xx_can_reg.h"
#include "ac78xx_gpio.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct _CAN_MSG_INFO
{
    uint32_t    ID: 29;            ///< CAN identifier
    uint32_t    RTR: 1;            ///< Remote transmission request frame
    uint32_t    IDE: 1;            ///< Identifier Extension
    uint32_t    DLC: 4;            ///< Data length code
    uint32_t    CYCLE_TIME: 16;    ///< Cycle time for TTCAN
    uint8_t     Data[8];           ///< Data
} CAN_MSG_INFO;

typedef int32_t (* CAN_Event_Callback)(uint32_t event, uint32_t wparam, uint32_t lparam);

typedef struct
{
    uint32_t           TPSS : 1;               ///< Single Shot mode for primary mode
    uint32_t           TSSS : 1;               ///< Single Shot mode for secondary mode
    uint32_t           autoReset: 1;           ///< Auto reset after bus off to active
    uint8_t            interruptEnable;        ///< CAN interrupt enable
    uint16_t           errorFlag;              ///< CAN error flag
    CAN_Event_Callback callbackFunc;           ///< CAN event callback function
} CAN_Device;

///< Baudrate = CAN_CLOCK / ((S_PRESC + 1) * (1 + (S_SEG_1 + 1) + (S_SEG_2 + 1)))
typedef struct
{
    uint8_t S_PRESC;               ///< Prescaler
    uint8_t S_SEG_1;               ///< Bit Timing Segment 1
    uint8_t S_SEG_2;               ///< Bit Timing Segment 2
    uint8_t S_SJW;                 ///< Synchronization Jump Width: SJW = SEG_2 / 2 ~ SEG_2 * 2 / 3
} CAN_BaudrateConfig;

typedef struct
{
    uint8_t index;                 ///< Filter index
    uint8_t enable;                ///< Enable or disable
    uint32_t code;                 ///< Code data
    uint32_t mask;                 ///< Mask data
} CAN_FilterControl;

typedef struct
{
    uint32_t canMode: 3;            ///< CAN mode
    uint32_t clockSrc: 1;           ///< CAN clock source
    uint32_t interruptEnable: 1;    ///< Interrupt enable
    uint32_t autoReset: 1;          ///< Auto reset after bus off to active
    uint32_t TPSS: 1;               ///< Transmission Primary Single Shot mode for PTB
    uint32_t TSSS: 1;               ///< Transmission Secondary Single Shot Mode for STP
    uint32_t TSMODE: 1;             ///< Transmit buffer Secondary operation MODE
    uint32_t ROM: 1;                ///< Receive buffer Overflow Mode
    CAN_FilterControl *filterList; ///< Filter controller list
} CAN_Config;

typedef enum
{
    CAN_EVENT_WATCHTRIGGER = 1 << 22,                ///< Watch trigger interrupt flag
    CAN_EVENT_TRIGGERERROR = 1 << 21,                ///< Trigger error interrupt flag
    CAN_EVENT_TIMETRIGGER = 1 << 19,                 ///< Time trigger interrupt flag
    CAN_EVENT_ERRORWARNING = 1 << 15,                ///< Error warning interrupt flag
    CAN_EVENT_ERRORPASSIVEACTIVE = 1 << 14,          ///< Error passive acitve interrupt flag
    CAN_EVENT_ERRORPASSIVE = 1 << 12,                ///< Error passive interrupt flag
    CAN_EVENT_ARBITLOST = 1 << 10,                   ///< Arbitration lost interrupt flag
    CAN_EVENT_BUSERROR = 1 << 8,                     ///< Bus error interrupt flag
    CAN_EVENT_RECVMSG = 1 << 7,                      ///< Receive message interrupt flag
    CAN_EVENT_RECVBUFOVERRUN = 1 << 6,               ///< Buffer overrun interrupt flag
    CAN_EVENT_RECVBUFFULL = 1 << 5,                  ///< Receive buffer full interrupt flag
    CAN_EVENT_RECVBUFALMOSTFULL = 1 << 4,            ///< Receive buffer almost full interrupt flag
    CAN_EVENT_TRANSPRIMDONE = 1 << 3,                ///< Transmission primary done interrupt flag
    CAN_EVENT_TRANSSECDONE = 1 << 2,                 ///< Transmission secondary done interrupt flag
    CAN_EVENT_ERROR = 1 << 1,                        ///< Error interrupt flag
    CAN_EVENT_ABORT = 1 << 0,                        ///< Abort interrupt flag
} CAN_EventFlag;

typedef enum
{
    CAN_BAUDRATE_1M = 0,
    CAN_BAUDRATE_800K,
    CAN_BAUDRATE_500K,
    CAN_BAUDRATE_250K,
    CAN_BAUDRATE_125K,
    CAN_BAUDRATE_100K,
    CAN_BAUDRATE_50K,
    CAN_BAUDRATE_20K,
    CAN_BAUDRATE_10K,
    CAN_BAUDRATE_5K,
    CAN_BAUDRATE_NUM,
} CAN_BAUDRATE_TYPE;               ///< CAN baudrate type

typedef enum
{
    CAN_MODE_INITIALIZATION,       ///< Initialization mode
    CAN_MODE_NORMAL,               ///< Normal mode
    CAN_MODE_RESTRICTED,           ///< Restricted mode
    CAN_MODE_MONITOR,              ///< Listen only mode
    CAN_MODE_LOOPBACK_INTERNAL,    ///< Loopback internal mode
    CAN_MODE_LOOPBACK_EXTERNAL     ///< Loopback external mode
} CAN_MODE;

typedef enum
{
    CAN_CLKSRC_AHB,                ///< Clcok source from AHB bus
    CAN_CLKSRC_EXTERNAL_OSC,       ///< Clcok source from external OSC
} CAN_CLKSRC;

//#define GETCANINDEX(CANx)    ((CANx == CAN2) ? 1 : 0)    ///< Get CAN index


const CAN_BaudrateConfig *GetCommonBaudrate(CAN_BAUDRATE_TYPE type);
int32_t CAN_Initialize(CAN_Type *CANx, CAN_Config *config, const CAN_BaudrateConfig *baudrate);
int32_t CAN_Uninitialize(CAN_Type *CANx);
int32_t CAN_MessageSend(CAN_Type *CANx, const CAN_MSG_INFO *info, TRANSMIT_TYPE type);
int32_t CAN_MessageRead(CAN_Type *CANx, CAN_MSG_INFO *info);
int32_t CAN_SetEventCallBack(CAN_Type *CANx, CAN_Event_Callback callbackFunc);
int32_t CAN_SetFilter(CAN_Type *CANx, uint8_t index, uint32_t code, uint32_t mask, uint8_t enable);
int32_t CAN_GetError(CAN_Type *CANx);
int32_t CAN_WaitTransmissionIdle(CAN_Type *CANx, TRANSMIT_TYPE type);
int32_t CAN_WaitTransmissionDone(CAN_Type *CANx, TRANSMIT_TYPE type);
void CAN_SetMsgInfo(CAN_Type *CANx, const CAN_MSG_INFO *info, TRANSMIT_TYPE type);


#ifdef __cplusplus
}
#endif

#endif
