#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "../../flash.h"
#include "../../sensors.h"

typedef struct gps_datastruct{
  int32_t time; // seconds
  int32_t latitude; // decimal degrees
  int32_t longitude; // decimal degrees
  int32_t fix_quality;
  uint8_t sats_tracked;
  int32_t hdop;
  int32_t altitude; // meters, according to reference site
} gps_data;

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
  gps_data gps;
  gps.time = 0;
  gps.latitude = 0;
  gps.longitude = 0;
  gps.fix_quality = 0;
  gps.sats_tracked = 0;
  gps.hdop = 0;
  gps.altitude = 0;
  float gps_time, latitude, longitude, fix_quality, hdop, altitude;

  for(int n = 0; n < 3; n++){
    g.data[n] = 0;
    a.data[n] = 0;
  }
  b.data = 0;
  uint32_t time = 0;
  uint32_t last_time = 0;
  uint8_t string[255] = "\0";

  // CSV header
  uint8_t line[255];
  printf("time,page,gyro_id,gyro_x,gyro_y,gyro_z,accel_x,accel_y,accel_z,barodata,gps_time,num_sats,altitude,lat,lon,string,\n\0");  // That last comma is really important, idk why, but everything breaks without it.

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
              b.data /= 100; // Convert to millibar
              base_index += 5;
              break;
             case PACKET_TYPE_GPS: // :o
              gps.time = page[base_index+1] << 24;
              gps.time |= page[base_index+2] << 16;
              gps.time |= page[base_index+3] << 8;
              gps.time |= page[base_index+4];
              gps_time = ((float) gps.time) / 1000;

              gps.latitude = page[base_index+5] << 24;
              gps.latitude |= page[base_index+6] << 16;
              gps.latitude |= page[base_index+7] << 8;
              gps.latitude |= page[base_index+8];
              latitude = ((float) gps.latitude) / 1000000;

              gps.longitude = page[base_index+9] << 24;
              gps.longitude |= page[base_index+10] << 16;
              gps.longitude |= page[base_index+11] << 8;
              gps.longitude |= page[base_index+12];
              longitude = ((float) gps.longitude) / 1000000;

              gps.fix_quality = page[base_index+13] << 24;
              gps.fix_quality |= page[base_index+14] << 16;
              gps.fix_quality |= page[base_index+15] << 8;
              gps.fix_quality |= page[base_index+16];
              fix_quality = ((float) gps.fix_quality) / 1000;

              gps.hdop = page[base_index+17] << 24;
              gps.hdop |= page[base_index+18] << 16;
              gps.hdop |= page[base_index+19] << 8;
              gps.hdop |= page[base_index+20];
              hdop = ((float) gps.hdop) / 1000;

              gps.altitude = page[base_index+21] << 24;
              gps.altitude |= page[base_index+22] << 16;
              gps.altitude |= page[base_index+23] << 8;
              gps.altitude |= page[base_index+24];
              altitude = ((float) gps.altitude) / 1000;

              gps.sats_tracked = page[base_index+25];

              base_index += 26;
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
                page[base_index] = PACKET_TYPE_EOP;
                //exit(1);
              break;
          }
            if(time != last_time){
            printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%.3f,%d,%.3f,%.6f,%.6f,%s,\n\0",
              time, current_page,
              g.id, g.data[0], g.data[1], g.data[2],
              a.data[0], a.data[1], a.data[2],
              b.data,
              gps_time, gps.sats_tracked, altitude, latitude, longitude,
              string);
            string[0] = '\0';         // Clear the current message, if any
            last_time = time;
            }
          type = page[base_index];  // Get the type of the next packet
      }
      current_page++;
  }

}