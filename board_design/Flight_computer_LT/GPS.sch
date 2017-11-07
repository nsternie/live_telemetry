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
Sheet 8 8
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
L UBLOX-M8N U?
U 1 1 59FFF26A
P 5050 2400
F 0 "U?" H 5100 2450 60  0000 C CNN
F 1 "UBLOX-M8N" H 5350 850 60  0000 C CNN
F 2 "" H 5500 2700 60  0001 C CNN
F 3 "" H 5500 2700 60  0001 C CNN
	1    5050 2400
	1    0    0    -1  
$EndComp
Text GLabel 8050 3800 2    57   UnSpc ~ 0
GND
NoConn ~ 6350 3350
NoConn ~ 6350 3250
NoConn ~ 6350 3150
NoConn ~ 6350 2600
NoConn ~ 6350 2500
Text GLabel 4700 2750 0    57   UnSpc ~ 0
GND
Text GLabel 4700 2500 0    57   UnSpc ~ 0
3V3
NoConn ~ 4850 2950
NoConn ~ 4850 3050
NoConn ~ 6350 3000
NoConn ~ 4850 3300
NoConn ~ 4850 3400
NoConn ~ 4850 3500
NoConn ~ 4850 3600
Text GLabel 4700 3700 0    57   Output ~ 0
USART_RX1
Text GLabel 4700 3800 0    57   Input ~ 0
USART_TX1
Wire Wire Line
	6350 3500 6400 3500
Wire Wire Line
	6400 3500 6400 3800
Wire Wire Line
	6350 3800 8050 3800
Connection ~ 6400 3800
Wire Wire Line
	6350 3700 6400 3700
Connection ~ 6400 3700
Wire Wire Line
	6350 3600 6400 3600
Connection ~ 6400 3600
Wire Wire Line
	4850 2600 4800 2600
Wire Wire Line
	4800 2600 4800 2500
Wire Wire Line
	4700 2500 4850 2500
Connection ~ 4800 2500
Wire Wire Line
	4700 2750 4850 2750
Wire Wire Line
	4700 3700 4850 3700
Wire Wire Line
	4850 3800 4700 3800
Text GLabel 4700 3150 0    57   Input ~ 0
GPS_nRST
Wire Wire Line
	4700 3150 4850 3150
Wire Wire Line
	6350 2900 6600 2900
$Comp
L R R?
U 1 1 59FFFB4F
P 6750 2900
F 0 "R?" V 6830 2900 50  0000 C CNN
F 1 "10" V 6750 2900 50  0000 C CNN
F 2 "" V 6680 2900 50  0001 C CNN
F 3 "" H 6750 2900 50  0001 C CNN
	1    6750 2900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6900 2900 7250 2900
$Comp
L L L?
U 1 1 59FFFB90
P 7400 2900
F 0 "L?" V 7350 2900 50  0000 C CNN
F 1 "27nH" V 7475 2900 50  0000 C CNN
F 2 "" H 7400 2900 50  0001 C CNN
F 3 "" H 7400 2900 50  0001 C CNN
	1    7400 2900
	0    -1   -1   0   
$EndComp
$Comp
L C C?
U 1 1 59FFFBCF
P 7050 3100
F 0 "C?" H 7075 3200 50  0000 L CNN
F 1 "10nF" H 7075 3000 50  0000 L CNN
F 2 "" H 7088 2950 50  0001 C CNN
F 3 "" H 7050 3100 50  0001 C CNN
	1    7050 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 3250 7050 3800
Connection ~ 7050 3800
Wire Wire Line
	7050 2950 7050 2900
Connection ~ 7050 2900
Text Notes 2800 3800 0    57   ~ 0
NOTE: UART from view of uC
$Comp
L Conn_Coaxial J?
U 1 1 59FFFC85
P 7950 2750
F 0 "J?" H 7960 2870 50  0000 C CNN
F 1 "SMA_Edge" V 8065 2750 50  0000 C CNN
F 2 "" H 7950 2750 50  0001 C CNN
F 3 "" H 7950 2750 50  0001 C CNN
	1    7950 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 2750 7800 2750
Wire Wire Line
	7550 2900 7700 2900
Wire Wire Line
	7700 2900 7700 2750
Connection ~ 7700 2750
Wire Wire Line
	7950 3800 7950 2950
Connection ~ 7950 3800
Text Notes 6400 4300 0    57   ~ 0
LAYOUT: RF traces should be 50Ω\nLAYOUT: Shield GPS trace w/ vias\n
$EndSCHEMATC
