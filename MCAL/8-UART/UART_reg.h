#ifndef UART_REG_H
#define UART_REG_H

/* UART Data Register (UDR)
   This register holds the data to be transmitted or received */
#define UDR               *((volatile uint8*)0x2C)

/* UART Control and Status Register A (UCSRA)
   This register contains flags for the status of the UART operations */
#define UCSRA             *((volatile uint8*)0x2B)

/* Bit definitions for UCSRA */
#define UCSRA_RXC         7u  // Receive Complete
#define UCSRA_TXC         6u  // Transmit Complete
#define UCSRA_UDRE        5u  // Data Register Empty
#define UCSRA_FE          4u  // Frame Error
#define UCSRA_DOR         3u  // Data OverRun
#define UCSRA_PE          2u  // Parity Error
#define UCSRA_U2X         1u  // Double the USART Transmission Speed
#define UCSRA_MPCM        0u  // Multi-processor Communication Mode

/* UART Control and Status Register B (UCSRB)
   This register controls the enabling/disabling of transmitter, receiver, and interrupt features */
#define UCSRB             *((volatile uint8*)0x2A)

/* Bit definitions for UCSRB */
#define UCSRB_RXCIE       7u  // RX Complete Interrupt Enable
#define UCSRB_TXCIE       6u  // TX Complete Interrupt Enable
#define UCSRB_UDRIE       5u  // USART Data Register Empty Interrupt Enable
#define UCSRB_RXEN        4u  // Receiver Enable
#define UCSRB_TXEN        3u  // Transmitter Enable
#define UCSRB_UCSZ2       2u  // Character Size Bit 2
#define UCSRB_RXB8        1u  // Receive Data Bit 8 (used in 9-bit data frames)
#define UCSRB_TXB8        0u  // Transmit Data Bit 8 (used in 9-bit data frames)

/* UART Control and Status Register C (UCSRC)
   This register configures the UART frame format, mode of operation, and parity mode */
#define UCSRC             *((volatile uint8*)0x40)

/* Bit definitions for UCSRC */
#define UCSRC_URSEL       7u  // Register Select (must be set to access UCSRC instead of UBRRH)
#define UCSRC_UMSEL       6u  // USART Mode Select (0: Asynchronous, 1: Synchronous)
#define UCSRC_UPM1        5u  // Parity Mode Bit 1
#define UCSRC_UPM0        4u  // Parity Mode Bit 0
#define UCSRC_USBS        3u  // Stop Bit Select (0: 1 stop bit, 1: 2 stop bits)
#define UCSRC_UCSZ1       2u  // Character Size Bit 1
#define UCSRC_UCSZ0       1u  // Character Size Bit 0
#define UCSRC_UCPOL       0u  // Clock Polarity (used in synchronous mode)

/* UART Baud Rate Register High (UBRRH)
   This register holds the high bits of the baud rate */
#define UBRRH             *((volatile uint8*)0x40)

/* Bit definitions for UBRRH */
#define UBRRH_URSEL       7u  // Register Select (shared with UCSRC, must be cleared to access UBRRH)
#define UBRRH_UBRR3       3u  // Baud Rate Bit 3
#define UBRRH_UBRR2       2u  // Baud Rate Bit 2
#define UBRRH_UBRR1       1u  // Baud Rate Bit 1
#define UBRRH_UBRR0       0u  // Baud Rate Bit 0

/* UART Baud Rate Register Low (UBRRL)
   This register holds the low bits of the baud rate */
#define UBRRL             *((volatile uint8*)0x29)

#endif // UART_REG_H
