/*
 * flash.h
 *
 *  Created on: Jan 10, 2018
 *      Author: Nick Sterenberg
 */

#ifndef FLASH_H_
#define FLASH_H_

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


typedef struct logfilestruct{
  uint16_t start_page;
  uint16_t stop_page;
  uint16_t current_page;
  uint16_t bytes_free;
} logfile;


int read_flash_id();   // Returns 0 if ok, 1 for error
void flash_command(uint8_t command);

void unlock_all();

void read_flash_status();


uint16_t load_page(uint16_t page_number);
void read_buffer(uint16_t column, uint8_t *buffer, uint16_t size);
void write_buffer(uint16_t column, uint8_t *page_buffer, uint16_t size);
void program_page(uint16_t page_number);

void erase_block(uint16_t block_number);
uint8_t flash_read_status_register(uint8_t reg);

uint8_t flash_test();   // This WILL corrupt any data on the disk

// TODO: Functions
logfile new_log();  // return log stuct
// log(log_stuct, type, data)
// close_log()
uint8_t flash_busy(); // check the busy bit
#endif /* FLASH_H_ */
