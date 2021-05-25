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
 * @file main.c
 *
 * @author AutoChips
 *
 * @version 0.0.1
 *
 * @date Oct.31.2018
 *
 * @brief main implement
 *
 *******************************************************************************/
#include "ac78xx.h"
#include "ac78xx_debugout.h"
#include "ac78xx_gpio.h"
#include "ac78xx_uart.h"
#include "ac78xx_timer.h"
#include "stdio.h"

#define BUS_CLK                      48000000
#define Delay1us                    (BUS_CLK/1000000)
#define Delay1s                     (BUS_CLK-1)
#define Delay500ms                  (BUS_CLK/2 - 1)
#define Delay1ms                    (BUS_CLK/1000 - 1)
#define Delayus(n)                  ((BUS_CLK/1000000) * n - 1)  //n us
/* makesure n < 16 */
#define PAout(n) BIT_ADDR(GPIOA_ODR_ADDR, n)
#define PAin(n) BIT_ADDR(GPIOA_IDR_ADDR, n)

#define PBout(n) BIT_ADDR(GPIOB_ODR_ADDR, n)
#define PBin(n) BIT_ADDR(GPIOB_IDR_ADDR, n)

#define PCout(n) BIT_ADDR(GPIOC_ODR_ADDR, n)
#define PCin(n) BIT_ADDR(GPIOC_IDR_ADDR, n)

#define PDout(n) BIT_ADDR(GPIOD_ODR_ADDR, n)
#define PDin(n) BIT_ADDR(GPIOD_IDR_ADDR, n)

#define PEout(n) BIT_ADDR(GPIOE_ODR_ADDR, n)
#define PEin(n) BIT_ADDR(GPIOE_IDR_ADDR, n)

/* gpio bit-band control */
#define LED2 PBout(9)
#define LED3 PBout(10)

#define KEY6 PAin(11)
#define KEY7 PAin(12)

/* define key gpio */
#define PIN_K6 GPIO_PA11
#define PIN_K7 GPIO_PA12

/* define LED gpio */
#define PIN_LED2 GPIO_PB9
#define PIN_LED3 GPIO_PB10
uint32_t g_timerCnt = 0;

/**
 * TIMER1_Task
 *
 * @param[in] timerIndex 
 * @return  none
 *
 * @brief timer1 deal with ignition task
 */
void TIMER1_Task(uint8_t timerIndex)
{
    if (TIMER_GetIntFlag(TIMER1))
    {
        TIMER_ClrIntFlag(TIMER1);
        g_timerCnt ++;
    }
}
/**
 * LED_Init
 *
 * @param[in]  none
 * @return none
 *
 * @brief  init led control gpio
 *
 */
void LED_Init(void) {
  /* init gpio as output mode */
  GPIO_SetDir(PIN_LED2, 1);
  GPIO_SetDir(PIN_LED3, 1);
}

/**
 * KEY_Init
 *
 * @param[in]  none
 * @return none
 *
 * @brief  init key control gpio
 *
 */
void KEY_Init(void) {
  /* init gpio as input mode */
  GPIO_SetDir(PIN_K6, 0);
  GPIO_SetDir(PIN_K7, 0);
}
uint32_t g_useTime = 0;
float g_result = 0;
float Float_OperationEvaluate(void)
{
    float a,b,c,reslut;
    int i;
    a = 3.1415;
    b = 2.233;
    g_useTime = g_timerCnt;
    for(i = 0; i < 20000; i ++)
    {
        c = a + b;
        b = c - a;
        a = b * c;
        b = c / a;
        reslut += b;
    }
    g_useTime = g_timerCnt - g_useTime;
    return reslut;
}
int g_cnt = 0;

/**
 * Put_Timer1_CNT
 *
 * @param[in] value:time (1us * value), flag: disable:TIMER_CNT_DISABLE, enable:TIMER_CNT_EN
 * @return  none
 * note:timer0 and timer1 is 32bit, timer2-timer7 is 16bit.
 * @brief  set timer1 load value
 */
void Put_Timer1_CNT(uint32_t value, uint8_t flag)
{
    uint32_t time = value;
    TIMER_ConfigType  timerConfig = {0};
    timerConfig.loadValue      = Delayus(time);/// timeout
    timerConfig.interruptEn      = flag;
    timerConfig.linkMode        = 0;
    timerConfig.timerEn          = flag;
    TIMER_SetCallback(TIMER1, TIMER1_Task);
    TIMER_DeInit(TIMER1);
    TIMER_Init(TIMER1, &timerConfig);
}
/**
 * main
 *
 * @param[in]  none
 * @return none
 *
 * @brief  main function
 *
 */
int main(void) {
  static uint8_t s_key6Up = 1; /* key6 push/pop status   1:pop  0:push */
  static uint8_t s_key7Up = 1; /* key7 push/pop status   1:pop  0:push */

  InitDebug();
  KEY_Init(); /* init key gpio */
  LED_Init(); /* init led gpio */
  LED2 = 1;
  LED3 = 1;
  printf("\nAC7811: GPIO_Demo\n");
  Put_Timer1_CNT(1, 1);
  g_result = Float_OperationEvaluate();
  while (1) {
    if (s_key6Up && KEY6 == 0) {
      mdelay(10);
      if (s_key6Up && KEY6 == 0) {
        printf("\ntoggle LED2 s_key6Up:%d\n", s_key6Up);
        LED2 = !LED2; /* toggle LED2 output */
        if (s_key6Up == 1) {
          s_key6Up = 0;
        }
        g_cnt++;
      }
    } else {
      if (s_key6Up == 0 && KEY6 == 1) {
        s_key6Up = 1;
      }
    }

    if (s_key7Up && KEY7 == 0) {
      mdelay(10);
      if (s_key7Up && KEY7 == 0) {
        printf("\ntoggle LED3\n");
        LED3 = !LED3; /* toggle LED3 output */
        if (s_key7Up == 1) {
          s_key7Up = 0;
        }
      }
    } else {
      if (s_key7Up == 0 && KEY7 == 1) {
        s_key7Up = 1;
      }
    }
  }
}
