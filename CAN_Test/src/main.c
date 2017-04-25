/**
 ******************************************************************************
 * File Name          : main.c
 * Description        : Main program body
 ******************************************************************************
 *
 * COPYRIGHT(c) 2017 STMicroelectronics
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

// CAN Device ID
#define CAN_ID_11b 0x123
// Helpers
#define True 1
#define False 0

// CAN Periph handle
CAN_HandleTypeDef hcan;

// Set on valid packet
uint8_t replyflag = False;

// timer storage for LED blink
uint32_t timecounter = 0;

// timer length, set in CAN ISR by data packet
uint32_t ontime = 0;

// CAN periph bug, reinit cant be called from ISR, so do it from main loop
uint8_t CAN_ISR_CALLED = False;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void Error_Handler(void);
static void MX_GPIO_Init(void);
static void MX_CAN_Init(void);
static void MX_NVIC_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{

	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration----------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* Configure the system clock */
	SystemClock_Config();

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_CAN_Init();

	/* Initialize interrupts */
	MX_NVIC_Init();

	/* USER CODE BEGIN 2 */

	// Set up CAN Receiver in Interrupt mode.
	if(HAL_CAN_Receive_IT(&hcan, CAN_FIFO0) != HAL_OK)
	{
		Error_Handler();
	}

	// Set after valid msg, keeps unnessary off messages.
	uint8_t sendblock = 0;

	// timer storage for periodic static message (DEADBEEFFEED)
	uint32_t periodicpackettimer = 0;

	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1)
	{

		// Turn LED on
		if(replyflag)
		{

			// Housekeeping and GPIO
			replyflag = False;
			sendblock = True;
			timecounter = HAL_GetTick();
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, 0);

			// Set up CAN transmission
			uint8_t msg[] = "LED ON";
			hcan.pTxMsg->DLC = strlen(msg);
			strcpy(hcan.pTxMsg->Data, msg);
			HAL_CAN_Transmit(&hcan, 10);

		}

		// Turn LED off after time ontime
		else if(HAL_GetTick() - timecounter > ontime && sendblock)
		{
			sendblock = False;
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, 1);

			// Set up CAN transmission
			uint8_t msg[] = "LED OFF";
			hcan.pTxMsg->DLC = strlen(msg);
			strcpy(hcan.pTxMsg->Data, msg);
			HAL_CAN_Transmit(&hcan, 100);
		}

		// Periodic static message (debug purposes, heartbeat)
		if(HAL_GetTick() - periodicpackettimer > 5000)
		{
			periodicpackettimer = HAL_GetTick();
			uint8_t data[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
			hcan.pTxMsg->DLC = sizeof(data);
			strcpy(hcan.pTxMsg->Data, data);
			HAL_CAN_Transmit(&hcan, 100);

		}

		/* CAN Periph seems to be stubborn and wont work from its own ISR
		 * If it doesnt reinitialize, keep trying.
		 * It seems to be randomly busy so retry is needed to make sure new
		 * packets are received.
		 */
		if(CAN_ISR_CALLED)
		{
			// Reinitialize reception
			if(HAL_CAN_Receive_IT(&hcan, CAN_FIFO0) == HAL_OK)
			{
				CAN_ISR_CALLED = False;
			}
		}

		/* USER CODE END WHILE */
		/* USER CODE BEGIN 3 */

	}
	/* USER CODE END 3 */

}

/** System Clock Configuration
 */
void SystemClock_Config(void)
{

	RCC_OscInitTypeDef RCC_OscInitStruct;
	RCC_ClkInitTypeDef RCC_ClkInitStruct;

	/**Initializes the CPU, AHB and APB busses clocks
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
			|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
	{
		Error_Handler();
	}

	/**Configure the Systick interrupt time
	 */
	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

	/**Configure the Systick
	 */
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

	/* SysTick_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/** NVIC Configuration
 */
static void MX_NVIC_Init(void)
{
	/* USB_LP_CAN1_RX0_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(USB_LP_CAN1_RX0_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(USB_LP_CAN1_RX0_IRQn);
}

/* CAN init function */
static void MX_CAN_Init(void)
{
	CAN_FilterConfTypeDef sFilterConfig;
	// Why cube doesnt do this automatically I dont know...
	static CanTxMsgTypeDef TxMsg;
	static CanRxMsgTypeDef RxMsg;

	hcan.pTxMsg = &TxMsg;
	hcan.pRxMsg = &RxMsg;

	hcan.Instance = CAN1;
	hcan.Init.Prescaler = 12;
	hcan.Init.Mode = CAN_MODE_NORMAL;
	hcan.Init.SJW = CAN_SJW_1TQ;
	hcan.Init.BS1 = CAN_BS1_15TQ;
	hcan.Init.BS2 = CAN_BS2_8TQ;
	hcan.Init.TTCM = DISABLE;
	hcan.Init.ABOM = DISABLE;
	hcan.Init.AWUM = DISABLE;
	hcan.Init.NART = DISABLE;
	hcan.Init.RFLM = DISABLE;
	hcan.Init.TXFP = DISABLE;
	if (HAL_CAN_Init(&hcan) != HAL_OK)
	{
		Error_Handler();
	}

	/*##-2- Configure the CAN Filter ###########################################*/
	sFilterConfig.FilterNumber = 0;
	sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
	sFilterConfig.FilterIdHigh = 0x0000;
	sFilterConfig.FilterIdLow = 0x0000;
	sFilterConfig.FilterMaskIdHigh = 0x0000;
	sFilterConfig.FilterMaskIdLow = 0x0000;
	sFilterConfig.FilterFIFOAssignment = 0;
	sFilterConfig.FilterActivation = ENABLE;
	sFilterConfig.BankNumber = 14;

	if (HAL_CAN_ConfigFilter(&hcan, &sFilterConfig) != HAL_OK)
	{
		/* Filter configuration Error */
		Error_Handler();
	}

	// Configure static CAN TX Parameters
	hcan.pTxMsg->StdId = CAN_ID_11b;
	hcan.pTxMsg->ExtId = 0x00;
	hcan.pTxMsg->RTR = CAN_RTR_DATA;
	hcan.pTxMsg->IDE = CAN_ID_STD;


}

/** Configure pins as 
 * Analog
 * Input
 * Output
 * EVENT_OUT
 * EXTI
 */
static void MX_GPIO_Init(void)
{

	GPIO_InitTypeDef GPIO_InitStruct;

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin : LED1_Pin */
	GPIO_InitStruct.Pin = LED1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(LED1_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @param  None
 * @retval None
 */
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler */
	/* User can add his own implementation to report the HAL error return state */
	while(1)
	{
	}
	/* USER CODE END Error_Handler */
}


void HAL_CAN_RxCpltCallback(CAN_HandleTypeDef *hcan)
{
	// If we get an RTR packet, turn on the led and send back a response;
	if((hcan->pRxMsg->StdId == 0x125) && (hcan->pRxMsg->Data[0]==0xFE))
	{
		replyflag = 1;
		if(hcan->pRxMsg->DLC == 5)
		{
			ontime = hcan->pRxMsg->Data[1] << 24 | hcan->pRxMsg->Data[2] << 16 | hcan->pRxMsg->Data[3] << 8 | hcan->pRxMsg->Data[4];
		}
	}

	CAN_ISR_CALLED = True;
}

#ifdef USE_FULL_ASSERT

/**
 * @brief Reports the name of the source file and the source line number
 * where the assert_param error has occurred.
 * @param file: pointer to the source file name
 * @param line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */

}

#endif

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
