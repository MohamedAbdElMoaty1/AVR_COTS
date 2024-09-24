# ATmega32 Drivers

## Introduction
This project provides a set of drivers for the ATmega32 microcontroller (AVR). It is organized into three main layers:

1. **MCAL (Microcontroller Abstraction Layer)**: Provides low-level access to the hardware.
2. **HAL (Hardware Abstraction Layer)**: Contains hardware drivers that abstract the complexity of interacting with various peripherals.
3. **Library**: Provides utility functions and common libraries to support the project.

The drivers are designed to be modular, reusable, and easily integrable into various embedded systems projects using ATmega32.

## Table of Contents
- [MCAL (Microcontroller Abstraction Layer)](https://github.com/MohamedAbdElMoaty1/AVR_COTS/tree/Develop/MCAL)
- [HAL (Hardware Abstraction Layer)](https://github.com/MohamedAbdElMoaty1/AVR_COTS/tree/Develop/HAL)
- [Library](https://github.com/MohamedAbdElMoaty1/AVR_COTS/tree/Develop/Library)

## MCAL (Microcontroller Abstraction Layer)
The MCAL provides essential drivers to interface with the hardware components of the ATmega32 microcontroller. Below are the modules available in the MCAL:

- **DIO (Digital Input/Output)**
- **PORT**: Port control and configuration
- **GIE (Global Interrupt Enable)**: Enables and disables global interrupts
- **EXTI (External Interrupts)**
- **ADC (Analog to Digital Converter)**
- **TIMER**: Timers and counters
- **WDT (Watchdog Timer)**
- **UART (Universal Asynchronous Receiver-Transmitter)**
- **SPI (Serial Peripheral Interface)**

Each driver is built to be easily configurable and flexible, ensuring proper hardware abstraction and ease of use.

## HAL (Hardware Abstraction Layer)
The HAL layer abstracts specific hardware components, making it easier to interface with peripherals in a generic way. Below are the components covered:

- **CLCD (LCD)**
- **DAC (Digital to Analog Converter)**
- **DC Motor**
- **Keypad**
- **LDR (Light Dependent Resistor)**
- **LED (Light Emitting Diode)**
- **LM35 (Temperature Sensor)**
- **SSD (Seven Segment Display)**
- **Switch**
- **Stepper Motor**

The HAL drivers simplify the use of these peripherals by abstracting the low-level register manipulation into user-friendly APIs.

## Library
The LIBRARY section provides common utility functions and types used throughout the project:

- **MAP**: For mapping values from one range to another.
- **BIT_MATH**: Utility macros for bit manipulation.
- **ErrType**: Error type definitions used across drivers.
- **STD_TYPES**: Standard type definitions such as `uint8`, `uint16`, etc.

These libraries ensure code reusability and efficiency across the MCAL and HAL layers.
