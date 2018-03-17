/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
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
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"

/* USER CODE BEGIN 0 */
extern SPI_HandleTypeDef hspi1;
/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim7;
extern TIM_HandleTypeDef htim10;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart3;

/******************************************************************************/
/*            Cortex-M4 Processor Interruption and Exception Handlers         */ 
/******************************************************************************/

/**
* @brief This function handles Non maskable interrupt.
*/
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
* @brief This function handles Hard fault interrupt.
*/
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
  }
  /* USER CODE BEGIN HardFault_IRQn 1 */

  /* USER CODE END HardFault_IRQn 1 */
}

/**
* @brief This function handles Memory management fault.
*/
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
  }
  /* USER CODE BEGIN MemoryManagement_IRQn 1 */

  /* USER CODE END MemoryManagement_IRQn 1 */
}

/**
* @brief This function handles Pre-fetch fault, memory access fault.
*/
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
  }
  /* USER CODE BEGIN BusFault_IRQn 1 */

  /* USER CODE END BusFault_IRQn 1 */
}

/**
* @brief This function handles Undefined instruction or illegal state.
*/
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
  }
  /* USER CODE BEGIN UsageFault_IRQn 1 */

  /* USER CODE END UsageFault_IRQn 1 */
}

/**
* @brief This function handles System service call via SWI instruction.
*/
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
* @brief This function handles Debug monitor.
*/
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
* @brief This function handles Pendable request for system service.
*/
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
* @brief This function handles System tick timer.
*/
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
* @brief This function handles EXTI line 1 interrupt.
*/
void EXTI1_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI1_IRQn 0 */

  /* USER CODE END EXTI1_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
  /* USER CODE BEGIN EXTI1_IRQn 1 */

  /* USER CODE END EXTI1_IRQn 1 */
}

/**
* @brief This function handles EXTI line 2 interrupt.
*/
void EXTI2_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI2_IRQn 0 */

  /* USER CODE END EXTI2_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
  /* USER CODE BEGIN EXTI2_IRQn 1 */

  /* USER CODE END EXTI2_IRQn 1 */
}

/**
* @brief This function handles EXTI line 3 interrupt.
*/
void EXTI3_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI3_IRQn 0 */

  /* USER CODE END EXTI3_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
  /* USER CODE BEGIN EXTI3_IRQn 1 */

  /* USER CODE END EXTI3_IRQn 1 */
}

/**
* @brief This function handles EXTI line[9:5] interrupts.
*/
void EXTI9_5_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI9_5_IRQn 0 */

  /* USER CODE END EXTI9_5_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_7);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);
  /* USER CODE BEGIN EXTI9_5_IRQn 1 */

  /* USER CODE END EXTI9_5_IRQn 1 */
}

/**
* @brief This function handles TIM1 update interrupt and TIM10 global interrupt.
*/
void TIM1_UP_TIM10_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_UP_TIM10_IRQn 0 */

  /* USER CODE END TIM1_UP_TIM10_IRQn 0 */
  HAL_TIM_IRQHandler(&htim10);
  /* USER CODE BEGIN TIM1_UP_TIM10_IRQn 1 */

  /* USER CODE END TIM1_UP_TIM10_IRQn 1 */
}

/**
* @brief This function handles USART1 global interrupt.
*/
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */

  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */

  /* USER CODE END USART1_IRQn 1 */
}

/**
* @brief This function handles USART3 global interrupt.
*/
void USART3_IRQHandler(void)
{
  /* USER CODE BEGIN USART3_IRQn 0 */

  /* USER CODE END USART3_IRQn 0 */
  HAL_UART_IRQHandler(&huart3);
  /* USER CODE BEGIN USART3_IRQn 1 */

  /* USER CODE END USART3_IRQn 1 */
}

/**
* @brief This function handles EXTI line[15:10] interrupts.
*/
void EXTI15_10_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI15_10_IRQn 0 */

  /* USER CODE END EXTI15_10_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_12);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_15);
  /* USER CODE BEGIN EXTI15_10_IRQn 1 */

  /* USER CODE END EXTI15_10_IRQn 1 */
}

/**
* @brief This function handles TIM6 global interrupt and DAC1, DAC2 underrun error interrupts.
*/
void TIM6_DAC_IRQHandler(void)
{
  /* USER CODE BEGIN TIM6_DAC_IRQn 0 */

  /* USER CODE END TIM6_DAC_IRQn 0 */
  HAL_TIM_IRQHandler(&htim6);
  /* USER CODE BEGIN TIM6_DAC_IRQn 1 */

  /* USER CODE END TIM6_DAC_IRQn 1 */
}

/**
* @brief This function handles TIM7 global interrupt.
*/
void TIM7_IRQHandler(void)
{
  /* USER CODE BEGIN TIM7_IRQn 0 */

  /* USER CODE END TIM7_IRQn 0 */
  HAL_TIM_IRQHandler(&htim7);
  /* USER CODE BEGIN TIM7_IRQn 1 */

  /* USER CODE END TIM7_IRQn 1 */
}

/* USER CODE BEGIN 1 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){

  uint8_t TX_Buff[30] = {0};
  uint8_t RX_Buff[30] = {0};
  if(GPIO_Pin == GPIO_PIN_1){
	  HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	  TX_Buff[0] = 0x97;
	  TX_Buff[1] = 0xFF;
	  TX_Buff[2] = 0xFF;
	  HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	  HAL_SPI_TransmitReceive(&hspi1, TX_Buff, RX_Buff, 3, 0xff);
	  HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);
  }
  if(GPIO_Pin == GPIO_PIN_2){
	  HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
	  //Get packet status (RSSI and SNR for LoRa)
	  TX_Buff[0] = 0x1D;
	  TX_Buff[1] = 0x00;
	  TX_Buff[2] = 0x00;
	  TX_Buff[3] = 0x00;
	  TX_Buff[4] = 0x00;
	  TX_Buff[5] = 0x00;
	  TX_Buff[6] = 0x00;
	  HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	  HAL_SPI_TransmitReceive(&hspi1, TX_Buff, RX_Buff, 7, 0xff);
	  HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);
	  HAL_Delay(1);

	  volatile float RSSI = -1*((int8_t)RX_Buff[2]/2.0); //Not sure if this calc is correct? RX_Buff needs cast to int8_t?
	  volatile float SNR = ((int8_t)RX_Buff[3])/4.0;

	  //Get RX Buffer Status
	  volatile uint8_t Offset = 0x80;
	  volatile uint8_t PayloadLen = 0x00;
	  TX_Buff[0] = 0x17;
	  TX_Buff[1] = 0x00;
	  TX_Buff[2] = 0x00;
	  TX_Buff[3] = 0x00;
	  HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	  HAL_SPI_TransmitReceive(&hspi1, TX_Buff, RX_Buff, 4, 0xff);
	  HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);
	  Offset = RX_Buff[3];
	  PayloadLen = RX_Buff[2];
	  HAL_Delay(1);

	  //Read buffer
	  TX_Buff[0] = 0x1B;
	  TX_Buff[1] = Offset;
	  TX_Buff[2] = 0x00;

	  TX_Buff[3] = 0x00;
	  TX_Buff[4] = 0x00;
	  TX_Buff[5] = 0x00;
	  TX_Buff[6] = 0x00;
	  TX_Buff[7] = 0x00;
	  TX_Buff[8] = 0x00;
	  TX_Buff[9] = 0x00;
	  TX_Buff[10] = 0x00;
	  TX_Buff[11] = 0x00;
	  TX_Buff[12] = 0x00;
	  TX_Buff[13] = 0x00;
	  TX_Buff[14] = 0x00;
	  TX_Buff[15] = 0x00;
	  TX_Buff[16] = 0x00;
	  TX_Buff[17] = 0x00;
	  TX_Buff[18] = 0x00;
	  TX_Buff[19] = 0x00;
	  TX_Buff[20] = 0x00;
	  TX_Buff[21] = 0x00;
	  TX_Buff[22] = 0x00;
	  TX_Buff[23] = 0x00;
	  TX_Buff[24] = 0x00;
	  HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	  HAL_SPI_TransmitReceive(&hspi1, TX_Buff, RX_Buff, 25, 0xff);
	  HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);
	  HAL_Delay(1);

	  //Clear IRQs
	  TX_Buff[0] = 0x97;
	  TX_Buff[1] = 0xFF;
	  TX_Buff[2] = 0xFF;
	  HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	  HAL_SPI_TransmitReceive(&hspi1, TX_Buff, RX_Buff, 3, 0xff);
	  HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);
	  HAL_Delay(1);

	  //Set into RX for next pkt
	  TXData[0] = 0x82;
	  TXData[1] = 0x00;
	  TXData[2] = 0x00;
	  TXData[3] = 0x00;
	  HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 3, 0xff);
	  HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);
  }


}
/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
