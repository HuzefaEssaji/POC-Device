/*
 * mlx90614.c
 *
 *  Created on: 29 mag 2019
 *      Author: Michele Gazzarri
 */

#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "stm32f3xx_hal.h"
#include "mlx90614.h"

extern I2C_HandleTypeDef hi2c1;
char temp_buff[128] = {};

static const uint8_t crc_table[] = {
    0x00, 0x07, 0x0e, 0x09, 0x1c, 0x1b, 0x12, 0x15, 0x38, 0x3f, 0x36, 0x31,
    0x24, 0x23, 0x2a, 0x2d, 0x70, 0x77, 0x7e, 0x79, 0x6c, 0x6b, 0x62, 0x65,
    0x48, 0x4f, 0x46, 0x41, 0x54, 0x53, 0x5a, 0x5d, 0xe0, 0xe7, 0xee, 0xe9,
    0xfc, 0xfb, 0xf2, 0xf5, 0xd8, 0xdf, 0xd6, 0xd1, 0xc4, 0xc3, 0xca, 0xcd,
    0x90, 0x97, 0x9e, 0x99, 0x8c, 0x8b, 0x82, 0x85, 0xa8, 0xaf, 0xa6, 0xa1,
    0xb4, 0xb3, 0xba, 0xbd, 0xc7, 0xc0, 0xc9, 0xce, 0xdb, 0xdc, 0xd5, 0xd2,
    0xff, 0xf8, 0xf1, 0xf6, 0xe3, 0xe4, 0xed, 0xea, 0xb7, 0xb0, 0xb9, 0xbe,
    0xab, 0xac, 0xa5, 0xa2, 0x8f, 0x88, 0x81, 0x86, 0x93, 0x94, 0x9d, 0x9a,
    0x27, 0x20, 0x29, 0x2e, 0x3b, 0x3c, 0x35, 0x32, 0x1f, 0x18, 0x11, 0x16,
    0x03, 0x04, 0x0d, 0x0a, 0x57, 0x50, 0x59, 0x5e, 0x4b, 0x4c, 0x45, 0x42,
    0x6f, 0x68, 0x61, 0x66, 0x73, 0x74, 0x7d, 0x7a, 0x89, 0x8e, 0x87, 0x80,
    0x95, 0x92, 0x9b, 0x9c, 0xb1, 0xb6, 0xbf, 0xb8, 0xad, 0xaa, 0xa3, 0xa4,
    0xf9, 0xfe, 0xf7, 0xf0, 0xe5, 0xe2, 0xeb, 0xec, 0xc1, 0xc6, 0xcf, 0xc8,
    0xdd, 0xda, 0xd3, 0xd4, 0x69, 0x6e, 0x67, 0x60, 0x75, 0x72, 0x7b, 0x7c,
    0x51, 0x56, 0x5f, 0x58, 0x4d, 0x4a, 0x43, 0x44, 0x19, 0x1e, 0x17, 0x10,
    0x05, 0x02, 0x0b, 0x0c, 0x21, 0x26, 0x2f, 0x28, 0x3d, 0x3a, 0x33, 0x34,
    0x4e, 0x49, 0x40, 0x47, 0x52, 0x55, 0x5c, 0x5b, 0x76, 0x71, 0x78, 0x7f,
    0x6a, 0x6d, 0x64, 0x63, 0x3e, 0x39, 0x30, 0x37, 0x22, 0x25, 0x2c, 0x2b,
    0x06, 0x01, 0x08, 0x0f, 0x1a, 0x1d, 0x14, 0x13, 0xae, 0xa9, 0xa0, 0xa7,
    0xb2, 0xb5, 0xbc, 0xbb, 0x96, 0x91, 0x98, 0x9f, 0x8a, 0x8d, 0x84, 0x83,
    0xde, 0xd9, 0xd0, 0xd7, 0xc2, 0xc5, 0xcc, 0xcb, 0xe6, 0xe1, 0xe8, 0xef,
    0xfa, 0xfd, 0xf4, 0xf3
};

uint8_t CRC8_Calc (uint8_t *p, uint8_t len) {
        uint16_t i;
        uint16_t crc = 0x0;

        while (len--) {
                i = (crc ^ *p++) & 0xFF;
                crc = (crc_table[i] ^ (crc << 8)) & 0xFF;
        }

        return crc & 0xFF;
}

void MLX90614_WriteReg(uint8_t devAddr, uint8_t regAddr, uint16_t data) {

	uint8_t i2cdata[4], temp[4];

	temp[0] = (devAddr << 1);
	temp[1] = regAddr;

	temp[2] = 0x00;
	temp[3] = 0x00;

	// For a write word command, in the crc8 calculus, you have to include [SA_W, Command, LSB, MSB]

	i2cdata[0] = temp[1]; //EEPROM-address
	i2cdata[1] = temp[2]; //Delete-Byte, low
	i2cdata[2] = temp[3]; //Delete-Byte, high
	i2cdata[3] = CRC8_Calc(temp, 4); //CRC8-checksum calculation: http://www.sunshine2k.de/coding/javascript/crc/crc_js.html

	HAL_I2C_Master_Transmit(&hi2c1, (devAddr << 1), i2cdata, 4, 0xFFFF);
	HAL_Delay(10);

	MLX90614_SendDebugMsg(MLX90614_DBG_MSG_W, devAddr, i2cdata[0], (i2cdata[1] <<8 | i2cdata[2]), i2cdata[3], 0x00);

	temp[2] = data & 0xFF; //Getting LSB first
	temp[3] = data >> 8;   //Getting MSB after

	i2cdata[0] = temp[1]; //EEPROM-address
	i2cdata[1] = temp[2]; //Delete-Byte, low
	i2cdata[2] = temp[3]; //Delete-Byte, high
	i2cdata[3] = CRC8_Calc(temp, 4); //CRC8-checksum calculation: http://www.sunshine2k.de/coding/javascript/crc/crc_js.html

	HAL_I2C_Master_Transmit(&hi2c1, (devAddr << 1), i2cdata, 4, 0xFFFF);
	HAL_Delay(10);
	MLX90614_SendDebugMsg(MLX90614_DBG_MSG_W, devAddr, i2cdata[0], data, i2cdata[3], 0x00);
}
uint16_t MLX90614_ReadReg(uint8_t devAddr, uint8_t regAddr, uint8_t dbg_lvl) {
	uint16_t data;
	uint8_t in_buff[3], crc_buff[5], crc;

	HAL_I2C_Mem_Read(&hi2c1, (devAddr<<1), regAddr, 1, in_buff, 3, 100);

	// For a read word command, in the crc8 calculus, you have to include [SA_W, Command, SA_R, LSB, MSB]
	crc_buff[0] = (devAddr<<1);
	crc_buff[1] = regAddr;
	crc_buff[2] = (devAddr<<1) + 1;
	crc_buff[3] = in_buff[0];
	crc_buff[4] = in_buff[1];
	crc = CRC8_Calc(crc_buff, 5);

	data = (in_buff[1] <<8 | in_buff[0]);

	//TODO: implement CRC8 check on data received
	/*if (crc != in_buff[2]) {
		data = 0x0000;
	}
	if(dbg_lvl == MLX90614_DBG_ON)	MLX90614_SendDebugMsg(MLX90614_DBG_MSG_R, devAddr, regAddr, data, in_buff[2], crc);
*/
	//HAL_Delay(1);
	return data;
}
float MLX90614_ReadTemp(uint8_t devAddr, uint8_t regAddr) {
	float temp;
	uint16_t data;

	data = MLX90614_ReadReg(devAddr, regAddr, MLX90614_DBG_OFF);
	temp = data*0.02 - 273.15;

	return temp;
}
/*
void MLX90614_ScanDevices (void) {
	HAL_StatusTypeDef result;
	for (int i = 0; i<128; i++)
		  {
			  result = HAL_I2C_IsDeviceReady(&hi2c1, (uint16_t) (i<<1), 2, 2);
			  if (result != HAL_OK)
			  {
				  sprintf(temp_buff, ".");
				  CDC_Transmit_FS(temp_buff, strlen((const char *)temp_buff));
			  }
			  if (result == HAL_OK)
			  {
				  sprintf(temp_buff, "0x%X", i);
				  CDC_Transmit_FS(temp_buff, strlen((const char *)temp_buff));

			  }
		  }
}
void MLX90614_SendDebugMsg(uint8_t op_type, uint8_t devAddr, uint8_t regAddr, uint16_t data, uint8_t crc_in, uint8_t crc_calc) {
	if(op_type == MLX90614_DBG_MSG_W) {
		snprintf(temp_buff, sizeof(temp_buff), "W Dev: 0x%02X, Reg: 0x%02X, Data: 0x%04X, CRC8_calc:0x%02X\r\n", devAddr, regAddr, data, crc_calc);
		CDC_Transmit_FS(temp_buff, strlen((const char *)temp_buff));
	}
	else if (op_type == MLX90614_DBG_MSG_R) {
		snprintf(temp_buff, sizeof(temp_buff), "R Dev: 0x%02X, Reg: 0x%02X, Data: 0x%04X, CRC8_in:0x%02X, CRC8_calc:0x%02X\r\n", devAddr, regAddr, data, crc_in, crc_calc);
		CDC_Transmit_FS(temp_buff, strlen((const char *)temp_buff));
	}

}
*/
