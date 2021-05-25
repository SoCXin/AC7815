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
#ifndef AC78XX_PWM_H_
#define  AC78XX_PWM_H_
#ifdef __cplusplus
extern "C" {
#endif
#include "ac78xx_pwm_reg.h"
#include "ac78xx.h"

#define PWM_NUM                 4                ///< PWM NUM

#define PWM_ERR_SUCCESS         0               ///< return ok 
#define PWM_ERR_INVALID_PARAM   1               ///< return invalid parameter 



/******************************************************************************
* PWM channel number definition
*******************************************************************************/
#define PWM_CHANNEL_CHANNEL0    0               ///< channel 0 
#define PWM_CHANNEL_CHANNEL1    1               ///< channel 1 
#define PWM_CHANNEL_CHANNEL2    2               ///< channel 2 
#define PWM_CHANNEL_CHANNEL3    3               ///< channel 3 
#define PWM_CHANNEL_CHANNEL4    4               ///< channel 4 
#define PWM_CHANNEL_CHANNEL5    5               ///< channel 5 

#define PWM_CHANNELPAIR0        0               ///< channel pair 0:ch0 & ch1 
#define PWM_CHANNELPAIR1        2               ///< channel pair 1:ch2 & ch3 
#define PWM_CHANNELPAIR2        4               ///< channel pair 2:ch4 & ch5 

/******************************************************************************
* PWM pwm mode definition
*******************************************************************************/
#define PWM_PWMMODE_EDGEALLIGNED      0          ///< EPWM
#define PWM_PWMMODE_CENTERALLIGNED    1          ///< CPWM
#define PWM_PWMMODE_COMBINE           2          ///< Combine PWM 

/******************************************************************************
* PWM init value definition
*******************************************************************************/
#define PWM_MCVR_INIT	(20000-1)                ///< MVCR inite value
#define PWM_CH0V_INIT	1000                     ///< CH0V inite value
#define PWM_CH1V_INIT	1000                     ///< CH1V inite value
#define PWM_CH2V_INIT	1000                     ///< CH2V inite value    
#define PWM_CH3V_INIT	1000                     ///< CH3V inite value
#define PWM_CH4V_INIT	1000                     ///< CH4V inite value
#define PWM_CH5V_INIT	1000                     ///< CH5V inite value

/******************************************************************************
* PWM combine feature definition
*******************************************************************************/
#define PWM_MODESEL_FAULTEN_MASK  0x40       ///< fault enable
#define PWM_MODESEL_SYNCEN_MASK   0x20       ///< sync enable 
#define PWM_MODESEL_DTEN_MASK     0x10       ///< dead time insertion enable
#define PWM_MODESEL_DECAP_MASK    0x08       ///< dual capture status 
#define PWM_MODESEL_DECAPEN_MASK  0x04       ///< dual capture enable 
#define PWM_MODESEL_COMP_MASK     0x02       ///< complementary enable 
#define PWM_MODESEL_COMBINE_MASK  0x01       ///< combine enable 
/******************************************************************************
* PWM clock sources definition
*******************************************************************************/
#define PWM_CLOCK_NOCLOCK             0                 ///< No Clock 
#define PWM_CLOCK_SYSTEMCLOCK         1                 ///< System clock/2
#define PWM_CLOCK_FIXEDFREQCLOCK      2                 ///< Fixed Freq Clock
#define PWM_CLOCK_EXTERNALCLOCK       3                 ///< External Clock 

/******************************************************************************
* PWM dead time clock prescale definition
*******************************************************************************/
#define PWM_DEADTIME_DTPS_DIV1        0                 ///< DIV 1
#define PWM_DEADTIME_DTPS_DIV4        2                 ///< DIV 4 
#define PWM_DEADTIME_DTPS_DIV16       3                 ///< DIV 16

/******************************************************************************
* PWM output mode definition
*******************************************************************************/
#define PWM_OUTPUT_TOGGLE   1                    ///< toggle output on match 
#define PWM_OUTPUT_CLEAR    2                    ///< clear output on match
#define PWM_OUTPUT_SET      3                    ///< set output on match

/******************************************************************************
* PWM input capture edge definition
*******************************************************************************/
#define PWM_INPUTCAPTURE_RISINGEDGE           1     ///< rising edge
#define PWM_INPUTCAPTURE_FALLINGEDGE          2     ///< falling edge
#define PWM_INPUTCAPTURE_DUALEDGE             3     ///< both edge 

#define PWM_INPUTCAPTURE_DUALEDGE_NOEDGE      0     ///< none 
#define PWM_INPUTCAPTURE_DUALEDGE_RISINGEDGE  1     ///< rising edge
#define PWM_INPUTCAPTURE_DUALEDGE_FALLINGEDGE 2     ///< falling edge
#define PWM_INPUTCAPTURE_DUALEDGE_BOTHEDGE    3     ///< both edge 

/******************************************************************************
* PWM dual edge capture mode definition
*
*******************************************************************************/
#define PWM_INPUTCAPTURE_DUALEDGE_ONESHOT     4  ///< dual edge one shot mode 
#define PWM_INPUTCAPTURE_DUALEDGE_CONTINUOUS  5  ///< dual edge continuouse mode

/******************************************************************************
* PWM PWM edge definition
*******************************************************************************/
#define PWM_PWM_HIGHTRUEPULSE        1            ///< high true pulses
#define PWM_PWM_LOWTRUEPULSE         2            ///< low true pulses

/******************************************************************************
* PWM sync trigger source definition
*******************************************************************************/
#define PWM_SYNC_TRIGGER_SOFTWARE    0x80        ///< Software synchronization
#define PWM_SYNC_TRIGGER_SW          0x40        ///< Tigger2 synchronization, 0x40016000[14]
#define PWM_SYNC_TRIGGER_PWMCH0      0x20        ///< Tigger1 synchronization, PWMCH0
#define PWM_SYNC_TRIGGER_ACMP0       0x10        ///< Tigger0 synchronization, ACMP0

/******************************************************************************
* PWM Fault flag Clear mode definition
*******************************************************************************/
#define PWM_CHANNEL_FAULT_DIS      0
#define PWM_FAULT_MANUAL_CLEAR     2  ///< fault flag manual clear mode
#define PWM_FAULT_AUTO_CLEAR       3  ///< fault flag auto clear mode

#define PWM_INTERNAL_FAULT1     0
#define PWM_INTERNAL_FAULT2     3
#define PWM_EXTERNAL_FAULT1     1
#define PWM_EXTERNAL_FAULT2     2
/******************************************************************************
* PWM SW output control definition
*******************************************************************************/
#define PWM_CHOSWCR_HIGH    1                ///< software output high
#define PWM_CHOSWCR_LOW     0                ///< software output low 

/******************************************************************************
* PWM  polarity definition
*******************************************************************************/
#define PWM_POLARITY_HIGH     0        ///< active high
#define PWM_POLARITY_LOW      1        ///< active low 

typedef struct
{
    uint8_t   clkSource;         ///< clock source
    uint8_t   preScale;          ///< clock prescaler
    uint8_t   init;              ///< status and control
    uint8_t   funcSel;           ///< features mode selction
    uint8_t   sync;              ///< synchronization
    uint8_t   outputInit;        ///< initial state for channels output
    uint8_t   outMask;           ///< output mask
    uint8_t   extTrig;           ///< external trigger
    uint8_t   chPol;             ///< channels polarity
    uint8_t   fdsr;              ///< fault mode status
    uint8_t   fltPol;            ///< fault input polarity
    uint8_t   invCtrl;           ///< inverting control
    uint16_t  mod;               ///< counter mod
    uint16_t  cnt;               ///< counter value
    uint16_t  cntInit;           ///< counter inite
    uint16_t  dtSet;             ///< dead time insertion control
    uint16_t  capFilter;         ///< input filter control
    uint16_t  ffafer;            ///< fault control
    uint16_t  conf;              ///< PWM configuration
    uint16_t  chSwCtrl;          ///< software output control
    uint16_t  pwmLoad;           ///< pwm load control
    uint32_t  modeSel;           ///< function for linked channels
    uint32_t  synConf;           ///< synchronization configuration
} PWM_ConfigType;

typedef struct
{
    uint8_t qeiEnable      : 1;   ///<QEI Module Enable or not
    uint8_t qeiMode        : 1;   ///<QEI Mode Select, 0:PhaseA,PhaseB encoding Mode; 1:Count and direction encoding mode
    uint8_t qeiDirection   : 1;   ///< QEI direction select, 0: Counting direction is decreasing (FTM counter decrement).1: Counting direction is increasing (FTM counter increment).

    uint8_t qeiPhaPolarity : 1;   ///< 0: Normal polarity.1: Inverted polarity.
    uint8_t qeiPhbPolarity : 1;   ///< 0: Normal polarity.1: Inverted polarity.

    uint8_t qeiPhaFilterEn : 1;   ///< 0: Phase A input filter is disabled 1: Phase A input filter is enabled
    uint8_t qeiPhbFilterEn : 1;   ///< 0: Phase B input filter is disabled 1: Phase B input filter is enabled
    uint8_t RESERVED       : 1;   ///< Reserved;
} QEI_ConfigType;

typedef struct
{
    uint8_t combineEn : 1;     ///<Combine Mode Enable or not
    uint8_t compEn    : 1;     ///<Combine channel complementary Enable or not
    uint8_t decapEn   : 1;     ///<Combine dual edge capture Enable or not
    uint8_t decap     : 1;     ///<Combine dual edge capture function Enable or not
    uint8_t dtEn      : 1;     ///<Combine channel deadtime Enable or not
    uint8_t syncEn    : 1;     ///<Combine channel sync Enable or not
    uint8_t faultEn   : 1;     ///<Combien channel fault enable or not
    uint8_t RESERVED  : 1;     ///<Reserved;
} Combine_ConfigType;

void PWM_ModuleEnable(PWM_Type *PWMx);
void PWM_ModuleDisable(PWM_Type *PWMx);
int32_t PWM_EnableIRQ(PWM_Type *PWMx);
int32_t PWM_DisableIRQ(PWM_Type *PWMx);
void PWM_ClockSet(PWM_Type *PWMx, uint8_t clockSource, uint16_t clockPrescale);
int32_t PWM_PWMInit(PWM_Type *PWMx, uint8_t cntModeSelect, uint8_t pwmEdgeSelect);
int32_t PWM_InputCaptureInit(PWM_Type *PWMx, uint8_t pwmChannel, uint8_t captureMode);
int32_t PWM_DualEdgeCaptureInit(PWM_Type *PWMx, uint8_t channelPair, uint8_t captureMode,  uint8_t channelEdge, uint8_t channel1Edge);
int32_t PWM_OutputCompareInit(PWM_Type *PWMx, uint8_t pwmChannel, uint8_t compareMode);
int32_t PWM_CombineModeInit(PWM_Type *PWMx, Combine_ConfigType *combineType, uint8_t pair);
void PWM_OutputSWControlSet(PWM_Type *PWMx, uint8_t pwmChannel, uint8_t channelValue);
void PWM_OutputPolaritySet(PWM_Type *PWMx, uint8_t pwmChannel, uint8_t channelValue);
int32_t PWM_Init(PWM_Type *PWMx, PWM_ConfigType *pwmConfig);
int32_t PWM_DeInit(PWM_Type *PWMx);
int32_t PWM_QEIInit(PWM_Type *PWMx, QEI_ConfigType *qeiConfig);
int32_t PWM_QEIDeInit(PWM_Type *PWMx);
uint8_t PWM_GetQEIOverflowDirFlag(PWM_Type *PWMx);
void PWM_HardwareSyncSelect(PWM_Type *PWMx, uint8_t trigSource);
void PWM_SetPWMDutyCycle(PWM_Type *PWMx, uint8_t pwmPair, uint8_t dutyCycle);
void PWM_SetCallback(PWM_Type *PWMx, PWM_CallbackPtr pwmCallback);
void PWM0_IRQHandler(void);
void PWM1_IRQHandler(void);
void PWM2_IRQHandler(void);
void PWM3_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif
