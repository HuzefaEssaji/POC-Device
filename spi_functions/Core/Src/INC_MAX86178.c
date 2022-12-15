/*
 * INC_X86178.c
 *
 *  Created on: Sep 7, 2022
 *      Author: essaj
 */

//#include "INC_MAX86178.h"

#include "stm32f3xx_hal.h"
#include "cyprus.h"
#include "86178_REG.h"
#include <stdlib.h>
/*
unsigned char tx[3];
unsigned char rx[3];
unsigned char burst_rx[6];
 */

unsigned char rec[8];
unsigned char rx_global[20];

extern UART_HandleTypeDef huart1;

//unsigned char sample[9000];

extern SPI_HandleTypeDef hspi2;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
unsigned char * max_read_reg( unsigned char  reg_addr,uint8_t count)
{
	unsigned char tx[count+2];
	unsigned char rx[count+2];

	//read

	tx[0] = reg_addr;
	tx[1] = 0x80;
	tx[2] = 0xff;

	for(int i=3;i<count+2;i++)
	{
		tx[i]=0xff;
	}

	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, tx, rx, (uint16_t)count+2, (uint32_t)1000);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_SET);


	for (int i = 0; i < count+2; i++)
	{
		rx_global[i] = rx[i];

	}
	return rx_global;

}
/*/////////////////////////////////////////////////////////////////////////////////////////////*/
void  max_write_reg(uint8_t reg_addr,uint8_t  write_val,uint8_t count)
{

	unsigned char tx[count+2];

	max_read_reg(reg_addr,count);  //dummy read

	//write
	tx[0] = reg_addr;
	tx[1] = 0x00;
	tx[2] = write_val;

	for(int i=3;i<count+2;i++)
	{
		tx[i]=0xff;
	}


	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi2, tx, (uint16_t)count+2, (uint32_t)1000);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_SET);
	tx[2] = 0xff;

	for(int i=3;i<count+2;i++)
	{
		tx[i]=0xff;
	}

}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

uint32_t shifter(uint32_t msb_sample,uint32_t mid_sample,uint32_t lsb_sample)
{

	uint32_t temp = 0;
	msb_sample =  0x0000000F & msb_sample ;
	msb_sample = msb_sample << 16;
	temp = temp | msb_sample;
	mid_sample = mid_sample<< 8;
	temp = temp | mid_sample;
	temp = temp | lsb_sample;

	return -1*temp;
}



/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

unsigned char * ppg_init()

{
	unsigned char ppg_config[122]=
	{

			Pin_Functional_Configuration,  Set_Pin_Functional_Configuration,
			PLL_Configuration_2,   Set_PLL_Config2,
			PLL_Configuration_4,Set_PLL_Config4,
			PLL_Configuration_5,Set_PLL_Config5,
			PLL_Configuration_6,Set_PLL_Config6,
			PPG_Configuration_1,Set_ppg_config1,

			PPG_Configuration_2,Set_ppg_config2,
			PPG_Configuration_3,Set_ppg_config3,
			PPG_Configuration_4,Set_ppg_config4,
			Photodiode_Bias, Set_photodiode_bias,
			FR_Clock_Divider_MSB,Set_FR_CLK_DIV,

			MEAS1_Selects,Set_MEAS1_DRVA,
			MEAS1_Configuration_1,Set_MEAS1_FLTR2_SEL,
			MEAS1_Configuration_2,Set_MEAS1_PPG2_ADC_RGE,
			MEAS1_Configuration_4,Set_MEAS1_LED_SETLNG,
			MEAS1_Configuration_5,Set_MEAS1_PD3_SEL,
			MEAS1_LEDA,Set_MEAS1_DRVA_PA,
			MEAS1_LEDB,Set_MEAS1_DRVB_PA,

			MEAS2_Selects,Set_MEAS2_DRVA,
			MEAS2_Configuration_1,Set_MEAS2_FLTR2_SEL,
			MEAS2_Configuration_2,Set_MEAS2_PPG2_ADC_RGE,
			MEAS2_Configuration_4,Set_MEAS2_LED_SETLNG,
			MEAS2_LEDA,Set_MEAS2_DRVA_PA,
			MEAS2_LEDB,Set_MEAS2_DRVB_PA,
			MEAS2_Configuration_5,Set_MEAS2_PD3_SEL,

			MEAS3_Selects,Set_MEAS3_DRVA,
			MEAS3_Configuration_1,Set_MEAS3_FLTR2_SEL,
			MEAS3_Configuration_2,Set_MEAS3_PPG2_ADC_RGE,
			MEAS3_Configuration_4,Set_MEAS3_LED_SETLNG,
			MEAS3_LEDA,Set_MEAS3_DRVA_PA,
			MEAS3_LEDB,Set_MEAS3_DRVB_PA,
			MEAS3_Configuration_5,Set_MEAS3_PD3_SEL,

			MEAS4_Selects,Set_MEAS4_AMB,
			MEAS4_Configuration_2,Set_MEAS4_PPG2_ADC_RGE,
			MEAS4_Configuration_1,Set_MEAS4_FLTR2_SEL,
			MEAS4_Configuration_5,Set_MEAS4_PD2_SEL,

			MEAS5_Selects,Set_MEAS5_DRVA,
			MEAS5_Configuration_1,Set_MEAS5_FLTR2_SEL,
			MEAS5_Configuration_2,Set_MEAS5_PPG2_ADC_RGE,
			MEAS5_Configuration_4,Set_MEAS5_LED_SETLNG,
			MEAS5_LEDA,Set_MEAS5_DRVA_PA,
			MEAS5_LEDB,Set_MEAS5_DRVB_PA,
			MEAS5_Configuration_5,Set_MEAS5_PD2_SEL,

			MEAS6_Selects,Set_MEAS6_DRVA,
			MEAS6_Configuration_1,Set_MEAS6_FLTR2_SEL,
			MEAS6_Configuration_2,Set_MEAS6_PPG2_ADC_RGE,
			MEAS6_Configuration_4,Set_MEAS6_LED_SETLNG,
			MEAS6_LEDA,Set_MEAS6_DRVA_PA,
			MEAS6_LEDB,Set_MEAS6_DRVB_PA,
			MEAS6_Configuration_5,Set_MEAS6_PD2_SEL,

			PPG_HI_THRESHOLD1 , Set_PPG_Threshold_HI1,
			PPG_LO_THRESHOLD1,Set_PPG_Threshold_LO1,
			PPG_HI_THRESHOLD2 ,Set_PPG_Threshold_HI2,
			PPG_LO_THRESHOLD2,Set_PPG_Threshold_LO2,
			0x0d,0xfa,
			0xc0,0x80,
			0x0e,0x18,
			0x11,0x00,
			0x18,0x01,
			0x20,0x07,
			0x0e,0x18,



	};

	for(int i=0; i<122;i=i+2)
	{
		max_write_reg(ppg_config[i],ppg_config[i+1],1);
	}

	unsigned char *temp;

	int k = 2;
	uint8_t * buf;

	uint32_t number = 0;

//	uint8_t *xy =&buf;

	unsigned char* sample = calloc(18, sizeof(char));

	/*for(int j=0;j<500;++j)
	{
*/
	while(1)
{
		while (1)
		{
			if(*(max_read_reg(0x0b,1)+2)==0x06){
				break;
			}


		}


		temp=max_read_reg(0x0c,18);

		while(k<20){

			*(sample+(k-2))= *(temp+k);
			k++;

		}


		k=2;

//		for(int h =0; h<18;h = h + 3){
//
//			number = shifter((uint32_t)*(sample+h),(uint32_t) *(sample+h+1),(uint32_t)*(sample+h+2));
////			buf = &number;
//			HAL_UART_Transmit(&huart1, (uint8_t *)number, sizeof(number), HAL_MAX_DELAY);
//		}

		HAL_UART_Transmit(&huart1, sample, 18, 100);
		HAL_Delay(10);

	}

	//return sample;

}
