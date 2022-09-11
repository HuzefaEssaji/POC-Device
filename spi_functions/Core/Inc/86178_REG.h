/*
 * 86178_REG.h
 *
 *  Created on: Sep 9, 2022
 *      Author: essaj
 */

#ifndef INC_86178_REG_H_
#define INC_86178_REG_H_



#endif /* INC_86178_REG_H_ */



/*--------------------------------------------------------------------------
MAX86178

Header file for the Maxim MAX86178.
Copyright (c) Anuj Sharma 2022-2027.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __MAX86178_H__
#define __MAX86178_H__
#endif
/*------------------------------------------------
Byte Registers

------------------------------------------------*/
#define Status_1												0x00
#define Status_2												0x01
#define Status_3												0x02
#define Status_4												0x03
#define Status_5												0x04

#define FIFO_Write_Pointer							 0x08
#define FIFO_Read_Pointer							 0x09
#define FIFO_Counter_1									 0x0A
#define FIFO_Counter_2									 0x0B
#define FIFO_Data_Register							 0x0C
#define FIFO_Configuration_1						 0x0D
#define FIFO_Configuration_2						 0x0E

#define System_Sync											 0x10
#define System_Configuration_1 					 0x11
#define System_Configuration_2 					 0x12
#define Pin_Functional_Configuration		 0x13
#define Output_Pin_Configuration 				 0x14
#define I2C_Broadcast_Address						 0x15

#define PLL_Configuration_1							 0x18
#define PLL_Configuration_2							 0x19
#define PLL_Configuration_3							 0x1A
#define PLL_Configuration_4							 0x1B
#define PLL_Configuration_5							 0x1C
#define PLL_Configuration_6							 0x1D
#define PPG_Configuration_1							 0x20
#define PPG_Configuration_2							 0x21
#define PPG_Configuration_3							 0x22
#define PPG_Configuration_4							 0x23

#define Photodiode_Bias									 0x24
#define FR_Clock_Divider_MSB						 0x28
#define FR_Clock_Divider_LSB						 0x29

#define MEAS1_Selects										 0x30
#define MEAS1_Configuration_1						 0x31
#define MEAS1_Configuration_2						 0x32
#define MEAS1_Configuration_3						 0x33
#define MEAS1_Configuration_4						 0x34
#define MEAS1_Configuration_5						 0x35
#define MEAS1_LEDA											 0x36
#define MEAS1_LEDB											 0x32
#define MEAS2_Selects										 0x38
#define MEAS2_Configuration_1						 0x39
#define MEAS2_Configuration_2						 0x3A
#define MEAS2_Configuration_3						 0x3B
#define MEAS2_Configuration_4						 0x3C
#define MEAS2_Configuration_5						 0x3D
#define MEAS2_LEDA											 0x3E
#define MEAS2_LEDB											 0x3F
#define MEAS3_Selects										 0x40
#define MEAS3_Configuration_1						 0x41
#define MEAS3_Configuration_2						 0x42
#define MEAS3_Configuration_3						 0x43
#define MEAS3_Configuration_4						 0x44
#define MEAS3_Configuration_5						 0x45
#define MEAS3_LEDA											 0x46
#define MEAS3_LEDB											 0x47
#define MEAS4_Selects										 0x48
#define MEAS4_Configuration_1						 0x49
#define MEAS4_Configuration_2						 0x4A
#define MEAS4_Configuration_3						 0x4B
#define MEAS4_Configuration_4						 0x4C
#define MEAS4_Configuration_5						 0x4D
#define MEAS4_LEDA											 0x4E
#define MEAS4_LEDB											 0x4F
#define MEAS5_Selects										 0x50
#define MEAS5_Configuration_1						 0x51
#define MEAS5_Configuration_2						 0x52
#define MEAS5_Configuration_3						 0x53
#define MEAS5_Configuration_4						 0x54
#define MEAS5_Configuration_5						 0x55
#define MEAS5_LEDA											 0x56
#define MEAS5_LEDB											 0x57
#define MEAS6_Selects										 0x58
#define MEAS6_Configuration_1						 0x59
#define MEAS6_Configuration_2						 0x5A
#define MEAS6_Configuration_3						 0x5B
#define MEAS6_Configuration_4						 0x5C
#define MEAS6_Configuration_5						 0x5D
#define MEAS6_LEDA											 0x5E
#define MEAS6_LEDB											 0x5F
#define THRESHOLD_MEAS									 0x70
#define THRESHOLD_HYST									 0x71
#define PPG_HI_THRESHOLD1 							 0x72
#define PPG_LO_THRESHOLD1								 0x73
#define PPG_HI_THRESHOLD2 							 0x74
#define PPG_LO_THRESHOLD2								 0x75
#define ECG_Configuration_1							 0x80
#define ECG_Configuration_2							 0x81
#define ECG_Configuration_3							 0x82
#define ECG_Configuration_4							 0x83
#define ECG_CAL_Configuration_1					 0x84
#define ECG_CAL_Configuration_2					 0x85
#define ECG_CAL_Configuration_3					 0x86
#define ECG_Lead_Detect_Configuration_1	 0x88
#define ECG_Lead_Detect_Configuration_2	 0x89
#define ECG_Lead_Bias_Configuration_1		 0x90
#define RLD_Configuration_1							 0x92
#define RLD_Configuration_2							 0x93
#define BIOZ_Configuration_1						 0xA0
#define BIOZ_Configuration_2						 0xA1
#define BIOZ_Configuration_3						 0xA2
#define BIOZ_Configuration_4						 0xA3
#define BIOZ_Configuration_5						 0xA4
#define BIOZ_Configuration_6						 0xA5
#define BIOZ_Configuration_7						 0xA6
#define BIOZ_Configuration_8						 0xA7
#define BIOZ_Low_Threshold							 0xA8
#define BIOZ_High_Threshold							 0xA9
#define BIOZ_Mux_Configuration_1				 0xAA
#define BIOZ_Mux_Configuration_2				 0xAB
#define BIOZ_Mux_Configuration_3				 0xAC
#define BIOZ_Mux_Configuration_4				 0xAD
#define BIOZ_Lead_Detect_Configuration_1			 0xB0
#define BIOZ_Lead_Off_Threshold						 0xB1
#define BIOZ_Lead_Bias_Configuration_1				 0xB4
#define Respiration_Configuration_1					 0xB6
#define Interrupt1_Enable_1							 0xC0
#define Interrupt1_Enable_2							 0xC1
#define Interrupt1_Enable_3							 0xC2
#define Interrupt1_Enable_4							 0xC3
#define Interrupt1_Enable_5							 0xC4
#define Interrupt2_Enable_1							 0xC5
#define Interrupt2_Enable_2							 0xC6
#define Interrupt2_Enable_3							 0xC7
#define Interrupt2_Enable_4							 0xC8
#define Interrupt2_Enable_5							 0xC9
#define Part_ID										 0xFF
/*------------------------------------------------
Status 1(0x00) Bit Values
------------------------------------------------*/
//#define PWR_RDY    				0x01
//#define PPG_THRESH1_HILO  	 	 0x02
//#define PPG_THRESH2_HILO   	 	0x04
//#define EXP_OVF    				0x08
//#define ALC_OVF			   	 0x10
//#define FIFO_DATA_RDY	    	0x20
//#define PPG_FRAME_RDY			 0x40
//#define A_FULL			   		 0x80
//
///*------------------------------------------------
//Status 2(0x01) Bit Values
//------------------------------------------------*/
//#define LED1_COMPB    				0x01
//#define LED2_COMPB   	 	 0x02
//#define LED3_COMPB   	 	0x04
//#define LED4_COMPB    				0x08
//#define LED5_COMPB 			   	 0x10
//#define LED6_COMPB 	    	0x20
//
//#define INVALID_PPG_CFG			   		 0x80
//
///*------------------------------------------------
//Status 3(0x02) Bit Values
//------------------------------------------------*/
//
//#define PHASE_LOCK  	 	 0x02
//#define PHASE_UNLOCK   	 	0x04
//#define FREQ_LOCK    				0x08
//#define FREQ_UNLOCK		   	 0x10
//
///*------------------------------------------------
//Status 4(0x03) Bit Values
//------------------------------------------------*/
//#define ECG_LOFF_NL    				0x01
//#define ECG_LOFF_NH  	 	 0x02
//#define ECG_LOFF_PL   	 	0x04
//#define ECG_LOFF_PH    				0x08
//#define RLD_OOR		   	 0x10
//#define ECG_FAST_REC	    	0x20
//
//#define ECG_LON			   		 0x80
//
///*------------------------------------------------
//Status 5(0x04) Bit Values
//------------------------------------------------*/
//#define BIOZ_LOFF_NL    				0x01
//#define BIOZ_LOFF_NH  	 	 0x02
//#define BIOZ_LOFF_PL   	 	0x04
//#define BIOZ_LOFF_PH    				0x08
//#define BIOZ_DRV_OOR		   	 0x10
//#define BIOZ_UNDR	    	0x20
//#define BIOZ_OVER	    	0x40
//#define ECG_LON			   		 0x80
//
///*------------------------------------------------
//FIFO Write Pointer	(0x08) Bit Values
//------------------------------------------------*/
//#define FIFO_WR_PTR0    				0x01
//#define FIFO_WR_PTR1   	 	 0x02
//#define FIFO_WR_PTR2    	 	0x04
//#define FIFO_WR_PTR3     				0x08
//#define FIFO_WR_PTR4 		   	 0x10
//#define FIFO_WR_PTR5 	    	0x20
//#define FIFO_WR_PTR6 	    	0x40
//#define FIFO_WR_PTR7 			   		 0x80
//
///*------------------------------------------------
//FIFO Read Pointer	(0x09) Bit Values
//------------------------------------------------*/
//#define FIFO_RD_PTR0    				0x01
//#define FIFO_RD_PTR1   	 	 0x02
//#define FIFO_RD_PTR2    	 	0x04
//#define FIFO_RD_PTR3     				0x08
//#define FIFO_RD_PTR4 		   	 0x10
//#define FIFO_RD_PTR5 	    	0x20
//#define FIFO_RD_PTR6 	    	0x40
//#define FIFO_RD_PTR7 			   		 0x80
//
///*------------------------------------------------
//FIFO Counter 1	(0x0A) Bit Values
//------------------------------------------------*/
//#define OVF_COUNTER0    				0x01
//#define OVF_COUNTER1   	 	 0x02
//#define OVF_COUNTER2    	 	0x04
//#define OVF_COUNTER3     				0x08
//#define OVF_COUNTER4 		   	 0x10
//#define OVF_COUNTER5 	    	0x20
//#define OVF_COUNTER6 	    	0x40
//#define FIFO_DATA_COUNT8	   		 0x80
//
///*------------------------------------------------
//FIFO Counter 2	(0x0B) Bit Values
//------------------------------------------------*/
//#define FIFO_DATA_COUNT0    				0x01
//#define FIFO_DATA_COUNT1   	 	 0x02
//#define FIFO_DATA_COUNT2    	 	0x04
//#define FIFO_DATA_COUNT3     				0x08
//#define FIFO_DATA_COUNT4 		   	 0x10
//#define FIFO_DATA_COUNT5 	    	0x20
//#define FIFO_DATA_COUNT6 	    	0x40
//#define FIFO_DATA_COUNT7	   		 0x80
//
///*------------------------------------------------
//FIFO Data Register	(0x0C) Bit Values
//------------------------------------------------*/
//#define FIFO_DATA0    				0x01
//#define FIFO_DATA1   	 	 0x02
//#define FIFO_DATA2    	 	0x04
//#define FIFO_DATA3     				0x08
//#define FIFO_DATA4 		   	 0x10
//#define FIFO_DATA5 	    	0x20
//#define FIFO_DATA6 	    	0x40
//#define FIFO_DATA7	   		 0x80
//
///*------------------------------------------------
//FIFO Configuration 1	(0x0D) Bit Values
//------------------------------------------------*/
//#define FIFO_A_FULL0    				0x01
//#define FIFO_A_FULL1   	 	 0x02
//#define FIFO_A_FULL2    	 	0x04
//#define FIFO_A_FULL3     				0x08
//#define FIFO_A_FULL4 		   	 0x10
//#define FIFO_A_FULL5 	    	0x20
//#define FIFO_A_FULL6 	    	0x40
//#define FIFO_A_FULL7	   		 0x80
//
///*------------------------------------------------
//FIFO Configuration 2	(0x0E) Bit Values
//------------------------------------------------*/
//
//#define FIFO_RO   	 	 0x02
//#define A_FULL_TYPE   	 	0x04
//#define FIFO_STAT_CLR     				0x08
//#define FLUSH_FIFO 		   	 0x10
//#define FIFO_MARK	    	0x20
//
///*------------------------------------------------
//System Sync	(0x10) Bit Values
//------------------------------------------------*/
//
//#define TIMING_SYS_RESET	   		 0x80
//
///*------------------------------------------------
//System Configuration 1	(0x11) Bit Values
//------------------------------------------------*/
//#define RESET   				0x01
//#define SHDN			   	 	 0x02
//
//#define ECG_BIOZ_TIMING_DATA     				0x08
//#define BIOZ_PPG_TIMING_DATA 		   	 0x10
//#define ECG_PPG_TIMING_DATA	    	0x20
//#define DISABLE_I2C	    	0x40
//
//
///*------------------------------------------------
//System Configuration 2	(0x12) Bit Values
//------------------------------------------------*/
//#define ECG_SAMP_SYNC_FREQ0    				0x01
//#define ECG_SAMP_SYNC_FREQ1   	 	 0x02
//#define ECG_SAMP_SYNC_FREQ2    	 	0x04
//#define ECG_SAMP_SYNC_FREQ3     				0x08
//#define ECG_SAMP_SYNC_FREQ4 		   	 0x10
//
//
//#define BYP_DLY	   		 0x80
//
///*------------------------------------------------
//Pin Functional Configuration 	(0x13) Bit Values
//------------------------------------------------*/
//#define INT1_FCFG0    				0x01
//#define INT1_FCFG1   	 	 0x02
//#define INT2_FCFG0    	 	0x04
//#define INT2_FCFG1      				0x08
//#define TRIG_ICFG 		   	 0x10
//#define TRIG_FCFG0	    	0x20
//#define TRIG_FCFG1 	    	0x40
//#define TRIG_FCFG2	   		 0x80
//
///*------------------------------------------------
//Output Pin Configuration 	(0x14) Bit Values
//------------------------------------------------*/
//#define INT1_OCFG0    				0x01
//#define INT1_OCFG1   	 	 0x02
//#define INT2_OCFG0    	 	0x04
//#define INT2_OCFG1      				0x08
//
//#define TRIG_OCFG1 	    	0x40
//#define TRIG_OCFG2	   		 0x80
//
///*------------------------------------------------
//I2C Broadcast Address 	(0x15) Bit Values
//------------------------------------------------*/
//#define I2C_BCAST_EN0    				0x01
//#define I2C_BCAST_ADDR0  	 	 0x02
//#define I2C_BCAST_ ADDR1    	 	0x04
//#define I2C_BCAST_ ADDR2     				0x08
//#define I2C_BCAST_ ADDR3 		   	 0x10
//#define I2C_BCAST_ ADDR4 	    	0x20
//#define I2C_BCAST_ ADDR5 	    	0x40
//#define I2C_BCAST_ ADDR6	   		 0x80
//
///*------------------------------------------------
//PLL Configuration 1 	(0x18) Bit Values
//------------------------------------------------*/
//#define PLL_EN    				0x01
//#define PLL_LOCK_WNDW  	 	 0x02
//
//#define MDIV8 	    	0x40
//#define MDIV9	   		 0x80
//
///*------------------------------------------------
//PLL Configuration 2 	(0x19) Bit Values
//------------------------------------------------*/
//#define MDIV0    				0x01
//#define MDIV1 	 	 0x02
//#define MDIV2    	 	0x04
//#define MDIV3     				0x08
//#define MDIV4 		   	 0x10
//#define MDIV5 	    	0x20
//#define MDIV6 	    	0x40
//#define MDIV7	   		 0x80
//
//
///*------------------------------------------------
//PLL Configuration 3	(0x1A) Bit Values
//------------------------------------------------*/
//#define BIOZ_KDIV0    				0x01
//#define BIOZ_KDIV1 	 	 0x02
//#define BIOZ_KDIV2    	 	0x04
//#define BIOZ_KDIV3     				0x08
//
//#define BIOZ_NDIV0 	    	0x40
//#define BIOZ_NDIV1	   		 0x80
//
///*------------------------------------------------
//PLL Configuration 4	(0x1B) Bit Values
//------------------------------------------------*/
//#define ECG_FDIV0    				0x01
//#define ECG_FDIV1 	 	 0x02
//#define ECG_FDIV2    	 	0x04
//
//#define ECG_NDIV8      				0x20
//#define ECG_NDIV9	    	0x40
//#define ECG_NDIV10	   		 0x80
//
///*------------------------------------------------
//PLL Configuration 5	(0x1C) Bit Values
//------------------------------------------------*/
//#define ECG_NDIV0    				0x01
//#define ECG_NDIV1 	 	 0x02
//#define ECG_NDIV2    	 	0x04
//#define ECG_NDIV3     				0x08
//#define ECG_NDIV4 		   	 0x10
//#define ECG_NDIV5 	    	0x20
//#define ECG_NDIV6 	    	0x40
//#define ECG_NDIV7	   		 0x80
//
///*------------------------------------------------
//PLL Configuration 5	(0x1C) Bit Values
//------------------------------------------------*/
//#define CLK_FINE_TUNE0    				0x01
//#define CLK_FINE_TUNE1 	 	 0x02
//#define CLK_FINE_TUNE2    	 	0x04
//#define CLK_FINE_TUNE3     				0x08
//#define CLK_FINE_TUNE4 		   	 0x10
//#define CLK_FREQ_SEL	    	0x20
//#define REF_CLK_SEL 	    	0x40
//
///*------------------------------------------------
//PPG Configuration 1	(0x20) Bit Values
//------------------------------------------------*/
//#define MEAS1_EN    				0x01
//#define MEAS2_EN 	 	 0x02
//#define MEAS3_EN    	 	0x04
//#define MEAS4_EN     				0x08
//#define MEAS5_EN 		   	 0x10
//#define MEAS6_EN 	    	0x20
///*------------------------------------------------
//PPG Configuration 2	(0x21) Bit Values
//------------------------------------------------*/
//
//#define PPG1_PWRDN    	 	0x04
//#define PPG2_PWRDN     				0x08
//
//#define PPG_SYNC_MODE 	    	0x20
//
///*------------------------------------------------
//PPG Configuration 3	(0x22) Bit Values
//------------------------------------------------*/
//#define MEAS1_CONFIG_SEL    				0x01
//#define COLLECT_RAW_DATA 	 	 0x02
//
//#define ALC_DISABLE     				0x08
//#define SMP_AVE0 		   	 0x10
//#define SMP_AVE1 	    	0x20
//#define SMP_AVE2 	    	0x40
//
///*------------------------------------------------
//PPG Configuration 4	(0x23) Bit Values
//------------------------------------------------*/
//
//#define PROX_AUTO     				0x08
//#define PROX_DATA_EN 		   	 0x10
//
///*------------------------------------------------
//Photodiode Bias	(0x24) Bit Values
//------------------------------------------------*/
//#define PD1_BIAS0    				0x01
//#define PD1_BIAS1 	 	 0x02
//#define PD2_BIAS0    	 	0x04
//#define PD2_BIAS1     				0x08
//#define PD3_BIAS0 		   	 0x10
//#define PD3_BIAS1 	    	0x20
//#define PD4_BIAS0 	    	0x40
//#define PD4_BIAS1	   		 0x80
//
///*------------------------------------------------
//FR Clock Divider MSB	(0x28) Bit Values
//------------------------------------------------*/
//#define FR_CLK_DIV8  				0x01
//#define FR_CLK_DIV9 	 	 0x02
//#define FR_CLK_DIV10	 	0x04
//#define FR_CLK_DIV11   				0x08
//#define FR_CLK_DIV12		   	 0x10
//#define FR_CLK_DIV13	    	0x20
//#define FR_CLK_DIV14	    	0x40
//
///*------------------------------------------------
//FR Clock Divider LSB	(0x29) Bit Values
//------------------------------------------------*/
//#define FR_CLK_DIV0 				0x01
//#define FR_CLK_DIV1 	 	 0x02
//#define FR_CLK_DIV2	 	0x04
//#define FR_CLK_DIV3   				0x08
//#define FR_CLK_DIV4		   	 0x10
//#define FR_CLK_DIV5	    	0x20
//#define FR_CLK_DIV6	    	0x40
//#define FR_CLK_DIV7	   		 0x80
//
///*------------------------------------------------
//MEAS1 Selects	(0x30) Bit Values
//------------------------------------------------*/
//
//#define MEAS1_DRVA0 				0x01
//#define MEAS1_DRVA1 	 	 0x02
//#define MEAS1_DRVA2	 	0x04
//#define MEAS1_DRVB0   				0x08
//#define MEAS1_DRVB1		   	 0x10
//#define MEAS1_DRVB2	    	0x20
//#define MEAS1_AMB	    	0x40
//
//
///*------------------------------------------------
//MEAS1 Configuration 1	(0x31) Bit Values
//------------------------------------------------*/
//
//#define MEAS1_AVER0 				0x01
//#define MEAS1_AVER1 	 	 0x02
//#define MEAS1_AVER2	 	0x04
//#define MEAS1_TINT0   				0x08
//#define MEAS1_TINT1		   	 0x10
//#define MEAS1_FILT_SEL	    	0x20
//#define MEAS1_FILT2_SEL	    	0x40
//#define MEAS1_SINC3_SEL	   		 0x80
//
///*------------------------------------------------
//MEAS1 Configuration 2	(0x32) Bit Values
//------------------------------------------------*/
//
//#define MEAS1_PPG1_ADC_RGE0 				0x01
//#define MEAS1_PPG1_ADC_RGE1 	 	 0x02
//
//#define MEAS1_PPG2_ADC_RGE0		   	 0x10
//#define MEAS1_PPG2_ADC_RGE1	    	0x20
//
///*------------------------------------------------
//MEAS1 Configuration 3	(0x33) Bit Values
//------------------------------------------------*/
//
//#define MEAS1_PPG1_DACOFF0 				0x01
//#define MEAS1_PPG1_DACOFF1 	 	 0x02
//#define MEAS1_PPG1_DACOFF2	 	0x04
//#define MEAS1_PPG1_DACOFF3   				0x08
//#define MEAS1_PPG2_DACOFF0		   	 0x10
//#define MEAS1_PPG2_DACOFF1	    	0x20
//#define MEAS1_PPG2_DACOFF2	    	0x40
//#define MEAS1_PPG2_DACOFF3	   		 0x80
//
///*------------------------------------------------
//MEAS1 Configuration 4	(0x34) Bit Values
//------------------------------------------------*/
//
//#define MEAS1_LED_RGE0 				0x01
//#define MEAS1_LED_RGE1 	 	 0x02
//#define MEAS1_LED_SETLNG0	 	0x04
//#define MEAS1_LED_SETLNG1   				0x08
//
//#define MEAS1_PD_SETLNG0	    	0x40
//#define MEAS1_PD_SETLNG1	   		 0x80
//
///*------------------------------------------------
//MEAS1 Configuration 5	(0x35) Bit Values
//------------------------------------------------*/
//#define MEAS1_PD1_SEL0    				0x01
//#define MEAS1_PD1_SEL1 	 	 0x02
//#define MEAS1_PD2_SEL0    	 	0x04
//#define MEAS1_PD2_SEL1     				0x08
//#define MEAS1_PD3_SEL0 		   	 0x10
//#define MEAS1_PD3_SEL1 	    	0x20
//#define MEAS1_PD4_SEL0 	    	0x40
//#define MEAS1_PD4_SEL1	   		 0x80
//
///*------------------------------------------------
//MEAS1 LEDA Current	(0x36) Bit Values
//------------------------------------------------*/
//#define MEAS1_DRVA_PA0    				0x01
//#define MEAS1_DRVA_PA1 	 	 0x02
//#define MEAS1_DRVA_PA2    	 	0x04
//#define MEAS1_DRVA_PA3     				0x08
//#define MEAS1_DRVA_PA4 		   	 0x10
//#define MEAS1_DRVA_PA5 	    	0x20
//#define MEAS1_DRVA_PA6 	    	0x40
//#define MEAS1_DRVA_PA7	   		 0x80
//
///*------------------------------------------------
//MEAS1 LEDB Current	(0x37) Bit Values
//------------------------------------------------*/
//#define MEAS1_DRVB_PA0    				0x01
//#define MEAS1_DRVB_PA1 	 	 0x02
//#define MEAS1_DRVB_PA2    	 	0x04
//#define MEAS1_DRVB_PA3     				0x08
//#define MEAS1_DRVB_PA4 		   	 0x10
//#define MEAS1_DRVB_PA5 	    	0x20
//#define MEAS1_DRVB_PA6 	    	0x40
//#define MEAS1_DRVB_PA7	   		 0x80
//
//////
///*------------------------------------------------
//MEAS2 Selects	(0x38) Bit Values
//------------------------------------------------*/
//
//#define MEAS2_DRVA0 				0x01
//#define MEAS2_DRVA1 	 	 0x02
//#define MEAS2_DRVA2	 	0x04
//#define MEAS2_DRVB0   				0x08
//#define MEAS2_DRVB1		   	 0x10
//#define MEAS2_DRVB2	    	0x20
//#define MEAS2_AMB	    	0x40
//
//
///*------------------------------------------------
//MEAS2 Configuration 1	(0x39) Bit Values
//------------------------------------------------*/
//
//#define MEAS2_AVER0 				0x01
//#define MEAS2_AVER1 	 	 0x02
//#define MEAS2_AVER2	 	0x04
//#define MEAS2_TINT0   				0x08
//#define MEAS2_TINT1		   	 0x10
//#define MEAS2_FILT_SEL	    	0x20
//#define MEAS2_FILT2_SEL	    	0x40
//#define MEAS2_SINC3_SEL	   		 0x80
//
///*------------------------------------------------
//MEAS2 Configuration 2	(0x3A) Bit Values
//------------------------------------------------*/
//
//#define MEAS2_PPG1_ADC_RGE0 				0x01
//#define MEAS2_PPG1_ADC_RGE1 	 	 0x02
//
//#define MEAS2_PPG2_ADC_RGE0		   	 0x10
//#define MEAS2_PPG2_ADC_RGE1	    	0x20
//
///*------------------------------------------------
//MEAS2 Configuration 3	(0x3B) Bit Values
//------------------------------------------------*/
//
//#define MEAS2_PPG1_DACOFF0 				0x01
//#define MEAS2_PPG1_DACOFF1 	 	 0x02
//#define MEAS2_PPG1_DACOFF2	 	0x04
//#define MEAS2_PPG1_DACOFF3   				0x08
//#define MEAS2_PPG2_DACOFF0		   	 0x10
//#define MEAS2_PPG2_DACOFF1	    	0x20
//#define MEAS2_PPG2_DACOFF2	    	0x40
//#define MEAS2_PPG2_DACOFF3	   		 0x80
//
///*------------------------------------------------
//MEAS2 Configuration 4	(0x3C) Bit Values
//------------------------------------------------*/
//
//#define MEAS2_LED_RGE0 				0x01
//#define MEAS2_LED_RGE1 	 	        0x02
//#define MEAS2_LED_SETLNG0	 	    0x04
//#define MEAS2_LED_SETLNG1   	    0x08
//
//#define MEAS2_PD_SETLNG0	    	0x40
//#define MEAS2_PD_SETLNG1	   		0x80
//
///*------------------------------------------------
//MEAS2 Configuration 5	(0x3D) Bit Values
//------------------------------------------------*/
//#define MEAS2_PD1_SEL0    				0x01
//#define MEAS2_PD1_SEL1 	 	            0x02
//#define MEAS2_PD2_SEL0    	 	        0x04
//#define MEAS2_PD2_SEL1     				0x08
//#define MEAS2_PD3_SEL0 		   	        0x10
//#define MEAS2_PD3_SEL1 	    	        0x20
//#define MEAS2_PD4_SEL0 	    	        0x40
//#define MEAS2_PD4_SEL1	   		        0x80
//
///*------------------------------------------------
//MEAS2 LEDA Current	(0x3E) Bit Values
//------------------------------------------------*/
//#define MEAS2_DRVA_PA0    				0x01
//#define MEAS2_DRVA_PA1 	 	           0x02
//#define MEAS2_DRVA_PA2    	        	0x04
//#define MEAS2_DRVA_PA3     				0x08
//#define MEAS2_DRVA_PA4 		     	 0x10
//#define MEAS2_DRVA_PA5 	    	0x20
//#define MEAS2_DRVA_PA6 	    	0x40
//#define MEAS2_DRVA_PA7	   		 0x80
//
///*------------------------------------------------
//MEAS2 LEDB Current	(0x3F) Bit Values
//------------------------------------------------*/
//#define MEAS2_DRVB_PA0    				0x01
//#define MEAS2_DRVB_PA1 	 	 0x02
//#define MEAS2_DRVB_PA2    	 	0x04
//#define MEAS2_DRVB_PA3     				0x08
//#define MEAS2_DRVB_PA4 		   	 0x10
//#define MEAS2_DRVB_PA5 	    	0x20
//#define MEAS2_DRVB_PA6 	    	0x40
//#define MEAS2_DRVB_PA7	   		 0x80
//
//
///*------------------------------------------------
//MEAS3 Selects	(0x40) Bit Values
//------------------------------------------------*/
//
//#define MEAS3_DRVA0 				0x01
//#define MEAS3_DRVA1 	 	 0x02
//#define MEAS3_DRVA2	 	0x04
//#define MEAS3_DRVB0   				0x08
//#define MEAS3_DRVB1		   	 0x10
//#define MEAS3_DRVB2	    	0x20
//#define MEAS3_AMB	    	0x40
//
//
///*------------------------------------------------
//MEAS3 Configuration 1	(0x41) Bit Values
//------------------------------------------------*/
//
//#define MEAS3_AVER0 				0x01
//#define MEAS3_AVER1 	 	 0x02
//#define MEAS3_AVER2	 	0x04
//#define MEAS3_TINT0   				0x08
//#define MEAS3_TINT1		   	 0x10
//#define MEAS3_FILT_SEL	    	0x20
//#define MEAS3_FILT2_SEL	    	0x40
//#define MEAS3_SINC3_SEL	   		 0x80
//
///*------------------------------------------------
//MEAS3 Configuration 2	(0x42) Bit Values
//------------------------------------------------*/
//
//#define MEAS3_PPG1_ADC_RGE0 				0x01
//#define MEAS3_PPG1_ADC_RGE1 	 	 0x02
//
//#define MEAS3_PPG2_ADC_RGE0		   	 0x10
//#define MEAS3_PPG2_ADC_RGE1	    	0x20
//
///*------------------------------------------------
//MEAS3 Configuration 3	(0x43) Bit Values
//------------------------------------------------*/
//
//#define MEAS3_PPG1_DACOFF0 				0x01
//#define MEAS3_PPG1_DACOFF1 	 	 0x02
//#define MEAS3_PPG1_DACOFF2	 	0x04
//#define MEAS3_PPG1_DACOFF3   				0x08
//#define MEAS3_PPG2_DACOFF0		   	 0x10
//#define MEAS3_PPG2_DACOFF1	    	0x20
//#define MEAS3_PPG2_DACOFF2	    	0x40
//#define MEAS3_PPG2_DACOFF3	   		 0x80
//
///*------------------------------------------------
//MEAS3 Configuration 4	(0x44) Bit Values
//------------------------------------------------*/
//
//#define MEAS3_LED_RGE0 				0x01
//#define MEAS3_LED_RGE1 	 	 0x02
//#define MEAS3_LED_SETLNG0	 	0x04
//#define MEAS3_LED_SETLNG1   				0x08
//#define MEAS3_PD_SETLNG0	    	0x40
//#define MEAS3_PD_SETLNG1	   		 0x80
//
///*------------------------------------------------
//MEAS3 Configuration 5	(0x45) Bit Values
//------------------------------------------------*/
//#define MEAS3_PD1_SEL0    				0x01
//#define MEAS3_PD1_SEL1 	 	 0x02
//#define MEAS3_PD2_SEL0    	 	0x04
//#define MEAS3_PD2_SEL1     				0x08
//#define MEAS3_PD3_SEL0 		   	 0x10
//#define MEAS3_PD3_SEL1 	    	0x20
//#define MEAS3_PD4_SEL0 	    	0x40
//#define MEAS3_PD4_SEL1	   		 0x80
//
///*------------------------------------------------
//MEAS3 LEDA Current	(0x46) Bit Values
//------------------------------------------------*/
//#define MEAS3_DRVA_PA0    				0x01
//#define MEAS3_DRVA_PA1 	 	 0x02
//#define MEAS3_DRVA_PA2    	 	0x04
//#define MEAS3_DRVA_PA3     				0x08
//#define MEAS3_DRVA_PA4 		   	 0x10
//#define MEAS3_DRVA_PA5 	    	0x20
//#define MEAS3_DRVA_PA6 	    	0x40
//#define MEAS3_DRVA_PA7	   		 0x80
//
///*------------------------------------------------
//MEAS3 LEDB Current	(0x47) Bit Values
//------------------------------------------------*/
//#define MEAS3_DRVB_PA0    				0x01
//#define MEAS3_DRVB_PA1 	 	 0x02
//#define MEAS3_DRVB_PA2    	 	0x04
//#define MEAS3_DRVB_PA3     				0x08
//#define MEAS3_DRVB_PA4 		   	 0x10
//#define MEAS3_DRVB_PA5 	    	0x20
//#define MEAS3_DRVB_PA6 	    	0x40
//#define MEAS3_DRVB_PA7	   		 0x80
//
//
///*------------------------------------------------
//MEAS4 Selects	(0x48) Bit Values
//------------------------------------------------*/
//
//#define MEAS4_DRVA0 				0x01
//#define MEAS4_DRVA1 	 	 0x02
//#define MEAS4_DRVA2	 	0x04
//#define MEAS4_DRVB0   				0x08
//#define MEAS4_DRVB1		   	 0x10
//#define MEAS4_DRVB2	    	0x20
//#define MEAS4_AMB	    	0x40
//
//
///*------------------------------------------------
//MEAS4 Configuration 1	(0x49) Bit Values
//------------------------------------------------*/
//
//#define MEAS4_AVER0 				0x01
//#define MEAS4_AVER1 	 	 0x02
//#define MEAS4_AVER2	 	0x04
//#define MEAS4_TINT0   				0x08
//#define MEAS4_TINT1		   	 0x10
//#define MEAS4_FILT_SEL	    	0x20
//#define MEAS4_FILT2_SEL	    	0x40
//#define MEAS4_SINC3_SEL	   		 0x80
//
///*------------------------------------------------
//MEAS4 Configuration 2	(0x4A) Bit Values
//------------------------------------------------*/
//
//#define MEAS4_PPG1_ADC_RGE0 				0x01
//#define MEAS4_PPG1_ADC_RGE1 	 	 0x02
//
//#define MEAS4_PPG2_ADC_RGE0		   	 0x10
//#define MEAS4_PPG2_ADC_RGE1	    	0x20
//
///*------------------------------------------------
//MEAS4 Configuration 3	(0x4B) Bit Values
//------------------------------------------------*/
//
//#define MEAS4_PPG1_DACOFF0 				0x01
//#define MEAS4_PPG1_DACOFF1 	 	 0x02
//#define MEAS4_PPG1_DACOFF2	 	0x04
//#define MEAS4_PPG1_DACOFF3   				0x08
//#define MEAS4_PPG2_DACOFF0		   	 0x10
//#define MEAS4_PPG2_DACOFF1	    	0x20
//#define MEAS4_PPG2_DACOFF2	    	0x40
//#define MEAS4_PPG2_DACOFF3	   		 0x80
//
///*------------------------------------------------
//MEAS4 Configuration 4	(0x4C) Bit Values
//------------------------------------------------*/
//
//#define MEAS4_LED_RGE0 				0x01
//#define MEAS4_LED_RGE1 	 	 0x02
//#define MEAS4_LED_SETLNG0	 	0x04
//#define MEAS4_LED_SETLNG1   				0x08
//#define MEAS4_PD_SETLNG0	    	0x40
//#define MEAS4_PD_SETLNG1	   		 0x80
//
///*------------------------------------------------
//MEAS4 Configuration 5	(0x4D) Bit Values
//------------------------------------------------*/
//#define MEAS4_PD1_SEL0    				0x01
//#define MEAS4_PD1_SEL1 	 	 0x02
//#define MEAS4_PD2_SEL0    	 	0x04
//#define MEAS4_PD2_SEL1     				0x08
//#define MEAS4_PD3_SEL0 		   	 0x10
//#define MEAS4_PD3_SEL1 	    	0x20
//#define MEAS4_PD4_SEL0 	    	0x40
//#define MEAS4_PD4_SEL1	   		 0x80
//
///*------------------------------------------------
//MEAS4 LEDA Current	(0x4E) Bit Values
//------------------------------------------------*/
//#define MEAS4_DRVA_PA0    				0x01
//#define MEAS4_DRVA_PA1 	 	 0x02
//#define MEAS4_DRVA_PA2    	 	0x04
//#define MEAS4_DRVA_PA3     				0x08
//#define MEAS4_DRVA_PA4 		   	 0x10
//#define MEAS4_DRVA_PA5 	    	0x20
//#define MEAS4_DRVA_PA6 	    	0x40
//#define MEAS4_DRVA_PA7	   		 0x80
//
///*------------------------------------------------
//MEAS4 LEDB Current	(0x4F) Bit Values
//------------------------------------------------*/
//#define MEAS4_DRVB_PA0    				0x01
//#define MEAS4_DRVB_PA1 	 	 0x02
//#define MEAS4_DRVB_PA2    	 	0x04
//#define MEAS4_DRVB_PA3     				0x08
//#define MEAS4_DRVB_PA4 		   	 0x10
//#define MEAS4_DRVB_PA5 	    	0x20
//#define MEAS4_DRVB_PA6 	    	0x40
//#define MEAS4_DRVB_PA7	   		 0x80
//
///*------------------------------------------------
//MEAS5 Selects	(0x50) Bit Values
//------------------------------------------------*/
//
//#define MEAS5_DRVA0 				0x01
//#define MEAS5_DRVA1 	 	 0x02
//#define MEAS5_DRVA2	 	0x04
//#define MEAS5_DRVB0   				0x08
//#define MEAS5_DRVB1		   	 0x10
//#define MEAS5_DRVB2	    	0x20
//#define MEAS5_AMB	    	0x40
//
//
///*------------------------------------------------
//MEAS5 Configuration 1	(0x51) Bit Values
//------------------------------------------------*/
//
//#define MEAS5_AVER0 				0x01
//#define MEAS5_AVER1 	 	 0x02
//#define MEAS5_AVER2	 	0x04
//#define MEAS5_TINT0   				0x08
//#define MEAS5_TINT1		   	 0x10
//#define MEAS5_FILT_SEL	    	0x20
//#define MEAS5_FILT2_SEL	    	0x40
//#define MEAS5_SINC3_SEL	   		 0x80
//
///*------------------------------------------------
//MEAS5 Configuration 2	(0x52) Bit Values
//------------------------------------------------*/
//
//#define MEAS5_PPG1_ADC_RGE0 				0x01
//#define MEAS5_PPG1_ADC_RGE1 	 	 0x02
//
//#define MEAS5_PPG2_ADC_RGE0		   	 0x10
//#define MEAS5_PPG2_ADC_RGE1	    	0x20
//
///*------------------------------------------------
//MEAS5 Configuration 3	(0x53) Bit Values
//------------------------------------------------*/
//
//#define MEAS5_PPG1_DACOFF0 				0x01
//#define MEAS5_PPG1_DACOFF1 	 	 0x02
//#define MEAS5_PPG1_DACOFF2	 	0x04
//#define MEAS5_PPG1_DACOFF3   				0x08
//#define MEAS5_PPG2_DACOFF0		   	 0x10
//#define MEAS5_PPG2_DACOFF1	    	0x20
//#define MEAS5_PPG2_DACOFF2	    	0x40
//#define MEAS5_PPG2_DACOFF3	   		 0x80
//
///*------------------------------------------------
//MEAS5 Configuration 4	(0x54) Bit Values
//------------------------------------------------*/
//
//#define MEAS5_LED_RGE0 				0x01
//#define MEAS5_LED_RGE1 	 	 0x02
//#define MEAS5_LED_SETLNG0	 	0x04
//#define MEAS5_LED_SETLNG1   				0x08
//#define MEAS5_PD_SETLNG0	    	0x40
//#define MEAS5_PD_SETLNG1	   		 0x80
//
///*------------------------------------------------
//MEAS5 Configuration 5	(0x55) Bit Values
//------------------------------------------------*/
//#define MEAS5_PD1_SEL0    				0x01
//#define MEAS5_PD1_SEL1 	 	 0x02
//#define MEAS5_PD2_SEL0    	 	0x04
//#define MEAS5_PD2_SEL1     				0x08
//#define MEAS5_PD3_SEL0 		   	 0x10
//#define MEAS5_PD3_SEL1 	    	0x20
//#define MEAS5_PD4_SEL0 	    	0x40
//#define MEAS5_PD4_SEL1	   		 0x80
//
///*------------------------------------------------
//MEAS5 LEDA Current	(0x56) Bit Values
//------------------------------------------------*/
//#define MEAS5_DRVA_PA0    				0x01
//#define MEAS5_DRVA_PA1 	 	 0x02
//#define MEAS5_DRVA_PA2    	 	0x04
//#define MEAS5_DRVA_PA3     				0x08
//#define MEAS5_DRVA_PA4 		   	 0x10
//#define MEAS5_DRVA_PA5 	    	0x20
//#define MEAS5_DRVA_PA6 	    	0x40
//#define MEAS5_DRVA_PA7	   		 0x80
//
///*------------------------------------------------
//MEAS5 LEDB Current	(0x57) Bit Values
//------------------------------------------------*/
//#define MEAS5_DRVB_PA0    				0x01
//#define MEAS5_DRVB_PA1 	 	 0x02
//#define MEAS5_DRVB_PA2    	 	0x04
//#define MEAS5_DRVB_PA3     				0x08
//#define MEAS5_DRVB_PA4 		   	 0x10
//#define MEAS5_DRVB_PA5 	    	0x20
//#define MEAS5_DRVB_PA6 	    	0x40
//#define MEAS5_DRVB_PA7	   		 0x80
//
///*------------------------------------------------
//MEAS6 Selects	(0x58) Bit Values
//------------------------------------------------*/
//
//#define MEAS6_DRVA0 				0x01
//#define MEAS6_DRVA1 	 	 0x02
//#define MEAS6_DRVA2	 	0x04
//#define MEAS6_DRVB0   				0x08
//#define MEAS6_DRVB1		   	 0x10
//#define MEAS6_DRVB2	    	0x20
//#define MEAS6_AMB	    	0x40
//
//
///*------------------------------------------------
//MEAS6 Configuration 1	(0x59) Bit Values
//------------------------------------------------*/
//
//#define MEAS6_AVER0 				0x01
//#define MEAS6_AVER1 	 	 0x02
//#define MEAS6_AVER2	 	0x04
//#define MEAS6_TINT0   				0x08
//#define MEAS6_TINT1		   	 0x10
//#define MEAS6_FILT_SEL	    	0x20
//#define MEAS6_FILT2_SEL	    	0x40
//#define MEAS6_SINC3_SEL	   		 0x80
//
///*------------------------------------------------
//MEAS6 Configuration 2	(0x5A) Bit Values
//------------------------------------------------*/
//
//#define MEAS6_PPG1_ADC_RGE0 				0x01
//#define MEAS6_PPG1_ADC_RGE1 	 	 0x02
//
//#define MEAS6_PPG2_ADC_RGE0		   	 0x10
//#define MEAS6_PPG2_ADC_RGE1	    	0x20
//
///*------------------------------------------------
//MEAS6 Configuration 3	(0x5B) Bit Values
//------------------------------------------------*/
//
//#define MEAS6_PPG1_DACOFF0 				0x01
//#define MEAS6_PPG1_DACOFF1 	 	 0x02
//#define MEAS6_PPG1_DACOFF2	 	0x04
//#define MEAS6_PPG1_DACOFF3   				0x08
//#define MEAS6_PPG2_DACOFF0		   	 0x10
//#define MEAS6_PPG2_DACOFF1	    	0x20
//#define MEAS6_PPG2_DACOFF2	    	0x40
//#define MEAS6_PPG2_DACOFF3	   		 0x80
//
///*------------------------------------------------
//MEAS6 Configuration 4	(0x5C) Bit Values
//------------------------------------------------*/
//
//#define MEAS6_LED_RGE0 				0x01
//#define MEAS6_LED_RGE1 	 	 0x02
//#define MEAS6_LED_SETLNG0	 	0x04
//#define MEAS6_LED_SETLNG1   				0x08
//#define MEAS6_PD_SETLNG0	    	0x40
//#define MEAS6_PD_SETLNG1	   		 0x80
//
///*------------------------------------------------
//MEAS6 Configuration 5	(0x5D) Bit Values
//------------------------------------------------*/
//#define MEAS6_PD1_SEL0    				0x01
//#define MEAS6_PD1_SEL1 	 	 0x02
//#define MEAS6_PD2_SEL0    	 	0x04
//#define MEAS6_PD2_SEL1     				0x08
//#define MEAS6_PD3_SEL0 		   	 0x10
//#define MEAS6_PD3_SEL1 	    	0x20
//#define MEAS6_PD4_SEL0 	    	0x40
//#define MEAS6_PD4_SEL1	   		 0x80
//
///*------------------------------------------------
//MEAS6 LEDA Current	(0x5E) Bit Values
//------------------------------------------------*/
//#define MEAS6_DRVA_PA0    				0x01
//#define MEAS6_DRVA_PA1 	 	 0x02
//#define MEAS6_DRVA_PA2    	 	0x04
//#define MEAS6_DRVA_PA3     				0x08
//#define MEAS6_DRVA_PA4 		   	 0x10
//#define MEAS6_DRVA_PA5 	    	0x20
//#define MEAS6_DRVA_PA6 	    	0x40
//#define MEAS6_DRVA_PA7	   		 0x80
//
///*------------------------------------------------
//MEAS6 LEDB Current	(0x5F) Bit Values
//------------------------------------------------*/
//#define MEAS6_DRVB_PA0    				0x01
//#define MEAS6_DRVB_PA1 	 	 0x02
//#define MEAS6_DRVB_PA2    	 	0x04
//#define MEAS6_DRVB_PA3     				0x08
//#define MEAS6_DRVB_PA4 		   	 0x10
//#define MEAS6_DRVB_PA5 	    	0x20
//#define MEAS6_DRVB_PA6 	    	0x40
//#define MEAS6_DRVB_PA7	   		 0x80
//
///*------------------------------------------------
//THRESHOLD MEAS SEL	(0x70) Bit Values
//------------------------------------------------*/
//
//#define THRESH1_MEAS_SEL0 				0x01
//#define THRESH1_MEAS_SEL1 	 	 0x02
//#define THRESH1_MEAS_SEL2	 	0x04
//#define MEAS3_TINT0   				0x08
//#define THRESH2_MEAS_SEL0		   	 0x10
//#define THRESH2_MEAS_SEL1	    	0x20
//#define THRESH2_MEAS_SEL2    	0x40
//
///*------------------------------------------------
//THRESHOLD HYST	(0x71) Bit Values
//------------------------------------------------*/
//#define LEVEL_HYST0    				0x01
//#define LEVEL_HYST1 	 	 0x02
//#define LEVEL_HYST2    	 	0x04
//#define TIME_HYST0     				0x08
//#define TIME_HYST1 		   	 0x10
//#define THRESH1_PPG_SEL 	    	0x40
//#define THRESH2_PPG_SEL	   		 0x80
//
///*------------------------------------------------
//PPG HI THRESHOLD1	(0x72) Bit Values
//------------------------------------------------*/
//#define THRESHOLD1_UPPER0    				0x01
//#define THRESHOLD1_UPPER1 	 	 0x02
//#define THRESHOLD1_UPPER2    	 	0x04
//#define THRESHOLD1_UPPER3     				0x08
//#define THRESHOLD1_UPPER4 		   	 0x10
//#define THRESHOLD1_UPPER5 	    	0x20
//#define THRESHOLD1_UPPER6 	    	0x40
//#define THRESHOLD1_UPPER7	   		 0x80
//
///*------------------------------------------------
//PPG LO THRESHOLD1	(0x73) Bit Values
//------------------------------------------------*/
//#define THRESHOLD1_LOWER0    				0x01
//#define THRESHOLD1_LOWER1 	 	 0x02
//#define THRESHOLD1_LOWER2    	 	0x04
//#define THRESHOLD1_LOWER3     				0x08
//#define THRESHOLD1_LOWER4 		   	 0x10
//#define THRESHOLD1_LOWER5 	    	0x20
//#define THRESHOLD1_LOWER6 	    	0x40
//#define THRESHOLD1_LOWER7	   		 0x80
///*------------------------------------------------
//PPG HI THRESHOLD2	(0x74) Bit Values
//------------------------------------------------*/
//#define THRESHOLD2_UPPER0    				0x01
//#define THRESHOLD2_UPPER1 	 	 0x02
//#define THRESHOLD2_UPPER2    	 	0x04
//#define THRESHOLD2_UPPER3     				0x08
//#define THRESHOLD2_UPPER4 		   	 0x10
//#define THRESHOLD2_UPPER5 	    	0x20
//#define THRESHOLD2_UPPER6 	    	0x40
//#define THRESHOLD2_UPPER7	   		 0x80
//
///*------------------------------------------------
//PPG LO THRESHOLD2	(0x75) Bit Values
//------------------------------------------------*/
//#define THRESHOLD2_LOWER0    				0x01
//#define THRESHOLD2_LOWER1 	 	 0x02
//#define THRESHOLD2_LOWER2    	 	0x04
//#define THRESHOLD2_LOWER3     				0x08
//#define THRESHOLD2_LOWER4 		   	 0x10
//#define THRESHOLD2_LOWER5 	    	0x20
//#define THRESHOLD2_LOWER6 	    	0x40
//#define THRESHOLD2_LOWER7	   		 0x80
//
///*------------------------------------------------
//ECG Configuration 1(0x80) Bit Values
//------------------------------------------------*/
//#define ECG_EN 				0x01
//#define ECG_DEC_RATE0 				0x02
//#define ECG_DEC_RATE1 	 	 0x04
//#define ECG_DEC_RATE2	 	0x08
//
///*------------------------------------------------
//ECG Configuration 1(0x81) Bit Values
//------------------------------------------------*/
//#define ECG_INA_GAIN0    				0x01
//#define ECG_INA_GAIN1 	 			 0x02
//#define ECG_INA_RGE0  	 	0x04
//#define ECG_INA_RGE1     				0x08
//#define ECG_PGA_GAIN0		   	 0x10
//#define ECG_PGA_GAIN1	    	0x20
//#define ECG_PGA_GAIN2 	    	0x40
//#define ECG_IPOL	   		 0x80
///*------------------------------------------------
//ECG Configuration 3(0x82) Bit Values
//------------------------------------------------*/
//#define ECG_MUX_SEL0    				0x01
//#define ECG_MUX_SEL1 	 			 0x02
//#define ECG_AUTO_REC  	 	0x04
//#define ECG_IMP_HI     				0x08
//
///*------------------------------------------------
//ECG Configuration 4(0x83) Bit Values
//------------------------------------------------*/
//#define ECG_FAST_REC_THRESHOLD0    				0x01
//#define ECG_FAST_REC_THRESHOLD1	 			 0x02
//#define ECG_FAST_REC_THRESHOLD2  	 	0x04
//#define ECG_FAST_REC_THRESHOLD3     				0x08
//#define ECG_FAST_REC_THRESHOLD4		   	 0x10
//#define ECG_FAST_REC_THRESHOLD5    	0x20
//#define EN_ECG_FAST_REC0 	    	0x40
//#define EN_ECG_FAST_REC1	   		 0x80
//
///*------------------------------------------------
//ECG CAL Configuration 1(0x84) Bit Values
//------------------------------------------------*/
//#define ECG_CAL_EN    				0x01
//#define ECG_CAL_DUTY	 			 0x02
//#define ECG_CAL_FREQ0  	 	0x04
//#define ECG_CAL_FREQ1      				0x08
//#define ECG_CAL_FREQ2 		   	 0x10
//#define ECG_CAL_HIGH8     	0x20
//#define ECG_CAL_HIGH9 	    	0x40
//#define ECG_CAL_HIGH10	   		 0x80
//
///*------------------------------------------------
//ECG CAL Configuration 2(0x85) Bit Values
//------------------------------------------------*/
//#define ECG_CAL_HIGH0  				0x01
//#define ECG_CAL_HIGH1	 			 0x02
//#define ECG_CAL_HIGH2 	 	0x04
//#define ECG_CAL_HIGH3      				0x08
//#define ECG_CAL_HIGH4 		   	 0x10
//#define ECG_CAL_HIGH5     	0x20
//#define ECG_CAL_HIGH6 	    	0x40
//#define ECG_CAL_HIGH7	   		 0x80
//
///*------------------------------------------------
//ECG CAL Configuration 3(0x86) Bit Values
//------------------------------------------------*/
//#define ECG_CAL_N_SEL0  				0x01
//#define ECG_CAL_N_SEL1	 			 0x02
//#define ECG_CAL_P_SEL0 	 	0x04
//#define ECG_CAL_P_SEL1      				0x08
//#define ECG_CAL_MAG 		   	 0x10
//#define ECG_CAL_MODE     	0x20
//#define ECG_CAL_OPEN_N 	    	0x40
//#define ECG_CAL_OPEN_P   		 0x80
//
///*------------------------------------------------
//ECG Lead Detect Configuration 1(0x88) Bit Values
//------------------------------------------------*/
//#define ECG_LOFF_FREQ0  				0x01
//#define ECG_LOFF_FREQ1	 			 0x02
//#define ECG_LOFF_FREQ2 	 	0x04
//#define ECG_LOFF_MODE      				0x08
//
//#define EN_ECG_CAL_LOFF 	    	0x40
//#define EN_ECG_CAL_LON 	   		 0x80
//
///*------------------------------------------------
//ECG Lead Detect Configuration 2(0x89) Bit Values
//------------------------------------------------*/
//#define ECG_LOFF_THRESH0  				0x01
//#define ECG_LOFF_THRESH1	 			 0x02
//#define ECG_LOFF_THRESH2 	 	0x04
//#define ECG_LOFF_THRESH3      				0x08
//#define ECG_LOFF_IMAG0  		   	 0x10
//#define ECG_LOFF_IMAG1     	0x20
//#define ECG_LOFF_IMAG2 	    	0x40
//#define ECG_LOFF_IPOL	   		 0x80
//
///*------------------------------------------------
//ECG Lead Bias Configuration 2(0x90) Bit Values
//------------------------------------------------*/
//#define EN_ECG_RBIASN  				0x01
//#define EN_ECG_RBIASP	 			 0x02
//#define ECG_RBIAS_VALUE0 	 	0x04
//#define ECG_RBIAS_VALUE1     				0x08
//
///*------------------------------------------------
//RLD Configuration 1(0x92) Bit Values
//------------------------------------------------*/
//#define RLD_GAIN0  				0x01
//#define RLD_GAIN1	 			 0x02
//#define ACTV_CM_N 	 	0x04
//#define ACTV_CM_P      				0x08
//#define EN_RLD_OOR  		   	 0x10
//#define RLD_RBIAS     	0x20
//#define RLD_MODE	    	0x40
//#define RLD_EN	   		 0x80
//
///*------------------------------------------------
//RLD Configuration 2(0x93) Bit Values
//------------------------------------------------*/
//#define BODY_BIAS_DAC0  				0x01
//#define BODY_BIAS_DAC1	 			 0x02
//#define BODY_BIAS_DAC2 	 	0x04
//#define BODY_BIAS_DAC3     				0x08
//#define RLD_BW0		  		   	 0x10
//#define RLD_BW1     	0x20
//#define RLD_SEL_ECG	    	0x40
//#define RLD_EXT_RES	   		 0x80
//
///*------------------------------------------------
//BIOZ Configuration 1(0xA0) Bit Values
//------------------------------------------------*/
//#define BIOZ_EN0    				0x01
//#define BIOZ_EN1	 			 0x02
//#define ECG_BIOZ_BG_EN  	 	0x04
//#define BIOZ_ADC_OSR0      				0x08
//#define BIOZ_ADC_OSR1  		   	 0x10
//#define BIOZ_ADC_OSR2      	0x20
//#define BIOZ_DAC_OSR0  	    	0x40
//#define BIOZ_DAC_OSR1	   			0x80
//
///*------------------------------------------------
//BIOZ Configuration 2(0xA1) Bit Values
//------------------------------------------------*/
//#define EN_BIOZ_THRESH    				0x01
//
//#define BIOZ_DLPF0      				0x08
//#define BIOZ_DLPF1  		   	 0x10
//#define BIOZ_DLPF2      	0x20
//#define BIOZ_DHPF0  	    	0x40
//#define BIOZ_DHPF1	  			0x80
//
///*------------------------------------------------
//BIOZ Configuration 3(0xA2) Bit Values
//------------------------------------------------*/
//#define BIOZ_DRV_MODE0    				0x01
//#define BIOZ_DRV_MODE1	 			 0x02
//#define BIOZ_IDRV_RGE0 	 	0x04
//#define BIOZ_IDRV_RGE1      				0x08
//#define BIOZ_VDRV_MAG0  		   	 0x10
//#define BIOZ_VDRV_MAG1      	0x20
//
//#define BIOZ_EXT_RES	   		0x80
//
///*------------------------------------------------
//BIOZ Configuration 4(0xA3) Bit Values
//------------------------------------------------*/
//
//
//#define EN_UTIL_MODE	   		0x80
//
///*------------------------------------------------
//BIOZ Configuration 5(0xA4) Bit Values
//------------------------------------------------*/
//#define BIOZ_DC_DAC_CODE0    				0x01
//#define BIOZ_DC_DAC_CODE1 			 0x02
//#define BIOZ_DC_DAC_CODE2 	 	0x04
//#define BIOZ_DC_DAC_CODE3      				0x08
//#define BIOZ_DC_DAC_CODE4 		   	 0x10
//#define BIOZ_DC_DAC_CODE5      	0x20
//#define BIOZ_DC_DAC_CODE6  	    	0x40
//#define BIOZ_DC_CODE_SEL	   			0x80
//
///*------------------------------------------------
//BIOZ Configuration 6(0xA5) Bit Values
//------------------------------------------------*/
//#define BIOZ_GAIN0    				0x01
//#define BIOZ_GAIN1 			 0x02
//#define BIOZ_DM_DIS 	 	0x04
//#define BIOZ_INA_MODE      				0x08
//#define BIOZ_AHPF0 		   	 0x10
//#define BIOZ_AHPF1      	0x20
//#define BIOZ_AHPF2  	    	0x40
//#define BIOZ_AHPF3	   			0x80
//
///*------------------------------------------------
//BIOZ Configuration 7(0xA6) Bit Values
//------------------------------------------------*/
//#define BIOZ_AMP_BW0    				0x01
//#define BIOZ_AMP_BW1 			 0x02
//#define BIOZ_AMP_RGE0 	 	0x04
//#define BIOZ_AMP_RGE1      				0x08
//#define BIOZ_DAC_RESET		   	 0x10
//#define BIOZ_DRV_RESET      	0x20
//#define BIOZ_DC_RESTORE  	    	0x40
//#define BIOZ_EXT_CAP	   			0x80
//
///*------------------------------------------------
//BIOZ Configuration 8(0xA7) Bit Values
//------------------------------------------------*/
//#define BIOZ_CH_FSEL    				0x01
//#define BIOZ_INA_CHOP_EN 			 0x02
//#define BIOZ_FAST 	 					0x04
//#define BIOZ_IPOL     				0x08
//#define BIOZ_STBY_ON		   	 0x10
//#define BIOZ_CMRES_DIS      	0x20
//#define RLD_DRV  	  			  	0x40
//#define RLD_SEL_BIOZ	   			0x80
//
///*------------------------------------------------
//BIOZ Low Threshold (0xA8) Bit Values
//------------------------------------------------*/
//#define BIOZ_LO_THRESH0  				0x01
//#define BIOZ_LO_THRESH1	 			 0x02
//#define BIOZ_LO_THRESH2 	 			0x04
//#define BIOZ_LO_THRESH3      				0x08
//#define BIOZ_LO_THRESH4 		   		 0x10
//#define BIOZ_LO_THRESH5     				0x20
//#define BIOZ_LO_THRESH6 	    			0x40
//#define BIOZ_LO_THRESH7	   			 0x80
//
///*------------------------------------------------
//BIOZ High Threshold (0xA9) Bit Values
//------------------------------------------------*/
//#define BIOZ_HI_THRESH0  				0x01
//#define BIOZ_HI_THRESH1	 			 0x02
//#define BIOZ_HI_THRESH2 	 			0x04
//#define BIOZ_HI_THRESH3      				0x08
//#define BIOZ_HI_THRESH4 		   		 0x10
//#define BIOZ_HI_THRESH5     				0x20
//#define BIOZ_HI_THRESH6 	    			0x40
//#define BIOZ_HI_THRESH7	   			 0x80
//
///*------------------------------------------------
//BIOZ Mux Configuration 1(0xAA) Bit Values
//------------------------------------------------*/
//#define BIOZ_CAL_EN  				0x01
//#define BIOZ_MUX_EN	 			 0x02
//#define CONNECT_CAL_ONLY 	 			0x04
//
//#define BMUX_BIST_EN 				0x20
//#define BMUX_RSEL0 	    			0x40
//#define BMUX_RSEL1   			 0x80
//
///*------------------------------------------------
//BIOZ Mux Configuration 2(0xAB) Bit Values
//------------------------------------------------*/
//#define EN_INT_INLOAD  				0x01
//#define EN_EXT_INLOAD			 0x02
//
//
//#define GSR_LOAD_EN 				0x20
//#define BMUX_GSR_RSEL0 	    			0x40
//#define BMUX_GSR_RSEL1   			 0x80
//
///*------------------------------------------------
//BIOZ Mux Configuration 3(0xAC) Bit Values
//------------------------------------------------*/
//#define DRVN_ASSIGN0  				0x01
//#define DRVN_ASSIGN1	 			 0x02
//#define DRVP_ASSIGN0 	 			0x04
//#define DRVP_ASSIGN1      				0x08
//#define BIN_ASSIGN0		   		 0x10
//#define BIN_ASSIGN1     				0x20
//#define BIP_ASSIGN0	    			0x40
//#define BIP_ASSIGN1		   			 0x80
//
///*------------------------------------------------
//BIOZ Mux Configuration 4(0xAD) Bit Values
//------------------------------------------------*/
//#define BIST_R_ERR0  				0x01
//#define BIST_R_ERR1	 			 0x02
//#define BIST_R_ERR2 	 			0x04
//#define BIST_R_ERR3      				0x08
//#define BIST_R_ERR4 		   		 0x10
//#define BIST_R_ERR5     				0x20
//#define BIST_R_ERR6 	    			0x40
//#define BIST_R_ERR7	   			 0x80
//
///*------------------------------------------------
//BIOZ Lead Detect Configuration 1(0xB0) Bit Values
//------------------------------------------------*/
//#define BIOZ_LOFF_IMAG0  				0x01
//#define BIOZ_LOFF_IMAG1	 			 0x02
//#define BIOZ_LOFF_IMAG2 	 			0x04
//#define BIOZ_LOFF_IPOL      				0x08
//#define EN_BIOZ_DRV_OOR 		   		 0x10
//#define EN_EXT_BIOZ_LOFF     				0x20
//#define EN_BIOZ_LOFF	    			0x40
//#define EN_BIOZ_LON  			 0x80
//
///*------------------------------------------------
//BIOZ Lead-Off Threshold 1(0xB1) Bit Values
//------------------------------------------------*/
//#define BIOZ_LOFF_THRESH0  				0x01
//#define BIOZ_LOFF_THRESH1	 			 0x02
//#define BIOZ_LOFF_THRESH2 	 			0x04
//#define BIOZ_LOFF_THRESH3     				0x08
//#define RESP_CG_MAG0 		   		 0x10
//#define RESP_CG_MAG1     				0x20
//#define RESP_CG_MAG2	    			0x40
//#define RESP_CG_MAG_4X  			 0x80
//
///*------------------------------------------------
//BIOZ Lead Bias Configuration 1(0xB4) Bit Values
//------------------------------------------------*/
//#define EN_BIOZ_RBIASN  				0x01
//#define EN_BIOZ_RBIASP	 			 0x02
//#define BIOZ_RBIAS_VALUE0 	 			0x04
//#define BIOZ_RBIAS_VALUE1      				0x08
//
//
///*------------------------------------------------
//Respiration Configuration 1(0xB6) Bit Values
//------------------------------------------------*/
//#define RESP_EN  				0x01
//#define CG_MODE0	 			 0x02
//#define CG_MODE1 	 			0x04
//#define CG_CHOP_CLK0     				0x08
//#define CG_CHOP_CLK1 		   		 0x10
//#define CG_LPF_DUTY0    				0x20
//#define CG_LPF_DUTY1	    			0x40
//#define CG_LPF_DUTY2  			 0x80
//
///*------------------------------------------------
//Interrupt1 Enable 1(0xC0) Bit Values
//------------------------------------------------*/
//
//#define PPG_THRESH1_HILO_EN1	 			 0x02
//#define PPG_THRESH2_HILO_EN1	 			0x04
//#define EXP_OVF_EN1     				0x08
//#define ALC_OVF_EN1  		   		 0x10
//#define FIFO_DATA_RDY_EN1   				0x20
//#define PPG_FRAME_RDY_EN1	    			0x40
//#define A_FULL_EN1  			 0x80
//
///*------------------------------------------------
//Interrupt1 Enable 2(0xC1) Bit Values
//------------------------------------------------*/
//#define LED1_COMPB_EN1    			0x01
//#define LED2_COMPB_EN1	 			 0x02
//#define LED3_COMPB_EN1	 			0x04
//#define LED4_COMPB_EN1    				0x08
//#define LED5_COMPB_EN1 		   		 0x10
//#define LED6_COMPB_EN1   				0x20
//
//#define INVALID_PPG_CFG_EN1  			 0x80
//
//
///*------------------------------------------------
//Interrupt1 Enable 3(0xC2) Bit Values
//------------------------------------------------*/
//
//#define PHASE_LOCK_EN1	 			 0x02
//#define PHASE_UNLOCK_EN1	 			0x04
//#define FREQ_LOCK_EN1    				0x08
//#define FREQ_UNLOCK_EN1 		   		 0x10
//
///*------------------------------------------------
//Interrupt1 Enable 4(0xC3) Bit Values
//------------------------------------------------*/
//#define ECG_LOFF_NL_EN1    			0x01
//#define ECG_LOFF_NH_EN1  	 			 0x02
//#define ECG_LOFF_PL_EN1	 			0x04
//#define ECG_LOFF_PH_EN1   				0x08
//#define RLD_OOR_EN1 		   		 0x10
//#define ECG_FAST_REC_EN1   				0x20
//
//#define ECG_LON_EN1  			 0x80
//
///*------------------------------------------------
//Interrupt1 Enable 5(0xC4) Bit Values
//------------------------------------------------*/
//#define BIOZ_LOFF_NL_EN1    			0x01
//#define BIOZ_LOFF_NH_EN1  	 			 0x02
//#define BIOZ_LOFF_PL_EN1	 			0x04
//#define BIOZ_LOFF_PH_EN1   				0x08
//#define BIOZ_DRVP_OFF_EN1 		   		 0x10
//#define BIOZ_UNDR_EN1   				0x20
//#define BIOZ_OVER_EN1   				0x40
//#define BIOZ_LON_EN1  			 0x80
//
///*------------------------------------------------
//Interrupt2 Enable 1(0xC5) Bit Values
//------------------------------------------------*/
//
//#define PPG_THRESH1_HILO_EN2	 			 0x02
//#define PPG_THRESH2_HILO_EN2	 			0x04
//#define EXP_OVF_EN2     				0x08
//#define ALC_OVF_EN2  		   		 0x10
//#define FIFO_DATA_RDY_EN2   				0x20
//#define PPG_FRAME_RDY_EN2	    			0x40
//#define A_FULL_EN2  			 0x80
//
///*------------------------------------------------
//Interrupt2 Enable 2(0xC6) Bit Values
//------------------------------------------------*/
//#define LED1_COMPB_EN2    			0x01
//#define LED2_COMPB_EN2	 			 0x02
//#define LED3_COMPB_EN2	 			0x04
//#define LED4_COMPB_EN2    				0x08
//#define LED5_COMPB_EN2 		   		 0x10
//#define LED6_COMPB_EN2   				0x20
//
//#define INVALID_PPG_CFG_EN2  			 0x80
//
//
///*------------------------------------------------
//Interrupt2 Enable 3(0xC7) Bit Values
//------------------------------------------------*/
//
//#define PHASE_LOCK_EN2	 			 0x02
//#define PHASE_UNLOCK_EN2	 			0x04
//#define FREQ_LOCK_EN2    				0x08
//#define FREQ_UNLOCK_EN2 		   		 0x10
//
///*------------------------------------------------
//Interrupt2 Enable 4(0xC8) Bit Values
//------------------------------------------------*/
//#define ECG_LOFF_NL_EN2    			0x01
//#define ECG_LOFF_NH_EN2  	 			 0x02
//#define ECG_LOFF_PL_EN2	 			0x04
//#define ECG_LOFF_PH_EN2   				0x08
//#define RLD_OOR_EN2 		   		 0x10
//#define ECG_FAST_REC_EN2   				0x20
//
//#define ECG_LON_EN2  			 0x80
//
///*------------------------------------------------
//Interrupt2 Enable 5(0xC9) Bit Values
//------------------------------------------------*/
//#define BIOZ_LOFF_NL_EN2    			0x01
//#define BIOZ_LOFF_NH_EN2  	 			 0x02
//#define BIOZ_LOFF_PL_EN2	 			0x04
//#define BIOZ_LOFF_PH_EN2   				0x08
//#define BIOZ_DRVP_OFF_EN2 		   		 0x10
//#define BIOZ_UNDR_EN2   				0x20
//#define BIOZ_OVER_EN2   				0x40
//#define BIOZ_LON_EN2  			 0x80
//
///*------------------------------------------------
//Part ID(0xFF) Bit Values
//------------------------------------------------*/
//#define PART_ID0    			0x01
//#define PART_ID1   	 			 0x02
//#define PART_ID2 	 			0x04
//#define PART_ID3    				0x08
//#define PART_ID4  		   		 0x10
//#define PART_ID5    				0x20
//#define PART_ID6    				0x40
//#define PART_ID7   			 0x80


