/*
 * sensors.h
 *
 *  Created on: Jan 12, 2018
 *      Author: nicks
 */

#ifndef SENSORS_H_
#define SENSORS_H_

typedef struct gyrostruct{
  int16_t data[3];    // x, y, z, or just value in data[0]
  float fs_range;
  int32_t sample_time;
  uint8_t id;
} gyro;

typedef struct accelstruct{
  int32_t data[3];
  float fs_range;
  int32_t sample_time;
} accel;

typedef struct barostruct{
  int32_t data;
  float fs_range;
  int32_t sample_time;
} baro;


void read_gyro(gyro *g);
void read_accel(accel *a);
void read_bary(baro *b);

#endif /* SENSORS_H_ */
