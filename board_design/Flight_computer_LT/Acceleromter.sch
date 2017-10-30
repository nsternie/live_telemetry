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
Sheet 4 7
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
L ADXL357 U?
U 1 1 59F6CEC7
P 4500 2900
F 0 "U?" H 4550 2950 60  0000 C CNN
F 1 "ADXL357" H 4850 1950 60  0000 C CNN
F 2 "" H 5050 3250 60  0001 C CNN
F 3 "" H 5050 3250 60  0001 C CNN
	1    4500 2900
	1    0    0    -1  
$EndComp
Text GLabel 4200 3000 0    57   Input ~ 0
CS_ADXL
Text GLabel 4200 3100 0    57   Input ~ 0
SCK1
Text GLabel 4200 3200 0    57   Input ~ 0
MOSI1
Text GLabel 4200 3300 0    57   Output ~ 0
MISO1
Text GLabel 4200 3700 0    57   Output ~ 0
DRDY_ADXL
Wire Wire Line
	4200 3000 4300 3000
Wire Wire Line
	4200 3100 4300 3100
Wire Wire Line
	4200 3200 4300 3200
Wire Wire Line
	4200 3300 4300 3300
Wire Wire Line
	4200 3700 4300 3700
Wire Wire Line
	5350 3600 5400 3600
Wire Wire Line
	5400 3600 5400 3700
Wire Wire Line
	5350 3700 7900 3700
Connection ~ 5400 3700
Text GLabel 7900 3700 2    57   UnSpc ~ 0
GND
NoConn ~ 5350 3450
$Comp
L C C?
U 1 1 59F6D134
P 5550 3500
F 0 "C?" H 5575 3600 50  0000 L CNN
F 1 "100nF" H 5575 3400 50  0000 L CNN
F 2 "" H 5588 3350 50  0001 C CNN
F 3 "" H 5550 3500 50  0001 C CNN
	1    5550 3500
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 59F6D18B
P 5850 3500
F 0 "C?" H 5875 3600 50  0000 L CNN
F 1 "1uF" H 5875 3400 50  0000 L CNN
F 2 "" H 5888 3350 50  0001 C CNN
F 3 "" H 5850 3500 50  0001 C CNN
	1    5850 3500
	1    0    0    -1  
$EndComp
Connection ~ 5550 3700
Connection ~ 5850 3700
$Comp
L C C?
U 1 1 59F6D208
P 6150 3500
F 0 "C?" H 6175 3600 50  0000 L CNN
F 1 "100nF" H 6175 3400 50  0000 L CNN
F 2 "" H 6188 3350 50  0001 C CNN
F 3 "" H 6150 3500 50  0001 C CNN
	1    6150 3500
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 59F6D240
P 6450 3500
F 0 "C?" H 6475 3600 50  0000 L CNN
F 1 "1uF" H 6475 3400 50  0000 L CNN
F 2 "" H 6488 3350 50  0001 C CNN
F 3 "" H 6450 3500 50  0001 C CNN
	1    6450 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 3200 6150 3350
Connection ~ 6150 3200
Connection ~ 6150 3700
Wire Wire Line
	5350 3300 5850 3300
Connection ~ 5550 3300
Wire Wire Line
	5550 3700 5550 3650
Wire Wire Line
	5850 3300 5850 3350
Wire Wire Line
	5550 3350 5550 3300
Wire Wire Line
	5850 3700 5850 3650
Wire Wire Line
	6150 3700 6150 3650
$Comp
L C C?
U 1 1 59F6D5BD
P 6750 3500
F 0 "C?" H 6775 3600 50  0000 L CNN
F 1 "100nF" H 6775 3400 50  0000 L CNN
F 2 "" H 6788 3350 50  0001 C CNN
F 3 "" H 6750 3500 50  0001 C CNN
	1    6750 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 3700 6450 3650
Connection ~ 6450 3700
Wire Wire Line
	6750 3650 6750 3700
Connection ~ 6750 3700
Wire Wire Line
	5350 3200 6450 3200
Wire Wire Line
	6450 3200 6450 3350
Wire Wire Line
	6750 3350 6750 3100
Wire Wire Line
	5350 3100 7900 3100
Wire Wire Line
	5350 3000 5400 3000
Wire Wire Line
	5400 3000 5400 3100
Connection ~ 5400 3100
$Comp
L C C?
U 1 1 59F6D74F
P 7050 3500
F 0 "C?" H 7075 3600 50  0000 L CNN
F 1 "1uF" H 7075 3400 50  0000 L CNN
F 2 "" H 7088 3350 50  0001 C CNN
F 3 "" H 7050 3500 50  0001 C CNN
	1    7050 3500
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 59F6D78C
P 7350 3500
F 0 "C?" H 7375 3600 50  0000 L CNN
F 1 "100nF" H 7375 3400 50  0000 L CNN
F 2 "" H 7388 3350 50  0001 C CNN
F 3 "" H 7350 3500 50  0001 C CNN
	1    7350 3500
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 59F6D7C8
P 7650 3500
F 0 "C?" H 7675 3600 50  0000 L CNN
F 1 "1uF" H 7675 3400 50  0000 L CNN
F 2 "" H 7688 3350 50  0001 C CNN
F 3 "" H 7650 3500 50  0001 C CNN
	1    7650 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 3100 7050 3350
Connection ~ 6750 3100
Wire Wire Line
	7350 3100 7350 3350
Connection ~ 7050 3100
Wire Wire Line
	7650 3100 7650 3350
Connection ~ 7350 3100
Wire Wire Line
	7650 3700 7650 3650
Wire Wire Line
	7350 3650 7350 3700
Connection ~ 7350 3700
Wire Wire Line
	7050 3650 7050 3700
Connection ~ 7050 3700
Connection ~ 7650 3700
Text GLabel 7900 3100 2    57   UnSpc ~ 0
3V3
Connection ~ 7650 3100
Text Notes 5300 3950 0    57   ~ 0
LAYOUT: Each power pin gets 1 100nF and 1 1uF cap. Place close to device.
Text GLabel 4200 3500 0    57   Output ~ 0
INT1_ADXL
Wire Wire Line
	4200 3500 4300 3500
NoConn ~ 4300 3600
$EndSCHEMATC
