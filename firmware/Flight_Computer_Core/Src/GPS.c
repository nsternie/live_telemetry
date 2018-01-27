/*
 * GPS.c
 *
 *  Created on: Jan 27, 2018
 *      Author: Devin Salbert
 */

#include "minmea.h"


//read GPS into UART3


//into buffer

struct minmea_sentence_gga parsed;

float latitude, longitude;

//parse buffer, only care about GGA/fix data
//{latitude, longitude} parse_gps(){
//	bool check = minmea_parse_gga(&parsed /*where it stores new*/, &sentence /*nmea sentence*/);
//	if (!check)
//		//boop
//	else
//		latitude = minmea_float(parsed.latitude); //this function minmea_float() may not exist
//		longitude = minmea_float(parsed.longitude); //this function minmea_float() may not exist
//		return {latitude, longitude};
//}


