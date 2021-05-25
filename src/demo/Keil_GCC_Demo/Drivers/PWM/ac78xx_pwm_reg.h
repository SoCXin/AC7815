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

#ifndef AC78XX_PWM_REG_H_
#define AC78XX_PWM_REG_H_
#ifdef __cplusplus
extern "C" {
#endif
#include "stdint.h"
#include "stdio.h"
#include "cmsis_gcc.h"

#define __IO    volatile                    ///<All drivers need this type
#define __I     volatile const
//#define __STATIC_INLINE static __inline


/* ----------------------------------------------------------------------------
   -- PWM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/**
* @brief PWM configure struct.
*
*/
typedef struct {                                      ///< PWM1 Structure
    __IO uint32_t  INIT;                              ///< 0x00; PWM Initialize, Include Clock and Prescale Setting
    __IO uint32_t  CNT;                               ///< 0x04;PWM Counter Current Count Value
    __IO uint32_t  MCVR;                              ///< 0x08;PWM Counter Max Count Value Register
    struct {                                          ///< offset: 0xC, array step: 0x8 */
        __IO uint32_t CHSCR;                          ///< Channel (n) Status And Control, array offset: 0xC, array step: 0x8
        __IO uint32_t CHV;                            ///< Channel (n) Value, array offset: 0x10, array step: 0x8
    } CHANNELS[6];                                    ///<0x0c to 0x38*/
    __I  uint32_t  RESERVED[4];
    __IO uint32_t  CNTIN;                             ///< 0x4c; Counter Initial Value
    __IO uint32_t  STR;                               ///< 0x50; Status Register
    __IO uint32_t  FUNCSEL;                           ///< 0x54; PWM Features(Functions) Mode Selection Register
    __IO uint32_t  SYNC;                              ///< 0x58; Synchronization
    __IO uint32_t  OUTINIT;                           ///< 0x5c; Initial Value For Channels Output
    __IO uint32_t  OMCR;                              ///< 0x60; Output Mask Control Register
    __IO uint32_t  MODESEL;                           ///< 0x64; 0x64; PWM Function Mode Selection
    __IO uint32_t  DTSET;                             ///< 0x68; Deadtime Paramenters Setting Register
    __IO uint32_t  EXTTRIG;                           ///< 0x6c; PWM External Trigger
    __IO uint32_t  CHOPOLCR;                          ///< 0x70; Channels Output Polarity Control Register
    __IO uint32_t  FDSR;                              ///< 0x74; Fault Detect Status Register
    __IO uint32_t  CAPFILTER;                         ///< 0x78; Input Capture Filter Control
    __IO uint32_t  FFAFER;                            ///< 0x7c; Fault Filter and Fault Enable Register
    __IO uint32_t  QEI;                               ///< 0x80; Quadrature Encoder/Decoder Interface Configuration Register
    __IO uint32_t  CONF;                              ///< 0x84; Configuration
    __IO uint32_t  FLTPOL;                            ///< 0x88; PWM Fault Input Polarity
    __IO uint32_t  SYNCONF;                           ///< 0x8c; Synchronization Configuration
    __IO uint32_t  INVCR;                             ///< 0x90; PWM Inverse Control Register
    __IO uint32_t  CHOSWCR;                           ///< 0x94; PWM CHannel Software Output Control Register
} PWM_Type;

/* ----------------------------------------------------------------------------
   -- PWM Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------  PWM_INIT  --------------------------------- */
#define PWM_INIT_CLKSRC_Pos                  3                                                      ///< PWM INIT: CLKSRC Position              
#define PWM_INIT_CLKSRC_Msk                  (0x03UL << PWM_INIT_CLKSRC_Pos)                        ///< PWM INIT: CLKSRC Mask                  
#define PWM_INIT_CNTMODE_Pos                 5                                                      ///< PWM INIT: CNTMODE Position             
#define PWM_INIT_CNTMODE_Msk                 (0x01UL << PWM_INIT_CNTMODE_Pos)                       ///< PWM INIT: CNTMODE Mask                 
#define PWM_INIT_CNTOIE_Pos                  6                                                      ///< PWM INIT: CNTOIE Position              
#define PWM_INIT_CNTOIE_Msk                  (0x01UL << PWM_INIT_CNTOIE_Pos)                        ///< PWM INIT: CNTOIE Mask                  
#define PWM_INIT_CNTOF_Pos                   7                                                      ///< PWM INIT: CNTOF Position               
#define PWM_INIT_CNTOF_Msk                   (0x01UL << PWM_INIT_CNTOF_Pos)                         ///< PWM INIT: CNTOF Mask                   
#define PWM_INIT_CLKPSC_Pos                  8                                                      ///< PWM INIT: CLKPSC Position              
#define PWM_INIT_CLKPSC_Msk                  (0x0000ffffUL << PWM_INIT_CLKPSC_Pos)                  ///< PWM INIT: CLKPSC Mask                  

/* ----------------------------------  PWM_CNT  ---------------------------------- */
#define PWM_CNT_COUNT_Pos                    0                                                      ///< PWM CNT: COUNT Position                
#define PWM_CNT_COUNT_Msk                    (0x0000ffffUL << PWM_CNT_COUNT_Pos)                    ///< PWM CNT: COUNT Mask                    

/* ----------------------------------  PWM_MCVR  --------------------------------- */
#define PWM_MCVR_MCVR_Pos                    0                                                      ///< PWM MCVR: MCVR Position                
#define PWM_MCVR_MCVR_Msk                    (0x0000ffffUL << PWM_MCVR_MCVR_Pos)                    //< PWM MCVR: MCVR Mask                    

/* ---------------------------------  PWM_CHSCR  -------------------------------- */
#define PWM_CHSCR_ELSR0_Pos                 2                                                     ///< PWM CH0SCR: ELSR0 Position             
#define PWM_CHSCR_ELSR0_Msk                 (0x01UL << PWM_CHSCR_ELSR0_Pos)                       ///< PWM CH0SCR: ELSR0 Mask                 
#define PWM_CHSCR_ELSR1_Pos                 3                                                     ///< PWM CH0SCR: ELSR1 Position            
#define PWM_CHSCR_ELSR1_Msk                 (0x01UL << PWM_CHSCR_ELSR1_Pos)                       ///< PWM CH0SCR: ELSR1 Mask                 
#define PWM_CHSCR_MSR0_Pos                  4                                                     ///< PWM CH0SCR: MSR0 Position              
#define PWM_CHSCR_MSR0_Msk                  (0x01UL << PWM_CHSCR_MSR0_Pos)                        ///< PWM CH0SCR: MSR0 Mask                  
#define PWM_CHSCR_MSR1_Pos                  5                                                     ///< PWM CH0SCR: MSR1 Position              
#define PWM_CHSCR_MSR1_Msk                  (0x01UL << PWM_CHSCR_MSR1_Pos)                        ///< PWM CH0SCR: MSR1 Mask                  
#define PWM_CHSCR_CHIE_Pos                  6                                                     ///< PWM CH0SCR: CHIE Position              
#define PWM_CHSCR_CHIE_Msk                  (0x01UL << PWM_CHSCR_CHIE_Pos)                        ///< PWM CH0SCR: CHIE Mask                  
#define PWM_CHSCR_CHIF_Pos                  7                                                     ///< PWM CH0SCR: CHIF Position              
#define PWM_CHSCR_CHIF_Msk                  (0x01UL << PWM_CHSCR_CHIF_Pos)                        ///< PWM CH0SCR: CHIF Mask                  

/* ----------------------------------  PWM_CHV  --------------------------------- */
#define PWM_CHV_CHCVAL_Pos                  0                                                     ///< PWM CH0V: CHCVAL Position             
#define PWM_CHV_CHCVAL_Msk                  (0x0000ffffUL << PWM_CHV_CHCVAL_Pos)                  ///< PWM CH0V: CHCVAL Mask                  

/* ---------------------------------  PWM_CNTIN  --------------------------------- */
#define PWM_CNTIN_CNTINIT_Pos                0                                                    ///< PWM CNTIN: CNTINIT Position      
#define PWM_CNTIN_CNTINIT_Msk                (0x0000ffffUL << PWM_CNTIN_CNTINIT_Pos)              ///< PWM CNTIN: CNTINIT Mask              

/* ----------------------------------  PWM_STR  ---------------------------------- */
#define PWM_STR_CH0SF_Pos                    0                                                    ///< PWM STR: CH0SF Position             
#define PWM_STR_CH0SF_Msk                    (0x01UL << PWM_STR_CH0SF_Pos)                        ///< PWM STR: CH0SF Mask                  
#define PWM_STR_CH1SF_Pos                    1                                                    ///< PWM STR: CH1SF Position             
#define PWM_STR_CH1SF_Msk                    (0x01UL << PWM_STR_CH1SF_Pos)                        ///< PWM STR: CH1SF Mask                  
#define PWM_STR_CH2SF_Pos                    2                                                    ///< PWM STR: CH2SF Position             
#define PWM_STR_CH2SF_Msk                    (0x01UL << PWM_STR_CH2SF_Pos)                        ///< PWM STR: CH2SF Mask                  
#define PWM_STR_CH3SF_Pos                    3                                                    ///< PWM STR: CH3SF Position             
#define PWM_STR_CH3SF_Msk                    (0x01UL << PWM_STR_CH3SF_Pos)                        ///< PWM STR: CH3SF Mask                  
#define PWM_STR_CH4SF_Pos                    4                                                    ///< PWM STR: CH4SF Position             
#define PWM_STR_CH4SF_Msk                    (0x01UL << PWM_STR_CH4SF_Pos)                        ///< PWM STR: CH4SF Mask                  
#define PWM_STR_CH5SF_Pos                    5                                                    ///< PWM STR: CH5SF Position             
#define PWM_STR_CH5SF_Msk                    (0x01UL << PWM_STR_CH5SF_Pos)                        ///< PWM STR: CH5SF Mask                  

/* --------------------------------  PWM_FUNCSEL  -------------------------------- */
#define PWM_FUNCSEL_PWMEN2_Pos               0                                                    ///< PWM FUNCSEL: PWMEN2 Position        
#define PWM_FUNCSEL_PWMEN2_Msk               (0x01UL << PWM_FUNCSEL_PWMEN2_Pos)                   ///< PWM FUNCSEL: PWMEN2 Mask             
#define PWM_FUNCSEL_INIT_Pos                 1                                                    ///< PWM FUNCSEL: INIT Position          
#define PWM_FUNCSEL_INIT_Msk                 (0x01UL << PWM_FUNCSEL_INIT_Pos)                     ///< PWM FUNCSEL: INIT Mask               
#define PWM_FUNCSEL_WPDIS_Pos                2                                                    ///< PWM FUNCSEL: WPDIS Position         
#define PWM_FUNCSEL_WPDIS_Msk                (0x01UL << PWM_FUNCSEL_WPDIS_Pos)                    ///< PWM FUNCSEL: WPDIS Mask              
#define PWM_FUNCSEL_PWMSYNC_Pos              3                                                    ///< PWM FUNCSEL: PWMSYNC Position       
#define PWM_FUNCSEL_PWMSYNC_Msk              (0x01UL << PWM_FUNCSEL_PWMSYNC_Pos)                  ///< PWM FUNCSEL: PWMSYNC Mask            
#define PWM_FUNCSEL_CAPTEST_Pos              4                                                    ///< PWM FUNCSEL: CAPTEST Position       
#define PWM_FUNCSEL_CAPTEST_Msk              (0x01UL << PWM_FUNCSEL_CAPTEST_Pos)                  ///< PWM FUNCSEL: CAPTEST Mask            
#define PWM_FUNCSEL_FAULTMODE_Pos            5                                                    ///< PWM FUNCSEL: FAULTMODE Position     
#define PWM_FUNCSEL_FAULTMODE_Msk            (0x03UL << PWM_FUNCSEL_FAULTMODE_Pos)                ///< PWM FUNCSEL: FAULTMODE Mask          
#define PWM_FUNCSEL_FAULTIE_Pos              7                                                    ///< PWM FUNCSEL: FAULTIE Position       
#define PWM_FUNCSEL_FAULTIE_Msk              (0x01UL << PWM_FUNCSEL_FAULTIE_Pos)                  ///< PWM FUNCSEL: FAULTIE Mask            

/* ----------------------------------  PWM_SYNC  --------------------------------- */
#define PWM_SYNC_MINSYNCP_Pos                0                                                    ///< PWM SYNC: MINSYNCP Position         
#define PWM_SYNC_MINSYNCP_Msk                (0x01UL << PWM_SYNC_MINSYNCP_Pos)                    ///< PWM SYNC: MINSYNCP Mask              
#define PWM_SYNC_MAXSYNCP_Pos                1                                                    ///< PWM SYNC: MAXSYNCP Position         
#define PWM_SYNC_MAXSYNCP_Msk                (0x01UL << PWM_SYNC_MAXSYNCP_Pos)                    ///< PWM SYNC: MAXSYNCP Mask              
#define PWM_SYNC_REINIT_Pos                  2                                                    ///< PWM SYNC: REINIT Position           
#define PWM_SYNC_REINIT_Msk                  (0x01UL << PWM_SYNC_REINIT_Pos)                      ///< PWM SYNC: REINIT Mask                
#define PWM_SYNC_OMSYNCP_Pos                 3                                                    ///< PWM SYNC: OMSYNCP Position          
#define PWM_SYNC_OMSYNCP_Msk                 (0x01UL << PWM_SYNC_OMSYNCP_Pos)                     ///< PWM SYNC: OMSYNCP Mask               
#define PWM_SYNC_ACMPTRIG_Pos                4                                                    ///< PWM SYNC: ACMPTRIG Position         
#define PWM_SYNC_ACMPTRIG_Msk                (0x01UL << PWM_SYNC_ACMPTRIG_Pos)                    ///< PWM SYNC: ACMPTRIG Mask              
#define PWM_SYNC_PWMTRIG_Pos                5                                                     ///< PWM SYNC: PWMTRIG Position           
#define PWM_SYNC_PWMTRIG_Msk                (0x01UL << PWM_SYNC_PWMTRIG_Pos)                      ///< PWM SYNC: PWMTRIG Mask                *
#define PWM_SYNC_SWTRIG_Pos                  6                                                    ///< PWM SYNC: SWTRIG Position           
#define PWM_SYNC_SWTRIG_Msk                  (0x01UL << PWM_SYNC_SWTRIG_Pos)                      ///< PWM SYNC: SWTRIG Mask                
#define PWM_SYNC_SWSYNC_Pos                  7                                                    ///< PWM SYNC: SWSYNC Position           
#define PWM_SYNC_SWSYNC_Msk                  (0x01UL << PWM_SYNC_SWSYNC_Pos)                      ///< PWM SYNC: SWSYNC Mask                

/* --------------------------------  PWM_OUTINIT  -------------------------------- */
#define PWM_OUTINIT_CH0OIV_Pos               0                                                    ///< PWM OUTINIT: CH0OIV Position        
#define PWM_OUTINIT_CH0OIV_Msk               (0x01UL << PWM_OUTINIT_CH0OIV_Pos)                   ///< PWM OUTINIT: CH0OIV Mask             
#define PWM_OUTINIT_CH1OIV_Pos               1                                                    ///< PWM OUTINIT: CH1OIV Position        
#define PWM_OUTINIT_CH1OIV_Msk               (0x01UL << PWM_OUTINIT_CH1OIV_Pos)                   ///< PWM OUTINIT: CH1OIV Mask             
#define PWM_OUTINIT_CH2OIV_Pos               2                                                    ///< PWM OUTINIT: CH2OIV Position        
#define PWM_OUTINIT_CH2OIV_Msk               (0x01UL << PWM_OUTINIT_CH2OIV_Pos)                   ///< PWM OUTINIT: CH2OIV Mask             
#define PWM_OUTINIT_CH3OIV_Pos               3                                                    ///< PWM OUTINIT: CH3OIV Position        
#define PWM_OUTINIT_CH3OIV_Msk               (0x01UL << PWM_OUTINIT_CH3OIV_Pos)                   ///< PWM OUTINIT: CH3OIV Mask             
#define PWM_OUTINIT_CH4OIV_Pos               4                                                    ///< PWM OUTINIT: CH4OIV Position        
#define PWM_OUTINIT_CH4OIV_Msk               (0x01UL << PWM_OUTINIT_CH4OIV_Pos)                   ///< PWM OUTINIT: CH4OIV Mask             
#define PWM_OUTINIT_CH5OIV_Pos               5                                                    ///< PWM OUTINIT: CH5OIV Position        
#define PWM_OUTINIT_CH5OIV_Msk               (0x01UL << PWM_OUTINIT_CH5OIV_Pos)                   ///< PWM OUTINIT: CH5OIV Mask             

/* ----------------------------------  PWM_OMCR  --------------------------------- */
#define PWM_OMCR_CH0OMEN_Pos                 0                                                    ///< PWM OMCR: CH0OMEN Position          
#define PWM_OMCR_CH0OMEN_Msk                 (0x01UL << PWM_OMCR_CH0OMEN_Pos)                     ///< PWM OMCR: CH0OMEN Mask               
#define PWM_OMCR_CH1OMEN_Pos                 1                                                    ///< PWM OMCR: CH1OMEN Position          
#define PWM_OMCR_CH1OMEN_Msk                 (0x01UL << PWM_OMCR_CH1OMEN_Pos)                     ///< PWM OMCR: CH1OMEN Mask               
#define PWM_OMCR_CH2OMEN_Pos                 2                                                    ///< PWM OMCR: CH2OMEN Position          
#define PWM_OMCR_CH2OMEN_Msk                 (0x01UL << PWM_OMCR_CH2OMEN_Pos)                     ///< PWM OMCR: CH2OMEN Mask               
#define PWM_OMCR_CH3OMEN_Pos                 3                                                    ///< PWM OMCR: CH3OMEN Position          
#define PWM_OMCR_CH3OMEN_Msk                 (0x01UL << PWM_OMCR_CH3OMEN_Pos)                     ///< PWM OMCR: CH3OMEN Mask               
#define PWM_OMCR_CH4OMEN_Pos                 4                                                    ///< PWM OMCR: CH4OMEN Position          
#define PWM_OMCR_CH4OMEN_Msk                 (0x01UL << PWM_OMCR_CH4OMEN_Pos)                     ///< PWM OMCR: CH4OMEN Mask               
#define PWM_OMCR_CH5OMEN_Pos                 5                                                    ///< PWM OMCR: CH5OMEN Position          
#define PWM_OMCR_CH5OMEN_Msk                 (0x01UL << PWM_OMCR_CH5OMEN_Pos)                     ///< PWM OMCR: CH5OMEN Mask               

/* --------------------------------  PWM_MODESEL  -------------------------------- */
#define PWM_MODESEL_PAIR0COMBINEN_Pos        0                                                    ///< PWM MODESEL: PAIR0COMBINEN Position 
#define PWM_MODESEL_PAIR0COMBINEN_Msk        (0x01UL << PWM_MODESEL_PAIR0COMBINEN_Pos)            ///< PWM MODESEL: PAIR0COMBINEN Mask      
#define PWM_MODESEL_PAIR0COMPEN_Pos          1                                                    ///< PWM MODESEL: PAIR0COMPEN Position   
#define PWM_MODESEL_PAIR0COMPEN_Msk          (0x01UL << PWM_MODESEL_PAIR0COMPEN_Pos)              ///< PWM MODESEL: PAIR0COMPEN Mask        
#define PWM_MODESEL_PAIR0DECAPEN_Pos         2                                                    ///< PWM MODESEL: PAIR0DECAPEN Position  
#define PWM_MODESEL_PAIR0DECAPEN_Msk         (0x01UL << PWM_MODESEL_PAIR0DECAPEN_Pos)             ///< PWM MODESEL: PAIR0DECAPEN Mask       
#define PWM_MODESEL_PAIR0DECAP_Pos           3                                                    ///< PWM MODESEL: PAIR0DECAP Position    
#define PWM_MODESEL_PAIR0DECAP_Msk           (0x01UL << PWM_MODESEL_PAIR0DECAP_Pos)               ///< PWM MODESEL: PAIR0DECAP Mask         
#define PWM_MODESEL_PAIR0DTEN_Pos            4                                                    ///< PWM MODESEL: PAIR0DTEN Position     
#define PWM_MODESEL_PAIR0DTEN_Msk            (0x01UL << PWM_MODESEL_PAIR0DTEN_Pos)                ///< PWM MODESEL: PAIR0DTEN Mask          
#define PWM_MODESEL_PAIR0SYNCEN_Pos          5                                                    ///< PWM MODESEL: PAIR0SYNCEN Position   
#define PWM_MODESEL_PAIR0SYNCEN_Msk          (0x01UL << PWM_MODESEL_PAIR0SYNCEN_Pos)              ///< PWM MODESEL: PAIR0SYNCEN Mask        
#define PWM_MODESEL_PAIR0FAULTEN_Pos         6                                                    ///< PWM MODESEL: PAIR0FAULTEN Position  
#define PWM_MODESEL_PAIR0FAULTEN_Msk         (0x01UL << PWM_MODESEL_PAIR0FAULTEN_Pos)             ///< PWM MODESEL: PAIR0FAULTEN Mask       
#define PWM_MODESEL_PAIR1COMBINEN_Pos         8                                                   ///< PWM MODESEL: PAIR1COMBINE Position 
#define PWM_MODESEL_PAIR1COMBINEN_Msk         (0x01UL << PWM_MODESEL_PAIR1COMBINEN_Pos)           ///< PWM MODESEL: PAIR1COMBINE Mask     
#define PWM_MODESEL_PAIR1COMPEN_Pos          9                                                    ///< PWM MODESEL: PAIR1COMPEN Position   
#define PWM_MODESEL_PAIR1COMPEN_Msk          (0x01UL << PWM_MODESEL_PAIR1COMPEN_Pos)              ///< PWM MODESEL: PAIR1COMPEN Mask        
#define PWM_MODESEL_PAIR1DECAPEN_Pos         10                                                   ///< PWM MODESEL: PAIR1DECAPEN Position  
#define PWM_MODESEL_PAIR1DECAPEN_Msk         (0x01UL << PWM_MODESEL_PAIR1DECAPEN_Pos)             ///< PWM MODESEL: PAIR1DECAPEN Mask       
#define PWM_MODESEL_PAIR1DECAP_Pos           11                                                   ///< PWM MODESEL: PAIR1DECAP Position    
#define PWM_MODESEL_PAIR1DECAP_Msk           (0x01UL << PWM_MODESEL_PAIR1DECAP_Pos)               ///< PWM MODESEL: PAIR1DECAP Mask         
#define PWM_MODESEL_PAIR1DTEN_Pos            12                                                   ///< PWM MODESEL: PAIR1DTEN Position     
#define PWM_MODESEL_PAIR1DTEN_Msk            (0x01UL << PWM_MODESEL_PAIR1DTEN_Pos)                ///< PWM MODESEL: PAIR1DTEN Mask          
#define PWM_MODESEL_PAIR1SYNCEN_Pos          13                                                   ///< PWM MODESEL: PAIR1SYNCEN Position   
#define PWM_MODESEL_PAIR1SYNCEN_Msk          (0x01UL << PWM_MODESEL_PAIR1SYNCEN_Pos)              ///< PWM MODESEL: PAIR1SYNCEN Mask        
#define PWM_MODESEL_PAIR1FAULTEN_Pos         14                                                   ///< PWM MODESEL: PAIR1FAULTEN Position  
#define PWM_MODESEL_PAIR1FAULTEN_Msk         (0x01UL << PWM_MODESEL_PAIR1FAULTEN_Pos)             ///< PWM MODESEL: PAIR1FAULTEN Mask       
#define PWM_MODESEL_PAIR2COMBINEN_Pos         16                                                  ///< PWM MODESEL: PAIR2COMBINE Position 
#define PWM_MODESEL_PAIR2COMBINEN_Msk         (0x01UL << PWM_MODESEL_PAIR2COMBINEN_Pos)           ///< PWM MODESEL: PAIR2COMBINE Mask     
#define PWM_MODESEL_PAIR2COMPEN_Pos          17                                                   ///< PWM MODESEL: PAIR2COMPEN Position   
#define PWM_MODESEL_PAIR2COMPEN_Msk          (0x01UL << PWM_MODESEL_PAIR2COMPEN_Pos)              ///< PWM MODESEL: PAIR2COMPEN Mask        
#define PWM_MODESEL_PAIR2DECAPEN_Pos         18                                                   ///< PWM MODESEL: PAIR2DECAPEN Position  
#define PWM_MODESEL_PAIR2DECAPEN_Msk         (0x01UL << PWM_MODESEL_PAIR2DECAPEN_Pos)             ///< PWM MODESEL: PAIR2DECAPEN Mask       
#define PWM_MODESEL_PAIR2DECAP_Pos           19                                                   ///< PWM MODESEL: PAIR2DECAP Position    
#define PWM_MODESEL_PAIR2DECAP_Msk           (0x01UL << PWM_MODESEL_PAIR2DECAP_Pos)               ///< PWM MODESEL: PAIR2DECAP Mask         
#define PWM_MODESEL_PAIR2DTEN_Pos            20                                                   ///< PWM MODESEL: PAIR2DTEN Position     
#define PWM_MODESEL_PAIR2DTEN_Msk            (0x01UL << PWM_MODESEL_PAIR2DTEN_Pos)                ///< PWM MODESEL: PAIR2DTEN Mask          
#define PWM_MODESEL_PAIR2SYNCEN_Pos          21                                                   ///< PWM MODESEL: PAIR2SYNCEN Position   
#define PWM_MODESEL_PAIR2SYNCEN_Msk          (0x01UL << PWM_MODESEL_PAIR2SYNCEN_Pos)              ///< PWM MODESEL: PAIR2SYNCEN Mask        
#define PWM_MODESEL_PAIR2FAULTEN_Pos         22                                                   ///< PWM MODESEL: PAIR2FAULTEN Position  
#define PWM_MODESEL_PAIR2FAULTEN_Msk         (0x01UL << PWM_MODESEL_PAIR2FAULTEN_Pos)             ///< PWM MODESEL: PAIR2FAULTEN Mask       

/* ---------------------------------  PWM_DTSET  --------------------------------- */
#define PWM_DTSET_DTVAL_Pos                  0                                                    ///< PWM DTSET: DTVAL Position           
#define PWM_DTSET_DTVAL_Msk                  (0x3fUL << PWM_DTSET_DTVAL_Pos)                      ///< PWM DTSET: DTVAL Mask                
#define PWM_DTSET_DTPSC_Pos                  6                                                    ///< PWM DTSET: DTPSC Position           
#define PWM_DTSET_DTPSC_Msk                  (0x03UL << PWM_DTSET_DTPSC_Pos)                      ///< PWM DTSET: DTPSC Mask                
/* --------------------------------  PWM_EXTTRIG  -------------------------------- */
#define PWM_EXTTRIG_CH2TRIG_Pos              0                                                    ///< PWM EXTTRIG: CH2TRIG Position       
#define PWM_EXTTRIG_CH2TRIG_Msk              (0x01UL << PWM_EXTTRIG_CH2TRIG_Pos)                  ///< PWM EXTTRIG: CH2TRIG Mask            
#define PWM_EXTTRIG_CH3TRIG_Pos              1                                                    ///< PWM EXTTRIG: CH3TRIG Position       
#define PWM_EXTTRIG_CH3TRIG_Msk              (0x01UL << PWM_EXTTRIG_CH3TRIG_Pos)                  ///< PWM EXTTRIG: CH3TRIG Mask            
#define PWM_EXTTRIG_CH4TRIG_Pos              2                                                    ///< PWM EXTTRIG: CH4TRIG Position       
#define PWM_EXTTRIG_CH4TRIG_Msk              (0x01UL << PWM_EXTTRIG_CH4TRIG_Pos)                  ///< PWM EXTTRIG: CH4TRIG Mask            
#define PWM_EXTTRIG_CH5TRIG_Pos              3                                                    ///< PWM EXTTRIG: CH5TRIG Position       
#define PWM_EXTTRIG_CH5TRIG_Msk              (0x01UL << PWM_EXTTRIG_CH5TRIG_Pos)                  ///< PWM EXTTRIG: CH5TRIG Mask            
#define PWM_EXTTRIG_CH0TRIG_Pos              4                                                    ///< PWM EXTTRIG: CH0TRIG Position       
#define PWM_EXTTRIG_CH0TRIG_Msk              (0x01UL << PWM_EXTTRIG_CH0TRIG_Pos)                  ///< PWM EXTTRIG: CH0TRIG Mask            
#define PWM_EXTTRIG_CH1TRIG_Pos              5                                                    ///< PWM EXTTRIG: CH1TRIG Position       
#define PWM_EXTTRIG_CH1TRIG_Msk              (0x01UL << PWM_EXTTRIG_CH1TRIG_Pos)                  ///< PWM EXTTRIG: CH1TRIG Mask            
#define PWM_EXTTRIG_INITTRIGEN_Pos           6                                                    ///< PWM EXTTRIG: INITTRIGEN Position    
#define PWM_EXTTRIG_INITTRIGEN_Msk           (0x01UL << PWM_EXTTRIG_INITTRIGEN_Pos)               ///< PWM EXTTRIG: INITTRIGEN Mask         
#define PWM_EXTTRIG_TRIGF_Pos                7                                                    ///< PWM EXTTRIG: TRIGF Position         
#define PWM_EXTTRIG_TRIGF_Msk                (0x01UL << PWM_EXTTRIG_TRIGF_Pos)                    ///< PWM EXTTRIG: TRIGF Mask              

/* --------------------------------  PWM_CHOPOLCR  ------------------------------- */
#define PWM_CHOPOLCR_CH0POL_Pos              0                                                    ///< PWM CHOPOLCR: CH0POL Position       
#define PWM_CHOPOLCR_CH0POL_Msk              (0x01UL << PWM_CHOPOLCR_CH0POL_Pos)                  ///< PWM CHOPOLCR: CH0POL Mask            
#define PWM_CHOPOLCR_CH1POL_Pos              1                                                    ///< PWM CHOPOLCR: CH1POL Position       
#define PWM_CHOPOLCR_CH1POL_Msk              (0x01UL << PWM_CHOPOLCR_CH1POL_Pos)                  ///< PWM CHOPOLCR: CH1POL Mask            
#define PWM_CHOPOLCR_CH2POL_Pos              2                                                    ///< PWM CHOPOLCR: CH2POL Position       
#define PWM_CHOPOLCR_CH2POL_Msk              (0x01UL << PWM_CHOPOLCR_CH2POL_Pos)                  ///< PWM CHOPOLCR: CH2POL Mask            
#define PWM_CHOPOLCR_CH3POL_Pos              3                                                    ///< PWM CHOPOLCR: CH3POL Position       
#define PWM_CHOPOLCR_CH3POL_Msk              (0x01UL << PWM_CHOPOLCR_CH3POL_Pos)                  ///< PWM CHOPOLCR: CH3POL Mask            
#define PWM_CHOPOLCR_CH4POL_Pos              4                                                    ///< PWM CHOPOLCR: CH4POL Position       
#define PWM_CHOPOLCR_CH4POL_Msk              (0x01UL << PWM_CHOPOLCR_CH4POL_Pos)                  ///< PWM CHOPOLCR: CH4POL Mask            
#define PWM_CHOPOLCR_CH5POL_Pos              5                                                    ///< PWM CHOPOLCR: CH5POL Position       
#define PWM_CHOPOLCR_CH5POL_Msk              (0x01UL << PWM_CHOPOLCR_CH5POL_Pos)                  ///< PWM CHOPOLCR: CH5POL Mask            

/* ----------------------------------  PWM_FDSR  --------------------------------- */
#define PWM_FDSR_FAULTDF0_Pos                0                                                    ///< PWM FDSR: FAULTDF0 Position         
#define PWM_FDSR_FAULTDF0_Msk                (0x01UL << PWM_FDSR_FAULTDF0_Pos)                    ///< PWM FDSR: FAULTDF0 Mask              
#define PWM_FDSR_FAULTDF1_Pos                1                                                    ///< PWM FDSR: FAULTDF1 Position         
#define PWM_FDSR_FAULTDF1_Msk                (0x01UL << PWM_FDSR_FAULTDF1_Pos)                    ///< PWM FDSR: FAULTDF1 Mask              
#define PWM_FDSR_FAULTDF2_Pos                2                                                    ///< PWM FDSR: FAULTDF2 Position         
#define PWM_FDSR_FAULTDF2_Msk                (0x01UL << PWM_FDSR_FAULTDF2_Pos)                    ///< PWM FDSR: FAULTDF2 Mask              
#define PWM_FDSR_FAULTDF3_Pos                3                                                    ///< PWM FDSR: FAULTDF3 Position         
#define PWM_FDSR_FAULTDF3_Msk                (0x01UL << PWM_FDSR_FAULTDF3_Pos)                    ///< PWM FDSR: FAULTDF3 Mask              
#define PWM_FDSR_FAULTIN_Pos                 5                                                    ///< PWM FDSR: FAULTIN Position          
#define PWM_FDSR_FAULTIN_Msk                 (0x01UL << PWM_FDSR_FAULTIN_Pos)                     ///< PWM FDSR: FAULTIN Mask               
#define PWM_FDSR_WPEN_Pos                    6                                                    ///< PWM FDSR: WPEN Position             
#define PWM_FDSR_WPEN_Msk                    (0x01UL << PWM_FDSR_WPEN_Pos)                        ///< PWM FDSR: WPEN Mask                  
#define PWM_FDSR_FAULTDF_Pos                 7                                                    ///< PWM FDSR: FAULTDF Position          
#define PWM_FDSR_FAULTDF_Msk                 (0x01UL << PWM_FDSR_FAULTDF_Pos)                     ///< PWM FDSR: FAULTDF Mask               

/* -------------------------------  PWM_CAPFILTER  ------------------------------- */
#define PWM_CAPFILTER_CH0CAPFVAL_Pos         0                                                    ///< PWM CAPFILTER: CH0CAPFVAL Position  
#define PWM_CAPFILTER_CH0CAPFVAL_Msk         (0x1fUL << PWM_CAPFILTER_CH0CAPFVAL_Pos)             ///< PWM CAPFILTER: CH0CAPFVAL Mask       
#define PWM_CAPFILTER_CH1CAPFVAL_Pos         5                                                    ///< PWM CAPFILTER: CH1CAPFVAL Position  
#define PWM_CAPFILTER_CH1CAPFVAL_Msk         (0x1fUL << PWM_CAPFILTER_CH1CAPFVAL_Pos)             ///< PWM CAPFILTER: CH1CAPFVAL Mask       
#define PWM_CAPFILTER_CH2CAPFVAL_Pos         10                                                   ///< PWM CAPFILTER: CH2CAPFVAL Position  
#define PWM_CAPFILTER_CH2CAPFVAL_Msk         (0x1fUL << PWM_CAPFILTER_CH2CAPFVAL_Pos)             ///< PWM CAPFILTER: CH2CAPFVAL Mask       
#define PWM_CAPFILTER_CH3CAPFVAL_Pos         15                                                   ///< PWM CAPFILTER: CH3CAPFVAL Position  
#define PWM_CAPFILTER_CH3CAPFVAL_Msk         (0x1fUL << PWM_CAPFILTER_CH3CAPFVAL_Pos)             ///< PWM CAPFILTER: CH3CAPFVAL Mask       

/* ---------------------------------  PWM_FFAFER  -------------------------------- */
#define PWM_FFAFER_FER0EN_Pos                0                                                    ///< PWM FFAFER: FER0EN Position         
#define PWM_FFAFER_FER0EN_Msk                (0x01UL << PWM_FFAFER_FER0EN_Pos)                    ///< PWM FFAFER: FER0EN Mask              
#define PWM_FFAFER_FER1EN_Pos                1                                                    ///< PWM FFAFER: FER1EN Position         
#define PWM_FFAFER_FER1EN_Msk                (0x01UL << PWM_FFAFER_FER1EN_Pos)                    ///< PWM FFAFER: FER1EN Mask              
#define PWM_FFAFER_FER2EN_Pos                2                                                    ///< PWM FFAFER: FER2EN Position         
#define PWM_FFAFER_FER2EN_Msk                (0x01UL << PWM_FFAFER_FER2EN_Pos)                    ///< PWM FFAFER: FER2EN Mask              
#define PWM_FFAFER_FER3EN_Pos                3                                                    ///< PWM FFAFER: FER3EN Position         
#define PWM_FFAFER_FER3EN_Msk                (0x01UL << PWM_FFAFER_FER3EN_Pos)                    ///< PWM FFAFER: FER3EN Mask              
#define PWM_FFAFER_FF0EN_Pos                 4                                                    ///< PWM FFAFER: FF0EN Position          
#define PWM_FFAFER_FF0EN_Msk                 (0x01UL << PWM_FFAFER_FF0EN_Pos)                     ///< PWM FFAFER: FF0EN Mask               
#define PWM_FFAFER_FF1EN_Pos                 5                                                    ///< PWM FFAFER: FF1EN Position          
#define PWM_FFAFER_FF1EN_Msk                 (0x01UL << PWM_FFAFER_FF1EN_Pos)                     ///< PWM FFAFER: FF1EN Mask               
#define PWM_FFAFER_FF2EN_Pos                 6                                                    ///< PWM FFAFER: FF2EN Position          
#define PWM_FFAFER_FF2EN_Msk                 (0x01UL << PWM_FFAFER_FF2EN_Pos)                     ///< PWM FFAFER: FF2EN Mask               
#define PWM_FFAFER_FF3EN_Pos                 7                                                    ///< PWM FFAFER: FF3EN Position          
#define PWM_FFAFER_FF3EN_Msk                 (0x01UL << PWM_FFAFER_FF3EN_Pos)                     ///< PWM FFAFER: FF3EN Mask               
#define PWM_FFAFER_FFVAL_Pos                 8                                                    ///< PWM FFAFER: FFVAL Position          
#define PWM_FFAFER_FFVAL_Msk                 (0x0fUL << PWM_FFAFER_FFVAL_Pos)                     ///< PWM FFAFER: FFVAL Mask               

/* ----------------------------------  PWM_QEI  ---------------------------------- */
#define PWM_QEI_QEIEN_Pos                    0                                                    ///< PWM QEI: QEIEN Position             
#define PWM_QEI_QEIEN_Msk                    (0x01UL << PWM_QEI_QEIEN_Pos)                        ///< PWM QEI: QEIEN Mask                  
#define PWM_QEI_TOFDIR_Pos                   1                                                    ///< PWM QEI: TOFDIR Position            
#define PWM_QEI_TOFDIR_Msk                   (0x01UL << PWM_QEI_TOFDIR_Pos)                       ///< PWM QEI: TOFDIR Mask                 
#define PWM_QEI_QUADIR_Pos                   2                                                    ///< PWM QEI: QUADIR Position            
#define PWM_QEI_QUADIR_Msk                   (0x01UL << PWM_QEI_QUADIR_Pos)                       ///< PWM QEI: QUADIR Mask                 
#define PWM_QEI_QUADMODE_Pos                 3                                                    ///< PWM QEI: QUADMODE Position          
#define PWM_QEI_QUADMODE_Msk                 (0x01UL << PWM_QEI_QUADMODE_Pos)                     ///< PWM QEI: QUADMODE Mask               
#define PWM_QEI_PHBPOL_Pos                   4                                                    ///< PWM QEI: PHBPOL Position            
#define PWM_QEI_PHBPOL_Msk                   (0x01UL << PWM_QEI_PHBPOL_Pos)                       ///< PWM QEI: PHBPOL Mask                 
#define PWM_QEI_PHAPOL_Pos                   5                                                    ///< PWM QEI: PHAPOL Position            
#define PWM_QEI_PHAPOL_Msk                   (0x01UL << PWM_QEI_PHAPOL_Pos)                       ///< PWM QEI: PHAPOL Mask                 
#define PWM_QEI_PHBFLTREN_Pos                6                                                    ///< PWM QEI: PHBFLTREN Position         
#define PWM_QEI_PHBFLTREN_Msk                (0x01UL << PWM_QEI_PHBFLTREN_Pos)                    ///< PWM QEI: PHBFLTREN Mask              
#define PWM_QEI_PHAFLTREN_Pos                7                                                    ///< PWM QEI: PHAFLTREN Position         
#define PWM_QEI_PHAFLTREN_Msk                (0x01UL << PWM_QEI_PHAFLTREN_Pos)                    ///< PWM QEI: PHAFLTREN Mask              

/* ----------------------------------  PWM_CONF  --------------------------------- */
#define PWM_CONF_CNTOFNUM_Pos                0                                                    ///< PWM CONF: CNTOFNUM Position         
#define PWM_CONF_CNTOFNUM_Msk                (0x7fUL << PWM_CONF_CNTOFNUM_Pos)                    ///< PWM CONF: CNTOFNUM Mask              
#define PWM_CONF_BDMMODE_Pos                 7                                                    ///< PWM CONF: BDMMODE Position          
#define PWM_CONF_BDMMODE_Msk                 (0x03UL << PWM_CONF_BDMMODE_Pos)                     ///< PWM CONF: BDMMODE Mask               
#define PWM_CONF_GTBEEN_Pos                  9                                                    ///< PWM CONF: GTBEEN Position           
#define PWM_CONF_GTBEEN_Msk                  (0x01UL << PWM_CONF_GTBEEN_Pos)                      ///< PWM CONF: GTBEEN Mask                
#define PWM_CONF_GTBEOUT_Pos                 10                                                   ///< PWM CONF: GTBEOUT Position          
#define PWM_CONF_GTBEOUT_Msk                 (0x01UL << PWM_CONF_GTBEOUT_Pos)                     ///< PWM CONF: GTBEOUT Mask               
#define PWM_CONF_EVENTPSC_Pos                16                                                   ///< PWM CONF: EVENTPSC Position         
#define PWM_CONF_EVENTPSC_Msk                (0x00000fffUL << PWM_CONF_EVENTPSC_Pos)              ///< PWM CONF: EVENTPSC Mask              

/* ---------------------------------  PWM_FLTPOL  -------------------------------- */
#define PWM_FLTPOL_FLT0POL_Pos               0                                                    ///< PWM FLTPOL: FLT0POL Position        
#define PWM_FLTPOL_FLT0POL_Msk               (0x01UL << PWM_FLTPOL_FLT0POL_Pos)                   ///< PWM FLTPOL: FLT0POL Mask             
#define PWM_FLTPOL_FLT1POL_Pos               1                                                    ///< PWM FLTPOL: FLT1POL Position        
#define PWM_FLTPOL_FLT1POL_Msk               (0x01UL << PWM_FLTPOL_FLT1POL_Pos)                   ///< PWM FLTPOL: FLT1POL Mask             
#define PWM_FLTPOL_FLT2POL_Pos               2                                                    ///< PWM FLTPOL: FLT2POL Position        
#define PWM_FLTPOL_FLT2POL_Msk               (0x01UL << PWM_FLTPOL_FLT2POL_Pos)                   ///< PWM FLTPOL: FLT2POL Mask             
#define PWM_FLTPOL_FLT3POL_Pos               3                                                    ///< PWM FLTPOL: FLT3POL Position        
#define PWM_FLTPOL_FLT3POL_Msk               (0x01UL << PWM_FLTPOL_FLT3POL_Pos)                   ///< PWM FLTPOL: FLT3POL Mask             

/* --------------------------------  PWM_SYNCONF  -------------------------------- */
#define PWM_SYNCONF_HWTRIGMODESEL_Pos        0                                                    ///< PWM SYNCONF: HWTRIGMODESEL Position 
#define PWM_SYNCONF_HWTRIGMODESEL_Msk        (0x01UL << PWM_SYNCONF_HWTRIGMODESEL_Pos)            ///< PWM SYNCONF: HWTRIGMODESEL Mask      
#define PWM_SYNCONF_CNTINC_Pos               2                                                    ///< PWM SYNCONF: CNTINC Position        
#define PWM_SYNCONF_CNTINC_Msk               (0x01UL << PWM_SYNCONF_CNTINC_Pos)                   ///< PWM SYNCONF: CNTINC Mask             
#define PWM_SYNCONF_INVC_Pos                 4                                                    ///< PWM SYNCONF: INVC Position          
#define PWM_SYNCONF_INVC_Msk                 (0x01UL << PWM_SYNCONF_INVC_Pos)                     ///< PWM SYNCONF: INVC Mask               
#define PWM_SYNCONF_SWOC_Pos                 5                                                    ///< PWM SYNCONF: SWOC Position          
#define PWM_SYNCONF_SWOC_Msk                 (0x01UL << PWM_SYNCONF_SWOC_Pos)                     ///< PWM SYNCONF: SWOC Mask               
#define PWM_SYNCONF_SYNCMODE_Pos             7                                                    ///< PWM SYNCONF: SYNCMODE Position      
#define PWM_SYNCONF_SYNCMODE_Msk             (0x01UL << PWM_SYNCONF_SYNCMODE_Pos)                 ///< PWM SYNCONF: SYNCMODE Mask           
#define PWM_SYNCONF_CNTVSWSYNC_Pos           8                                                    ///< PWM SYNCONF: CNTVSWSYNC Position    
#define PWM_SYNCONF_CNTVSWSYNC_Msk           (0x01UL << PWM_SYNCONF_CNTVSWSYNC_Pos)               ///< PWM SYNCONF: CNTVSWSYNC Mask         
#define PWM_SYNCONF_PWMSVSWSYNC_Pos          9                                                    ///< PWM SYNCONF: PWMSVSWSYNC Position   
#define PWM_SYNCONF_PWMSVSWSYNC_Msk          (0x01UL << PWM_SYNCONF_PWMSVSWSYNC_Pos)              ///< PWM SYNCONF: PWMSVSWSYNC Mask        
#define PWM_SYNCONF_OMVSWSYNC_Pos            10                                                   ///< PWM SYNCONF: OMVSWSYNC Position     
#define PWM_SYNCONF_OMVSWSYNC_Msk            (0x01UL << PWM_SYNCONF_OMVSWSYNC_Pos)                ///< PWM SYNCONF: OMVSWSYNC Mask          
#define PWM_SYNCONF_INVSWSYNC_Pos            11                                                   ///< PWM SYNCONF: INVSWSYNC Position     
#define PWM_SYNCONF_INVSWSYNC_Msk            (0x01UL << PWM_SYNCONF_INVSWSYNC_Pos)                ///< PWM SYNCONF: INVSWSYNC Mask          
#define PWM_SYNCONF_SWVSWSYNC_Pos            12                                                   ///< PWM SYNCONF: SWVSWSYNC Position     
#define PWM_SYNCONF_SWVSWSYNC_Msk            (0x01UL << PWM_SYNCONF_SWVSWSYNC_Pos)                ///< PWM SYNCONF: SWVSWSYNC Mask          
#define PWM_SYNCONF_CNTVHWSYNC_Pos           16                                                   ///< PWM SYNCONF: CNTVHWSYNC Position    
#define PWM_SYNCONF_CNTVHWSYNC_Msk           (0x01UL << PWM_SYNCONF_CNTVHWSYNC_Pos)               ///< PWM SYNCONF: CNTVHWSYNC Mask         
#define PWM_SYNCONF_PWMSVHWSYNC_Pos          17                                                   ///< PWM SYNCONF: PWMSVHWSYNC Position   
#define PWM_SYNCONF_PWMSVHWSYNC_Msk          (0x01UL << PWM_SYNCONF_PWMSVHWSYNC_Pos)              ///< PWM SYNCONF: PWMSVHWSYNC Mask        
#define PWM_SYNCONF_OMVHWSYNC_Pos            18                                                   ///< PWM SYNCONF: OMVHWSYNC Position     
#define PWM_SYNCONF_OMVHWSYNC_Msk            (0x01UL << PWM_SYNCONF_OMVHWSYNC_Pos)                ///< PWM SYNCONF: OMVHWSYNC Mask          
#define PWM_SYNCONF_INVHWSYNC_Pos            19                                                   ///< PWM SYNCONF: INVHWSYNC Position     
#define PWM_SYNCONF_INVHWSYNC_Msk            (0x01UL << PWM_SYNCONF_INVHWSYNC_Pos)                ///< PWM SYNCONF: INVHWSYNC Mask          
#define PWM_SYNCONF_SWVHWSYNC_Pos            20                                                   ///< PWM SYNCONF: SWVHWSYNC Position     
#define PWM_SYNCONF_SWVHWSYNC_Msk            (0x01UL << PWM_SYNCONF_SWVHWSYNC_Pos)                ///< PWM SYNCONF: SWVHWSYNC Mask          
#define PWM_SYNCONF_SWPOL_Pos                21                                                   ///< PWM SYNCONF: SWPOL Position         
#define PWM_SYNCONF_SWPOL_Msk                (0x01UL << PWM_SYNCONF_SWPOL_Pos)                    ///< PWM SYNCONF: SWPOL Mask              
#define PWM_SYNCONF_HWPOL_Pos                22                                                   ///< PWM SYNCONF: HWPOL Position         
#define PWM_SYNCONF_HWPOL_Msk                (0x01UL << PWM_SYNCONF_HWPOL_Pos)                    ///< PWM SYNCONF: HWPOL Mask              

/* ---------------------------------  PWM_INVCR  --------------------------------- */
#define PWM_INVCR_PAIR0INVEN_Pos             0                                                    ///< PWM INVCR: PAIR0INVEN Position      
#define PWM_INVCR_PAIR0INVEN_Msk             (0x01UL << PWM_INVCR_PAIR0INVEN_Pos)                 ///< PWM INVCR: PAIR0INVEN Mask           
#define PWM_INVCR_PAIR1INVEN_Pos             1                                                    ///< PWM INVCR: PAIR1INVEN Position      
#define PWM_INVCR_PAIR1INVEN_Msk             (0x01UL << PWM_INVCR_PAIR1INVEN_Pos)                 ///< PWM INVCR: PAIR1INVEN Mask           
#define PWM_INVCR_PAIR2INVEN_Pos             2                                                    ///< PWM INVCR: PAIR2INVEN Position      
#define PWM_INVCR_PAIR2INVEN_Msk             (0x01UL << PWM_INVCR_PAIR2INVEN_Pos)                 ///< PWM INVCR: PAIR2INVEN Mask           

/* --------------------------------  PWM_CHOSWCR  -------------------------------- */
#define PWM_CHOSWCR_CH0SWEN_Pos              0                                                    ///< PWM CHOSWCR: CH0SWEN Position       
#define PWM_CHOSWCR_CH0SWEN_Msk              (0x01UL << PWM_CHOSWCR_CH0SWEN_Pos)                  ///< PWM CHOSWCR: CH0SWEN Mask            
#define PWM_CHOSWCR_CH1SWEN_Pos              1                                                    ///< PWM CHOSWCR: CH1SWEN Position       
#define PWM_CHOSWCR_CH1SWEN_Msk              (0x01UL << PWM_CHOSWCR_CH1SWEN_Pos)                  ///< PWM CHOSWCR: CH1SWEN Mask            
#define PWM_CHOSWCR_CH2SWEN_Pos              2                                                    ///< PWM CHOSWCR: CH2SWEN Position       
#define PWM_CHOSWCR_CH2SWEN_Msk              (0x01UL << PWM_CHOSWCR_CH2SWEN_Pos)                  ///< PWM CHOSWCR: CH2SWEN Mask            
#define PWM_CHOSWCR_CH3SWEN_Pos              3                                                    ///< PWM CHOSWCR: CH3SWEN Position       
#define PWM_CHOSWCR_CH3SWEN_Msk              (0x01UL << PWM_CHOSWCR_CH3SWEN_Pos)                  ///< PWM CHOSWCR: CH3SWEN Mask            
#define PWM_CHOSWCR_CH4SWEN_Pos              4                                                    ///< PWM CHOSWCR: CH4SWEN Position       
#define PWM_CHOSWCR_CH4SWEN_Msk              (0x01UL << PWM_CHOSWCR_CH4SWEN_Pos)                  ///< PWM CHOSWCR: CH4SWEN Mask            
#define PWM_CHOSWCR_CH5SWEN_Pos              5                                                    ///< PWM CHOSWCR: CH5SWEN Position       
#define PWM_CHOSWCR_CH5SWEN_Msk              (0x01UL << PWM_CHOSWCR_CH5SWEN_Pos)                  ///< PWM CHOSWCR: CH5SWEN Mask            
#define PWM_CHOSWCR_CH0SWCV_Pos              8                                                    ///< PWM CHOSWCR: CH0SWCV Position       
#define PWM_CHOSWCR_CH0SWCV_Msk              (0x01UL << PWM_CHOSWCR_CH0SWCV_Pos)                  ///< PWM CHOSWCR: CH0SWCV Mask            
#define PWM_CHOSWCR_CH1SWCV_Pos              9                                                    ///< PWM CHOSWCR: CH1SWCV Position       
#define PWM_CHOSWCR_CH1SWCV_Msk              (0x01UL << PWM_CHOSWCR_CH1SWCV_Pos)                  ///< PWM CHOSWCR: CH1SWCV Mask            
#define PWM_CHOSWCR_CH2SWCV_Pos              10                                                   ///< PWM CHOSWCR: CH2SWCV Position       
#define PWM_CHOSWCR_CH2SWCV_Msk              (0x01UL << PWM_CHOSWCR_CH2SWCV_Pos)                  ///< PWM CHOSWCR: CH2SWCV Mask            
#define PWM_CHOSWCR_CH3SWCV_Pos              11                                                   ///< PWM CHOSWCR: CH3SWCV Position       
#define PWM_CHOSWCR_CH3SWCV_Msk              (0x01UL << PWM_CHOSWCR_CH3SWCV_Pos)                  ///< PWM CHOSWCR: CH3SWCV Mask            
#define PWM_CHOSWCR_CH4SWCV_Pos              12                                                   ///< PWM CHOSWCR: CH4SWCV Position       
#define PWM_CHOSWCR_CH4SWCV_Msk              (0x01UL << PWM_CHOSWCR_CH4SWCV_Pos)                  ///< PWM CHOSWCR: CH4SWCV Mask            
#define PWM_CHOSWCR_CH5SWCV_Pos              13                                                   ///< PWM CHOSWCR: CH5SWCV Position       
#define PWM_CHOSWCR_CH5SWCV_Msk              (0x01UL << PWM_CHOSWCR_CH5SWCV_Pos)                  ///< PWM CHOSWCR: CH5SWCV Mask            
          

/* PWM - Peripheral instance base addresses */
/** Peripheral PWM0 base address */
#define PWM0_BASE                                (0x40013000u)
/** Peripheral PWM0 base pointer */
#define PWM0                                     ((PWM_Type *)PWM0_BASE)
/** Peripheral PWM1 base address */
#define PWM1_BASE                                (0x40014000u)
/** Peripheral PWM1 base pointer */
#define PWM1                                     ((PWM_Type *)PWM1_BASE)
/** Peripheral PWM2 base address */
#define PWM2_BASE                                (0x40015000u)
/** Peripheral PWM2 base pointer */
#define PWM2                                     ((PWM_Type *)PWM2_BASE)
/** Peripheral PWM3 base address */
#define PWM3_BASE                                (0x4001e000u)
/** Peripheral PWM3 base pointer */
#define PWM3                                     ((PWM_Type *)PWM3_BASE)
/** Array initializer of PWM peripheral base pointers */
#define PWM_BASES                                { PWM0, PWM1, PWM2, PWM3}


/**
 * @brief PWM_CALLBACK function declaration
 */
typedef void (*PWM_CallbackPtr)(void);

/**
 * PWM inline functions
 */

/**
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @return  none.
* @brief  enable the over flow interrupt.
*
*/
__STATIC_INLINE void PWM_EnableOverflowInt(PWM_Type *PWMx)
{
    if (PWMx->INIT & PWM_INIT_CNTOF_Msk)
    {
        PWMx->INIT &= ~PWM_INIT_CNTOF_Msk;
    }
    PWMx->INIT |= PWM_INIT_CNTOIE_Msk;
}

/**

* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @return none.
* @brief  disable the over flow interrupt.
*
*/
__STATIC_INLINE void PWM_DisableOverflowInt(PWM_Type *PWMx)
{
    PWMx->INIT &= ~PWM_INIT_CNTOIE_Msk;
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] pwmChannel: channel number(PWM_CHANNEL_CHANNEL0 to PWM_CHANNEL_CHANNEL5).
*
* @return none.
*
* @brief  enable the channel interrupt.
*/
__STATIC_INLINE void PWM_EnableChannelInt(PWM_Type *PWMx, uint8_t pwmChannel)
{
    PWMx->CHANNELS[pwmChannel].CHSCR |= PWM_CHSCR_CHIE_Msk;
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] pwmChannel:  channel number(PWM_CHANNEL_CHANNEL0 to PWM_CHANNEL_CHANNEL5).
*
* @return none.
*
* @brief  disable the channel interrupt.
*/
__STATIC_INLINE void PWM_DisableChannelInt(PWM_Type *PWMx, uint8_t pwmChannel)
{
    PWMx->CHANNELS[pwmChannel].CHSCR &= ~ PWM_CHSCR_CHIE_Msk;
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
*
* @return PWM Overflow Flag: 0:PWM counter do not overflow ;1:PWM counter Overflow.
*
* @brief  get the over flow flag.
*
*/
__STATIC_INLINE uint8_t PWM_GetOverFlowFlag(PWM_Type *PWMx)
{
    return (PWMx->INIT & PWM_INIT_CNTOF_Msk);
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
*
* @return none.
*
* @brief  clear the over flow flag.
*
*/
__STATIC_INLINE void PWM_ClrOverFlowFlag(PWM_Type *PWMx)
{
    PWMx->INIT &= ~PWM_INIT_CNTOF_Msk;
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] pwmChannel: channel number(PWM_CHANNEL_CHANNEL0 to PWM_CHANNEL_CHANNEL5).
*
* @return Channel Interrupt Flag.
*
* @brief  get the channel flag.
*
*/
__STATIC_INLINE uint8_t PWM_GetChannelIntFlag(PWM_Type *PWMx, uint8_t pwmChannel)
{
    return (PWMx->CHANNELS[pwmChannel].CHSCR & PWM_CHSCR_CHIF_Msk);
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] pwmChannel: channel number(PWM_CHANNEL_CHANNEL0 to PWM_CHANNEL_CHANNEL5).
*
* @return none.
*
* @brief  clear the channel flag.
*
*/
__STATIC_INLINE void PWM_ClrChannelIntFlag(PWM_Type *PWMx, uint8_t pwmChannel)
{
    PWMx->CHANNELS[pwmChannel].CHSCR  &= ~PWM_CHSCR_CHIF_Msk;
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
*
* @return none.
*
* @brief enable the write protection function.Write protected bits cannot be written.
*
*/
__STATIC_INLINE void PWM_WriteProtectionEnable(PWM_Type *PWMx)
{
    PWMx->FDSR |= PWM_FDSR_WPEN_Msk;
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
*
* @return none.
*
* @brief disable the write protection function.Write protected bits can be written.
*
*/
__STATIC_INLINE void PWM_WriteProtectionDisable(PWM_Type *PWMx)
{
    if (PWMx->FDSR & PWM_FDSR_WPEN_Msk)
    {
        PWMx->FUNCSEL |= PWM_FUNCSEL_WPDIS_Msk;
    }
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
*
* @return none.
*
* @brief  set PWMEN bit to enable PWM-specific register.
*
*/
__STATIC_INLINE void PWM_SetPWMEnhanced(PWM_Type *PWMx)
{
    if (PWMx->FUNCSEL & PWM_FUNCSEL_WPDIS_Msk)   //if not write protected
    {
        PWMx->FUNCSEL |= PWM_FUNCSEL_PWMEN2_Msk;
    }
    else
    {
        PWM_WriteProtectionDisable(PWMx);
        PWMx->FUNCSEL |= PWM_FUNCSEL_PWMEN2_Msk;
        PWM_WriteProtectionEnable(PWMx);
    }
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
*
* @return none.
*
* @brief  clear PWMEN bit to disable PWM-specific registers, only TPM-compatible
*         registers can be used.
*
*/
__STATIC_INLINE void PWM_SetPWMBasic(PWM_Type *PWMx)
{
    if (PWMx->FUNCSEL & PWM_FUNCSEL_WPDIS_Msk)   //if not write protected
    {
        PWMx->FUNCSEL &= ~PWM_FUNCSEL_PWMEN2_Msk;
    }
    else
    {
        PWM_WriteProtectionDisable(PWMx);
        PWMx->FUNCSEL &= ~PWM_FUNCSEL_PWMEN2_Msk;
        PWM_WriteProtectionEnable(PWMx);
    }

}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] modValue: the mod value required to set(from 0x0000 to 0xffff).
*
* @return none.
*
* @brief  set the PWM mod value.
*
*/
__STATIC_INLINE void PWM_SetModValue(PWM_Type *PWMx, uint16_t modValue)
{
    PWMx->CNT = 0;
    PWMx->MCVR = modValue;
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] pwmChannel: PWM channel number(PWM_CHANNEL_CHANNEL0 to PWM_CHANNEL_CHANNEL5).
* @param[in] channelValue: the CnV value required to set(from 0x0000 to 0xffff).
*
* @return none.
*
* @brief  set the PWM channel value.
*
*/
__STATIC_INLINE void PWM_SetChannelValue(PWM_Type *PWMx, uint8_t pwmChannel, uint16_t channelValue)
{
    PWMx->CHANNELS[pwmChannel].CHV = channelValue;
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] counterValue: the CNTIN value required to set(from 0x0000 to 0xffff).
*
* @return none.
*
* @brief  set the PWM Init Count value.
*
*/
__STATIC_INLINE void PWM_SetCounterInitValue(PWM_Type *PWMx, uint16_t counterValue)
{
    PWMx->CNTIN = counterValue;
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] channelValue: PWM channel number(PWM_CHANNEL_CHANNEL0 to PWM_CHANNEL_CHANNEL5)
*
* @return none.
*
* @brief set PWM channels polarity.
*
*/
__STATIC_INLINE void PWM_SetChannelsPolarity(PWM_Type *PWMx, uint8_t channelValue)
{
    PWMx->CHOPOLCR |= channelValue;
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] channelValue: PWM channel number(PWM_CHANNEL_CHANNEL0 to PWM_CHANNEL_CHANNEL5)
*
* @return none.
*
* @brief clr PWM channels polarity.
*
*/
__STATIC_INLINE void PWM_ClrChannelsPolarity(PWM_Type *PWMx, uint8_t channelValue)
{
    PWMx->CHOPOLCR &= ~channelValue;
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
*
* @return channels polarity .
*
* @brief get PWM channels polarity.
*
*/
__STATIC_INLINE uint8_t PWM_GetChannelsPolarity(PWM_Type *PWMx)
{
    return (PWMx->CHOPOLCR);
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
*
* @return none.
*
* @brief general configuration to PWM2 to start software synchronization.
*/
__STATIC_INLINE void PWM_SoftwareSync(PWM_Type *PWMx)
{
    PWMx->SYNCONF   |= PWM_SYNCONF_SYNCMODE_Msk;   //recommend enhanced sync mode
    PWMx->SYNC      |= PWM_SYNC_SWSYNC_Msk;
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] prescalerValue: system clock divide value, 0 to 3.
* @param[in] deadtimeValue: n count clock is inserted, 0 to 63.
*
* @return none.
*
* @brief general configuration to PWM_No to start software synchronization.
*
*/
__STATIC_INLINE void PWM_PWMDeadtimeSet(PWM_Type *PWMx, uint8_t prescalerValue, uint8_t deadtimeValue)
{
    PWMx->MODESEL |= 0x101010;             //enable dead time insertion

    if (!(PWMx->FUNCSEL & PWM_FUNCSEL_WPDIS_Msk)) //if write protection is enabled
    {
        PWMx->FUNCSEL |= PWM_FUNCSEL_WPDIS_Msk;  //disable the write protection
        PWMx->DTSET = (prescalerValue << PWM_DTSET_DTPSC_Pos) | (deadtimeValue << PWM_DTSET_DTVAL_Pos);
        PWMx->FUNCSEL &= ~PWM_FUNCSEL_WPDIS_Msk; //enable the write protection
    }
    else
    {
        //if no protection
        PWMx->DTSET = (prescalerValue << PWM_DTSET_DTPSC_Pos) | (deadtimeValue << PWM_DTSET_DTVAL_Pos);
    }
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] pwmChannel: PWM channel number(PWM_CHANNEL_CHANNEL0 to PWM_CHANNEL_CHANNEL5).
*
* @return none.
*
* @brief set output mask.
*
*/
__STATIC_INLINE void PWM_OutputMaskSet(PWM_Type *PWMx, uint8_t pwmChannel)
{
    PWMx->OMCR |= (1 << pwmChannel);
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] pwmChannel: PWM channel number(PWM_CHANNEL_CHANNEL0 to PWM_CHANNEL_CHANNEL5).
*
* @return none.
*
* @brief clr output mask.
*
*/
__STATIC_INLINE void PWM_ClrOutputMask(PWM_Type *PWMx, uint8_t pwmChannel)
{
    PWMx->OMCR &= ~(1 << pwmChannel);
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] pwmChannel: PWM channel number(PWM_CHANNEL_CHANNEL0 to PWM_CHANNEL_CHANNEL5).
*
* @return none.
*
* @brief Disable Software Control
*
*/
__STATIC_INLINE void PWM_ClrOutputSWControl(PWM_Type *PWMx, uint8_t pwmChannel)
{
    PWMx->CHOSWCR &= ~(1 << pwmChannel);
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] cntTOFNum: TOF numbers before setting TOF bit, 0~31.
*
* @return none.
*
* @brief Selects the ratio between the number of counter overflows to the number of times the TOF bit is set.
*
*/
__STATIC_INLINE void PWM_SetCntTOFNum(PWM_Type *PWMx, uint8_t cntTOFNum)
{
    PWMx->CONF &= ~PWM_CONF_CNTOFNUM_Msk;
    PWMx->CONF |= cntTOFNum << PWM_CONF_CNTOFNUM_Pos;
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] channelPair: the pair to be swapped, 0,1,2.
*
* @return none.
*
* @brief swap the output of CH(n) and CH(n+1).
*
*/
__STATIC_INLINE void PWM_InvertChannel(PWM_Type *PWMx, uint8_t channelPair)
{
    PWMx->INVCR |= 1 << channelPair;
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
*
* @return none.
*
* @see PWM_DisableEnhancedSYNCMode.
*
* @brief select the enhanced SYNC mode.
*
*/
__STATIC_INLINE void PWM_EnableEnhancedSYNCMode(PWM_Type *PWMx)
{
    PWMx->SYNCONF |= PWM_SYNCONF_SYNCMODE_Msk;   // recommend enhanced sync mode
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
*
* @return none.
*
* @brief select the legacy SYNC mode.
*
*/
__STATIC_INLINE void PWM_DisableEnhancedSYNCMode(PWM_Type *PWMx)
{
    PWMx->SYNCONF &= ~PWM_SYNCONF_SYNCMODE_Msk;   // recommend enhanced sync mode
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] configValue: PWMx_SYNCONF register config value.
*
* @return none.
*
* @brief configure the PWMx_SYNCONF register including SW and HW Sync selection.
*
*/
__STATIC_INLINE void PWM_SyncConfigActivate(PWM_Type *PWMx, uint32_t configValue)
{
    PWMx->SYNCONF |= configValue;
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] configValue: PWMx_SYNCONF register config value.
*
* @return none.
*
* @brief configure the PWMx_SYNCONF register including SW and HW Sync selection.
*
*/
__STATIC_INLINE void PWM_SyncConfigDeactivate(PWM_Type *PWMx, uint32_t configValue)
{
    PWMx->SYNCONF &= ~configValue;
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] tirggerSource: initial trigger or CHn(0~5)trigger
*
* @return none.
*
* @brief set the external trigger source.
*
*/
__STATIC_INLINE void PWM_SetExternalTrigger(PWM_Type *PWMx, uint8_t tirggerSource)
{
    PWMx->EXTTRIG = tirggerSource;
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
*
* @return external trigger flag.
*
* @brief get the external trigger flag.
*
*/
__STATIC_INLINE uint8_t PWM_GetExternalTriggerFlag(PWM_Type *PWMx)
{
    return (PWMx->EXTTRIG & PWM_EXTTRIG_TRIGF_Msk);
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] pwmChannel: the channel number(PWM_CHANNEL_CHANNEL0 to PWM_CHANNEL_CHANNEL3).
*
* @return none.
*
* @brief disable the channel input capture filter.
*
*/
__STATIC_INLINE void PWM_InputCaptureFilterClr(PWM_Type *PWMx, uint8_t pwmChannel)
{
    uint8_t pwmShift = 0;
    pwmShift = 5 * pwmChannel;
    PWMx->CAPFILTER &= ~(0x001F << pwmShift);
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] pwmChannel: the channel number(PWM_CHANNEL_CHANNEL0 to PWM_CHANNEL_CHANNEL3).
* @param[in] filterValue: fliter cycles:0~31, 0: disable channel filter.
*
* @return none.
*
* @brief set the channel input capture filter value.
*
*/
__STATIC_INLINE void PWM_InputCaptureFilterSet(PWM_Type *PWMx, uint8_t pwmChannel, uint16_t filterValue)
{
    if (filterValue)
    {
        PWMx->CAPFILTER |= (filterValue << (5 * pwmChannel));
    }
    else
    {
        PWM_InputCaptureFilterClr(PWMx, pwmChannel);
    }
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] pwmChannel: the channel number(PWM_CHANNEL_CHANNEL0 to PWM_CHANNEL_CHANNEL5).
* @param[in] capturePSCValue: capture Event Prescale Value(00:1,01:2;10:4;11:8)
*
* @return none.
*
* @brief  set the PWM Capture Event Prescale value.
*
*/
__STATIC_INLINE void PWM_SetCapturePSCValue(PWM_Type *PWMx, uint8_t pwmChannel, uint16_t capturePSCValue)
{
    uint8_t pwmChannelShift;
    if (capturePSCValue > 3)
    {
        capturePSCValue = 3;
    }
    pwmChannelShift = pwmChannel * 2 + PWM_CONF_EVENTPSC_Pos;
    PWMx->CONF |= (capturePSCValue << pwmChannelShift);
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] faultModeSelect: fault flag clear Mode Select
*
* @return none.
*
* @brief Set PWM Fault Flag Clear Mode.
*
*/
__STATIC_INLINE void PWM_FaultModeSel(PWM_Type *PWMx, uint8_t faultModeSel)
{
    PWMx->FUNCSEL &= ~PWM_FUNCSEL_FAULTMODE_Msk;
    PWMx->FUNCSEL |= (faultModeSel << PWM_FUNCSEL_FAULTMODE_Pos);
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
*
* @return none.
*
* @brief Enable PWM Fault Interrupt.
*
*/
__STATIC_INLINE void PWM_FaultIntEnable(PWM_Type *PWMx)
{
    PWMx->FUNCSEL |= PWM_FUNCSEL_FAULTIE_Msk;
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @return none.
*
* @brief Disable PWM Fault Interrupt.
*
*/
__STATIC_INLINE void PWM_FaultIntDisable(PWM_Type *PWMx)
{
    PWMx->FUNCSEL &= ~PWM_FUNCSEL_FAULTIE_Msk;
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] faultChannel: fault input pin number(PWM_INTERNAL_FAULT1,PWM_INTERNAL_FAULT2,PWM_EXTERNAL_FAULT1,PWM_EXTERNAL_FAULT2).
* @param[in] faultPirority: Fault pirority:
*
* @return none
*
* @brief Set Fault Pirority.
*
*/
__STATIC_INLINE void PWM_SetFaultPirority(PWM_Type *PWMx, uint8_t faultChannel, uint8_t faultPirority)
{
    if (faultPirority)
    {
        PWMx->FLTPOL |= faultPirority << faultChannel;
    }
    else
    {
        PWMx->FLTPOL &= ~(1 << faultChannel);
    }
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] faultInputSelect: fault input pin number(PWM_INTERNAL_FAULT1,PWM_INTERNAL_FAULT2,PWM_EXTERNAL_FAULT1,PWM_EXTERNAL_FAULT2).
*
* @return none.
*
* @brief enable the fault input pin.
*
*/
__STATIC_INLINE void PWM_FaultEnable(PWM_Type *PWMx, uint8_t faultInputSelect)
{
    if (PWMx->FUNCSEL & PWM_FUNCSEL_WPDIS_Msk) //if not protected
    {
        PWMx->FFAFER |= (1 << faultInputSelect);
    }
    else                                  //if protected
    {
        PWM_WriteProtectionDisable(PWMx);
        PWMx->FFAFER |= (1 << faultInputSelect);
        PWM_WriteProtectionEnable(PWMx);
    }
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] faultInputSelect: fault input pin number(PWM_INTERNAL_FAULT1,PWM_INTERNAL_FAULT2,PWM_EXTERNAL_FAULT1,PWM_EXTERNAL_FAULT2).
*
* @return none.
*
* @brief disable the fault input pin.
*
*/
__STATIC_INLINE void PWM_FaultDisable(PWM_Type *PWMx, uint8_t faultInputSelect)
{
    if (PWMx->FUNCSEL & PWM_FUNCSEL_WPDIS_Msk) //if not protected
    {
        PWMx->FFAFER  &= ~(1 << faultInputSelect);
    }
    else                                  //if protected
    {
        PWM_WriteProtectionDisable(PWMx);
        PWMx->FFAFER  &= ~(1 << faultInputSelect);
        PWM_WriteProtectionEnable(PWMx);
    }
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] faultInputSelect: fault input pin number(PWM_INTERNAL_FAULT1,PWM_INTERNAL_FAULT2,PWM_EXTERNAL_FAULT1,PWM_EXTERNAL_FAULT2).
*
* @return none.
*
* @brief enable the fault pin filter.
*
*/
__STATIC_INLINE void PWM_FaultFilterEnable(PWM_Type *PWMx, uint8_t faultInputSelect, uint8_t faultValue)
{
    if (PWMx->FUNCSEL & PWM_FUNCSEL_WPDIS_Msk) //if not protected
    {
        PWMx->FFAFER |= (0x10 << faultInputSelect);
        PWMx->FFAFER |= (faultValue << PWM_FFAFER_FFVAL_Pos);
    }
    else                                  //if protected
    {
        PWM_WriteProtectionDisable(PWMx);
        PWMx->FFAFER |= (0x10 << faultInputSelect);
        PWMx->FFAFER |= (faultValue << PWM_FFAFER_FFVAL_Pos);
        PWM_WriteProtectionEnable(PWMx);
    }
}

/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] faultInputSelect: fault input pin number(PWM_INTERNAL_FAULT1,PWM_INTERNAL_FAULT2,PWM_EXTERNAL_FAULT1,PWM_EXTERNAL_FAULT2).
*
* @return none.
*
* @brief disable the fault pin filter.
*
*/
__STATIC_INLINE void PWM_FaultFilterDisable(PWM_Type *PWMx, uint8_t faultInputSelect)
{
    if (PWMx->FUNCSEL & PWM_FUNCSEL_WPDIS_Msk) //if not protected
    {
        PWMx->FFAFER &= ~(0x10 << faultInputSelect);
    }
    else                                  //if protected
    {
        PWM_WriteProtectionDisable(PWMx);
        PWMx->FFAFER &= ~(0x10 << faultInputSelect);
        PWM_WriteProtectionEnable(PWMx);
    }
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] faultNum: fault input pin number(PWM_INTERNAL_FAULT1,PWM_INTERNAL_FAULT2,PWM_EXTERNAL_FAULT1,PWM_EXTERNAL_FAULT2).
*
* @return Fault Detection Flag.
*
* @brief get the fault detection flag
*
*/
__STATIC_INLINE uint8_t PWM_GetFaultDetectionFlag(PWM_Type *PWMx, uint8_t faultNum)
{
    return (PWMx->FDSR & (1 << faultNum));
}
/**
*
* @param[in] PWMx: pointer to one of three PWM base register address(PWM0 to PWM3).
* @param[in] faultNum: fault input pin number(PWM_INTERNAL_FAULT1,PWM_INTERNAL_FAULT2,PWM_EXTERNAL_FAULT1,PWM_EXTERNAL_FAULT2).
*
* @return none.
*
* @brief clear the fault detection flag
*
*/
__STATIC_INLINE void PWM_ClrFaultDetectionFlag(PWM_Type *PWMx, uint8_t faultNum)
{
    PWMx->FDSR &= ~(1 << faultNum);
}
/*! @} End of PWM_api_list                                                    */


#ifdef __cplusplus
}
#endif

#endif
