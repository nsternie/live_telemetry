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
Text GLabel 4550 3650 2    57   UnSpc ~ 0
GND
Text GLabel 4550 3550 2    57   UnSpc ~ 0
3V3
Text GLabel 4550 3450 2    57   Input ~ 0
SCLK1
Text GLabel 4550 3350 2    57   Output ~ 0
MISO1
Text GLabel 4550 3250 2    57   Output ~ 0
MOSI1
$Comp
L Conn_01x08 J?
U 1 1 59F6E9E1
P 4250 3350
F 0 "J?" H 4250 3750 50  0000 C CNN
F 1 "Conn_01x08" H 4250 2850 50  0000 C CNN
F 2 "" H 4250 3350 50  0001 C CNN
F 3 "" H 4250 3350 50  0001 C CNN
	1    4250 3350
	-1   0    0    1   
$EndComp
Text GLabel 4550 3150 2    57   Input ~ 0
CS_CC1125
Text GLabel 4550 3050 2    57   Input ~ 0
LNA_Control
Text GLabel 4550 2950 2    57   Input ~ 0
PA_Control
Wire Wire Line
	4450 3650 4550 3650
Wire Wire Line
	4450 3550 4550 3550
Wire Wire Line
	4450 3450 4550 3450
Wire Wire Line
	4450 3350 4550 3350
Wire Wire Line
	4450 3250 4550 3250
Wire Wire Line
	4450 3150 4550 3150
Wire Wire Line
	4450 3050 4550 3050
Wire Wire Line
	4450 2950 4550 2950
$EndSCHEMATC
