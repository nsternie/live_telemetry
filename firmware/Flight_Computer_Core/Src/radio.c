



#include "radio.h"
#include "main.h"
#include "stm32f4xx_hal.h"

extern SPI_HandleTypeDef hspi1;

//Configures radio for 2Kbit/s GFSK
void init_radio(void){
  uint8_t RXData[20] = {0};
  uint8_t TXData[20] = {0};
  //nR/W then address so 0x8 would be write to 0x00

  //Configuration parameters from spreadsheet
  TXData[0] = 0x1C | 0x80;
  TXData[1] = 0x1E;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);

  TXData[0] = 0x20 | 0x80;
  TXData[1] = 0xE8;
  TXData[2] = 0x60;
  TXData[3] = 0x20;
  TXData[4] = 0xC5;
  TXData[5] = 0x00;
  TXData[6] = 0x05;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 7, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);

  TXData[0] = 0x2A | 0x80;
  TXData[1] = 0x20;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);

  TXData[0] = 0x30 | 0x80;
  TXData[1] = 0xAC;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);

  TXData[0] = 0x32 | 0x80;
  TXData[1] = 0x8C;
  TXData[2] = 0x02;
  TXData[3] = 0x08;
  TXData[4] = 0x22;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 5, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);

  TXData[0] = 0x6E | 0x80;
  TXData[1] = 0x10;
  TXData[2] = 0x62;
  TXData[3] = 0x2C;
  TXData[4] = 0x23;
  TXData[5] = 0x50;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 6, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);

  TXData[0] = 0x75 | 0x80;
  TXData[1] = 0x76;
  TXData[2] = 0x25;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 3, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);

  //GPIO Config to use Antenna 2
  //GPIO 1 HIGH
  //GPIO 2 LOW
  //Should be antenna "B" on the left looking at radio
  //0b01011101 high
  //0b01011111 low
  //Needs to be switched to antenna diversity at some point

  TXData[0] = 0x0C | 0x80;
  TXData[1] = 0b01011101;
  TXData[2] = 0b01011111;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 3, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);

  TXData[0] = 0x0C;
  TXData[1] = 0b0;
  TXData[2] = 0b0;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 3, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);

  //Configure output power

  //Configure packet len
  TXData[0] = 0x3E | 0x80;
  TXData[1] = RADIO_PKT_LEN;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);
}

//Returns radio's RSSI value
uint8_t radio_readRSSI(void){
  uint8_t RXData[2] = {0};
  uint8_t TXData[2] = {0};
  TXData[0] = 0x26;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);
  return RXData[1];
}

//Returns radio's status register
//Bit 5 is RX FIFO empty status
uint8_t radio_readStatus(void){
  uint8_t RXData[2] = {0};
  uint8_t TXData[2] = {0};
  TXData[0] = 0x02;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);
  return RXData[1];
}

uint8_t radio_initInterrupt(void){
  //Set interrupt enable bit
  uint8_t RXData[3] = {0};
  uint8_t TXData[3] = {0};
  TXData[0] = 0x05 | 0x80;
  //Interrupt on packet receive
  //Can be changed to be more clever in the future for receiving commands to FC
  TXData[1] = 0b00000010;
  TXData[2] = 0b00000000;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 3, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);
  return 1;
}

uint8_t radio_clearInterrupt(void){
  //Clear interrupt bit
  uint8_t RXData[3] = {0};
  uint8_t TXData[3] = {0};
  TXData[0] = 0x03;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 3, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);
  return 1;
}

uint8_t radio_txPacket(uint8_t* packet){
  //Transmitt packet
  uint8_t RXData[RADIO_PKT_LEN] = {0};
  uint8_t TXData[1] = {0};
  TXData[0] = 0x7F | 0x80;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 1, 0xff);
  HAL_SPI_TransmitReceive(&hspi1, packet, RXData, RADIO_PKT_LEN, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);
  return 1;
}

uint8_t radio_rxPacket(uint8_t* packet){
  //Receive packet
  uint8_t RXData[RADIO_PKT_LEN] = {0};
  uint8_t TXData[1] = {0};
  TXData[0] = 0x7F;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 1, 0xff);
  HAL_SPI_TransmitReceive(&hspi1, RXData, packet, RADIO_PKT_LEN, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);
  return 1;
}
