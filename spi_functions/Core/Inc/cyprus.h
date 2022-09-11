/*
 * cyprus.h
 *
 *  Created on: Sep 9, 2022
 *      Author: essaj
 */

#ifndef INC_CYPRUS_H_
#define INC_CYPRUS_H_



#endif /* INC_CYPRUS_H_ */

#define base						(uint8_t)0x00


#define Set_Pin_Functional_Configuration (uint8_t)0x01


#define Set_PLL_Config2                 (uint8_t)0xff
#define Set_PLL_Config4                 (uint8_t)0x03
#define Set_PLL_Config5                 (uint8_t)0x40
#define Set_PLL_Config6                 (uint8_t)0x20

#define Set_ppg_config1                  (uint8_t)0x07
#define Set_ppg_config2                  (uint8_t)0x00
#define Set_ppg_config3                 (uint8_t)0x00
#define Set_ppg_config4                  (uint8_t)0x00
#define Set_photodiode_bias				 (uint8_t)0x55


#define Set_REF_CLK_SEL             (uint8_t)0x00                    //0-internal oscillator and 1-external oscillator
#define Set_CLK_FREQ_SEL			(uint8_t)0x1<<5 | Set_REF_CLK_SEL //0-32khz and 1-32.768khz



#define Set_FR_CLK_DIV              (uint8_t)0x01                          //default
//PPG Configuration
#define Set_PPG1_PWRDN              (uint8_t)0x00
#define Set_PPG2_PWRDN				(uint8_t)0x00
#define Set_MEAS1_EN				(uint8_t)0x01
#define Set_MEAS2_EN				(uint8_t)0x01<<2|Set_MEAS1_EN
#define Set_MEAS3_EN				(uint8_t)0x01<<3|Set_MEAS2_EN
//#define Set_MEAS4_EN				(uint8_t)0x01

//PPG MEASUREMENT 1 CONFIGURATION
#define Set_MEAS1_AMB				(uint8_t)0x00
#define Set_MEAS1_DRVA   			(uint8_t)0x00
#define Set_MEAS1_AVER				(uint8_t)0x0                     //for number of led pulses equal to 8
#define Set_MEAS1_PPG1_ADC_RGE		(uint8_t)0x3
#define Set_MEAS1_PPG2_ADC_RGE		base |(uint8_t)0x3<<4 |Set_MEAS1_PPG1_ADC_RGE   //default
#define Set_MEAS1_PPG_TINT			(uint8_t)0x3<<3 |Set_MEAS1_AVER
#define Set_MEAS1_FLTR2_SEL			(uint8_t)0x1<<6|Set_MEAS1_PPG_TINT
#define Set_MEAS1_LED_RGE			(uint8_t)0x3
#define Set_MEAS1_PD_SETLNG			base |(uint8_t)0x1<<6 |Set_MEAS1_LED_RGE
#define Set_MEAS1_LED_SETLNG		base |(uint8_t)0x1<<2 |Set_MEAS1_PD_SETLNG
#define Set_MEAS1_DRVA_PA			(uint8_t)0x0f
#define Set_MEAS1_DRVB_PA  			(uint8_t)0x00
#define Set_MEAS1_PD1_SEL  			(uint8_t)0x2
#define Set_MEAS1_PD2_SEL			(uint8_t)0x1<<2 |Set_MEAS1_PD1_SEL
#define Set_MEAS1_PD3_SEL  			(uint8_t)0x1<<3|Set_MEAS1_PD2_SEL

//PPG MEASUREMENT 2  CONFIGURATION
#define Set_MEAS2_AMB				(uint8_t)0x00
#define Set_MEAS2_DRVA   			(uint8_t)0x1
#define Set_MEAS2_AVER				(uint8_t)0x0
#define Set_MEAS2_PPG1_ADC_RGE		(uint8_t)0x3
#define Set_MEAS2_PPG2_ADC_RGE		base |(uint8_t)0x2<<4 |Set_MEAS2_PPG1_ADC_RGE
#define Set_MEAS2_PPG_TINT			(uint8_t)0x3<<3|Set_MEAS2_AVER
#define Set_MEAS2_FLTR2_SEL			(uint8_t)0x1<<6|Set_MEAS2_PPG_TINT
#define Set_MEAS2_LED_RGE			(uint8_t)0x3
#define Set_MEAS2_PD_SETLNG			base |(uint8_t)0x1<<6 |Set_MEAS2_LED_RGE
#define Set_MEAS2_LED_SETLNG		base |(uint8_t)0x1<<2 |Set_MEAS2_PD_SETLNG
#define Set_MEAS2_DRVA_PA			(uint8_t)0x01e
#define Set_MEAS2_DRVB_PA  			(uint8_t)0x00
#define Set_MEAS2_PD3_SEL  			(uint8_t)0x20

//PPG MEASUREMENT 3  CONFIGURATION
#define Set_MEAS3_AMB				(uint8_t)0x00
#define Set_MEAS3_DRVA              base |(uint8_t)0x1<<1
#define Set_MEAS3_AVER				(uint8_t)0x0					  //for number of led pulses equal to 8
#define Set_MEAS3_PPG1_ADC_RGE		(uint8_t)0x3
#define Set_MEAS3_PPG2_ADC_RGE		base |(uint8_t)0x2<<4 |Set_MEAS3_PPG1_ADC_RGE
#define Set_MEAS3_PPG_TINT			base |(uint8_t)0x3<<3|Set_MEAS3_AVER
#define Set_MEAS3_FLTR2_SEL			base |(uint8_t)0x1<<6|Set_MEAS3_PPG_TINT
#define Set_MEAS3_LED_RGE			(uint8_t)0x3
#define Set_MEAS3_PD_SETLNG			base |(uint8_t)0x1<<6 |Set_MEAS3_LED_RGE
#define Set_MEAS3_LED_SETLNG		base |(uint8_t)0x1<<2 |Set_MEAS3_PD_SETLNG
#define Set_MEAS3_DRVA_PA			(uint8_t)0x20
#define Set_MEAS3_DRVB_PA  			(uint8_t)0x00
#define Set_MEAS3_PD3_SEL  			base |(uint8_t)0x20

//PPG MEASUREMENT 4  CONFIGURATION
#define Set_MEAS4_AMB				(uint8_t)0x00
#define Set_MEAS4_PPG1_ADC_RGE		(uint8_t)0x2
#define Set_MEAS4_PPG2_ADC_RGE		base |(uint8_t)0x2<<4 |Set_MEAS4_PPG1_ADC_RGE
#define Set_MEAS4_PPG_TINT			base |(uint8_t)0x3<<3
#define Set_MEAS4_FLTR2_SEL			base |(uint8_t)0x1<<6|Set_MEAS4_PPG_TINT
#define Set_MEAS4_PD1_SEL  			(uint8_t)0x2
#define Set_MEAS4_PD2_SEL  			base |(uint8_t)0x3<<2|Set_MEAS4_PD1_SEL

//PPG MEASUREMENT 5  CONFIGURATION
#define Set_MEAS5_AMB				(uint8_t)0x00
#define Set_MEAS5_DRVA              base |(uint8_t)0x00
#define Set_MEAS5_AVER				(uint8_t)0x0					  //for number of led pulses equal to 8
#define Set_MEAS5_PPG1_ADC_RGE		(uint8_t)0x2
#define Set_MEAS5_PPG2_ADC_RGE		base |(uint8_t)0x2<<4 |Set_MEAS3_PPG1_ADC_RGE
#define Set_MEAS5_PPG_TINT			base |(uint8_t)0x3<<3|Set_MEAS3_AVER
#define Set_MEAS5_FLTR2_SEL			base |(uint8_t)0x1<<6|Set_MEAS3_PPG_TINT
#define Set_MEAS5_LED_RGE			(uint8_t)0x3
#define Set_MEAS5_PD_SETLNG			base |(uint8_t)0x1<<6 |Set_MEAS3_LED_RGE
#define Set_MEAS5_LED_SETLNG		base |(uint8_t)0x1<<2 |Set_MEAS3_PD_SETLNG
#define Set_MEAS5_DRVA_PA			(uint8_t)0x00
#define Set_MEAS5_DRVB_PA  			(uint8_t)0x00
#define Set_MEAS5_PD1_SEL  			base |(uint8_t)0x2
#define Set_MEAS5_PD2_SEL  			base |(uint8_t)0x3<<2 | Set_MEAS5_PD1_SEL

//PPG MEASUREMENT 6  CONFIGURATION
#define Set_MEAS6_AMB				(uint8_t)0x00
#define Set_MEAS6_DRVA              base |(uint8_t)0x00
#define Set_MEAS6_AVER				(uint8_t)0x0					  //for number of led pulses equal to 8
#define Set_MEAS6_PPG1_ADC_RGE		(uint8_t)0x2
#define Set_MEAS6_PPG2_ADC_RGE		base |(uint8_t)0x2<<4 |Set_MEAS3_PPG1_ADC_RGE
#define Set_MEAS6_PPG_TINT			base |(uint8_t)0x3<<3|Set_MEAS3_AVER
#define Set_MEAS6_FLTR2_SEL			base |(uint8_t)0x1<<6|Set_MEAS3_PPG_TINT
#define Set_MEAS6_LED_RGE			(uint8_t)0x3
#define Set_MEAS6_PD_SETLNG			base |(uint8_t)0x1<<6 |Set_MEAS3_LED_RGE
#define Set_MEAS6_LED_SETLNG		base |(uint8_t)0x1<<2 |Set_MEAS3_PD_SETLNG
#define Set_MEAS6_DRVA_PA			(uint8_t)0x00
#define Set_MEAS6_DRVB_PA  			(uint8_t)0x00
#define Set_MEAS6_PD1_SEL  			base |(uint8_t)0x2
#define Set_MEAS6_PD2_SEL  			base |(uint8_t)0x3<<2


//PPG THRESHOLD INTERRUPTS

#define Set_PPG_Threshold_HI1           0xff
#define Set_PPG_Threshold_LO1           0x00
#define Set_PPG_Threshold_HI2           0xff
#define Set_PPG_Threshold_LO2           0x0



/*
//User Register Map
#define Status1 					(uint8_t)0x00
#define Status2 					(uint8_t)0x01
#define Status3 					(uint8_t)0x02
#define Status4 					(uint8_t)0x03
#define Status5 					(uint8_t)0x04
*/





//
//char* read_reg(char reg_addr);
//
//void write_reg(char reg_addr,char write_val);
