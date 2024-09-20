#ifndef TIMERS_REG_H
#define TIMERS_REG_H

// Timer/Counter Control Register 0 (8-bit timer)
#define TCCR0          *((volatile uint8*)0x53)

// Bit positions for Timer/Counter Control Register 0
#define TCCR0_FOC0           7u   // Force Output Compare
#define TCCR0_WGM00          6u   // Waveform Generation Mode bit 0
#define TCCR0_COM01          5u   // Compare Match Output Mode bit 1
#define TCCR0_COM00          4u   // Compare Match Output Mode bit 0
#define TCCR0_WGM01          3u   // Waveform Generation Mode bit 1
#define TCCR0_CS02           2u   // Clock Select bit 2
#define TCCR0_CS01           1u   // Clock Select bit 1
#define TCCR0_CS00           0u   // Clock Select bit 0

// Timer/Counter Register 0 (counts timer ticks)
#define TCNT0          *((volatile uint8*)0x52)

// Output Compare Register 0 (compare value for timer 0)
#define OCR0           *((volatile uint8*)0x5C)

// Timer Interrupt Mask Register
#define TIMSK          *((volatile uint8*)0x59)

// Bit positions for Timer Interrupt Mask Register
#define TIMSK_TOIE0          0u   // Timer Overflow Interrupt Enable for Timer 0
#define TIMSK_OCIE0          1u   // Output Compare Match Interrupt Enable for Timer 0
#define TIMSK_TOIE1          2u   // Timer Overflow Interrupt Enable for Timer 1
#define TIMSK_OCIE1B         3u   // Output Compare Match B Interrupt Enable for Timer 1
#define TIMSK_OCIE1A         4u   // Output Compare Match A Interrupt Enable for Timer 1
#define TIMSK_TICIE1         5u   // Timer Input Capture Interrupt Enable for Timer 1
#define TIMSK_TOIE2          6u   // Timer Input Capture Interrupt Enable for Timer 1
#define TIMSK_OCIE2          7u   // Timer Input Capture Interrupt Enable for Timer 1

// Timer Interrupt Flag Register (flags for timer events)
#define TIFR           *((volatile uint8*)0x58)

// Timer/Counter Control Register 1A (controls specific timer 1 settings)
#define TCCR1A           *((volatile uint8*)0x4F)

// Bit positions for Timer/Counter Control Register 1A
#define TCCR1A_WGM10     0u   // Waveform Generation Mode bit 0 for Timer 1
#define TCCR1A_WGM11     1u   // Waveform Generation Mode bit 1 for Timer 1
#define TCCR1A_FOC1B     2u   // Force Output Compare for Channel B
#define TCCR1A_FOC1A     3u   // Force Output Compare for Channel A
#define TCCR1A_COM1B0    4u   // Compare Output Mode for Channel B bit 0
#define TCCR1A_COM1B1    5u   // Compare Output Mode for Channel B bit 1
#define TCCR1A_COM1A0    6u   // Compare Output Mode for Channel A bit 0
#define TCCR1A_COM1A1    7u   // Compare Output Mode for Channel A bit 1

// Timer/Counter Control Register 1B (controls prescaler and other settings for timer 1)
#define TCCR1B           *((volatile uint8*)0x4E)

// Bit positions for Timer/Counter Control Register 1B
#define TCCR1B_CS10      0u   // Clock Select bit 0
#define TCCR1B_CS11      1u   // Clock Select bit 1
#define TCCR1B_CS12      2u   // Clock Select bit 2
#define TCCR1B_WGM12     3u   // Waveform Generation Mode bit 2
#define TCCR1B_WGM13     4u   // Waveform Generation Mode bit 3
#define TCCR1B_ICES1     6u   // Input Capture Edge Select
#define TCCR1B_ICNC1     7u   // Input Capture Noise Canceler

// Input Capture Register 1 High Byte and Low Byte
#define ICR1H            *((volatile uint8*)0x47)
#define ICR1L            *((volatile uint8*)0x46)
#define TOP              *((volatile uint16*)0x46)  // Top value for the timer

// Output Compare Registers for Timer 1A (used for compare match operations)
#define OCR1AL           *((volatile uint8*)0x4A)  // Low byte
#define OCR1AH           *((volatile uint8*)0x4B)  // High byte
#define OCR1A            *((volatile uint16*)0x4A) // 16-bit register

// Output Compare Registers for Timer 1B (used for compare match operations)
#define OCR1BL           *((volatile uint8*)0x48)  // Low byte
#define OCR1BH           *((volatile uint8*)0x49)  // High byte
#define OCR1B            *((volatile uint16*)0x48) // 16-bit register

// Timer/Counter 1 High Byte and Low Byte (holds the current value of the timer)
#define TCNT1H            *((volatile uint8*)0x4D)
#define TCNT1L            *((volatile uint8*)0x4C)
#define TCNT1             *((volatile uint16*)0x4C) // 16-bit register

#define TCCR2             *((volatile uint8*)0x45)

#define TCCR2_CS20        0u
#define TCCR2_CS21        1u
#define TCCR2_CS22        2u
#define TCCR2_WGM21       3u
#define TCCR2_COM20       4u
#define TCCR2_COM21       5u
#define TCCR2_WGM20       6u
#define TCCR2_FOC2        7u

#define TCNT2             *((volatile uint8*)0x44)
#define OCR2              *((volatile uint8*)0x43)

#endif //TIMERS_REG_H
