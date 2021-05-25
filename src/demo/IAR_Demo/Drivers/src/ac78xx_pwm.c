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
/**
*
* @file ac78xx_pwm.c
*
* @author AutoChips
*
* @version 0.0.1
*
* @date March.16.2016
*
* @brief providing APIs for configuring PWM.
*
*/
#include "ac78xx_pwm.h"
static PWM_CallbackPtr s_pwmCallback[4] = {(PWM_CallbackPtr)NULL};
static const PWM_Type * const s_pwmCtrlMap [PWM_NUM] = {PWM0, PWM1, PWM2, PWM3};
static const IRQn_Type s_pwmIrqCtrlMap[PWM_NUM] = {PWM0_IRQn, PWM1_IRQn, PWM2_IRQn, PWM3_IRQn};

/**
*
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3)
*
* @return none.
*
* @brief Enable PWM Module.
*
*/
void PWM_ModuleEnable(PWM_Type *PWMx)
{
    if (PWM0 == PWMx)
    {
        CKGEN_Enable(CLK_PWM0_TIMER, 1);
        CKGEN_Enable(CLK_PWM0_APB, 1);
        CKGEN_SoftReset(SRST_PWM0_APB, 1);
        CKGEN_SoftReset(SRST_PWM0_TIMER, 1);
    }
    else if (PWM1 == PWMx)
    {
        CKGEN_Enable(CLK_PWM1_TIMER, 1);
        CKGEN_Enable(CLK_PWM1_APB, 1);
        CKGEN_SoftReset(SRST_PWM1_APB, 1);
        CKGEN_SoftReset(SRST_PWM1_TIMER, 1);
    }
    else if (PWM2 == PWMx)
    {
        CKGEN_Enable(CLK_PWM2_TIMER, 1);
        CKGEN_Enable(CLK_PWM2_APB, 1);
        CKGEN_SoftReset(SRST_PWM2_APB, 1);
        CKGEN_SoftReset(SRST_PWM2_TIMER, 1);
    }
    else
    {
        CKGEN_Enable(CLK_PWM3_TIMER, 1);
        CKGEN_Enable(CLK_PWM3_APB, 1);
        CKGEN_SoftReset(SRST_PWM3_APB, 1);
        CKGEN_SoftReset(SRST_PWM3_TIMER, 1);
    }
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3)
*
* @return none.
*
* @brief Disable PWM Module.
*/
void PWM_ModuleDisable(PWM_Type *PWMx)
{
    if (PWM0 == PWMx)
    {
        CKGEN_SoftReset(SRST_PWM0_APB, 0);
        CKGEN_SoftReset(SRST_PWM0_TIMER, 0);
        CKGEN_Enable(CLK_PWM0_TIMER, 0);
        CKGEN_Enable(CLK_PWM0_APB, 0);
    }
    else if (PWM1 == PWMx)
    {
       CKGEN_SoftReset(SRST_PWM1_APB, 0);
        CKGEN_SoftReset(SRST_PWM1_TIMER, 0);
        CKGEN_Enable(CLK_PWM1_TIMER, 0);
        CKGEN_Enable(CLK_PWM1_APB, 0);
    }
    else if (PWM2 == PWMx)
    {
        CKGEN_SoftReset(SRST_PWM2_APB, 0);
        CKGEN_SoftReset(SRST_PWM2_TIMER, 0);
        CKGEN_Enable(CLK_PWM2_TIMER, 0);
        CKGEN_Enable(CLK_PWM2_APB, 0);
    }
    else
    {
        CKGEN_SoftReset(SRST_PWM3_APB, 0);
        CKGEN_SoftReset(SRST_PWM3_TIMER, 0);
        CKGEN_Enable(CLK_PWM3_TIMER, 0);
        CKGEN_Enable(CLK_PWM3_APB, 0);
    }
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3)
* @param[in] combineType: refer to struct Combine_ConfigType
* @param[in] pair: Combine Channel value is constant: 0,1,2 or 3
* @return 0. 0:Success
*
* @brief PWM Combine Mode Select
*/
int32_t PWM_CombineModeInit(PWM_Type *PWMx, Combine_ConfigType *combineType, uint8_t pair)
{
    PWM_ModuleEnable(PWMx);
    if (combineType->combineEn)
    {
        PWMx->MODESEL |= 0x01 << (pair * 8);
    }
    if (combineType->compEn)
    {
        PWMx->MODESEL |= 0x02 << (pair * 8);
    }
    if (combineType->decapEn)
    {
        PWMx->MODESEL |= 0x04 << (pair * 8);
    }
    if (combineType->decap)
    {
        PWMx->MODESEL |= 0x08 << (pair * 8);
    }
    if (combineType->dtEn)
    {
        PWMx->MODESEL |= 0x10 << (pair * 8);
    }
    if (combineType->syncEn)
    {
        PWMx->MODESEL |= 0x20 << (pair * 8);
    }
    if (combineType->faultEn)
    {
        PWMx->MODESEL |= 0x40 << (pair * 8);
    }

    PWMx->INIT &= ~PWM_INIT_CNTMODE_Msk;

    return 0;
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3)
* @param[in] clockSource: PWM clock source(PWM_CLOCK_SYSTEMCLOCK,PWM_CLOCK_FIXEDFREQCLOCK,PWM_CLOCK_EXTERNALCLOCK).
* @param[in] clockPrescale: prescale factor(from 0 to 65535).
*
* @return none.
*
* @brief set the PWM moule clock source and prescale.
*/
void PWM_ClockSet(PWM_Type *PWMx, uint8_t clockSource, uint16_t clockPrescale)
{
    PWMx->INIT |= ((clockSource << PWM_INIT_CLKSRC_Pos) | (clockPrescale << PWM_INIT_CLKPSC_Pos));
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3)
* @param[in] cntModeSelect: select CPWM , EPWM  or combine pwm mode.
* @param[in] pwmEdgeSelect: select high true or low true pulse(PWM_PWM_HIGHTRUEPULSE and PWM_PWM_LOWTRUEPULSE).
*
* @return 0. 0:Success
*
* @brief general configuration to PWM to high ture EPWM mode, clock soure is the
*        system clock, MCVR, CHnV are the initial value.
*/
int32_t PWM_PWMInit(PWM_Type *PWMx, uint8_t cntModeSelect, uint8_t pwmEdgeSelect)
{
    uint8_t channel;
    uint8_t temp;

    if (PWM2 == PWMx)
    {
        channel = 6;
    }
    else
    {
        channel = 2;
    }
    PWM_ModuleEnable(PWMx);
    PWMx->INIT = 0x0;                                   /* disable counter */
    PWMx->MCVR = PWM_MCVR_INIT;
    switch (cntModeSelect)
    {
    case PWM_PWMMODE_CENTERALLIGNED:
        PWMx->INIT |= PWM_INIT_CNTMODE_Msk;
        break;
    case PWM_PWMMODE_EDGEALLIGNED:
        PWMx->INIT &= ~PWM_INIT_CNTMODE_Msk;
        break;
    case  PWM_PWMMODE_COMBINE:
    {
        if (PWM2 == PWMx)
        {
            PWMx->MODESEL = PWM_MODESEL_PAIR0COMBINEN_Msk | PWM_MODESEL_PAIR0COMPEN_Msk | PWM_MODESEL_PAIR0SYNCEN_Msk | PWM_MODESEL_PAIR0DTEN_Msk | PWM_MODESEL_PAIR0FAULTEN_Msk |
                            PWM_MODESEL_PAIR1COMBINEN_Msk | PWM_MODESEL_PAIR1COMPEN_Msk | PWM_MODESEL_PAIR1SYNCEN_Msk | PWM_MODESEL_PAIR1DTEN_Msk | PWM_MODESEL_PAIR1FAULTEN_Msk |
                            PWM_MODESEL_PAIR2COMBINEN_Msk | PWM_MODESEL_PAIR2COMPEN_Msk | PWM_MODESEL_PAIR2SYNCEN_Msk | PWM_MODESEL_PAIR2DTEN_Msk | PWM_MODESEL_PAIR2FAULTEN_Msk
                            ;
        }
        else
        {
            PWMx->MODESEL = PWM_MODESEL_PAIR0COMBINEN_Msk | PWM_MODESEL_PAIR0COMPEN_Msk | PWM_MODESEL_PAIR0SYNCEN_Msk |
                            PWM_MODESEL_PAIR0DTEN_Msk | PWM_MODESEL_PAIR0FAULTEN_Msk;
        }
        PWMx->INIT &= ~PWM_INIT_CNTMODE_Msk;
    }
    break;
    default:
        break;
    }
    if (PWM_PWM_HIGHTRUEPULSE == pwmEdgeSelect)
    {
        for (temp = 0; temp < channel; temp++)
        {
            PWMx->CHANNELS[temp].CHSCR = PWM_CHSCR_MSR1_Msk | PWM_CHSCR_ELSR1_Msk;
            PWMx->CHANNELS[temp].CHV = PWM_CH0V_INIT + temp;
        }
    }
    else
    {
        for (temp = 0; temp < channel; temp++)
        {
            PWMx->CHANNELS[temp].CHSCR = PWM_CHSCR_MSR1_Msk | PWM_CHSCR_ELSR0_Msk;
            PWMx->CHANNELS[temp].CHV = PWM_CH0V_INIT + temp;
        }
    }
    return 0;
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3)
*
* @return 0. 0:Success
*
* @brief Enable PWM IRQ
*/
int32_t PWM_EnableIRQ(PWM_Type *PWMx)
{
    uint8_t i = 0;
    IRQn_Type tmpIrq = PWM0_IRQn;

    for (i = 0; i < PWM_NUM; i++)
    {
        if (PWMx == (PWM_Type *)s_pwmCtrlMap [i])
        {
            tmpIrq = s_pwmIrqCtrlMap[i];
        }
    }
    NVIC_EnableIRQ(tmpIrq);

    return 0;
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3)
*
* @return 0. 0:Success
*
* @brief Disable PWM IRQ
*/
int32_t PWM_DisableIRQ(PWM_Type *PWMx)
{
    uint8_t i = 0;
    IRQn_Type tmpIrq = PWM0_IRQn;

    for (i = 0; i < PWM_NUM; i++)
    {
        if (PWMx == (PWM_Type *)s_pwmCtrlMap[i])
        {
            tmpIrq = s_pwmIrqCtrlMap[i];
        }
    }
    NVIC_DisableIRQ(tmpIrq);

    return 0;
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3)
* @param[in] pwmChannel: channel number to be configured.
* @param[in] captureMode: select capture edge: rising, falling or both.
*
* @return 0. 0:Success; -1:error
*
* @brief general configuration PWM to input capture mode, enable interrupt.
*/
int32_t PWM_InputCaptureInit(PWM_Type *PWMx, uint8_t pwmChannel, uint8_t captureMode)
{
    int32_t err = 0;
    PWM_ModuleEnable(PWMx);

    PWMx->INIT  = 0x0;
    PWMx->MCVR = 0xFFFF;

    PWMx->CHANNELS[pwmChannel].CHSCR = 0;

    if (PWM_INPUTCAPTURE_RISINGEDGE == captureMode)        //Capture on rising edge
    {
        PWMx->CHANNELS[pwmChannel].CHSCR = PWM_CHSCR_CHIE_Msk | PWM_CHSCR_ELSR0_Msk;
    }
    else if (PWM_INPUTCAPTURE_FALLINGEDGE == captureMode)  //Capture on falling edge
    {
        PWMx->CHANNELS[pwmChannel].CHSCR = PWM_CHSCR_CHIE_Msk | PWM_CHSCR_ELSR1_Msk;
    }
    else if (PWM_INPUTCAPTURE_DUALEDGE == captureMode)     //Capture on rising or falling edge
    {
        PWMx->CHANNELS[pwmChannel].CHSCR = PWM_CHSCR_CHIE_Msk | PWM_CHSCR_ELSR0_Msk | PWM_CHSCR_ELSR1_Msk;
    }
    else
    {
        err = -1;
    }

    return err;
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3)
* @param[in] channelPair: ChannelPair number to be configured: 0, 2, 4.
* @param[in] captureMode: select capture edge: one shot and continuous mode.
* @param[in] channelEdge: channel N detect edge.
* @param[in] channel1Edge: channel N+1 detect edge.
*
* @return 0.   0:Success
*
* @brief general configuration PWM to Dual Edge Capture mode to measure the
*        width or the period  of a pulse.
*/
int32_t PWM_DualEdgeCaptureInit(PWM_Type *PWMx, uint8_t channelPair, uint8_t captureMode,
                                uint8_t channelEdge, uint8_t channel1Edge)
{
    PWM_ModuleEnable(PWMx);

    PWMx->INIT    = 0x0;                  //diable counter
    PWMx->MCVR   = 0xFFFF;
    PWMx->FUNCSEL |= PWM_FUNCSEL_PWMEN2_Msk;
    PWMx->MODESEL |=  ((PWM_MODESEL_PAIR0DECAPEN_Msk) << (channelPair * 4));

    PWMx->CHANNELS[channelPair].CHSCR &= ~PWM_CHSCR_CHIF_Msk;       //CH(n)F and CH(n+1)F bits must be cleared first
    PWMx->CHANNELS[channelPair + 1].CHSCR &= ~PWM_CHSCR_CHIF_Msk;

    if (PWM_INPUTCAPTURE_DUALEDGE_ONESHOT == captureMode)          //oneshot mode
    {
        PWMx->CHANNELS[channelPair].CHSCR &= ~PWM_CHSCR_MSR0_Msk;
    }
    else //continuouse mode
    {
        PWMx->CHANNELS[channelPair].CHSCR |= PWM_CHSCR_MSR0_Msk;
    }

    PWMx->CHANNELS[channelPair].CHSCR |= (channelEdge << 2);  //select detec edge
    PWMx->CHANNELS[channelPair + 1].CHSCR |= (channel1Edge << 2);

    PWMx->MODESEL |=  (PWM_MODESEL_PAIR0DECAP_Msk << (channelPair * 4));

    return 0;
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3)
* @param[in] pwmChannel: channel number to be configured.
* @param[in] compareMode: select compare edge: toggle, set and clear.
*
* @return 0. 0:Success
*
* @brief general configuration PWM to output compare mode.
*/
int32_t PWM_OutputCompareInit(PWM_Type *PWMx, uint8_t pwmChannel, uint8_t compareMode)
{
    PWM_ModuleEnable(PWMx);
    PWMx->INIT  = 0x0;                                                                   //diable counter
    PWMx->MCVR = PWM_MCVR_INIT;
    PWMx->CHANNELS[pwmChannel].CHSCR = (PWM_CHSCR_MSR0_Msk | (compareMode << 2));    //select detec edge
    PWMx->CHANNELS[pwmChannel].CHV  = PWM_CH0V_INIT;

    return 0;
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3)
* @param[in] pwmChannel: pwm channel needed to be controlled by software.
* @param[in] channelValue: the value to be set,  0 or 1.
*
* @return none.
*
* @brief general configuration PWM to start software synchronization.
*/
void PWM_OutputSWControlSet(PWM_Type *PWMx, uint8_t pwmChannel, uint8_t channelValue)
{
    if (PWM_CHOSWCR_HIGH == channelValue)
    {
        PWMx->CHOSWCR |= (0x0101 << pwmChannel);
    }
    else
    {
        PWMx->CHOSWCR |= (1 << pwmChannel);
        PWMx->CHOSWCR &= ~(0x100UL << pwmChannel);
    }
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3)
* @param[in] enable: 1: enable PWM2 6 channel complementary Mode; 0: Disable PWM2 complementary mode
*
* @return none
*
* @brief PWM_ComplementaryModeConfig
*
*/
void PWM_ComplementaryModeConfig(PWM_Type *PWMx, uint8_t enable)
{
    if (PWM2 == PWMx)
    {
        if (enable)
        {
            PWMx->MODESEL |= PWM_MODESEL_PAIR0COMPEN_Msk | PWM_MODESEL_PAIR1COMPEN_Msk | PWM_MODESEL_PAIR2COMPEN_Msk ;
        }
        else
        {
            PWMx->MODESEL &= ~PWM_MODESEL_PAIR0COMPEN_Msk;
            PWMx->MODESEL &= ~PWM_MODESEL_PAIR1COMPEN_Msk;
            PWMx->MODESEL &= ~PWM_MODESEL_PAIR2COMPEN_Msk;
        }
    }
    else
    {
        //only PWM2 can config complementary mode
    }
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3)
* @param[in] pwmChannel: pwm channel needed to be controlled by software.
* @param[in] channelValue: the value to be set,  0 or 1.
*
* @return none.
*
* @brief set PWM polarity.
*/
void PWM_OutputPolaritySet(PWM_Type *PWMx, uint8_t pwmChannel, uint8_t channelValue)
{
    if (PWM_POLARITY_HIGH == channelValue)
    {
        PWMx->CHOPOLCR &=  ~(1UL << pwmChannel);
    }
    else
    {
        PWMx->CHOPOLCR |=  (1 << pwmChannel);
    }
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3)
* @param[in] trigSource: select the hardware trigger source.
*
* @return none.
*
* @brief general configuration to PWM to enable hardware synchronization.
*/
void PWM_HardwareSyncSelect(PWM_Type *PWMx, uint8_t trigSource)
{
    PWMx->SYNCONF   |= PWM_SYNCONF_SYNCMODE_Msk;   //recommend enhanced sync mode

    switch (trigSource)
    {
    case PWM_SYNC_TRIGGER_SW:
        PWMx->SYNC |= PWM_SYNC_SWTRIG_Msk;
        break;
    case PWM_SYNC_TRIGGER_PWMCH0: //need configure PWM0CH0 first
        PWMx->SYNC |= PWM_SYNC_PWMTRIG_Msk;
        break;
    case PWM_SYNC_TRIGGER_ACMP0: //need configure ACMP0 first
        PWMx->SYNC |= PWM_SYNC_ACMPTRIG_Msk;
        break;
    default:
        break;
    }
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3)
* @param[in] pwmConfig: pointer to PWM general parameters, refer to struct PWM_ConfigType.
*
* @return 0. 0:Success
*
* @brief configure the PWM as specified control parameters
*/
int32_t PWM_Init(PWM_Type *PWMx, PWM_ConfigType *pwmConfig)
{
    PWM_ModuleEnable(PWMx);

    PWMx->INIT = 0; //diable counter
    PWMx->FUNCSEL = pwmConfig->funcSel;
    PWMx->MCVR = pwmConfig->mod;
    PWMx->CNT = pwmConfig->cnt;

    PWMx->MODESEL   = pwmConfig->modeSel;
    PWMx->CNTIN     = pwmConfig->cntInit;
    PWMx->SYNC      = pwmConfig->sync;
    PWMx->OUTINIT   = pwmConfig->outputInit;
    PWMx->OMCR   = pwmConfig->outMask;
    PWMx->DTSET  = pwmConfig->dtSet;
    PWMx->EXTTRIG   = pwmConfig->extTrig;
    PWMx->CHOPOLCR = pwmConfig->chPol;
    PWMx->FDSR = pwmConfig->fdsr;
    PWMx->CAPFILTER = pwmConfig->capFilter;
    PWMx->FFAFER = pwmConfig->ffafer;   //fault control
    PWMx->FLTPOL    = pwmConfig->fltPol;
    PWMx->CONF      = pwmConfig->conf;
    PWMx->SYNCONF   = pwmConfig->synConf;
    PWMx->CHOSWCR = pwmConfig->chSwCtrl;

    PWMx->INIT = pwmConfig->init; //enable clock

    return 0;
}


/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3)
*
* @return 0. 0:Success
*
* @brief  DeInitialize the PWM moudle.
*/
int32_t PWM_DeInit(PWM_Type *PWMx)
{
    uint8_t i = 0;
    IRQn_Type tmpIrq = PWM0_IRQn;

    PWMx->INIT = 0;
    PWMx->MCVR = 0;
    PWMx->CNT = 0;
    PWMx->FUNCSEL = 0x4;
    PWMx->MODESEL = 0;
    PWMx->CNTIN = 0;
    PWMx->SYNC = 0;
    PWMx->OUTINIT = 0;
    PWMx->OMCR = 0;
    PWMx->DTSET = 0;
    PWMx->EXTTRIG = 0;
    PWMx->CHOPOLCR = 0;
    PWMx->FDSR = 0;
    PWMx->CAPFILTER = 0;
    PWMx->FFAFER = 0;
    PWMx->QEI = 0;
    PWMx->FLTPOL = 0;
    PWMx->CONF = 0;
    PWMx->SYNCONF = 0;
    PWMx->CHOSWCR = 0;

    PWM_ModuleDisable(PWMx);
    for (i = 0; i < PWM_NUM; i++)
    {
        if (PWMx == (PWM_Type *)s_pwmCtrlMap[i])
        {
            tmpIrq = s_pwmIrqCtrlMap[i];
        }
    }
    NVIC_DisableIRQ(tmpIrq);
    return 0;
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3)
* @param[in] qeiConfig: refer to struct QEI_Config Type, Set QEI Config
*
* @return 0. 0:Success
*
* @brief  QEI Init
*/
int32_t PWM_QEIInit(PWM_Type *PWMx, QEI_ConfigType *qeiConfig)
{
    uint32_t tmpReg = 0;

    PWM_ModuleEnable(PWMx);
    tmpReg |= (qeiConfig->qeiMode) << PWM_QEI_QUADMODE_Pos;
    tmpReg |= (qeiConfig->qeiDirection) << PWM_QEI_QUADIR_Pos;
    tmpReg |= (qeiConfig->qeiPhaPolarity) << PWM_QEI_PHAPOL_Pos;
    tmpReg |= (qeiConfig->qeiPhbPolarity) << PWM_QEI_PHBPOL_Pos;
    tmpReg |= (qeiConfig->qeiPhaFilterEn) << PWM_QEI_PHAFLTREN_Pos;
    tmpReg |= (qeiConfig->qeiPhbFilterEn) << PWM_QEI_PHBFLTREN_Pos;
    tmpReg |= (qeiConfig->qeiEnable) << PWM_QEI_QEIEN_Pos;

    PWMx->QEI = tmpReg;

    return 0;
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3)
*
* @return 0. 0:Success
*
* @brief  QEI DeInit
*/
int32_t PWM_QEIDeInit(PWM_Type *PWMx)
{
    PWMx->QEI = 0x00;
    PWM_ModuleDisable(PWMx);
    return 0;
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3)
*
* @return QEI Overflow Direction Flag.
*
* @brief  Get QEI Status
*/
uint8_t PWM_GetQEIOverflowDirFlag(PWM_Type *PWMx)
{
    return( (PWMx->QEI & PWM_QEI_TOFDIR_Msk) >> PWM_QEI_TOFDIR_Pos);
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3)
* @param[in] pwmPair: odd channel num:0,2.4.
* @param[in] dutyCycle: duty cycle in percentage. e.g. 10, means 10%.
*
* @return none.
*
* @brief set the PWM channel value register per duty cycle and modulo for combine mode
*        odd channel no must be provided and even channel value register is not changed.
*/
void PWM_SetPWMDutyCycle(PWM_Type *PWMx, uint8_t pwmPair, uint8_t dutyCycle)
{
    uint16_t   cnv = PWMx->CHANNELS[pwmPair].CHV;
    uint16_t   modulo = PWMx->MCVR;

    cnv += (dutyCycle * (modulo + 1)) / 100;
    if (cnv > modulo)
    {
        cnv = modulo - 1;
    }
    PWMx->CHANNELS[pwmPair + 1].CHV = cnv ;

}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3)
* @param[in] pwmCallback: functon address.
*
* @return none.
*
* @brief This function sets the callback function.
*/
void PWM_SetCallback(PWM_Type *PWMx, PWM_CallbackPtr pwmCallback)
{
    if (PWM3 == PWMx)
    {
        s_pwmCallback[3] = pwmCallback;
    }
    else
    {
        s_pwmCallback[((uint32_t)PWMx - (uint32_t)PWM0_BASE) >> 12] = pwmCallback;
    }
}
/**
*
* @param[in] none.
*
* @return none.
*
* @brief PWM0_Isr interrupt service routine.
*/
void PWM0_IRQHandler(void)
{
    if (s_pwmCallback[0])
    {
        s_pwmCallback[0]();
    }
}

/**
*
* @param[in] none.
*
* @return none.
*
* @brief PWM1_Isr interrupt service routine.
*/
void PWM1_IRQHandler(void)
{
    if (s_pwmCallback[1])
    {
        s_pwmCallback[1]();
    }
}

/**
*
* @param[in] none.
*
* @return none.
*
* @brief PWM2_Isr interrupt service routine.
*/
void PWM2_IRQHandler(void)
{
    if (s_pwmCallback[2])
    {
        s_pwmCallback[2]();
    }
}
/**
*
* @param[in] none.
*
* @return none.
*
* @brief PWM3_Isr interrupt service routine.
*/
void PWM3_IRQHandler(void)
{
    if (s_pwmCallback[3])
    {
        s_pwmCallback[3]();
    }
}
