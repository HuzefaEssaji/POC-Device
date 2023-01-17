/*
 * INC_X86178.c
 *
 *  Created on: Sep 7, 2022
 *      Author: essaj
 */

//#include "INC_MAX86178.h"

#include "stm32f3xx_hal.h"
 unsigned char tx[3];
 unsigned char rx[3];

extern SPI_HandleTypeDef hspi2;





unsigned char * read_reg( char  reg_addr)
 {


	 	 //read

	 	tx[0] = reg_addr;
	 	tx[1] = 0x80;
	 	tx[2] = 0xff;

	 	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_SET);
	 	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_RESET);
	 	HAL_SPI_TransmitReceive(&hspi2, tx, rx, (uint16_t)3, (uint32_t)1000);
	 	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_SET);

	 	return rx;
 }


void  write_reg(uint8_t reg_addr,uint8_t  write_val)
 {



	 	read_reg(reg_addr);  //dummy read

	 	//write
	 	tx[0] = reg_addr;
	 	tx[1] = 0x00;
	 	tx[2] = write_val;



	 	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_RESET);
	 	HAL_SPI_Transmit(&hspi2, tx, (uint16_t)3, (uint32_t)1000);
	 	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_SET);
	 	tx[2] = 0xff;

 }

