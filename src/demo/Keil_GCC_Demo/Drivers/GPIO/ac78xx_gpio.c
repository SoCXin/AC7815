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

#include "ac78xx_gpio.h"
#include "string.h"
#include "ac78xx.h"
#include "math.h"

static const GPIO_ConfigPMUXType s_gpioPinmuxTable[] =
{
    {PMUX0, 0},    //GPIO 0
    {PMUX0, 1},
    {PMUX0, 2},
    {PMUX0, 3},
    {PMUX0, 4},
    {PMUX0, 5},
    {PMUX0, 6},
    {PMUX0, 7},
    {PMUX0, 8},
    {PMUX0, 9},
    {PMUX1, 0},    //GPIO 10
    {PMUX1, 1},
    {PMUX1, 2},
    {PMUX1, 3},
    {PMUX1, 4},
    {PMUX1, 5},
    {PMUX1, 6},    //GPIO 16
    {PMUX1, 7},
    {PMUX1, 8},
    {PMUX1, 9},
    {PMUX2, 0},
    {PMUX2, 1},
    {PMUX2, 2},
    {PMUX2, 3},
    {PMUX2, 4},
    {PMUX2, 5},
    {PMUX2, 6},
    {PMUX2, 7},
    {PMUX2, 8},
    {PMUX2, 9},
    {PMUX3, 0},
    {PMUX3, 1},
    {PMUX3, 2},    //GPIO 32
    {PMUX3, 3},
    {PMUX3, 4},
    {PMUX3, 5},
    {PMUX3, 6},
    {PMUX3, 7},
    {PMUX3, 8},
    {PMUX3, 9},
    {PMUX4, 0},
    {PMUX4, 1},
    {PMUX4, 2},
    {PMUX4, 3},
    {PMUX4, 4},
    {PMUX4, 5},
    {PMUX4, 6},
    {PMUX4, 7},
    {PMUX4, 8},    //GPIO 48
    {PMUX4, 9},
    {PMUX5, 0},
    {PMUX5, 1},
    {PMUX5, 2},
    {PMUX5, 3},
    {PMUX5, 4},
    {PMUX5, 5},
    {PMUX5, 6},
    {PMUX5, 7},
    {PMUX5, 8},
    {PMUX5, 9},
    {PMUX6, 0},
    {PMUX6, 1},
    {PMUX6, 2},
    {PMUX6, 3},
    {PMUX6, 4},    //GPIO 64
    {PMUX6, 5},
    {PMUX6, 6},
    {PMUX6, 7},
    {PMUX6, 8},
    {PMUX6, 9},    //GPIO 69
};

int32_t GPIO_SetPinExtIntSource(uint32_t gpioNum);
int32_t GPIO_GetPinExtIntSource(uint32_t gpioNum);
int32_t GPIO_SetPinFallingEdgeEnable(uint32_t gpioNum, FunctionalState fallingEdgeEnable);
int32_t GPIO_SetPinRisingEdgeEnable(uint32_t gpioNum, FunctionalState risingEdgeEnable);
int32_t GPIO_SetPinExtIntMaskEnable(uint32_t gpioPinNum, FunctionalState intMaskEnable);

/**
 * EXTI0_IRQHandler
 *
 * @param[in]  none
 * @return     none
 *
 * @brief  override the EXTI0_IRQHandler
 */
void EXTI0_IRQHandler(void)
{
    uint32_t tmpGPIONum = GPIO_GetPendingExtIntGPIONum(0);

    GPIO_ClearPendingExtInt(tmpGPIONum);
}

/**
 * EXTI1_IRQHandler
 *
 * @param[in]  none
 * @return     none
 *
 * @brief  override the EXTI1_IRQHandler
 */
void EXTI1_IRQHandler(void)
{
    uint32_t tmpGPIONum = GPIO_GetPendingExtIntGPIONum(1);

    GPIO_ClearPendingExtInt(tmpGPIONum);
}

/**
 * EXTI2_IRQHandler
 *
 * @param[in]  none
 * @return     none
 *
 * @brief  override the EXTI2_IRQHandler
 */
void EXTI2_IRQHandler(void)
{
    uint32_t tmpGPIONum = GPIO_GetPendingExtIntGPIONum(2);

    GPIO_ClearPendingExtInt(tmpGPIONum);
}

/**
 * EXTI3_IRQHandler
 *
 * @param[in]  none
 * @return     none
 *
 * @brief  override the EXTI3_IRQHandler
 */
void EXTI3_IRQHandler(void)
{
    uint32_t tmpGPIONum = GPIO_GetPendingExtIntGPIONum(3);

    GPIO_ClearPendingExtInt(tmpGPIONum);
}

/**
 * EXTI4_IRQHandler
 *
 * @param[in]  none
 * @return     none
 *
 * @brief  override the EXTI4_IRQHandler
 */
void EXTI4_IRQHandler(void)
{
    uint32_t tmpGPIONum = GPIO_GetPendingExtIntGPIONum(4);

    GPIO_ClearPendingExtInt(tmpGPIONum);
}

/**
 * EXTI5_9_IRQHandler
 *
 * @param[in]  none
 * @return     none
 *
 * @brief  override the EXTI5_9_IRQHandler
 */
void EXTI5_9_IRQHandler(void)
{
    uint32_t tmpGPIOPendingIRQMask = GPIO_GetPendingIRQMask();
    uint32_t tmpGPIONum = 0, i = 0;

    for (i = 0x20; i < 0x400; i = i << 1)
    {
        if (tmpGPIOPendingIRQMask & i)
        {
            tmpGPIONum = GPIO_GetPendingExtIntGPIONum(log(i) / log(2));

            GPIO_ClearPendingExtInt(tmpGPIONum);
        }
    }
}

/**
 * EXTI10_15_IRQHandler
 *
 * @param[in]  none
 * @return     none
 *
 * @brief  override the EXTI10_15_IRQHandler
 */
void EXTI10_15_IRQHandler(void)
{
    uint32_t tmpGPIOPendingIRQMask = GPIO_GetPendingIRQMask();
    uint32_t tmpGPIONum = 0, i = 0;

    for (i = 0x400; i < 0x10000; i = i << 1)
    {
        if (tmpGPIOPendingIRQMask & i)
        {
            tmpGPIONum = GPIO_GetPendingExtIntGPIONum(log(i) / log(2));

            GPIO_ClearPendingExtInt(tmpGPIONum);
        }
    }
}

/**
* GPIO_SetFunc
*
* @param[in] gpioNum: GPIO number
* @param[in] functionx: GPIO function, refer to reference manual
* @return    0: success, -1: GPIO_PinNum is too large
*
* @brief  Set a GPIO pin's Pmux and pin function
*/
int32_t GPIO_SetFunc(uint32_t gpioNum, uint32_t functionx)
{
    GPIO_ConfigPMUXType tmpGPIOConfig = {0};

    tmpGPIOConfig = GPIO_GetPMUXConfig(gpioNum);
    PMUX_SetPMUXxPFSELx(tmpGPIOConfig.PMUXx, tmpGPIOConfig.PMUXx_PFSEL, functionx);

    return 0;
}

/**
* GPIO_SetDir
*
* @param[in] gpioNum: GPIO number
* @param[in] pinMode: 1:Output  0:Input
* @return    0: success, -1: GPIO_PinNum is too large
*
* @brief  Set a GPIO pin's pin mode
*/
int32_t GPIO_SetDir(uint32_t gpioNum, uint32_t pinMode)
{
    uint32_t tmpGPIOx = 0, tmpGPIOxPinNum = 0;

    tmpGPIOx = gpioNum / GPIO_ONE_GROUP_NUM;                  // Calculate GPIO Group(A~E)
    tmpGPIOxPinNum = gpioNum % GPIO_ONE_GROUP_NUM;            // Calculate GPIO Group's Internal Pin Number(0~15)

    switch (tmpGPIOx)
    {
    case 0:
        GPIO_SetGPIOxMODE(GPIOA, tmpGPIOxPinNum, pinMode);
        break;
    case 1:
        GPIO_SetGPIOxMODE(GPIOB, tmpGPIOxPinNum, pinMode);
        break;
    case 2:
        GPIO_SetGPIOxMODE(GPIOC, tmpGPIOxPinNum, pinMode);
        break;
    case 3:
        GPIO_SetGPIOxMODE(GPIOD, tmpGPIOxPinNum, pinMode);
        break;
    case 4:
        GPIO_SetGPIOxMODE(GPIOE, tmpGPIOxPinNum, pinMode);
        break;

    default:
        return -1;
    }

    return 0;
}

/**
* GPIO_SetPinValue
*
* @param[in] gpioNum: GPIO number
* @param[in] pinValue: GPIO Pin output value
* @return    0: success, -1: GPIO_PinNum is too large
*
* @brief  Set GPIO pin output value
*/
int32_t GPIO_SetPinValue(uint32_t gpioNum, uint32_t pinValue)
{
    uint32_t tmpGPIOx = 0, tmpGPIOxPinNum = 0;

    tmpGPIOx = gpioNum / GPIO_ONE_GROUP_NUM;                  // Calculate GPIO Group(A~E)
    tmpGPIOxPinNum = gpioNum % GPIO_ONE_GROUP_NUM;           // Calculate GPIO Group's Internal Pin Number(0~15)

    switch (tmpGPIOx)
    {
    case 0:
        GPIO_SetGPIOxODRx(GPIOA, tmpGPIOxPinNum, pinValue);
        break;
    case 1:
        GPIO_SetGPIOxODRx(GPIOB, tmpGPIOxPinNum, pinValue);
        break;
    case 2:
        GPIO_SetGPIOxODRx(GPIOC, tmpGPIOxPinNum, pinValue);
        break;
    case 3:
        GPIO_SetGPIOxODRx(GPIOD, tmpGPIOxPinNum, pinValue);
        break;
    case 4:
        GPIO_SetGPIOxODRx(GPIOE, tmpGPIOxPinNum, pinValue);
        break;

    default:
        return -1;
    }

    return 0;
}


/**
* GPIO_SetPinBits
*
* @param[in] gpioNum: GPIO number
* @return    0: success, -1: GPIO_PinNum is too large
*
* @brief  Set Select GPIO pin
*/
int32_t GPIO_SetPinBits(uint32_t gpioNum)
{
    uint32_t tmpGPIOx = 0, tmpGPIOxPinNum = 0;

    tmpGPIOx = gpioNum / GPIO_ONE_GROUP_NUM;                  // Calculate GPIO Group(A~E)
    tmpGPIOxPinNum = gpioNum % GPIO_ONE_GROUP_NUM;           // Calculate GPIO Group's Internal Pin Number(0~15)

    switch (tmpGPIOx)
    {
    case 0:
        GPIO_SetGPIOxBSRRx(GPIOA, tmpGPIOxPinNum);
        break;
    case 1:
        GPIO_SetGPIOxBSRRx(GPIOB, tmpGPIOxPinNum);
        break;
    case 2:
        GPIO_SetGPIOxBSRRx(GPIOC, tmpGPIOxPinNum);
        break;
    case 3:
        GPIO_SetGPIOxBSRRx(GPIOD, tmpGPIOxPinNum);
        break;
    case 4:
        GPIO_SetGPIOxBSRRx(GPIOE, tmpGPIOxPinNum);
        break;

    default:
        return -1;
    }

    return 0;
}


/**
* GPIO_ResetPinBits
*
* @param[in] gpioNum: GPIO number
* @return    0: success, -1: GPIO_PinNum is too large
*
* @brief  Set Select GPIO pin
*/
int32_t GPIO_ResetPinBits(uint32_t gpioNum)
{
    uint32_t tmpGPIOx = 0, tmpGPIOxPinNum = 0;

    tmpGPIOx = gpioNum / GPIO_ONE_GROUP_NUM;                  // Calculate GPIO Group(A~E)
    tmpGPIOxPinNum = gpioNum % GPIO_ONE_GROUP_NUM;           // Calculate GPIO Group's Internal Pin Number(0~15)

    switch (tmpGPIOx)
    {
    case 0:
        GPIO_SetGPIOxBRRx(GPIOA, tmpGPIOxPinNum);
        break;
    case 1:
        GPIO_SetGPIOxBRRx(GPIOB, tmpGPIOxPinNum);
        break;
    case 2:
        GPIO_SetGPIOxBRRx(GPIOC, tmpGPIOxPinNum);
        break;
    case 3:
        GPIO_SetGPIOxBRRx(GPIOD, tmpGPIOxPinNum);
        break;
    case 4:
        GPIO_SetGPIOxBRRx(GPIOE, tmpGPIOxPinNum);
        break;

    default:
        return -1;
    }

    return 0;
}



/**
* GPIO_GetPinValue
*
* @param[in] gpioNum: GPIO number
* @return    GPIO Pin input value; -1:  GPIO_PinNum is too large
*
* @brief  Get GPIO pin input value
*/
int32_t GPIO_GetPinValue(uint32_t gpioNum)
{
    uint32_t tmpGPIOx = 0, tmpGPIOxPinNum = 0, tmpGPIOPinValue = 0;

    tmpGPIOx = gpioNum / GPIO_ONE_GROUP_NUM;                  // Calculate GPIO Group(A~E)
    tmpGPIOxPinNum = gpioNum % GPIO_ONE_GROUP_NUM;            // Calculate GPIO Group's Internal Pin Number(0~15)

    switch (tmpGPIOx)
    {
    case 0:
        tmpGPIOPinValue = GPIO_GetGPIOxIDR(GPIOA);
        break;
    case 1:
        tmpGPIOPinValue = GPIO_GetGPIOxIDR(GPIOB);
        break;
    case 2:
        tmpGPIOPinValue = GPIO_GetGPIOxIDR(GPIOC);
        break;
    case 3:
        tmpGPIOPinValue = GPIO_GetGPIOxIDR(GPIOD);
        break;
    case 4:
        tmpGPIOPinValue = GPIO_GetGPIOxIDR(GPIOE);
        break;

    default:
        return -1;
    }

    return ((tmpGPIOPinValue >> tmpGPIOxPinNum) & 0x1);
}

/**
* GPIO_GetPMUXConfig
*
* @param[in]  gpioNum: GPIO number
* @return     GPIO ConfigType struct
*
* @brief  Get GPIO Pmux information and return it in GPIO ConfigType struct
*/
GPIO_ConfigPMUXType GPIO_GetPMUXConfig(uint32_t gpioNum)
{
    return s_gpioPinmuxTable[gpioNum];
}

/**
* GPIO_SetFuncGroup
*
* @param[in]  GPIOx: GPIO type structure pointer
* @param[in]  pinMask: GPIO pin mask
* @param[in]  functionx: GPIO group function
* @return     0: success
*
* @brief  Set several GPIO pins' Pmux and pin function
*/
int32_t GPIO_SetFuncGroup(GPIO_Type *GPIOx, uint32_t pinMask, uint32_t functionx)
{
    uint32_t pinPos = 0x00, pos = 0x00;
    uint32_t pinNumBase = (((uint32_t)GPIOx - (uint32_t)GPIOA) / 0x30) * GPIO_ONE_GROUP_NUM, tmpPinNum = 0x00;
    GPIO_ConfigPMUXType tmpConfig = {0};

    if ((pinMask & 0xFFFF) > 0)
    {
        for (pinPos = 0x00; pinPos < 0x10; pinPos++)
        {
            pos = ((uint32_t)0x01) << pinPos;
            if (pinMask & pos)
            {
                tmpPinNum = pinNumBase + pinPos;
                tmpConfig = GPIO_GetPMUXConfig(tmpPinNum);
                PMUX_SetPMUXxPFSELx(tmpConfig.PMUXx, tmpConfig.PMUXx_PFSEL, functionx);
            }
        }
    }

    return 0;
}

/**
* GPIO_SetDirGroup
*
* @param[in]    GPIOx: GPIO type structure pointer
* @param[in]  pinMask: GPIO pin mask
* @param[in]  pinMode: GPIO group pin mode, direction
* @return     0: success
*
* @brief  Set several GPIO pins' pin mode
*/
int32_t GPIO_SetDirGroup(GPIO_Type *GPIOx, uint32_t pinMask, uint32_t pinMode)
{
    uint32_t currentMode = pinMode, pinPos = 0x00, pos = 0x00;
    uint32_t tmpReg = 0x00;

    if ((pinMask & 0xFFFF) > 0)
    {
        tmpReg = GPIOx->GPIO_CR.GPIO_CR_Byte;
        for (pinPos = 0x00; pinPos < 0x10; pinPos++)
        {
            pos = ((uint32_t)0x01) << pinPos;
            if (pinMask & pos)
            {
                tmpReg &= ~pos;
                /* Write the mode configuration in the corresponding bits */
                tmpReg |= (currentMode << pinPos);
            }
        }
        GPIOx->GPIO_CR.GPIO_CR_Byte = tmpReg;
    }

    return 0;
}

/**
* GPIO_GetPinFunc
*
* @param[in]  gpioNum: GPIO number
* @return     0: GPIO pin Pmux function
*
* @brief  Get a GPIO pin's Pmux function
*/
int32_t GPIO_GetPinFunc(uint32_t gpioNum)
{
    GPIO_ConfigPMUXType tmpGPIOConfig = {0};

    tmpGPIOConfig = GPIO_GetPMUXConfig(gpioNum);

    switch (tmpGPIOConfig.PMUXx_PFSEL)
    {
    case 0:
        return tmpGPIOConfig.PMUXx->PMUX_FS.PMUX_FS_Bit.PFSEL0;
    case 1:
        return tmpGPIOConfig.PMUXx->PMUX_FS.PMUX_FS_Bit.PFSEL1;
    case 2:
        return tmpGPIOConfig.PMUXx->PMUX_FS.PMUX_FS_Bit.PFSEL2;
    case 3:
        return tmpGPIOConfig.PMUXx->PMUX_FS.PMUX_FS_Bit.PFSEL3;
    case 4:
        return tmpGPIOConfig.PMUXx->PMUX_FS.PMUX_FS_Bit.PFSEL4;
    case 5:
        return tmpGPIOConfig.PMUXx->PMUX_FS.PMUX_FS_Bit.PFSEL5;
    case 6:
        return tmpGPIOConfig.PMUXx->PMUX_FS.PMUX_FS_Bit.PFSEL6;
    case 7:
        return tmpGPIOConfig.PMUXx->PMUX_FS.PMUX_FS_Bit.PFSEL7;
    case 8:
        return tmpGPIOConfig.PMUXx->PMUX_FS.PMUX_FS_Bit.PFSEL8;
    case 9:
        return tmpGPIOConfig.PMUXx->PMUX_FS.PMUX_FS_Bit.PFSEL9;

    default:
        return -1;
    }
}

/**
* GPIO_GetPinMode
*
* @param[in]  gpioNum: GPIO number
* @return     0: GPIO pin mode
*
* @brief  Get a GPIO pin's pin mode
*/
int32_t GPIO_GetPinMode(uint32_t gpioNum)
{
    uint32_t tmpGPIOx = 0u, tmpGPIOxPinNum = 0u;
    GPIO_Type *GPIOx = GPIOA;

    tmpGPIOx = gpioNum / GPIO_ONE_GROUP_NUM;                  // Calculate GPIO Group(A~E)
    tmpGPIOxPinNum = gpioNum % GPIO_ONE_GROUP_NUM;           // Calculate GPIO Group's Internal Pin Number(0~15)

    switch (tmpGPIOx)
    {
    case 0:
        GPIOx = GPIOA;
        break;
    case 1:
        GPIOx = GPIOB;
        break;
    case 2:
        GPIOx = GPIOC;
        break;
    case 3:
        GPIOx = GPIOD;
        break;
    case 4:
        GPIOx = GPIOE;
        break;

    default:
        return -1;
    }


    switch (tmpGPIOxPinNum)
    {
    case 0:
        return GPIOx->GPIO_CR.GPIO_CR_Bit.MODE0;
    case 1:
        return GPIOx->GPIO_CR.GPIO_CR_Bit.MODE1;
    case 2:
        return GPIOx->GPIO_CR.GPIO_CR_Bit.MODE2;
    case 3:
        return GPIOx->GPIO_CR.GPIO_CR_Bit.MODE3;
    case 4:
        return GPIOx->GPIO_CR.GPIO_CR_Bit.MODE4;
    case 5:
        return GPIOx->GPIO_CR.GPIO_CR_Bit.MODE5;
    case 6:
        return GPIOx->GPIO_CR.GPIO_CR_Bit.MODE6;
    case 7:
        return GPIOx->GPIO_CR.GPIO_CR_Bit.MODE7;
    case 8:
        return GPIOx->GPIO_CR.GPIO_CR_Bit.MODE8;
    case 9:
        return GPIOx->GPIO_CR.GPIO_CR_Bit.MODE9;
    case 10:
        return GPIOx->GPIO_CR.GPIO_CR_Bit.MODE10;
    case 11:
        return GPIOx->GPIO_CR.GPIO_CR_Bit.MODE11;
    case 12:
        return GPIOx->GPIO_CR.GPIO_CR_Bit.MODE12;
    case 13:
        return GPIOx->GPIO_CR.GPIO_CR_Bit.MODE13;
    case 14:
        return GPIOx->GPIO_CR.GPIO_CR_Bit.MODE14;
    case 15:
        return GPIOx->GPIO_CR.GPIO_CR_Bit.MODE15;

    default:
        return -1;
    }
}


/**
* GPIO_EnableGPIOExtInt
*
* @param[in]  gpioNum: GPIO number
* @param[in]  risingFallingEdge: GPIO's external interrupt is 0: falling edge; 1: rising edge; 2: both edge sensitive
* @return  0: GPIO external interrupt configuration success; -1: fail
*
* @brief  Enable a GPIO pin's external interrupt and trigger condition
*/
int32_t GPIO_EnableGPIOExtInt(uint32_t gpioNum, EXTITrigger_TypeDef risingFallingEdge)
{
    uint32_t tmpGPIOGroupInternalNum = 0u;

    if (gpioNum > MAX_PIN_NUM || risingFallingEdge > EXTI_Trigger_Rising_Falling)
    {
        return -1;
    }

    GPIO_SetPinExtIntSource(gpioNum);
    if (risingFallingEdge == EXTI_Trigger_Falling)
    {
        GPIO_SetPinFallingEdgeEnable(gpioNum, ENABLE);
    }
    else if (risingFallingEdge == EXTI_Trigger_Rising)
    {
        GPIO_SetPinRisingEdgeEnable(gpioNum, ENABLE);
    }
    else if (risingFallingEdge == EXTI_Trigger_Rising_Falling)
    {
        GPIO_SetPinFallingEdgeEnable(gpioNum, ENABLE);
        GPIO_SetPinRisingEdgeEnable(gpioNum, ENABLE);
    }
    else
    {

    }

    tmpGPIOGroupInternalNum = gpioNum % GPIO_ONE_GROUP_NUM;           /* Calculate GPIO Group's Internal Pin Number(0~15) */
    /* Enable GPIO external interrupt */
    if (tmpGPIOGroupInternalNum > 9u)
    {
        NVIC_EnableIRQ(EXTI10_15_IRQn);
    }
    else if (tmpGPIOGroupInternalNum > 4u)
    {
        NVIC_EnableIRQ(EXTI5_9_IRQn);
    }
    else
    {
        switch (tmpGPIOGroupInternalNum)
        {
        case 0:
            NVIC_EnableIRQ(EXTI0_IRQn);
            break;
        case 1:
            NVIC_EnableIRQ(EXTI1_IRQn);
            break;
        case 2:
            NVIC_EnableIRQ(EXTI2_IRQn);
            break;
        case 3:
            NVIC_EnableIRQ(EXTI3_IRQn);
            break;
        case 4:
            NVIC_EnableIRQ(EXTI4_IRQn);
            break;

        default :
            break;
        }
    }
    GPIO_SetPinExtIntMaskEnable(gpioNum, ENABLE);

    return 0;
}

/**
* GPIO_DisableGPIOExtInt
*
* @param[in]  gpioNum: GPIO number
* @return  0: GPIO external interrupt configuration success; -1: fail
*
* @brief  Disable a GPIO pin's external interrupt and trigger condition
*/
int32_t GPIO_DisableGPIOExtInt(uint32_t gpioNum)
{
    uint32_t tmpGPIOGroupInternalNum = 0;

    if (gpioNum > MAX_PIN_NUM)
    {
        return -1;
    }

    GPIO_SetPinFallingEdgeEnable(gpioNum, DISABLE);
    GPIO_SetPinRisingEdgeEnable(gpioNum, DISABLE);

    tmpGPIOGroupInternalNum = gpioNum % GPIO_ONE_GROUP_NUM;           /* Calculate GPIO Group's Internal Pin Number(0~15) */
    /* Enable GPIO external interrupt */
    if (tmpGPIOGroupInternalNum > 9u)
    {
        NVIC_DisableIRQ(EXTI10_15_IRQn);
    }
    else if (tmpGPIOGroupInternalNum > 4u)
    {
        NVIC_DisableIRQ(EXTI5_9_IRQn);
    }
    else
    {
        switch (tmpGPIOGroupInternalNum)
        {
        case 0:
            NVIC_DisableIRQ(EXTI0_IRQn);
            break;
        case 1:
            NVIC_DisableIRQ(EXTI1_IRQn);
            break;
        case 2:
            NVIC_DisableIRQ(EXTI2_IRQn);
            break;
        case 3:
            NVIC_DisableIRQ(EXTI3_IRQn);
            break;
        case 4:
            NVIC_DisableIRQ(EXTI4_IRQn);
            break;

        default :
            break;
        }
    }
    GPIO_SetPinExtIntMaskEnable(gpioNum, DISABLE);

    return 0;
}
/**
* GPIO_SetPinExtIntSource
*
* @param[in]  gpioNum: GPIO number
* @return     0: GPIO external interrupt configuration success; -1: fail
*
* @brief  Set a GPIO pin's external interrupt
*/
int32_t GPIO_SetPinExtIntSource(uint32_t gpioNum)
{
    uint32_t tmpGPIOx = 0, tmpGPIOxPinNum = 0;
    uint32_t tmpExtValue = 0;

    tmpGPIOx = gpioNum  / GPIO_ONE_GROUP_NUM;                  // Calculate GPIO Group(A~E)
    tmpGPIOxPinNum = gpioNum % GPIO_ONE_GROUP_NUM;           // Calculate GPIO Group's Internal Pin Number(0~15)
    tmpExtValue = tmpGPIOx;

    switch (tmpGPIOxPinNum)
    {
    case 0:
        GPIOINT->GPIO_EXTICR0.Bit.EXTIC0 = tmpExtValue;
        break;
    case 1:
        GPIOINT->GPIO_EXTICR0.Bit.EXTIC1 = tmpExtValue;
        break;
    case 2:
        GPIOINT->GPIO_EXTICR0.Bit.EXTIC2 = tmpExtValue;
        break;
    case 3:
        GPIOINT->GPIO_EXTICR0.Bit.EXTIC3 = tmpExtValue;
        break;
    case 4:
        GPIOINT->GPIO_EXTICR1.Bit.EXTIC4 = tmpExtValue;
        break;
    case 5:
        GPIOINT->GPIO_EXTICR1.Bit.EXTIC5 = tmpExtValue;
        break;
    case 6:
        GPIOINT->GPIO_EXTICR1.Bit.EXTIC6 = tmpExtValue;
        break;
    case 7:
        GPIOINT->GPIO_EXTICR1.Bit.EXTIC7 = tmpExtValue;
        break;
    case 8:
        GPIOINT->GPIO_EXTICR2.Bit.EXTIC8 = tmpExtValue;
        break;
    case 9:
        GPIOINT->GPIO_EXTICR2.Bit.EXTIC9 = tmpExtValue;
        break;
    case 10:
        GPIOINT->GPIO_EXTICR2.Bit.EXTIC10 = tmpExtValue;
        break;
    case 11:
        GPIOINT->GPIO_EXTICR2.Bit.EXTIC11 = tmpExtValue;
        break;
    case 12:
        GPIOINT->GPIO_EXTICR3.Bit.EXTIC12 = tmpExtValue;
        break;
    case 13:
        GPIOINT->GPIO_EXTICR3.Bit.EXTIC13 = tmpExtValue;
        break;
    case 14:
        GPIOINT->GPIO_EXTICR3.Bit.EXTIC14 = tmpExtValue;
        break;
    case 15:
        GPIOINT->GPIO_EXTICR3.Bit.EXTIC15 = tmpExtValue;
        break;

    default:
        return -1;
    }
    return 0;
}

/**
* GPIO_GetPinExtIntSource
*
* @param[in]  gpioNum: GPIO number
* @return     0: GPIO external interrupt configuration success; -1: fail
*
* @brief  Get a GPIO pin's external interrupt configuration value
*/
int32_t GPIO_GetPinExtIntSource(uint32_t gpioNum)
{
    uint32_t tmpGPIOxPinNum = 0;

    tmpGPIOxPinNum = gpioNum % GPIO_ONE_GROUP_NUM;           // Calculate GPIO Group's Internal Pin Number(0~15)

    switch (tmpGPIOxPinNum)
    {
    case 0:
        return GPIOINT->GPIO_EXTICR0.Bit.EXTIC0;
    case 1:
        return GPIOINT->GPIO_EXTICR0.Bit.EXTIC1;
    case 2:
        return GPIOINT->GPIO_EXTICR0.Bit.EXTIC2;
    case 3:
        return GPIOINT->GPIO_EXTICR0.Bit.EXTIC3;
    case 4:
        return GPIOINT->GPIO_EXTICR1.Bit.EXTIC4;
    case 5:
        return GPIOINT->GPIO_EXTICR1.Bit.EXTIC5;
    case 6:
        return GPIOINT->GPIO_EXTICR1.Bit.EXTIC6;
    case 7:
        return GPIOINT->GPIO_EXTICR1.Bit.EXTIC7;
    case 8:
        return GPIOINT->GPIO_EXTICR2.Bit.EXTIC8;
    case 9:
        return GPIOINT->GPIO_EXTICR2.Bit.EXTIC9;
    case 10:
        return GPIOINT->GPIO_EXTICR2.Bit.EXTIC10;
    case 11:
        return GPIOINT->GPIO_EXTICR2.Bit.EXTIC11;
    case 12:
        return GPIOINT->GPIO_EXTICR3.Bit.EXTIC12;
    case 13:
        return GPIOINT->GPIO_EXTICR3.Bit.EXTIC13;
    case 14:
        return GPIOINT->GPIO_EXTICR3.Bit.EXTIC14;
    case 15:
        return GPIOINT->GPIO_EXTICR3.Bit.EXTIC15;

    default:
        return -1;
    }
}

/**
* GPIO_SetPinFallingEdgeEnable
*
* @param[in]  gpioNum: GPIO number
* @param[in]  fallingEdgeEnable: GPIO pin falling edge: 0: disable; 1: enable
* @return     0: GPIO external interrupt falling edge sensitive configuration success; -1: fail
*
* @brief  Set a GPIO pin's external interrupt falling edge sensitive
*/
int32_t GPIO_SetPinFallingEdgeEnable(uint32_t gpioNum, FunctionalState fallingEdgeEnable)
{
    uint32_t tmpGPIOxPinNum = 0;
    uint32_t tmpFallEdgeValue = 0;

    tmpGPIOxPinNum = gpioNum % GPIO_ONE_GROUP_NUM;           // Calculate GPIO Group's Internal Pin Number(0~15)
    tmpFallEdgeValue = fallingEdgeEnable;

    switch (tmpGPIOxPinNum)
    {
    case 0:
        GPIOINT->GPIO_FECR.Bit.FEC0 = tmpFallEdgeValue;
        break;
    case 1:
        GPIOINT->GPIO_FECR.Bit.FEC1 = tmpFallEdgeValue;
        break;
    case 2:
        GPIOINT->GPIO_FECR.Bit.FEC2 = tmpFallEdgeValue;
        break;
    case 3:
        GPIOINT->GPIO_FECR.Bit.FEC3 = tmpFallEdgeValue;
        break;
    case 4:
        GPIOINT->GPIO_FECR.Bit.FEC4 = tmpFallEdgeValue;
        break;
    case 5:
        GPIOINT->GPIO_FECR.Bit.FEC5 = tmpFallEdgeValue;
        break;
    case 6:
        GPIOINT->GPIO_FECR.Bit.FEC6 = tmpFallEdgeValue;
        break;
    case 7:
        GPIOINT->GPIO_FECR.Bit.FEC7 = tmpFallEdgeValue;
        break;
    case 8:
        GPIOINT->GPIO_FECR.Bit.FEC8 = tmpFallEdgeValue;
        break;
    case 9:
        GPIOINT->GPIO_FECR.Bit.FEC9 = tmpFallEdgeValue;
        break;
    case 10:
        GPIOINT->GPIO_FECR.Bit.FEC10 = tmpFallEdgeValue;
        break;
    case 11:
        GPIOINT->GPIO_FECR.Bit.FEC11 = tmpFallEdgeValue;
        break;
    case 12:
        GPIOINT->GPIO_FECR.Bit.FEC12 = tmpFallEdgeValue;
        break;
    case 13:
        GPIOINT->GPIO_FECR.Bit.FEC13 = tmpFallEdgeValue;
        break;
    case 14:
        GPIOINT->GPIO_FECR.Bit.FEC14 = tmpFallEdgeValue;
        break;
    case 15:
        GPIOINT->GPIO_FECR.Bit.FEC15 = tmpFallEdgeValue;
        break;

    default:
        return -1;
    }
    return 0;

}

/**
* GPIO_SetPinRisingEdgeEnable
*
* @param[in]  gpioNum: GPIO number
* @param[in]  risingEdgeEnable: GPIO pin falling edge: 0: disable; 1: enable
* @return     0: GPIO external interrupt rising edge sensitive configuration success; -1: fail
*
* @brief  Set a GPIO pin's external interrupt rising edge sensitive
*/
int32_t GPIO_SetPinRisingEdgeEnable(uint32_t gpioNum, FunctionalState risingEdgeEnable)
{
    uint32_t tmpGPIOxPinNum = 0;
    uint32_t tmpRisingEdgeValue = 0;

    tmpGPIOxPinNum = gpioNum % GPIO_ONE_GROUP_NUM;           // Calculate GPIO Group's Internal Pin Number(0~15)
    tmpRisingEdgeValue = risingEdgeEnable;

    switch (tmpGPIOxPinNum)
    {
    case 0:
        GPIOINT->GPIO_RECR.Bit.REC0 = tmpRisingEdgeValue;
        break;
    case 1:
        GPIOINT->GPIO_RECR.Bit.REC1 = tmpRisingEdgeValue;
        break;
    case 2:
        GPIOINT->GPIO_RECR.Bit.REC2 = tmpRisingEdgeValue;
        break;
    case 3:
        GPIOINT->GPIO_RECR.Bit.REC3 = tmpRisingEdgeValue;
        break;
    case 4:
        GPIOINT->GPIO_RECR.Bit.REC4 = tmpRisingEdgeValue;
        break;
    case 5:
        GPIOINT->GPIO_RECR.Bit.REC5 = tmpRisingEdgeValue;
        break;
    case 6:
        GPIOINT->GPIO_RECR.Bit.REC6 = tmpRisingEdgeValue;
        break;
    case 7:
        GPIOINT->GPIO_RECR.Bit.REC7 = tmpRisingEdgeValue;
        break;
    case 8:
        GPIOINT->GPIO_RECR.Bit.REC8 = tmpRisingEdgeValue;
        break;
    case 9:
        GPIOINT->GPIO_RECR.Bit.REC9 = tmpRisingEdgeValue;
        break;
    case 10:
        GPIOINT->GPIO_RECR.Bit.REC10 = tmpRisingEdgeValue;
        break;
    case 11:
        GPIOINT->GPIO_RECR.Bit.REC11 = tmpRisingEdgeValue;
        break;
    case 12:
        GPIOINT->GPIO_RECR.Bit.REC12 = tmpRisingEdgeValue;
        break;
    case 13:
        GPIOINT->GPIO_RECR.Bit.REC13 = tmpRisingEdgeValue;
        break;
    case 14:
        GPIOINT->GPIO_RECR.Bit.REC14 = tmpRisingEdgeValue;
        break;
    case 15:
        GPIOINT->GPIO_RECR.Bit.REC15 = tmpRisingEdgeValue;
        break;

    default:
        return -1;
    }
    return 0;

}

/**
* GPIO_GetPendingIRQMask
*
* @param[in]  none
* @return     GPIO's Pending external interrupt IRQ number
*
* @brief  Get a GPIO pin's pending external interrupt IRQ number, a 16bit mask which represents the GPIO's group internal position
*/
uint32_t GPIO_GetPendingIRQMask(void)
{
    return GPIOINT->GPIO_IFPR.Byte;
}

/**
* GPIO_GetPendingExtIntGPIONum
*
* @param[in]  pendingIRQNum: External Interrupt Flag, which is the GPIO's group internal position, in range [0:15]
* @return     GPIO Number, which is the source of pending external interrupt
*
* @brief  Get a GPIO Num, which is the source of an external interrupt pending
*/
uint32_t GPIO_GetPendingExtIntGPIONum(uint32_t pendingIRQNum)
{
    uint32_t tmpGPIOxGroupInternalNum = pendingIRQNum;
    uint32_t tmpGPIOGroup = 0, tmpGPIONum = 0;

    switch (tmpGPIOxGroupInternalNum)
    {
    case 0:
        tmpGPIOGroup = GPIOINT->GPIO_EXTICR0.Bit.EXTIC0;
        break;
    case 1:
        tmpGPIOGroup = GPIOINT->GPIO_EXTICR0.Bit.EXTIC1;
        break;
    case 2:
        tmpGPIOGroup = GPIOINT->GPIO_EXTICR0.Bit.EXTIC2;
        break;
    case 3:
        tmpGPIOGroup = GPIOINT->GPIO_EXTICR0.Bit.EXTIC3;
        break;
    case 4:
        tmpGPIOGroup = GPIOINT->GPIO_EXTICR1.Bit.EXTIC4;
        break;
    case 5:
        tmpGPIOGroup = GPIOINT->GPIO_EXTICR1.Bit.EXTIC5;
        break;
    case 6:
        tmpGPIOGroup = GPIOINT->GPIO_EXTICR1.Bit.EXTIC6;
        break;
    case 7:
        tmpGPIOGroup = GPIOINT->GPIO_EXTICR1.Bit.EXTIC7;
        break;
    case 8:
        tmpGPIOGroup = GPIOINT->GPIO_EXTICR2.Bit.EXTIC8;
        break;
    case 9:
        tmpGPIOGroup = GPIOINT->GPIO_EXTICR2.Bit.EXTIC9;
        break;
    case 10:
        tmpGPIOGroup = GPIOINT->GPIO_EXTICR2.Bit.EXTIC10;
        break;
    case 11:
        tmpGPIOGroup = GPIOINT->GPIO_EXTICR2.Bit.EXTIC11;
        break;
    case 12:
        tmpGPIOGroup = GPIOINT->GPIO_EXTICR3.Bit.EXTIC12;
        break;
    case 13:
        tmpGPIOGroup = GPIOINT->GPIO_EXTICR3.Bit.EXTIC13;
        break;
    case 14:
        tmpGPIOGroup = GPIOINT->GPIO_EXTICR3.Bit.EXTIC14;
        break;
    case 15:
        tmpGPIOGroup = GPIOINT->GPIO_EXTICR3.Bit.EXTIC15;
        break;

    default:
        return 0xFFFF;
    }
    tmpGPIONum = (tmpGPIOGroup * GPIO_ONE_GROUP_NUM) + tmpGPIOxGroupInternalNum;

    return tmpGPIONum;
}

/**
* GPIO_ClearPendingExtInt
*
* @param[in]  gpioNum: GPIO number
* @return     0: clear GPIO external interrupt pending flag success; -1: fail
*
* @brief  Clear a GPIO pin's external interrupt pending flag
*/
int32_t GPIO_ClearPendingExtInt(uint32_t gpioNum)
{
    uint32_t tmpGPIOxPinNum = 0;

    tmpGPIOxPinNum = gpioNum % GPIO_ONE_GROUP_NUM;           // Calculate GPIO Group's Internal Pin Number(0~15)

    switch (tmpGPIOxPinNum)
    {
    case 0:
        GPIOINT->GPIO_IFPR.Bit.IFP0 = 1u;
        break;
    case 1:
        GPIOINT->GPIO_IFPR.Bit.IFP1 = 1u;
        break;
    case 2:
        GPIOINT->GPIO_IFPR.Bit.IFP2 = 1u;
        break;
    case 3:
        GPIOINT->GPIO_IFPR.Bit.IFP3 = 1u;
        break;
    case 4:
        GPIOINT->GPIO_IFPR.Bit.IFP4 = 1u;
        break;
    case 5:
        GPIOINT->GPIO_IFPR.Bit.IFP5 = 1u;
        break;
    case 6:
        GPIOINT->GPIO_IFPR.Bit.IFP6 = 1u;
        break;
    case 7:
        GPIOINT->GPIO_IFPR.Bit.IFP7 = 1u;
        break;
    case 8:
        GPIOINT->GPIO_IFPR.Bit.IFP8 = 1u;
        break;
    case 9:
        GPIOINT->GPIO_IFPR.Bit.IFP9 = 1u;
        break;
    case 10:
        GPIOINT->GPIO_IFPR.Bit.IFP10 = 1u;
        break;
    case 11:
        GPIOINT->GPIO_IFPR.Bit.IFP11 = 1u;
        break;
    case 12:
        GPIOINT->GPIO_IFPR.Bit.IFP12 = 1u;
        break;
    case 13:
        GPIOINT->GPIO_IFPR.Bit.IFP13 = 1u;
        break;
    case 14:
        GPIOINT->GPIO_IFPR.Bit.IFP14 = 1u;
        break;
    case 15:
        GPIOINT->GPIO_IFPR.Bit.IFP15 = 1u;
        break;

    default:
        return -1;
    }

    return 0;
}

/**
* GPIO_SetPinExtIntMaskEnable
*
* @param[in]  gpioNum: GPIO number
* @param[in]  intMaskEnable: GPIO pin external interrupt mask: 0: disable; 1: enable
* @return     0: GPIO external interrupt mask configuration success; -1: fail
*
* @brief  Set a GPIO pin's external interrupt mask
*/
int32_t GPIO_SetPinExtIntMaskEnable(uint32_t gpioNum, FunctionalState intMaskEnable)
{
    uint32_t tmpGPIOxPinNum = 0;

    tmpGPIOxPinNum = gpioNum % GPIO_ONE_GROUP_NUM;           // Calculate GPIO Group's Internal Pin Number(0~15)

    switch (tmpGPIOxPinNum)
    {
    case 0:
        GPIOINT->GPIO_IMR.Bit.IM0 = intMaskEnable;
        break;
    case 1:
        GPIOINT->GPIO_IMR.Bit.IM1 = intMaskEnable;
        break;
    case 2:
        GPIOINT->GPIO_IMR.Bit.IM2 = intMaskEnable;
        break;
    case 3:
        GPIOINT->GPIO_IMR.Bit.IM3 = intMaskEnable;
        break;
    case 4:
        GPIOINT->GPIO_IMR.Bit.IM4 = intMaskEnable;
        break;
    case 5:
        GPIOINT->GPIO_IMR.Bit.IM5 = intMaskEnable;
        break;
    case 6:
        GPIOINT->GPIO_IMR.Bit.IM6 = intMaskEnable;
        break;
    case 7:
        GPIOINT->GPIO_IMR.Bit.IM7 = intMaskEnable;
        break;
    case 8:
        GPIOINT->GPIO_IMR.Bit.IM8 = intMaskEnable;
        break;
    case 9:
        GPIOINT->GPIO_IMR.Bit.IM9 = intMaskEnable;
        break;
    case 10:
        GPIOINT->GPIO_IMR.Bit.IM10 = intMaskEnable;
        break;
    case 11:
        GPIOINT->GPIO_IMR.Bit.IM11 = intMaskEnable;
        break;
    case 12:
        GPIOINT->GPIO_IMR.Bit.IM12 = intMaskEnable;
        break;
    case 13:
        GPIOINT->GPIO_IMR.Bit.IM13 = intMaskEnable;
        break;
    case 14:
        GPIOINT->GPIO_IMR.Bit.IM14 = intMaskEnable;
        break;
    case 15:
        GPIOINT->GPIO_IMR.Bit.IM15 = intMaskEnable;
        break;

    default:
        return -1;
    }
    return 0;

}

/**
* GPIO_SetPullupEnable
*
* @param[in]  gpioNum: GPIO number
* @param[in]  enable: FunctionalState Can be ENABLE or DISABLE
* @return     0: GPIO pull up configuration success; -1: fail
*
* @brief  Set GPIO pin's pull up
*/
int32_t GPIO_SetPullupEnable(uint32_t gpioNum, FunctionalState enable)
{
    uint32_t tmpGPIOx = 0, tmpGPIOxPinNum = 0;

    tmpGPIOx = gpioNum / GPIO_ONE_GROUP_NUM;                  // Calculate GPIO Group(A~E)
    tmpGPIOxPinNum = gpioNum % GPIO_ONE_GROUP_NUM;           // Calculate GPIO Group's Internal Pin Number(0~15)

    if (enable)
    {
        switch (tmpGPIOx)
        {
        case 0:
            GPIOA->GPIO_PU.Byte |= ((uint32_t)0x01) << tmpGPIOxPinNum;
            break;
        case 1:
            GPIOB->GPIO_PU.Byte |= ((uint32_t)0x01) << tmpGPIOxPinNum;
            break;
        case 2:
            GPIOC->GPIO_PU.Byte |= ((uint32_t)0x01) << tmpGPIOxPinNum;
            break;
        case 3:
            GPIOD->GPIO_PU.Byte |= ((uint32_t)0x01) << tmpGPIOxPinNum;
            break;
        case 4:
            GPIOE->GPIO_PU.Byte |= ((uint32_t)0x01) << tmpGPIOxPinNum;
            break;

        default:
            return -1;
        }
    }
    else
    {
        switch (tmpGPIOx)
        {
        case 0:
            GPIOA->GPIO_PU.Byte &= ~(((uint32_t)0x01) << tmpGPIOxPinNum);
            break;
        case 1:
            GPIOB->GPIO_PU.Byte &= ~(((uint32_t)0x01) << tmpGPIOxPinNum);
            break;
        case 2:
            GPIOC->GPIO_PU.Byte &= ~(((uint32_t)0x01) << tmpGPIOxPinNum);
            break;
        case 3:
            GPIOD->GPIO_PU.Byte &= ~(((uint32_t)0x01) << tmpGPIOxPinNum);
            break;
        case 4:
            GPIOE->GPIO_PU.Byte &= ~(((uint32_t)0x01) << tmpGPIOxPinNum);
            break;

        default:
            return -1;
        }
    }

    return 0;
}

/**
* GPIO_SetPulldownEnable
*
* @param[in]  gpioNum: GPIO number
* @param[in]  enable: GPIO pin pull down: 0: disable; 1: enable
* @return     0: GPIO pull down configuration success; -1: fail
*
* @brief  Set GPIO pin's pull down
*/
int32_t GPIO_SetPulldownEnable(uint32_t gpioNum, FunctionalState enable)
{
    uint32_t tmpGPIOx = 0, tmpGPIOxPinNum = 0;

    tmpGPIOx = gpioNum / GPIO_ONE_GROUP_NUM;                  // Calculate GPIO Group(A~E)
    tmpGPIOxPinNum = gpioNum % GPIO_ONE_GROUP_NUM;           // Calculate GPIO Group's Internal Pin Number(0~15)

    if (enable)
    {
        switch (tmpGPIOx)
        {
        case 0:
            GPIOA->GPIO_PD.Byte |= ((uint32_t)0x01) << tmpGPIOxPinNum;
            break;
        case 1:
            GPIOB->GPIO_PD.Byte |= ((uint32_t)0x01) << tmpGPIOxPinNum;
            break;
        case 2:
            GPIOC->GPIO_PD.Byte |= ((uint32_t)0x01) << tmpGPIOxPinNum;
            break;
        case 3:
            GPIOD->GPIO_PD.Byte |= ((uint32_t)0x01) << tmpGPIOxPinNum;
            break;
        case 4:
            GPIOE->GPIO_PD.Byte |= ((uint32_t)0x01) << tmpGPIOxPinNum;
            break;

        default:
            return -1;
        }
    }
    else
    {
        switch (tmpGPIOx)
        {
        case 0:
            GPIOA->GPIO_PD.Byte &= ~(((uint32_t)0x01) << tmpGPIOxPinNum);
            break;
        case 1:
            GPIOB->GPIO_PD.Byte &= ~(((uint32_t)0x01) << tmpGPIOxPinNum);
            break;
        case 2:
            GPIOC->GPIO_PD.Byte &= ~(((uint32_t)0x01) << tmpGPIOxPinNum);
            break;
        case 3:
            GPIOD->GPIO_PD.Byte &= ~(((uint32_t)0x01) << tmpGPIOxPinNum);
            break;
        case 4:
            GPIOE->GPIO_PD.Byte &= ~(((uint32_t)0x01) << tmpGPIOxPinNum);
            break;

        default:
            return -1;
        }
    }

    return 0;
}

/**
* GPIO_SetE4E2
*
* @param[in]  gpioNum: GPIO number
* @param[in]  E4E2Value: GPIO E2E4 value: 0: 4mA; 1: 8mA; 2: 12mA; 3: 16mA
* @return     0: GPIO driving capability configuration success; -1: fail
*
* @brief  Set a GPIO pin's driving capability
*/
int32_t GPIO_SetE4E2(uint32_t gpioNum, uint32_t E4E2Value)
{
    uint32_t tmpGPIOx = 0, tmpGPIOxPinNum = 0;

    if (E4E2Value > 3)
    {
        return -1;
    }

    tmpGPIOx = gpioNum / GPIO_ONE_GROUP_NUM;                  // Calculate GPIO Group(A~E)
    tmpGPIOxPinNum = gpioNum % GPIO_ONE_GROUP_NUM;            // Calculate GPIO Group's Internal Pin Number(0~15)

    switch (tmpGPIOx)
    {
    case 0:
        GPIO_SetGPIOxE4E2x(GPIOA, tmpGPIOxPinNum, E4E2Value);
        break;
    case 1:
        GPIO_SetGPIOxE4E2x(GPIOB, tmpGPIOxPinNum, E4E2Value);
        break;
    case 2:
        GPIO_SetGPIOxE4E2x(GPIOC, tmpGPIOxPinNum, E4E2Value);
        break;
    case 3:
        GPIO_SetGPIOxE4E2x(GPIOD, tmpGPIOxPinNum, E4E2Value);
        break;
    case 4:
        GPIO_SetGPIOxE4E2x(GPIOE, tmpGPIOxPinNum, E4E2Value);
        break;

    default:
        return -1;
    }

    return 0;
}


