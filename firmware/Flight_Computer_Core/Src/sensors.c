/*
 * sensors.c
 *
 *  Created on: Jan 12, 2018
 *      Author: Nick Sterenberg
 *
 */

#include "main.h"
#include "stm32f4xx_hal.h"
#include "sensors.h"

extern SPI_HandleTypeDef hspi2;

void read_gyro(gyro *g){

  GPIO_TypeDef *port;
  uint16_t pin;

  switch(g->id){
    case 1:
      port = GYRO1_CS_GPIO_Port;
      pin = GYRO1_CS_Pin;
      break;
    case 2:
      port = GYRO2_CS_GPIO_Port;
      pin = GYRO2_CS_Pin;
      break;
    case 3:
      port = GYRO3_CS_GPIO_Port;
      pin = GYRO3_CS_Pin;
      break;
    case 4:
      port = GYRO4_CS_GPIO_Port;
      pin = GYRO4_CS_Pin;
      break;
    case 5:
      port = GYRO5_CS_GPIO_Port;
      pin = GYRO5_CS_Pin;
      break;
    case 6:
      port = GYRO6_CS_GPIO_Port;
      pin = GYRO6_CS_Pin;
      break;

  }

  uint8_t data[6];
  data[0] = 0x12 | 0b10000000;

  HAL_GPIO_WritePin(port, pin, 0);          // Select device
  HAL_SPI_Transmit(&hspi2, data, 1, 0xff);  // Send address of high byte of z axis
  HAL_SPI_Receive(&hspi2, data, 6, 0xff);   // read z to x
  HAL_GPIO_WritePin(port, pin, 1);          // Release device

  g->data[0] = (data[0] << 8) | data[1];
  g->data[1] = (data[2] << 8) | data[3];
  g->data[2] = (data[4] << 8) | data[5];

}


