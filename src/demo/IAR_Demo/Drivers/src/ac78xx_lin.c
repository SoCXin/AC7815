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

#include "ac78xx_lin.h"

LIN_Event_Callback g_linCallback = NULL;

/**
 * LIN0_Handler
 *
 * @param[in] : none
 * @return : none
 *
 * @brief  LIN interrupt function
 */
void LIN0_Handler(void)
{
    uint32_t sts = LIN0->LINSTS, error = LIN0->LINESTS;

    if (error)
    {
        LIN0->LINESTS = error;
        if (g_linCallback)
        {
            g_linCallback(sts, error, 0);
        }
        return;
    }

    if (sts & (HEAD_RX_FLAG | RESP_RX_FLAG | RESP_TX_FLAG | WAKEUP_FLAG))
    {
        LIN0->LINSTS = sts;
        if (sts & WAKEUP_FLAG)
        {
            LIN0->LINIEN_B.WUIE = 0;
        }
        if (g_linCallback)
        {
            g_linCallback(sts, error, 0);
        }
    }
}

/**
 * LIN_SetEventCallBack
 *
 * @param[in]  eventFunc: Event call back function
 * @return     0: no error, 1: eventFunc is null
 *
 * @brief  Set event call back function
 */
int32_t LIN_SetEventCallBack(LIN_Event_Callback eventFunc)
{
    int32_t err = 0;

    if (eventFunc)
    {
        g_linCallback = eventFunc;
    }
    else
    {
        err = 1;
    }

    return err;
}

/**
 * LIN_Initialize
 *
 * @param[in]  config: LIN configure
 * @return : none
 *
 * @brief  Init LIN module
 */
void LIN_Initialize(LIN_Config *config)
{
    // LIN clock enable
    CKGEN_Enable(CLK_LIN, 1);
    CKGEN_SoftReset(SRST_LIN, 1);

    // Enter init mode first
    LIN_InitMode(INIT_MODE);

    // Set master or slave mode
    LIN_SetMode(config->mode);

    // Set baudrate
    LIN_SetBaudrate(config->baudrate);

    if (config->mode == MASTER_MODE)
    {
        LIN0->LINCTRL1_B.BTL = config->breakLength - 10;  // Break length 13bit (0-F : 10-25bit)
        LIN0->LINIEN_B.HRIE = 0;
    }
    else
    {
        LIN0->LINCTRL1_B.RSE = config->autoResync;  // Slave Automatic Resynchronization
        LIN0->LINCTRL1_B.BLT = config->breakThreshold;   // Break threshold length 11bit (11 / 10)
        LIN0->LINIEN_B.HRIE = 1;
    }

    LIN0->LINIEN_B.RRIE = 1;
    LIN0->LINIEN_B.RTIE = 1;

    // Enable error interrupt
    LIN0->LINIEN |= 0 << WAKEUP_IRQ_EN_POS |
                    1 << FRAME_ERR_IRQ_EN_POS |
                    0 << BUF_OVRUN_IRQ_EN_POS |
                    0 << HEAD_RX_ERR_IRQ_EN_POS |
                    1 << CS_ERR_IRQ_EN_POS |
                    1 << BIT_ERR_IRQ_EN_POS |
                    1 << TIMEOUT_ERR_IRQ_EN_POS |
                    0 << LONG0_ERR_IRQ_EN_POS;

    // Auto wakeup
    LIN0->LINCTRL1_B.ATWU = config->autoWakeup;

    // Software rx all interrupt
    LIN0->LINCTRL1_B.SCM = config->softCtrl;

    // Disable bit error to idle
    LIN0->LINCTRL1_B.DIOB = 1;

    // Enable timeout
    LIN0->LINTO2_B.TOEN = 1;

    // Enter normal mode
    LIN_InitMode(NORMAL_MODE);
}

/**
 * LIN_Uninitialize
 *
 * @param[in] : none
 * @return : none
 *
 * @brief  Uninitialize LIN module
 */
void LIN_Uninitialize(void)
{
    // LIN clock disable
    CKGEN_SoftReset(SRST_LIN, 0);
    CKGEN_Enable(CLK_LIN, 0);
}
