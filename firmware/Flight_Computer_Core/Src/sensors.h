/*
 * sensors.h
 *
 *  Created on: Jan 12, 2018
 *      Author: Nick Sterenberg
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
  uint16_t prom[6];
  uint8_t D1_OSR;
  uint8_t D2_OSR;
  uint32_t D1;
  uint32_t D2;
  float fs_range;
  int32_t sample_time;
} baro;

void init_gyros(void);
void test_gyros(void);
void read_gyro(gyro *g);

void init_accel(void);
void test_accel(void);
void read_accel(accel *a);

void init_baro(baro *b);
void D1_conv_baro(baro *b);
void D2_conv_baro(baro *b);
void read_D1_baro(baro *b);
void read_D2_baro(baro *b);
void conv_pres_baro(baro *b);

#endif /* SENSORS_H_ */
