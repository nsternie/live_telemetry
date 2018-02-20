//#include <PacketSerial.h>
#include <stdint.h>
#include <stddef.h>

//#define FinishBlock(X) (*code_ptr = X, code_ptr = dst++, code = 0x01)
#define LENGTH 23

uint16_t packetNumber = 0;
uint8_t packetType = 0;
float gpsLat;
float gpsLong;
float latitude = 42.293309;
float longitude = -83.710903;
float range = 0.0002;
uint16_t maxAlt = 12000;
unsigned long lastTime;

typedef union {
  float f;
  char bytes[4];
} fVal;

void stuff_telem(uint8_t *unstuffed, uint8_t *stuffed){
  const uint8_t *end = unstuffed + LENGTH;
  uint8_t *code_ptr = stuffed++;
  uint8_t code = 0x01;

  while (unstuffed < end){
    if (*unstuffed == '\n') {
      *code_ptr = code;
      code_ptr = stuffed++;
      code = 0x01;
    }
    else {
      *stuffed++ = *unstuffed;
      if (++code == 0xFF){
        *code_ptr = code;
        code_ptr = stuffed++;
        code = 0x01;
      }
    }
    unstuffed++;
  }
  *stuffed = '\n';

  *code_ptr = code;
  code_ptr = stuffed++;
  code = 0x01;
}

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (millis() - lastTime >= 200UL) {
    float gpsLat = latitude - range + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(range)));
    float gpsLong = longitude - range + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(range)));
    uint16_t baro = uint16_t(abs(12000 * sin(packetNumber*3.14/100)));
    uint8_t rssi = uint8_t(abs(255 * sin(packetNumber*3.14/100)));
    
    int16_t gyroZ = int16_t(242);
    int16_t accelVel = int16_t(-102);
    int32_t accelZ = int32_t(9.81*10);

    uint8_t unstuffedPacket[LENGTH];
    uint8_t *dst = &unstuffedPacket[0];
    uint8_t stuffedPacket[LENGTH+2];

    fVal gpsLongUnion;
    gpsLongUnion.f = gpsLong;

    fVal gpsLatUnion;
    gpsLatUnion.f = gpsLat;

    *dst = packetType >> 0;
    *(dst+1) = packetNumber >> 0;
    *(dst+2) = packetNumber >> 8;
    *(dst+3) = gpsLatUnion.bytes[0];
    *(dst+4) = gpsLatUnion.bytes[1];
    *(dst+5) = gpsLatUnion.bytes[2];
    *(dst+6) = gpsLatUnion.bytes[3];
    *(dst+7) = gpsLongUnion.bytes[0];
    *(dst+8) = gpsLongUnion.bytes[1];
    *(dst+9) = gpsLongUnion.bytes[2];
    *(dst+10) = gpsLongUnion.bytes[3];
    *(dst+11) = baro >> 0;
    *(dst+12) = baro >> 8;
    *(dst+13) = maxAlt >> 0;
    *(dst+14) = maxAlt >> 8;
    *(dst+15) = gyroZ >> 0;
    *(dst+16) = gyroZ >> 8;
    *(dst+17) = accelVel >> 0;
    *(dst+18) = accelVel >> 8;
    *(dst+19) = accelZ >> 0;
    *(dst+20) = accelZ >> 8;
    *(dst+21) = accelZ >> 16;
    *(dst+22) = rssi >> 0;

    stuff_telem(unstuffedPacket, stuffedPacket);

    packetNumber++;
    for (int i=0; i < LENGTH+2; i++) {
      Serial.write(stuffedPacket[i]);
    }
    //Serial.print('\n');
    lastTime += 200UL;
  }

}
