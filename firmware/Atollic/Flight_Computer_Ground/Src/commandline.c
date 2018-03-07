/*
 * commandline.c
 *
 *  Created on: Jan 12, 2018
 *      Author: Nick Sterenberg
 */

#include "commandline.h"
#include "flash.h"

extern UART_HandleTypeDef huart1;
extern uint8_t tx_pkt_cmd;
extern uint8_t radio_cmd;

void buffer_init(buffer *b, size_t size, uint8_t id){
  b->start = &(b->data);
  b->end = (b->start)+size;
  b->head = b->start;
  b->tail = b->start;
  b->length = b->end - b->start;
  b->filled = 0;
  b->id = id;
  b->new_data = 0;

  for(uint16_t n = 0; n < b->length; n++){
    b->data[n] = 0;
  }
}
void buffer_read(buffer *b, uint8_t* dst, size_t size){
  assert(size<=b->filled);
  for(uint16_t n = 0; n < size; n++){
    *(dst++) = *(b->tail++);
    if(b->tail > b-> end){
      b->tail = b->start;
    }
    b->filled--;
  }
}
void buffer_write(buffer *b, uint8_t* src, size_t size){
  for(uint16_t n = 0; n < size; n++){ // How even many bytes there are to write (Usually just 1)
    *(b->head++) = *(src++);          // Write a byte
    if(b->head > b->end){            // Wrap around if we went past max address
      b->head = b->start;             // Set the head to the start
    }
    if(b->head==b->tail){             // Head has hit the tail
      b->tail++;                      // Inc tail
      if(b->tail > b->end){           // Did the tail hit the max addr
        b->tail = b->start;           // Yep, send it to the start
      }
    }
    else{
      b->filled++;        // No hits, just incr filled
    }
  }
  b->new_data++;          // We now need to run parse_buffer at some point
}
void parse_buffer(buffer *b){

  for(uint8_t* data_ptr = (b->head)-(b->new_data); data_ptr < b->head; data_ptr++){

    if(b->id == COMMAND_SOURCE){                  // Is this the command source
      for(uint8_t n = 0; n < COMMAND_BUFFER_LENGTH; n ++){    // Copy the buffer into the command buffer then
        command_buffer[command_index][n] = b->data[n]; //
      }

      if(*(data_ptr) == '\r'){                      // Got a return char, run the command and clear the command buffer
        if(command_index < COMMAND_HISTORY-1){          // Register the command
          command_index++;
          serial_command(command_buffer[command_index-1]);  // Copy into command history buffers
        }
        else{                         // Command history full, shift all the buffers
          serial_command(command_buffer[command_index]);
          // Shift all the lines up 1, (new command line)
          for(uint8_t n = 0; n < COMMAND_HISTORY-1; n++){
            strcpy(command_buffer[n], command_buffer[n+1]);
          }
        }
        // Clear the new line of the command buffer
        for(uint8_t n = 0; n < 64; n ++){
          command_buffer[command_index][n] = 0;
        }
        // Clear the serial buffer on the commanding channel
        buffer_init(b, UART_BUFFER_SIZE, b->id);
      }
    }
  }
  b->new_data = 0;    // We parsed all new data
}


uint32_t  serial_command(uint8_t* cbuf_in){

  char cbuf[COMMAND_BUFFER_LENGTH];
  strcpy(cbuf, cbuf_in);
  char argv[MAX_COMMAND_ARGS][MAX_COMMAND_LENGTH];
  const char s[2] = " ";
  char *token;
  token = strtok(cbuf, s);
  int argc = 0;
  while( token != NULL ){
    strcpy(argv[argc++], token);
    token = strtok(NULL, s);
  }



  if((strcmp(argv[0], "delay") == 0)){
    return atoi(argv[1]);
  }

  else if((strcmp(argv[0], "test") == 0)){
      char* msg = "Commandline works!\r\n";
      HAL_UART_Transmit(&huart1, msg, strlen(msg), 0xff);
  }
  else if((strcmp(argv[0], "wipe") == 0)){
      for(int n = 0; n < 1024; n++){
        erase_block(64*n);
      }
      print("All memory cleared\r\n\0");
  }
  else if((strcmp(argv[0], "numfiles") == 0)){
      filesystem tempfs;
      read_filesystem(&tempfs);
      uint8_t message[10];
      snprintf(message, sizeof(message), "%d\r\n", tempfs.num_files);
      print(message);
  }

  else if((strcmp(argv[0], "pf") == 0)){

      uint32_t filenum =  atoi(argv[1]);

      filesystem tempfs;
      read_filesystem(&tempfs);

      if(filenum > tempfs.num_files - 1){
          print("ERROR: INVALID FILE NUMBER\r\n\0");
          print("Hint: use \"numfiles\" to find out how many files there are\r\n\0");
          return 1;
      }

      print_file(filenum);

   }
  else if((strcmp(argv[0], "pfr") == 0)){ // print file raw
      uint32_t filenum =  atoi(argv[1]);
      filesystem tempfs;
      read_filesystem(&tempfs);
      if(filenum > tempfs.num_files - 1){
          print("ERROR: INVALID FILE NUMBER\r\n\0");
          print("Hint: use \"numfiles\" to find out how many files there are\r\n\0");
          return 1;
      }
      print_file_raw(filenum);
   }
  else if((strcmp(argv[0], "dump") == 0)){ // print file raw
     for(int page_address = 0; page_address < 25; page_address++){
         load_page(page_address*64);
         uint8_t buffer[2048];
         read_buffer(0, buffer, 2048);
         HAL_UART_Transmit(&huart1, buffer, 2048, 0xff);
     }
  }
  else if((strcmp(argv[0], "cmd") == 0)){
	  tx_pkt_cmd = 1;
	  radio_cmd = 0x1;
    }





  return 0;
}


void print(uint8_t* message){
  HAL_UART_Transmit(&huart1, message, strlen(message), 0xff);
}
