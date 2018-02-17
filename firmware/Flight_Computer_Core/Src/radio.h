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
#define RADIO_TRANSMITTING 1
#define RADIO_REC 2
#define RADIO_IDLE 3

void init_radio(void);
uint8_t radio_readRSSI(void);
uint8_t radio_readStatus(void);
uint8_t radio_initInterrupt(void);
uint8_t radio_clearInterrupt(void);
uint8_t radio_txPacket(uint8_t* packet);
uint8_t radio_rxPacket(uint8_t* packet);
uint8_t radio_resetFIFO(void);
uint8_t radio_checkMAC(void);
uint8_t radio_readInterrupt(void);
void radio_RXMode(void);

#endif /* RADIO_H_ */
