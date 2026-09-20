/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
ADC_HandleTypeDef hadc1;

/* USER CODE BEGIN PV */
uint16_t adc_value = 0;
uint16_t senhaGravada[3] = {9, 6, 5};
uint16_t senhaDigitada[3] = {0};
uint8_t contador = 0;
uint8_t digito = 0;
uint8_t botao_anterior = 1;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
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
  MX_ADC1_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  HAL_GPIO_WritePin(PLACA_GPIO_Port, PLACA_Pin, GPIO_PIN_SET);
      HAL_ADC_Start(&hadc1);
      if (HAL_ADC_PollForConversion(&hadc1, 100) == HAL_OK)
      {
          adc_value = HAL_ADC_GetValue(&hadc1);
      }
      HAL_ADC_Stop(&hadc1);
      // digito 0
      if (adc_value <= 408 ){
    	  HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_RESET);
    	  HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_RESET);
    	  HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_RESET);
    	  HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_RESET);
    	  digito = 0;
      }
      // digito 1
      if (adc_value>= 409 && adc_value <= 817 ){
    	  HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_SET);
    	  HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_RESET);
    	  HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_RESET);
    	  HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_RESET);
    	  digito = 1;
      }
      // digito 2
      if (adc_value>= 818 && adc_value <= 1226 ){
    	  HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_RESET);
    	  HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_SET);
    	  HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_RESET);
    	  HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_RESET);
    	  digito = 2;
      }
      // digito 3
      if (adc_value>= 1227 && adc_value <= 1635 ){
    	  HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_SET);
    	  HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_SET);
    	  HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_RESET);
    	  HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_RESET);
    	  digito = 3;
      }
      // digito 4
      if (adc_value>= 1636 && adc_value <= 2044 ){
    	  HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_RESET);
    	  HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_RESET);
    	  HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_SET);
    	  HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_RESET);
    	  digito = 4;
      }
      // digito 5
      if (adc_value>= 2045 && adc_value <= 2453 ){
    	  HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_SET);
    	  HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_RESET);
    	  HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_SET);
    	  HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_RESET);
    	  digito = 5;
      }
      // digito 6
      if (adc_value>= 2454 && adc_value <= 2862 ){
    	  HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_RESET);
    	  HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_SET);
    	  HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_SET);
    	  HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_RESET);
    	  digito = 6;
      }
      // digito 7
      if (adc_value>= 2863 && adc_value <= 3271 ){
    	  HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_SET);
    	  HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_SET);
    	  HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_SET);
    	  HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_RESET);
    	  digito = 7;
      }
      // digito 8
      if (adc_value>= 3272 && adc_value <= 3680 ){
    	  HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_RESET);
    	  HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_RESET);
    	  HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_RESET);
    	  HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_SET);
    	  digito = 8;
      }
      // digito 9
      if (adc_value>= 3681){
    	  HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_SET);
    	  HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_RESET);
    	  HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_RESET);
    	  HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_SET);
    	  digito = 9;
      }
      uint8_t botao_atual = HAL_GPIO_ReadPin(BOTAO_GPIO_Port, BOTAO_Pin);

       if (botao_anterior == GPIO_PIN_SET && botao_atual == GPIO_PIN_RESET)
       {
           HAL_Delay(30);  // debounce

           if (HAL_GPIO_ReadPin(BOTAO_GPIO_Port, BOTAO_Pin) == GPIO_PIN_RESET)
           {
;
        	   if (contador < 3) {
        		   HAL_GPIO_WritePin(PLACA_GPIO_Port, PLACA_Pin, GPIO_PIN_RESET);
        		   senhaDigitada[contador] = digito;
        		   contador++;
        	   }
        		  if (contador == 3)

        		      {
        		          if (senhaDigitada[0] == senhaGravada[0] &&
        		              senhaDigitada[1] == senhaGravada[1] &&
        		              senhaDigitada[2] == senhaGravada[2])
        		          {
        		        	  for (int i = 0; i < 3; i++)
        		        	  {
        	    	              HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_SET);
        	    	              HAL_Delay(500);
        	    	              HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_RESET);
        	    	              HAL_Delay(500);
        		        	  }

        		          }
        		          else
        		          {
        		        	  for (int i = 0; i < 3; i++)
        		        	  {
        	    	              HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_SET);
        	    	              HAL_Delay(500);
        	    	              HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_RESET);
        	    	              HAL_Delay(500);
        		        	  }
        		          }

        		      contador = 0;
        		      }
           }
       }
       botao_anterior = botao_atual;
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
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
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(PLACA_GPIO_Port, PLACA_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, L4_Pin|L3_Pin|L2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PLACA_Pin */
  GPIO_InitStruct.Pin = PLACA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(PLACA_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : L4_Pin L3_Pin L2_Pin */
  GPIO_InitStruct.Pin = L4_Pin|L3_Pin|L2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : L1_Pin */
  GPIO_InitStruct.Pin = L1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(L1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : BOTAO_Pin */
  GPIO_InitStruct.Pin = BOTAO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(BOTAO_GPIO_Port, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
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
#ifdef USE_FULL_ASSERT
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
