/*
 * sensors.c
 *
 *  Created on: Jan 12, 2018
 *      Author: Nick Sterenberg, Jacob Sigler
 *
 */

#include "main.h"
#include "stm32f4xx_hal.h"
#include "sensors.h"
#include "math.h"

extern SPI_HandleTypeDef hspi2;
extern UART_HandleTypeDef huart1;


//Reads data from a single gyro
//Takes gyro struct and returns data in same struct
void read_gyro(gyro *g){

  GPIO_TypeDef *port;
  uint16_t pin;

  //Default if switch fails for some reason
  port = GYRO1_CS_GPIO_Port;
  pin = GYRO1_CS_Pin;

  switch(g->id){
    case 1:
      port = GYRO1_CS_GPIO_Port;
      pin = GYRO1_CS_Pin;
      break;
    case 2:
      port = GYRO2_CS_GPIO_Port;
      pin = GYRO2_CS_Pin;
      break;
    case 3:
      port = GYRO3_CS_GPIO_Port;
      pin = GYRO3_CS_Pin;
      break;
    case 4:
      port = GYRO4_CS_GPIO_Port;
      pin = GYRO4_CS_Pin;
      break;
    case 5:
      port = GYRO5_CS_GPIO_Port;
      pin = GYRO5_CS_Pin;
      break;
    case 6:
      port = GYRO6_CS_GPIO_Port;
      pin = GYRO6_CS_Pin;
      break;

  }

  uint8_t RXData[7] = {0};
  uint8_t TXData[7] = {0};
  TXData[0] = 0x12 | 0x80;

  HAL_GPIO_WritePin(port, pin, 0);          // Select device
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 7, 0xff);
  HAL_GPIO_WritePin(port, pin, 1);          // Release device

  g->data[0] = (RXData[2] << 8) | RXData[1]; //X data
  g->data[1] = (RXData[4] << 8) | RXData[3]; //Y data
  g->data[2] = (RXData[6] << 8) | RXData[5]; //Z data

}

//Initalize and turns on all gyros
init_gyros(void){

  uint8_t RXData[7] = {0};
  uint8_t TXData[7] = {0};
  TXData[0] = 0x7E;
  TXData[1] = 0x15;

  HAL_GPIO_WritePin(GYRO1_CS_GPIO_Port, GYRO1_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO1_CS_GPIO_Port, GYRO1_CS_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin(GYRO2_CS_GPIO_Port, GYRO2_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO2_CS_GPIO_Port, GYRO2_CS_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin(GYRO3_CS_GPIO_Port, GYRO3_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO3_CS_GPIO_Port, GYRO3_CS_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin(GYRO4_CS_GPIO_Port, GYRO4_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO4_CS_GPIO_Port, GYRO4_CS_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin(GYRO5_CS_GPIO_Port, GYRO5_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO5_CS_GPIO_Port, GYRO5_CS_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin(GYRO6_CS_GPIO_Port, GYRO6_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO6_CS_GPIO_Port, GYRO6_CS_Pin, 1);

  //Need to decide ODR here

  //Need to decide Resolution here (dynamic range)

  //Setup interrupts
  TXData[0] = 0x51;
  TXData[1] = 0x10;
  HAL_GPIO_WritePin(GYRO1_CS_GPIO_Port, GYRO1_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO1_CS_GPIO_Port, GYRO1_CS_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin(GYRO2_CS_GPIO_Port, GYRO2_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO2_CS_GPIO_Port, GYRO2_CS_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin(GYRO3_CS_GPIO_Port, GYRO3_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO3_CS_GPIO_Port, GYRO3_CS_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin(GYRO4_CS_GPIO_Port, GYRO4_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO4_CS_GPIO_Port, GYRO4_CS_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin(GYRO5_CS_GPIO_Port, GYRO5_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO5_CS_GPIO_Port, GYRO5_CS_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin(GYRO6_CS_GPIO_Port, GYRO6_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO6_CS_GPIO_Port, GYRO6_CS_Pin, 1);

  TXData[0] = 0x53;
  TXData[1] = 0x0B; //Might be wrong on the edge bit?
  HAL_GPIO_WritePin(GYRO1_CS_GPIO_Port, GYRO1_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO1_CS_GPIO_Port, GYRO1_CS_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin(GYRO2_CS_GPIO_Port, GYRO2_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO2_CS_GPIO_Port, GYRO2_CS_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin(GYRO3_CS_GPIO_Port, GYRO3_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO3_CS_GPIO_Port, GYRO3_CS_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin(GYRO4_CS_GPIO_Port, GYRO4_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO4_CS_GPIO_Port, GYRO4_CS_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin(GYRO5_CS_GPIO_Port, GYRO5_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO5_CS_GPIO_Port, GYRO5_CS_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin(GYRO6_CS_GPIO_Port, GYRO6_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO6_CS_GPIO_Port, GYRO6_CS_Pin, 1);

  TXData[0] = 0x56;
  TXData[1] = 0x80;
  HAL_GPIO_WritePin(GYRO1_CS_GPIO_Port, GYRO1_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO1_CS_GPIO_Port, GYRO1_CS_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin(GYRO2_CS_GPIO_Port, GYRO2_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO2_CS_GPIO_Port, GYRO2_CS_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin(GYRO3_CS_GPIO_Port, GYRO3_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO3_CS_GPIO_Port, GYRO3_CS_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin(GYRO4_CS_GPIO_Port, GYRO4_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO4_CS_GPIO_Port, GYRO4_CS_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin(GYRO5_CS_GPIO_Port, GYRO5_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO5_CS_GPIO_Port, GYRO5_CS_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin(GYRO6_CS_GPIO_Port, GYRO6_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(GYRO6_CS_GPIO_Port, GYRO6_CS_Pin, 1);
}

void test_gyros(void){
  gyro g1, g2, g3, g4, g5, g6;
  g1.id = 1;
  g2.id = 2;
  g3.id = 3;
  g4.id = 4;
  g5.id = 5;
  g6.id = 6;

  uint8_t data[100] = "starting gyro test\r\n\0";
  HAL_UART_Transmit(&huart1, data, strlen(data), 0xff);

  init_gyros();
  int16_t avg_x, avg_y, avg_z;

  while(1){
    read_gyro(&g6);
    read_gyro(&g5);
    read_gyro(&g4);
    read_gyro(&g3);
    read_gyro(&g2);
    read_gyro(&g1);
    avg_x = (g1.data[0] + g2.data[0] + g3.data[0] + g4.data[0] + g5.data[0] + g6.data[0])/6;
    avg_y = (g1.data[1] + g2.data[1] + g3.data[1] + g4.data[1] + g5.data[1] + g6.data[1])/6;
    avg_z = (g1.data[2] + g2.data[2] + g3.data[2] + g4.data[2] + g5.data[2] + g6.data[2])/6;
    snprintf(data, 100, "%d %d %d\r\n", avg_x, avg_y, avg_z);
    HAL_UART_Transmit(&huart1, data, strlen(data), 0xff);
    HAL_Delay(100);
  }
}

void init_accel(void){
  uint8_t RXData[2] = {0};
  uint8_t TXData[2] = {0};
  TXData[0] = 0x2D << 1;
  TXData[1] = 0x00;        //Turn off standby and go to measurement mode

  HAL_GPIO_WritePin(ADXL_CS_GPIO_Port, ADXL_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(ADXL_CS_GPIO_Port, ADXL_CS_Pin, 1);

  //Set ODR and Filter BW here

  //Set DRDY here?

  //Set Range
}

void read_accel(accel *a){
  uint8_t RXData[10] = {0};
  uint8_t TXData[10] = {0};
  TXData[0] = 0x08 << 1 | 0x1; //ADXL does addr first then R/nW bit

  HAL_GPIO_WritePin(ADXL_CS_GPIO_Port, ADXL_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 10, 0xff);
  HAL_GPIO_WritePin(ADXL_CS_GPIO_Port, ADXL_CS_Pin, 1);

  a->data[0] = (RXData[1] << 12) | (RXData[2] << 4) | ((RXData[3] & 0xF0) >> 4); //This isn't correct, data is left justified
  a->data[1] = (RXData[4] << 12) | (RXData[5] << 4) | ((RXData[6] & 0xF0) >> 4);
  a->data[2] = (RXData[7] << 12) | (RXData[8] << 4) | ((RXData[9] & 0xF0) >> 4);


  //Sign extension
  if(((RXData[1] & 0x80) >> 7) == 0x1){
      a->data[0] = a->data[0] | (0xFFF << 20);
  }
  if(((RXData[4] & 0x80) >> 7) == 0x1){
      a->data[1] = a->data[1] | (0xFFF << 20);
  }
  if(((RXData[7] & 0x80) >> 7) == 0x1){
      a->data[2] = a->data[2] | (0xFFF << 20);
  }
}

void test_accel(void){
  double temp1, temp2, temp3;
    accel a;
    init_accel();
    uint8_t data[100] = "starting accel test\r\n\0";
    HAL_UART_Transmit(&huart1, data, strlen(data), 0xff);

    while(1){
      HAL_Delay(500);
      read_accel(&a);
      temp1 = ((double)a.data[0])*(10.0/(0x1 << 19));
      temp2 = ((double)a.data[1])*(10.0/(0x1 << 19));
      temp3 = ((double)a.data[2])*(10.0/(0x1 << 19));
      snprintf(data, 100, "%.3f %.3f %.3f\r\n", temp1, temp2, temp3); //X Y Z
      HAL_UART_Transmit(&huart1, data, strlen(data), 0xff);
    }
}

void init_baro(baro *b){
  uint8_t RXData[3] = {0};
  uint8_t TXData[3] = {0};

  //Sent reset first
  TXData[0] = 0x1E;
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 1, 0xff);
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 1);
  HAL_Delay(100);

  //Read in PROM data
  TXData[0] = 0xA2;
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 3, 0xff);
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 1);
  b->prom[0] = (RXData[1] << 8) | RXData[2];

  TXData[0] = 0xA4;
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 3, 0xff);
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 1);
  b->prom[1] = (RXData[1] << 8) | RXData[2];

  TXData[0] = 0xA6;
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 3, 0xff);
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 1);
  b->prom[2] = (RXData[1] << 8) | RXData[2];

  TXData[0] = 0xA8;
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 3, 0xff);
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 1);
  b->prom[3] = (RXData[1] << 8) | RXData[2];

  TXData[0] = 0xAA;
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 3, 0xff);
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 1);
  b->prom[4] = (RXData[1] << 8) | RXData[2];

  TXData[0] = 0xAC;
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 3, 0xff);
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 1);
  b->prom[5] = (RXData[1] << 8) | RXData[2];

  //See figure 4 table for OSR settings
  b->D1_OSR = 0x48;
  b->D2_OSR = 0x58;
}

void D1_conv_baro(baro *b){
  uint8_t RXData[1] = {0};
  uint8_t TXData[1] = {0};

  TXData[0] = b->D1_OSR;
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 1, 0xff);
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 1);
}

void D2_conv_baro(baro *b){
  uint8_t RXData[1] = {0};
  uint8_t TXData[1] = {0};

  TXData[0] = b->D2_OSR;
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 1, 0xff);
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 1);
}

void read_D1_baro(baro *b){
  uint8_t RXData[4] = {0};
  uint8_t TXData[4] = {0};

  TXData[0] = 0x00;
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 4, 0xff);
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 1);

  b->D1 = (RXData[1] << 16) | (RXData[2] << 8) | RXData[3];
}

void read_D2_baro(baro *b){
  uint8_t RXData[4] = {0};
  uint8_t TXData[4] = {0};

  TXData[0] = 0x00;
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi2, TXData, RXData, 4, 0xff);
  HAL_GPIO_WritePin(MS5607_CS_GPIO_Port, MS5607_CS_Pin, 1);

  b->D2 = (RXData[1] << 16) | (RXData[2] << 8) | RXData[3];
}

void conv_pres_baro(baro *b){
  volatile int32_t dT, TEMP;
  volatile int64_t OFF, SENS;
  volatile int64_t partialA, partialB;

  dT = b->D2 - ((b->prom[4])*(0x1<<8));                       //D2-C5*2^8
  TEMP = 2000 + ((int64_t)dT*((int64_t)b->prom[5]))/(0x1<<23);                  //2000 + dT*C6/2^23
  partialA = ((int64_t)b->prom[3])*(int64_t)dT;
  OFF = ((int64_t)b->prom[1])*(0x1<<17) + (partialA)/(0x1<<6);  //C2*2^17 + C4*dT/2^6
  SENS = ((int64_t)b->prom[0])*(0x1<<16) + (((int64_t)b->prom[2])*(int64_t)dT)/(0x1<<7); //C1*2^16 + C3*dT/2^7

  b->data = ((((int64_t)b->D1)*SENS)/(0x1<<21)-OFF)/(0x1<<15);         //(D1*SENS/2^21-OFF)/2^15
}

void conv_alt(baro *b){
  float pressure = ((float)b->data)/100.0; //Pressure in mBar
  float tempA = (pressure/1013.25);
  float tempB = pow(tempA, 0.190284);
  float tempC = 1.0-tempB;
  b->altitude = tempC * 145366.45;
}

