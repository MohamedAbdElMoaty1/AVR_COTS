#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

void EEPROM_voidWriteDataByte(uint16 Copy_u16LocAddress , uint8 Copy_u8DataByte);

uint8 EEPROM_voidReadDataByte(uint16 Copy_u16LocAddress);


#endif //EEPROM_INTERFACE_H
