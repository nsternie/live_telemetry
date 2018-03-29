#include "SX1280.h"
#include "main.h"
#include "stm32f4xx_hal.h"

extern SPI_HandleTypeDef hspi1;

void init_radio(void){
	HAL_GPIO_WritePin(nRST_RADIO_GPIO_Port, nRST_RADIO_Pin, 1);
	HAL_Delay(1000);

	volatile uint8_t TXData[30] = {0};
	volatile uint8_t RXData[30] = {0};

	//Set into standby
	TXData[0] = 0x80;
	TXData[1] = 0x00;
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);
	HAL_Delay(10);

	//Set pkt type to LORA
	TXData[0] = 0x8A;
	TXData[1] = 0x01;
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 2, 0xff);
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);
	HAL_Delay(10);

	//Set RF frequency to ~2.4GHz
	TXData[0] = 0x86;
	TXData[1] = 0xB8;
	TXData[2] = 0x9D;
	TXData[3] = 0x80;
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 4, 0xff);
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);
	HAL_Delay(10);

	//Set TX/RX buffer base addresses
	TXData[0] = 0x8F;
	TXData[1] = 0x00;	//txBase
	TXData[2] = 0x80;	//rxBase
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 3, 0xff);
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);
	HAL_Delay(10);

	//Set modulation params
	TXData[0] = 0x8B;
	TXData[1] = 0xB0; //SF = 11
	TXData[2] = 0x0A; //BW = 1600
	TXData[3] = 0x05; //LI 4/5
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 4, 0xff);
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);
	HAL_Delay(10);

	//Write 0x32 to reg 0x925 as per data sheet note on pg 115
	//Not 100% sure this is correct
	TXData[0] = 0x18;
	TXData[1] = 0x09;
	TXData[2] = 0x25;
	TXData[3] = 0x32;
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 4, 0xff);
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);
	HAL_Delay(10);

	//Set packet params
	TXData[0] = 0x8C;
	TXData[1] = 0x0C; //16 (12???) symbol preamble
	TXData[2] = 0x00; //explicit header (variable len pkt)
	TXData[3] = 0x16; //Payload (22 bytes)
	TXData[4] = 0x20; //CRC enabled
	TXData[5] = 0x40; //Standard IQ
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 6, 0xff);
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);
	HAL_Delay(10);

	//Set TX power & ramp speed
	TXData[0] = 0x8E;
	TXData[1] = 0x19; //19 is 7dBm of output power ~33dBm after amps. Max is 0x31 which is 13dBm out
	TXData[2] = 0xE0;
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 3, 0xff);
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);
	HAL_Delay(10);

	//Set IRQs
	TXData[0] = 0x8D;
	TXData[1] = 0x00;
	TXData[2] = 0x03; //TXDone and RXDone active
	TXData[3] = 0x00;
	TXData[4] = 0x01; //TXDone on DIO1
	TXData[5] = 0x00;
	TXData[6] = 0x02; //RXDone on DIO2
	TXData[7] = 0x00;
	TXData[8] = 0x00;
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 9, 0xff);
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);
	HAL_Delay(10);

	//Read back some params to make sure comms are okay
	//Read back packet type, should be 0x01;
	TXData[0] = 0x03;
	TXData[1] = 0x00;
	TXData[2] = 0x00;
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 3, 0xff);
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);
	HAL_Delay(10);
}

uint8_t radio_txPacket(uint8_t* packet){

	volatile uint8_t TXData[30] = {0};
	volatile uint8_t RXData[30] = {0};

	packet[0] = 0x1A;
	packet[1] = 0x00; //TXBase

	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	HAL_SPI_TransmitReceive(&hspi1, packet, RXData, 24, 0xff);
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);

	//HAL_Delay(1); //Replace with a check of the busy pin in future for faster operation

	TXData[0] = 0x83;
	TXData[1] = 0x00;
	TXData[2] = 0x00;
	TXData[3] = 0x00;
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 4, 0xff);
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);

	return(1);
}

uint8_t radio_clearInterrupt(void){
	uint8_t TXData[30] = {0};
	uint8_t RXData[30] = {0};

	TXData[0] = 0x97;
	TXData[1] = 0xFF;
	TXData[2] = 0xFF;
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 3, 0xff);
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);

	return(1);
}

void radio_RXMode(void){
	uint8_t TXData[30] = {0};
	uint8_t RXData[30] = {0};

	TXData[0] = 0x82;
	TXData[1] = 0x00;
	TXData[2] = 0x00;
	TXData[3] = 0x00;
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 3, 0xff);
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);
}

void radio_getPktStatus(void){
	uint8_t TXData[30] = {0};
	uint8_t RXData[30] = {0};
	TXData[0] = 0x1D;
	TXData[1] = 0x00;
	TXData[2] = 0x00;
	TXData[3] = 0x00;
	TXData[4] = 0x00;
	TXData[5] = 0x00;
	TXData[6] = 0x00;
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 7, 0xff);
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);

	volatile float RSSI = -1*((int8_t)RXData[2]/2.0); //Not sure if this calc is correct? RX_Buff needs cast to int8_t?
	volatile float SNR = ((int8_t)RXData[3])/4.0;
}

void radio_getRXBufferStatus(void){
	uint8_t TXData[30] = {0};
	uint8_t RXData[30] = {0};
	volatile uint8_t Offset = 0x80;
	volatile uint8_t PayloadLen = 0x00;
	TXData[0] = 0x17;
	TXData[1] = 0x00;
	TXData[2] = 0x00;
	TXData[3] = 0x00;
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	HAL_SPI_TransmitReceive(&hspi1, TXData, RXData, 4, 0xff);
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);
	Offset = RXData[3];
	PayloadLen = RXData[2];
}

//Change? Depends on the packet length
//Modified for Rocket!
uint8_t radio_rxPacket(uint8_t* packet){
	uint8_t TXData[30] = {0};
	uint8_t RXData[30] = {0};

	TXData[0] = 0x1B;
	TXData[1] = 0x80; //Change to radio Offset
	TXData[2] = 0x00;

	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 0);
	HAL_SPI_TransmitReceive(&hspi1, TXData, packet, 5, 0xff);
	HAL_GPIO_WritePin(CS_Radio_GPIO_Port, CS_Radio_Pin, 1);
}
