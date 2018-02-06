/*
 * flash.h
 *
 *  Created on: Jan 10, 2018
 *      Author: Nick Sterenberg
 */

#ifndef FLASH_H_
#define FLASH_H_

#include "sensors.h"

#define FLASH_COMMAND_RESET         0xff
#define FLASH_COMMAND_WRITE_ENABLE  0x06
#define FLASH_COMMAND_WRITE_DISABLE 0x04
#define FLASH_COMMAND_PAGE_READ     0x13
#define FLASH_COMMAND_READ_DATA     0x03
#define FLASH_COMMAND_BLOCK_ERASE   0xd8
#define FLASH_COMMAND_LOAD_DATA     0x02
#define FLASH_COMMAND_LOAD_RANDOM_DATA  0x84
#define FLASH_COMMAND_PROGRAM_EXECUTE   0x10
#define FLASH_COMMAND_WRITE_STATUS_REGISTER 0x1f
#define FLASH_COMMAND_READ_STATUS_REGISTER  0x0f


#define PACKET_TYPE_STRING            2
#define PACKET_TYPE_GYRO              3
#define PACKET_TYPE_ACCEL             4
#define PACKET_TYPE_BARO              5
#define PACKET_TYPE_MILLIS            6
#define PACKET_TYPE_GPS               7
#define PACKET_TYPE_EOP               255

#define PACKET_LENGTH_MILLIS            4
#define PACKET_LENGTH_MICROS            4
#define PACKET_LENGTH_GYRO              7
#define PACKET_LENGTH_ACCEL             9
#define PACKET_LENGTH_BARO              4
#define PACKET_LENGTH_GPS               25


typedef struct filestruct{
  uint16_t start_page;
  uint16_t stop_page;
  uint16_t current_page;
  uint16_t bytes_free;
  uint16_t file_number;
} file;

#define MAX_FILES 16
typedef struct filesystemstruct{
  uint32_t num_files;
  int32_t current_file;
  uint16_t next_file_page;
  file files[MAX_FILES];
} filesystem;

void print_file(FILE* binfile);


#endif /* FLASH_H_ */
