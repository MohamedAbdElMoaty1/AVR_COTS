#ifndef ADC_CFG_H
#define ADC_CFG_H


/*configure the ADC prescaler division factor, options:   1- DIVISION_BY_2
 *                                                        2- DIVISION_BY_4
 *                                                        3- DIVISION_BY_8
 *                                                        4- DIVISION_BY_16
 *                                                        5- DIVISION_BY_32
 *                                                        6- DIVISION_BY_64
 *                                                        7- DIVISION_BY_128
 * */
#define ADC_u8PRESCALER_DIVISION_FACTOR                      DIVISION_BY_128


/*configure the ADC resolution, options: 1- EIGHT_BITS
 *                                       2- TEN_BITS
 * */
#define ADC_u8Resolution                    EIGHT_BITS


/*configure the ADC reference voltage, options: 1- AVCC
 *                                              2- AREF
 * */
#define ADC_u8Reference_Voltage                    AVCC

#endif //ADC_CFG_H
