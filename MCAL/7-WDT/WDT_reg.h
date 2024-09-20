#ifndef WDT_REG_H
#define WDT_REG_H

// Watchdog Timer Control Register (WDTCR)
#define WDTCR            *((volatile uint8*)0x41)   // Define WDTCR at memory address 0x41

// Bit positions in the WDTCR register
#define WDTCR_WDTOE      4u   // Watchdog Turn-off Enable (WDTOE) bit
#define WDTCR_WDE        3u   // Watchdog Enable (WDE) bit
#define WDTCR_WDP2       2u   // Watchdog Timer Prescaler bit 2 (WDP2)
#define WDTCR_WDP1       1u   // Watchdog Timer Prescaler bit 1 (WDP1)
#define WDTCR_WDP0       0u   // Watchdog Timer Prescaler bit 0 (WDP0)

#endif // WDT_REG_H
