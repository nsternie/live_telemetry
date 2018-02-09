/*
 * radio.h
 *
 *  Created on: Jan 22, 2018
 *      Author: Lato
 */

#include <stdint.h>

#ifndef RADIO_H_
#define RADIO_H_

void init_radio(void);
uint8_t radio_readRSSI(void);
uint8_t radio_readStatus(void);

#endif /* RADIO_H_ */
