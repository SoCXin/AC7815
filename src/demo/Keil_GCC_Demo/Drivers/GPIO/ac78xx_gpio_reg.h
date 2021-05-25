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

#ifndef AC78XX_GPIO_REG_H
#define AC78XX_GPIO_REG_H
#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "stdio.h"
#include "cmsis_gcc.h"
#define __IO    volatile                    //All drivers need this type
#define __I     volatile const
//#define __STATIC_INLINE static __inline


//***********************************************************************************************
typedef struct {
    union {
        __IO uint32_t PMUX_FS_Byte;
        struct{
            __IO uint32_t PFSEL0    :3;
            __IO uint32_t PFSEL1    :3;
            __IO uint32_t PFSEL2    :3;
            __IO uint32_t PFSEL3    :3;
            __IO uint32_t PFSEL4    :3;
            __IO uint32_t PFSEL5    :3;
            __IO uint32_t PFSEL6    :3;
            __IO uint32_t PFSEL7    :3;
            __IO uint32_t PFSEL8    :3;
            __IO uint32_t PFSEL9    :3;
            __IO uint32_t           :2;
        }PMUX_FS_Bit;
    }PMUX_FS;
}PMUX_Type;                                                      /* PMUX Function Selection Register, offset: 0x0 */

typedef struct {
    union{
        struct{
            __IO uint32_t MODE0     :1;
            __IO uint32_t MODE1     :1;
            __IO uint32_t MODE2     :1;
            __IO uint32_t MODE3     :1;
            __IO uint32_t MODE4     :1;
            __IO uint32_t MODE5     :1;
            __IO uint32_t MODE6     :1;
            __IO uint32_t MODE7     :1;
            __IO uint32_t MODE8     :1;
            __IO uint32_t MODE9     :1;
            __IO uint32_t MODE10    :1;
            __IO uint32_t MODE11    :1;
            __IO uint32_t MODE12    :1;
            __IO uint32_t MODE13    :1;
            __IO uint32_t MODE14    :1;
            __IO uint32_t MODE15    :1;
            __IO uint32_t           :16;
        }GPIO_CR_Bit;
        __IO uint32_t GPIO_CR_Byte;
    }GPIO_CR;                                                    /* GPIO Control Register, offset: 0x0 */
    union{
        struct{
            __I uint32_t IDR0       :1;
            __I uint32_t IDR1       :1;
            __I uint32_t IDR2       :1;
            __I uint32_t IDR3       :1;
            __I uint32_t IDR4       :1;
            __I uint32_t IDR5       :1;
            __I uint32_t IDR6       :1;
            __I uint32_t IDR7       :1;
            __I uint32_t IDR8       :1;
            __I uint32_t IDR9       :1;
            __I uint32_t IDR10      :1;
            __I uint32_t IDR11      :1;
            __I uint32_t IDR12      :1;
            __I uint32_t IDR13      :1;
            __I uint32_t IDR14      :1;
            __I uint32_t IDR15      :1;
            __IO uint32_t           :16;
        } Bit;
        __I uint32_t  Byte;
    }GPIO_IDR;                                                   /* GPIO Input Data Register, offset: 0x4 */
    union{
        struct{
            __IO uint32_t ODR0      :1;
            __IO uint32_t ODR1      :1;
            __IO uint32_t ODR2      :1;
            __IO uint32_t ODR3      :1;
            __IO uint32_t ODR4      :1;
            __IO uint32_t ODR5      :1;
            __IO uint32_t ODR6      :1;
            __IO uint32_t ODR7      :1;
            __IO uint32_t ODR8      :1;
            __IO uint32_t ODR9      :1;
            __IO uint32_t ODR10     :1;
            __IO uint32_t ODR11     :1;
            __IO uint32_t ODR12     :1;
            __IO uint32_t ODR13     :1;
            __IO uint32_t ODR14     :1;
            __IO uint32_t ODR15     :1;
            __IO uint32_t           :16;
        }Bit;
        __IO uint32_t  Byte;
    }GPIO_ODR;                                                    /* GPIO Output Data Register, offset: 0x8 */
    union{
         struct{
            __IO uint32_t BS0       :1;
            __IO uint32_t BS1       :1;
            __IO uint32_t BS2       :1;
            __IO uint32_t BS3       :1;
            __IO uint32_t BS4       :1;
            __IO uint32_t BS5       :1;
            __IO uint32_t BS6       :1;
            __IO uint32_t BS7       :1;
            __IO uint32_t BS8       :1;
            __IO uint32_t BS9       :1;
            __IO uint32_t BS10      :1;
            __IO uint32_t BS11      :1;
            __IO uint32_t BS12      :1;
            __IO uint32_t BS13      :1;
            __IO uint32_t BS14      :1;
            __IO uint32_t BS15      :1;
            __IO uint32_t BR0       :1;
            __IO uint32_t BR1       :1;
            __IO uint32_t BR2       :1;
            __IO uint32_t BR3       :1;
            __IO uint32_t BR4       :1;
            __IO uint32_t BR5       :1;
            __IO uint32_t BR6       :1;
            __IO uint32_t BR7       :1;
            __IO uint32_t BR8       :1;
            __IO uint32_t BR9       :1;
            __IO uint32_t BR10      :1;
            __IO uint32_t BR11      :1;
            __IO uint32_t BR12      :1;
            __IO uint32_t BR13      :1;
            __IO uint32_t BR14      :1;
            __IO uint32_t BR15      :1;
        }Bit;
            __IO uint32_t Byte;
    }GPIO_BSRR;                                                   /* GPIO BSRR Register, offset: 0xC */
    union{
            struct{
            __IO uint32_t BR0       :1;
            __IO uint32_t BR1       :1;
            __IO uint32_t BR2       :1;
            __IO uint32_t BR3       :1;
            __IO uint32_t BR4       :1;
            __IO uint32_t BR5       :1;
            __IO uint32_t BR6       :1;
            __IO uint32_t BR7       :1;
            __IO uint32_t BR8       :1;
            __IO uint32_t BR9       :1;
            __IO uint32_t BR10      :1;
            __IO uint32_t BR11      :1;
            __IO uint32_t BR12      :1;
            __IO uint32_t BR13      :1;
            __IO uint32_t BR14      :1;
            __IO uint32_t BR15      :1;
            __IO uint32_t           :16;
        }Bit;
            __IO uint32_t Byte;
    }GPIO_BRR;                                                    /* GPIO BRR Register, offset: 0x10 */

            __IO uint32_t ReserveData;

    union{
        struct{
            __IO uint32_t PD0       :1;
            __IO uint32_t PD1       :1;
            __IO uint32_t PD2       :1;
            __IO uint32_t PD3       :1;
            __IO uint32_t PD4       :1;
            __IO uint32_t PD5       :1;
            __IO uint32_t PD6       :1;
            __IO uint32_t PD7       :1;
            __IO uint32_t PD8       :1;
            __IO uint32_t PD9       :1;
            __IO uint32_t PD10      :1;
            __IO uint32_t PD11      :1;
            __IO uint32_t PD12      :1;
            __IO uint32_t PD13      :1;
            __IO uint32_t PD14      :1;
            __IO uint32_t PD15      :1;
            __IO uint32_t           :16;
        }Bit;
          __IO uint32_t Byte;
    }GPIO_PD;                                                     /* GPIO PD Register, offset: 0x18 */
    union{
        struct{
            __IO uint32_t PU0       :1;
            __IO uint32_t PU1       :1;
            __IO uint32_t PU2       :1;
            __IO uint32_t PU3       :1;
            __IO uint32_t PU4       :1;
            __IO uint32_t PU5       :1;
            __IO uint32_t PU6       :1;
            __IO uint32_t PU7       :1;
            __IO uint32_t PU8       :1;
            __IO uint32_t PU9       :1;
            __IO uint32_t PU10      :1;
            __IO uint32_t PU11      :1;
            __IO uint32_t PU12      :1;
            __IO uint32_t PU13      :1;
            __IO uint32_t PU14      :1;
            __IO uint32_t PU15      :1;
            __IO uint32_t           :16;
        }Bit;
          __IO uint32_t Byte;
    }GPIO_PU;                                                     /* GPIO PU Register, offset: 0x1C */
    union{
        struct{
            __IO uint32_t E4E2_0    :2;
            __IO uint32_t E4E2_1    :2;
            __IO uint32_t E4E2_2    :2;
            __IO uint32_t E4E2_3    :2;
            __IO uint32_t E4E2_4    :2;
            __IO uint32_t E4E2_5    :2;
            __IO uint32_t E4E2_6    :2;
            __IO uint32_t E4E2_7    :2;
            __IO uint32_t E4E2_8    :2;
            __IO uint32_t E4E2_9    :2;
            __IO uint32_t E4E2_10   :2;
            __IO uint32_t E4E2_11   :2;
            __IO uint32_t E4E2_12   :2;
            __IO uint32_t E4E2_13   :2;
            __IO uint32_t E4E2_14   :2;
            __IO uint32_t E4E2_15   :2;
        }Bit;
          __IO uint32_t Byte;
    }GPIO_E4E2;                                                   /* GPIO E4E2 Register, offset: 0x20 */
} GPIO_Type;

typedef struct {
    union{
        struct{
            __IO uint32_t IFP0      :1;
            __IO uint32_t IFP1      :1;
            __IO uint32_t IFP2      :1;
            __IO uint32_t IFP3      :1;
            __IO uint32_t IFP4      :1;
            __IO uint32_t IFP5      :1;
            __IO uint32_t IFP6      :1;
            __IO uint32_t IFP7      :1;
            __IO uint32_t IFP8      :1;
            __IO uint32_t IFP9      :1;
            __IO uint32_t IFP10     :1;
            __IO uint32_t IFP11     :1;
            __IO uint32_t IFP12     :1;
            __IO uint32_t IFP13     :1;
            __IO uint32_t IFP14     :1;
            __IO uint32_t IFP15     :1;
            __IO uint32_t           :16;
        }Bit;
        __IO uint32_t  Byte;
    }GPIO_IFPR;                                                     /* GPIO Interrupt Flag Pending Register, offset: 0x160 */
    union{
        struct{
            __IO uint32_t IM0       :1;
            __IO uint32_t IM1       :1;
            __IO uint32_t IM2       :1;
            __IO uint32_t IM3       :1;
            __IO uint32_t IM4       :1;
            __IO uint32_t IM5       :1;
            __IO uint32_t IM6       :1;
            __IO uint32_t IM7       :1;
            __IO uint32_t IM8       :1;
            __IO uint32_t IM9       :1;
            __IO uint32_t IM10      :1;
            __IO uint32_t IM11      :1;
            __IO uint32_t IM12      :1;
            __IO uint32_t IM13      :1;
            __IO uint32_t IM14      :1;
            __IO uint32_t IM15      :1;
            __IO uint32_t           :16;
        }Bit;
        __IO uint32_t  Byte;
    }GPIO_IMR;                                                      /* GPIO Interrupt Mask Register, offset: 0x164 */
    union{
        struct{
            __IO uint32_t REC0      :1;
            __IO uint32_t REC1      :1;
            __IO uint32_t REC2      :1;
            __IO uint32_t REC3      :1;
            __IO uint32_t REC4      :1;
            __IO uint32_t REC5      :1;
            __IO uint32_t REC6      :1;
            __IO uint32_t REC7      :1;
            __IO uint32_t REC8      :1;
            __IO uint32_t REC9      :1;
            __IO uint32_t REC10     :1;
            __IO uint32_t REC11     :1;
            __IO uint32_t REC12     :1;
            __IO uint32_t REC13     :1;
            __IO uint32_t REC14     :1;
            __IO uint32_t REC15     :1;
            __IO uint32_t           :16;
        }Bit;
        __IO uint32_t  Byte;
    }GPIO_RECR;                                                     /* GPIO Rising Edge Configuration Register, offset: 0x168 */
    union{
        struct{
            __IO uint32_t FEC0      :1;
            __IO uint32_t FEC1      :1;
            __IO uint32_t FEC2      :1;
            __IO uint32_t FEC3      :1;
            __IO uint32_t FEC4      :1;
            __IO uint32_t FEC5      :1;
            __IO uint32_t FEC6      :1;
            __IO uint32_t FEC7      :1;
            __IO uint32_t FEC8      :1;
            __IO uint32_t FEC9      :1;
            __IO uint32_t FEC10     :1;
            __IO uint32_t FEC11     :1;
            __IO uint32_t FEC12     :1;
            __IO uint32_t FEC13     :1;
            __IO uint32_t FEC14     :1;
            __IO uint32_t FEC15     :1;
            __IO uint32_t           :16;
        }Bit;
        __IO uint32_t  Byte;
    }GPIO_FECR;                                                      /* GPIO Rising Edge Configuration Register, offset: 0x16C */
    union{
        struct{
            __IO uint32_t EXTIC0    :4;
            __IO uint32_t EXTIC1    :4;
            __IO uint32_t EXTIC2    :4;
            __IO uint32_t EXTIC3    :4;
            __IO uint32_t           :16;
        }Bit;
        __IO uint32_t  Byte;
    }GPIO_EXTICR0;                                                   /* GPIO External Interrupt Configuration Register 0, offset: 0x170 */
    union{
        struct{
            __IO uint32_t EXTIC4    :4;
            __IO uint32_t EXTIC5    :4;
            __IO uint32_t EXTIC6    :4;
            __IO uint32_t EXTIC7    :4;
            __IO uint32_t           :16;
        }Bit;
        __IO uint32_t  Byte;
    }GPIO_EXTICR1;                                                   /* GPIO External Interrupt Configuration Register 1, offset: 0x174 */
    union{
        struct{
            __IO uint32_t EXTIC8    :4;
            __IO uint32_t EXTIC9    :4;
            __IO uint32_t EXTIC10   :4;
            __IO uint32_t EXTIC11   :4;
            __IO uint32_t           :16;
        }Bit;
        __IO uint32_t  Byte;
    }GPIO_EXTICR2;                                                   /* GPIO External Interrupt Configuration Register 2, offset: 0x178 */
    union{
        struct{
            __IO uint32_t EXTIC12   :4;
            __IO uint32_t EXTIC13   :4;
            __IO uint32_t EXTIC14   :4;
            __IO uint32_t EXTIC15   :4;
            __IO uint32_t           :16;
        }Bit;
        __IO uint32_t  Byte;
    }GPIO_EXTICR3;                                                   /* GPIO External Interrupt Configuration Register 3, offset: 0x17C */
}GPIO_Interrupt_Type;
/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIOx base address */
#define GPIOA_BASE                                (0x20080000u)
#define GPIOB_BASE                                (0x20080030u)
#define GPIOC_BASE                                (0x20080060u)
#define GPIOD_BASE                                (0x20080090u)
#define GPIOE_BASE                                (0x200800c0u)
/** Peripheral PMUX base address */
#define PMUX0_BASE                                (0x20080140u)
#define PMUX1_BASE                                (0x20080144u)
#define PMUX2_BASE                                (0x20080148u)
#define PMUX3_BASE                                (0x2008014cu)
#define PMUX4_BASE                                (0x20080150u)
#define PMUX5_BASE                                (0x20080154u)
#define PMUX6_BASE                                (0x20080158u)
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASES                                { GPIOA, GPIOB, GPIOC, GPIOD, GPIOE }
/** Array initializer of PMUX peripheral base pointers */
#define PMUX_BASES                                { PMUX0, PMUX1, PMUX2, PMUX3, PMUX4, PMUX5, PMUX6 }
//******************************************************************************

/* ODR interfaces */
#define GPIOA_ODR_ADDR    (GPIOA_BASE+0x8) //0x20080008
#define GPIOB_ODR_ADDR    (GPIOB_BASE+0x8) //0x20080038
#define GPIOC_ODR_ADDR    (GPIOC_BASE+0x8) //0x20080068
#define GPIOD_ODR_ADDR    (GPIOD_BASE+0x8) //0x20080098
#define GPIOE_ODR_ADDR    (GPIOE_BASE+0x8) //0x200800c8
/* IDR interfaces */
#define GPIOA_IDR_ADDR    (GPIOA_BASE+0x4) //0x20080004
#define GPIOB_IDR_ADDR    (GPIOB_BASE+0x4) //0x20080034
#define GPIOC_IDR_ADDR    (GPIOC_BASE+0x4) //0x20080064
#define GPIOD_IDR_ADDR    (GPIOD_BASE+0x4) //0x20080094
#define GPIOE_IDR_ADDR    (GPIOE_BASE+0x4) //0x200800c4

/* Bit Band Operation */
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2))
#define MEM_ADDR(addr)  *((volatile uint32_t *)(addr))
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum))

/******************************************************************************
* GPIO API list
*******************************************************************************/
/**
 * PMUX_SetPMUXxPFSELx
 *
 * @param[in] PMUXx: PMUX type pointer
 * @param[in] PFSELx: PFSEL index    (0-9)
 * @param[in] functionx: Function index (0-7)
 * @return    none
 *
 * @brief  Set PMUXx and PFSELx with functionx
 */
__STATIC_INLINE void PMUX_SetPMUXxPFSELx(PMUX_Type *PMUXx, uint32_t PFSELx, uint32_t functionx)
{
    switch (PFSELx)
    {
        case 0: PMUXx->PMUX_FS.PMUX_FS_Bit.PFSEL0 = functionx; break;
        case 1: PMUXx->PMUX_FS.PMUX_FS_Bit.PFSEL1 = functionx; break;
        case 2: PMUXx->PMUX_FS.PMUX_FS_Bit.PFSEL2 = functionx; break;
        case 3: PMUXx->PMUX_FS.PMUX_FS_Bit.PFSEL3 = functionx; break;
        case 4: PMUXx->PMUX_FS.PMUX_FS_Bit.PFSEL4 = functionx; break;
        case 5: PMUXx->PMUX_FS.PMUX_FS_Bit.PFSEL5 = functionx; break;
        case 6: PMUXx->PMUX_FS.PMUX_FS_Bit.PFSEL6 = functionx; break;
        case 7: PMUXx->PMUX_FS.PMUX_FS_Bit.PFSEL7 = functionx; break;
        case 8: PMUXx->PMUX_FS.PMUX_FS_Bit.PFSEL8 = functionx; break;
        case 9: PMUXx->PMUX_FS.PMUX_FS_Bit.PFSEL9 = functionx; break;

        default: return;
    }
}

/**
 * PMUX_GetPMUXxPFSELx
 *
 * @param[in] PMUXx: PMUX type pointer
 * @return    PMUX value
 *
 * @brief  Get PMUX value
 */
__STATIC_INLINE uint32_t PMUX_GetPMUXxPFSEL(PMUX_Type *PMUXx)
{
    return (PMUXx->PMUX_FS.PMUX_FS_Byte);
}

/**
 * GPIO_SetGPIOxMODE
 *
 * @param[in]  GPIOx: GPIO type pointer
 * @param[in]  MODEx: pin index    (0-15)
 * @param[in]  modeValue: 1:output mode 0: input mode
 * @return     none
 *
 * @brief  Set GPIO Configuration and Mode
 */
__STATIC_INLINE void GPIO_SetGPIOxMODE(GPIO_Type *GPIOx, uint32_t MODEx, uint32_t modeValue)
{
    switch (MODEx)
    {
        case 0: GPIOx->GPIO_CR.GPIO_CR_Bit.MODE0 = modeValue; break;
        case 1: GPIOx->GPIO_CR.GPIO_CR_Bit.MODE1 = modeValue; break;
        case 2: GPIOx->GPIO_CR.GPIO_CR_Bit.MODE2 = modeValue; break;
        case 3: GPIOx->GPIO_CR.GPIO_CR_Bit.MODE3 = modeValue; break;
        case 4: GPIOx->GPIO_CR.GPIO_CR_Bit.MODE4 = modeValue; break;
        case 5: GPIOx->GPIO_CR.GPIO_CR_Bit.MODE5 = modeValue; break;
        case 6: GPIOx->GPIO_CR.GPIO_CR_Bit.MODE6 = modeValue; break;
        case 7: GPIOx->GPIO_CR.GPIO_CR_Bit.MODE7 = modeValue; break;
        case 8: GPIOx->GPIO_CR.GPIO_CR_Bit.MODE8 = modeValue; break;
        case 9: GPIOx->GPIO_CR.GPIO_CR_Bit.MODE9 = modeValue; break;
        case 10: GPIOx->GPIO_CR.GPIO_CR_Bit.MODE10 = modeValue; break;
        case 11: GPIOx->GPIO_CR.GPIO_CR_Bit.MODE11 = modeValue; break;
        case 12: GPIOx->GPIO_CR.GPIO_CR_Bit.MODE12 = modeValue; break;
        case 13: GPIOx->GPIO_CR.GPIO_CR_Bit.MODE13 = modeValue; break;
        case 14: GPIOx->GPIO_CR.GPIO_CR_Bit.MODE14 = modeValue; break;
        case 15: GPIOx->GPIO_CR.GPIO_CR_Bit.MODE15 = modeValue; break;

        default: return;
    }
}

/**
 * GPIO_GetGPIOxCR
 *
 * @param[in]  GPIOx: GPIO type pointer
 * @return     CR value
 *
 * @brief  Get GPIO Configuration and Mode value
 */
__STATIC_INLINE uint32_t GPIO_GetGPIOxCR(GPIO_Type *GPIOx)
{
    return (GPIOx->GPIO_CR.GPIO_CR_Byte);
}


/**
 * GPIO_GetGPIOxIDR
 *
 * @param[in] GPIOx: GPIO type pointer
 * @return    IDR register value
 *
 * @brief  Get GPIO IDR register value
 */
__STATIC_INLINE uint32_t GPIO_GetGPIOxIDR(GPIO_Type *GPIOx)
{
    return (GPIOx->GPIO_IDR.Byte);
}

/**
 * GPIO_SetGPIOxODR
 *
 * @param[in]  GPIOx: GPIO type pointer
 * @param[in]  ODRx: pin index
 * @param[in]  ODRValue: GPIO output value
 * @return     none
 *
 * @brief  Set GPIO ODR register value
 */
__STATIC_INLINE void GPIO_SetGPIOxODRx(GPIO_Type *GPIOx, uint32_t ODRx, uint32_t ODRValue)
{
    switch (ODRx)
    {
        case 0: GPIOx->GPIO_ODR.Bit.ODR0 = ODRValue; break;
        case 1: GPIOx->GPIO_ODR.Bit.ODR1 = ODRValue; break;
        case 2: GPIOx->GPIO_ODR.Bit.ODR2 = ODRValue; break;
        case 3: GPIOx->GPIO_ODR.Bit.ODR3 = ODRValue; break;
        case 4: GPIOx->GPIO_ODR.Bit.ODR4 = ODRValue; break;
        case 5: GPIOx->GPIO_ODR.Bit.ODR5 = ODRValue; break;
        case 6: GPIOx->GPIO_ODR.Bit.ODR6 = ODRValue; break;
        case 7: GPIOx->GPIO_ODR.Bit.ODR7 = ODRValue; break;
        case 8: GPIOx->GPIO_ODR.Bit.ODR8 = ODRValue; break;
        case 9: GPIOx->GPIO_ODR.Bit.ODR9 = ODRValue; break;
        case 10: GPIOx->GPIO_ODR.Bit.ODR10 = ODRValue; break;
        case 11: GPIOx->GPIO_ODR.Bit.ODR11 = ODRValue; break;
        case 12: GPIOx->GPIO_ODR.Bit.ODR12 = ODRValue; break;
        case 13: GPIOx->GPIO_ODR.Bit.ODR13 = ODRValue; break;
        case 14: GPIOx->GPIO_ODR.Bit.ODR14 = ODRValue; break;
        case 15: GPIOx->GPIO_ODR.Bit.ODR15 = ODRValue; break;

        default: return;
    }
}

/**
 * GPIO_GetGPIOxODR
 *
 * @param[in]  GPIOx: GPIO type pointer
 * @return     ODR register value
 *
 * @brief  Get GPIO ODR register value
 */
__STATIC_INLINE uint32_t GPIO_GetGPIOxODR(GPIO_Type *GPIOx)
{
    return (GPIOx->GPIO_ODR.Byte);
}

/**
 * GPIO_SetGPIOxBSRRx
 *
 * @param[in] GPIOx: GPIO type pointer
 * @param[in] BSRRx: BSRRx index
 * @return    none
 *
 * @brief  Set GPIO BSRR register value
 */
__STATIC_INLINE void GPIO_SetGPIOxBSRRx(GPIO_Type *GPIOx, uint32_t BSRRx)
{
    switch (BSRRx)
    {
        case 0: GPIOx->GPIO_BSRR.Bit.BS0 = 0x1; break;
        case 1: GPIOx->GPIO_BSRR.Bit.BS1 = 0x1; break;
        case 2: GPIOx->GPIO_BSRR.Bit.BS2 = 0x1; break;
        case 3: GPIOx->GPIO_BSRR.Bit.BS3 = 0x1; break;
        case 4: GPIOx->GPIO_BSRR.Bit.BS4 = 0x1; break;
        case 5: GPIOx->GPIO_BSRR.Bit.BS5 = 0x1; break;
        case 6: GPIOx->GPIO_BSRR.Bit.BS6 = 0x1; break;
        case 7: GPIOx->GPIO_BSRR.Bit.BS7 = 0x1; break;
        case 8: GPIOx->GPIO_BSRR.Bit.BS8 = 0x1; break;
        case 9: GPIOx->GPIO_BSRR.Bit.BS9 = 0x1; break;
        case 10: GPIOx->GPIO_BSRR.Bit.BS10 = 0x1; break;
        case 11: GPIOx->GPIO_BSRR.Bit.BS11 = 0x1; break;
        case 12: GPIOx->GPIO_BSRR.Bit.BS12 = 0x1; break;
        case 13: GPIOx->GPIO_BSRR.Bit.BS13 = 0x1; break;
        case 14: GPIOx->GPIO_BSRR.Bit.BS14 = 0x1; break;
        case 15: GPIOx->GPIO_BSRR.Bit.BS15 = 0x1; break;

        default: return;
    }
}

/**
 * GPIO_SetGPIOxBRRx
 *
 * @param[in] GPIOx: GPIO type pointer
 * @param[in] BRRx: brrx index
 * @return    none
 *
 * @brief  Set GPIO BRR register value
 */
__STATIC_INLINE void GPIO_SetGPIOxBRRx(GPIO_Type *GPIOx, uint32_t BRRx)
{
    switch (BRRx)
    {
        case 0: GPIOx->GPIO_BRR.Bit.BR0 = 0x1; break;
        case 1: GPIOx->GPIO_BRR.Bit.BR1 = 0x1; break;
        case 2: GPIOx->GPIO_BRR.Bit.BR2 = 0x1; break;
        case 3: GPIOx->GPIO_BRR.Bit.BR3 = 0x1; break;
        case 4: GPIOx->GPIO_BRR.Bit.BR4 = 0x1; break;
        case 5: GPIOx->GPIO_BRR.Bit.BR5 = 0x1; break;
        case 6: GPIOx->GPIO_BRR.Bit.BR6 = 0x1; break;
        case 7: GPIOx->GPIO_BRR.Bit.BR7 = 0x1; break;
        case 8: GPIOx->GPIO_BRR.Bit.BR8 = 0x1; break;
        case 9: GPIOx->GPIO_BRR.Bit.BR9 = 0x1; break;
        case 10: GPIOx->GPIO_BRR.Bit.BR10 = 0x1; break;
        case 11: GPIOx->GPIO_BRR.Bit.BR11 = 0x1; break;
        case 12: GPIOx->GPIO_BRR.Bit.BR12 = 0x1; break;
        case 13: GPIOx->GPIO_BRR.Bit.BR13 = 0x1; break;
        case 14: GPIOx->GPIO_BRR.Bit.BR14 = 0x1; break;
        case 15: GPIOx->GPIO_BRR.Bit.BR15 = 0x1; break;

        default: return;
    }
}

/**
 * GPIO_SetGPIOxE4E2x
 *
 * @param[in]  GPIOx: GPIO type pointer
 * @param[in]  E4E2x: pin index
 * @param[in]  E4E2Value: output driver level
 * @return     none
 *
 * @brief  Set GPIO E4E2 register value
 */
__STATIC_INLINE void GPIO_SetGPIOxE4E2x(GPIO_Type *GPIOx, uint32_t E4E2x, uint32_t E4E2Value)
{
    switch (E4E2x)
    {
        case 0: GPIOx->GPIO_E4E2.Bit.E4E2_0 = E4E2Value; break;
        case 1: GPIOx->GPIO_E4E2.Bit.E4E2_1 = E4E2Value; break;
        case 2: GPIOx->GPIO_E4E2.Bit.E4E2_2 = E4E2Value; break;
        case 3: GPIOx->GPIO_E4E2.Bit.E4E2_3 = E4E2Value; break;
        case 4: GPIOx->GPIO_E4E2.Bit.E4E2_4 = E4E2Value; break;
        case 5: GPIOx->GPIO_E4E2.Bit.E4E2_5 = E4E2Value; break;
        case 6: GPIOx->GPIO_E4E2.Bit.E4E2_6 = E4E2Value; break;
        case 7: GPIOx->GPIO_E4E2.Bit.E4E2_7 = E4E2Value; break;
        case 8: GPIOx->GPIO_E4E2.Bit.E4E2_8 = E4E2Value; break;
        case 9: GPIOx->GPIO_E4E2.Bit.E4E2_9 = E4E2Value; break;
        case 10: GPIOx->GPIO_E4E2.Bit.E4E2_10 = E4E2Value; break;
        case 11: GPIOx->GPIO_E4E2.Bit.E4E2_11 = E4E2Value; break;
        case 12: GPIOx->GPIO_E4E2.Bit.E4E2_12 = E4E2Value; break;
        case 13: GPIOx->GPIO_E4E2.Bit.E4E2_13 = E4E2Value; break;
        case 14: GPIOx->GPIO_E4E2.Bit.E4E2_14 = E4E2Value; break;
        case 15: GPIOx->GPIO_E4E2.Bit.E4E2_15 = E4E2Value; break;

        default: return;
    }
}


/******************************************************************************
* Global functions
******************************************************************************/
void PMUX_SetPMUXxPFSELx(PMUX_Type *PMUXx, uint32_t PFSELx, uint32_t functionx);
uint32_t PMUX_GetPMUXxPFSEL(PMUX_Type *PMUXx);
void GPIO_SetGPIOxMODE(GPIO_Type *GPIOx, uint32_t MODEx, uint32_t modeValue);
uint32_t GPIO_GetGPIOxCR(GPIO_Type *GPIOx);

uint32_t GPIO_GetGPIOxIDR(GPIO_Type *GPIOx);
void GPIO_SetGPIOxODRx(GPIO_Type *GPIOx, uint32_t ODRx, uint32_t ODRValue);
uint32_t GPIO_GetGPIOxODR(GPIO_Type *GPIOx);
void GPIO_SetGPIOxBSRRx(GPIO_Type *GPIOx, uint32_t BSRRx);
void GPIO_SetGPIOxBRRx(GPIO_Type *GPIOx, uint32_t BRRx);



#ifdef __cplusplus
}
#endif

#endif
