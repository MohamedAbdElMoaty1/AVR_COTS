ATmega32 COTS
Overview
This project involves developing various peripheral drivers and modules for the ATmega32 microcontroller. The repository is structured to include hardware abstraction layers (HAL), microcontroller abstraction layers (MCAL), and utility libraries, making it modular and scalable for different microcontroller applications.

Repository Structure
The project is organized into three main directories:

1. HAL (Hardware Abstraction Layer)
The HAL contains drivers for different hardware modules that interact with the microcontroller. The following modules are implemented:

CLCD: Driver for character LCD displays.
DAC: Digital-to-Analog Converter driver.
DC_Motor: DC motor control driver.
Keypad: Driver for interfacing with a 4x4 matrix keypad.
LDR: Light-dependent resistor interface.
LED: Basic LED driver for digital output control.
LM35: Temperature sensor driver using the LM35 sensor.
SSD: Seven Segment Display driver.
Switch: Button and switch interface.
Stepper_Motor: Stepper motor control driver.
2. MCAL (Microcontroller Abstraction Layer)
MCAL includes low-level drivers specific to ATmega32 for interfacing with hardware peripherals:

1-DIO: Digital Input/Output control.
2-PORT: Port configuration and management.
3-GIE: Global Interrupt Enable control.
4-EXTI: External Interrupt configuration.
5-ADC: Analog-to-Digital Converter setup and handling.
6-Timer: Timer control for PWM, time delays, and more.
7-WDT: Watchdog Timer.
8-UART: Universal Asynchronous Receiver-Transmitter driver for serial communication.
9-SPI: Serial Peripheral Interface driver.
3. Library
This folder contains general utility functions and types:

Map: Function for value mapping between ranges.
BIT_MATH.h: Macros for bit manipulation.
ErrType.h: Error handling types and definitions.
STD_TYPES.h: Standard data type definitions for consistency across the project.
