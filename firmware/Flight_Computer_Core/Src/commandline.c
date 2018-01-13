/*
 * commandline.c
 *
 *  Created on: Jan 12, 2018
 *      Author: Nick Sterenberg
 */

#include "commandline.h"

commandline commandline_init(UART_HandleTypeDef *huart){

  commandline c;

  c.port = huart;

  HAL_UART_Receive_IT(c.port, 1, &c.char_in);


}



