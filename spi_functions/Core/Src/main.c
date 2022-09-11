/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "INC_MAX86178.h"
#include "stdio.h"
#include "string.h"
/*
#include "86178_REG.h"
#include "cyprus.h"
*/
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi2;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI2_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */

	HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI2_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  /*unsigned char ppg_config[108]={

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
		  MEAS4_Configuration_5	,Set_MEAS4_PD2_SEL,

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
		  PPG_LO_THRESHOLD1	,Set_PPG_Threshold_LO1,
		  PPG_HI_THRESHOLD2 	,Set_PPG_Threshold_HI2,
		  PPG_LO_THRESHOLD2,Set_PPG_Threshold_LO2




  };*/
//  unsigned char x;
unsigned char *x;



//  10011110 10100100 10010100

//  11110000 00000000 00000000

x[2] x[3] x[4]

 temp=  x[2]>>4

base = 0x000000

temp2  = 00001111 & x[2]


  32 -> x[3]

  32 - > x[4]

32 - > temp2

            temp2    x[3]     x[4]
00000000 000000000 00000000 00000000

temp3 -> 32 = 000

temp2<<16
temp3 = temp3 | temp2


x[3]<<8
temp3 = temp3 | x[3]

temp3 = temp3 | x[4]


temp3 = -1*temp3 - > value











///


  	  x=ppg_init();

  	  for (int l =0 ;l<600;l++){

  	  }

  /*x=max_read_reg(0x02);
  int y=*(x+2);7*/

/*max_write_reg(0x20,0xab);
max_read_reg(0x20);*/





//  uint8_t ppg_arr[51]={
//
//
//
//
//
//
//
//  };

  /*unsigned char *buf_ppg_arr;

  unsigned char y[3];

  for(int i=0; i<108;i=i+2)
  {
	  write_reg(ppg_config[i],ppg_config[i+1]);

	  buf_ppg_arr=read_reg(ppg_config[i]);

	  y[0] = *buf_ppg_arr;
	  y[2] = *(buf_ppg_arr +2);
	  y[1] = *(buf_ppg_arr +1);

  }
*/


 /*uint8_t *buf;
  char y1[3];

  uint8_t add1=0x20;
  uint8_t val1=0x07;

	write_reg(add1,val1);
//	write_reg(add2,val2);


  buf=read_reg(add1);
  y1[0] = *buf;
  y1[2] = *(buf +2);
  y1[1] = *(buf +1);
*/
//  *buf2=read(add2);



	/*uint8_t tx1[3]={0xc9,0x00,0xab};
	uint8_t tx2[3]={0xc9,0x80,0xff};
	uint8_t rx[3];
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_SET);

	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, tx2, rx, 3, 1000);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_SET);


	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi2, tx1, 3, 1000);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_SET);


	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, tx2, rx, 3, 1000);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_SET);

*/




    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL2;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 7;
  hspi2.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi2.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC3 */
  GPIO_InitStruct.Pin = GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
