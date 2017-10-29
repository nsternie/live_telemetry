//Setup for FC
//  _MS5607 MS5607;
//  MS5607.CS_Port = GPIOC;
//  MS5607.Pin = GPIO_PIN_3;
//  MS5607.spi = &hspi1;
#include "stm32f4xx_hal.h"

#ifndef MS5607
#define MS5607

//PROM Offsets
#define MFG 0xA0
#define CFC1 0xA2
#define CFC2 0xA4
#define CFC3 0xA6
#define CFC4 0xA8
#define CFC5 0xAA
#define CFC6 0xAC
#define MS5607_CRC 0xAE

//Commands
#define CVT_D1 0x40
//_256 0x40
//#define CVT_D1_512 0x42
//#define CVT_D1_1024 0x44
//#define CVT_D1_2048 0x46
//#define CVT_D1_4096 0x48
#define CVT_D2 0x50
//_256 0x50
//#define CVT_D2_512 0x52
//#define CVT_D2_1024 0x54
//#define CVT_D2_2048 0x56
//#define CVT_D2_4096 0x58
#define ADC_READ 0x00
#define MS_RESET 0x1E

#define Conv_Offset 0x04
//Conv offset table
//0x00 = 256
//0x02 = 512
//0x04 = 1024
//0x06 = 2048

typedef struct
{
  SPI_HandleTypeDef *spi;

  GPIO_TypeDef *CS_Port;

  uint16_t Pin;

  uint16_t CFC[8];

}_MS5607;

int MS5607_Cmd(uint8_t *Data, _MS5607 *Device);
int MS5607_PROM(_MS5607 *Device);
void MS5607_Rst(_MS5607 *Device);
void MS5607_ConvD1(_MS5607 *Device);
void MS5607_ConvD2(_MS5607 *Device);
uint32_t MS5607_ReadADC(_MS5607 *Device);
int32_t MS5607_CalcTemp(uint32_t D2, _MS5607 *Device);
int32_t MS5607_CalcPres(uint32_t D1, uint32_t D2, _MS5607 *Device);

#endif
