/*
 * flash.h
 *
 *  Created on: Jan 10, 2018
 *      Author: Nick Sterenberg
 */

#ifndef FLASH_H_
#define FLASH_H_


uint8_t read_flash_id();   // Returns 0 if ok, 1 for error
void flash_reset();

void read_flash_status();

uint16_t load_page(uint16_t page_number);
uint8_t read_buffer(uint16_t column);

#endif /* FLASH_H_ */
