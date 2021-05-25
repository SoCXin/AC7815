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
#ifndef AC78XX_ADC_REG_H_
#define AC78XX_ADC_REG_H_
#ifdef __cplusplus
extern "C" {
#endif
#include "stdint.h"
#include "stdio.h"

#define __IO    volatile                    //All drivers need this type
#define __I     volatile const
#define __STATIC_INLINE static __inline
    /* ================================================================================ */
    /* ================                       ADC                      ================ */
    /* ================================================================================ */
    /**
      * @brief Analog to Digital Convert Module (ADC)
      */

typedef struct {                                      ///< ADC Structure
    __IO uint32_t  STR;                               ///<0x00!< ADC status Register
    __IO uint32_t  CTRL1;                             ///<0x04!< ADC control register 1
    __IO uint32_t  CTRL2;                             ///<0x08!< ADC Control Register 2
    __IO uint32_t  SPT1;                              ///<0x0C!< ADC Sample time setting register 1
    __IO uint32_t  SPT2;                              ///<0x10!< ADC Sample time setting register 2
    __IO uint32_t  IOFR1;                             ///<0x14!< ADC Injection Group Offset Register(n)
    __IO uint32_t  IOFR2;                             ///<0x18!< ADC Injection Group Offset Register(n)
    __IO uint32_t  IOFR3;                             ///<0x1C!< ADC Injection Group Offset Register(n)
    __IO uint32_t  IOFR4;                             ///<0x20!< ADC Injection Group Offset Register(n)
    __IO uint32_t  AWDH;                              ///<0x24!< AWD High threshold register
    __IO uint32_t  AWDL;                              ///<0x28!< AWD Low threshold register
    __IO uint32_t  RSQR1;                             ///<0x2C!< ADC regular group sequence configure register 1
    __IO uint32_t  RSQR2;                             ///<0x30!< ADC regular group sequence configure register 2
    __IO uint32_t  RSQR3;                             ///<0x34!< ADC regular group sequence configure register 3
    __IO uint32_t  ISQR;                              ///<0x38!< ADC injection group sequence configure register
    __I  uint32_t  IDR1;                              ///<0x3C!< ADC Injection Group data Register(n)
    __I  uint32_t  IDR2;                              ///<0x40!< ADC Injection Group data Register(n)
    __I  uint32_t  IDR3;                              ///<0x44!< ADC Injection Group data Register(n)
    __I  uint32_t  IDR4;                              ///<0x48!< ADC Injection Group data Register(n)
    __I  uint32_t  RDR;                               ///<0x4C!< ADC Regular Group data Register
} ADC_Type;

typedef struct {                                      ///< ADC Analog Channel Select Structure
    __IO uint32_t  MODE;                              ///<0x00!< ADC chanenel status Register
} ADC_ANA_CHANNEL_Type;

typedef struct {                                      ///< ADC Analog LP config Structure
    __IO uint32_t  ADC_RSV1;                          ///<0x00!< ADC LP Register
} ADC_AUXADC_CFG0_Type;
	
typedef struct {                                      ///< ADC Analog LP config Structure
    __IO uint32_t  ADCBUF_RSV1;                       ///<0x00!< ADC LP Register
} ADC_MCU_ADCBUF_CFG0_Type;
/* ================================================================================ */
/* ================          struct 'ADC' Position & Mask          ================ */
/* ================================================================================ */


/* -----------------------------------  ADC_STR  ---------------------------------- */
#define ADC_STR_AMO_Pos                       0                                                       ///< ADC STR: AMO Position                  
#define ADC_STR_AMO_Msk                       (0x01UL << ADC_STR_AMO_Pos)                             ///< ADC STR: AMO Mask                       
#define ADC_STR_EOC_Pos                       1                                                       ///< ADC STR: EOC Position                   
#define ADC_STR_EOC_Msk                       (0x01UL << ADC_STR_EOC_Pos)                             ///< ADC STR: EOC Mask                       
#define ADC_STR_IEOC_Pos                      2                                                       ///< ADC STR: IEOC Position                  
#define ADC_STR_IEOC_Msk                      (0x01UL << ADC_STR_IEOC_Pos)                            ///< ADC STR: IEOC Mask                      
#define ADC_STR_IDLE_Pos                      3                                                       ///< ADC STR: IDLE Position                  
#define ADC_STR_IDLE_Msk                      (0x01UL << ADC_STR_IDLE_Pos)                            ///< ADC STR: IDLE Mask                      

/* ----------------------------------  ADC_CTRL1  --------------------------------- */
#define ADC_CTRL1_AMOCH_Pos                   0                                                       ///< ADC CTRL1: AMOCH Position               
#define ADC_CTRL1_AMOCH_Msk                   (0x1fUL << ADC_CTRL1_AMOCH_Pos)                         ///< ADC CTRL1: AMOCH Mask                   
#define ADC_CTRL1_AMOCH(x)                 (((uint32_t)(((uint32_t)(x))<<ADC_CTRL1_AMOCH_Pos))&ADC_CTRL1_AMOCH_Msk)
#define ADC_CTRL1_AMOSGL_Pos                  5                                                       ///< ADC CTRL1: AMOSGL Position              
#define ADC_CTRL1_AMOSGL_Msk                  (0x01UL << ADC_CTRL1_AMOSGL_Pos)                        ///< ADC CTRL1: AMOSGL Mask                  
#define ADC_CTRL1_IAMOEN_Pos                  6                                                       ///< ADC CTRL1: IAMOEN Position              
#define ADC_CTRL1_IAMOEN_Msk                  (0x01UL << ADC_CTRL1_IAMOEN_Pos)                        ///< ADC CTRL1: IAMOEN Mask                  
#define ADC_CTRL1_AMOEN_Pos                   7                                                       ///< ADC CTRL1: AMOEN Position               
#define ADC_CTRL1_AMOEN_Msk                   (0x01UL << ADC_CTRL1_AMOEN_Pos)                         ///< ADC CTRL1: AMOEN Mask                   
#define ADC_CTRL1_DISCNUM_Pos                 8                                                       ///< ADC CTRL1: DISCNUM Position             
#define ADC_CTRL1_DISCNUM_Msk                 (0x07UL << ADC_CTRL1_DISCNUM_Pos)                       ///< ADC CTRL1: DISCNUM Mask                 
#define ADC_CTRL1_DISCNUM(x)                  (((uint32_t)(((uint32_t)(x))<<ADC_CTRL1_DISCNUM_Pos))&ADC_CTRL1_DISCNUM_Msk)
#define ADC_CTRL1_IAUTO_Pos                   11                                                      ///< ADC CTRL1: IAUTO Position               
#define ADC_CTRL1_IAUTO_Msk                   (0x01UL << ADC_CTRL1_IAUTO_Pos)                         ///< ADC CTRL1: IAUTO Mask                   
#define ADC_CTRL1_IDISCEN_Pos                 12                                                      ///< ADC CTRL1: IDISCEN Position             
#define ADC_CTRL1_IDISCEN_Msk                 (0x01UL << ADC_CTRL1_IDISCEN_Pos)                       ///< ADC CTRL1: IDISCEN Mask                 
#define ADC_CTRL1_DISCEN_Pos                  13                                                      ///< ADC CTRL1: DISCEN Position              
#define ADC_CTRL1_DISCEN_Msk                  (0x01UL << ADC_CTRL1_DISCEN_Pos)                        ///< ADC CTRL1: DISCEN Mask                  
#define ADC_CTRL1_CONT_Pos                    14                                                      ///< ADC CTRL1: CONT Position                
#define ADC_CTRL1_CONT_Msk                    (0x01UL << ADC_CTRL1_CONT_Pos)                          ///< ADC CTRL1: CONT Mask                    
#define ADC_CTRL1_SCAN_Pos                    15                                                      ///< ADC CTRL1: SCAN Position                
#define ADC_CTRL1_SCAN_Msk                    (0x01UL << ADC_CTRL1_SCAN_Pos)                          ///< ADC CTRL1: SCAN Mask                    
#define ADC_CTRL1_EOCIE_Pos                   16                                                      ///< ADC CTRL1: EOCIE Position               
#define ADC_CTRL1_EOCIE_Msk                   (0x01UL << ADC_CTRL1_EOCIE_Pos)                         ///< ADC CTRL1: EOCIE Mask                   
#define ADC_CTRL1_IEOCIE_Pos                  17                                                      ///< ADC CTRL1: IEOCIE Position              
#define ADC_CTRL1_IEOCIE_Msk                  (0x01UL << ADC_CTRL1_IEOCIE_Pos)                        ///< ADC CTRL1: IEOCIE Mask                  
#define ADC_CTRL1_AMOIE_Pos                   18                                                      ///< ADC CTRL1: AMOIE Position               
#define ADC_CTRL1_AMOIE_Msk                   (0x01UL << ADC_CTRL1_AMOIE_Pos)                         ///< ADC CTRL1: AMOIE Mask                   
#define ADC_CTRL1_DMAEN_Pos                   19                                                      ///< ADC CTRL1: DMAEN Position               
#define ADC_CTRL1_DMAEN_Msk                   (0x01UL << ADC_CTRL1_DMAEN_Pos)                         ///< ADC CTRL1: DMAEN Mask                   
#define ADC_CTRL1_EXTTRIG_Pos                 20                                                      ///< ADC CTRL1: EXTTRIG Position             
#define ADC_CTRL1_EXTTRIG_Msk                 (0x01UL << ADC_CTRL1_EXTTRIG_Pos)                       ///< ADC CTRL1: EXTTRIG Mask                 
#define ADC_CTRL1_EXTTRIG(x)                 (((uint32_t)(((uint32_t)(x))<<ADC_CTRL1_EXTTRIG_Pos))&ADC_CTRL1_EXTTRIG_Msk)
#define ADC_CTRL1_IEXTTRIG_Pos                21                                                      ///< ADC CTRL1: IEXTTRIG Position            
#define ADC_CTRL1_IEXTTRIG_Msk                (0x01UL << ADC_CTRL1_IEXTTRIG_Pos)                      ///< ADC CTRL1: IEXTTRIG Mask                
#define ADC_CTRL1_IEXTTRIG(x)                 (((uint32_t)(((uint32_t)(x))<<ADC_CTRL1_IEXTTRIG_Pos))&ADC_CTRL1_IEXTTRIG_Msk)
#define ADC_CTRL1_ALIGN_Pos                   22                                                      ///< ADC CTRL1: ALIGN Position               
#define ADC_CTRL1_ALIGN_Msk                   (0x01UL << ADC_CTRL1_ALIGN_Pos)                         ///< ADC CTRL1: ALIGN Mask                   
#define ADC_CTRL1_ALIGN(x)                 (((uint32_t)(((uint32_t)(x))<<ADC_CTRL1_ALIGN_Pos))&ADC_CTRL1_ALIGN_Msk)
#define ADC_CTRL1_ISWSTART_Pos                30                                                      ///< ADC CTRL1: ISWSTART Position            
#define ADC_CTRL1_ISWSTART_Msk                (0x01UL << ADC_CTRL1_ISWSTART_Pos)                      ///< ADC CTRL1: ISWSTART Mask                
#define ADC_CTRL1_SWSTART_Pos                 31                                                      ///< ADC CTRL1: SWSTART Position             
#define ADC_CTRL1_SWSTART_Msk                 (0x01UL << ADC_CTRL1_SWSTART_Pos)                       ///< ADC CTRL1: SWSTART Mask                 

/* ----------------------------------  ADC_CTRL2  --------------------------------- */
#define ADC_CTRL2_ADON_Pos                    0                                                       ///< ADC CTRL2: ADON Position                
#define ADC_CTRL2_ADON_Msk                    (0x01UL << ADC_CTRL2_ADON_Pos)                          ///< ADC CTRL2: ADON Mask                    
#define ADC_CTRL2_CALEN_Pos                   1                                                       ///< ADC CTRL2: CALEN Position               
#define ADC_CTRL2_CALEN_Msk                   (0x01UL << ADC_CTRL2_CALEN_Pos)                         ///< ADC CTRL2: CALEN Mask                               
#define ADC_CTRL2_PSC_Pos                     12                                                      ///< ADC CTRL2: PSC Position                 
#define ADC_CTRL2_PSC_Msk                     (0x0fUL << ADC_CTRL2_PSC_Pos)                           ///< ADC CTRL2: PSC Mask                     
#define ADC_CTRL2_PSC(x)                 (((uint32_t)(((uint32_t)(x))<<ADC_CTRL2_PSC_Pos))&ADC_CTRL2_PSC_Msk)

/* ----------------------------------  ADC_SPT1  ---------------------------------- */
#define ADC_SPT1_SPT10_Pos                    0                                                       ///< ADC SPT1: SPT10 Position                
#define ADC_SPT1_SPT10_Msk                    (0x07UL << ADC_SPT1_SPT10_Pos)                          ///< ADC SPT1: SPT10 Mask                    
#define ADC_SPT1_SPT11_Pos                    3                                                       ///< ADC SPT1: SPT11 Position                
#define ADC_SPT1_SPT11_Msk                    (0x07UL << ADC_SPT1_SPT11_Pos)                          ///< ADC SPT1: SPT11 Mask                    
#define ADC_SPT1_SPT12_Pos                    6                                                       ///< ADC SPT1: SPT12 Position                
#define ADC_SPT1_SPT12_Msk                    (0x07UL << ADC_SPT1_SPT12_Pos)                          ///< ADC SPT1: SPT12 Mask                    
#define ADC_SPT1_SPT13_Pos                    9                                                       ///< ADC SPT1: SPT13 Position                
#define ADC_SPT1_SPT13_Msk                    (0x07UL << ADC_SPT1_SPT13_Pos)                          ///< ADC SPT1: SPT13 Mask                    
#define ADC_SPT1_SPT14_Pos                    12                                                      ///< ADC SPT1: SPT14 Position                
#define ADC_SPT1_SPT14_Msk                    (0x07UL << ADC_SPT1_SPT14_Pos)                          ///< ADC SPT1: SPT14 Mask                    
#define ADC_SPT1_SPT15_Pos                    15                                                      ///< ADC SPT1: SPT15 Position                
#define ADC_SPT1_SPT15_Msk                    (0x07UL << ADC_SPT1_SPT15_Pos)                          ///< ADC SPT1: SPT15 Mask                    
#define ADC_SPT1_SPT16_Pos                    18                                                      ///< ADC SPT1: SPT16 Position                
#define ADC_SPT1_SPT16_Msk                    (0x07UL << ADC_SPT1_SPT16_Pos)                          ///< ADC SPT1: SPT16 Mask                    
#define ADC_SPT1_SPT17_Pos                    21                                                      ///< ADC SPT1: SPT17 Position                
#define ADC_SPT1_SPT17_Msk                    (0x07UL << ADC_SPT1_SPT17_Pos)                          ///< ADC SPT1: SPT17 Mask                    

/* ----------------------------------  ADC_SPT2  ---------------------------------- */
#define ADC_SPT2_SPT0_Pos                     0                                                       ///< ADC SPT2: SPT0 Position                 
#define ADC_SPT2_SPT0_Msk                     (0x07UL << ADC_SPT2_SPT0_Pos)                           ///< ADC SPT2: SPT0 Mask                     
#define ADC_SPT2_SPT1_Pos                     3                                                       ///< ADC SPT2: SPT1 Position                 
#define ADC_SPT2_SPT1_Msk                     (0x07UL << ADC_SPT2_SPT1_Pos)                           ///< ADC SPT2: SPT1 Mask                     
#define ADC_SPT2_SPT2_Pos                     6                                                       ///< ADC SPT2: SPT2 Position                 
#define ADC_SPT2_SPT2_Msk                     (0x07UL << ADC_SPT2_SPT2_Pos)                           ///< ADC SPT2: SPT2 Mask                     
#define ADC_SPT2_SPT3_Pos                     9                                                       ///< ADC SPT2: SPT3 Position                 
#define ADC_SPT2_SPT3_Msk                     (0x07UL << ADC_SPT2_SPT3_Pos)                           ///< ADC SPT2: SPT3 Mask                     
#define ADC_SPT2_SPT4_Pos                     12                                                      ///< ADC SPT2: SPT4 Position                 
#define ADC_SPT2_SPT4_Msk                     (0x07UL << ADC_SPT2_SPT4_Pos)                           ///< ADC SPT2: SPT4 Mask                     
#define ADC_SPT2_SPT5_Pos                     15                                                      ///< ADC SPT2: SPT5 Position                 
#define ADC_SPT2_SPT5_Msk                     (0x07UL << ADC_SPT2_SPT5_Pos)                           ///< ADC SPT2: SPT5 Mask                     
#define ADC_SPT2_SPT6_Pos                     18                                                      ///< ADC SPT2: SPT6 Position                 
#define ADC_SPT2_SPT6_Msk                     (0x07UL << ADC_SPT2_SPT6_Pos)                           ///< ADC SPT2: SPT6 Mask                     
#define ADC_SPT2_SPT7_Pos                     21                                                      ///< ADC SPT2: SPT7 Position                 
#define ADC_SPT2_SPT7_Msk                     (0x07UL << ADC_SPT2_SPT7_Pos)                           ///< ADC SPT2: SPT7 Mask                     
#define ADC_SPT2_SPT8_Pos                     24                                                      ///< ADC SPT2: SPT8 Position                 
#define ADC_SPT2_SPT8_Msk                     (0x07UL << ADC_SPT2_SPT8_Pos)                           ///< ADC SPT2: SPT8 Mask                     
#define ADC_SPT2_SPT9_Pos                     27                                                      ///< ADC SPT2: SPT9 Position                 
#define ADC_SPT2_SPT9_Msk                     (0x07UL << ADC_SPT2_SPT9_Pos)                           ///< ADC SPT2: SPT9 Mask                     

/* ----------------------------------  ADC_IOFR1  --------------------------------- */
#define ADC_IOFR1_IOFR_Pos                    0                                                       ///< ADC IOFR1: IOFR Position                
#define ADC_IOFR1_IOFR_Msk                    (0x00000fffUL << ADC_IOFR1_IOFR_Pos)                    ///< ADC IOFR1: IOFR Mask                    

/* ----------------------------------  ADC_IOFR2  --------------------------------- */
#define ADC_IOFR2_IOFR_Pos                    0                                                       ///< ADC IOFR2: IOFR Position                
#define ADC_IOFR2_IOFR_Msk                    (0x00000fffUL << ADC_IOFR2_IOFR_Pos)                    ///< ADC IOFR2: IOFR Mask                    

/* ----------------------------------  ADC_IOFR3  --------------------------------- */
#define ADC_IOFR3_IOFR_Pos                    0                                                       ///< ADC IOFR3: IOFR Position                
#define ADC_IOFR3_IOFR_Msk                    (0x00000fffUL << ADC_IOFR3_IOFR_Pos)                    ///< ADC IOFR3: IOFR Mask                    

/* ----------------------------------  ADC_IOFR4  --------------------------------- */
#define ADC_IOFR4_IOFR_Pos                    0                                                       ///< ADC IOFR4: IOFR Position                
#define ADC_IOFR4_IOFR_Msk                    (0x00000fffUL << ADC_IOFR4_IOFR_Pos)                    ///< ADC IOFR4: IOFR Mask                    

/* ----------------------------------  ADC_AWDH  ---------------------------------- */
#define ADC_AWDH_AWDH_Pos                     0                                                       ///< ADC AWDH: AWDH Position                 
#define ADC_AWDH_AWDH_Msk                     (0x00000fffUL << ADC_AWDH_AWDH_Pos)                     ///< ADC AWDH: AWDH Mask                     

/* ----------------------------------  ADC_AWDL  ---------------------------------- */
#define ADC_AWDL_AWDL_Pos                     0                                                       ///< ADC AWDL: AWDL Position                 
#define ADC_AWDL_AWDL_Msk                     (0x00000fffUL << ADC_AWDL_AWDL_Pos)                     ///< ADC AWDL: AWDL Mask                     

/* ----------------------------------  ADC_RSQR1  --------------------------------- */
#define ADC_RSQR1_RSQ13_Pos                   0                                                       ///< ADC RSQR1: RSQ13 Position               
#define ADC_RSQR1_RSQ13_Msk                   (0x1fUL << ADC_RSQR1_RSQ13_Pos)                         ///< ADC RSQR1: RSQ13 Mask                   
#define ADC_RSQR1_RSQ14_Pos                   5                                                       ///< ADC RSQR1: RSQ14 Position               
#define ADC_RSQR1_RSQ14_Msk                   (0x1fUL << ADC_RSQR1_RSQ14_Pos)                         ///< ADC RSQR1: RSQ14 Mask                   
#define ADC_RSQR1_RSQ15_Pos                   10                                                      ///< ADC RSQR1: RSQ15 Position               
#define ADC_RSQR1_RSQ15_Msk                   (0x1fUL << ADC_RSQR1_RSQ15_Pos)                         ///< ADC RSQR1: RSQ15 Mask                   
#define ADC_RSQR1_RSQ16_Pos                   15                                                      ///< ADC RSQR1: RSQ16 Position               
#define ADC_RSQR1_RSQ16_Msk                   (0x1fUL << ADC_RSQR1_RSQ16_Pos)                         ///< ADC RSQR1: RSQ16 Mask                   
#define ADC_RSQR1_RSQL_Pos                    20                                                      ///< ADC RSQR1: RSQL Position                
#define ADC_RSQR1_RSQL_Msk                    (0x0fUL << ADC_RSQR1_RSQL_Pos)                          ///< ADC RSQR1: RSQL Mask                    
#define ADC_RSQR1_RSQL(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_RSQR1_RSQL_Pos))&ADC_RSQR1_RSQL_Msk)

/* ----------------------------------  ADC_RSQR2  --------------------------------- */
#define ADC_RSQR2_RSQ7_Pos                    0                                                       ///< ADC RSQR2: RSQ7 Position                
#define ADC_RSQR2_RSQ7_Msk                    (0x1fUL << ADC_RSQR2_RSQ7_Pos)                          ///< ADC RSQR2: RSQ7 Mask                    
#define ADC_RSQR2_RSQ8_Pos                    5                                                       ///< ADC RSQR2: RSQ8 Position                
#define ADC_RSQR2_RSQ8_Msk                    (0x1fUL << ADC_RSQR2_RSQ8_Pos)                          ///< ADC RSQR2: RSQ8 Mask                    
#define ADC_RSQR2_RSQ9_Pos                    10                                                      ///< ADC RSQR2: RSQ9 Position               
#define ADC_RSQR2_RSQ9_Msk                    (0x1fUL << ADC_RSQR2_RSQ9_Pos)                          ///< ADC RSQR2: RSQ9 Mask                    
#define ADC_RSQR2_RSQ10_Pos                   15                                                      ///< ADC RSQR2: RSQ10 Position               
#define ADC_RSQR2_RSQ10_Msk                   (0x1fUL << ADC_RSQR2_RSQ10_Pos)                         ///< ADC RSQR2: RSQ10 Mask                   
#define ADC_RSQR2_RSQ11_Pos                   20                                                      ///< ADC RSQR2: RSQ11 Position               
#define ADC_RSQR2_RSQ11_Msk                   (0x1fUL << ADC_RSQR2_RSQ11_Pos)                         ///< ADC RSQR2: RSQ11 Mask                   
#define ADC_RSQR2_RSQ12_Pos                   25                                                      ///< ADC RSQR2: RSQ12 Position               
#define ADC_RSQR2_RSQ12_Msk                   (0x1fUL << ADC_RSQR2_RSQ12_Pos)                         ///< ADC RSQR2: RSQ12 Mask                   

/* ----------------------------------  ADC_RSQR3  --------------------------------- */
#define ADC_RSQR3_RSQ1_Pos                    0                                                       ///< ADC RSQR3: RSQ1 Position                
#define ADC_RSQR3_RSQ1_Msk                    (0x1fUL << ADC_RSQR3_RSQ1_Pos)                          ///< ADC RSQR3: RSQ1 Mask                    
#define ADC_RSQR3_RSQ2_Pos                    5                                                       ///< ADC RSQR3: RSQ2 Position                
#define ADC_RSQR3_RSQ2_Msk                    (0x1fUL << ADC_RSQR3_RSQ2_Pos)                          ///< ADC RSQR3: RSQ2 Mask                    
#define ADC_RSQR3_RSQ3_Pos                    10                                                      ///< ADC RSQR3: RSQ3 Position                
#define ADC_RSQR3_RSQ3_Msk                    (0x1fUL << ADC_RSQR3_RSQ3_Pos)                          ///< ADC RSQR3: RSQ3 Mask                    
#define ADC_RSQR3_RSQ4_Pos                    15                                                      ///< ADC RSQR3: RSQ4 Position                
#define ADC_RSQR3_RSQ4_Msk                    (0x1fUL << ADC_RSQR3_RSQ4_Pos)                          ///< ADC RSQR3: RSQ4 Mask                    
#define ADC_RSQR3_RSQ5_Pos                    20                                                      ///< ADC RSQR3: RSQ5 Position                
#define ADC_RSQR3_RSQ5_Msk                    (0x1fUL << ADC_RSQR3_RSQ5_Pos)                          ///< ADC RSQR3: RSQ5 Mask                    
#define ADC_RSQR3_RSQ6_Pos                    25                                                      ///< ADC RSQR3: RSQ6 Position                
#define ADC_RSQR3_RSQ6_Msk                    (0x1fUL << ADC_RSQR3_RSQ6_Pos)                          ///< ADC RSQR3: RSQ6 Mask                    

/* ----------------------------------  ADC_ISQR  ---------------------------------- */
#define ADC_ISQR_ISQ1_Pos                     0                                                       ///< ADC ISQR: ISQ1 Position                 
#define ADC_ISQR_ISQ1_Msk                     (0x1fUL << ADC_ISQR_ISQ1_Pos)                           ///< ADC ISQR: ISQ1 Mask                     
#define ADC_ISQR_RSQ14_Pos                    5                                                       ///< ADC ISQR: RSQ14 Position                
#define ADC_ISQR_RSQ14_Msk                    (0x1fUL << ADC_ISQR_RSQ14_Pos)                          ///< ADC ISQR: RSQ14 Mask                    
#define ADC_ISQR_RSQ15_Pos                    10                                                      ///< ADC ISQR: RSQ15 Position                
#define ADC_ISQR_RSQ15_Msk                    (0x1fUL << ADC_ISQR_RSQ15_Pos)                          ///< ADC ISQR: RSQ15 Mask                    
#define ADC_ISQR_RSQ16_Pos                    15                                                      ///< ADC ISQR: RSQ16 Position                
#define ADC_ISQR_RSQ16_Msk                    (0x1fUL << ADC_ISQR_RSQ16_Pos)                          ///< ADC ISQR: RSQ16 Mask                    
#define ADC_ISQR_ISQL_Pos                     20                                                      ///< ADC ISQR: ISQL Position                 
#define ADC_ISQR_ISQL_Msk                     (0x03UL << ADC_ISQR_ISQL_Pos)                           ///< ADC ISQR: ISQL Mask                     
#define ADC_ISQR_ISQL(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_ISQR_ISQL_Pos))&ADC_ISQR_ISQL_Msk)

/* ----------------------------------  ADC_IDR1  ---------------------------------- */
#define ADC_IDR1_IDR_Pos                      0                                                       ///< ADC IDR1: IDR Position                  
#define ADC_IDR1_IDR_Msk                      (0x00000fffUL << ADC_IDR1_IDR_Pos)                      ///< ADC IDR1: IDR Mask                      

/* ----------------------------------  ADC_IDR2  ---------------------------------- */
#define ADC_IDR2_IDR_Pos                      0                                                       ///< ADC IDR2: IDR Position                  
#define ADC_IDR2_IDR_Msk                      (0x00000fffUL << ADC_IDR2_IDR_Pos)                      ///< ADC IDR2: IDR Mask                      

/* ----------------------------------  ADC_IDR3  ---------------------------------- */
#define ADC_IDR3_IDR_Pos                      0                                                       ///< ADC IDR3: IDR Position                  
#define ADC_IDR3_IDR_Msk                      (0x00000fffUL << ADC_IDR3_IDR_Pos)                      ///< ADC IDR3: IDR Mask                      

/* ----------------------------------  ADC_IDR4  ---------------------------------- */
#define ADC_IDR4_IDR_Pos                      0                                                       ///< ADC IDR4: IDR Position                  
#define ADC_IDR4_IDR_Msk                      (0x00000fffUL << ADC_IDR4_IDR_Pos)                      ///< ADC IDR4: IDR Mask                      

/* -----------------------------------  ADC_RDR  ---------------------------------- */
#define ADC_RDR_IDR_Pos                       0                                                       ///< ADC RDR: IDR Position                   
#define ADC_RDR_IDR_Msk                       (0x00000fffUL << ADC_RDR_IDR_Pos)                       ///< ADC RDR: IDR Mask                       

/* -----------------------------------	ADC_AUXADC_CFG0  -------------------------- */
#define ADC_AUXADC_CFG0_RSRV1_Pos             12                                                      ///< ADC AUXADC CFG0: RSRV1 Position         
#define ADC_AUXADC_CFG0_RSRV1_Msk             (0xffUL << ADC_AUXADC_CFG0_RSRV1_Pos)                   ///< ADC AUXADC CFG0: RSRV1 Mask             
#define ADC_AUXADC_CFG0_RSRV0_Pos             20                                                      ///< ADC AUXADC CFG0: RSRV0 Position         
#define ADC_AUXADC_CFG0_RSRV0_Msk             (0xffUL << ADC_AUXADC_CFG0_RSRV0_Pos)                   ///< ADC AUXADC CFG0: RSRV0 Mask             

/* -----------------------------------	ADC_MCU_ADCBUF_CFG0  ----------------------- */
#define ADC_MCU_ADCBUF_CFG0_RSRV1_Pos         16                                                      ///< ADC MCU ADCBUF CFG0: RSRV1 Position     
#define ADC_MCU_ADCBUF_CFG0_RSRV1_Msk         (0xffUL << ADC_MCU_ADCBUF_CFG0_RSRV1_Pos)               ///< ADC MCU ADCBUF CFG0: RSRV1 Mask         
#define ADC_MCU_ADCBUF_CFG0_RSRV0_Pos         24                                                      ///< ADC MCU ADCBUF CFG0: RSRV0 Position     
#define ADC_MCU_ADCBUF_CFG0_RSRV0_Msk         (0xffUL << ADC_MCU_ADCBUF_CFG0_RSRV0_Pos)               ///< ADC MCU ADCBUF CFG0: RSRV0 Mask         


/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */
#define ADC_BASE                        0x40003000UL
#define ADC_ANA_CHANNEL_BASE            0x4000480CUL
#define ADC_AUXADC_CFG0_BASE            0x40008840UL
#define ADC_MCU_ADCBUF_CFG0_BASE        0x40008844UL

/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */
#define ADC                             ((ADC_Type                 *) ADC_BASE)
#define ADC_ANA_CHANNEL                 ((ADC_ANA_CHANNEL_Type     *) ADC_ANA_CHANNEL_BASE)
#define ADC_AUXADC_CFG0                 ((ADC_AUXADC_CFG0_Type     *) ADC_AUXADC_CFG0_BASE)
#define ADC_MCU_ADCBUF_CFG0             ((ADC_MCU_ADCBUF_CFG0_Type *) ADC_MCU_ADCBUF_CFG0_BASE)

/******************************************************************************
* Types
******************************************************************************/
/*! @brief ADC_CALLBACK function declaration                                  */
typedef void (*ADC_CallbackPtr)(void);
/*! @} End of ADC_callback                                                    */

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC Power On.
  */
__STATIC_INLINE void ADC_PowerOn(ADC_Type *ADCx)
{
    ADCx->CTRL2 |= ADC_CTRL2_ADON_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC Power Down.
  */
__STATIC_INLINE void ADC_PowerDown(ADC_Type *ADCx)
{
    ADCx->CTRL2 &= ~ADC_CTRL2_ADON_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC Calibration Enable.
  */
__STATIC_INLINE void ADC_CalibrationEnable(ADC_Type *ADCx)
{
    ADCx->CTRL2 |= ADC_CTRL2_CALEN_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC Calibration Disable.
  */
__STATIC_INLINE void ADC_CalibrationDisable(ADC_Type *ADCx)
{
    ADCx->CTRL2 &= ~ADC_CTRL2_CALEN_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @param[in] prescaler: prescaler value
  * @return none.
  * @brief  ADC Set Clock Prescale.
  */
__STATIC_INLINE void ADC_SetClockPrescaler(ADC_Type *ADCx, uint32_t prescaler)
{
    ADCx->CTRL2 = (ADCx->CTRL2 & ~(ADC_CTRL2_PSC_Msk)) | ADC_CTRL2_PSC(prescaler);
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC Software trigger for regular channels Enable.
  */
__STATIC_INLINE void ADC_SoftwareTriggerCovEnable(ADC_Type *ADCx)
{
    ADCx->CTRL1 |= ADC_CTRL1_SWSTART_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC Software trigger for regular channels Disable.
  */
__STATIC_INLINE void ADC_SoftwareTriggerCovDisable(ADC_Type *ADCx)
{
    ADCx->CTRL1 &= ~ADC_CTRL1_SWSTART_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC Software trigger for Inject channels Enable.
  */
__STATIC_INLINE void ADC_SoftwareTriggerInjectCovEnable(ADC_Type *ADCx)
{
    ADCx->CTRL1 |= ADC_CTRL1_ISWSTART_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC Software trigger for Inject channels Disable.
  */
__STATIC_INLINE void ADC_SoftwareTriggerInjectCovDisable(ADC_Type *ADCx)
{
    ADCx->CTRL1 &= ~ADC_CTRL1_ISWSTART_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @param[in] dataAlign: 0:Right alignment; 1: Left alignment
  * @return none.
  * @brief  ADC Data Alignment Select.
  */
__STATIC_INLINE void ADC_DataAlignSel(ADC_Type *ADCx, uint32_t dataAlign)
{
    ADCx->CTRL1 = (ADCx->CTRL1 & ~(ADC_CTRL1_ALIGN_Msk)) | ADC_CTRL1_ALIGN(dataAlign);
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @param[in] trigSource: 0:Internal Source(Software trig); 1: External Source
  * @return none.
  * @brief  ADC Inject group trigger source select.
  */
__STATIC_INLINE void ADC_InjectTrigSourceSel(ADC_Type *ADCx, uint32_t trigSource)
{
    ADCx->CTRL1 = (ADCx->CTRL1 & ~(ADC_CTRL1_IEXTTRIG_Msk)) | ADC_CTRL1_IEXTTRIG(trigSource);
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @param[in] trigSource: 0:Internal Source(Software trig); 1: External Source
  * @return none.
  * @brief  ADC Regular group trigger source select.
  */
__STATIC_INLINE void ADC_RegularTrigSourceSel(ADC_Type *ADCx, uint32_t trigSource)
{
    ADCx->CTRL1 = (ADCx->CTRL1 & ~(ADC_CTRL1_EXTTRIG_Msk)) | ADC_CTRL1_EXTTRIG(trigSource);
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC DMA Mode Enable.
  */
__STATIC_INLINE void ADC_DMAEnable(ADC_Type *ADCx)
{
    ADCx->CTRL1 |= ADC_CTRL1_DMAEN_Msk ;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC DMA Mode Disable.
  */
__STATIC_INLINE void ADC_DMADisable(ADC_Type *ADCx)
{
    ADCx->CTRL1 &= ~ADC_CTRL1_DMAEN_Msk ;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC EOC Interrupt Enable.
  */
__STATIC_INLINE void ADC_RegularConvInterruptEnable(ADC_Type *ADCx)
{
    ADCx->CTRL1 |= ADC_CTRL1_EOCIE_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC EOC Interrupt Disable.
  */
__STATIC_INLINE void ADC_RegularConvInterruptDisable(ADC_Type *ADCx)
{
    ADCx->CTRL1 &= ~ADC_CTRL1_EOCIE_Msk ;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC IEOC Interrupt Enable.
  */
__STATIC_INLINE void ADC_InjectConvInterruptEnable(ADC_Type *ADCx)
{
    ADCx->CTRL1 |= ADC_CTRL1_IEOCIE_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC IEOC Interrupt Disable.
  */
__STATIC_INLINE void ADC_InjectConvInterruptDisable(ADC_Type *ADCx)
{
    ADCx->CTRL1 &= ~ADC_CTRL1_IEOCIE_Msk ;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC AMO Interrupt Enable.
  */
__STATIC_INLINE void ADC_AnalogWatchDogInterruptEnable(ADC_Type *ADCx)
{
    ADCx->CTRL1 |= ADC_CTRL1_AMOIE_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC AMO Interrupt Disable.
  */
__STATIC_INLINE void ADC_AnalogWatchDogInterruptDisable(ADC_Type *ADCx)
{
    ADCx->CTRL1 &= ~ADC_CTRL1_AMOIE_Msk ;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @param[in] channel: the ADC channel to configure for the analog watchdog.
  * @return none.
  * @brief  ADC AMO Single Channel Select.
  */
__STATIC_INLINE void ADC_AnalogWatchDogSingleChannelSel(ADC_Type *ADCx, uint32_t channel)
{
    ADCx->CTRL1 = (ADCx->CTRL1 & ~(ADC_CTRL1_AMOCH_Msk)) | ADC_CTRL1_AMOCH(channel);
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC AMO Single Channel Mode Sel.
  */
__STATIC_INLINE void ADC_AnalogWatchDogSingleChannelModeEnable(ADC_Type *ADCx)
{
    ADCx->CTRL1 |= ADC_CTRL1_AMOSGL_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC AMO All Channel Mode Sel.
  */
__STATIC_INLINE void ADC_AnalogWatchDogAllChannelModeEnable(ADC_Type *ADCx)
{
    ADCx->CTRL1 &= ~ADC_CTRL1_AMOSGL_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC AMO On Regular Channel Mode Enable.
  */
__STATIC_INLINE void ADC_AnalogWatchDogOnRegularChannelModeEnable(ADC_Type *ADCx)
{
    ADCx->CTRL1 |= ADC_CTRL1_AMOEN_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC AMO On Regular Channel Mode Disable.
  */
__STATIC_INLINE void ADC_AnalogWatchDogOnRegularChannelModeDisable(ADC_Type *ADCx)
{
    ADCx->CTRL1 &= ~ADC_CTRL1_AMOEN_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC AMO On Inject Channel Mode Enable.
  */
__STATIC_INLINE void ADC_AnalogWatchDogOnInjectChannelModeEnable(ADC_Type *ADCx)
{
    ADCx->CTRL1 |= ADC_CTRL1_IAMOEN_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  ADC AMO On Inject Channel Mode Disable.
  */
__STATIC_INLINE void ADC_AnalogWatchDogOnInjectChannelModeDisable(ADC_Type *ADCx)
{
    ADCx->CTRL1 &= ~ADC_CTRL1_IAMOEN_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  Enables the selected ADC automatic injected group conversion after regular one.
  */
__STATIC_INLINE void ADC_InjectAutoConvEnable(ADC_Type *ADCx)
{
    ADCx->CTRL1 |= ADC_CTRL1_IAUTO_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  Disable the selected ADC automatic injected group conversion after regular one.
  */
__STATIC_INLINE void ADC_InjectAutoConvDisable(ADC_Type *ADCx)
{
    ADCx->CTRL1 &= ~ADC_CTRL1_IAUTO_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  Enables the discontinuous mode for injected group channel
  */
__STATIC_INLINE void ADC_InjectDiscontinousModeEnable(ADC_Type *ADCx)
{
    ADCx->CTRL1 |= ADC_CTRL1_IDISCEN_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  Disable the discontinuous mode for injected group channel
  */
__STATIC_INLINE void ADC_InjectDiscontinousModeDisable(ADC_Type *ADCx)
{
    ADCx->CTRL1 &= ~ADC_CTRL1_IDISCEN_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  Enables the discontinuous mode for Regular group channel
  */
__STATIC_INLINE void ADC_RegularDiscontinousModeEnable(ADC_Type *ADCx)
{
    ADCx->CTRL1 |= ADC_CTRL1_IDISCEN_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  Disable the discontinuous mode for Regular group channel
  */
__STATIC_INLINE void ADC_RegularDiscontinousModeDisable(ADC_Type *ADCx)
{
    ADCx->CTRL1 &= ~ADC_CTRL1_IDISCEN_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  Enables the Continuous Conversion mode
  */
__STATIC_INLINE void ADC_ContinousModeEnable(ADC_Type *ADCx)
{
    ADCx->CTRL1 |= ADC_CTRL1_CONT_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  Disable the Continuous Conversion mode
  */
__STATIC_INLINE void ADC_ContinousModDisable(ADC_Type *ADCx)
{
    ADCx->CTRL1 &= ~ADC_CTRL1_CONT_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  Enables the Scan Conversion mode
  */
__STATIC_INLINE void ADC_ScanModeEnable(ADC_Type *ADCx)
{
    ADCx->CTRL1 |= ADC_CTRL1_SCAN_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  Disable the Scan Conversion mode
  */
__STATIC_INLINE void ADC_ScanModeDisable(ADC_Type *ADCx)
{
    ADCx->CTRL1 &= ~ADC_CTRL1_SCAN_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @param[in] num: Discontinous mode numbers from 0 to 8
  * @return none.
  * @brief  Discontinous mode Number Select
  */
__STATIC_INLINE void ADC_DiscModeNumSel(ADC_Type* ADCx, uint32_t num)
{
    ADCx->CTRL1 = (ADCx->CTRL1 & ~(ADC_CTRL1_DISCNUM_Msk)) | ADC_CTRL1_DISCNUM(num);
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @param[in] channel: ADC Channel from 0 to 17
  * @param[in] sampleTime: SampleTime
  * @return none.
  * @brief  Channel Sample Time Select
  */
__STATIC_INLINE void ADC_ChannelSampleTimeSel(ADC_Type *ADCx, uint32_t channel, uint32_t sampleTime)
{
    if (channel < 10)
    {
        ADCx->SPT2 &= ~(0x7 << ((channel) * 3));
        ADCx->SPT2 |= (sampleTime << ((channel) * 3));
    }
    else
    {
        ADCx->SPT1 &= ~(0x7 << ((channel - 10) * 3));
        ADCx->SPT1 |= (sampleTime << ((channel - 10) * 3));
    }
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @param[in] group: Inject Group, from 1 to 4
  * @param[in] offset: Offset Value
  * @return none.
  * @brief  ADC Inject Group Offset Value
  */
__STATIC_INLINE void ADC_SetInjectGroupOffset(ADC_Type *ADCx, uint32_t group, uint32_t offset)
{
    if (1 == group)
    {
        ADCx->IOFR1 |= offset;
    }
    else if (2 == group)
    {
        ADCx->IOFR2 |= offset;
    }
    else if (3 == group)
    {
        ADCx->IOFR3 |= offset;
    }
    else if (4 == group)
    {
        ADCx->IOFR4 |= offset;
    }
    else
    {

    }
}
/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @param[in] highValue: High Threshold value
  * @param[in] lowValue: Low Threshold value
  * @return none.
  * @brief  Set AnalogWatchDog High and Low Threshold value
  */
__STATIC_INLINE void ADC_SetAnalogWatchDogThreshold(ADC_Type *ADCx, uint32_t highValue, uint32_t lowValue)
{
    ADCx->AWDH = highValue;
    ADCx->AWDL = lowValue;
}
/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @param[in] channel: Regular Group sequence Channel from 0 to 15
  * @return none.
  * @brief  Set ADC Channel PIN to Analog Input PIN
  */
__STATIC_INLINE void ADC_SetADChannelToAnalogInputPin(ADC_Type *ADCx, uint32_t channel)
{
    ADC_ANA_CHANNEL->MODE &= ~(0x01 << (31 - channel));
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @param[in] channel: Regular Group sequence Channel from 0 to 15
  * @return none.
  * @brief  Set ADC Channel PIN to Digital PIN
  */
__STATIC_INLINE void ADC_SetADChannelToDigitalPin(ADC_Type *ADCx, uint32_t channel)
{
    ADC_ANA_CHANNEL->MODE |= (0x01 << (31 - channel));
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  Enables the ADC LP1 mode
  */
__STATIC_INLINE void ADC_LP1Enable(ADC_Type *ADCx)
{
    ADC_AUXADC_CFG0->ADC_RSV1 |= ADC_AUXADC_CFG0_RSRV1_Msk;
    ADC_MCU_ADCBUF_CFG0->ADCBUF_RSV1 |= ADC_MCU_ADCBUF_CFG0_RSRV1_Msk;
}
/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  Disables the ADC LP1 mode
  */
__STATIC_INLINE void ADC_LP1Disable(ADC_Type *ADCx)
{
    ADC_AUXADC_CFG0->ADC_RSV1 &= ~ADC_AUXADC_CFG0_RSRV1_Msk;
	ADC_MCU_ADCBUF_CFG0->ADCBUF_RSV1 &= ~ADC_MCU_ADCBUF_CFG0_RSRV1_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  Enables the ADC LP0 mode
  */
__STATIC_INLINE void ADC_LP0Enable(ADC_Type *ADCx)
{
    ADC_AUXADC_CFG0->ADC_RSV1 |= ADC_AUXADC_CFG0_RSRV0_Msk;
    ADC_MCU_ADCBUF_CFG0->ADCBUF_RSV1 |= ADC_MCU_ADCBUF_CFG0_RSRV0_Msk;
}	
/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @return none.
  * @brief  Disables the ADC LP0 mode
  */
__STATIC_INLINE void ADC_LP0Disable(ADC_Type *ADCx)
{
    ADC_AUXADC_CFG0->ADC_RSV1 &= ~ADC_AUXADC_CFG0_RSRV0_Msk;
	ADC_MCU_ADCBUF_CFG0->ADCBUF_RSV1 &= ~ADC_MCU_ADCBUF_CFG0_RSRV0_Msk;
}

/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @param[in] length: Regular Group Conversion Length from 1 to 16
  * @return none.
  * @brief  Set Regular Group Length
  */
__STATIC_INLINE void ADC_SetRegularGroupLength(ADC_Type *ADCx, uint32_t length)
{
    ADCx->RSQR1 = (ADCx->RSQR1 & ~(ADC_RSQR1_RSQL_Msk)) | ADC_RSQR1_RSQL(length - 1);
}
/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @param[in] seq: Regular Group sequence from 1 to 16
  * @param[in] channel: Regular Group sequence Channel from 0 to 17
  * @return none.
  * @brief  Set Regular Group sequence Channel
  */
__STATIC_INLINE void ADC_SetRegularGroupSequence(ADC_Type *ADCx, uint32_t seq, uint32_t channel)
{
    if (seq < 7)
    {
        ADCx->RSQR3 &= ~((0x1F) << (seq - 1) * 5);
        ADCx->RSQR3 |= (channel << ((seq - 1) * 5));
    }
    else if (seq < 13)
    {
        ADCx->RSQR2 &= ~((0x1F) << (seq - 7) * 5);
        ADCx->RSQR2 |= (channel << ((seq - 7) * 5));
    }
    else
    {
        ADCx->RSQR1 &= ~((0x1F) << (seq - 13) * 5);
        ADCx->RSQR1 |= (channel << ((seq - 13) * 5));
    }
    ADC_SetADChannelToAnalogInputPin(ADC, channel);
}
/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @param[in] length: Regular Group Conversion Length from 1 to 16
  * @return none.
  * @brief  Set Inject Group Length
  */
__STATIC_INLINE void ADC_SetInjectGroupLength(ADC_Type *ADCx, uint32_t length)
{
    ADCx->ISQR = (ADCx->ISQR & ~(ADC_ISQR_ISQL_Msk)) | ADC_ISQR_ISQL(length - 1);
}
/**
  * @param[in] ADCx: pointer to one of three ADC base register address.
  * @param[in] seq: Regular Group sequence from 1 to 4
  * @param[in] channel: Regular Group sequence Channel from 0 to 17
  * @return none.
  * @brief  Set Inject Group sequence Channel
  */
__STATIC_INLINE void ADC_SetInjectGroupSequence(ADC_Type *ADCx, uint32_t seq, uint32_t channel)
{
    ADCx->ISQR &= ~(0x1F << ((seq - 1) * 5));
    ADCx->ISQR |= (channel << ((seq - 1) * 5));
    ADC_SetADChannelToAnalogInputPin(ADC, channel);
}
#ifdef __cplusplus
}
#endif

#endif
