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
Sheet 7 8
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
L L7805 U17
U 1 1 59FF775F
P 5950 2350
F 0 "U17" H 5800 2475 50  0000 C CNN
F 1 "L7805" H 5950 2475 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:TO-252-3_TabPin2" H 5975 2200 50  0001 L CIN
F 3 "" H 5950 2300 50  0001 C CNN
	1    5950 2350
	1    0    0    -1  
$EndComp
$Comp
L C C74
U 1 1 59FF7809
P 5400 2550
F 0 "C74" H 5425 2650 50  0000 L CNN
F 1 "1uF" H 5425 2450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5438 2400 50  0001 C CNN
F 3 "" H 5400 2550 50  0001 C CNN
	1    5400 2550
	1    0    0    -1  
$EndComp
Text GLabel 5100 2350 0    57   UnSpc ~ 0
VIN
Text GLabel 7450 2150 2    57   UnSpc ~ 0
5V
Text GLabel 7400 2900 2    57   UnSpc ~ 0
GND
$Comp
L MIC5219-3.3 U18
U 1 1 59FF7D18
P 6000 4150
F 0 "U18" H 5850 4375 50  0000 C CNN
F 1 "MIC5219-3.3" H 6000 4375 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-5" H 6000 4475 50  0001 C CNN
F 3 "" H 6000 4150 50  0001 C CNN
	1    6000 4150
	1    0    0    -1  
$EndComp
Text GLabel 5150 4050 0    57   UnSpc ~ 0
VIN
$Comp
L C C75
U 1 1 59FF7D99
P 5400 4250
F 0 "C75" H 5425 4350 50  0000 L CNN
F 1 "1uF" H 5425 4150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5438 4100 50  0001 C CNN
F 3 "" H 5400 4250 50  0001 C CNN
	1    5400 4250
	1    0    0    -1  
$EndComp
$Comp
L C C76
U 1 1 59FF7DD5
P 6400 4350
F 0 "C76" H 6425 4450 50  0000 L CNN
F 1 "470pF" H 6425 4250 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6438 4200 50  0001 C CNN
F 3 "" H 6400 4350 50  0001 C CNN
	1    6400 4350
	1    0    0    -1  
$EndComp
$Comp
L C C78
U 1 1 59FF7E2E
P 6800 4250
F 0 "C78" H 6825 4350 50  0000 L CNN
F 1 "2.2uF" H 6825 4150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6838 4100 50  0001 C CNN
F 3 "" H 6800 4250 50  0001 C CNN
	1    6800 4250
	1    0    0    -1  
$EndComp
Text GLabel 7450 3900 2    57   UnSpc ~ 0
3V3
Text GLabel 7450 4650 2    57   UnSpc ~ 0
GND
Text Notes 4600 4900 0    57   ~ 0
DESIGN: AP2210 is drop in replacement 
Text Notes 4600 5000 0    57   ~ 0
NOTE: Changed input cap to 1uF from reccomended value of 0.33uF
Text Notes 4900 5100 0    57   ~ 0
Should not have effect, but look here if something is wrong\n
Text Notes 4650 2950 0    60   ~ 0
NOTE: Actually use LD29150DT50R
$Comp
L CP C79
U 1 1 5A101B8D
P 6850 2550
F 0 "C79" H 6875 2650 50  0000 L CNN
F 1 "10uF" H 6875 2450 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206" H 6888 2400 50  0001 C CNN
F 3 "" H 6850 2550 50  0001 C CNN
	1    6850 2550
	1    0    0    -1  
$EndComp
$Comp
L TEST_1P T7
U 1 1 5A12967F
P 6600 2300
F 0 "T7" H 6600 2500 50  0000 C CNN
F 1 "TP" H 6600 2500 50  0001 C CNN
F 2 "Measurement_Points:Test_Point_Keystone_5015_Micro-Minature" H 6800 2300 50  0001 C CNN
F 3 "" H 6800 2300 50  0001 C CNN
	1    6600 2300
	1    0    0    -1  
$EndComp
$Comp
L TEST_1P T8
U 1 1 5A129698
P 6600 4000
F 0 "T8" H 6600 4200 50  0000 C CNN
F 1 "TP" H 6600 4200 50  0001 C CNN
F 2 "Measurement_Points:Test_Point_Keystone_5015_Micro-Minature" H 6800 4000 50  0001 C CNN
F 3 "" H 6800 4000 50  0001 C CNN
	1    6600 4000
	1    0    0    -1  
$EndComp
Text Notes 4650 3250 0    60   ~ 0
LAYOUT: Include adaquite thermal vias on exposed pad
Text Notes 4650 3050 0    60   ~ 0
NOTE: Power dissipation ~1.6W
Text Notes 4650 3150 0    60   ~ 0
NOTE: C79 must be tantalum. Check power line for oscillation in implemented design. 
$Comp
L LED D2
U 1 1 5A13BABC
P 7350 4100
F 0 "D2" H 7350 4200 50  0000 C CNN
F 1 "LED" H 7350 4000 50  0000 C CNN
F 2 "LEDs:LED_0603" H 7350 4100 50  0001 C CNN
F 3 "" H 7350 4100 50  0001 C CNN
	1    7350 4100
	0    -1   -1   0   
$EndComp
$Comp
L R R23
U 1 1 5A13BCA3
P 7350 4450
F 0 "R23" V 7430 4450 50  0000 C CNN
F 1 "1K" V 7350 4450 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 7280 4450 50  0001 C CNN
F 3 "" H 7350 4450 50  0001 C CNN
	1    7350 4450
	1    0    0    -1  
$EndComp
$Comp
L LED D1
U 1 1 5A13BD03
P 7300 2350
F 0 "D1" H 7300 2450 50  0000 C CNN
F 1 "LED" H 7300 2250 50  0000 C CNN
F 2 "LEDs:LED_0603" H 7300 2350 50  0001 C CNN
F 3 "" H 7300 2350 50  0001 C CNN
	1    7300 2350
	0    -1   -1   0   
$EndComp
$Comp
L R R22
U 1 1 5A13BD73
P 7300 2700
F 0 "R22" V 7380 2700 50  0000 C CNN
F 1 "1K" V 7300 2700 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 7230 2700 50  0001 C CNN
F 3 "" H 7300 2700 50  0001 C CNN
	1    7300 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 2700 5400 2750
Wire Wire Line
	5400 2750 7050 2750
Wire Wire Line
	6250 2350 7050 2350
Wire Wire Line
	5400 2400 5400 2350
Wire Wire Line
	5100 2350 5650 2350
Connection ~ 5400 2350
Wire Wire Line
	5950 2650 5950 2750
Connection ~ 5950 2750
Wire Wire Line
	6850 2400 6850 2350
Connection ~ 6850 2350
Wire Wire Line
	6850 2750 6850 2700
Connection ~ 6850 2750
Wire Wire Line
	5150 4050 5700 4050
Wire Wire Line
	5700 4150 5650 4150
Wire Wire Line
	5650 4150 5650 4050
Connection ~ 5650 4050
Wire Wire Line
	5400 4100 5400 4050
Connection ~ 5400 4050
Wire Wire Line
	6300 4150 6400 4150
Wire Wire Line
	6400 4150 6400 4200
Wire Wire Line
	6300 4050 7050 4050
Wire Wire Line
	6800 4050 6800 4100
Connection ~ 6800 4050
Wire Wire Line
	6800 4400 6800 4550
Wire Wire Line
	5400 4550 7050 4550
Wire Wire Line
	5400 4550 5400 4400
Wire Wire Line
	6000 4450 6000 4550
Connection ~ 6000 4550
Wire Wire Line
	6400 4500 6400 4550
Connection ~ 6400 4550
Connection ~ 6800 4550
Wire Wire Line
	6600 4050 6600 4000
Connection ~ 6600 4050
Wire Wire Line
	6600 2350 6600 2300
Connection ~ 6600 2350
Wire Wire Line
	7050 2900 7400 2900
Wire Wire Line
	7300 2900 7300 2850
Wire Wire Line
	7050 2750 7050 2900
Connection ~ 7300 2900
Wire Wire Line
	7050 2350 7050 2150
Wire Wire Line
	7050 2150 7450 2150
Wire Wire Line
	7300 2200 7300 2150
Connection ~ 7300 2150
Wire Wire Line
	7300 2500 7300 2550
Wire Wire Line
	7050 4650 7450 4650
Wire Wire Line
	7350 4650 7350 4600
Wire Wire Line
	7050 4550 7050 4650
Connection ~ 7350 4650
Wire Wire Line
	7050 4050 7050 3900
Wire Wire Line
	7050 3900 7450 3900
Wire Wire Line
	7350 3900 7350 3950
Connection ~ 7350 3900
Wire Wire Line
	7350 4250 7350 4300
$EndSCHEMATC
