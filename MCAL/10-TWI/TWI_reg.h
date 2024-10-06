#ifndef TWI_REG_H
#define TWI_REG_H

// TWI (Two Wire Interface) Bit Rate Register (TWBR)
// Used to set the SCL frequency in TWI communication
#define TWBR             *((volatile uint8*)0x20)

// Bit positions for the TWBR register (bit rate settings)
#define TWBR_TWBR0       0u
#define TWBR_TWBR1       1u
#define TWBR_TWBR2       2u
#define TWBR_TWBR3       3u
#define TWBR_TWBR4       4u
#define TWBR_TWBR5       5u
#define TWBR_TWBR6       6u
#define TWBR_TWBR7       7u

// TWI Control Register (TWCR)
// Used to control various operations of the TWI module, like enabling TWI, generating start/stop conditions
#define TWCR             *((volatile uint8*)0x56)

// Bit positions for TWCR (control flags)
#define TWCR_TWIE        0u    // TWI Interrupt Enable
#define TWCR_TWEN        2u    // TWI Enable Bit
#define TWCR_TWWC        3u    // TWI Write Collision Flag
#define TWCR_TWSTO       4u    // TWI Stop Condition Bit
#define TWCR_TWSTA       5u    // TWI Start Condition Bit
#define TWCR_TWEA        6u    // TWI Enable Acknowledge Bit
#define TWCR_TWINT       7u    // TWI Interrupt Flag

// TWI Status Register (TWSR)
// Holds the status of the TWI interface and prescaler bits for SCL frequency
#define TWSR             *((volatile uint8*)0x21)

// Bit positions for TWSR (prescaler and status bits)
#define TWSR_TWPS0       0u    // Prescaler Bit 0
#define TWSR_TWPS1       1u    // Prescaler Bit 1
#define TWSR_TWS3        3u    // TWI Status Bit 3
#define TWSR_TWS4        4u    // TWI Status Bit 4
#define TWSR_TWS5        5u    // TWI Status Bit 5
#define TWSR_TWS6        6u    // TWI Status Bit 6
#define TWSR_TWS7        7u    // TWI Status Bit 7

// TWI Data Register (TWDR)
// Used to hold the data to be transmitted or received
#define TWDR             *((volatile uint8*)0x23)

// Bit positions for TWDR (data bits)
#define TWDR_TWD0        0u
#define TWDR_TWD1        1u
#define TWDR_TWD2        2u
#define TWDR_TWD3        3u
#define TWDR_TWD4        4u
#define TWDR_TWD5        5u
#define TWDR_TWD6        6u
#define TWDR_TWD7        7u

// TWI Address Register (TWAR)
// Used to configure the slave address of the TWI module
#define TWAR             *((volatile uint8*)0x22)

// Bit positions for TWAR (address and general call enable)
#define TWAR_TWGCE       0u    // TWI General Call Enable
#define TWAR_TWA0        1u    // TWI Address Bit 0
#define TWAR_TWA1        2u    // TWI Address Bit 1
#define TWAR_TWA2        3u    // TWI Address Bit 2
#define TWAR_TWA3        4u    // TWI Address Bit 3
#define TWAR_TWA4        5u    // TWI Address Bit 4
#define TWAR_TWA5        6u    // TWI Address Bit 5
#define TWAR_TWA6        7u    // TWI Address Bit 6

#endif // TWI_REG_H
