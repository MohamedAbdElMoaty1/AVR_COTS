#ifndef SPI_REG_H
#define SPI_REG_H

// SPI Control Register (SPCR) - Address: 0x2D
#define SPCR          *((volatile uint8*)0x2D)

// SPI Control Register Bit Definitions
#define SPCR_SPR0     0u    // SPI Clock Rate Select Bit 0
#define SPCR_SPR1     1u    // SPI Clock Rate Select Bit 1
#define SPCR_CPHA     2u    // Clock Phase
#define SPCR_CPOL     3u    // Clock Polarity
#define SPCR_MSTR     4u    // Master/Slave Select
#define SPCR_DORD     5u    // Data Order
#define SPCR_SPE      6u    // SPI Enable
#define SPCR_SPIE     7u    // SPI Interrupt Enable

// SPI Status Register (SPSR) - Address: 0x2E
#define SPSR          *((volatile uint8*)0x2E)

// SPI Status Register Bit Definitions
#define SPSR_SPI2X    0u    // Double SPI Speed Bit
#define SPSR_WCOL     6u    // Write Collision Flag
#define SPSR_SPIF     7u    // SPI Interrupt Flag

// SPI Data Register (SPDR) - Address: 0x2F
#define SPDR          *((volatile uint8*)0x2F)

#endif // SPI_REG_H
