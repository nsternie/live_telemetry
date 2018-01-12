/*
 * data-structures.h
 *
 *  Created on: Jan 12, 2018
 *      Author: Nick Sterenberg
 */

#ifndef DATA_STRUCTURES_H_
#define DATA_STRUCTURES_H_

#define SENSOR_TYPE_GYRO    10
#define SENSOR_TYPE_ACCEL   11
#define SENSOR_TYPE_BARO    12


typedef struct sensor{
  int16_t data[3];    // x, y, z, or just value in data[0]
  float fs_range;
  int32_t sample_time;
  uint8_t sensor_type;
};


#endif /* DATA_STRUCTURES_H_ */
