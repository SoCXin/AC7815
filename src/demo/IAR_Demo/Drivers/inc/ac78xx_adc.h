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
#ifndef AC78XX_ADC_H_
#define  AC78XX_ADC_H_
#ifdef __cplusplus
extern "C" {
#endif
#include "ac78xx_adc_reg.h"
#include "ac78xx.h"


typedef void (*ADC_CallbackType)(void);							///< ADC call back function

#define ADC_CHANNEL_AD0                                 0x0 ///< ADC input channel 0
#define ADC_CHANNEL_AD1                                 0x1 ///< ADC input channel 1
#define ADC_CHANNEL_AD2                                 0x2 ///< ADC input channel 2
#define ADC_CHANNEL_AD3                                 0x3 ///< ADC input channel 3
#define ADC_CHANNEL_AD4                                 0x4 ///< ADC input channel 4
#define ADC_CHANNEL_AD5                                 0x5 ///< ADC input channel 5
#define ADC_CHANNEL_AD6                                 0x6 ///< ADC input channel 6
#define ADC_CHANNEL_AD7                                 0x7 ///< ADC input channel 7
#define ADC_CHANNEL_AD8                                 0x8 ///< ADC input channel 8
#define ADC_CHANNEL_AD9                                 0x9 ///< ADC input channel 9
#define ADC_CHANNEL_AD10                                0xa ///< ADC input channel 10
#define ADC_CHANNEL_AD11                                0xb ///< ADC input channel 11
#define ADC_CHANNEL_AD12                                0xc ///< ADC input channel 12
#define ADC_CHANNEL_AD13                                0xd ///< ADC input channel 13
#define ADC_CHANNEL_AD14                                0xe ///< ADC input channel 14
#define ADC_CHANNEL_AD15                                0xf ///< ADC input channel 15
#define ADC_CHANNEL_AD16                                0x10///< ADC input channel 16
#define ADC_CHANNEL_AD17                                0x11///< ADC input channel 17
#define ADC_CHANNEL_AD16_BANDGAP                        0x10///< ADC input channel bandgap
#define ADC_CHANNEL_AD17_TEMPSENSOR                     0x11///< ADC input channel internal temperature sensor

#define ADC_ADIV_DIVIDE_1                               0x00///< ADC clock divide by 1
#define ADC_ADIV_DIVIDE_2                               0x01///< ADC clock divide by 2
#define ADC_ADIV_DIVIDE_3                               0x02///< ADC clock divide by 3
#define ADC_ADIV_DIVIDE_4                               0x03///< ADC clock divide by 4
#define ADC_ADIV_DIVIDE_5                               0x04///< ADC clock divide by 5
#define ADC_ADIV_DIVIDE_6                               0x05///< ADC clock divide by 6
#define ADC_ADIV_DIVIDE_7                               0x06///< ADC clock divide by 7
#define ADC_ADIV_DIVIDE_8                               0x07///< ADC clock divide by 8
#define ADC_ADIV_DIVIDE_9                               0x08///< ADC clock divide by 9
#define ADC_ADIV_DIVIDE_10                              0x09///< ADC clock divide by 10
#define ADC_ADIV_DIVIDE_11                              0x0A///< ADC clock divide by 11
#define ADC_ADIV_DIVIDE_12                              0x0B///< ADC clock divide by 12
#define ADC_ADIV_DIVIDE_13                              0x0C///< ADC clock divide by 13
#define ADC_ADIV_DIVIDE_14                              0x0D///< ADC clock divide by 14
#define ADC_ADIV_DIVIDE_15                              0x0E///< ADC clock divide by 15
#define ADC_ADIV_DIVIDE_16                              0x0F///< ADC clock divide by 16

#define IDR_Offset       0x3C
#define ADC_InjectedChannel_1                           0x00///<Injected Channel1 selected
#define ADC_InjectedChannel_2                           0x04///<Injected Channel2 selected
#define ADC_InjectedChannel_3                           0x08///<Injected Channel3 selected
#define ADC_InjectedChannel_4                           0x0C///<Injected Channel4 selected

#define ADC_FLAG_AMO                                    0x01///<Analog monitor/watchdog flag
#define ADC_FLAG_EOC                                    0x02///<End of conversion flag
#define ADC_FLAG_IEOC                                   0x04///<End of injected group conversion flag

#define ADC_DataAlign_Right                             ((uint32_t)0x00)///<Conversion Data right alignment
#define ADC_DataAlign_Left                              ((uint32_t)0x01)///<Conversion Data left alignment

#define ADC_TrigSource_Internal                         ((uint32_t)0x00)///<Conversion trig source software
#define ADC_TrigSource_External                         ((uint32_t)0x01)///<Conversion trig source external

#define ADC_AnalogWatchDog_SingleChannelEnable          ((uint32_t)0x01)///<WatchDog Channel Enable
#define ADC_AnalogWatchDog_OnRegularEnable              ((uint32_t)0x01)///<WatchDog Regular group Enable
#define ADC_AnalogWatchDog_OnInjectEnable               ((uint32_t)0x01)///<WatchDog Inject group Enable

#define AMO_SETTING_RESET                               (0xffffff1f)///<Monitor configt reset
#define TRIG_SOURCE_SETTING_RESET                       (0xffcfffff)///<Conversion trig source reset
#define ADC_MODE_RESET                                  (0xffff07ff)///<ADC Conversion Mode reset

#define ADC_SampleTime_6Cycle                           ((uint8_t)0x00)///<ADC Sample 6 Clock Cycle
#define ADC_SampleTime_14Cycle                          ((uint8_t)0x01)///<ADC Sample 14 Clock Cycle
#define ADC_SampleTime_29Cycle                          ((uint8_t)0x02)///<ADC Sample 29 Clock Cycle
#define ADC_SampleTime_42Cycle                          ((uint8_t)0x03)///<ADC Sample 42 Clock Cycle
#define ADC_SampleTime_56Cycle                          ((uint8_t)0x04)///<ADC Sample 56 Clock Cycle
#define ADC_SampleTime_72Cycle                          ((uint8_t)0x05)///<ADC Sample 72 Clock Cycle
#define ADC_SampleTime_215Cycle                         ((uint8_t)0x06)///<ADC Sample 215 Clock Cycle
#define ADC_SampleTime_3Cycle                           ((uint8_t)0x07)///<ADC Sample 3 Clock Cycle

#define ADC_Regular_Single_One_Mode                     ((uint8_t)0x01)///<ADC Conversion Regular Group Single Channel one times Mode 
#define ADC_Regular_Single_Continous_Mode               ((uint8_t)0x02)///<ADC Conversion Regular Group Single Channel continous Mode 
#define ADC_Regular_Multiple_One_Mode                   ((uint8_t)0x03)///<ADC Conversion Regular Group Multipe Channel and Auto Inject Group one time Mode 
#define ADC_Regular_Multiple_AutoInject_Mode            ((uint8_t)0x04)///<ADC Conversion Regular Group Multipe Channel one time Mode 
#define ADC_Regular_Multiple_Continous_Mode             ((uint8_t)0x05)///<ADC Conversion Regular Group Multipe Channel continous Mode 
#define ADC_Regular_Multiple_Continous_AutoInject_Mode 	((uint8_t)0x06)///<ADC Conversion Regular Group Multipe Channel and Auto Inject Group continous Mode 
#define ADC_Regular_Multiple_Discontinous_Mode          ((uint8_t)0x07)///<ADC Conversion Regular Group Multipe Channel by Disnum one time Mode 
#define ADC_Inject_Multiple_Discontinous_Mode         	((uint8_t)0x08)///<ADC Conversion Inject Group by Disnum one time Mode 

#define ADC_ENABLE                                      1///<Set enable
#define ADC_DISABLE                                     0///<Set disable

typedef struct {
    uint32_t dataAlign;                                 ///< Select Data Alignment: 0 for Right alignment; 1 for left alignment
    uint32_t scanMode;                                  ///< Scan Mode for Regular and Inject Group Enable/Disable
    uint32_t continousMode;                             ///< Continous Mode Enabled/Disabled
    uint32_t disContinousModeOnRegularGroup;            ///< Discontinous Mode for Regular Group
    uint32_t disContinousModeOnInjectGroup;             ///< Discontinous Mode for Inject Group
    uint32_t injectAutoMode;                            ///< Antomatic Mode for Inject Group
    uint32_t discNum;                                   ///< Discontinous Mode the number of continous
} ADC_InitType;
typedef struct {
    uint32_t regularTrigSource;                         ///< Select Internal or External Trigger Source for Regular Group
    uint32_t injectTrigSource;                          ///< Select Internal or External Trigger Source for Inject Group
} ADC_TrigSourceType;
typedef struct {
    uint32_t analogWatchDogSingleMode;                  ///< Select WatchDog single channel mode
    uint32_t analogWatchDogOnRegularGroup;              ///< Select WatchDog Gegular Group mode
    uint32_t analogWatchDogOnInjectGroup;               ///< Select WatchDog Inject Group mode
    uint32_t analogWatchDogChannel;                     ///< Select WatchDog ADC Channel
} ADC_AnalogWatchDogType;

void ADC_DeInit(ADC_Type* ADCx);
void ADC_ModuleEnable(ADC_Type* ADCx);
void ADC_ModuleDisable(ADC_Type* ADCx);
void ADC_AnalogWatchDogInit(ADC_Type* ADCx, ADC_AnalogWatchDogType* adcAnalogWatchDogConfig);
void ADC_TrigSourceInit(ADC_Type* ADCx, ADC_TrigSourceType* adcTrigSourceConfig);
void ADC_DMACmd(ADC_Type* ADCx, uint8_t state);
void ADC_SoftwareStartRegularConvCmd(ADC_Type* ADCx, uint8_t state);
void ADC_SoftwareStartInjectConvCmd(ADC_Type* ADCx, uint8_t state);
void ADC_Cmd(ADC_Type* ADCx, uint8_t state);
void ADC_Init(ADC_Type* ADCx, ADC_InitType* adcConfig);
uint16_t ADC_GetRegularConversionValue(ADC_Type* ADCx);
uint16_t ADC_GetInjectedConversionValue(ADC_Type* ADCx, uint8_t adcInjectedChannel);
int32_t ADC_GetIntFlag(ADC_Type* ADCx, uint8_t adcFlag);
void ADC_ClearFlag(ADC_Type* ADCx, uint8_t adcFlag);
void ADC_SetCallback(ADC_Type *ADCx, ADC_CallbackType funcCallback);
void ADC_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif
