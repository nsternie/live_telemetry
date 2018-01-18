/*
 * commandline.h
 *
 *  Created on: Jan 12, 2018
 *      Author: Nick Sterenberg
 */

#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_

#include "stm32f4xx_hal.h"

#define COMMANDLINE_MAX_ARGS  16
#define END_OF_PACKET         0xff

// COMMAND DEFINITIONS
#define COMMAND_LIST_FILES        0
#define COMMAND_TRANSMIT_FILE_BIN 1
#define COMMAND_TRANSMIT_FILE_ASCII 2


#define MAX_COMMAND_ARGS  7
#define MAX_COMMAND_LENGTH  32
#define COMMAND_HISTORY 5

#define UART_BUFFER_SIZE  1024
#define COMMAND_BUFFER_LENGTH 64
#define COMMAND_SOURCE 1

uint8_t command_buffer[COMMAND_HISTORY][COMMAND_BUFFER_LENGTH];
uint8_t command_index;


typedef struct bufferstruct{
  uint8_t *start;
  uint8_t *end;
  uint16_t length;
  uint16_t filled;
  uint8_t *head;
  uint8_t *tail;
  uint8_t id;
  uint8_t new_data;
  uint8_t data[UART_BUFFER_SIZE];
} buffer;


void buffer_init(buffer *b, size_t size, uint8_t id);
void buffer_read(buffer *b, uint8_t* dst, size_t size);
void buffer_write(buffer *b, uint8_t* src, size_t size);
void parse_buffer(buffer *b);
uint32_t  serial_command(uint8_t* cbuf_in);


#endif /* COMMANDLINE_H_ */
