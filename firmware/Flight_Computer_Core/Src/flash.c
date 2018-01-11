/*
 * flash.c
 *
 *  Created on: Jan 10, 2018
 *      Author: Nick Sterenberg
 */

#include "main.h"
#include "stm32f4xx_hal.h"


extern SPI_HandleTypeDef hspi1;

int read_flash_id(){


  HAL_GPIO_WritePin(MEM_CS_GPIO_Port, MEM_CS_Pin, 0);
  uint8_t data[8];
  data[0] = 0x9F;
  HAL_SPI_Transmit(&hspi1, data, 1, 0xFF);
  HAL_SPI_Receive(&hspi1, data, 4, 0xFF);
  HAL_GPIO_WritePin(MEM_CS_GPIO_Port, MEM_CS_Pin, 1);

  if(data[1] == 0xef && data[2] == 0xaa && data[3] == 0x21){
      return 0;
  }
  else{
      return 1;
  }

}
void flash_reset(){

}

