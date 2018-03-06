#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "flash.h"
#include "sensors.h"

int main(int argc, char* argv[]){
    FILE* binfile = fopen(argv[1], "rb");
    if(binfile == 0){
        printf("Could not open %s\n", argv[1]);
    } 
    print_file(binfile);
    return 0;
}   

int sign_extend_accel(int in){
    int value = in & 0x0007ffff;
    int sign = (in & 0x00080000) > 0;
    if(sign != 0){
        //printf("%d becomes %d\n", in, -value);
        return (-1*value);
    }
    else{
        //printf("%d becomes %d\n", in, value);
        return value;
    }
}

// Parses a log file, concerts it to a csv, and sends it over UART
void print_file(FILE* binfile){

    fseek(binfile, 0L, SEEK_END);
    int size = ftell(binfile);
    rewind(binfile);
    int num_pages = size / 2048;

    //printf("Pages: %d\n", num_pages);


  gyro g;
  accel a;
  baro b;
  for(int n = 0; n < 3; n++){
    g.data[n] = 0;
    a.data[n] = 0;
  }
  b.data = 0;
  uint32_t time = 0;
  uint8_t string[255] = "\0";

  // CSV header
  uint8_t line[255];
  printf("time,page,gyro_id,gyro_x,gyro_y,gyro_z,accel_x,accel_y,accel_z,barodata,string,\n\0");  // That last comma is really important, idk why, but everything breaks without it.

  uint16_t current_page = 0;
  while(current_page < num_pages){
      uint8_t page[2048];

      fread(page, sizeof(uint8_t), 2048, binfile);//read_buffer(0, page, 2048);
      uint8_t type = page[0];
      int32_t base_index = 0;
      while(type != PACKET_TYPE_EOP){
          switch(type){
            case PACKET_TYPE_GYRO:
              g.id = page[base_index+1];
              g.data[0] = page[base_index+2] << 8;
              g.data[0] |= page[base_index+3];
              g.data[1] = page[base_index+4] << 8;
              g.data[1] |= page[base_index+5];
              g.data[2] = page[base_index+6] << 8;
              g.data[2] |= page[base_index+7];
              base_index += 8;
              break;
            case PACKET_TYPE_ACCEL:
              a.data[0] = page[base_index+1] << 24;
              a.data[0] |= page[base_index+2] << 16;
              a.data[0] |= page[base_index+3] << 8;
              a.data[0] |= page[base_index+4];
              a.data[1] = page[base_index+5] << 24;
              a.data[1] |= page[base_index+6] << 16;
              a.data[1] |= page[base_index+7] << 8;
              a.data[1] |= page[base_index+8];
              a.data[2] = page[base_index+9] << 24;
              a.data[2] |= page[base_index+10] << 16;
              a.data[2] |= page[base_index+11] << 8;
              a.data[2] |= page[base_index+12];
              // for(int i = 0; i < 3; i++){
              //   a.data[i] = sign_extend_accel(a.data[i]);
              // }
              base_index += 13;
              break;
            case PACKET_TYPE_BARO:
              b.data = page[base_index+1] << 24;
              b.data |= page[base_index+2] << 16;
              b.data |= page[base_index+3] << 8;
              b.data |= page[base_index+4];
              base_index += 5;
              break;
            case PACKET_TYPE_GPS:
                // TODO when gps is merged in
              break;
            case PACKET_TYPE_MILLIS:
              time = page[base_index+1] << 24;
              time |= page[base_index+2] << 16;
              time |= page[base_index+3] << 8;
              time |= page[base_index+4];
              base_index += 5;
              break;
            case PACKET_TYPE_STRING:
             // strcpy(page[base_index+1], string);
              break;
            default:
                printf("Invalid packet code: 0x%x\n", type);
                exit(1);
              break;
          }
          printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%s,\n\0", time, current_page,
                   g.id, g.data[0], g.data[1], g.data[2],
                   a.data[0], a.data[1], a.data[2],
                   b.data,
                   string);
          string[0] = '\0';         // Clear the current message, if any
          type = page[base_index];  // Get the type of the next packet
      }
      current_page++;
  }

}