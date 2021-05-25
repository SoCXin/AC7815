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

#ifndef AC78xx_CTU_H_
#define AC78xx_CTU_H_
#ifdef __cplusplus
extern "C" {
#endif
#include "ac78xx_ctu_reg.h"
#include "ac78xx.h"

#define TRIG_ADC_USE_RTC_OVERFLOW               0x00
#define TRIG_ADC_USE_PWM0_INIT                  0x01
#define TRIG_ADC_USE_PWM2_INIT                  0x02
#define TRIG_ADC_USE_PWM2_MATCH                 0x03
#define TRIG_ADC_USE_TIMER_CHANNEL0_OVERFLOW    0x04
#define TRIG_ADC_USE_TIMER_CHANNEL1_OVERFLOW    0x05
#define TRIG_ADC_USE_ACMP0_OUTPUT               0x06
#define TRIG_ADC_USE_ACMP1_OUTPUT               0x07

typedef struct {
    uint32_t acmpTrig                   : 1;   ///<ACMP Trig PWN2 Selection
    uint32_t uartRxFilter               : 2;   ///< UART0 RxD Filter Select
    uint32_t rtcCapture                 : 1;   ///<Real-Time Counter Capture by PWM1 Channel1
    uint32_t acmpCapture                : 1;   ///<Analog Comparator to PWM1 Channel0 Input Capture
    uint32_t uartRxCapture              : 1;   ///<UART0 RX to PWM0 Channel1 capture
    uint32_t pwmSync                    : 1;   ///<PWM synchronization Select
    uint32_t uartTxModulate             : 1;   ///<Use PWM0 Channel0 to Modulate UART0 TX signal
    uint32_t clk                        : 3;   ///<BUS Clock Output Select
    uint32_t adcRegularHardwareTrig     : 3;   ///<ADC Hardware Trigger Source for Regular Group Select
    uint32_t delayAct                   : 1;   ///<Trigger Delay Active
    uint8_t  delayCnt                   : 8;   ///<Trigger Delay Cnt
    uint32_t acmpCaptureByPwdt          : 1;   ///<ACMP0_OUT or ACMP1_OUT connect to PWDT_IN3 Select
    uint32_t uartRxCaptureByPwdt        : 2;   ///<UART RX connect to PWDT_IN3 Select
    uint32_t adcInjectHardwareTrig	    : 3;   ///<ADC Hardware Trigger Source for Inject Group Select
} CTUConfig_Type;
void CTU_ModuleEnable(void);
void CTU_ModuleDisable(void);
int32_t CTU_Init(CTUConfig_Type *ctuConfig);
#ifdef __cplusplus
}
#endif
#endif /* CTU_H_ */
