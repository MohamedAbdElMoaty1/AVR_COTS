#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void SPI_voidMasterInit(void);
void SPI_voidSalveInit(void);
void SPI_voidSendByte(uint8 copy_u8Data_Byte);
uint8 SPI_u8ReceiveByte(void);
void SPI_voidSend_Buffer(uint8 *Copy_u8Data);
void SPI_voidSend_Buffer(uint8 *Copy_u8Data);
void MSPI_VidSPI_SetCallBack(void(*Copy_ptrCallBack)(void));


#endif //SPI_INTERFACE_H
