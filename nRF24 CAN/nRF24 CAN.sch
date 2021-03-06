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
LIBS:stm32f103c8t6-mod
LIBS:DIPSwitch
LIBS:mcp2557fd
LIBS:nrf24l01
LIBS:nRF24 CAN-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L STM32F103C8T6-MOD U2
U 1 1 594D728F
P 2950 2950
F 0 "U2" H 2950 4147 60  0000 C CNN
F 1 "STM32F103C8T6-MOD" H 2950 4041 60  0000 C CNN
F 2 "Housings_DIP:DIP-40_W15.24mm_Socket_LongPads" H 2950 2950 60  0001 C CNN
F 3 "" H 2950 2950 60  0001 C CNN
	1    2950 2950
	1    0    0    -1  
$EndComp
$Comp
L MCP2557FD U3
U 1 1 594D7308
P 4300 3200
F 0 "U3" H 4300 3300 39  0000 C CNN
F 1 "MCP2557FD" H 4300 3200 39  0000 C CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 4300 3200 39  0001 C CNN
F 3 "" H 4300 3200 39  0001 C CNN
	1    4300 3200
	1    0    0    -1  
$EndComp
$Comp
L nRF24L01 U1
U 1 1 594D75BA
P 1300 2850
F 0 "U1" H 1578 2822 60  0000 L CNN
F 1 "nRF24L01" H 1578 2928 60  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04_Pitch2.54mm" H 1300 2850 60  0001 C CNN
F 3 "" H 1300 2850 60  0001 C CNN
	1    1300 2850
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X04 J1
U 1 1 594D76D7
P 5700 2950
F 0 "J1" H 5777 2991 50  0000 L CNN
F 1 "CAN IN" H 5777 2900 50  0000 L CNN
F 2 "Connectors_Phoenix:PhoenixContact_MSTBA-G_04x5.08mm_Angled" H 5700 2950 50  0001 C CNN
F 3 "" H 5700 2950 50  0001 C CNN
	1    5700 2950
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 J2
U 1 1 594D773B
P 5700 3450
F 0 "J2" H 5777 3491 50  0000 L CNN
F 1 "CAN OUT" H 5777 3400 50  0000 L CNN
F 2 "Connectors_Phoenix:PhoenixContact_MSTBA-G_04x5.08mm_Angled" H 5700 3450 50  0001 C CNN
F 3 "" H 5700 3450 50  0001 C CNN
	1    5700 3450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 594D7A8F
P 2250 3950
F 0 "#PWR01" H 2250 3700 50  0001 C CNN
F 1 "GND" H 2255 3777 50  0000 C CNN
F 2 "" H 2250 3950 50  0001 C CNN
F 3 "" H 2250 3950 50  0001 C CNN
	1    2250 3950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 594D7D2D
P 3750 2150
F 0 "#PWR02" H 3750 1900 50  0001 C CNN
F 1 "GND" H 3755 1977 50  0000 C CNN
F 2 "" H 3750 2150 50  0001 C CNN
F 3 "" H 3750 2150 50  0001 C CNN
	1    3750 2150
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR03
U 1 1 594D7DF6
P 3750 2000
F 0 "#PWR03" H 3750 1850 50  0001 C CNN
F 1 "+3V3" H 3765 2173 50  0000 C CNN
F 2 "" H 3750 2000 50  0001 C CNN
F 3 "" H 3750 2000 50  0001 C CNN
	1    3750 2000
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR04
U 1 1 594D7EB4
P 900 3400
F 0 "#PWR04" H 900 3250 50  0001 C CNN
F 1 "+3V3" H 915 3573 50  0000 C CNN
F 2 "" H 900 3400 50  0001 C CNN
F 3 "" H 900 3400 50  0001 C CNN
	1    900  3400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 594D7EE5
P 1450 2350
F 0 "#PWR05" H 1450 2100 50  0001 C CNN
F 1 "GND" H 1600 2300 50  0000 C CNN
F 2 "" H 1450 2350 50  0001 C CNN
F 3 "" H 1450 2350 50  0001 C CNN
	1    1450 2350
	1    0    0    -1  
$EndComp
$Comp
L C_Small C1
U 1 1 594D8027
P 1100 3550
F 0 "C1" H 1192 3596 50  0000 L CNN
F 1 "0.1u" H 1192 3505 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1100 3550 50  0001 C CNN
F 3 "" H 1100 3550 50  0001 C CNN
	1    1100 3550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 594D805F
P 1100 3700
F 0 "#PWR06" H 1100 3450 50  0001 C CNN
F 1 "GND" H 1105 3527 50  0000 C CNN
F 2 "" H 1100 3700 50  0001 C CNN
F 3 "" H 1100 3700 50  0001 C CNN
	1    1100 3700
	1    0    0    -1  
$EndComp
$Comp
L C_Small C2
U 1 1 594D8176
P 3950 2100
F 0 "C2" H 4042 2146 50  0000 L CNN
F 1 "0.1u" H 4042 2055 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3950 2100 50  0001 C CNN
F 3 "" H 3950 2100 50  0001 C CNN
	1    3950 2100
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR07
U 1 1 594D8345
P 4300 2650
F 0 "#PWR07" H 4300 2500 50  0001 C CNN
F 1 "+5V" H 4315 2823 50  0000 C CNN
F 2 "" H 4300 2650 50  0001 C CNN
F 3 "" H 4300 2650 50  0001 C CNN
	1    4300 2650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 594D8452
P 4250 3650
F 0 "#PWR08" H 4250 3400 50  0001 C CNN
F 1 "GND" H 4255 3477 50  0000 C CNN
F 2 "" H 4250 3650 50  0001 C CNN
F 3 "" H 4250 3650 50  0001 C CNN
	1    4250 3650
	1    0    0    -1  
$EndComp
$Comp
L C_Small C3
U 1 1 594D856C
P 4500 2700
F 0 "C3" V 4271 2700 50  0000 C CNN
F 1 "0.1u" V 4362 2700 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4500 2700 50  0001 C CNN
F 3 "" H 4500 2700 50  0001 C CNN
	1    4500 2700
	0    1    1    0   
$EndComp
$Comp
L GND #PWR09
U 1 1 594D863D
P 4750 2700
F 0 "#PWR09" H 4750 2450 50  0001 C CNN
F 1 "GND" H 4755 2527 50  0000 C CNN
F 2 "" H 4750 2700 50  0001 C CNN
F 3 "" H 4750 2700 50  0001 C CNN
	1    4750 2700
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR010
U 1 1 594D888D
P 5350 2750
F 0 "#PWR010" H 5350 2600 50  0001 C CNN
F 1 "+5V" H 5365 2923 50  0000 C CNN
F 2 "" H 5350 2750 50  0001 C CNN
F 3 "" H 5350 2750 50  0001 C CNN
	1    5350 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 2900 2200 2900
Wire Wire Line
	2200 2900 2200 3000
Wire Wire Line
	2200 3000 2350 3000
Wire Wire Line
	2000 3000 2150 3000
Wire Wire Line
	2150 3000 2150 3100
Wire Wire Line
	2150 3100 2350 3100
Wire Wire Line
	2000 3100 2050 3100
Wire Wire Line
	2050 3100 2050 2950
Wire Wire Line
	2050 2950 2300 2950
Wire Wire Line
	2300 2950 2300 2900
Wire Wire Line
	2300 2900 2350 2900
Wire Wire Line
	2350 3800 2250 3800
Wire Wire Line
	2250 3800 2250 3950
Connection ~ 2250 3900
Wire Wire Line
	3550 2100 3850 2100
Wire Wire Line
	3750 2100 3750 2150
Wire Wire Line
	3550 2000 3950 2000
Wire Wire Line
	900  3400 1300 3400
Wire Wire Line
	1300 2350 1450 2350
Wire Wire Line
	1100 3650 1100 3700
Wire Wire Line
	1100 3450 1100 3400
Connection ~ 1100 3400
Connection ~ 3750 2000
Wire Wire Line
	3950 2200 3850 2200
Wire Wire Line
	3850 2200 3850 2100
Connection ~ 3750 2100
Wire Wire Line
	4300 2650 4300 2700
Wire Wire Line
	4250 3650 4250 3600
Wire Wire Line
	4300 2700 4400 2700
Wire Wire Line
	4600 2700 4750 2700
Wire Wire Line
	5500 2900 5400 2900
Wire Wire Line
	5400 2900 5400 3400
Wire Wire Line
	5400 3400 5500 3400
Wire Wire Line
	5500 3000 5450 3000
Wire Wire Line
	5450 3000 5450 3500
Wire Wire Line
	5450 3500 5500 3500
Wire Wire Line
	4950 3150 5400 3150
Connection ~ 5400 3150
Wire Wire Line
	4950 3250 5450 3250
Connection ~ 5450 3250
Wire Wire Line
	5350 2800 5500 2800
Wire Wire Line
	5350 2750 5350 3300
Wire Wire Line
	5350 3300 5500 3300
Connection ~ 5350 2800
$Comp
L GND #PWR011
U 1 1 594D8BC3
P 5300 3650
F 0 "#PWR011" H 5300 3400 50  0001 C CNN
F 1 "GND" H 5305 3477 50  0000 C CNN
F 2 "" H 5300 3650 50  0001 C CNN
F 3 "" H 5300 3650 50  0001 C CNN
	1    5300 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 3100 5300 3100
Wire Wire Line
	5300 3100 5300 3650
Wire Wire Line
	5500 3600 5300 3600
Connection ~ 5300 3600
Wire Wire Line
	3550 3100 3750 3100
Wire Wire Line
	3750 3200 3550 3200
Wire Wire Line
	3550 3300 3750 3300
$Comp
L LED D1
U 1 1 594D937E
P 3750 3650
F 0 "D1" V 3800 3850 50  0000 R CNN
F 1 "LED" V 3700 3850 50  0000 R CNN
F 2 "LEDs:LED_D5.0mm" H 3750 3650 50  0001 C CNN
F 3 "" H 3750 3650 50  0001 C CNN
	1    3750 3650
	0    -1   -1   0   
$EndComp
$Comp
L LED D2
U 1 1 594D949A
P 3900 3650
F 0 "D2" V 3938 3533 50  0000 R CNN
F 1 "LED" V 3847 3533 50  0000 R CNN
F 2 "LEDs:LED_D5.0mm" H 3900 3650 50  0001 C CNN
F 3 "" H 3900 3650 50  0001 C CNN
	1    3900 3650
	0    -1   -1   0   
$EndComp
$Comp
L R R1
U 1 1 594D992C
P 3750 4000
F 0 "R1" H 3819 4046 50  0000 L CNN
F 1 "220" H 3819 3955 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3680 4000 50  0001 C CNN
F 3 "" H 3750 4000 50  0001 C CNN
	1    3750 4000
	-1   0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 594D99D9
P 3900 4000
F 0 "R2" H 3970 4046 50  0000 L CNN
F 1 "220" H 3970 3955 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3830 4000 50  0001 C CNN
F 3 "" H 3900 4000 50  0001 C CNN
	1    3900 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 3850 3900 3800
$Comp
L +3V3 #PWR012
U 1 1 594DA1E7
P 2250 3700
F 0 "#PWR012" H 2250 3550 50  0001 C CNN
F 1 "+3V3" H 2300 3650 50  0000 C CNN
F 2 "" H 2250 3700 50  0001 C CNN
F 3 "" H 2250 3700 50  0001 C CNN
	1    2250 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 3700 2350 3700
Wire Wire Line
	3550 3500 3750 3500
Wire Wire Line
	3550 3400 3900 3400
Wire Wire Line
	3900 3400 3900 3500
Wire Wire Line
	3750 3800 3750 3850
$Comp
L GND #PWR013
U 1 1 594DB5C0
P 3850 4200
F 0 "#PWR013" H 3850 3950 50  0001 C CNN
F 1 "GND" H 3855 4027 50  0000 C CNN
F 2 "" H 3850 4200 50  0001 C CNN
F 3 "" H 3850 4200 50  0001 C CNN
	1    3850 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 4150 3750 4200
Wire Wire Line
	3750 4200 3900 4200
Wire Wire Line
	3900 4200 3900 4150
Connection ~ 3850 4200
Wire Wire Line
	2000 2700 2200 2700
Wire Wire Line
	2200 2700 2200 2100
Wire Wire Line
	2200 2100 2350 2100
Wire Wire Line
	2000 2800 2250 2800
Wire Wire Line
	2250 2800 2250 2200
Wire Wire Line
	2250 2200 2350 2200
Wire Wire Line
	2000 2600 2250 2600
Wire Wire Line
	2250 2600 2250 3200
Wire Wire Line
	2250 3200 2350 3200
$Comp
L +5V #PWR?
U 1 1 594DC032
P 4000 2500
F 0 "#PWR?" H 4000 2350 50  0001 C CNN
F 1 "+5V" H 4015 2673 50  0000 C CNN
F 2 "" H 4000 2500 50  0001 C CNN
F 3 "" H 4000 2500 50  0001 C CNN
	1    4000 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 2500 3650 2500
Wire Wire Line
	3650 2500 3650 2200
Wire Wire Line
	3650 2200 3550 2200
$EndSCHEMATC
