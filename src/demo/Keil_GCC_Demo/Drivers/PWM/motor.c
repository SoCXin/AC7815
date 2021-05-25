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
* @file     motor.c
*
* @author   AutoChips
*
* @version  0.0.1
*
* @date     March 31, 2016
*
* @brief    SensorLess BLDC Control Source Code
*
*/
#include "motor.h"
#ifndef EMULATION_TEST
#include "moduletest.h" ///Only for ucOS,when used in Emulation, Mark this, Use mDelay instead of Sleep()
#endif
#include "ac78xx_pwm.h"
#include "ac78xx_pwdt.h"
#include "ac78xx_timer.h"
#include "system_ac78xx.h"

extern void mdelay(uint32_t ms);

static uint8_t const s_motorPhaseCtrlMap [PHASE_NUM][2] =
{
    {PWM_CHANNEL_CHANNEL0, PWM_CHANNEL_CHANNEL1},
    {PWM_CHANNEL_CHANNEL2, PWM_CHANNEL_CHANNEL3},
    {PWM_CHANNEL_CHANNEL4, PWM_CHANNEL_CHANNEL5}
};

/**
*
* @param[in] None
*
* @return none
*
* @brief Mask ALL BLDC PWM Output
*
*/
void PWM_MaskAllChannels(void)
{
    PWM_OutputMaskSet(PWM2, PWM_CHANNEL_CHANNEL0);
    PWM_OutputMaskSet(PWM2, PWM_CHANNEL_CHANNEL1);
    PWM_OutputMaskSet(PWM2, PWM_CHANNEL_CHANNEL2);
    PWM_OutputMaskSet(PWM2, PWM_CHANNEL_CHANNEL3);
    PWM_OutputMaskSet(PWM2, PWM_CHANNEL_CHANNEL4);
    PWM_OutputMaskSet(PWM2, PWM_CHANNEL_CHANNEL5);
}
/**
*
* @param[in] None
*
* @return none
*
* @brief Set ALL BLDC PWM Output to Low through Software Control
*
*/
void PWM_ClearAllPWMOutput(void)
{
    PWM_OutputSWControlSet(PWM2, PWM_CHANNEL_CHANNEL0, PWM_CHOSWCR_LOW);
    PWM_OutputSWControlSet(PWM2, PWM_CHANNEL_CHANNEL1, PWM_CHOSWCR_LOW);
    PWM_OutputSWControlSet(PWM2, PWM_CHANNEL_CHANNEL2, PWM_CHOSWCR_LOW);
    PWM_OutputSWControlSet(PWM2, PWM_CHANNEL_CHANNEL3, PWM_CHOSWCR_LOW);
    PWM_OutputSWControlSet(PWM2, PWM_CHANNEL_CHANNEL4, PWM_CHOSWCR_LOW);
    PWM_OutputSWControlSet(PWM2, PWM_CHANNEL_CHANNEL5, PWM_CHOSWCR_LOW);
}
/**
*
* @param[in] None
*
* @return none
*
* @brief Change BLDC PWM Phase using Trig Mode
*
*/
void PWM_ChangeMotorPhaseUseTrigMode(void)
{
    PWM_SetPWMEnhanced(PWM2);
    PWM2->MODESEL |= PWM_MODESEL_PAIR0SYNCEN_Msk | PWM_MODESEL_PAIR1SYNCEN_Msk | PWM_MODESEL_PAIR2SYNCEN_Msk; ////Enable PWM Sync
    PWM2->SYNCONF |= PWM_SYNCONF_SWVSWSYNC_Msk |  PWM_SYNCONF_SYNCMODE_Msk | PWM_SYNCONF_SWOC_Msk;
    PWM2->SYNC |= PWM_SYNC_OMSYNCP_Msk;
    PWM2->SYNCONF |= PWM_SYNCONF_OMVSWSYNC_Msk |  PWM_SYNCONF_SYNCMODE_Msk ;
    PWM2->SYNCONF |= PWM_SYNCONF_CNTVSWSYNC_Msk | PWM_SYNCONF_PWMSVSWSYNC_Msk;  ////SW Trig MCVR and CHnV
}
/**
*
* @param[in] positivePhase: positive phase, refer to enum MOTOR_PHASE
* @param[in] nagetivePhase: nagetive phase, refer to enum MOTOR_PHASE
*
* @return none
*
* @brief Set BLDC PWM Output phase
*
*/
void PWM_MotorOutput(uint8_t positivePhase, uint8_t nagetivePhase)
{
    uint8_t i = 0;
    PWM_MaskAllChannels();
    PWM_ClearAllPWMOutput();
    for (i = 0; i < PHASE_NUM; i++)
    {
        if (i == positivePhase)
        {
            PWM_ClrOutputSWControl(PWM2, s_motorPhaseCtrlMap[positivePhase][0]);
            PWM_ClrOutputMask(PWM2, s_motorPhaseCtrlMap[positivePhase][0]);
            PWM_OutputMaskSet(PWM2, s_motorPhaseCtrlMap[positivePhase][1]);
        }
        if (i == nagetivePhase)
        {
            PWM_OutputMaskSet(PWM2, s_motorPhaseCtrlMap[nagetivePhase][0]);
            PWM_OutputSWControlSet(PWM2, s_motorPhaseCtrlMap[nagetivePhase][0], PWM_CHOSWCR_LOW);
            PWM_OutputSWControlSet(PWM2, s_motorPhaseCtrlMap[nagetivePhase][1], PWM_CHOSWCR_HIGH);
            PWM_ClrOutputMask(PWM2, s_motorPhaseCtrlMap[nagetivePhase][1]);
        }
    }
    PWM_SoftwareSync(PWM2);
}
/**
*
* @param[in] motorDir: Motor rotation Direction
* @param[in] getHallStatus: Hall Status
*
* @return return 1;
*
* @brief Sensor BLDC Start Code,
*
*/
uint8_t MotorSensor_Start(uint8_t motorDir, uint8_t getHallStatus)
{    
    if (motorDir)  ///正转
    {
        switch (getHallStatus)
        {
        case 1:        //B+,A-
            PWM_MotorOutput(PHASEB, PHASEA);
            ///g_phaseStep= 5;
            break;

        case 2:       //A+,C-
            PWM_MotorOutput(PHASEA, PHASEC);
            ///g_phaseStep=3;
            break;

        case 3:       //B+,C-
            PWM_MotorOutput(PHASEB, PHASEC);
            ///g_phaseStep=1;
            break;
        case 4:  //C+,B-
            PWM_MotorOutput(PHASEC, PHASEB);
            ///g_phaseStep=6;
            break;
        case 5:   		//C+,A-
            PWM_MotorOutput(PHASEC, PHASEA);
            ///g_phaseStep=4;
            break;
        case 6:     // A+,B-
            PWM_MotorOutput(PHASEA, PHASEB);
            ///g_phaseStep=2;
            break;
        default:
            Motor_Stop();
            break;
        }
    }
    else ///反转
    {
        switch (getHallStatus)
        {
        case 1:      // A+,B-
            PWM_MotorOutput(PHASEA, PHASEB);
            ///g_phaseStep= 5;
            break;
        case 2:  //C+,A-
            PWM_MotorOutput(PHASEC, PHASEA);
            ///g_phaseStep=3;
            break;
        case 3:                 //C+,B-
            PWM_MotorOutput(PHASEC, PHASEB);
            ///g_phaseStep=1;
            break;
        case 4:  //B+,C-
            PWM_MotorOutput(PHASEB, PHASEC);
            ///g_phaseStep=6;
            break;
        case 5:   	    //A+,C-
            PWM_MotorOutput(PHASEA, PHASEC);
            ///g_phaseStep=4;
            break;
        case 6:            //B+,A-
            PWM_MotorOutput(PHASEB, PHASEA);
            ///g_phaseStep=2;
            break;
        default:
            Motor_Stop();
            break;
        }
    }
    return 1;
}
/**
*
* @param[i] delayTime: Delay time from 0 to 0xffffffff
*
* @return none
*
* @brief Init Delay Timer
*
*/
void delay1ms(uint32_t delayTime)     ////delay 1ms
{
    uint32_t i = 0;
    uint32_t j = 0;
    for (i = 0; i < delayTime; i++)
    {
        for (j = 0; j < 5000; j++)
        {
        }
    }
}
/**
*
* @param[in] motorDir: Motor Direction(1:forward rotation;0:Reverse Rotation)
*
* @return motorStartReady: 1:Success 0:fail
*
* @brief Sensor-less BLDC Start Code,
*
*/
uint8_t MotorSensorless_Start(uint8_t motorDir)
{
    uint8_t motorStartReady = 0;
    uint16_t motorStartCnt = 0;
    uint8_t flowState = 0;
    do
    {
        if (!motorDir)
        {
            switch (flowState)
            {
            case 0: //A+,C-
                PWM_MotorOutput(PHASEA, PHASEC);
                flowState = 1;
                break;
            case 1: // A+,B-
                PWM_MotorOutput(PHASEA, PHASEB);
                flowState = 2;
                break;
            case 2://C+,B-
                PWM_MotorOutput(PHASEC, PHASEB);
                flowState = 3;
                break;
            case 3://C+,A-
                PWM_MotorOutput(PHASEC, PHASEA);
                flowState = 4;
                break;
            case 4:      //B+,A-
                PWM_MotorOutput(PHASEB, PHASEA);
                flowState = 5;
                break;
            case 5: //B+,C-
                PWM_MotorOutput(PHASEB, PHASEC);
                flowState = 0;
                break;
            default:
                break;
            }
        }
        else
        {
            switch (flowState)
            {
            case 0:// A+,B-
                PWM_MotorOutput(PHASEA, PHASEB);
                flowState = 1;
                break;
            case 1: //A+,C-
                PWM_MotorOutput(PHASEA, PHASEC);
                flowState = 2;
                break;
            case 2:  //B+,C-
                PWM_MotorOutput(PHASEB, PHASEC);
                flowState = 3;
                break;
            case 3://B+,A-
                PWM_MotorOutput(PHASEB, PHASEA);
                flowState = 4;
                break;
            case 4: //C+,A-
                PWM_MotorOutput(PHASEC, PHASEA);
                flowState = 5;
                break;
            case 5://C+,B-
                PWM_MotorOutput(PHASEC, PHASEB);
                flowState = 0;
                break;
            default:
                break;
            }
        }
        #ifndef EMULATION_TEST        
            Sleep(BLDC_SENSORLESS_INIT_DELAY_TIME); //should be tuned for different motor type(20,40,...)
        #else        
            mdelay(BLDC_SENSORLESS_INIT_DELAY_TIME);
        #endif
 ///Only for ucOS,when used in Emulation, Mark this, Use mDelay instead of Sleep()       
        if (motorStartCnt > 30)
        {
            motorStartReady = 1;
            motorStartCnt = 0;
            DEBUGMSG(DEBUG_ZONE_INFO, ("[SENSORLESS]Motor Startup OK, cut to Close loop\r\n"));
        }
        else
        {
            motorStartCnt++;
        }

    } while (!motorStartReady);
    return motorStartReady;
}
/**
*
* @param[in] motorDir: Motor Direction(1:forward rotation;0:Reverse Rotation)
* @param[in] getHallStatus: Hall Status
*
* @return motorStartReady: 1:Success 0:fail
*
* @brief Sensor-less BLDC RUN Code,
*
*/
void MotorSensorless_Run(uint8_t motorDir, uint8_t getHallStatus)
{
    if (!motorDir)  ///正转
    {
        switch (getHallStatus)
        {
        case 1:  //C+,A-
            PWM_MotorOutput(PHASEC, PHASEA);
            break;
        case 2:   //B+,C-
            PWM_MotorOutput(PHASEB, PHASEC);
            break;
        case 3:  //B+,A-
            PWM_MotorOutput(PHASEB, PHASEA);
            break;
        case 4:    // A+,B-
            PWM_MotorOutput(PHASEA, PHASEB);
            break;
        case 5:   //C+,B-
            PWM_MotorOutput(PHASEC, PHASEB);
            break;
        case 6:       //A+,C-
            PWM_MotorOutput(PHASEA, PHASEC);
            break;
        default:
            Motor_Stop();
            break;
        }
    }
    else ///反转
    {
        switch (getHallStatus)
        {
        case 1:               //C+,B-
            PWM_MotorOutput(PHASEC, PHASEB);
            break;
        case 2:    //B+,A-
            PWM_MotorOutput(PHASEB, PHASEA);
            break;
        case 3:  	//C+,A-
            PWM_MotorOutput(PHASEC, PHASEA);
            break;
        case 4:   	  //A+,C-
            PWM_MotorOutput(PHASEA, PHASEC);
            break;
        case 5:     // A+,B-
            PWM_MotorOutput(PHASEA, PHASEB);
            break;
        case 6://B+,C-
            PWM_MotorOutput(PHASEB, PHASEC);
            break;
        default:
            Motor_Stop();
            break;
        }
    }
}
/**
*
* @param[in] none
*
* @return none
*
* @brief Motor Stop Code
*
*/
void Motor_Stop(void)
{
    PWM_MaskAllChannels();
    PWM_ClearAllPWMOutput();
    PWM_SoftwareSync(PWM2);
}
/**
*
* @param[in] motorSpeed: set Motor Speed(from 0 to 100)
*
* @return none
*
* @brief Motor Set Motor Speed
*
*/
void Motor_SetMotorSpeed(uint8_t motorSpeed)
{
    PWM_SetPWMDutyCycle(PWM2, 0, motorSpeed);
    PWM_SetPWMDutyCycle(PWM2, 2, motorSpeed);
    PWM_SetPWMDutyCycle(PWM2, 4, motorSpeed);
    PWM_SoftwareSync(PWM2);
}

