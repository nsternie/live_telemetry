/**
  ******************************************************************************
  * File Name          : main.hpp
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
  /* Includes ------------------------------------------------------------------*/

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define GYRO2_INT_Pin GPIO_PIN_13
#define GYRO2_INT_GPIO_Port GPIOC
#define GYRO2_INT_EXTI_IRQn EXTI15_10_IRQn
#define MEM_CS_Pin GPIO_PIN_14
#define MEM_CS_GPIO_Port GPIOC
#define PYRO_2_SENSE_Pin GPIO_PIN_1
#define PYRO_2_SENSE_GPIO_Port GPIOC
#define PYRO_2_FIRE_Pin GPIO_PIN_3
#define PYRO_2_FIRE_GPIO_Port GPIOC
#define PYRO_1_FIRE_Pin GPIO_PIN_1
#define PYRO_1_FIRE_GPIO_Port GPIOA
#define PYRO_1_SENSE_Pin GPIO_PIN_2
#define PYRO_1_SENSE_GPIO_Port GPIOA
#define MS5607_CS_Pin GPIO_PIN_2
#define MS5607_CS_GPIO_Port GPIOB
#define GYRO5_CS_Pin GPIO_PIN_6
#define GYRO5_CS_GPIO_Port GPIOC
#define GYRO4_CS_Pin GPIO_PIN_7
#define GYRO4_CS_GPIO_Port GPIOC
#define ADXL_CS_Pin GPIO_PIN_8
#define ADXL_CS_GPIO_Port GPIOC
#define GYRO4_INT_Pin GPIO_PIN_9
#define GYRO4_INT_GPIO_Port GPIOC
#define GYRO4_INT_EXTI_IRQn EXTI9_5_IRQn
#define GYRO1_INT_Pin GPIO_PIN_8
#define GYRO1_INT_GPIO_Port GPIOA
#define GYRO1_INT_EXTI_IRQn EXTI9_5_IRQn
#define GYRO1_CS_Pin GPIO_PIN_11
#define GYRO1_CS_GPIO_Port GPIOA
#define GYRO5_INT_Pin GPIO_PIN_12
#define GYRO5_INT_GPIO_Port GPIOA
#define GYRO5_INT_EXTI_IRQn EXTI15_10_IRQn
#define ADXL_DRDY_Pin GPIO_PIN_15
#define ADXL_DRDY_GPIO_Port GPIOA
#define ADXL_DRDY_EXTI_IRQn EXTI15_10_IRQn
#define nIRQ_RADIO_Pin GPIO_PIN_10
#define nIRQ_RADIO_GPIO_Port GPIOC
#define nIRQ_RADIO_EXTI_IRQn EXTI15_10_IRQn
#define RADIO_CS_Pin GPIO_PIN_11
#define RADIO_CS_GPIO_Port GPIOC
#define GPS_nRST_Pin GPIO_PIN_12
#define GPS_nRST_GPIO_Port GPIOC
#define GYRO6_CS_Pin GPIO_PIN_2
#define GYRO6_CS_GPIO_Port GPIOD
#define GYRO3_CS_Pin GPIO_PIN_4
#define GYRO3_CS_GPIO_Port GPIOB
#define GYRO6_INT_Pin GPIO_PIN_5
#define GYRO6_INT_GPIO_Port GPIOB
#define GYRO6_INT_EXTI_IRQn EXTI9_5_IRQn
#define GYRO2_CS_Pin GPIO_PIN_6
#define GYRO2_CS_GPIO_Port GPIOB
#define GYRO3_INT_Pin GPIO_PIN_7
#define GYRO3_INT_GPIO_Port GPIOB
#define GYRO3_INT_EXTI_IRQn EXTI9_5_IRQn

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
