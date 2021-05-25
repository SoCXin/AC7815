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

#ifndef _AC78XX_UART_REG_H_
#define _AC78XX_UART_REG_H_
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__CC_ARM)
  #pragma anon_unions
#elif defined(CCARM__)
  #pragma language=extended
#elif defined (__ICCARM__)
/* anonymous unions are enabled by default */
#elif defined(__GNUC__)
/* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif

#include "ac78xx.h"
#include "ac78xx_dma.h"

#if defined ( __ICCARM__ )
#define __STATIC_INLINE static inline
#elif defined ( __GNUC__)
#define __STATIC_INLINE static inline
#elif defined (__CC_ARM)
#define __STATIC_INLINE static __inline
#endif


#define     UART_BUSCLK        APB_BUS_FREQ
#define     BAUDRATE_1M        (1000000u)

///< [offset:0x0C]UARTn_LCR0, Line Control Register
#define            BIT5                    (5)
#define            BIT6                    (6)
#define            BIT7                    (7)
#define            BIT8                    (8)
#define            BIT9                    (9)

#define            NOPARITY                (0)
#define            ODD                     (1)
#define            EVEN                    (2)

#define            STOP_1BIT               (1)
#define            STOP_2BIT               (2)

///< [offset:0x1C]UARTn_IER, Interrupt Enable Register
#define            IER_ERXNE               (1<<0)
#define            IER_ETXE                (1<<1)
#define            IER_ETC                 (1<<2)
#define            IER_EPE                 (1<<3)
#define            IER_EFE                 (1<<4)
#define            IER_ENE                 (1<<5)
#define            IER_EOEBI               (1<<6)
#define            IER_EDCTS               (1<<7)

///< [offset:0x18]UARTn_EFR, Enhanced Feature Register
#define            EFR_AUTO_CTS            (1<<7)
#define            EFR_AUTO_RTS            (1<<6)
#define            RTSCTS_NONE             (0)
#define            RTS_ONLY                (1)
#define            CTS_ONLY                (2)
#define            RTS_CTS                 (3)

///< [offset:0x20]UARTn_LSR0, Line Status Register
#define            LSR0_DR                 (1<<0)            ///< Data ready
#define            LSR0_OE                 (1<<1)            ///< Overrun error
#define            LSR0_PE                 (1<<2)            ///< parity error
#define            LSR0_FE                 (1<<3)            ///< Framing error
#define            LSR0_BI                 (1<<4)            ///< Break interrupt
#define            LSR0_THRE               (1<<5)            ///< Tx holding reg is empty
#define            LSR0_TEMT               (1<<6)            ///< Tx holding reg and Tx shift reg are empty
#define            LSR0_NE                 (1<<7)            ///< Noise error detect

///< [offset:0x24]UARTn_LSR1, Line Status Register
#define            LSR1_IDLE               (1<<0)
#define            LSR1_RTO                (1<<1)
#define            LSR1_FBRK               (1<<2)
#define            LSR1_DCTS               (1<<3)
#define            LSR1_CTS                (1<<6)
#define            LSR1_RTS                (1<<7)

///< [offset:0x28]UARTn_RATE_STEP, Sample Counter uart
#define            RATE_STEP_0             (0x0)
#define            RATE_STEP_1             (0x1)
#define            RATE_STEP_2             (0x2)
#define            SAMPLE_COUNTER_16       (16)
#define            SAMPLE_COUNTER_8        (8)
#define            SAMPLE_COUNTER_4        (4)

///< [offset:0x34]UARTn_GUARD, Guard time added register
#define            GUARDEN                 (1<<4)
#define            GUARDCNT_MASK           (0xF)
#define            GUARDCNT_DEF            (0x10)

///< [offset:0x40]UARTn_DMA_EN, DMA enable register
#define            RXDMAEN                 (1<<0)
#define            TXDMAEN                 (1<<1)
#define            TO_CNTAUTORST           (1<<2)

#define            FIFOMODE                (1)
#define            DMAMODE                 (2)

///< [offset:0x4C]UARTn_RS485CR, RS485 control register
#define            RS485_DLYEN             (1<<4)
#define            RS485_INVPOL            (1<<5)
#define            RS485_DIRPINSEL         (1<<6)
#define            RS485_EN                (1<<7)

///< [offset:0x58]UARTn_MULCOMCR, Multiprocessor communication control register
#define            MULCOM_IDLEIE           (1<<4)
#define            MULCOM_EN               (1<<7)

///< [offset:0x5C]UARTn_LINCR, LIN control register
#define            LIN_LBRKDF              (1<<0)
#define            LIN_LABAUDEN            (1<<3)
#define            LIN_SDBRK               (1<<4)
#define            LIN_LBRKDL              (1<<5)
#define            LIN_LBRKIE              (1<<6)
#define            LIN_EN                  (1<<7)

typedef volatile struct {
    uint32_t    UARTn_RBR_THR;                                     ///< [offset:0x00]RX buffer register/TX holding register
    uint32_t    UARTn_DLL;                                         ///< [offset:0x04]Divisor Latch(LS)
    uint32_t    UARTn_DLM;                                         ///< [offset:0x08]Divisor Latch(MS)

    struct {                                                       ///< [offset:0x0C]UARTn_LCR0, Line Control Register
        uint32_t WLS1_WLS0            :2;                          ///< bit[0:1]: select word length
        uint32_t STB                  :1;                          ///< bit[2]: Number of stop bits
        uint32_t PEN                  :1;                          ///< bit[3]: Enable parity
        uint32_t EPS                  :1;                          ///< bit[4]: Select even parity
        uint32_t SP                   :1;                          ///< bit[5]: Stick parity
        uint32_t SB                   :1;                          ///< bit[6]: Sets up break
        uint32_t DLAB                 :1;                          ///< bit[7]: Divisor latch access bit
        uint32_t                      :24;                         ///< bit[8-31]: reserved
    }UARTn_LCR0;

    struct {                                                       ///< [offset:0x10]UARTn_LCR1
        uint32_t RXEN                 :1;
        uint32_t TXEN                 :1;
        uint32_t                      :2;                          ///< bit[0-3]:reserved
        uint32_t Loop                 :1;                          ///< bit[4]:Loop-back control bit
        uint32_t WLS2                 :1;                          ///< bit[5]:determine whether 9 bit data mode is available
        uint32_t INVRX                :1;                          ///< bit[6]:determine whether inverse the rx output
        uint32_t INVTX                :1;                          ///< bit[7]:determine whether inverse the tx output
        uint32_t                      :24;                         ///< bit[8-31]: reserved
    }UARTn_LCR1;

    struct {                                                       ///< [offset:0x14]UARTn_FCR, FIFO Control Register
        uint32_t FIFOE                :1;                          ///< bit[0] FIFO Enable
        uint32_t                      :31;                         ///< bit[1-31]: reserved
    }UARTn_FCR;

    struct {                                                       ///< [offset:0x18]UARTn_EFR, Enhanced Feature Register
        uint32_t                      :6;                          ///< bit[0-5]: reserved
        uint32_t AUTO_RTS             :1;                          ///< bit[6]: auto rts
        uint32_t AUTO_CTS             :1;                          ///< bit[7]: auto cts
        uint32_t                      :24;                         ///< bit[8-31]: reserved
    }UARTn_EFR;

    union {
        uint32_t Ux_IER;                                           ///< [offset:0x1C]UARTn_IER, Interrupt Enable Register
        struct {                                                   ///< [offset:0x1C]UARTn_IER, Interrupt Enable Register
            uint32_t ERXNE            :1;                          ///< bit[0]: rx buffer not empty
            uint32_t ETXE             :1;                          ///< bit[1]: tx holding register is empty
            uint32_t ETC              :1;                          ///< bit[2]: tx transmitting is completed(tx holding reg and tx shift reg are empty)
            uint32_t EPE              :1;                          ///< bit[3]: parity error interrupt
            uint32_t EFE              :1;                          ///< bit[4]: frame error interrupt
            uint32_t ENE              :1;                          ///< bit[5]: noise error interrupt
            uint32_t EOEBI            :1;                          ///< bit[6]: overrun error and break error interrupt
            uint32_t EDCTS            :1;                          ///< bit[7]: CTS change interrupt
            uint32_t                  :24;                         ///< bit[8-31]: reserved
        }UARTn_IER;
    };

    union {
        uint32_t Ux_LSR0;                                          ///< [offset:0x20]UARTn_LSR0, Line Status Register
        struct {                                                   ///< [offset:0x20]UARTn_LSR0, Line Status Register
            uint32_t DR               :1;                          ///< bit[0]:Data ready
            uint32_t OE               :1;                          ///< bit[1]:Overrun error
            uint32_t PE               :1;                          ///< bit[2]:Parity error
            uint32_t FE               :1;                          ///< bit[3]:Framing error
            uint32_t BI               :1;                          ///< bit[4]:Break interrupt
            uint32_t THRE             :1;                          ///< bit[5]:Tx holding reg is empty
            uint32_t TC               :1;                          ///< bit[6]:Tx holding reg and Tx shift reg are empty
            uint32_t NE               :1;                          ///< bit[7]:Noise error detect
            uint32_t                  :24;                         ///< bit[8-31]: reserved
        }UARTn_LSR0;
    };

    union {
        uint32_t Ux_LSR1;                                          ///< [offset:0x24]UARTn_LSR1, Line Status Register
        struct {                                                   ///< [offset:0x24]UARTn_LSR1, Line Status Register
            uint32_t IDLE             :1;                          ///< bit[0]:IDLE
            uint32_t                  :1;                          ///< bit[1]:reserved
            uint32_t FBRK             :1;                          ///< bit[2]:FBRK
            uint32_t DCTS             :1;                          ///< bit[3]:DCTS
            uint32_t                  :1;                          ///< bit[4]:reserved
            uint32_t UART_IDLE        :1;                          ///< bit[5]:UART_IDLE
            uint32_t CTS              :1;                          ///< bit[6]:CTS
            uint32_t RTS              :1;                          ///< bit[7]:RTS
            uint32_t                  :24;                         ///< bit[8-31]: reserved
        }UARTn_LSR1;
    };

    struct {                                                       ///< [offset:0x28]UARTn_RATE_STEP, High speed uart
        uint32_t    SMP_CNT           :2;                          ///< bit[0-1]:speed
        uint32_t                      :30;                         ///< bit[2-31]: reserved
    }UARTn_RATE_STEP;

        uint32_t    RESERVED_0x2c;                                 ///< Reserve
        uint32_t    RESERVED_0x30;                                 ///< Reserve

    struct {                                                       ///< [offset:0x34]UARTn_GUARD, Guard time added register
        uint32_t    GUARD_CNT         :4;                          ///< bit[0-3]:Guard interval count value
        uint32_t    GUARD_EN          :1;                          ///< bit[4]:Guard interval enabling signal
        uint32_t                      :27;                         ///< bit[5-31]: reserved
    }UARTn_GUARD;

        uint32_t    RESERVED_0x38;                                 ///< [offset:0x38]Reserved

    struct {                                                       ///< [offset:0x3C]UARTn_SLEEP_EN, Sleep enable register
        uint32_t    SLEEP_EN          :1;                          ///< bit[0]:enable sleep mode
        uint32_t                      :31;                         ///< bit[1-31]: reserved
    }UARTn_SLEEP_EN;

    struct {                                                       ///< [offset:0x40]UARTn_DMA_EN, DMA enable register
        uint32_t    RX_DMA_EN         :1;                          ///< bit[0]:enable rx dma
        uint32_t    TX_DMA_EN         :1;                          ///< bit[1]:enable tx dma
        uint32_t    TO_CNT_AUTO_RTS   :1;                          ///< bit[2]:enable rx dma
        uint32_t                      :29;                         ///< bit[3-31]: reserved
    }UARTn_DMA_EN;

        uint32_t    UARTn_FRACDIV_L;                               ///< [offset:0x44]Fractional divider LSB address
        uint32_t    reserve_48;                                    ///< [offset:0x48]Fractional divider MSB address

    struct {                                                       ///< [offset:0x4C]UARTn_RS485CR, RS485 control register
        uint32_t                      :4;                          ///< reserved
        uint32_t    DLYEN             :1;                          ///< DELAY insert between the last stop bit and rts_n of dtr_n de-assertion
        uint32_t    INVPOL            :1;                          ///< inverse the polarity of rts_n or dtr_n
        uint32_t                      :1;                          ///< bit[6]:reserved
        uint32_t    RS485EN           :1;                          ///< enable/disable rs485 mode
        uint32_t                      :24;                         ///< bit[8-31]: reserved
    }UARTn_RS485CR;

        uint32_t    UARTn_SLADDR;                                  ///< [offset:0x50]Address for RS485 or Multi-processor communication
        uint32_t    UARTn_CNTR;                                    ///< [offset:0x54]delay time in RS485 mode

    struct {                                                       ///< [offset:0x58]UARTn_MULCOMCR, Multiprocessor communication control register
        uint32_t                      :4;                          ///< bit[0-3]:reserved
        uint32_t    IDLEIE            :1;                          ///< bit[4]:IDLE interrupt enable
        uint32_t                      :2;                          ///< bit[5-6]:reserved
        uint32_t    MULCOMEN          :1;                          ///< bit[7]:Multi communication enable
        uint32_t                      :24;                         ///< bit[8-31]: reserved
    }UARTn_MULCOMCR;

    struct {                                                       ///< [offset:0x5C]UARTn_LINCR, LIN control register
        uint32_t    LBRKDF            :1;                          ///< bit[0]:Lin break detect flag
        uint32_t                      :2;                          ///< bit[1-2]:reserved
        uint32_t    LABAUDEN          :1;                          ///< bit[3]:0x55 detect to autobaud
        uint32_t    SDBRK             :1;                          ///< bit[4]:LIN mode whether transmit 13 0s
        uint32_t    LBRKDL            :1;                          ///< bit[5]:LIN mode break detect length
        uint32_t    LBRKIE            :1;                          ///< bit[6]:LIN break character detect interupt enable
        uint32_t    LINEN             :1;                          ///< bit[7]:LIN mode enable
        uint32_t                      :24;                         ///< bit[8-31]:reserved
    }UARTn_LINCR;

        uint32_t    RESERVED_0x60;                                 ///< [offset:0x60]Reserved
        uint32_t    RESERVED_0x64;                                 ///< [offset:0x64]Reserved
        uint32_t    RESERVED_0x68;                                 ///< [offset:0x68]Reserved
        uint32_t    RESERVED_0x6C;                                 ///< [offset:0x6C]Reserved
        uint32_t    RESERVED_0x70;                                 ///< [offset:0x70]Reserved
        uint32_t    RESERVED_0x74;                                 ///< [offset:0x74]Reserved
        uint32_t    RESERVED_0x78;                                 ///< [offset:0x78]Reserved
        uint32_t    RESERVED_0x7C;                                 ///< [offset:0x7C]Reserved
        uint32_t    UARTn_DEBUG0;                                  ///< [offset:0x80]Debug register0 tx state
        uint32_t    UARTn_DEBUG1;                                  ///< [offset:0x84]Debug register1 rx state
        uint32_t    UARTn_SCR;                                     ///< [offset:0x88]
}UART_Type;

typedef struct {
    uint32_t   baudrate;
    uint8_t    dataBits;
    uint8_t    stopBits;
    uint8_t    parity;
    uint8_t    fifoByte;
    uint8_t    dmaEn;                ///< 0; FIFO mode,  1: RX DMA, 2: TX DMA, 3: RX & TX DMA
    uint8_t    rateStep;             ///< sample counter
}UART_SettingType;

/* UART - Peripheral instance base addresses */
/** Peripheral UART1 base address */
#define UART1_BASE                                (0x40018000u)
/** Peripheral UART1 base pointer */
#define UART1                                     ((UART_Type *)UART1_BASE)

/** Peripheral UART2 base address */
#define UART2_BASE                                (0x40019000u)
/** Peripheral UART2 base pointer */
#define UART2                                     ((UART_Type *)UART2_BASE)

/** Peripheral UART3 base address */
#define UART3_BASE                                (0x4001a000u)
/** Peripheral UART3 base pointer */
#define UART3                                     ((UART_Type *)UART3_BASE)

/** Peripheral UART4 base address */
#define UART4_BASE                                (0x4001b000u)
/** Peripheral UART4 base pointer */
#define UART4                                     ((UART_Type *)UART4_BASE)

/** Peripheral UART5 base address */
#define UART5_BASE                                (0x4001c000u)
/** Peripheral UART5 base pointer */
#define UART5                                     ((UART_Type *)UART5_BASE)

/** Peripheral UART6 base address */
#define UART6_BASE                                (0x4001d000u)
/** Peripheral UART6 base pointer */
#define UART6                                     ((UART_Type *)UART6_BASE)

#define    PORT1        1
#define    PORT2        2
#define    PORT3        3
#define    PORT4        4
#define    PORT5        5
#define    PORT6        6

/** Array initializer of UART peripheral base pointers */
#define UART_BASES                                { UART1, UART2, UART3, UART4, UART5, UART6 }
//*****************************************************************************

/****************************************************************************/
/**
* UART_SetDivisor
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @param[in] div: UART divisor data
* @return    none
*
* @brief  Set UART Divisor Latch
*/
__STATIC_INLINE void UART_SetDivisor(UART_Type *UARTx, float div)
{
    uint32_t integerDiv = (uint64_t)div;
    uint32_t fracDiv = (uint32_t)((div - integerDiv) * 32);

    UARTx->UARTn_DLL = integerDiv & 0xFF;
    UARTx->UARTn_DLM = (integerDiv >> 8) & 0xFF;

    UARTx->UARTn_FRACDIV_L = fracDiv;
}

/**
* UART_SetSampleCounter
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @param[in] sampleCounter: UART Sample counter, value can be 0 to 3
* @return    none
*
* @brief  Set UART Sample counter
*/
__STATIC_INLINE void UART_SetSampleCounter(UART_Type *UARTx, uint8_t sampleCounter)
{
    UARTx->UARTn_RATE_STEP.SMP_CNT = (sampleCounter & 0x3);
}

/**
* UART_SetGuard
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @param[in] guardTime: UART GuardTime, value can be 0 to 15
* @return    none
*
* @brief  Set UART Guart Time
*/
__STATIC_INLINE void UART_SetGuard(UART_Type *UARTx, uint8_t guardTime)
{
    if (guardTime & GUARDEN)
    {
        UARTx->UARTn_GUARD.GUARD_EN = 1;
        UARTx->UARTn_GUARD.GUARD_CNT = (guardTime & GUARDCNT_MASK);
    }
    else
    {
        UARTx->UARTn_GUARD.GUARD_EN = 0;
        UARTx->UARTn_GUARD.GUARD_CNT = 0;
    }
}

/**
* UART_SetWordLen
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @param[in] bits: UART WordLen, value can be 5 to 9
* @return    none
*
* @brief  Set UART Word Length
*/
__STATIC_INLINE void UART_SetDataBits(UART_Type *UARTx, uint8_t bits)
{
    switch (bits)
    {
    case BIT5:
        UARTx->UARTn_LCR0.WLS1_WLS0 = 0;
        UARTx->UARTn_LCR1.WLS2      = 0;
        break;

    case BIT6:
        UARTx->UARTn_LCR0.WLS1_WLS0 = 1;
        UARTx->UARTn_LCR1.WLS2      = 0;
        break;

    case BIT7:
        UARTx->UARTn_LCR0.WLS1_WLS0 = 2;
        UARTx->UARTn_LCR1.WLS2      = 0;
        break;

    case BIT8:
        UARTx->UARTn_LCR0.WLS1_WLS0 = 3;
        UARTx->UARTn_LCR1.WLS2      = 0;
        break;

    case BIT9:
        UARTx->UARTn_LCR0.WLS1_WLS0 = 0;
        UARTx->UARTn_LCR1.WLS2      = 1;
        break;

		default:
        break;
    }
}

/**
* UART_SetParity
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @param[in] parity: UART parity set
*                  - 0:no parity
*                  - 1:ODD parity
*                  - 2:EVEN parity
* @return    none
*
* @brief  Set UART Parity
*/
__STATIC_INLINE void UART_SetParity(UART_Type *UARTx, uint8_t parity)
{
    switch (parity)
    {
    case ODD:
        UARTx->UARTn_LCR0.PEN = 1;
        UARTx->UARTn_LCR0.SP  = 0;
        UARTx->UARTn_LCR0.EPS = 0;
        break;

    case EVEN:
        UARTx->UARTn_LCR0.PEN = 1;
        UARTx->UARTn_LCR0.SP  = 0;
        UARTx->UARTn_LCR0.EPS = 1;
        break;

    case NOPARITY:
        //fall bellow
    default:
        UARTx->UARTn_LCR0.PEN = 0;
        UARTx->UARTn_LCR0.SP  = 0;
        UARTx->UARTn_LCR0.EPS = 0;
        break;
    }
}

/**
* UART_SetStopBit
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @param[in] stopBit: UART StopBit. value can be
*                   - 2:2 stop bit
*                   - others:1 stop bit
* @return    none
*
* @brief  Set UART stop bit
*/
__STATIC_INLINE void UART_SetStopBit(UART_Type *UARTx, uint8_t stopBit)
{
    if (stopBit == STOP_2BIT)
    {
        UARTx->UARTn_LCR0.STB = 1;
    }
    else
    {
        UARTx->UARTn_LCR0.STB = 0;
    }
}

/**
* UART_SetInvTx
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @param[in] InvTx: UART invTx. 1: inverse tx output  0: don't inverse tx output
* @return    none
*
* @brief  Set UART Inverse the tx output
*/
__STATIC_INLINE void UART_SetInvTx(UART_Type *UARTx, uint8_t invTx)
{
    if (invTx == 1)
    {
        UARTx->UARTn_LCR1.INVTX = 1;
    }
    else
    {
        UARTx->UARTn_LCR1.INVTX = 0;
    }
}

/**
* UART_SetInvRx
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @param[in] invRx: UART invRx. 1: inverse rx input  0: don't inverse rx input
* @return    none
*
* @brief  Set UART Inverse the rx input
*/
__STATIC_INLINE void UART_SetInvRx(UART_Type *UARTx, uint8_t invRx)
{
    if (invRx == 1)
    {
        UARTx->UARTn_LCR1.INVRX = 1;
    }
    else
    {
        UARTx->UARTn_LCR1.INVRX = 0;
    }
}

/**
* UART_SetLoop
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @param[in] Loop: UART loop, 1: control the uart into loop mode  0: for user normal use
* @return    none
*
* @brief  Set UART loop mode
*/
__STATIC_INLINE void UART_SetLoop(UART_Type *UARTx, uint8_t loop)
{
    if (loop == 1)
    {
        UARTx->UARTn_LCR1.Loop = 1;
    }
    else
    {
        UARTx->UARTn_LCR1.Loop = 0;
    }
}

/**
* UART_Set2ByteFIFO
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @param[in] fifoByteEn: UART FIFO2ByteEn. 1: enable both tx&rx fifo  0: disable both tx&rx fifo
* @return    none
*
* @brief  Set UART 2byte fifo enable
*/
__STATIC_INLINE void UART_Set2ByteFIFO(UART_Type *UARTx, uint8_t fifoByteEn)
{
    if (fifoByteEn == 1)
    {
        UARTx->UARTn_FCR.FIFOE = 1;
    }
    else
    {
        UARTx->UARTn_FCR.FIFOE = 0;
    }
}

/**
* UART_SetCTSRTS
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @param[in] RTSCTS: UART rtsCts, value can be 0 to 3
* @return    none
*
* @brief  Set UART RTS CTS
*/
__STATIC_INLINE void UART_SetCTSRTS(UART_Type *UARTx, uint8_t RTSCTS)
{
    switch (RTSCTS)
    {
    case RTSCTS_NONE:
        UARTx->UARTn_EFR.AUTO_RTS = 0;
        UARTx->UARTn_EFR.AUTO_CTS = 0;
        break;

    case RTS_ONLY:
        UARTx->UARTn_EFR.AUTO_RTS = 1;
        UARTx->UARTn_EFR.AUTO_CTS = 0;
        break;

    case CTS_ONLY:
        UARTx->UARTn_EFR.AUTO_RTS = 0;
        UARTx->UARTn_EFR.AUTO_CTS = 1;
        break;

    case RTS_CTS:
        UARTx->UARTn_EFR.AUTO_RTS = 1;
        UARTx->UARTn_EFR.AUTO_CTS = 1;
        break;

    default:
        break;
    }
}

/**
* UART_SetIntEn
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @param[in] intEn: UART intEn set
* @return    none
*
* @brief  Set UART interrupt enable
*/
__STATIC_INLINE void UART_SetIntEn(UART_Type *UARTx, uint8_t intEn)
{
    UARTx->UARTn_IER.ERXNE  = ((intEn>>0) & 0x1);
    UARTx->UARTn_IER.EPE    = ((intEn>>3) & 0x1);
    UARTx->UARTn_IER.EFE    = ((intEn>>4) & 0x1);
    UARTx->UARTn_IER.ENE    = ((intEn>>5) & 0x1);
    UARTx->UARTn_IER.EOEBI  = ((intEn>>6) & 0x1);
    UARTx->UARTn_IER.EDCTS  = ((intEn>>7) & 0x1);
}

/**
* UART_SetSleepEn
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @param[in] sleepEn: UART sleepEn.
*                 - 1:Activate hardware flow control according to software initial settings
*                     when the chip enters the sleep mode. Release the hardware flow
*                     when the chip wakes up.
*                 - 0:Does not deal with sleep mode indication signal
* @return    none
*
* @brief  Set UART sleep enable
*/
__STATIC_INLINE void UART_SetSleepEn(UART_Type *UARTx, uint8_t sleepEn)
{
    if (sleepEn)
    {
        UARTx->UARTn_SLEEP_EN.SLEEP_EN = 1;
    }
    else
    {
        UARTx->UARTn_SLEEP_EN.SLEEP_EN = 0;
    }
}

/**
* UART_EnableDMAMode
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @param[in] mode: UART DMA Enable set. value can be
*                - 0:both tx&rx transfer with normal mode
*                - 1:rx with dma mode and tx with normal mode
*                - 2:tx with dma mode and rx with normal mode
*                - 3:both tx&rx transfer with dma mode
* @return    none
*
* @brief  Set UART DMA enable
*/
__STATIC_INLINE void UART_EnableDMA(UART_Type *UARTx, uint8_t mode)
{
    UARTx->UARTn_DMA_EN.RX_DMA_EN = ((mode>>0) & 0x1);
    UARTx->UARTn_DMA_EN.TX_DMA_EN = ((mode>>1) & 0x1);
}

/**
* UART_SetRS485CR
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @param[in] rs485CR: UART RS485CR. the corresponding control bit means
*                   - bit7: enable rs485 or disable
*                   - bit5: inverse or don't inverse the polarity of rts_n
*                   - bit4: delay insert between the last stop bit
* @return    none
*
* @brief  Set UART rs485 Control
*/
__STATIC_INLINE void UART_SetRS485CR(UART_Type *UARTx, uint8_t rs485CR)
{
    UARTx->UARTn_RS485CR.RS485EN   = ((rs485CR>>7) & 0x1);
    UARTx->UARTn_RS485CR.INVPOL    = ((rs485CR>>5) & 0x1);
    UARTx->UARTn_RS485CR.DLYEN     = ((rs485CR>>4) & 0x1);
}

/**
* UART_SetSlaAddr
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @param[in] slaveAddr: UART slave address. value can be
*                     - 7:0: 0~255 as a slave address for RS485 when rs485en=1
*                     - 3:0: 0~15 as a slave address for Mulprocessor communication when mulcomen =1
* @return    none
*
* @brief  Set UART slave address
*/
__STATIC_INLINE void UART_SetSlaveAddr(UART_Type *UARTx, uint8_t slaveAddr)
{
    UARTx->UARTn_SLADDR = slaveAddr;
}

/**
* UART_SetRS485Cnt
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @param[in] counter: UART Counter. value can be
*                   - 7:0: 0~255 bits time for time delay in RS485 mode
* @return    none
*
* @brief  Set UART delay time in RS485 mode
*/
__STATIC_INLINE void UART_SetRS485Cnt(UART_Type *UARTx, uint8_t counter)
{
    UARTx->UARTn_CNTR = counter;
}

/**
* UART_SetMulComEn
*
* @param[in] UARTx: UART type pointer, x value can be 1 to 6
* @param[in] mulComEn: UART Multi communication enable
* @return    none
*
* @brief  Set UART multiprocessor communication enable.
*/
__STATIC_INLINE void UART_SetMulComEn(UART_Type *UARTx, uint8_t mulComEn)
{
    if (mulComEn == 1)
    {
        UARTx->UARTn_MULCOMCR.MULCOMEN = 1;
    }
    else
    {
        UARTx->UARTn_MULCOMCR.MULCOMEN = 0;
    }
}


/**
* UART_SetIdleEn
*
* @param[in] UARTx: UART type pointer
* @param[in] idleEn: 1:idle interrupt enable  1:idle interrupt disable
* @return    none
*
* @brief  Set UART idle interrupt enable.must set MULCOMEN=1
*/
__STATIC_INLINE void UART_SetIdleEn(UART_Type *UARTx, uint8_t idleEn)
{
    if (idleEn == 1)
    {
        UARTx->UARTn_MULCOMCR.IDLEIE = 1;
    }
    else
    {
        UARTx->UARTn_MULCOMCR.IDLEIE = 0;
    }
}

/**
* UART_MulComIsIdle
*
* @param[in] UARTx: UART type pointer, x can be 1 to 6
* @return    mul com idle line detect
*
* @brief  Set UART Rx data is ready
*/
__STATIC_INLINE uint32_t UART_IsIdle(UART_Type *UARTx)
{
    return (uint32_t)UARTx->UARTn_LSR1.IDLE;
}

/**
* UART_SetLIN
*
* @param[in] UARTx: UART type pointer, x can be 1 to 6
* @param[in] linCtrl: UART linCtrl. the corresponding control bit means
*                   - bit7: LIN Mode enable
*                   - bit6: LIN Break character detect interrupt enable
*                   - bit5: LIN Mode break detect length  1:11bits  0:10bits
*                   - bit3: 1:0x55 used to auto baud rate detection  0: 0X55 not used to auto baud rate detection
* @return    none
*
* @brief  Set UART LIN control
*/
__STATIC_INLINE void UART_SetLIN(UART_Type *UARTx, uint8_t linCtrl)
{
    if (UARTx == UART6)
    {
        UARTx->UARTn_LINCR.LABAUDEN = ((linCtrl>>3) & 0x1);
        UARTx->UARTn_LINCR.LBRKDL   = ((linCtrl>>5) & 0x1);
        UARTx->UARTn_LINCR.LBRKIE   = ((linCtrl>>6) & 0x1);
        UARTx->UARTn_LINCR.LINEN    = ((linCtrl>>7) & 0x1);
    }
}

/**
* UART_RxIsDataReady
*
* @param[in] UARTx: UART type pointer, x can be 1 to 6
* @return    0:no date in buff or fifo,  1:RX buffer becoming full or RX FIFO not empty
*
* @brief  check if rx buffer get new data
*/
__STATIC_INLINE uint32_t UART_RxIsDataReady(UART_Type *UARTx)
{
    return (uint32_t)UARTx->UARTn_LSR0.DR;
}

/**
* UART_TxIsEmpty
*
* @param[in] UARTx: UART type pointer, x can be 1 to 6
* @return    0:TX holding register or FIFO is not empty   1:TX holding register or FIFO is empty
*
* @brief  Set UART Tx buffer is empty
*/
__STATIC_INLINE uint32_t UART_TxIsEmpty(UART_Type *UARTx)
{
    return (uint32_t)UARTx->UARTn_LSR0.THRE;
}

/**
* UART_TxIsFinished
*
* @param[in] UARTx: UART type pointer, x can be 1 to 6
* @return    0:transmitter has not finished,   1:transmitter has finished
*
* @brief  Set UART Tx Has Finished
*/
__STATIC_INLINE uint32_t UART_TxIsFinished(UART_Type *UARTx)
{
    return (uint32_t)UARTx->UARTn_LSR0.TC;
}


/**
* UART_SendData
*
* @param[in] UARTx: UART type pointer, x can be 1 to 6
* @param[in] data: data will be send
* @return    0:suaccess   -1:fail
*
* @brief  Set UART Send Data
*/
__STATIC_INLINE int32_t UART_SendData(UART_Type *UARTx, uint16_t data)
{
    uint32_t i = 0;

    for (i = 0; i < 0xFFF; i++)
    {
        if (UART_TxIsEmpty(UARTx))
        {
            UARTx->UARTn_RBR_THR = (data & (0x01FF));
            return 0;
        }
    }

    return -1;
}

/**
* UART_ReceiveData
*
* @param[in] UARTx: UART type pointer, x can be 1 to 6
* @return    UART received data
*
* @brief  Get UART received Data
*/
__STATIC_INLINE uint16_t UART_ReceiveData(UART_Type *UARTx)
{
    return (uint16_t)(UARTx->UARTn_RBR_THR & (0x01FF));
}

/**
* UART_EnableTX
*
* @param[in] UARTx: UART type pointer, x can be 1 to 6
* @param[in] enable: Enable uart tx function
* @return    always 0
*
* @brief  Enable UART TX
*/
__STATIC_INLINE int32_t UART_EnableTX(UART_Type *UARTx, uint8_t enable)
{
    UARTx->UARTn_LCR1.TXEN = enable;
    return 0;
}

/**
* UART_EnableRX
*
* @param[in] UARTx: UART type pointer, x can be 1 to 6
* @param[in] enable: Enable uart rx function
* @return    always 0
*
* @brief  Enable UART RX
*/
__STATIC_INLINE int32_t UART_EnableRX(UART_Type *UARTx, uint8_t enable)
{
    UARTx->UARTn_LCR1.RXEN = enable;
    return 0;
}

/**
* UART_IsLINBreak
*
* @param[in] UARTx: UART type pointer, x can be 1 to 6
* @return    detect lin break flag
*
* @brief detect lin break flag
*/
__STATIC_INLINE uint32_t UART_IsLINBreak(UART_Type *UARTx)
{
    if (UARTx == UART6)
    {
        return (uint32_t)UARTx->UARTn_LSR1.FBRK;
    }
    else
    {
        return (uint32_t)0;
    }
}

/**
* UART_ClearLINBreak
*
* @param[in] UARTx: UART type pointer, x can be 1 to 6
* @return    none
*
* @brief clear lin break flag
*/
__STATIC_INLINE void UART_ClearLINBreak(UART_Type *UARTx)
{
    if (UARTx == UART6)
    {
        UARTx->UARTn_LSR1.FBRK = 1;
    }
}

/**
* UART_SendLINBreak
*
* @param[in] UARTx: UART type pointer, x can be 1 to 6
* @return    none
*
* @brief Send lin break
*/
__STATIC_INLINE void UART_SendLINBreak(UART_Type *UARTx)
{
    if (UARTx == UART6)
    {
        UARTx->UARTn_LINCR.SDBRK = 1;
    }
}

/**
* UART_SetRxIntEn
*
* @param[in] UARTx: UART type pointer, x can be 1 to 6
* @param[in] enable: 1:Enable  0:Disable
* @return : none
*
* @brief Enable rx buffer not empty interrupt
*/
__STATIC_INLINE void UART_SetRxIntEn(UART_Type *UARTx, uint8_t enable)
{
    if (enable)
    {
        UARTx->UARTn_IER.ERXNE = 1;
    }
    else
    {
        UARTx->UARTn_IER.ERXNE = 0;
    }
}

/**
* UART_SetTxIntEn
*
* @param[in] UARTx: UART type pointer, x can be 1 to 6
* @param[in] enable: 1:Enable  0:Disable
* @return    none
*
* @brief Enable tx holding register is empty interrupt
*/
__STATIC_INLINE void UART_SetTxIntEn(UART_Type *UARTx, uint8_t enable)
{
    if (enable)
    {
        UARTx->UARTn_IER.ETXE  = 1;
    }
    else
    {
        UARTx->UARTn_IER.ETXE = 0;
    }
}

typedef struct _UART_DMA_INFO
{
    DMA_Type* txCH;            /*DMA Tx Channel*/
    DMA_Type* rxCH;            /*DMA Rx Channel*/
    IRQn_Type   txDMAIRQ;        /*DMA Tx Channel IRQ Number*/
    IRQn_Type   rxDMAIRQ;        /*DMA Rx Channel IRQ Number*/
}UART_DMA_INFO;

const UART_DMA_INFO * UART_GetDMAInfo(uint8_t uartIndex);

/******************************************************************************
* Global functions
******************************************************************************/
__STATIC_INLINE void UART_SetDivisor(UART_Type *UARTx, float div);
__STATIC_INLINE void UART_SetFrac(UART_Type *UARTx, uint8_t uartFracL, uint8_t uartFracM);
__STATIC_INLINE void UART_SetGuard(UART_Type *UARTx, uint8_t guardTime);
__STATIC_INLINE void UART_SetDataBits(UART_Type *UARTx, uint8_t bits);
__STATIC_INLINE void UART_SetParity(UART_Type *UARTx, uint8_t parity);
__STATIC_INLINE void UART_SetStopBit(UART_Type *UARTx, uint8_t stopBit);
__STATIC_INLINE void UART_SetInvTx(UART_Type *UARTx, uint8_t invTx);
__STATIC_INLINE void UART_SetInvRx(UART_Type *UARTx, uint8_t invRx);
__STATIC_INLINE void UART_SetLoop(UART_Type *UARTx, uint8_t loop);
__STATIC_INLINE void UART_Set2ByteFIFO(UART_Type *UARTx, uint8_t fifoByteEn);
__STATIC_INLINE void UART_SetCTSRTS(UART_Type *UARTx, uint8_t rtscts);
__STATIC_INLINE void UART_SetIntEn(UART_Type *UARTx, uint8_t intEn);
__STATIC_INLINE void UART_SetSleepEn(UART_Type *UARTx, uint8_t sleepEn);
__STATIC_INLINE void UART_EnableDMA(UART_Type *UARTx, uint8_t dmaEn);
__STATIC_INLINE void UART_SetRS485CR(UART_Type *UARTx, uint8_t rs485CR);
__STATIC_INLINE void UART_SetSlaveAddr(UART_Type *UARTx, uint8_t slaveAddr);
__STATIC_INLINE void UART_SetRS485Cnt(UART_Type *UARTx, uint8_t counter);
__STATIC_INLINE void UART_SetMulComEn(UART_Type *UARTx, uint8_t mulComEn);
__STATIC_INLINE void UART_SetIdleEn(UART_Type *UARTx, uint8_t idleEn);
__STATIC_INLINE uint32_t UART_IsIdle(UART_Type *UARTx);

__STATIC_INLINE void UART_SetLIN(UART_Type *UARTx, uint8_t linCtrl);
__STATIC_INLINE uint32_t UART_RxIsDataReady(UART_Type *UARTx);
__STATIC_INLINE uint32_t UART_TxIsEmpty(UART_Type *UARTx);

//**************************************************
void UART1_IRQHandler(void);
void UART2_IRQHandler(void);
void UART3_IRQHandler(void);
void UART4_IRQHandler(void);
void UART5_IRQHandler(void);
void UART6_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif


