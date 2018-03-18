#include <stdint.h>

#ifndef SX1280_H_
#define SX1280_H_

#define RADIO_PKT_LEN 22

#define START_LOG 1
#define STOP_LOG 2
#define CLEAR_FILE_SYS 3

void init_radio(void);
uint8_t radio_txPacket(uint8_t* packet);
uint8_t radio_clearInterrupt(void);
void radio_RXMode(void);
void radio_getPktStatus(void);
void radio_getRXBufferStatus(void);
uint8_t radio_rxPacket(uint8_t* packet);

uint8_t radio_readRSSI(void);
uint8_t radio_readStatus(void);
uint8_t radio_checkMAC(void);
uint8_t radio_readInterrupt(void);
void radio_IDLEMode(void);
uint8_t radio_initAntennaDiv(void);
uint8_t radio_checkRxPkt(void);


#endif /* RADIO_H_ */
