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

#ifndef _AC78XX_UART_H_
#define _AC78XX_UART_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "ac78xx_uart_reg.h"
#define UART_NUM 6

typedef int32_t (*UART_Event_Callback)(uint8_t port, uint32_t lsr0, uint32_t lsr1);
int32_t UART_SetEventCallback(UART_Type *UARTx, UART_Event_Callback callback);

int32_t UART_Init(UART_Type *UARTx, UART_SettingType *uartSetting);
int32_t UART_Uninit(UART_Type *UARTx);
int32_t UART_SendData(UART_Type *UARTx, uint16_t data);
uint16_t UART_ReceiveData(UART_Type *UARTx);

UART_Type* UART_GetUARTCtrl(uint8_t uartIndex);
int32_t UART_StartDMAReceive(uint8_t uartIndex, uint8_t dataBits, uint32_t memStartAddr, uint32_t rxTransferNum, DMA_EventCallback callback);
int32_t UART_StartDMATransmit(uint8_t uartIndex, uint8_t dataBits, uint32_t memStartAddr, uint32_t txTransferNum, DMA_EventCallback callback);
uint32_t UART_GetDMAReceiveCount(uint8_t uartIndex);
int32_t UART_StopDAMReceive(uint8_t uartIndex);
int32_t UART_StopDMATransmit(uint8_t uartIndex);
void UART_SetBaudrate(UART_Type *UARTx, uint32_t baudrate, uint8_t sampleCounter);

#ifdef __cplusplus
}
#endif

#endif

