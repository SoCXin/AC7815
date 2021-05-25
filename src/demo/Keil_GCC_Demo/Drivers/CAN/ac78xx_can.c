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

#include "ac78xx_can.h"


///< CAN device infomation struct
typedef struct
{
    uint8_t            TPSS : 1;               ///< Single Shot mode for primary mode
    uint8_t            TSSS : 1;               ///< Single Shot mode for secondary mode
    uint8_t            autoReset: 1;           ///< Auto reset after bus off to active
    uint8_t            interruptEnable;        ///< CAN interrupt flag
    uint16_t           errorFlag;              ///< CAN error flag
    CAN_Event_Callback eventFunc;              ///< CAN event function
} CAN_Device;

static CAN_Device s_canDevice[CAN_NUM] = {0};  ///< CAN device infomation

#if 1
///< Baurate sample setting list: Source clock = 48MHz, sample point = 75%, or user define
static const CAN_BaudrateConfig s_commonBaudrate[CAN_BAUDRATE_NUM] =
{
    {0x00, 0x22, 0x0B, 0x07},  // 1M
    {0x00, 0x2B, 0x0E, 0x07},  //800K
    {0x01, 0x22, 0x0B, 0x07},  //500K
    {0x03, 0x22, 0x0B, 0x07},  //250K
    {0x07, 0x22, 0x0B, 0x07},  //125K
    {0x09, 0x22, 0x0B, 0x07},  //100K
    {0x13, 0x22, 0x0B, 0x07},  //50K (Some transceiver minimum bit rate is 40 kbit/s)
    {0x31, 0x22, 0x0B, 0x07},  //20K
    {0x63, 0x22, 0x0B, 0x07},  //10K
    {0xC7, 0x22, 0x0B, 0x07},  //5K
};
#else
///< Baurate sample setting list: Source clock = 8MHz, sample point = 75%, or user define
static const CAN_BaudrateConfig s_commonBaudrate[CAN_BAUDRATE_NUM] =
{
    {0x00, 0x04, 0x01, 0x01},  // 1M
    {0x00, 0x06, 0x01, 0x01},  //800K ->80%
    {0x00, 0x0A, 0x03, 0x03},  //500K
    {0x00, 0x16, 0x07, 0x05},  //250K
    {0x01, 0x16, 0x07, 0x05},  //125K
    {0x01, 0x1C, 0x09, 0x07},  //100K
    {0x03, 0x1C, 0x09, 0x07},  //50K
    {0x09, 0x1C, 0x09, 0x07},  //20K
    {0x13, 0x1C, 0x09, 0x07},  //10K
    {0x27, 0x1C, 0x09, 0x07},  //5K
};
#endif

///< Filter sample setting list, or user define
static const CAN_FilterControl s_filterControl[CAN_MAX_FILTER_NUM] =
{
    {0, 1, 0x00000000, 0x1FFFFFFF},    // mask mode
    {1, 0, 0x00000002, 0x00000000},    // code mode
    {2, 0, 0x00000013, 0x00000000},
    {3, 0, 0x00000124, 0x00000000},
    {4, 0, 0x00000050, 0x1FFFFF0F},
    {5, 0, 0x00000060, 0x1FFFFF0F},
    {6, 0, 0x00000007, 0x1FFFFFF0},
    {7, 0, 0x00000008, 0x1FFFFFF0},

    {8, 0, 0x00000009, 0x5FFFFFF0},    // standard frames
    {9, 0, 0x0000000a, 0x7FFFFFF0},    // extended frames
    {10, 0, 0x00000700, 0x1FFFF0FF},   // Both
    {11, 0, 0x0000c000, 0x7FFF0FFF},
    {12, 0, 0x000d0000, 0x7FF0FFFF},
    {13, 0, 0x00e00000, 0x7F0FFFFF},
    {14, 0, 0x0f000000, 0x70FFFFFF},
    {15, 0, 0x10000000, 0x6FFFFFFF},
};

#define MAX_CAN_WAIT_TIMES 100000

/**
 * GetCanIndex
 *
 * @param[in]  CANx: CAN type pointer
 * @return     0: CAN_INDEX0, 1: CAN_INDEX1
 *
 * @brief  Get CAN index
 */
__inline uint8_t GetCanIndex(CAN_Type *CANx)
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
 * CAN_SetEventCallBack
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  eventFunc: Event call back function
 * @return     0: no error, 1: eventFunc is null
 *
 * @brief  Set event call back function
 */
int32_t CAN_SetEventCallBack(CAN_Type *CANx, CAN_Event_Callback eventFunc)
{
    uint8_t canIndex = GetCanIndex(CANx);
    int32_t err = 0;

    if (eventFunc)
    {
        s_canDevice[canIndex].eventFunc = eventFunc;
    }
    else
    {
        err = 1;
    }

    return err;
}

/**
 * CAN_HandleEvent
 *
 * @param[in]  CANx: CAN type pointer
 * @return : none
 *
 * @brief  CANx interrupt handle function
 */
void CAN_HandleEvent(CAN_Type *CANx)
{
    uint8_t flag = CANx->REG.RTIF, errInt = CANx->REG.ERRINT, ttCfg = 0;
    uint8_t canIndex = GetCanIndex(CANx);
    CAN_Device *device = &s_canDevice[canIndex];

    // Clear flag
    CANx->REG.RTIF = flag;
    CANx->REG.ERRINT = errInt;
#ifdef TTCAN
    ttCfg = CANx->REG.TTCFG;
    CANx->REG.TTCFG = ttCfg;
    if (ttCfg & (TTIF | TEIF | WTIF))
    {
        DEBUGMSG(DEBUG_ZONE_ERROR, ("[CAN%d]ttCfg:%x\r\n", canIndex, ttCfg));
    }
#endif

    // Check error flag
    if (flag & (EIF | ROIF | RFIF | RAFIF | AIF) || (errInt & (EPIF | ALIF | BEIF)))
    {
        if (flag & EIF)
        {
            DEBUGMSG(DEBUG_ZONE_ERROR, ("[CAN%d]RC:%d TC:%d BO:%d RS:%d\r\n", canIndex, CANx->REG.RECNT, CANx->REG.TECNT, CANx->BIT.BUSOFF, CANx->BIT.RESET));
            // Auto reset after bus off to active, or user define
            if (device->autoReset && CANx->BIT.RESET && (CANx->BIT.BUSOFF == 0))
            {
                CANx->BIT.RESET = 0;
                if (device->TPSS)
                {
                    CANx->REG.CFG_STAT |= TPSS;
                }
                if (device->TSSS)
                {
                    CANx->REG.CFG_STAT |= TSSS;
                }
            }
        }

        device->errorFlag = flag | (errInt << 8);
        //DEBUGMSG(DEBUG_ZONE_ERROR, ("[CAN%d]flag:%x %x %d\r\n", canIndex, flag, errInt, CANx->BIT.KOER));
    }

    // Call back function
    if (device->eventFunc)
    {
        device->eventFunc((uint32_t)(flag | (errInt << 8) | (ttCfg << 16)), (uint32_t)CANx->BIT.KOER, (uint32_t)CANx);
    }
}

/**
 * CAN1_Handler
 *
 * @param[in] : none
 * @return : none
 *
 * @brief  CAN1 interrupt handle function
 */
void CAN1_Handler(void)
{
    CAN_HandleEvent(CAN1);
}

/**
 * CAN2_Handler
 *
 * @param[in] : none
 * @return : none
 *
 * @brief  CAN2 interrupt handle function
 */
void CAN2_Handler(void)
{
    CAN_HandleEvent(CAN2);
}

/**
 * CAN_SetBitrate
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  config: Baud rate config
 * @return : none
 *
 * @brief  Set CAN baud rate
 */
static void CAN_SetBitrate(CAN_Type *CANx, const CAN_BaudrateConfig *config)
{
    CANx->BIT.RESET = 1;

    CANx->BIT.S_SEG_1 = config->S_SEG_1;
    CANx->BIT.S_SEG_2 = config->S_SEG_2;
    CANx->BIT.S_SJW   = config->S_SJW;
    CANx->BIT.S_PRESC = config->S_PRESC;
}

/**
 * GetCommonBaudRate
 *
 * @param[in]  type: Baud rate type
 * @return : Baud rate config data
 *
 * @brief  Get baud rate type
 */
const CAN_BaudrateConfig *GetCommonBaudrate(CAN_BAUDRATE_TYPE type)
{
    const CAN_BaudrateConfig *config = 0;

    if (type < CAN_BAUDRATE_NUM)
    {
        config = &s_commonBaudrate[type];
    }

    return config;
}

/**
 * CAN_GetError
 *
 * @param[in]  CANx: CAN type pointer
 * @return : error flag
 *
 * @brief  Get can error flag
 */
int32_t CAN_GetError(CAN_Type *CANx)
{
    uint8_t canIndex = GetCanIndex(CANx);
    int32_t errorFlag = 0;

    if (s_canDevice[canIndex].interruptEnable)
    {
        errorFlag = s_canDevice[canIndex].errorFlag;
    }
    else
    {
        errorFlag = (CANx->REG.RTIF & (EIF | ROIF | RFIF | RAFIF | AIF)) | ((CANx->REG.ERRINT & (EPIF | ALIF | BEIF)) << 8);
    }

    return errorFlag;
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
__inline void CAN_Reset(CAN_Type *CANx, uint8_t reset)
{
    CANx->BIT.RESET = reset;
}

/**
 * CAN_Initialize
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  config: CAN config
 * @param[in]  baudrate: CAN baud rate
 * @return     0: no error, 1: Initialize error
 *
 * @brief  Init CANx (GPIO, clock, baudrate, filter and interrupt setting)
 */
int32_t CAN_Initialize(CAN_Type *CANx, CAN_Config *config, const CAN_BaudrateConfig *baudrate)
{
    uint8_t canIndex = GetCanIndex(CANx), i = 0;
    int32_t err = ERROR_NO_EXCUTE;

    if (canIndex >= CAN_NUM && !config && !baudrate)
    {
        return err;
    }

    s_canDevice[canIndex].errorFlag = 0;

    // Check CAN GPIO first
    //CAN_InitGPIO(CANx, 0, 0);

    // CAN and clock enable
    if (config->clockSrc)
    {
        CKGEN_SetCANClock(canIndex, CAN_CLK_SEL_EXTERNAL_OSC, CAN_CLK_DIVIDER_1);
    }
    else
    {
        CKGEN_SetCANClock(canIndex, CAN_CLK_SEL_AHB, CAN_CLK_DIVIDER_2);
    }
    CKGEN_Enable((CLK_MODULE)(CLK_CAN1 + canIndex), 1);
    CKGEN_Enable((CLK_MODULE)(CLK_CAN1_CORE + canIndex), 1);
    CKGEN_SoftReset((SRST_MODULE)(SRST_CAN1 + canIndex), 1);

    // Set baudrate
    CAN_SetBitrate(CANx, baudrate);

    // Set filters
    for (i = 0; i < CAN_MAX_FILTER_NUM; i++)
    {
        CAN_SetFilter(CANx, s_filterControl[i].index, s_filterControl[i].code, s_filterControl[i].mask, s_filterControl[i].enable);
    }

    // Start synchronize
    CANx->BIT.RESET = 0;
    CANx->BIT.AFWL = CAN_RECEIVE_FIFO_COUNT - 1;
    CANx->BIT.EWL = CAN_ERROR_WARNING_LIMIT;

    // Set work mode
    if (config->canMode == CAN_MODE_MONITOR)
    {
        CANx->BIT.LOM = 1;
    }
    else if (config->canMode == CAN_MODE_LOOPBACK_INTERNAL)
    {
        CANx->BIT.LBMI = 1;
    }
    else if (config->canMode == CAN_MODE_LOOPBACK_EXTERNAL)
    {
        CANx->BIT.LBME = 1;
    }
    else
    {
    }

    s_canDevice[canIndex].autoReset = config->autoReset;
    CANx->BIT.TPSS = s_canDevice[canIndex].TPSS = config->TPSS;  // 1->Single Shot mode
    CANx->BIT.TSSS = s_canDevice[canIndex].TSSS = config->TSSS;  // 1->Single Shot mode
    CANx->BIT.TSMODE = config->TSMODE;  // 0->FIFO mode 1->priority decision mode
    CANx->BIT.ROM = config->ROM;        // 0->overwrite the oldest message 1->discard new message

    // Enable interrupt
    if (config->interruptEnable)
    {
        CANx->REG.RTIE = EIE | TSIE | TPIE | RAFIE | RFIE | ROIE | RIE;
        CANx->REG.ERRINT = BEIE | ALIE | EPIE;
        s_canDevice[canIndex].interruptEnable = config->interruptEnable;
        NVIC_EnableIRQ((IRQn_Type)(CAN1_IRQn + canIndex));
    }

    return 0;
}

/**
 * CAN_Uninitialize
 *
 * @param[in]  CANx: CAN type pointer
 * @return     0: no error, 1: Denintialize error
 *
 * @brief  Uninitialize CANx
 */
int32_t CAN_Uninitialize(CAN_Type *CANx)
{
    uint8_t canIndex = GetCanIndex(CANx);
    int32_t err = ERROR_NO_EXCUTE;

    if (canIndex >= CAN_NUM)
    {
        return err;
    }

    CANx->BIT.RESET = 1;
    // CAN and clock disable
    CKGEN_Enable((CLK_MODULE)(CLK_CAN1 + canIndex), 0);
    CKGEN_Enable((CLK_MODULE)(CLK_CAN1_CORE + canIndex), 0);
    CKGEN_SoftReset((SRST_MODULE)(SRST_CAN1 + canIndex), 0);

    return 0;
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
__inline int32_t CAN_Standby(CAN_Type *CANx, uint8_t enable)
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
        // Or set other GPIO to HIGH
    }
    else
    {
        CANx->BIT.STBY = 0;
        // Or set other GPIO to LOW
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
__inline int32_t CAN_IsMsgInReceiveBuf(CAN_Type *CANx)
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
__inline int32_t CAN_StartTransmission(CAN_Type *CANx, TRANSMIT_TYPE type, uint8_t mode)
{
    // Can't send message when CAN is in standby mode(return or delay)
    if (CANx->BIT.STBY)
    {
        return 1;
        //CANx->BIT.STBY = 0;
        //udelay(50);    // standby to normal mode delay time
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
__inline void CAN_AbortTransmission(CAN_Type *CANx, TRANSMIT_TYPE type)
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
 * WaitTransmitPrimaryDone
 *
 * @param[in]  CANx: CAN type pointer
 * @return : Transmit flag (0: done, 1: timeout)
 *
 * @brief Wait transmit primary done, otherwise timeout
 */
int32_t WaitTransmitPrimaryDone(CAN_Type *CANx)
{
    uint32_t i = 0;
    int32_t flag = 0;

    do
    {
        if (CANx->BIT.TPIF)
        {
            CANx->BIT.TPIF = 1;
            break;
        }
    } while (i++ < MAX_CAN_WAIT_TIMES);

    if (i >= MAX_CAN_WAIT_TIMES)
    {
        DEBUGMSG(DEBUG_ZONE_ERROR, ("[CAN%d]WaitTransmissionDone timeout\r\n", GetCanIndex(CANx)));
        flag = 1;
    }

    return flag;
}

/**
 * WaitTransmitSecondaryDone
 *
 * @param[in]  CANx: CAN type pointer
 * @return : Transmit flag (0: done, 1: timeout)
 *
 * @brief Wait transmit secondary done, otherwise timeout
 */
int32_t WaitTransmitSecondaryDone(CAN_Type *CANx)
{
    uint32_t i = 0;
    int32_t flag = 0;

    do
    {
        if (CANx->BIT.TSIF)
        {
            CANx->BIT.TSIF = 1;
            break;
        }
    } while (i++ < MAX_CAN_WAIT_TIMES);

    if (i >= MAX_CAN_WAIT_TIMES)
    {
        DEBUGMSG(DEBUG_ZONE_ERROR, ("[CAN%d]WaitTransmitSecondaryDone timeout\r\n", GetCanIndex(CANx)));
        flag = 1;
    }

    return flag;
}

/**
 * CAN_WaitTransmissionDone
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  type: CAN transmit type
 * @return : Transmit flag (0: done, 1: timeout)
 *
 * @brief Wait transmit done
 */
__inline int32_t CAN_WaitTransmissionDone(CAN_Type *CANx, TRANSMIT_TYPE type)
{
    int32_t ret = 0;

    if (s_canDevice[GetCanIndex(CANx)].interruptEnable)
    {
        //clear flag in IRQ
    }
    else if (type == TRANSMIT_PRIMARY)
    {
        ret = WaitTransmitPrimaryDone(CANx);
    }
    else
    {
        ret = WaitTransmitSecondaryDone(CANx);
    }

    return ret;
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
__inline int32_t CAN_IsTransmitBusy(CAN_Type *CANx, TRANSMIT_TYPE type)
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
__inline int32_t CAN_IsTransmitIdle(CAN_Type *CANx, TRANSMIT_TYPE type)
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
 * CAN_WaitTransmissionIdle
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  type: CAN transmit type
 * @return : Transmit idle flag (0: timeout, 1: idle)
 *
 * @brief Wait for transmitting done in primary mode; or transmission buffer not full in secondary mode, otherwise timeout
 */
int32_t CAN_WaitTransmissionIdle(CAN_Type *CANx, TRANSMIT_TYPE type)
{
    uint32_t i = 0;
    int32_t flag = 0;

    if (TRANSMIT_PRIMARY == type)
    {
        do
        {
            if (CANx->BIT.TPE == 0)    // Transmission is successful
            {
                break;
            }
        } while (i++ < MAX_CAN_WAIT_TIMES);
    }
    else
    {
        do
        {
            if (CANx->BIT.TSSTAT != 3)    // Transmission buffers are not full
            {
                break;
            }
        } while (i++ < MAX_CAN_WAIT_TIMES);
    }

    if (i >= MAX_CAN_WAIT_TIMES)
    {
        DEBUGMSG(DEBUG_ZONE_ERROR, ("[CAN%d]WaitTransmissionIdle timeout\r\n", GetCanIndex(CANx)));
        flag = 1;
    }

    return flag;
}

/**
 * CAN_SetMsgInfo
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  info: CAN message information
 * @param[in]  type: CAN transmit type
 * @return : none
 *
 * @brief Set message infomation
 */
void CAN_SetMsgInfo(CAN_Type *CANx, const CAN_MSG_INFO *info, TRANSMIT_TYPE type)
{
    if (TRANSMIT_PRIMARY == type)
    {
        CANx->BIT.TBSEL = 0;
    }
    else
    {
        CANx->BIT.TBSEL = 1;
    }

    CANx->TBUF.ID = info->ID;  // info->IDE ? info->ID : (info->ID & 0x7FF);
    CANx->TBUF.RTR = info->RTR;
    CANx->TBUF.IDE = info->IDE;
    CANx->TBUF.DLC = info->DLC;  // (info->DLC > 8) ? 8 : info->DLC;

    if (info->RTR == 0 && info->DLC)
    {
        CANx->TBUF.Data[0] = *(uint32_t *)(&info->Data[0]);
        CANx->TBUF.Data[1] = *(uint32_t *)(&info->Data[4]);
        //memcpy((uint8_t *)&(CANx->TBUF.Data[0]), &info->Data[0], info->DLC);    // another way
    }

    if (TRANSMIT_SECONDARY == type)
    {
        CANx->BIT.TSNEXT = 1;
    }
}

/**
 * CAN_MessageSend
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  info: CAN message information
 * @param[in]  type: CAN transmit type
 * @return : Error flag (0: success, 1: fail or timeout)
 *
 * @brief Send CANx message
 */
int32_t CAN_MessageSend(CAN_Type *CANx, const CAN_MSG_INFO *info, TRANSMIT_TYPE type)
{
    int32_t err = 0;

    if (!CAN_WaitTransmissionIdle(CANx, type))
    {
        CAN_SetMsgInfo(CANx, info, type);

        if (CAN_StartTransmission(CANx, type, 0))
        {
            err = 1;
        }
        else
        {
            if (CAN_WaitTransmissionDone(CANx, type))
            {
                err = 1;
            }
        }
    }
    else  // If timeout, return error or abort transmission
    {
        err = 1;
        //CAN_AbortTransmission(CANx, type);
    }

    return err;
}

/**
 * CAN_MessageRead
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  info: CAN message information
 * @return : Error flag (0: success, 1: no message)
 *
 * @brief Read CANx message
 */
int32_t CAN_MessageRead(CAN_Type *CANx, CAN_MSG_INFO *info)
{
    if (!CAN_IsMsgInReceiveBuf(CANx))
    {
        return 1;
    }

    info->ID = CANx->RBUF.ID;
    info->RTR = CANx->RBUF.RTR;
    info->IDE = CANx->RBUF.IDE;
    info->DLC = CANx->RBUF.DLC;
#ifdef TTCAN
    info->CYCLE_TIME = CANx->RBUF.CYCLE_TIME;
#endif
    if (info->RTR == 0 && info->DLC)
    {
        *(uint32_t *)(&info->Data[0]) = CANx->RBUF.Data[0];
        *(uint32_t *)(&info->Data[4]) = CANx->RBUF.Data[1];
        //memcpy(&info->Data[0], (uint8_t *)&(CANx->RBUF.Data[0]), info->DLC);    // another way
    }
    CANx->BIT.RREL = 1;

    return 0;
}

/**
 * CAN_SetFilter
 *
 * @param[in]  CANx: CAN type pointer
 * @param[in]  index: CAN filter index
 * @param[in]  code: CAN filter code
 * @param[in]  mask: CAN filter mask
 * @param[in]  enable: CAN filter enable
 * @return : Error flag (0: success, 1: index error)
 *
 * @brief Set CANx filter when RESET = 1
 */
int32_t CAN_SetFilter(CAN_Type *CANx, uint8_t index, uint32_t code, uint32_t mask, uint8_t enable)
{
    if (index >= CAN_MAX_FILTER_NUM)
    {
        return 1;
    }

    if (CANx->BIT.RESET == 0)
    {
        return 1;
    }

    if (enable)
    {
        CANx->REG.ACFCTRL = index;
        CANx->BIT.ACF = code;

        CANx->REG.ACFCTRL = index | SELMASK;
        CANx->BIT.ACF = mask;

        CANx->BIT.ACF_EN |= (1 << index);
    }
    else
    {
        CANx->BIT.ACF_EN &= ~(1 << index);
    }

    return 0;
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
__inline void TTCAN_Enable(CAN_Type *CANx, uint8_t enable)
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
__inline void TTCAN_SetPresc(CAN_Type *CANx, uint8_t presc)
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
__inline void TTCAN_SetBufMode(CAN_Type *CANx, uint8_t mode)
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
__inline void TTCAN_EnableTimeInt(CAN_Type *CANx, uint8_t enable)
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
__inline void TTCAN_EnableWatchInt(CAN_Type *CANx, uint8_t enable)
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
__inline void TTCAN_SetTriggerConfig(CAN_Type *CANx, uint8_t type, uint8_t tew, uint8_t ttptr, uint16_t time)
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
__inline uint8_t TTCAN_GetTriggerType(CAN_Type *CANx)
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
__inline void TTCAN_SetWatchTrigger(CAN_Type *CANx, uint16_t time)
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
__inline void TTCAN_SetTbptr(CAN_Type *CANx, uint8_t point)
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
__inline void TTCAN_SetTb(CAN_Type *CANx, uint8_t state)
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
__inline void TTCAN_SetRefMsg(CAN_Type *CANx, uint32_t refId, uint8_t refIde)
{
    CANx->BIT.REF_MSG = refId | (refIde << 31);
}

#endif
