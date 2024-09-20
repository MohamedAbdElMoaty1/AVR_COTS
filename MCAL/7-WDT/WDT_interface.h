#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H

// Enumeration for different WDT timeout periods
typedef enum
{
    time_16_3_ms,  // WDT timeout period: 16.3 milliseconds
    time_32_5_ms,  // WDT timeout period: 32.5 milliseconds
    time_65_ms,    // WDT timeout period: 65 milliseconds
    time_0_13_s,   // WDT timeout period: 0.13 seconds
    time_0_26_s,   // WDT timeout period: 0.26 seconds
    time_0_52_s,   // WDT timeout period: 0.52 seconds
    time_1_0_s,    // WDT timeout period: 1 second
    time_2_1_s     // WDT timeout period: 2.1 seconds
} WDT_time;  // Type definition for the available WDT timeout options

// Function to enable the Watchdog Timer (WDT)
// This function sets the WDE (Watchdog Enable) bit, which starts the WDT.
void WDT_voidOn(void);

// Function to disable the Watchdog Timer (WDT)
// This function turns off the WDT by clearing the WDE and WDTOE bits after 4 clock cycles.
void WDT_voidOff(void);

// Function to set the Watchdog Timer timeout period
// Input: WDT_time Time - Enumeration value representing the desired timeout period.
// This function adjusts the timeout of the WDT by configuring the lower 3 bits of WDTCR.
uint8 WDT_u8SetTime(WDT_time Time);

// Function to reset the Watchdog Timer (WDT)
// This function prevents the WDT from triggering a system reset by restarting the timer countdown.
void WDT_Reset(void);

#endif // WDT_INTERFACE_H
