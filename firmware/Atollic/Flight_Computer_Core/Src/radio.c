



#include "radio.h"
#include "main.h"
#include "stm32f4xx_hal.h"

extern SPI_HandleTypeDef hspi1;

//Configures radio for 2Kbit/s GFSK
void init_radio(void){
  uint8_t RXData[20] = {0};
  uint8_t TXData[20] = {0};
  //nR/W then address so 0x8 would be write to 0x00

  TXData[0] = 0x07 | 0x80;
  TXData[1] = 0x81;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);
  HAL_Delay(1000);

  //Configuration parameters from spreadsheet
  TXData[0] = 0x1C | 0x80;
  TXData[1] = 0xAB;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);

  TXData[0] = 0x20 | 0x80;
  TXData[1] = 0xEE;
  TXData[2] = 0x40;
  TXData[3] = 0x2B;
  TXData[4] = 0xB1;
  TXData[5] = 0x00;
  TXData[6] = 0x09;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 7, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);

  TXData[0] = 0x2A | 0x80;
  TXData[1] = 0x24;
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
  TXData[2] = 0x0A;
  TXData[3] = 0x10;
  TXData[4] = 0x22;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 5, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);


  //3E sets packet len
  TXData[0] = 0x3E | 0x80;
  TXData[1] = RADIO_PKT_LEN;// RADIO_PKT_LEN;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);


  TXData[0] = 0x6E | 0x80;
  TXData[1] = 0x20;
  TXData[2] = 0x5C;
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

  //Set TX power to max
  TXData[0] = 0x6D | 0x80;
  TXData[1] = 0b00011111;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);
}

//Returns radio's RSSI value


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

uint8_t radio_resetFIFO(void){
  //Warning!!! will mess up ant div. Call before ant div init.
  uint8_t RXData[3] = {0};
  uint8_t TXData[3] = {0};
  TXData[0] = 0x88;
  TXData[1] = 0b00000011;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);

  HAL_Delay(50);
  TXData[1] = 0b00000000;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);

  return 1;
}

uint8_t radio_txPacket(uint8_t* packet){
  //Transmitt packet
  uint8_t RXData[RADIO_PKT_LEN + 1] = {0};
  uint8_t TXData[2] = {0};
  packet[0] = 0x7F | 0x80;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, packet, RXData, RADIO_PKT_LEN + 1, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);

  TXData[0] = 0x07 | 0x80;
  TXData[1] = 0x09;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
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

//  TXData[0] = 0x07 | 0x80;
//  TXData[1] = 0x05;
//  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
//  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
//  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);
  return 1;
}

uint8_t radio_checkMAC(void){
  uint8_t RXData[3] = {0};
  uint8_t TXData[3] = {0};

  TXData[0] = 0x31;

  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);

  return RXData[1];
}

void radio_RXMode(void){
  uint8_t RXData[3] = {0};
  uint8_t TXData[3] = {0};

  TXData[0] = 0x07 | 0x80;
  TXData[1] = 0x05;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);
}

void radio_IDLEMode(void){
  uint8_t RXData[3] = {0};
  uint8_t TXData[3] = {0};

  TXData[0] = 0x07 | 0x80;
  TXData[1] = 0x02;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);
}

uint8_t radio_readInterrupt(void){
  //Will also clear interrupt
  uint8_t RXData[3] = {0};
  uint8_t TXData[3] = {0};
  TXData[0] = 0x03;
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
  HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
  HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);
  return RXData[1];
}

uint8_t radio_checkRxPkt(void){
	uint8_t RXData[3] = {0};
	uint8_t TXData[3] = {0};
	TXData[0] = 0x03;
	HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
	HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 3, 0xff);
	HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);

	if(((RXData[1] >> 1) & 0b1) == 1){
		return 1;
	}
	else{
		return 0;
	}
}

uint8_t radio_initAntennaDiv(void){
	//Set GPIO for antenna diversity
	//Set 0x08 register for antenna diversity
	//remember to change preamble length

	uint8_t RXData[3] = {0};
	uint8_t TXData[3] = {0};
	TXData[0] = 0x88;
	TXData[1] = 0b10100000;
	HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
	HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
	HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);

	TXData[0] = 0x0C | 0x80;
	TXData[1] = 0b01010111;
	TXData[2] = 0b01011000;
	HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
	HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 3, 0xff);
	HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);
	return 1;
}

uint8_t radio_readRSSI(void){
	uint8_t RXData[2] = {0};
	uint8_t TXData[2] = {0};
	TXData[0] = 0x26;
	HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 0);
	HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
	HAL_GPIO_WritePin(RADIO_CS_GPIO_Port, RADIO_CS_Pin, 1);
	return RXData[1];
}
