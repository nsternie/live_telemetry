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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
  /* Includes ------------------------------------------------------------------*/

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define PYRO_B_FIRE_Pin GPIO_PIN_0
#define PYRO_B_FIRE_GPIO_Port GPIOH
#define PYRO_A_FIRE_Pin GPIO_PIN_1
#define PYRO_A_FIRE_GPIO_Port GPIOH
#define PYRO_A_SENSE_Pin GPIO_PIN_0
#define PYRO_A_SENSE_GPIO_Port GPIOC
#define PYRO_B_SENSE_Pin GPIO_PIN_1
#define PYRO_B_SENSE_GPIO_Port GPIOC
#define PYRO_C_SENSE_Pin GPIO_PIN_2
#define PYRO_C_SENSE_GPIO_Port GPIOC
#define PYRO_D_SENSE_Pin GPIO_PIN_3
#define PYRO_D_SENSE_GPIO_Port GPIOC
#define PYRO_C_FIRE_Pin GPIO_PIN_0
#define PYRO_C_FIRE_GPIO_Port GPIOA
#define PYRO_D_FIRE_Pin GPIO_PIN_1
#define PYRO_D_FIRE_GPIO_Port GPIOA
#define INT1_ADXL_Pin GPIO_PIN_0
#define INT1_ADXL_GPIO_Port GPIOB
#define DRDY_ADXL_Pin GPIO_PIN_1
#define DRDY_ADXL_GPIO_Port GPIOB
#define CS_ADXL_Pin GPIO_PIN_2
#define CS_ADXL_GPIO_Port GPIOB
#define CS_MS5607_Pin GPIO_PIN_8
#define CS_MS5607_GPIO_Port GPIOC
#define GYRO5_INT_Pin GPIO_PIN_9
#define GYRO5_INT_GPIO_Port GPIOC
#define GYRO3_INT_Pin GPIO_PIN_8
#define GYRO3_INT_GPIO_Port GPIOA
#define CS_GYRO2_Pin GPIO_PIN_11
#define CS_GYRO2_GPIO_Port GPIOA
#define GYRO2_INT_Pin GPIO_PIN_12
#define GYRO2_INT_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define CS_GYRO4_Pin GPIO_PIN_15
#define CS_GYRO4_GPIO_Port GPIOA
#define GYRO4_INT_Pin GPIO_PIN_10
#define GYRO4_INT_GPIO_Port GPIOC
#define CS_GYRO1_Pin GPIO_PIN_11
#define CS_GYRO1_GPIO_Port GPIOC
#define GYRO6_INT_Pin GPIO_PIN_2
#define GYRO6_INT_GPIO_Port GPIOD
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define GYRO1_INT_Pin GPIO_PIN_4
#define GYRO1_INT_GPIO_Port GPIOB
#define CS_GYRO6_Pin GPIO_PIN_5
#define CS_GYRO6_GPIO_Port GPIOB
#define CS_GYRO3_Pin GPIO_PIN_6
#define CS_GYRO3_GPIO_Port GPIOB
#define CS_GYRO5_Pin GPIO_PIN_7
#define CS_GYRO5_GPIO_Port GPIOB

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
