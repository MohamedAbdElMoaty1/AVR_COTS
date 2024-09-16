#ifndef LDR_INTERFACE_H
#define LDR_INTERFACE_H

void LDR_VoidInit(void);
uint16 LDR_u16GetResistanceFrom8BitADC(uint8 Copy_u8Adc_Channel);
uint16 LDR_u16GetResistanceFrom10BitADC(uint8 Copy_u8Adc_Channel);

#endif //LDR_INTERFACE_H
