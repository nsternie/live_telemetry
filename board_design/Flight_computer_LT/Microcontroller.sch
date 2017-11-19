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
Sheet 2 8
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
L STM32F446RET6 U?
U 1 1 59F694FF
P 1950 3750
AR Path="/59F694FF" Ref="U?"  Part="1" 
AR Path="/59F689B4/59F694FF" Ref="U1"  Part="1" 
F 0 "U1" H 1800 3900 49  0000 C CNN
F 1 "STM32F446RET6" H 1800 2100 49  0000 C CNN
F 2 "Housings_QFP:LQFP-64_10x10mm_Pitch0.5mm" H 1950 3750 49  0001 C CNN
F 3 "" H 1950 3750 49  0001 C CNN
	1    1950 3750
	1    0    0    -1  
$EndComp
$Comp
L STM32F446RET6 U?
U 2 1 59F69506
P 4750 3750
AR Path="/59F69506" Ref="U?"  Part="2" 
AR Path="/59F689B4/59F69506" Ref="U1"  Part="2" 
F 0 "U1" H 4600 3900 49  0000 C CNN
F 1 "STM32F446RET6" H 4600 2100 49  0000 C CNN
F 2 "Housings_QFP:LQFP-64_10x10mm_Pitch0.5mm" H 4750 3750 49  0001 C CNN
F 3 "" H 4750 3750 49  0001 C CNN
	2    4750 3750
	1    0    0    -1  
$EndComp
$Comp
L STM32F446RET6 U?
U 3 1 59F6950D
P 6900 3750
AR Path="/59F6950D" Ref="U?"  Part="3" 
AR Path="/59F689B4/59F6950D" Ref="U1"  Part="3" 
F 0 "U1" H 6750 3900 49  0000 C CNN
F 1 "STM32F446RET6" H 6750 2100 49  0000 C CNN
F 2 "Housings_QFP:LQFP-64_10x10mm_Pitch0.5mm" H 6900 3750 49  0001 C CNN
F 3 "" H 6900 3750 49  0001 C CNN
	3    6900 3750
	1    0    0    -1  
$EndComp
$Comp
L STM32F446RET6 U?
U 4 1 59F69514
P 8800 3750
AR Path="/59F69514" Ref="U?"  Part="4" 
AR Path="/59F689B4/59F69514" Ref="U1"  Part="4" 
F 0 "U1" H 8650 3900 49  0000 C CNN
F 1 "STM32F446RET6" H 8400 3550 49  0000 C CNN
F 2 "Housings_QFP:LQFP-64_10x10mm_Pitch0.5mm" H 8800 3750 49  0001 C CNN
F 3 "" H 8800 3750 49  0001 C CNN
	4    8800 3750
	1    0    0    -1  
$EndComp
$Comp
L STM32F446RET6 U?
U 5 1 59F6951B
P 5150 1400
AR Path="/59F6951B" Ref="U?"  Part="5" 
AR Path="/59F689B4/59F6951B" Ref="U1"  Part="5" 
F 0 "U1" H 5000 1550 49  0000 C CNN
F 1 "STM32F446RET6" H 5000 -250 49  0000 C CNN
F 2 "Housings_QFP:LQFP-64_10x10mm_Pitch0.5mm" H 5150 1400 49  0001 C CNN
F 3 "" H 5150 1400 49  0001 C CNN
	5    5150 1400
	1    0    0    -1  
$EndComp
Text Label 3850 1400 0    60   ~ 0
GND
$Comp
L C C2
U 1 1 59F69533
P 3150 1800
F 0 "C2" H 3175 1900 50  0000 L CNN
F 1 "2.2nF" H 3175 1700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3188 1650 50  0001 C CNN
F 3 "" H 3150 1800 50  0001 C CNN
	1    3150 1800
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 59F6953A
P 2800 1800
F 0 "C1" H 2825 1900 50  0000 L CNN
F 1 "100nF" H 2825 1700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2838 1650 50  0001 C CNN
F 3 "" H 2800 1800 50  0001 C CNN
	1    2800 1800
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 59F69541
P 2800 1400
F 0 "R1" V 2880 1400 50  0000 C CNN
F 1 "1.5K" V 2800 1400 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 2730 1400 50  0001 C CNN
F 3 "" H 2800 1400 50  0001 C CNN
	1    2800 1400
	1    0    0    -1  
$EndComp
NoConn ~ 5350 2900
$Comp
L C C3
U 1 1 59F6955D
P 5950 2600
F 0 "C3" H 5975 2700 50  0000 L CNN
F 1 "2.2uF" H 5975 2500 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5988 2450 50  0001 C CNN
F 3 "" H 5950 2600 50  0001 C CNN
	1    5950 2600
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 59F6956B
P 7050 1550
F 0 "C5" H 7075 1650 50  0000 L CNN
F 1 "100nF" H 7075 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7088 1400 50  0001 C CNN
F 3 "" H 7050 1550 50  0001 C CNN
	1    7050 1550
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 59F69572
P 7450 1550
F 0 "C6" H 7475 1650 50  0000 L CNN
F 1 "100nF" H 7475 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7488 1400 50  0001 C CNN
F 3 "" H 7450 1550 50  0001 C CNN
	1    7450 1550
	1    0    0    -1  
$EndComp
$Comp
L C C7
U 1 1 59F69579
P 7850 1550
F 0 "C7" H 7875 1650 50  0000 L CNN
F 1 "100nF" H 7875 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7888 1400 50  0001 C CNN
F 3 "" H 7850 1550 50  0001 C CNN
	1    7850 1550
	1    0    0    -1  
$EndComp
$Comp
L C C8
U 1 1 59F69580
P 8250 1550
F 0 "C8" H 8275 1650 50  0000 L CNN
F 1 "100nF" H 8275 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 8288 1400 50  0001 C CNN
F 3 "" H 8250 1550 50  0001 C CNN
	1    8250 1550
	1    0    0    -1  
$EndComp
$Comp
L C C9
U 1 1 59F69587
P 8650 1550
F 0 "C9" H 8675 1650 50  0000 L CNN
F 1 "100nF" H 8675 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 8688 1400 50  0001 C CNN
F 3 "" H 8650 1550 50  0001 C CNN
	1    8650 1550
	1    0    0    -1  
$EndComp
$Comp
L C C10
U 1 1 59F6958E
P 9050 1550
F 0 "C10" H 9075 1650 50  0000 L CNN
F 1 "2.2nF" H 9075 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 9088 1400 50  0001 C CNN
F 3 "" H 9050 1550 50  0001 C CNN
	1    9050 1550
	1    0    0    -1  
$EndComp
$Comp
L C C11
U 1 1 59F69595
P 9450 1550
F 0 "C11" H 9475 1650 50  0000 L CNN
F 1 "2.2nF" H 9475 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 9488 1400 50  0001 C CNN
F 3 "" H 9450 1550 50  0001 C CNN
	1    9450 1550
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 59F6959C
P 6650 1550
F 0 "C4" H 6675 1650 50  0000 L CNN
F 1 "10uF" H 6675 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6688 1400 50  0001 C CNN
F 3 "" H 6650 1550 50  0001 C CNN
	1    6650 1550
	1    0    0    -1  
$EndComp
Text Notes 5450 3050 0    60   ~ 0
Verify VBat not needed\n
Text Notes 2950 5850 0    60   ~ 0
DESIGN: Be careful w/ external interrupts I/O mapping\n
Text GLabel 2450 1200 0    57   UnSpc ~ 0
3V3
Text GLabel 2450 2000 0    57   UnSpc ~ 0
GND
Text GLabel 5550 2700 2    57   UnSpc ~ 0
GND
Text GLabel 6200 2850 2    57   UnSpc ~ 0
GND
Text GLabel 6350 1750 0    57   UnSpc ~ 0
GND
Text GLabel 6350 1350 0    57   UnSpc ~ 0
3V3
Text GLabel 5600 1400 2    57   UnSpc ~ 0
3V3
Text GLabel 5650 2200 2    57   UnSpc ~ 0
GND
Text GLabel 5550 2600 2    57   UnSpc ~ 0
3V3
Text GLabel 2250 4350 2    57   Input ~ 0
MISO1
Text GLabel 2250 4450 2    57   Output ~ 0
MOSI1
Text GLabel 2250 4250 2    57   Output ~ 0
SCLK1
Text GLabel 5050 5150 2    57   Output ~ 0
MOSI2
Text GLabel 5050 4950 2    57   Output ~ 0
SCLK2
Text GLabel 5050 5050 2    57   Input ~ 0
MISO2
Text GLabel 2250 5050 2    57   Output ~ 0
TMS
Text GLabel 2250 5150 2    57   Output ~ 0
TCK
Text GLabel 5050 4050 2    57   Output ~ 0
SWO
Text GLabel 2650 1600 0    57   Input ~ 0
nRST
Text GLabel 2250 4750 2    57   Input ~ 0
USART_RX1
Text GLabel 2250 4650 2    57   Output ~ 0
USART_TX1
Text Notes 2850 4750 0    57   ~ 0
From view of uC\n
Text GLabel 7200 4250 2    57   Input ~ 0
USART_RX1
Text GLabel 5050 4750 2    57   Output ~ 0
USART_TX1
Wire Wire Line
	7100 4250 7200 4250
Wire Wire Line
	5050 4750 4950 4750
Wire Wire Line
	2250 4750 2150 4750
Wire Wire Line
	2250 4650 2150 4650
Wire Wire Line
	2150 5150 2250 5150
Wire Wire Line
	2150 5050 2250 5050
Wire Wire Line
	4950 4050 5050 4050
Wire Wire Line
	2150 4250 2250 4250
Wire Wire Line
	2150 4350 2250 4350
Wire Wire Line
	2150 4450 2250 4450
Wire Wire Line
	4950 5150 5050 5150
Wire Wire Line
	4950 5050 5050 5050
Wire Wire Line
	4950 4950 5050 4950
Wire Wire Line
	6350 1350 9450 1350
Connection ~ 9050 1750
Wire Wire Line
	9050 1700 9050 1750
Connection ~ 8650 1750
Wire Wire Line
	8650 1700 8650 1750
Connection ~ 8250 1750
Wire Wire Line
	8250 1700 8250 1750
Connection ~ 7850 1750
Wire Wire Line
	7850 1750 7850 1700
Connection ~ 7450 1750
Wire Wire Line
	7450 1750 7450 1700
Connection ~ 7050 1750
Wire Wire Line
	7050 1750 7050 1700
Connection ~ 6650 1750
Wire Wire Line
	6650 1750 6650 1700
Wire Wire Line
	6350 1750 9450 1750
Wire Wire Line
	9450 1750 9450 1700
Connection ~ 9050 1350
Wire Wire Line
	9050 1400 9050 1350
Connection ~ 8650 1350
Wire Wire Line
	8650 1400 8650 1350
Connection ~ 8250 1350
Wire Wire Line
	8250 1400 8250 1350
Connection ~ 7850 1350
Wire Wire Line
	7850 1400 7850 1350
Connection ~ 7450 1350
Wire Wire Line
	7450 1400 7450 1350
Connection ~ 7050 1350
Wire Wire Line
	7050 1400 7050 1350
Connection ~ 6650 1350
Wire Wire Line
	6650 1400 6650 1350
Wire Wire Line
	9450 1350 9450 1400
Wire Wire Line
	5950 2850 6200 2850
Wire Wire Line
	5950 2750 5950 2850
Wire Wire Line
	5950 2400 5950 2450
Wire Wire Line
	5350 2400 5950 2400
Wire Wire Line
	5350 2700 5550 2700
Wire Wire Line
	5350 2600 5550 2600
Wire Wire Line
	2450 1200 2800 1200
Wire Wire Line
	2800 1200 2800 1250
Wire Wire Line
	4100 1400 3850 1400
Connection ~ 3150 1600
Wire Wire Line
	3150 1650 3150 1600
Wire Wire Line
	3150 2000 3150 1950
Wire Wire Line
	5350 2200 5650 2200
Wire Wire Line
	5350 1400 5600 1400
Connection ~ 2800 2000
Wire Wire Line
	2800 2000 2800 1950
Wire Wire Line
	2450 2000 3150 2000
Connection ~ 2800 1600
Wire Wire Line
	2800 1550 2800 1650
Wire Wire Line
	2650 1600 4100 1600
Connection ~ 5400 2200
Connection ~ 5400 2000
Wire Wire Line
	5350 2000 5400 2000
Connection ~ 5400 2100
Wire Wire Line
	5350 2100 5400 2100
Wire Wire Line
	5400 1900 5400 2200
Wire Wire Line
	5350 1900 5400 1900
Connection ~ 5400 1400
Connection ~ 5400 1600
Wire Wire Line
	5350 1600 5400 1600
Connection ~ 5400 1500
Wire Wire Line
	5350 1500 5400 1500
Wire Wire Line
	5400 1700 5400 1400
Wire Wire Line
	5350 1700 5400 1700
Text GLabel 2250 4050 2    57   Output ~ 0
PYRO_A_SENSE
Text GLabel 7200 3850 2    57   Output ~ 0
PYRO_B_SENSE
Text GLabel 7200 3750 2    57   Output ~ 0
PYRO_C_SENSE
Text GLabel 2250 3850 2    57   Output ~ 0
PYRO_D_SENSE
Text GLabel 7200 5050 2    57   Output ~ 0
PYRO_C_FIRE
Text GLabel 2250 4150 2    57   Output ~ 0
PYRO_D_FIRE
Text GLabel 2250 3950 2    57   Input ~ 0
PYRO_A_FIRE
Text GLabel 7200 3950 2    57   Input ~ 0
PYRO_B_FIRE
Text GLabel 5050 4450 2    57   Output ~ 0
CS_GYRO5
Wire Wire Line
	4950 4450 5050 4450
Text GLabel 5050 4350 2    57   Output ~ 0
CS_GYRO3
Text GLabel 5050 4250 2    57   Output ~ 0
CS_GYRO6
Wire Wire Line
	4950 4350 5050 4350
Wire Wire Line
	4950 4250 5050 4250
Text GLabel 5050 4150 2    57   Input ~ 0
GYRO1_INT
Wire Wire Line
	5050 4150 4950 4150
Text GLabel 8900 3750 2    57   Input ~ 0
GYRO6_INT
Wire Wire Line
	8900 3750 8800 3750
Text GLabel 7200 4850 2    57   Output ~ 0
CS_GYRO1
Text GLabel 7200 4750 2    57   Input ~ 0
GYRO4_INT
Wire Wire Line
	7100 4750 7200 4750
Wire Wire Line
	7100 4850 7200 4850
Text GLabel 2250 5250 2    57   Output ~ 0
CS_GYRO4
Wire Wire Line
	2150 5250 2250 5250
Text GLabel 2250 4950 2    57   Input ~ 0
GYRO2_INT
Text GLabel 2250 4850 2    57   Output ~ 0
CS_GYRO2
Wire Wire Line
	2150 4850 2250 4850
Wire Wire Line
	2150 4950 2250 4950
Text GLabel 2250 4550 2    57   Input ~ 0
GYRO3_INT
Text GLabel 7200 4650 2    57   Input ~ 0
GYRO5_INT
Wire Wire Line
	7100 4650 7200 4650
Wire Wire Line
	2150 4550 2250 4550
Text GLabel 5050 3950 2    57   Output ~ 0
CS_ADXL
Wire Wire Line
	5050 3950 4950 3950
Text GLabel 5050 3850 2    57   Input ~ 0
DRDY_ADXL
Text GLabel 5050 3750 2    57   Input ~ 0
INT1_ADXL
Wire Wire Line
	5050 3750 4950 3750
Wire Wire Line
	5050 3850 4950 3850
Text GLabel 7200 4550 2    57   Output ~ 0
CS_MS5607
Wire Wire Line
	7200 4550 7100 4550
Text GLabel 7200 4150 2    57   Input ~ 0
CS_MEM
Wire Wire Line
	7100 4150 7200 4150
Text GLabel 5050 4550 2    57   Output ~ 0
CS_CC125
Wire Wire Line
	5050 4550 4950 4550
Text GLabel 5050 4650 2    57   Input ~ 0
GPIO0
Wire Wire Line
	5050 4650 4950 4650
NoConn ~ 4100 1900
NoConn ~ 4100 2050
Text GLabel 2250 3750 2    57   Output ~ 0
LNA_EN
Text GLabel 7200 4050 2    57   Output ~ 0
PA_EN
Wire Wire Line
	2150 3750 2250 3750
Wire Wire Line
	2250 3850 2150 3850
Wire Wire Line
	2150 3950 2250 3950
Wire Wire Line
	2250 4050 2150 4050
Wire Wire Line
	2150 4150 2250 4150
Wire Wire Line
	7100 5050 7200 5050
Wire Wire Line
	7100 4050 7200 4050
Wire Wire Line
	7200 3750 7100 3750
Wire Wire Line
	7100 3850 7200 3850
Wire Wire Line
	7200 3950 7100 3950
$EndSCHEMATC
