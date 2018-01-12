/*
 * commandline.h
 *
 *  Created on: Jan 12, 2018
 *      Author: Nick Sterenberg
 */

#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_

#define COMMAND_BUFFER_LENGTH 64

typedef struct commandline_struct{
  uint8_t buffer[COMMAND_BUFFER_LENGTH];
} commandline;

commandline commandline_init(UART_HandleTypeDef *huart);




#endif /* COMMANDLINE_H_ */
