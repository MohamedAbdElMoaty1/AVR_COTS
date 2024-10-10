/*
 * Includes necessary header files for standard types, bit manipulation macros,
 * delay utility, and TWI (I2C) communication protocol.
 */
#include "STD_TYPES.h"   // Standard data types
#include "BIT_MATH.h"    // Bit manipulation macros
#include "util/delay.h"  // Delay utility

#include "TWI_interface.h"  // TWI (I2C) protocol interface
#include "EEPROM_interface.h" // EEPROM interface for read/write operations
#include "EEPROM_prv.h"      // Private EEPROM macros and definitions
#include "EEPROM_cfg.h"      // EEPROM configuration file


/*
 * Function: EEPROM_voidWriteDataByte
 * ----------------------------------
 * Writes a byte of data to the EEPROM at a specified memory location.
 *
 * Parameters:
 *   Copy_u16LocAddress - The 16-bit memory address where data is to be written.
 *   Copy_u8DataByte    - The byte of data to be written at the specified location.
 *
 * Returns: None
 *
 * Procedure:
 *   1. Calculate the EEPROM slave address using a fixed address, the A2 connection, and
 *      the upper 2 bits of the location address.
 *   2. Send the start condition using the TWI interface.
 *   3. Send the slave address with the write operation.
 *   4. Send the lower byte of the memory location address.
 *   5. Write the data byte to the EEPROM.
 *   6. Send the stop condition to complete the operation.
 *   7. Add a delay of 10ms to ensure the EEPROM has time to write the data.
 */
void EEPROM_voidWriteDataByte(uint16 Copy_u16LocAddress , uint8 Copy_u8DataByte)
{
    // Calculate the EEPROM slave address based on the fixed address, A2, and location address
    uint8 Local_u8SlaveAddress = ( EEPROM_FIXED_ADDRESS | (A2_CONECTION << 2u) | ((Copy_u16LocAddress >> 8u) & 0x3) );

    TWI_enuSendStartCondition(); // Send start condition

    TWI_enuSendSlaveAddressWithWrite(Local_u8SlaveAddress); // Send slave address with write request

    TWI_enuMstrWriteDataByte((uint8) Copy_u16LocAddress); // Send memory address (lower byte)

    TWI_enuMstrWriteDataByte(Copy_u8DataByte); // Send data byte

    TWI_voidSendStopCondition(); // Send stop condition to end communication

    _delay_ms(10); // Delay to allow EEPROM write operation to complete
}

/*
 * Function: EEPROM_voidReadDataByte
 * ---------------------------------
 * Reads a byte of data from the EEPROM at a specified memory location.
 *
 * Parameters:
 *   Copy_u16LocAddress - The 16-bit memory address from which data is to be read.
 *
 * Returns:
 *   The byte of data read from the specified memory location.
 *
 * Procedure:
 *   1. Calculate the EEPROM slave address using a fixed address, the A2 connection, and
 *      the upper 2 bits of the location address.
 *   2. Send the start condition using the TWI interface.
 *   3. Send the slave address with the write operation to specify the memory location.
 *   4. Send the lower byte of the memory location address.
 *   5. Send a repeated start condition to initiate the read operation.
 *   6. Send the slave address with the read operation.
 *   7. Read the data byte from the EEPROM.
 *   8. Send the stop condition to end the communication.
 */
uint8 EEPROM_voidReadDataByte(uint16 Copy_u16LocAddress)
{
    uint8 Local_u8DataByte =  0; // Variable to store the read data byte

    // Calculate the EEPROM slave address based on the fixed address, A2, and location address
    uint8 Local_u8SlaveAddress = ( EEPROM_FIXED_ADDRESS | (A2_CONECTION << 2u) | ((Copy_u16LocAddress >> 8u) & 0x3) );

    TWI_enuSendStartCondition(); // Send start condition

    TWI_enuSendSlaveAddressWithWrite(Local_u8SlaveAddress); // Send slave address with write request

    TWI_enuMstrWriteDataByte((uint8) Copy_u16LocAddress); // Send memory address (lower byte)

    TWI_enuSendRepeatedStart(); // Send repeated start to initiate read operation

    TWI_enuSendSlaveAddressWithRead(Local_u8SlaveAddress); // Send slave address with read request

    TWI_enuMstrReadDataByte(&Local_u8DataByte); // Read data byte from EEPROM

    TWI_voidSendStopCondition(); // Send stop condition to end communication

    return Local_u8DataByte; // Return the read data byte
}
