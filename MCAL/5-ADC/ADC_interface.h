#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

void ADC_voidInit(void);
uint16 ADC_u8StartConversionSynch(uint8 Coppy_u8Channel , uint16* Copy_pu16Result);
uint16 ADC_u8StartConversionAsynch(uint8 Coppy_u8Channel , uint16* Copy_pu16Result , void(*Copy_pvNotificationFunc)(void));

#endif //ADC_INTERFACE_H
