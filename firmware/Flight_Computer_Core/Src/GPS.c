/*
 * GPS.c
 *
 *  Created on: Jan 27, 2018
 *      Author: Devin Salbert
 */

#include "GPS.h"
gps_data gps;

void parse_gps(const char* sentence){
	struct minmea_sentence_gga parsed;
	volatile uint8_t check = minmea_parse_gga(&parsed, sentence);

	//testing
	int buf[30];
	snprintf(buf, 30, "%d\n", check);

	if (check == 1){
		gps.time = (parsed.time.hours * 3600) + (parsed.time.minutes * 60) + parsed.time.seconds + (parsed.time.microseconds / 1000);

		int lat_deg = parsed.latitude.value / parsed.latitude.scale / 100;
		float lat_float = (float) parsed.latitude.value;
		float lat_temp = lat_float / parsed.latitude.scale / 100;
		float lat_min = (lat_temp - lat_deg) / 60 * 100;
		gps.latitude = lat_deg + lat_min;

		int long_deg = parsed.longitude.value / parsed.longitude.scale / 100;
		float long_float = (float) parsed.longitude.value;
		float long_temp = long_float / parsed.longitude.scale / 100;
		float long_min = (long_temp - long_deg) / 60 * 100;
		gps.longitude = long_deg + long_min;

		gps.fix_quality = parsed.fix_quality;
		gps.sats_tracked = parsed.satellites_tracked;

		float hdop_temp = (float) parsed.hdop.value;
		gps.hdop = hdop_temp / parsed.hdop.scale;

		float alt_temp = (float) parsed.altitude.value;
		gps.altitude = alt_temp / parsed.altitude.scale;
	}
}


