#ifndef CC1125
#define CC1125

#include <stdlib.h>
#include <stdio.h>

//First 3 includes must be in this order
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_cortex.h"
#include "stm32f4xx_hal_spi.h"
#include "stm32f4xx_hal_conf.h"
#include "stm32f4xx_hal_spi.h"


//Read/Write Offsets
#define CC_Write 0x00
#define CC_Write_Burst 0x40
#define CC_Read 0x80
#define CC_Read_Burst 0xC0

//Register Offsets
#define IOCFG3 0x00
#define IOCFG2 0x01
#define IOCFG1 0x02
#define IOCFG0 0x03
#define SYNC3 0x04
#define SYNC2 0x05
#define SYNC1 0x06
#define SYNC0 0x07
#define SYNC_CFG1 0x08
#define SYNC_CFG0 0x09
#define DEVIATION_M 0x0A
#define MODCFG_DEF_E 0x0B
#define DCFILT_CFG 0x0C
#define PREAMBLE_CFG1 0x0D
#define PREAMBLE_CFG0 0x0E
#define FREQ_IF_CFG 0x0F

#define IQIC 0x10
#define CHAN_BW 0x11
#define MDMCFG1 0x12
#define MDMCFG0 0x13
#define SYMBOL_RATE2 0x14
#define SYMBOL_RATE1 0x15
#define SYMBOL_RATE0 0x16
#define AGC_REF 0x17
#define AGC_CS_THR 0x18
#define AGC_GAIN_ADJUST 0x19
#define AGC_CFG3 0x1A
#define AGC_CFG2 0x1B
#define AGC_CFG1 0x1C
#define AGC_CFG0 0x1D
#define FIFO_CFG 0x1E
#define DEV_ADDR 0x1F

#define SETTLING_CFG 0x20
#define FS_CFG 0x21
#define WOR_CFG1 0x22
#define WOR_CFG0 0x23
#define WOR_EVENT0_MSB 0x24
#define WOR_EVENT0_LSB 0x25
#define PKT_CFG2 0x26
#define PKT_CFG1 0x27
#define PKT_CFG0 0x28
#define RFEND_CFG1 0x29
#define RFEND_CFG0 0x2A
#define PA_CFG2 0x2B
#define PA_CFG1 0x2C
#define PA_CFG0 0x2D
#define PKT_LEN 0x2E

//Register Extended Addr (See Data Sheet)
#define EXTEND_ADDR 0x2F

//Commands
#define SRES 0x30
#define SFSTXON 0x31
#define SXOFF 0x23
#define SCAL 0x33
#define SRX 0x34
#define STX 0x35
#define SIDLE 0x36
#define SAFC 0x37
#define SWOR 0x38
#define SPWD 0x39
#define SFRX 0x3A
//#define SFSTXON 0x3B
#define SWORRST 0x3C
#define SNOP 0x3D

typedef struct
{
  SPI_HandleTypeDef *spi;

  uint16_t Pin;

  GPIO_TypeDef *CS_Port;

  uint8_t State;

}_CC1125;


int CC1125_Cmd(uint8_t *Data, _CC1125 *Device);
int CC1125_Reg(uint16_t Addr, uint8_t Data, _CC1125 *Device);
int CC1125_TxFIFO(uint8_t Data, _CC1125 *Device);
int CC1125_RxFIFO(uint8_t *RxPacket, _CC1125 *Device);
int CC1125_GetState(_CC1125 *Device);
void CC1125_Cfg(_CC1125 *Device);
uint8_t CC1125_FIFO_NUM_TXBYTES(_CC1125 *Device);

#endif
