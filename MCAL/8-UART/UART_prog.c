#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"

#include "UART_interface.h"
#include "UART_prv.h"
#include "UART_cfg.h"
#include "UART_reg.h"



void UART_voidInit(void)
{
	uint8 Local_UCSRC_Value = 0u ;

	/*Receiver and transmitter enable*/
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);

	/*Character size: 8bits*/
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
	SET_BIT(Local_UCSRC_Value,UCSRC_UCSZ1);
	SET_BIT(Local_UCSRC_Value,UCSRC_UCSZ0);

	/*Set register select bit to select UCSRC*/
	SET_BIT(Local_UCSRC_Value,UCSRC_URSEL);

	/*Write the UCSRC register with bit 7 set*/
	UCSRC = Local_UCSRC_Value ;

	UBRRL = 103;
}

void UART_u8SendByte(uint8 Copy_u8Data)
{
	while((GET_BIT(UCSRA,UCSRA_UDRE)) == 0);

	UDR = Copy_u8Data ;
}

uint8 UART_u8ReceiveByte(void)
{
	while((GET_BIT(UCSRA,UCSRA_RXC))== 0);

	return UDR ;
}

void UART_u8SendBufferSync(uint8 *Copy_u8Data, uint8 Copy_u8Size)
{
    uint16 Local_u16Counter = 0;

    for (Local_u16Counter = 0; Local_u16Counter < Copy_u8Size; Local_u16Counter++)
    {
        // Wait until Data Register is Empty (UDRE is set to 1)
        while ((GET_BIT(UCSRA, UCSRA_UDRE)) == 0);

        // Send data by writing to UDR
        UDR = Copy_u8Data[Local_u16Counter];

        // Wait until Transmit Complete (TXC is set to 1)
        while (GET_BIT(UCSRA, UCSRA_TXC) == 0);
    }
}

void UART_u8ReceiveBufferSync(uint8* Copy_u8Data, uint8 Copy_u8Size)
{
	uint16 Local_u16Counter = 0 ;
	for(Local_u16Counter = 0 ; Local_u16Counter < Copy_u8Size ; Local_u16Counter++)
	{
		while((GET_BIT(UCSRA,UCSRA_RXC))== 0);

		Copy_u8Data[Local_u16Counter] = UDR ;
	}
}
