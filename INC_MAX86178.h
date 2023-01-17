/*
 * max86178.h
 *
 *  Created on: 28-Aug-2022
 *      Author: cmkum
 */

#ifndef INC_MAX86178_H_
#define INC_MAX86178_H_



#endif /* INC_MAX86178_H_ */

 //C standard Libraries
#define Set_REF_CLK_SEL             (unit8_t)0<<6                    //0-internal oscillator and 1-external oscillator
#define Set_CLK_FREQ_SEL			(unit8_t)0<<5 | Set_REF_CLK_SEL  //0-32khz and 1-32.768khz

#define Set_FR_CLK_DIV              0x0100                           //default
//PPG Configuration
#define Set_PPG1_PWRDN              (unit8_t)0x00
#define Set_PPG2_PWRDN				(unit8_t)0x00
#define Set_MEAS1_EN				(unit8_t)0x01
#define Set_MEAS2_EN				(unit8_t)0x01
#define Set_MEAS3_EN				(unit8_t)0x01
#define Set_MEAS4_EN				(unit8_t)0x01

//MEASUREMENT 1 CONFIGURATION
#define Set_MEAS1_AMB				(unit8_t)0x00
#define Set_MEAS1_DRVA   			(unit8_t)0x00
#define Set_MEAS1_AVER				(unit8_t)0x03                     //for number of led pulses equal to 8
#define Set_MEAS1_PPG1_ADC_RGE		(unit8_t)0x2
#define Set_MEAS1_PPG2_ADC_RGE		(unit8_t)0x2<<4 |Set_MEAS1_PPG1_ADC_RGE   //default
#define Set_MEAS1_PPG_TINT			(unit8_t)0x3
#define Set_MEAS1_LED_RGE			(unit8_t)0x3
#define Set_MEAS1_PD_SETLNG			(unit8_t)0x1<<6 |Set_MEAS1_LED_RGE
#define Set_MEAS1_LED_SETLNG		(unit8_t)0x1<<1 |MEAS1_PD_SETLNG
#define Set_MEAS1_DRVA_PA			(unit8_t)0x02
#define Set_MEAS1_DRVB_PA  			(unit8_t)0x00
#define Set_MEAS1_PD1_SEL  			(unit8_t)0x2
#define Set_MEAS1_PD3_SEL  			(unit8_t)0x3

//MEASUREMENT 2  CONFIGURATION
#define Set_MEAS2_AMB				(unit8_t)0x00
#define Set_MEAS2_DRVA   			(unit8_t)0x1
#define Set_MEAS2_AVER				(unit8_t)0x3
#define Set_MEAS2_PPG1_ADC_RGE		(unit8_t)0x2
#define Set_MEAS2_PPG2_ADC_RGE		(unit8_t)0x2<<4 |Set_MEAS1_PPG1_ADC_RGE
#define Set_MEAS2_PPG_TINT			(unit8_t)0x3
#define Set_MEAS2_LED_RGE			(unit8_t)0x3
#define Set_MEAS2_PD_SETLNG			(unit8_t)0x1<<6 |Set_MEAS1_LED_RGE
#define Set_MEAS2_LED_SETLNG		(unit8_t)0x1<<6 |Set_MEAS1_LED_RGE
#define Set_MEAS2_DRVA_PA			(unit8_t)0x02
#define Set_MEAS2_DRVB_PA  			(unit8_t)0x00
#define Set_MEAS2_PD2_SEL  			(unit8_t)0x0

//MEASUREMENT 3  CONFIGURATION
#define Set_MEAS3_AMB
#define Set_MEAS3_DRVB   0x2
#define Set_MEAS3_AVER
#define Set_MEAS3_PPG1_ADC_RGE
#define Set_MEAS3_PPG2_ADC_RGE
#define Set_MEAS3_PPG_TINT
#define Set_MEAS3_LED_RGE
#define Set_MEAS3_PD_SETLNG
#define Set_MEAS3_LED_SETLNG
#define Set_MEAS3_DRVA_PA
#define Set_MEAS3_DRVB_PA  0x00
#define Set_MEAS3_PD2_SEL  0x2

//MEASUREMENT 4  CONFIGURATION
#define Set_MEAS4_AMB
#define Set_MEAS4_PPG1_ADC_RGE
#define Set_MEAS4_PPG2_ADC_RGE
#define Set_MEAS4_PPG_TINT
#define Set_MEAS4_PD1_SEL  0x2
#define Set_MEAS4_PD3_SEL  0x3


//User Register Map
#define Status1 				(unit8_t)0x00
#define Status2 				(unit8_t)0x01
#define Status3 				(unit8_t)0x02
#define Status4 				(unit8_t)0x03
#define Status5 				(unit8_t)0x04