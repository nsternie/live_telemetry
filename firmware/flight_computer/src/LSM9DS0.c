#include <LSM9DS0.h>


uint8_t LSM9DS0_Config(_LSM9DS0 *Device){
  uint8_t pTxData[3] = {0, 0, 0};
  uint8_t pRxData[3] = {0, 0, 0};

  pTxData[0] = 0b10001111;

  //Verify who_am_i register for accel
  HAL_GPIO_WritePin(Accel_Port, Accel_Pin, RESET);
  HAL_SPI_TransmitReceive(Device->spi, pTxData, pRxData, 2, 0xFFFF);
  HAL_GPIO_WritePin(Accel_Port, Accel_Pin, SET);
  if(pRxData[1] != 0b11010100) return 2;

  //Verify who_am_i register for mag
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, RESET);
  HAL_SPI_TransmitReceive(Device->spi, pTxData, pRxData, 2, 0xFFFF);
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, SET);
  if(pRxData[1] != 0b01001001) return 3;

  pTxData[0] = 0b00100000;
  pTxData[1] = 0b01010111;

  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, RESET);
  HAL_SPI_TransmitReceive(Device->spi, pTxData, pRxData, 2, 0xFFFF);
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, SET);
  return 1;
}

int16_t LSM9DS0_ReadAccel(_LSM9DS0 *Device){
  uint8_t pTxData[3] = {0, 0, 0};
  uint8_t pRxData[3] = {0, 0, 0};
  int16_t temp = 0;

  pTxData[0] = 0b11101000;
  pRxData[0] = 0;
  pRxData[1] = 0;
  pRxData[2] = 0;

  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, RESET);
  HAL_SPI_TransmitReceive(Device->spi, pTxData, pRxData, 3, 0xFFFF);
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, SET);

  temp = (pRxData[2] << 8) | pRxData[1];
  return 1;
}

int16_t LSM9DS0_ReadAccelXYZ(int16_t* accelData, _LSM9DS0 *Device){
  uint8_t pTxData[7] = {0, 0, 0, 0, 0, 0, 0};
  uint8_t pRxData[7] = {0, 0, 0, 0, 0, 0, 0};

  pTxData[0] = 0b11101000;

  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, RESET);
  HAL_SPI_TransmitReceive(Device->spi, pTxData, pRxData, 7, 0xFFFF);
  HAL_GPIO_WritePin(Device->CS_Port, Device->Pin, SET);

  accelData[0] = (pRxData[2] << 8) | pRxData[1];  //X data
  accelData[1] = (pRxData[4] << 8) | pRxData[3];  //Y data
  accelData[2] = (pRxData[6] << 8) | pRxData[5];  //Z data

  return 1;
}
