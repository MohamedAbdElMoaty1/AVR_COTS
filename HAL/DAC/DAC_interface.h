#ifndef DAC_INTERFACE_H
#define DAC_INTERFACE_H

// Define the port where the DAC output is connected.
// In this case, the DAC is connected to PORTB.
#define DAC_u8PORT          DIO_u8PORTB

// Define the number of bits used by the DAC.
// In this case, the DAC is 8 bits, meaning it has 256 discrete levels (2^8).
#define Number_Of_Bits      Eight_Bits

// Define the step size in millivolts for the DAC.
// Step size is calculated as (Reference Voltage) / (2^Number_Of_Bits).
// Assuming a 5V reference and 8-bit DAC, the step size is approximately 19.6 mV.
#define StepSize            19.6  // 5000 mV / 256 levels

// Function Prototypes

/*
 * Function: DAC_voidInit
 * ----------------------
 * Initializes the DAC by setting the direction of the port to output.
 * This function must be called before setting any analog voltages.
 */
void DAC_voidInit(void);

/*
 * Function: DAC_voidSetAnalogVolt
 * -------------------------------
 * Sets the analog output voltage of the DAC.
 *
 * Parameters:
 *   - Copy_u16mVolt: The desired output voltage in millivolts.
 *
 * Description:
 *   This function converts the input voltage in millivolts to a corresponding digital value
 *   and outputs it to the specified port, generating the appropriate analog voltage.
 */
void DAC_voidSetAnalogVolt(uint16 Copy_u16mVolt);

#endif // DAC_INTERFACE_H
