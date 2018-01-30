import serial
ser =serial.Serial("COM11", baudrate=115200, timeout=10)
ser.write(b'dump \r')
file = open("log.txt", "w+")
for n in range(16):
	print("Block "+str(n)+" read...")
	file.write("\nBlock "+str(n)+"\t"+str(ser.read(2048)))
ser.close()