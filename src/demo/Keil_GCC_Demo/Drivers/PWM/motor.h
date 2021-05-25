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
* @file     motor.h
*
* @author   AutoChips
*
* @version  0.0.1
*
* @date     March 31, 2016
*
* @brief    SensorLess BLDC Header file
*
******************************************************************************/
#ifndef __MOTOR_H_
#define __MOTOR_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include "ac78xx_pwm.h"
#define MOTOR_DIRECTION_FORWARD     1  ///<Motor正转
#define MOTOR_DIRECTION_REVERSE     0  ///<Motor反转   

#define MOTOR_WITH_SENSOR     1///<Motor With Hall Sensor
#define MOTOR_WITHOUT_SENSOR  0///<Motor Without Hall Sensor    

#define BLDC_SENSORLESS_INIT_DELAY_TIME  20//40 ///<Init delay time for Motor-Sensorless Open Kick    

typedef enum {      ///<Define BLDC 3 phase
    PHASEA = 0,     ///<phase A
    PHASEB,         ///<phase B
    PHASEC,         ///<phase C
    PHASE_NUM,
}
MOTOR_PHASE;

void PWM_MotorOutput(uint8_t positivePhase, uint8_t nagetivePhase);
void delay1ms(uint32_t delayTime);     ///<delay 1ms
void PWM_ChangeMotorPhaseUseTrigMode(void);
uint8_t MotorSensorless_Start(uint8_t motorDir);///<Motor Start(Wait for Motor Startup)
void MotorSensorless_Run(uint8_t motorDir, uint8_t getHallStatus);
uint8_t MotorSensor_Start(uint8_t motorDir, uint8_t getHallStatus);
void Motor_SetMotorSpeed(uint8_t motorSpeed);
void Motor_Stop(void);
void PWM_MaskAllChannels(void);
void PWM_ClearAllPWMOutput(void);
#ifdef __cplusplus
}
#endif

#endif
