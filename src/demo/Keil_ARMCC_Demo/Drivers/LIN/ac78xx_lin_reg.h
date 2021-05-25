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
#ifndef _AC78XX_LIN_REG_H_
#define _AC78XX_LIN_REG_H_

#include "ac78xx.h"


#ifdef __cplusplus
extern "C" {
#endif

#pragma anon_unions
///< LIN register define structure
typedef volatile struct
{
    union {
        uint32_t LINSYS;
        struct {
            uint32_t LM: 2;     ///< LIN mode: 0->normal 1->initial 2->sleep mode
            uint32_t : 30;
        } LINSYS_B;
    };              /* [0x00] LIN system control register */

    union {
        uint32_t LINCTRL1;
        struct {
            uint32_t SM: 1;     ///< Slave mode: 0->master 1->slave mode
            uint32_t LBM: 1;    ///< Loopback mode: 0->disable 1->enable
            uint32_t STM: 1;    ///< Selftest mode: 0->disable 1->enable
            uint32_t SCM: 1;    ///< Software control mode: 0->disable 1->enable
            uint32_t BLT: 1;    ///< Break length threshold: 0->11bit 1->10bit
            uint32_t : 2;
            uint32_t : 1;
            uint32_t BTL: 4;    ///< Break TX length: (0 - 15)->(10 - 25bit)
            uint32_t ATWU: 1;   ///< Auto wakeup: 0->disable 1->enable
            uint32_t RSE: 1;    ///< Re-synchronization : 0->disable 1->enable
            uint32_t MCS: 1;    ///< Manual Checksum: 0->disable 1->enable
            uint32_t BDL: 1;    ///< Break delimiter length: 0->1bit 1->4bit
            uint32_t HIL: 2;    ///< Header inter length: (0 - 3)->(0 - 8bit)
            uint32_t RSL: 2;    ///< Response space length: (0 - 3)->(1 - 8bit)
            uint32_t RIL: 2;    ///< Response inter length: (0 - 3)->(0 - 4bit)
            uint32_t : 1;
            uint32_t DIOB: 1;   ///< Disable IDLE on bit error: 0->enable 1->disable
            uint32_t : 8;
        } LINCTRL1_B;
    };            /*  [0x04] LIN Control Register 1 */

    union {
        uint32_t LINCTRL2;
        struct {
            uint32_t HTR: 1;    ///< Header  TX request: write 1
            uint32_t TAR: 1;    ///< TX abort request: write 1
            uint32_t RTR: 1;    ///< Response TX request: write 1
            uint32_t RDR: 1;    ///< Response RX discard: write 1
            uint32_t WUTR: 1;   ///< Wakeup TX request: write 1
            uint32_t : 27;
        } LINCTRL2_B;
    };            /* [0x08] LIN Control Register 2 */

    union {
        uint32_t LINIEN;
        struct {
            uint32_t HRIE: 1;   ///< Header received interrupt enable: 0->disable 1->enable
            uint32_t RTIE: 1;   ///< Response transmitted interrupt enable: 0->disable 1->enable
            uint32_t RRIE: 1;   ///< Response received interrupt enable: 0->disable 1->enable
            uint32_t : 2;
            uint32_t WUIE: 1;   ///< Wakeup interrupt enable: 0->disable 1->enable
            uint32_t : 2;
            uint32_t FEIE: 1;   ///< Framing error interrupt enable: 0->disable 1->enable
            uint32_t BOIE: 1;   ///< Buffer overrun interrupt enable: 0->disable 1->enable
            uint32_t : 1;
            uint32_t HEIE: 1;   ///< Header error interrupt enable: 0->disable 1->enable
            uint32_t CEIE: 1;   ///< Checksum error interrupt enable: 0->disable 1->enable
            uint32_t BEIE: 1;   ///< Bit error interrupt enable: 0->disable 1->enable
            uint32_t TOIE: 1;   ///< Timeout error interrupt enable: 0->disable 1->enable
            uint32_t LZIE: 1;   ///< Long zero error interrupt enable: 0->disable 1->enable
            uint32_t : 16;
        } LINIEN_B;
    };              /* [0x0C] LIN Interrupt Enable Register */

    union {
        uint32_t LINSTS;
        struct {
            uint32_t HRF: 1;    ///< Header received flag
            uint32_t RTF: 1;    ///< Response transmitted flag
            uint32_t RRF: 1;    ///< Response received flag
            uint32_t WUF: 1;    ///< Wakeup flag
            uint32_t PS: 1;     ///< PIN status
            uint32_t RTIP: 1;   ///< Response TX in progress
            uint32_t RRIP: 1;   ///< Response RX in progress
            uint32_t : 1;
            uint32_t STS: 4;    ///< LIN status
            uint32_t : 20;
        } LINSTS_B;
    };              /* [0x10] LIN Status Register */

    union {
        uint32_t LINESTS;
        struct {
            uint32_t NF: 1;     ///< Noise flag
            uint32_t BOF: 1;    ///< Buffer overrun flag
            uint32_t FEF: 1;    ///< Framing error flag
            uint32_t IPEF: 1;   ///< Identifier parity error flag
            uint32_t BDEF: 1;   ///< Break delimiter error flag
            uint32_t SFEF: 1;   ///< Sync field error flag
            uint32_t CEF: 1;    ///< Checksum error flag
            uint32_t BEF: 1;    ///< Bit error flag
            uint32_t TOEF: 1;   ///< Timeout error flag
            uint32_t LZEF: 1;   ///< Long zero error flag
            uint32_t : 22;
        } LINESTS_B;
    };             /* [0x14] LIN Error Status Register */

    union {
        uint32_t LINTO1;
        struct {
            uint32_t HTOV: 6;   ///< Header timout value
            uint32_t : 26;
        } LINTO1_B;
    };              /* [0x18] LIN Timeout Control Register 1*/

    union {
        uint32_t LINTO2;
        struct {
            uint32_t TOEN: 1;   ///< Time out enable: 0->disable 1->enable
            uint32_t : 1;
            uint32_t : 30;
        } LINTO2_B;
    };              /* [0x1C] LIN Timeout Control Register 2*/

    union {
        uint32_t LINIBR;
        struct {
            uint32_t IBR: 12;   ///< Integer Baud Rate
            uint32_t : 20;
        } LINIBR_B;
    };              /* [0x20] LIN Integer Baud Rate Register */

    union {
        uint32_t LINFBR;
        struct {
            uint32_t FBR: 4;    ///< Fractional Baud Rate
            uint32_t : 28;
        } LINFBR_B;
    };              /* [0x24] LIN Fractional Baud Rate Register */

    union {
        uint32_t LINCS;
        struct {
            uint32_t CS: 8;     ///< Checksum
            uint32_t : 24;
        } LINCS_B;
    };               /* [0x28] LIN Checksum Field Register */

    union {
        uint32_t LINFRM;
        struct {
            uint32_t ID: 6;     ///< Identifier
            uint32_t : 2;
            uint32_t CST: 1;    ///< checksum type
            uint32_t DIR: 1;    ///< Direction
            uint32_t DFL: 3;    ///< Data Field Length
            uint32_t : 19;
        } LINFRM_B;
    };              /* [0x2C] LIN Frame Control Register */

    union {
        uint32_t BDLR;
        struct {
            uint32_t DATA0: 8;  ///< data0
            uint32_t DATA1: 8;  ///< data1
            uint32_t DATA2: 8;  ///< data2
            uint32_t DATA3: 8;  ///< data3
        } BDLR_B;
    };                /* [0x30] LIN Buffer Data Low Register */

    union {
        uint32_t BDHR;
        struct {
            uint32_t DATA4: 8;  ///< data4
            uint32_t DATA5: 8;  ///< data5
            uint32_t DATA6: 8;  ///< data6
            uint32_t DATA7: 8;  ///< data7
        } BDHR_B;
    };                /* [0x34] LIN Buffer Data High Register */

    union {
        uint32_t IFEN;
        struct {
            uint32_t EN: 16;    ///< Filter enable
            uint32_t : 16;
        } IFEN_B;
    };                /* [0x38] LIN Identifier Filter Enable Register */

    union {
        uint32_t IFMR;
        struct {
            uint32_t IFM: 8;    ///< Filter mode: 0->filter mode 1->mask mode
            uint32_t : 24;
        } IFMR_B;
    };                /* [0x3C] LIN Identifier Filter Mode Register */

    union {
        uint32_t IFMI;
        struct {
            uint32_t IFMI: 5;   ///< Filter match index
            uint32_t : 27;
        } IFMI_B;
    };                /* [0x40] LIN Identifier Filter Match Index Register */

    union {
        uint32_t IFCR0;
        struct {
            uint32_t ID: 6;     ///< Identifier
            uint32_t : 2;
            uint32_t CST: 1;    ///< checksum type
            uint32_t DIR: 1;    ///< Direction
            uint32_t DFL: 3;    ///< Data Field Length
            uint32_t : 19;
        } IFCR0_B;
    };               /* [0x44] LIN Identifier Filter Control Register 0 */

    union {
        uint32_t IFCR1;
        struct {
            uint32_t ID: 6;     ///< Identifier
            uint32_t : 2;
            uint32_t CST: 1;    ///< checksum type
            uint32_t DIR: 1;    ///< Direction
            uint32_t DFL: 3;    ///< Data Field Length
            uint32_t : 19;
        } IFCR1_B;
    };               /* [0x48] LIN Identifier Filter Control Register 1 */

    union {
        uint32_t IFCR2;
        struct {
            uint32_t ID: 6;     ///< Identifier
            uint32_t : 2;
            uint32_t CST: 1;    ///< checksum type
            uint32_t DIR: 1;    ///< Direction
            uint32_t DFL: 3;    ///< Data Field Length
            uint32_t : 19;
        } IFCR2_B;
    };               /* [0x4C] LIN Identifier Filter Control Register 2 */

    union {
        uint32_t IFCR3;
        struct {
            uint32_t ID: 6;     ///< Identifier
            uint32_t : 2;
            uint32_t CST: 1;    ///< checksum type
            uint32_t DIR: 1;    ///< Direction
            uint32_t DFL: 3;    ///< Data Field Length
            uint32_t : 19;
        } IFCR3_B;
    };               /* [0x50] LIN Identifier Filter Control Register 3 */

    union {
        uint32_t IFCR4;
        struct {
            uint32_t ID: 6;     ///< Identifier
            uint32_t : 2;
            uint32_t CST: 1;    ///< checksum type
            uint32_t DIR: 1;    ///< Direction
            uint32_t DFL: 3;    ///< Data Field Length
            uint32_t : 19;
        } IFCR4_B;
    };               /* [0x54] LIN Identifier Filter Control Register 4 */

    union {
        uint32_t IFCR5;
        struct {
            uint32_t ID: 6;     ///< Identifier
            uint32_t : 2;
            uint32_t CST: 1;    ///< checksum type
            uint32_t DIR: 1;    ///< Direction
            uint32_t DFL: 3;    ///< Data Field Length
            uint32_t : 19;
        } IFCR5_B;
    };               /* [0x58] LIN Identifier Filter Control Register 5 */

    union {
        uint32_t IFCR6;
        struct {
            uint32_t ID: 6;     ///< Identifier
            uint32_t : 2;
            uint32_t CST: 1;    ///< checksum type
            uint32_t DIR: 1;    ///< Direction
            uint32_t DFL: 3;    ///< Data Field Length
            uint32_t : 19;
        } IFCR6_B;
    };               /* [0x5C] LIN Identifier Filter Control Register 6 */

    union {
        uint32_t IFCR7;
        struct {
            uint32_t ID: 6;     ///< Identifier
            uint32_t : 2;
            uint32_t CST: 1;    ///< checksum type
            uint32_t DIR: 1;    ///< Direction
            uint32_t DFL: 3;    ///< Data Field Length
            uint32_t : 19;
        } IFCR7_B;
    };               /* [0x60] LIN Identifier Filter Control Register 7 */

    union {
        uint32_t IFCR8;
        struct {
            uint32_t ID: 6;     ///< Identifier
            uint32_t : 2;
            uint32_t CST: 1;    ///< checksum type
            uint32_t DIR: 1;    ///< Direction
            uint32_t DFL: 3;    ///< Data Field Length
            uint32_t : 19;
        } IFCR8_B;
    };               /* [0x64] LIN Identifier Filter Control Register 8 */

    union {
        uint32_t IFCR9;
        struct {
            uint32_t ID: 6;     ///< Identifier
            uint32_t : 2;
            uint32_t CST: 1;    ///< checksum type
            uint32_t DIR: 1;    ///< Direction
            uint32_t DFL: 3;    ///< Data Field Length
            uint32_t : 19;
        } IFCR9_B;
    };               /* [0x68] LIN Identifier Filter Control Register 9 */

    union {
        uint32_t IFCR10;
        struct {
            uint32_t ID: 6;     ///< Identifier
            uint32_t : 2;
            uint32_t CST: 1;    ///< checksum type
            uint32_t DIR: 1;    ///< Direction
            uint32_t DFL: 3;    ///< Data Field Length
            uint32_t : 19;
        } IFCR10_B;
    };              /* [0x6C] LIN Identifier Filter Control Register 10 */

    union {
        uint32_t IFCR11;
        struct {
            uint32_t ID: 6;     ///< Identifier
            uint32_t : 2;
            uint32_t CST: 1;    ///< checksum type
            uint32_t DIR: 1;    ///< Direction
            uint32_t DFL: 3;    ///< Data Field Length
            uint32_t : 19;
        } IFCR11_B;
    };              /* [0x70] LIN Identifier Filter Control Register 11 */

    union {
        uint32_t IFCR12;
        struct {
            uint32_t ID: 6;     ///< Identifier
            uint32_t : 2;
            uint32_t CST: 1;    ///< checksum type
            uint32_t DIR: 1;    ///< Direction
            uint32_t DFL: 3;    ///< Data Field Length
            uint32_t : 19;
        } IFCR12_B;
    };              /* [0x74] LIN Identifier Filter Control Register 12 */

    union {
        uint32_t IFCR13;
        struct {
            uint32_t ID: 6;     ///< Identifier
            uint32_t : 2;
            uint32_t CST: 1;    ///< checksum type
            uint32_t DIR: 1;    ///< Direction
            uint32_t DFL: 3;    ///< Data Field Length
            uint32_t : 19;
        } IFCR13_B;
    };              /* [0x78] LIN Identifier Filter Control Register 13 */

    union {
        uint32_t IFCR14;
        struct {
            uint32_t ID: 6;     ///< Identifier
            uint32_t : 2;
            uint32_t CST: 1;    ///< checksum type
            uint32_t DIR: 1;    ///< Direction
            uint32_t DFL: 3;    ///< Data Field Length
            uint32_t : 19;
        } IFCR14_B;
    };              /* [0x7C] LIN Identifier Filter Control Register 14 */

    union {
        uint32_t IFCR15;
        struct {
            uint32_t ID: 6;     ///< Identifier
            uint32_t : 2;
            uint32_t CST: 1;    ///< checksum type
            uint32_t DIR: 1;    ///< Direction
            uint32_t DFL: 3;    ///< Data Field Length
            uint32_t : 19;
        } IFCR15_B;
    };              /* [0x80] LIN Identifier Filter Control Register 15 */
} LIN_Type;

#define LIN0             ((LIN_Type *)0x40007000)   ///< LIN module base address
#define LIN_SRC_CLOCK    APB_BUS_FREQ               ///< LIN source clock (default 48MHz)

// LIN control
#define    HEAD_TX_REQ          (1 << 0)            ///< request send header
#define    RESP_TX_REQ          (1 << 2)            ///< request send response
#define    RESP_DIS_REQ         (1 << 3)            ///< discard response
#define    WAKEUP_REQ           (1 << 4)            ///< request wakeup response

// LIN status
#define    HEAD_RX_FLAG         (1 << 0)            ///< header receive flag
#define    RESP_TX_FLAG         (1 << 1)            ///< response transmit flag
#define    RESP_RX_FLAG         (1 << 2)            ///< response receive flag
#define    WAKEUP_FLAG          (1 << 3)            ///< wakeup flag
#define    PIN_STATUS           (1 << 4)            ///< pin status
#define    RESP_TX              (1 << 5)            ///< response transmit status
#define    RESP_RX              (1 << 6)            ///< response receive status
#define    LIN_STATUS_POS       8

#define    LIN_BREAK_LENGTH     13                  ///< break length default 13 bit (range 10 -25bit)
#define    LIN_BREAK_THRESHOLD  0                   ///< Break threshold length 11bit (11 / 10)

// Frame control
#define    BIDR_ID              0                   ///< Identifier offset
#define    BIDR_CST             8                   ///< Checksum type offset
#define    BIDR_DIR             9                   ///< Direction offset
#define    BIDR_DFL             10                  ///< Data length offset

// Checksum type
#define    ENHANCED_CHECKSUM    0                   ///< Enhanced checksum type
#define    CLASSIC_CHECKSUM     1                   ///< Classic checksum type

// Direction
#define    DIR_RX               0                   ///< receive direction
#define    DIR_TX               1                   ///< transmit direction

// Node mode
#define    MASTER_MODE          0                   ///< master mode
#define    SLAVE_MODE           1                   ///< slave mode

// Checksum mode
#define    AUTO_CHECKSUM        0                   ///< auto checksum mode
#define    MANUAL_CHECKSUM      1                   ///< manual checksum mode

// Defines for LIN node states
#define    NORMAL_MODE          0                   ///< normal mode
#define    INIT_MODE            1                   ///< init mode
#define    SLEEP_MODE           2                   ///< sleep mode

// Interrupt enable bit position
#define    HEAD_RX_IRQ_EN_POS          0            ///< header receive interrupt enable bit offset
#define    RESP_TX_IRQ_EN_POS          1            ///< response transmit interrupt enable bit offset
#define    RESP_RX_IRQ_EN_POS          2            ///< response receive interrupt enable bit offset
#define    WAKEUP_IRQ_EN_POS           5            ///< wakeup interrupt enable bit offset
#define    FRAME_ERR_IRQ_EN_POS        8            ///< frame error interrupt enable bit offset
#define    BUF_OVRUN_IRQ_EN_POS        9            ///< buffer overrun interrupt enable bit offset
#define    HEAD_RX_ERR_IRQ_EN_POS      11           ///< header error interrupt enable bit offset
#define    CS_ERR_IRQ_EN_POS           12           ///< checksum error interrupt enable bit offset
#define    BIT_ERR_IRQ_EN_POS          13           ///< bit error interrupt enable bit offset
#define    TIMEOUT_ERR_IRQ_EN_POS      14           ///< timeout interrupt enable bit offset
#define    LONG0_ERR_IRQ_EN_POS        15           ///< long zero error interrupt enable bit offset

// Interrupt flag
#define    NOISE_FLAG                  (1 << 0)     ///< noise flag
#define    BUFFER_OVERRUN_FLAG         (1 << 1)     ///< buffer overrun flag
#define    FRAME_ERROR_FLAG            (1 << 2)     ///< frame error flag
#define    PARITY_ERROR_FLAG           (1 << 3)     ///< parity error flag
#define    DELIMITER_ERROR_FLAG        (1 << 4)     ///< delimiter error flag
#define    SYNC_ERROR_FLAG             (1 << 5)     ///< sync error flag
#define    CHECKSUM_ERROR_FLAG         (1 << 6)     ///< checksum error flag
#define    BIT_ERROR_FLAG              (1 << 7)     ///< bit error flag
#define    TIMEOUT_ERROR_FLAG          (1 << 8)     ///< timeout error flag
#define    LONG0_ERROR_FLAG            (1 << 9)     ///< long zero error flag


#define __STATIC_INLINE static __inline
/**
 * LIN_InitMode
 *
 * @param[in]  mode: LIN mode
 * @return : none
 *
 * @brief  Init LIN mode (NORMAL, INIT, SLEEP)
 */
__STATIC_INLINE void LIN_InitMode(uint32_t mode)
{
    if (mode <= SLEEP_MODE)
    {
        DEBUGMSG(DEBUG_ZONE_INFO, ("[LIN]mode:%d\r\n", mode));
        if (mode == SLEEP_MODE)
        {
            LIN0->LINIEN_B.WUIE = 1;
        }
        else
        {
            LIN0->LINIEN_B.WUIE = 0;
        }
        LIN0->LINSYS_B.LM = mode;
    }
}

/**
 * LIN_SetMode
 *
 * @param[in]  mode: master or slave mode
 * @return : none
 *
 * @brief  Set master or slave mode
 */
__STATIC_INLINE void LIN_SetMode(uint32_t mode)
{
    if (MASTER_MODE == mode)
    {
        LIN0->LINCTRL1_B.SM = 0;  // Master Mode
    }
    else
    {
        LIN0->LINCTRL1_B.SM = 1;  // Slave Mode
    }
}

/**
 * LIN_SetBaudrate
 *
 * @param[in]  baudrate: baud rate
 * @return : none
 *
 * @brief  Set LIN baud rate
 */
__STATIC_INLINE void LIN_SetBaudrate(uint32_t baudrate)
{
    uint32_t integer = 0, fraction = 0, i = 0, temp = 0;

    integer = ((uint32_t)APB_BUS_FREQ / baudrate) >> 4U;
    for (i = 0U; i < 16U; i++)
    {
        temp = (uint32_t)APB_BUS_FREQ / ((integer << 4U ) + i);
        if (temp >= baudrate)
        {
            fraction = i;
        }
    }

    LIN0->LINFBR_B.FBR = fraction;
    LIN0->LINIBR_B.IBR = integer;
}

/**
 * LIN_TxHeader
 *
 * @param[in]  frame: frame infomation
 * @return : none
 *
 * @brief  Send LIN header
 */
__STATIC_INLINE void LIN_TxHeader(uint32_t frame)
{
    // Configure BIDR
    LIN0->LINFRM = frame;

    // Request send Header
    LIN0->LINCTRL2 = HEAD_TX_REQ;
}

/**
 * LIN_WriteBuffer
 *
 * @param[in]  data: data buffer
 * @return : none
 *
 * @brief  Write data to buffer
 */
__STATIC_INLINE void LIN_WriteBuffer(uint8_t *data)
{
    LIN0->BDLR = *(uint32_t *)data;
    LIN0->BDHR = *(uint32_t *)(data + 4);
}

/**
 * LIN_ReadBuffer
 *
 * @param[in]  data: data buffer
 * @return : none
 *
 * @brief  Read data from buffer
 */
__STATIC_INLINE void LIN_ReadBuffer(uint8_t *data)
{
    *(uint32_t *)data = LIN0->BDLR;
    *(uint32_t *)(data + 4) = LIN0->BDHR;
}

/**
 * LIN_SendData
 *
 * @param[in] : none
 * @return : none
 *
 * @brief  Request send data
 */
__STATIC_INLINE void LIN_SendData(void)
{
    LIN0->LINCTRL2 = RESP_TX_REQ;
}

/**
 * LIN_TxWakeup
 *
 * @param[in]  data: wake up data
 * @return : none
 *
 * @brief  Send a wake up signal
 */
__STATIC_INLINE void LIN_TxWakeup(uint32_t data)
{
    if (LIN0->LINSYS_B.LM == SLEEP_MODE)
    {
        LIN0->LINSYS_B.LM = NORMAL_MODE;
    }

    DEBUGMSG(DEBUG_ZONE_INFO, ("[LIN]Send wakeup\r\n"));
    // Configure Wake-up character
    LIN0->BDLR = data;

    // Request send a Wake-up signal
    LIN0->LINCTRL2 = WAKEUP_REQ;
}

/**
 * LIN_DiscardResponse
 *
 * @param[in] : none
 * @return : none
 *
 * @brief  discard response request for software filter
 */
__STATIC_INLINE void LIN_DiscardResponse(void)
{
    LIN0->LINCTRL2 = RESP_DIS_REQ;
}

/**
 * LIN_SetFilterMode
 *
 * @param[in]  mode: filter mode
 * @return : none
 *
 * @brief  Set LIN filter
 */
__STATIC_INLINE void LIN_SetFilterMode(uint8_t mode)
{
    LIN0->IFMR_B.IFM = mode;
}

/**
 * LIN_Setfilter
 *
 * @param[in]  index: filter index
 * @param[in]  ifcr: filter config
 * @return : none
 *
 * @brief  Set LIN filter
 */
__STATIC_INLINE void LIN_SetFilter(uint8_t index, uint32_t ifcr)
{
    *(uint32_t *)(&LIN0->IFCR0 + index) = ifcr;
}

/**
 * LIN_Enablefilter
 *
 * @param[in]  index: filter index
 * @param[in]  enable: enable or disable
 * @return : none
 *
 * @brief  Enable or disable LIN filter
 */
__STATIC_INLINE void LIN_EnableFilter(uint8_t index, uint8_t enable)
{
    if (enable)
    {
        LIN0->IFEN_B.EN |= 1 << index;
    }
    else
    {
        LIN0->IFEN_B.EN &= ~(1 << index);
    }
}

/**
 * LIN_SetFrame
 *
 * @param[in]  frame: frame infomation
 * @return : none
 *
 * @brief  Set frame infomation
 */
__STATIC_INLINE void LIN_SetFrame(uint32_t frame)
{
    LIN0->LINFRM = frame;
}

/**
 * LIN_GetId
 *
 * @param[in] : none
 * @return : Identifier
 *
 * @brief  Get frame Identifier
 */
__STATIC_INLINE uint8_t LIN_GetId(void)
{
    return LIN0->LINFRM_B.ID;
}

/**
 * LIN_SetChecksum
 *
 * @param[in]  checksum: checksum data
 * @return : none
 *
 * @brief  Set checksum for manual mode
 */
__STATIC_INLINE void LIN_SetChecksum(uint8_t checksum)
{
    LIN0->LINCS = checksum;
}

/**
 * LIN_GetMatchfilter
 *
 * @param[in] : none
 * @return : match filter index
 *
 * @brief  Get match filter index
 */
__STATIC_INLINE uint8_t LIN_GetMatchfilter(void)
{
    return LIN0->IFMI;
}

/**
 * LIN_IrqEnable
 *
 * @param[in]  enable: enable or disable
 * @return : none
 *
 * @brief  Enable or disable LIN interrupt
 */
__STATIC_INLINE void LIN_IrqEnable(uint32_t enable)
{
    if (enable)
    {
        NVIC_ClearPendingIRQ(LIN0_IRQn);
        NVIC_EnableIRQ(LIN0_IRQn);
    }
    else
    {
        NVIC_DisableIRQ(LIN0_IRQn);
    }
}


#ifdef __cplusplus
}
#endif

#endif
