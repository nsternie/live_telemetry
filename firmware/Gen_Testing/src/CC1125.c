#include "CC1125.h"

int CC1125_Cmd(uint8_t *Data, _CC1125 *Device){

  //Pull CS pin low
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_RESET);

  //Transmit cmd to CC1125 over SPI
  //If need to optimize, HAL can be replaced with low level spi implementation.
  HAL_SPI_Transmit(Device->spi, Data, 1, 0xFFFF);

  //Push CS pin high
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_SET);


  return 1;
}

int CC1125_Reg(uint16_t Addr, uint8_t Data, _CC1125 *Device){
  uint8_t Packet[3] = {0, 0, 0};

  if(((Addr >> 8) & 0xFF) == 0x00){
    //If normal address space
    Packet[0] = Addr & 0xFF;
    Packet[1] = Data;
    HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(Device->spi, Packet, 2, 0xFFFF);
    HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_SET);
  }
  else{
    Packet[0] = 0x2F;
    Packet[1] = Addr & 0xFF;
    Packet[2] = Data;
    HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(Device->spi, Packet, 3, 0xFFFF);
    HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_SET);
  }

  return 1;
}

int CC1125_TxFIFO(uint8_t Data, _CC1125 *Device){
  //Set up packet for HAL transmit function. (Something that can be optmized if
  //we switch to custom spi driver).
  uint8_t Packet[2];
  Packet[0] = 0x3F;
  Packet[1] = Data;

  //Pull CS pin low
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_RESET);

  //Transmit cmd to CC1125 over SPI
  //If need to optimize, HAL can be replaced with low level spi implementation.
  HAL_SPI_Transmit(Device->spi, Packet, 2, 0xFFFF);

  //Push CS pin high
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_SET);


  return 1;
}

int CC1125_RxFIFO(uint8_t *RxPacket, _CC1125 *Device){
  //May want to change so packet is returned by value not reference

  //Set up packet for HAL transmit function. (Something that can be optmized if
  //we switch to custom spi driver).
  uint8_t TxPacket = 0x3F+0x80;

  //Pull CS pin low
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_RESET);

  //Transmit packet
  HAL_SPI_TransmitReceive(Device->spi, &TxPacket, RxPacket, 1, 0xFFFF);

  //Push CS pin high
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_SET);

  return 1;
}

int CC1125_GetState(_CC1125 *Device){

  //Set up packet for HAL transmit function. (Something that can be optmized if
  //we switch to custom spi driver).
  uint8_t TxPacket = SNOP;
  uint8_t RxPacket = 0;

  //Pull CS pin low
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_RESET);

  //Transmit NOP to CC1125 over SPI and record CC1125 response
  //If need to optimize, HAL can be replaced with low level spi implementation.
  HAL_SPI_TransmitReceive(Device->spi, &TxPacket, &RxPacket, 1, 0xFFFF);

  //Push CS pin high
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_SET);

  Device->State = (RxPacket >> 4);

  return 1;
}

uint8_t CC1125_FIFO_NUM_TXBYTES(_CC1125 *Device){

  uint8_t TxPacket[3];
  uint8_t RxPacket[3] = {0, 0, 0};

  TxPacket[0] = 0xAF;
  TxPacket[1] = 0xD6;
  TxPacket[2] = 0x00;

  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_RESET);

  //Transmit NOP to CC1125 over SPI and record CC1125 response
  //If need to optimize, HAL can be replaced with low level spi implementation.
  HAL_SPI_TransmitReceive(Device->spi, TxPacket, RxPacket, 3, 0xFFFF);

  //Push CS pin high
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_SET);

  return RxPacket[2];

}

void CC1125_Cfg(_CC1125 *Device){

  // Rf settings for CC1125
  // Address Config = No address check
  // Bit Rate = 38
  // Carrier Frequency = 918.000000
  // Deviation = 25.024414
  // Device Address = 0
  // Manchester Enable = false
  // Modulation Format = 2-FSK
  // PA Ramping = true
  // Packet Bit Length = 0
  // Packet Length = 255
  // Packet Length Mode = Variable
  // Performance Mode = High Performance
  // RX Filter BW = 100.000000
  // Symbol rate = 38
  // TX Power = -6
  // Whitening = false
     CC1125_Reg(0x0000, 0x73, Device);  // IOCFG3
     CC1125_Reg(0x0001, 0x33, Device);  // IOCFG2
     CC1125_Reg(0x0003, 0x07, Device);  // IOCFG0
     CC1125_Reg(0x0008, 0x0B, Device);  // SYNC_CFG1
     CC1125_Reg(0x000A, 0x9A, Device);  // DEVIATION_M
     CC1125_Reg(0x000B, 0x05, Device);  // MODCFG_DEV_E
     CC1125_Reg(0x000C, 0x1C, Device);  // DCFILT_CFG
     CC1125_Reg(0x0010, 0x46, Device);  // IQIC
     CC1125_Reg(0x0011, 0x02, Device);  // CHAN_BW
     CC1125_Reg(0x0013, 0x05, Device);  // MDMCFG0
     CC1125_Reg(0x0014, 0x93, Device);  // SYMBOL_RATE2
     CC1125_Reg(0x0015, 0x74, Device);  // SYMBOL_RATE1
     CC1125_Reg(0x0016, 0xBC, Device);  // SYMBOL_RATE0
     CC1125_Reg(0x0017, 0x20, Device);  // AGC_REF
     CC1125_Reg(0x0018, 0x19, Device);  // AGC_CS_THR
     CC1125_Reg(0x001C, 0xA9, Device);  // AGC_CFG1
     CC1125_Reg(0x001D, 0xCF, Device);  // AGC_CFG0
     CC1125_Reg(0x0021, 0x12, Device);  // FS_CFG
     CC1125_Reg(0x0028, 0x20, Device);  // PKT_CFG0
     CC1125_Reg(0x002B, 0x4F, Device);  // PA_CFG2
     CC1125_Reg(0x002D, 0x7B, Device);  // PA_CFG0
     CC1125_Reg(0x002E, 0xFF, Device);  // PKT_LEN
     CC1125_Reg(0x2F00, 0x00, Device);  // IF_MIX_CFG
     CC1125_Reg(0x2F01, 0x22, Device);  // FREQOFF_CFG
     CC1125_Reg(0x2F0C, 0x72, Device);  // FREQ2
     CC1125_Reg(0x2F0D, 0xC0, Device);  // FREQ1
     CC1125_Reg(0x2F12, 0x00, Device);  // FS_DIG1
     CC1125_Reg(0x2F13, 0x5F, Device);  // FS_DIG0
     CC1125_Reg(0x2F17, 0x0E, Device);  // FS_CAL0
     CC1125_Reg(0x2F19, 0x03, Device);  // FS_DIVTWO
     CC1125_Reg(0x2F1B, 0x33, Device);  // FS_DSM0
     CC1125_Reg(0x2F1D, 0x17, Device);  // FS_DVC0
     CC1125_Reg(0x2F1F, 0x50, Device);  // FS_PFD
     CC1125_Reg(0x2F20, 0x6E, Device);  // FS_PRE
     CC1125_Reg(0x2F21, 0x14, Device);  // FS_REG_DIV_CML
     CC1125_Reg(0x2F22, 0xAC, Device);  // FS_SPARE
     CC1125_Reg(0x2F32, 0x0E, Device);  // XOSC5
     CC1125_Reg(0x2F34, 0xC7, Device);  // XOSC3
     CC1125_Reg(0x2F36, 0x07, Device);  // XOSC1

}
//  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_RESET);
//
//  HAL_SPI_Transmit(Device->spi, rfSettings_low, 48, 0xFFFF);
//
//  //Push CS pin high
//  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_SET);
//
//  HAL_Delay(1);
//
//  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_RESET);
//
//  HAL_SPI_Transmit(Device->spi, rfSettings_high, 58, 0xFFFF);
//
//  //Push CS pin high
//  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_SET);
//}
//
//
//
//uint8_t rfSettings_low[48] = {
//    0x40,  //Starts a burst write to 0x00 of the regular addr space
//
//    //Paste IOCFG3 through PKT_LEN settings below
//    0x73,  // IOCFG3
//    0x33,  // IOCFG2
//    0x30,  // IOCFG1
//    0x30,  // IOCFG0
//    0x93,  // SYNC3
//    0x0B,  // SYNC2
//    0x51,  // SYNC1
//    0xDE,  // SYNC0
//    0x0B,  // SYNC_CFG1
//    0x17,  // SYNC_CFG0
//    0xA3,  // DEVIATION_M
//    0x02,  // MODCFG_DEV_E
//    0x1C,  // DCFILT_CFG
//    0x14,  // PREAMBLE_CFG1
//    0x2A,  // PREAMBLE_CFG0
//    0x33,  // FREQ_IF_CFG
//    0xC6,  // IQIC
//    0x19,  // CHAN_BW
//    0x46,  // MDMCFG1
//    0x05,  // MDMCFG0
//    0x3F,  // SYMBOL_RATE2
//    0x75,  // SYMBOL_RATE1
//    0x10,  // SYMBOL_RATE0
//    0x20,  // AGC_REF
//    0x19,  // AGC_CS_THR
//    0x00,  // AGC_GAIN_ADJUST
//    0x91,  // AGC_CFG3
//    0x20,  // AGC_CFG2
//    0xA9,  // AGC_CFG1
//    0xCF,  // AGC_CFG0
//    0x00,  // FIFO_CFG
//    0x00,  // DEV_ADDR
//    0x0B,  // SETTLING_CFG
//    0x12,  // FS_CFG
//    0x08,  // WOR_CFG1
//    0x21,  // WOR_CFG0
//    0x00,  // WOR_EVENT0_MSB
//    0x00,  // WOR_EVENT0_LSB
//    0x04,  // PKT_CFG2
//    0x05,  // PKT_CFG1
//    0x20,  // PKT_CFG0
//    0x0F,  // RFEND_CFG1
//    0x00,  // RFEND_CFG0
//    0x43,  // PA_CFG2
//    0x56,  // PA_CFG1
//    0x7C,  // PA_CFG0
//    0xFF  // PKT_LEN
//  };
//
//  uint8_t rfSettings_high[58] = {
//    0x6F,
//    0x00,  //These first two bytes start a burst write to extended addr 0x00
//
//    //paste extended regs IF_MIX_CFG through FIFO_NUM_RXBTES here
//    //DO NOT PASTE ABOVE
//    0x00,  // IF_MIX_CFG
//    0x22,  // FREQOFF_CFG
//    0x0B,  // TOC_CFG
//    0x00,  // MARC_SPARE
//    0x00,  // ECG_CFG
//    0x00,  // CFM_DATA_CFG
//    0x01,  // EXT_CTRL
//    0x00,  // RCCAL_FINE
//    0x00,  // RCCAL_COARSE
//    0x00,  // RCCAL_OFFSET
//    0x00,  // FREQOFF1
//    0x00,  // FREQOFF0
//    0x5B,  // FREQ2
//    0x80,  // FREQ1
//    0x00,  // FREQ0
//    0x02,  // IF_ADC2
//    0xA6,  // IF_ADC1
//    0x05,  // IF_ADC0
//    0x00,  // FS_DIG1
//    0x5F,  // FS_DIG0
//    0x00,  // FS_CAL3
//    0x20,  // FS_CAL2
//    0x00,  // FS_CAL1
//    0x0E,  // FS_CAL0
//    0x28,  // FS_CHP
//    0x03,  // FS_DIVTWO
//    0x00,  // FS_DSM1
//    0x33,  // FS_DSM0
//    0xFF,  // FS_DVC1
//    0x17,  // FS_DVC0
//    0x00,  // FS_LBI
//    0x50,  // FS_PFD
//    0x6E,  // FS_PRE
//    0x14,  // FS_REG_DIV_CML
//    0xAC,  // FS_SPARE
//    0x14,  // FS_VCO4
//    0x00,  // FS_VCO3
//    0x00,  // FS_VCO2
//    0x00,  // FS_VCO1
//    0x81,  // FS_VCO0
//    0x00,  // GBIAS6
//    0x02,  // GBIAS5
//    0x00,  // GBIAS4
//    0x00,  // GBIAS3
//    0x10,  // GBIAS2
//    0x00,  // GBIAS1
//    0x00,  // GBIAS0
//    0x01,  // IFAMP
//    0x01,  // LNA
//    0x01,  // RXMIX
//    0x0E,  // XOSC5
//    0xA0,  // XOSC4
//    0xC7,  // XOSC3
//    0x04,  // XOSC2
//    0x07,  // XOSC1
//    0x00  // XOSC0
//  };
//
//  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_RESET);
//
//  HAL_SPI_Transmit(Device->spi, rfSettings_low, 48, 0xFFFF);
//
//  //Push CS pin high
//  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_SET);
//
//  HAL_Delay(1);
//
//  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_RESET);
//
//  HAL_SPI_Transmit(Device->spi, rfSettings_high, 58, 0xFFFF);
//
//  //Push CS pin high
//  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_SET);
