#include <MS5607.h>

int MS5607_Cmd(uint8_t *Data, _MS5607 *Device){
  //Pull CS pin low
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_RESET);

  //Transmit cmd to CC1125 over SPI
  //If need to optimize, HAL can be replaced with low level spi implementation.
  HAL_SPI_Transmit(Device->spi, Data, 1, 0xFFFF);

  //Push CS pin high
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_SET);

  return 1;
}

//Loads configuration parameters from memory and stores them in the Device struct
int MS5607_PROM(_MS5607 *Device){

  uint8_t pTxData[3] = {0, 0, 0};
  uint8_t pRxData[3] = {0, 0, 0};

  pTxData[0] = MFG;

  //MFG Config
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(Device->spi, pTxData, pRxData, 3, 0xFFFF);
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_SET);
  HAL_Delay(1);
  Device->CFC[0]=(pRxData[1] << 8) | (pRxData[2] & 0xFF);


  //C1
  pTxData[0] = CFC1;
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(Device->spi, pTxData, pRxData, 3, 0xFFFF);
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_SET);
  HAL_Delay(1);
  Device->CFC[1]=(pRxData[1] << 8) | (pRxData[2] & 0xFF);

  //C2
  pTxData[0] = CFC2;
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(Device->spi, pTxData, pRxData, 3, 0xFFFF);
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_SET);
  HAL_Delay(1);
  Device->CFC[2]=(pRxData[1] << 8) | (pRxData[2] & 0xFF);

  //C3
  pTxData[0] = CFC3;
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(Device->spi, pTxData, pRxData, 3, 0xFFFF);
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_SET);
  HAL_Delay(1);
  Device->CFC[3]=(pRxData[1] << 8) | (pRxData[2] & 0xFF);

  //C4
  pTxData[0] = CFC4;
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(Device->spi, pTxData, pRxData, 3, 0xFFFF);
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_SET);
  HAL_Delay(1);
  Device->CFC[4]=(pRxData[1] << 8) | (pRxData[2] & 0xFF);

  //C5
  pTxData[0] = CFC5;
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(Device->spi, pTxData, pRxData, 3, 0xFFFF);
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_SET);
  HAL_Delay(1);
  Device->CFC[5]=(pRxData[1] << 8) | (pRxData[2] & 0xFF);

  //C6
  pTxData[0] = CFC6;
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(Device->spi, pTxData, pRxData, 3, 0xFFFF);
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_SET);
  HAL_Delay(1);
  Device->CFC[6]=(pRxData[1] << 8) | (pRxData[2] & 0xFF);

  //CRC
  pTxData[0] = MS5607_CRC;
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(Device->spi, pTxData, pRxData, 3, 0xFFFF);
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_SET);
  HAL_Delay(1);
  Device->CFC[7]=(pRxData[1] << 8) | (pRxData[2] & 0xFF);

  return 1;
}

//Sends reset cmd to device (should delay be added here?)
void MS5607_Rst(_MS5607 *Device){

  //Set reset and send Cmd
  uint8_t Reset = MS_RESET;
  MS5607_Cmd(&Reset, Device);
  //Wait for device to finish reset
  HAL_Delay(100);
}

//Sends temp conversion cmd to baro. Basically tells the baro's adc to record
//the current temp value and store it in the baros flash so we can read it later.
void MS5607_ConvD1(_MS5607 *Device){

  //Send conversion cmd to baro
  uint8_t Cmd = CVT_D1 + Conv_Offset;
  MS5607_Cmd(&Cmd, Device);
}

//Sends pres. conversion cmd to baro. Tells the baro's adc to record pressure.
void MS5607_ConvD2(_MS5607 *Device){

  //Send conversion cmd to baro. This comment is not helpful.
  uint8_t Cmd = CVT_D2 + Conv_Offset;
  MS5607_Cmd(&Cmd, Device);
}

//Reads the value in the baro's adc. Need to send conversion cmd before calling
//this function. Can read out D1 or D2 depending on last conversion cmd sent.
uint32_t MS5607_ReadADC(_MS5607 *Device){

  uint8_t pTxData[4] = {0, 0, 0, 0};
  uint8_t pRxData[4] = {0, 0, 0, 0};

  pTxData[0] = ADC_READ;

  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(Device->spi, pTxData, pRxData, 4, 0xFFFF);
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, GPIO_PIN_SET);

  return ((pRxData[1] << 16) | (pRxData[2] << 8) | (pRxData[3]));
}

//Calculates temp based on D2 reading.
int32_t MS5607_CalcTemp(uint32_t D2, _MS5607 *Device){

  int32_t temp;
  int64_t intVar, dT;

  dT = D2 - ((Device->CFC[5])*(256));
  intVar = dT * (Device->CFC[6]); //I am so sorry for this variable name...
  temp = 2000 + intVar/(8388608);

  return temp;
}

//Calculate pressure, which requires D1 and D2. Note that this does not require
//calling CalcTemp. i.e. you can call this without finding temp first.
int32_t MS5607_CalcPres(uint32_t D1, uint32_t D2, _MS5607 *Device){

  int64_t OFF, SENS, dT;
  int64_t P, intVal;

  dT = D2 - ((Device->CFC[5])*(256));
  OFF = (((int64_t)Device->CFC[2]) * (131072)) + ((((int64_t)Device->CFC[4]) * dT)/(64));
  SENS = ((int64_t)Device->CFC[1]) * (65536) + (((int64_t)Device->CFC[3]) * dT)/(128);
  intVal = (D1 * SENS)/(2097152);
  P = (intVal - OFF)/(32768);

  return P;
}
