/*
 * flash.c
 *
 *  Created on: Jan 10, 2018
 *      Author: Nick Sterenberg
 */

#include "main.h"
#include "stm32f4xx_hal.h"
#include "flash.h"

extern SPI_HandleTypeDef hspi1;

// Loads a page into the flash page buffer (on the fash chip)
// TODO: test
uint16_t load_page(uint16_t page_number){

  uint8_t data[4];
  data[0] = FLASH_COMMAND_PAGE_READ;
  data[2] = (page_number & 0xF0) >> 8;
  data[3] = page_number & 0x0F;

  HAL_GPIO_WritePin(MEM_CS_GPIO_Port, MEM_CS_Pin, 0);
  HAL_SPI_Transmit(&hspi1, data, 4, 0xFF);
  HAL_GPIO_WritePin(MEM_CS_GPIO_Port, MEM_CS_Pin, 1);
}

// Sends a one-byte flash commad to the chip
// TODO: None
void flash_command(uint8_t command){
  HAL_GPIO_WritePin(MEM_CS_GPIO_Port, MEM_CS_Pin, 0);
  HAL_SPI_Transmit(&hspi1, &command, 1, 0xFF);
  HAL_GPIO_WritePin(MEM_CS_GPIO_Port, MEM_CS_Pin, 1);
}

// Checks the flash ID matches data sheet. A good check to see if the chip is alive
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
void unlock_all(){
  uint8_t data[3];
  data[0] = FLASH_COMMAND_WRITE_STATUS_REGISTER;
  data[1] = 0xA0;
  data[2] = 0b00000000;
  HAL_GPIO_WritePin(MEM_CS_GPIO_Port, MEM_CS_Pin, 0);
  HAL_SPI_Transmit(&hspi1, data, 3, 0xFF);
  HAL_GPIO_WritePin(MEM_CS_GPIO_Port, MEM_CS_Pin, 1);
}
void read_page(uint16_t page_number, uint8_t *page_buffer){
  load_page(page_number);

}

void read_buffer(uint16_t column, uint8_t *buffer, uint16_t size){

  uint8_t data[4];
  data[0] = FLASH_COMMAND_READ_DATA;
  data[1] = (column & 0xF0) >> 8;
  data[2] = column & 0x0F;

  HAL_GPIO_WritePin(MEM_CS_GPIO_Port, MEM_CS_Pin, 0);
  HAL_SPI_Transmit(&hspi1, data, 4, 0xff);

  HAL_SPI_Receive(&hspi1, buffer, size, 0xff);

  HAL_GPIO_WritePin(MEM_CS_GPIO_Port, MEM_CS_Pin, 1);

}

void erase_block(uint16_t block_number){

  uint8_t data[4];
  data[0] = FLASH_COMMAND_BLOCK_ERASE;
  data[2] = (block_number & 0xF0) >> 8;
  data[3] = block_number & 0x0F;

  HAL_GPIO_WritePin(MEM_CS_GPIO_Port, MEM_CS_Pin, 0);
  HAL_SPI_Transmit(&hspi1, data, 4, 0xFF);
  HAL_GPIO_WritePin(MEM_CS_GPIO_Port, MEM_CS_Pin, 1);

}

void write_buffer(uint16_t column, uint8_t *page_buffer, uint16_t size){



  uint8_t data[3];
  data[0] = FLASH_COMMAND_LOAD_DATA;
  data[1] = (column & 0xF0) >> 8;
  data[2] = column & 0x0F;

  HAL_GPIO_WritePin(MEM_CS_GPIO_Port, MEM_CS_Pin, 0);
  HAL_SPI_Transmit(&hspi1, data, 3, 0xff);

  HAL_SPI_Transmit(&hspi1, page_buffer, size, 0xff);

  HAL_GPIO_WritePin(MEM_CS_GPIO_Port, MEM_CS_Pin, 1);

}
uint8_t flash_read_status_register(uint8_t reg){
  uint8_t data[2];
  data[0] = FLASH_COMMAND_READ_STATUS_REGISTER;
  data[1] = reg;

  HAL_GPIO_WritePin(MEM_CS_GPIO_Port, MEM_CS_Pin, 0);
  HAL_SPI_Transmit(&hspi1, data, 2, 0xFF);
  HAL_SPI_Receive(&hspi1, data, 1, 0xFF);
  HAL_GPIO_WritePin(MEM_CS_GPIO_Port, MEM_CS_Pin, 1);

  return data[0];
}
void program_page(uint16_t page_number){


  uint8_t data[3];
  data[0] = FLASH_COMMAND_PROGRAM_EXECUTE;
  data[2] = (page_number & 0xF0) >> 8;
  data[3] = page_number & 0x0F;

  HAL_GPIO_WritePin(MEM_CS_GPIO_Port, MEM_CS_Pin, 0);
  HAL_SPI_Transmit(&hspi1, data, 4, 0xff);
  HAL_GPIO_WritePin(MEM_CS_GPIO_Port, MEM_CS_Pin, 1);


}

uint8_t flash_test(){


}


