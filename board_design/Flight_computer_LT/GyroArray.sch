EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:live_telem
LIBS:Flight_computer_LT-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 8
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L BMG250 U?
U 1 1 59F9462B
P 2700 1800
F 0 "U?" H 2750 1850 60  0000 C CNN
F 1 "BMG250" H 3000 750 60  0000 C CNN
F 2 "" H 3350 2200 60  0001 C CNN
F 3 "" H 3350 2200 60  0001 C CNN
	1    2700 1800
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 59F946CF
P 1650 2100
F 0 "C?" H 1675 2200 50  0000 L CNN
F 1 "100nF" H 1675 2000 50  0000 L CNN
F 2 "" H 1688 1950 50  0001 C CNN
F 3 "" H 1650 2100 50  0001 C CNN
	1    1650 2100
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 59F94710
P 1300 2100
F 0 "C?" H 1325 2200 50  0000 L CNN
F 1 "100nF" H 1325 2000 50  0000 L CNN
F 2 "" H 1338 1950 50  0001 C CNN
F 3 "" H 1300 2100 50  0001 C CNN
	1    1300 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 1900 2500 1900
Wire Wire Line
	2450 1900 2450 2000
Wire Wire Line
	2450 2000 2500 2000
Connection ~ 2450 1900
Text GLabel 1200 1900 0    57   UnSpc ~ 0
3V3
Wire Wire Line
	1650 2300 1650 2250
Wire Wire Line
	1200 2300 1650 2300
Wire Wire Line
	1300 2300 1300 2250
Connection ~ 1300 2300
Text GLabel 1200 2300 0    57   UnSpc ~ 0
GND
Wire Wire Line
	1300 1950 1300 1900
Connection ~ 1300 1900
Wire Wire Line
	1650 1950 1650 1900
Connection ~ 1650 1900
Wire Wire Line
	3450 2600 3500 2600
Wire Wire Line
	3500 2600 3500 2700
Wire Wire Line
	3450 2700 3550 2700
Connection ~ 3500 2700
Text GLabel 3550 2700 2    57   UnSpc ~ 0
GND
NoConn ~ 3450 1900
NoConn ~ 3450 2000
NoConn ~ 3450 2100
NoConn ~ 3450 2200
Text GLabel 2450 2150 0    57   Output ~ 0
MISO1
Text GLabel 2450 2250 0    57   Input ~ 0
CS_GYRO1
Wire Wire Line
	2450 2150 2500 2150
Wire Wire Line
	2450 2250 2500 2250
Text GLabel 2450 2350 0    57   Input ~ 0
SCLK1
Text GLabel 2450 2450 0    57   Input ~ 0
MOSI1
Text GLabel 2450 2600 0    57   Output ~ 0
GYRO1_INT
Wire Wire Line
	2450 2600 2500 2600
Wire Wire Line
	2450 2450 2500 2450
Wire Wire Line
	2450 2350 2500 2350
NoConn ~ 2500 2700
$Comp
L BMG250 U?
U 1 1 59F94A9D
P 5850 1850
F 0 "U?" H 5900 1900 60  0000 C CNN
F 1 "BMG250" H 6150 800 60  0000 C CNN
F 2 "" H 6500 2250 60  0001 C CNN
F 3 "" H 6500 2250 60  0001 C CNN
	1    5850 1850
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 59F94AA3
P 4800 2150
F 0 "C?" H 4825 2250 50  0000 L CNN
F 1 "100nF" H 4825 2050 50  0000 L CNN
F 2 "" H 4838 2000 50  0001 C CNN
F 3 "" H 4800 2150 50  0001 C CNN
	1    4800 2150
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 59F94AA9
P 4450 2150
F 0 "C?" H 4475 2250 50  0000 L CNN
F 1 "100nF" H 4475 2050 50  0000 L CNN
F 2 "" H 4488 2000 50  0001 C CNN
F 3 "" H 4450 2150 50  0001 C CNN
	1    4450 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 1950 5650 1950
Wire Wire Line
	5600 1950 5600 2050
Wire Wire Line
	5600 2050 5650 2050
Connection ~ 5600 1950
Text GLabel 4350 1950 0    57   UnSpc ~ 0
3V3
Wire Wire Line
	4800 2350 4800 2300
Wire Wire Line
	4350 2350 4800 2350
Wire Wire Line
	4450 2350 4450 2300
Connection ~ 4450 2350
Text GLabel 4350 2350 0    57   UnSpc ~ 0
GND
Wire Wire Line
	4450 2000 4450 1950
Connection ~ 4450 1950
Wire Wire Line
	4800 2000 4800 1950
Connection ~ 4800 1950
Wire Wire Line
	6600 2650 6650 2650
Wire Wire Line
	6650 2650 6650 2750
Wire Wire Line
	6600 2750 6700 2750
Connection ~ 6650 2750
Text GLabel 6700 2750 2    57   UnSpc ~ 0
GND
NoConn ~ 6600 1950
NoConn ~ 6600 2050
NoConn ~ 6600 2150
NoConn ~ 6600 2250
Text GLabel 5600 2200 0    57   Output ~ 0
MISO1
Text GLabel 5600 2300 0    57   Input ~ 0
CS_GYRO2
Wire Wire Line
	5600 2200 5650 2200
Wire Wire Line
	5600 2300 5650 2300
Text GLabel 5600 2400 0    57   Input ~ 0
SCLK1
Text GLabel 5600 2500 0    57   Input ~ 0
MOSI1
Text GLabel 5600 2650 0    57   Output ~ 0
GYRO2_INT
Wire Wire Line
	5600 2650 5650 2650
Wire Wire Line
	5600 2500 5650 2500
Wire Wire Line
	5600 2400 5650 2400
NoConn ~ 5650 2750
$Comp
L BMG250 U?
U 1 1 59F94BD8
P 8950 1850
F 0 "U?" H 9000 1900 60  0000 C CNN
F 1 "BMG250" H 9250 800 60  0000 C CNN
F 2 "" H 9600 2250 60  0001 C CNN
F 3 "" H 9600 2250 60  0001 C CNN
	1    8950 1850
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 59F94BDE
P 7900 2150
F 0 "C?" H 7925 2250 50  0000 L CNN
F 1 "100nF" H 7925 2050 50  0000 L CNN
F 2 "" H 7938 2000 50  0001 C CNN
F 3 "" H 7900 2150 50  0001 C CNN
	1    7900 2150
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 59F94BE4
P 7550 2150
F 0 "C?" H 7575 2250 50  0000 L CNN
F 1 "100nF" H 7575 2050 50  0000 L CNN
F 2 "" H 7588 2000 50  0001 C CNN
F 3 "" H 7550 2150 50  0001 C CNN
	1    7550 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 1950 8750 1950
Wire Wire Line
	8700 1950 8700 2050
Wire Wire Line
	8700 2050 8750 2050
Connection ~ 8700 1950
Text GLabel 7450 1950 0    57   UnSpc ~ 0
3V3
Wire Wire Line
	7900 2350 7900 2300
Wire Wire Line
	7450 2350 7900 2350
Wire Wire Line
	7550 2350 7550 2300
Connection ~ 7550 2350
Text GLabel 7450 2350 0    57   UnSpc ~ 0
GND
Wire Wire Line
	7550 2000 7550 1950
Connection ~ 7550 1950
Wire Wire Line
	7900 2000 7900 1950
Connection ~ 7900 1950
Wire Wire Line
	9700 2650 9750 2650
Wire Wire Line
	9750 2650 9750 2750
Wire Wire Line
	9700 2750 9800 2750
Connection ~ 9750 2750
Text GLabel 9800 2750 2    57   UnSpc ~ 0
GND
NoConn ~ 9700 1950
NoConn ~ 9700 2050
NoConn ~ 9700 2150
NoConn ~ 9700 2250
Text GLabel 8700 2200 0    57   Output ~ 0
MISO1
Text GLabel 8700 2300 0    57   Input ~ 0
CS_GYRO3
Wire Wire Line
	8700 2200 8750 2200
Wire Wire Line
	8700 2300 8750 2300
Text GLabel 8700 2400 0    57   Input ~ 0
SCLK1
Text GLabel 8700 2500 0    57   Input ~ 0
MOSI1
Text GLabel 8700 2650 0    57   Output ~ 0
GYRO3_INT
Wire Wire Line
	8700 2650 8750 2650
Wire Wire Line
	8700 2500 8750 2500
Wire Wire Line
	8700 2400 8750 2400
NoConn ~ 8750 2750
$Comp
L BMG250 U?
U 1 1 59F94D5A
P 2750 3650
F 0 "U?" H 2800 3700 60  0000 C CNN
F 1 "BMG250" H 3050 2600 60  0000 C CNN
F 2 "" H 3400 4050 60  0001 C CNN
F 3 "" H 3400 4050 60  0001 C CNN
	1    2750 3650
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 59F94D60
P 1700 3950
F 0 "C?" H 1725 4050 50  0000 L CNN
F 1 "100nF" H 1725 3850 50  0000 L CNN
F 2 "" H 1738 3800 50  0001 C CNN
F 3 "" H 1700 3950 50  0001 C CNN
	1    1700 3950
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 59F94D66
P 1350 3950
F 0 "C?" H 1375 4050 50  0000 L CNN
F 1 "100nF" H 1375 3850 50  0000 L CNN
F 2 "" H 1388 3800 50  0001 C CNN
F 3 "" H 1350 3950 50  0001 C CNN
	1    1350 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 3750 2550 3750
Wire Wire Line
	2500 3750 2500 3850
Wire Wire Line
	2500 3850 2550 3850
Connection ~ 2500 3750
Text GLabel 1250 3750 0    57   UnSpc ~ 0
3V3
Wire Wire Line
	1700 4150 1700 4100
Wire Wire Line
	1250 4150 1700 4150
Wire Wire Line
	1350 4150 1350 4100
Connection ~ 1350 4150
Text GLabel 1250 4150 0    57   UnSpc ~ 0
GND
Wire Wire Line
	1350 3800 1350 3750
Connection ~ 1350 3750
Wire Wire Line
	1700 3800 1700 3750
Connection ~ 1700 3750
Wire Wire Line
	3500 4450 3550 4450
Wire Wire Line
	3550 4450 3550 4550
Wire Wire Line
	3500 4550 3600 4550
Connection ~ 3550 4550
Text GLabel 3600 4550 2    57   UnSpc ~ 0
GND
NoConn ~ 3500 3750
NoConn ~ 3500 3850
NoConn ~ 3500 3950
NoConn ~ 3500 4050
Text GLabel 2500 4000 0    57   Output ~ 0
MISO1
Text GLabel 2500 4100 0    57   Input ~ 0
CS_GYRO4
Wire Wire Line
	2500 4000 2550 4000
Wire Wire Line
	2500 4100 2550 4100
Text GLabel 2500 4200 0    57   Input ~ 0
SCLK1
Text GLabel 2500 4300 0    57   Input ~ 0
MOSI1
Text GLabel 2500 4450 0    57   Output ~ 0
GYRO4_INT
Wire Wire Line
	2500 4450 2550 4450
Wire Wire Line
	2500 4300 2550 4300
Wire Wire Line
	2500 4200 2550 4200
NoConn ~ 2550 4550
$Comp
L BMG250 U?
U 1 1 59F94D8E
P 5900 3700
F 0 "U?" H 5950 3750 60  0000 C CNN
F 1 "BMG250" H 6200 2650 60  0000 C CNN
F 2 "" H 6550 4100 60  0001 C CNN
F 3 "" H 6550 4100 60  0001 C CNN
	1    5900 3700
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 59F94D94
P 4850 4000
F 0 "C?" H 4875 4100 50  0000 L CNN
F 1 "100nF" H 4875 3900 50  0000 L CNN
F 2 "" H 4888 3850 50  0001 C CNN
F 3 "" H 4850 4000 50  0001 C CNN
	1    4850 4000
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 59F94D9A
P 4500 4000
F 0 "C?" H 4525 4100 50  0000 L CNN
F 1 "100nF" H 4525 3900 50  0000 L CNN
F 2 "" H 4538 3850 50  0001 C CNN
F 3 "" H 4500 4000 50  0001 C CNN
	1    4500 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 3800 5700 3800
Wire Wire Line
	5650 3800 5650 3900
Wire Wire Line
	5650 3900 5700 3900
Connection ~ 5650 3800
Text GLabel 4400 3800 0    57   UnSpc ~ 0
3V3
Wire Wire Line
	4850 4200 4850 4150
Wire Wire Line
	4400 4200 4850 4200
Wire Wire Line
	4500 4200 4500 4150
Connection ~ 4500 4200
Text GLabel 4400 4200 0    57   UnSpc ~ 0
GND
Wire Wire Line
	4500 3850 4500 3800
Connection ~ 4500 3800
Wire Wire Line
	4850 3850 4850 3800
Connection ~ 4850 3800
Wire Wire Line
	6650 4500 6700 4500
Wire Wire Line
	6700 4500 6700 4600
Wire Wire Line
	6650 4600 6750 4600
Connection ~ 6700 4600
Text GLabel 6750 4600 2    57   UnSpc ~ 0
GND
NoConn ~ 6650 3800
NoConn ~ 6650 3900
NoConn ~ 6650 4000
NoConn ~ 6650 4100
Text GLabel 5650 4050 0    57   Output ~ 0
MISO1
Text GLabel 5650 4150 0    57   Input ~ 0
CS_GYRO5
Wire Wire Line
	5650 4050 5700 4050
Wire Wire Line
	5650 4150 5700 4150
Text GLabel 5650 4250 0    57   Input ~ 0
SCLK1
Text GLabel 5650 4350 0    57   Input ~ 0
MOSI1
Text GLabel 5650 4500 0    57   Output ~ 0
GYRO5_INT
Wire Wire Line
	5650 4500 5700 4500
Wire Wire Line
	5650 4350 5700 4350
Wire Wire Line
	5650 4250 5700 4250
NoConn ~ 5700 4600
$Comp
L BMG250 U?
U 1 1 59F94DC3
P 9000 3700
F 0 "U?" H 9050 3750 60  0000 C CNN
F 1 "BMG250" H 9300 2650 60  0000 C CNN
F 2 "" H 9650 4100 60  0001 C CNN
F 3 "" H 9650 4100 60  0001 C CNN
	1    9000 3700
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 59F94DC9
P 7950 4000
F 0 "C?" H 7975 4100 50  0000 L CNN
F 1 "100nF" H 7975 3900 50  0000 L CNN
F 2 "" H 7988 3850 50  0001 C CNN
F 3 "" H 7950 4000 50  0001 C CNN
	1    7950 4000
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 59F94DCF
P 7600 4000
F 0 "C?" H 7625 4100 50  0000 L CNN
F 1 "100nF" H 7625 3900 50  0000 L CNN
F 2 "" H 7638 3850 50  0001 C CNN
F 3 "" H 7600 4000 50  0001 C CNN
	1    7600 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 3800 8800 3800
Wire Wire Line
	8750 3800 8750 3900
Wire Wire Line
	8750 3900 8800 3900
Connection ~ 8750 3800
Text GLabel 7500 3800 0    57   UnSpc ~ 0
3V3
Wire Wire Line
	7950 4200 7950 4150
Wire Wire Line
	7500 4200 7950 4200
Wire Wire Line
	7600 4200 7600 4150
Connection ~ 7600 4200
Text GLabel 7500 4200 0    57   UnSpc ~ 0
GND
Wire Wire Line
	7600 3850 7600 3800
Connection ~ 7600 3800
Wire Wire Line
	7950 3850 7950 3800
Connection ~ 7950 3800
Wire Wire Line
	9750 4500 9800 4500
Wire Wire Line
	9800 4500 9800 4600
Wire Wire Line
	9750 4600 9850 4600
Connection ~ 9800 4600
Text GLabel 9850 4600 2    57   UnSpc ~ 0
GND
NoConn ~ 9750 3800
NoConn ~ 9750 3900
NoConn ~ 9750 4000
NoConn ~ 9750 4100
Text GLabel 8750 4050 0    57   Output ~ 0
MISO1
Text GLabel 8750 4150 0    57   Input ~ 0
CS_GYRO6
Wire Wire Line
	8750 4050 8800 4050
Wire Wire Line
	8750 4150 8800 4150
Text GLabel 8750 4250 0    57   Input ~ 0
SCLK1
Text GLabel 8750 4350 0    57   Input ~ 0
MOSI1
Text GLabel 8750 4500 0    57   Output ~ 0
GYRO6_INT
Wire Wire Line
	8750 4500 8800 4500
Wire Wire Line
	8750 4350 8800 4350
Wire Wire Line
	8750 4250 8800 4250
NoConn ~ 8800 4600
Text Notes 1450 5400 0    57   ~ 0
LAYOUT: Array should be consistant 2x3 or 3x2 with symmetric spacing between each element\n
Text Notes 1450 5500 0    57   ~ 0
DESIGN: Verify this many interrupts can be easily supported on uC side\n
$EndSCHEMATC
