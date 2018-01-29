import serial
import sys
ser =serial.Serial("COM11", baudrate=115200, timeout=3)
ser.write(b'pf 0  \r')
file = open("log.csv", "w+")
for n in range(500):
	file.write(((str(ser.readline().decode('ascii')))).rstrip('\n'))
ser.close()