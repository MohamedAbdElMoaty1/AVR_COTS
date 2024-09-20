#ifndef SPI_CFG_H
#define SPI_CFG_H

/* Configure the Interrupt mode:
 * Options:
 *      1 - Interrupt_Enable
 *      2 - Interrupt_Disable
 */
#define SPI_u8Interrupt                       Interrupt_Enable


/* Configure the Data Order mode:
 * Options:
 *      1 - LSB_Data_Order
 *      2 - MSB_Data_Order
 */
#define SPI_u8Data_Order                      MSB_Data_Order


/* Configure the Master or Slave Select mode:
 * Options:
 *      1 - Master
 *      2 - Slave
 */
#define SPI_u8Master_OR_Slave_Select          Master


/* Configure the Clock Polarity mode:
 * Options:
 *      1 - RisingLeading_FallingTrailing
 *      2 - FallingLeading_RisingTrailing
 */
#define SPI_u8Clock_Polarity_Mode             RisingLeading_FallingTrailing


/* Configure the Clock Phase mode:
 * Options:
 *      1 - SampleLeading_SetupTrailing
 *      2 - SetupLeading_SampleTrailing
 */
#define SPI_u8Clock_Phase_Mode                SampleLeading_SetupTrailing


/* Configure the SPI Clock Rate mode:
 * Options:
 *      1 - Prescaler_4
 *      2 - Prescaler_16
 *      3 - Prescaler_64
 *      4 - Prescaler_128
 *      5 - Prescaler_2
 *      6 - Prescaler_8
 *      7 - Prescaler_32
 */
#define SPI_u8Clock_Rate_Mode                 Prescaler_4

#endif // SPI_CFG_H
