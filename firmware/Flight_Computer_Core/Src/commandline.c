/*
 * commandline.c
 *
 *  Created on: Jan 12, 2018
 *      Author: Nick Sterenberg
 */

#include "commandline.h"


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
    *(b->head++) = *(src++);    // Write a byte
    if(b->head > b-> end){      // Wrap around if we went past max address
      b->head = b->start;     // Set the head to the start
    }
    if(b->head==b->tail){     // Head has hit the tail
      b->tail++;          // Inc tail
      if(b->tail > b->end){   // Did the tail hit the max addr
        b->tail = b->start;   // Yep, send it to the start
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


  return 0;
}
