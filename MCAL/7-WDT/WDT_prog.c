#include "STD_TYPES.h"    // Standard data types (e.g., uint8, etc.)
#include "BIT_MATH.h"     // Bit manipulation macros (e.g., SET_BIT, CLEAR_BIT)
#include "ErrType.h"      // Error types (e.g., OK, NOK)

#include "WDT_interface.h" // WDT interface header
#include "WDT_cfg.h"       // WDT configuration header
#include "WDT_prv.h"       // WDT private header
#include "WDT_reg.h"       // WDT register definitions header

// Function to enable the Watchdog Timer (WDT)
void WDT_voidOn(void)
{
    // Set the WDE (Watchdog Enable) bit in WDTCR to turn on the WDT
    SET_BIT(WDTCR, WDTCR_WDE);
}

// Function to disable the Watchdog Timer (WDT)
void WDT_voidOff(void)
{
    /* Write logical one to both WDTOE (Watchdog Turn-off Enable) and WDE (Watchdog Enable) */
    WDTCR = (1 << WDTCR_WDTOE) | (1 << WDTCR_WDE);

    /* Wait for 4 clock cycles and then write 0x00 to WDTCR to turn off the WDT */
    WDTCR = 0x00;
}

// Function to set the Watchdog Timer timeout period
// Input: WDT_time Time - enumeration representing the desired timeout period
uint8 WDT_u8SetTime(WDT_time Time)
{
    uint8 Local_u8Error_State = OK;  // Variable to hold error state

    // Clear the lower three bits of WDTCR to prepare for setting the timeout value
    // Then set the appropriate bits based on the specified timeout period
    switch(Time)
    {
        case time_16_3_ms: WDTCR &= 0b11111000; WDTCR |= 0b000;  break;  // Timeout: 16.3 ms
        case time_32_5_ms: WDTCR &= 0b11111000; WDTCR |= 0b001;  break;  // Timeout: 32.5 ms
        case time_65_ms  : WDTCR &= 0b11111000; WDTCR |= 0b010;  break;  // Timeout: 65 ms
        case time_0_13_s : WDTCR &= 0b11111000; WDTCR |= 0b011;  break;  // Timeout: 0.13 seconds
        case time_0_26_s : WDTCR &= 0b11111000; WDTCR |= 0b100;  break;  // Timeout: 0.26 seconds
        case time_0_52_s : WDTCR &= 0b11111000; WDTCR |= 0b101;  break;  // Timeout: 0.52 seconds
        case time_1_0_s  : WDTCR &= 0b11111000; WDTCR |= 0b110;  break;  // Timeout: 1 second
        case time_2_1_s  : WDTCR &= 0b11111000; WDTCR |= 0b111;  break;  // Timeout: 2.1 seconds
        default          : Local_u8Error_State = NOK;           break;   // If invalid timeout, set error state
    }

    return Local_u8Error_State;  // Return the error state (OK or NOK)
}

// Function to reset the Watchdog Timer (WDT)
void WDT_Reset(void)
{
    // Assembly instruction to reset the WDT
    __asm volatile("WDR");
}
