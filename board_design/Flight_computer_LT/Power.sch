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
Sheet 7 7
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
L L7805 U?
U 1 1 59FF775F
P 5950 2800
F 0 "U?" H 5800 2925 50  0000 C CNN
F 1 "L7805" H 5950 2925 50  0000 L CNN
F 2 "" H 5975 2650 50  0001 L CIN
F 3 "" H 5950 2750 50  0001 C CNN
	1    5950 2800
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 59FF77EC
P 6550 3000
F 0 "C?" H 6575 3100 50  0000 L CNN
F 1 "0.1uF" H 6575 2900 50  0000 L CNN
F 2 "" H 6588 2850 50  0001 C CNN
F 3 "" H 6550 3000 50  0001 C CNN
	1    6550 3000
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 59FF7809
P 5400 3000
F 0 "C?" H 5425 3100 50  0000 L CNN
F 1 "1uF" H 5425 2900 50  0000 L CNN
F 2 "" H 5438 2850 50  0001 C CNN
F 3 "" H 5400 3000 50  0001 C CNN
	1    5400 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 3150 5400 3200
Wire Wire Line
	5400 3200 7050 3200
Wire Wire Line
	6550 3150 6550 3200
Connection ~ 6550 3200
Wire Wire Line
	6250 2800 7050 2800
Wire Wire Line
	6550 2850 6550 2800
Connection ~ 6550 2800
Wire Wire Line
	5400 2850 5400 2800
Wire Wire Line
	5100 2800 5650 2800
Connection ~ 5400 2800
Wire Wire Line
	5950 3100 5950 3200
Connection ~ 5950 3200
Text GLabel 5100 2800 0    57   UnSpc ~ 0
VIN
Text GLabel 7050 2800 2    57   UnSpc ~ 0
5V
Text GLabel 7050 3200 2    57   UnSpc ~ 0
GND
$Comp
L C C?
U 1 1 59FF7AA7
P 6850 3000
F 0 "C?" H 6875 3100 50  0000 L CNN
F 1 "2.2uF" H 6875 2900 50  0000 L CNN
F 2 "" H 6888 2850 50  0001 C CNN
F 3 "" H 6850 3000 50  0001 C CNN
	1    6850 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 2850 6850 2800
Connection ~ 6850 2800
Wire Wire Line
	6850 3200 6850 3150
Connection ~ 6850 3200
$Comp
L MIC5219-3.3 U?
U 1 1 59FF7D18
P 6000 4150
F 0 "U?" H 5850 4375 50  0000 C CNN
F 1 "MIC5219-3.3" H 6000 4375 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-5" H 6000 4475 50  0001 C CNN
F 3 "" H 6000 4150 50  0001 C CNN
	1    6000 4150
	1    0    0    -1  
$EndComp
Text GLabel 5150 4050 0    57   UnSpc ~ 0
VIN
Wire Wire Line
	5150 4050 5700 4050
Wire Wire Line
	5700 4150 5650 4150
Wire Wire Line
	5650 4150 5650 4050
Connection ~ 5650 4050
$Comp
L C C?
U 1 1 59FF7D99
P 5400 4250
F 0 "C?" H 5425 4350 50  0000 L CNN
F 1 "1uF" H 5425 4150 50  0000 L CNN
F 2 "" H 5438 4100 50  0001 C CNN
F 3 "" H 5400 4250 50  0001 C CNN
	1    5400 4250
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 59FF7DD5
P 6400 4350
F 0 "C?" H 6425 4450 50  0000 L CNN
F 1 "470pF" H 6425 4250 50  0000 L CNN
F 2 "" H 6438 4200 50  0001 C CNN
F 3 "" H 6400 4350 50  0001 C CNN
	1    6400 4350
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 59FF7E2E
P 6800 4250
F 0 "C?" H 6825 4350 50  0000 L CNN
F 1 "2.2uF" H 6825 4150 50  0000 L CNN
F 2 "" H 6838 4100 50  0001 C CNN
F 3 "" H 6800 4250 50  0001 C CNN
	1    6800 4250
	1    0    0    -1  
$EndComp
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
Text GLabel 7050 4050 2    57   UnSpc ~ 0
3V3
Text GLabel 7050 4550 2    57   UnSpc ~ 0
GND
Text Notes 5250 4900 0    57   ~ 0
DESIGN: AP2210 is drop in replacement 
Text Notes 5250 5000 0    57   ~ 0
NOTE: Changed input cap to 1uF from reccomended value of 0.33uF
Text Notes 5550 5100 0    57   ~ 0
Should not have effect, but look here if something is wrong\n
$EndSCHEMATC
