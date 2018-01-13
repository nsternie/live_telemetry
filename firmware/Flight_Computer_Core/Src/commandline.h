/*
 * commandline.h
 *
 *  Created on: Jan 12, 2018
 *      Author: Nick Sterenberg
 */

#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_

#include "stm32f4xx_hal.h"

#define COMMANDLINE_MAX_ARGS 16

// COMMAND DEFINITIONS
#define COMMAND_LIST_FILES    0
#define COMMAND_TRANSMIT_FILE 1

typedef struct commandline_struct{
  volatile uint8_t char_in;
  uint8_t command;
  uint8_t argv[COMMANDLINE_MAX_ARGS];
  UART_HandleTypeDef *port;
} commandline;

commandline commandline_init(UART_HandleTypeDef *huart);




#endif /* COMMANDLINE_H_ */
