#include "ADXL357.h"

extern SPI_HandleTypeDef hspi2;

//initalize ADXL357 registers and interrupt
void ADXL357_Init(void){
  //Turn off standby mode and go to meas mode
  uint8_t pTxData[3] = {0, 0, 0};
  uint8_t pRxData[3] = {0, 0, 0};

  pTxData[0] = 0x2F << 1;
  pTxData[1] = 0x52;
  HAL_GPIO_WritePin(CS_ADXL_GPIO_Port, CS_ADXL_Pin, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(&hspi2, pTxData, pRxData, 2, 0xFFFF);
  HAL_GPIO_WritePin(CS_ADXL_GPIO_Port, CS_ADXL_Pin, GPIO_PIN_SET);

  HAL_Delay(100);

  pTxData[0] = 0x2D << 1;
  pTxData[1] = 0x00;
  HAL_GPIO_WritePin(CS_ADXL_GPIO_Port, CS_ADXL_Pin, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(&hspi2, pTxData, pRxData, 2, 0xFFFF);
  HAL_GPIO_WritePin(CS_ADXL_GPIO_Port, CS_ADXL_Pin, GPIO_PIN_SET);
}
