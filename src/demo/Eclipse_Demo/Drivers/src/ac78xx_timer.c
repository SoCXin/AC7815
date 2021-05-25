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
/*******************************************************************************
*
* @file     ac78xx_timer.c
*
* @author   AutoChips
*
* @version  0.0.1
*
* @date     March 23, 2016
*
* @brief    Periodic Interrupt Timer (TIMER) source code.
*
******************************************************************************/
#include "ac78xx_timer.h"
/**
* @param[in] timIndex:timer channel (0~7)
*
* @return TIMx: current timer channel
*
* @brief Get timer channel
*/
TIMER_Type* TIMER_GetTimerCtrl(uint8_t timIndex)
{
    TIMER_Type* TIMx = 0;
    if (timIndex < TIMER_NUM)
    {
        TIMx = (TIMER_Type*)s_timerCtrlMap[timIndex];
    }

    return TIMx;
}
/**
* @param[in] none
*
* @return none
*
* @brief TIMER module Enable
*/
void TIMER_ModuleEnable(void)
{
    /********************Enable TIM Clock****************/
    CKGEN_Enable(CLK_TIM, 1);
    CKGEN_SoftReset(SRST_TIM, 1);
    /*****************************************************/
    TIMER->MCR = 0x00;
}
/**
* @param[in] none
*
* @return none
*
* @brief TIMER module Disable
*/
void TIMER_ModuleDisable(void)
{
    TIMER->MCR = 0x02;
    ///<Disable TIM Clock
    CKGEN_SoftReset(SRST_TIM, 0);
    CKGEN_Enable(CLK_TIM, 0);
}
/**
* @param[in] TIMx: TIMER channel(TIMER0~TIMER7)
* @param[in] timConfig: TIMER config type pointer
* @return 0:Success
*
* @brief TIMER module initialize
*/
int32_t TIMER_Init(TIMER_Type *TIMx, TIMER_ConfigType *timConfig)
{
    IRQn_Type timeIrq = TIMER0_IRQn;
    uint8_t i;
    for (i = 0; i < TIMER_NUM; i++)
    {
        if (TIMx == (TIMER_Type*)s_timerCtrlMap[i])
        {
            timeIrq = s_timerIrqnCtrlMap[i];
        }
    }
    if (TIMER->MCR & TIMER_MCR_TMER_Msk) ///Enable Timer
    {
        TIMER_ModuleEnable();
    }
    TIMx->INITVAL = timConfig->loadValue;

    if (timConfig->interruptEn)
    {
        NVIC_EnableIRQ(timeIrq);
        TIMx->INIT |= ( timConfig->interruptEn << TIMER_INIT_TIE_Pos);
    }
    else
    {
        NVIC_DisableIRQ(timeIrq);
    }
    if (timConfig->linkMode)
    {
        TIMx->INIT |= (timConfig->linkMode << TIMER_INIT_LINKEN_Pos);
    }

    if (timConfig->timerEn)
    {
        TIMx->INIT |= (timConfig->timerEn << TIMER_INIT_TIMEREN_Pos);
    }
    return 0;
}

/**
* @param[in] TIMx: TIMER channel(TIMER0~TIMER7)
* @param[in] loadValue: timer init value
* @return none
*
* @brief Set timer init value
*/
void TIMER_SetLoadVal(TIMER_Type *TIMx, uint32_t loadValue)
{
    TIMx->INITVAL = loadValue;

}
/**
* @param[in] TIMx: TIMER channel(TIMER0~TIMER7)
*
* @return flag: Timer channel interrupt Flag
*
* @brief   Get timer channel interrupt flag
*/
uint8_t TIMER_GetIntFlag(TIMER_Type *TIMx)
{
    uint8_t flag;

    flag = (TIMx->TF & TIMER_TF_TIF_Msk);

    return flag;

}

/**
* @param[in] TIMx: TIMER channel(TIMER0~TIMER7)
*
* @return none
*
* @brief clear timer channel interrrupt flag
*/
void TIMER_ClrIntFlag(TIMER_Type *TIMx)
{
    TIMx->TF |= TIMER_TF_TIF_Msk;

}
/**
* @param[in]  TIMx: TIMER channel(TIMER0~TIMER7)
* @param[in]  timeCallback: timer callback
* @return none
*
* @brief TIMER module set call back
*/
void TIMER_SetCallback(TIMER_Type *TIMx, TIMER_CallbackType timeCallback)
{
    s_timerCallback[((uint32_t)TIMx - (uint32_t)TIMER0_BASE) >> 4]  = timeCallback;
}
/**
* @param[in] TIMx: TIMER channel(TIMER0~TIMER7)
*
* @return 0:Success
*
* @brief TIMER module de-initialize, reset TIMER register
*/
int32_t TIMER_DeInit(TIMER_Type *TIMx)
{
    uint8_t i = 0;
    IRQn_Type timeIrq = TIMER0_IRQn;

    for (i = 0; i < TIMER_NUM; i++)
    {
        if (TIMx == (TIMER_Type*)s_timerCtrlMap[i])
        {
            timeIrq = s_timerIrqnCtrlMap[i];
        }
    }
    NVIC_DisableIRQ(timeIrq);
    TIMER_SetLoadVal(TIMx, 0);
    TIMER_Disable(TIMx);
    TIMER_DisableInt(TIMx);
    TIMER_DisableLinkMode(TIMx);
    TIMER_ClrIntFlag(TIMx);
    return 0;
}


/**
* @param[in] none
*
* @return none
*
* @brief TIMER0 interrupt service routine
*/
void TIMER0_IRQHandler(void)
{
    if (s_timerCallback[0])
    {
        s_timerCallback[0](0);
    }
}

/**
* @param[in] none
*
* @return none
*
* @brief TIMER1 interrupt service routine
*/
void TIMER1_IRQHandler(void)
{
    if (s_timerCallback[1])
    {
        s_timerCallback[1](1);
    }
}
/**
* @param[in] none
*
* @return none
*
* @brief TIMER2 interrupt service routine
*/
void TIMER2_IRQHandler(void)
{
    if (s_timerCallback[2])
    {
        s_timerCallback[2](2);
    }
}
/**
* @param[in] none
*
* @return none
*
* @brief TIMER3 interrupt service routine
*/
void TIMER3_IRQHandler(void)
{
    if (s_timerCallback[3])
    {
        s_timerCallback[3](3);
    }
}
/**
* @param[in] none
*
* @return none
*
* @brief TIMER4 interrupt service routine
*/
void TIMER4_IRQHandler(void)
{
    if (s_timerCallback[4])
    {
        s_timerCallback[4](4);
    }
}
/**
* @param[in] none
*
* @return none
*
* @brief TIMER5 interrupt service routine
*/
void TIMER5_IRQHandler(void)
{
    if (s_timerCallback[5])
    {
        s_timerCallback[5](5);
    }
}
/**
* @param[in] none
*
* @return none
*
* @brief TIMER6 interrupt service routine
*/
void TIMER6_IRQHandler(void)
{
    if (s_timerCallback[6])
    {
        s_timerCallback[6](6);
    }
}
/**
* @param[in] none
*
* @return none
*
* @brief TIMER7 interrupt service routine
*/
void TIMER7_IRQHandler(void)
{
    if (s_timerCallback[7])
    {
        s_timerCallback[7](7);
    }
}
