#include "STD_TYPES.h"
#include "ErrType.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "DIO_interface.h"
#include "DAC_interface.h"
#include "DAC_prv.h"
#include "DAC_cfg.h"

/*
 * Function: DAC_voidInit
 * -----------------------
 * Initializes the DAC by setting the direction of the specified port to output.
 * This function must be called before using the DAC to set an analog voltage.
 */
void DAC_voidInit(void)
{
    // Set the direction of the entire port defined by DAC_u8PORT to output.
    DIO_u8SetPortDirection(DAC_u8PORT, DIO_u8PORT_OUTPUT);
}

/*
 * Function: DAC_voidSetAnalogVolt
 * --------------------------------
 * Sets the analog output voltage of the DAC.
 *
 * Parameters:
 *   - Copy_u16mVolt: The desired output voltage in millivolts.
 *
 * Description:
 *   The function converts the desired analog voltage (in millivolts) to the corresponding digital value.
 *   The digital value is then sent to the port connected to the DAC.
 */
void DAC_voidSetAnalogVolt(uint16 Copy_u16mVolt)
{
    // Variable to store the digital value corresponding to the desired analog voltage.
    f32 Local_s16Digital = 0;

    // This variable is unused in the current code, but might have been intended for other purposes.
    sint16 Local_s16Counter = 0;

    // Convert the desired analog voltage (in millivolts) to the corresponding digital value.
    // StepSize is assumed to be a macro or constant defined in DAC_prv.h or DAC_cfg.h
    Local_s16Digital = (Copy_u16mVolt / (StepSize) );

    // Set the port value to the calculated digital value.
    // The port will output this digital value, which will correspond to the desired analog voltage.
    DIO_u8SetPortValue(DAC_u8PORT, (uint16)Local_s16Digital);
}
