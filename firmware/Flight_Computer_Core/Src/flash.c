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

uint8_t LOG_OPEN = 0;

// eh

uint16_t two_one(uint8_t *arr){
  uint16_t out =  (*(arr) << 8) | *(arr+1);
  return out;
}
uint8_t *one_two(uint16_t in){
  static uint8_t out[2];
  out[0] = in >> 8;
  out[1] = in;
  return &out[0];
}
uint16_t packet_length(uint8_t packet_type){
  switch(packet_type){
    case PACKET_TYPE_MILLIS_TIMESTAMP:
      return PACKET_LENGTH_MILLIS_TIMESTAMP;
    case PACKET_TYPE_MICROS_TIMESTAMP:
      return PACKET_LENGTH_MICROS_TIMESTAMP;
    case PACKET_TYPE_GYRO:
      return PACKET_LENGTH_GYRO;
    case PACKET_TYPE_ACCEL:
      return PACKET_LENGTH_ACCEL;

  }
}


// eh

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

  while(flash_busy());      // wait for the page to load

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
  flash_command(FLASH_COMMAND_WRITE_ENABLE);
  uint8_t data[3];
  data[0] = FLASH_COMMAND_WRITE_STATUS_REGISTER;
  data[1] = 0xA0;
  data[2] = 0b00000000;
  HAL_GPIO_WritePin(MEM_CS_GPIO_Port, MEM_CS_Pin, 0);
  HAL_SPI_Transmit(&hspi1, data, 3, 0xFF);
  HAL_GPIO_WritePin(MEM_CS_GPIO_Port, MEM_CS_Pin, 1);
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
  data[0] = FLASH_COMMAND_LOAD_RANDOM_DATA;
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

  while(flash_busy());    // Wait for the page to finish programming


}
uint8_t flash_busy(){
  return flash_read_status_register(0xC0) & 0b00000001;
}
uint8_t flash_test(){


}
logfile *new_log(){

  LOG_OPEN = 1;

  logfile log;

  uint8_t index[2048];

  load_page(0);
  read_buffer(0, index, 2048);

  uint16_t num_files = two_one(&index[4]);
  uint16_t next_file_page = two_one(&index[6]);


  // Increment number of files
  num_files += 1;
  uint8_t *data_to_write = one_two(num_files);
  write_buffer(4, data_to_write, 2);
  program_page(0);

  log.start_page = next_file_page;
  log.current_page = log.start_page;
  load_page(log.current_page);
  log.bytes_free = 2048;
  log.file_number = num_files;

  return &log;
}
uint32_t log(logfile* log, uint8_t type, uint8_t *data){

  uint16_t length;
  if(type != PACKET_TYPE_STRING){
      length = packet_length(type);
  }
  else{
      length = strlen(data);
  }

  if(length > log->bytes_free){
      program_page(log->current_page);
      load_page(++log->current_page);
      log->bytes_free = 2048;
  }

  write_buffer(2048-log->bytes_free, data, length);
  log->bytes_free -= length;

}
uint32_t close_log(logfile *log){

}

void read_filesystem(filesystem* fs){
  load_page(0);
  read_buffer(0, (uint8_t *)fs, sizeof(*fs));
}
void write_filesystem(filesystem* fs){
  load_page(0);
  erase_block(0);

  write_buffer(0, (uint8_t *)fs, sizeof(*fs));

  program_page(0);

}
