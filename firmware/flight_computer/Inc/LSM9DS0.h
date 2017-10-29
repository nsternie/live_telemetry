#include "stm32f4xx_hal.h"

#ifndef LSM9DS0
#define LSM9DS0

#define Accel_Port GPIOA
#define Accel_Pin GPIO_PIN_1
#define Mag_Port GPIOA
#define Mag_Pin GPIO_PIN_0
#define HiAccel_Port GPIOA
#define HiAccel_Pin GPIO_PIN_3

typedef struct
{
  SPI_HandleTypeDef *spi;

  uint16_t Pin;

  GPIO_TypeDef *CS_Port;

}_LSM9DS0;

uint8_t LSM9DS0_Config(_LSM9DS0 *Device);
int16_t LSM9DS0_ReadAccel(_LSM9DS0 *Device);
int16_t LSM9DS0_ReadAccelXYZ(int16_t* accelData, _LSM9DS0 *Device);

#endif
