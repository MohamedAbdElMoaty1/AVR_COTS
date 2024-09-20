#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_voidInit(void);
void UART_u8SendByte(uint8 Copy_u8Data);
uint8 UART_u8ReceiveByte(void);
void UART_u8SendBufferSync(uint8 *Copy_u8Data, uint8 Copy_u8Size);
void UART_u8ReceiveBufferSync(uint8* Copy_u8Data, uint8 Copy_u8Size);

#endif //UART_INTERFACE_H
