/*
 * radio.h
 *
 *  Created on: Jan 22, 2018
 *      Author: Lato
 */

#include <stdint.h>

#ifndef RADIO_H_
#define RADIO_H_

#define RADIO_PKT_LEN 22

void init_radio(void);
uint8_t radio_readRSSI(void);
uint8_t radio_readStatus(void);
uint8_t radio_initInterrupt(void);
uint8_t radio_clearInterrupt(void);
uint8_t radio_txPacket(uint8_t* packet);
uint8_t radio_rxPacket(uint8_t* packet);

#endif /* RADIO_H_ */
