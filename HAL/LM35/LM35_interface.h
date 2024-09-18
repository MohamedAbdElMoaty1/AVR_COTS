#ifndef LM35_INTERFACE_H
#define LM35_INTERFACE_H

void LM35_voidInit(void);
uint16 LM35_uint8GetTempFrom8BitADC(uint8 copy_uint8ADC_Channel);
uint16 LM35_uint8GetTempFrom10BitADC(uint8 copy_uint8ADC_Channel);

#endif //LM35_INTERFACE_H
