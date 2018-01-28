/*
 * GPS.h
 *
 *  Created on: Jan 27, 2018
 *      Author: Devin Salbert
 */

#ifndef GPS_H_
#define GPS_H_

#include "minmea.h"

typedef struct gps_datastruct{
	float time; // seconds
	float latitude; // decimal degrees
	float longitude; // decimal degrees
	int fix_quality;
	int sats_tracked;
	float hdop;
	float altitude; // meters, according to reference site
} gps_data;

// returns a struct with all the GPS data
void parse_gps(const char* sentence);

#endif /* GPS_H_ */
