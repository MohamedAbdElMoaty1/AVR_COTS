#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"

#include "SPI_interface.h"
#include "SPI_prv.h"
#include "SPI_cfg.h"
#include "SPI_reg.h"

static void(*SPI_pvCallBackNotificationFunc)(void) = NULL;



void SPI_voidMasterInit(void)
{

#if SPI_u8Data_Order == LSB_Data_Order
	SET_BIT(SPCR,SPCR_DORD);
#elif SPI_u8Data_Order == MSB_Data_Order
	CLR_BIT(SPCR,SPCR_DORD);
#endif

#if SPI_u8Clock_Polarity_Mode == RisingLeading_FallingTrailing
	CLR_BIT(SPCR,SPCR_CPOL);
#elif SPI_u8Clock_Polarity_Mode == FallingLeading_RisingTrailing
	SET_BIT(SPCR,SPCR_CPOL);
#endif

#if SPI_u8Clock_Phase_Mode == SampleLeading_SetupTrailing
	CLR_BIT(SPCR,SPCR_CPHA);
#elif SPI_u8Clock_Phase_Mode == SetupLeading_SampleTrailing
	SET_BIT(SPCR,SPCR_CPHA);
#endif

#if SPI_u8Clock_Phase_Mode == Prescaler_4
	CLR_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
#elif SPI_u8Clock_Phase_Mode == Prescaler_16
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
#elif SPI_u8Clock_Phase_Mode == Prescaler_64
	CLR_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
#elif SPI_u8Clock_Phase_Mode == Prescaler_128
	SET_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
#elif SPI_u8Clock_Phase_Mode == Prescaler_2
	CLR_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);
#elif SPI_u8Clock_Phase_Mode == Prescaler_8
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);
#elif SPI_u8Clock_Phase_Mode == Prescaler_32
	CLR_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);
#endif

	/*SPI_u8Master_OR_Slave_Select == Master*/
	SET_BIT(SPCR,SPCR_MSTR);

	/*SPI Interrupt Enable*/
	SET_BIT(SPCR,SPCR_SPE);

#if SPI_u8Interrupt == Interrupt_Enable
	SET_BIT(SPCR,SPCR_SPIE);
#elif SPI_u8Interrupt == Interrupt_Disable
	CLR_BIT(SPCR,SPCR_SPIE);
#endif
}

void SPI_voidSalveInit(void)
{

#if SPI_u8Data_Order == MSB_Data_Order
	CLR_BIT(SPCR,SPCR_DORD);
#elif SPI_u8Data_Order == LSB_Data_Order
	SET_BIT(SPCR,SPCR_DORD);
#endif

#if SPI_u8Clock_Polarity_Mode == RisingLeading_FallingTrailing
	CLR_BIT(SPCR,SPCR_CPOL);
#elif SPI_u8Clock_Polarity_Mode == FallingLeading_RisingTrailing
	SET_BIT(SPCR,SPCR_CPOL);
#endif

#if SPI_u8Clock_Phase_Mode == SampleLeading_SetupTrailing
	CLR_BIT(SPCR,SPCR_CPHA);
#elif SPI_u8Clock_Phase_Mode == SetupLeading_SampleTrailing
	SET_BIT(SPCR,SPCR_CPHA);
#endif

	/* SPI_u8Master_OR_Slave_Select == Slave */
	CLR_BIT(SPCR,SPCR_MSTR);

	/*SPI Interrupt Enable*/
	SET_BIT(SPCR,SPCR_SPE);

#if SPI_u8Interrupt == Interrupt_Enable
	SET_BIT(SPCR,SPCR_SPIE);
#elif SPI_u8Interrupt == Interrupt_Disable
	CLR_BIT(SPCR,SPCR_SPIE);
#endif
}

void SPI_voidSendByte(uint8 copy_u8Data_Byte)
{
	SPDR = copy_u8Data_Byte;

	while(!GET_BIT(SPSR,SPSR_SPIF));
}

uint8 SPI_u8ReceiveByte(void)
{
	while(!GET_BIT(SPSR,SPSR_SPIF));

	return SPDR;
}


void SPI_voidSend_Buffer(uint8 *Copy_u8Data)
{
	uint8 Local_u8Counter = 0;
	while(Copy_u8Data[Local_u8Counter]!='\0')
	{
		SPI_voidSendByte(Copy_u8Data[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void SPI_voidReceive_Buffer(uint8 *Copy_u8Data)
{
	static uint8 Local_u8Counter = 0;
	Copy_u8Data[Local_u8Counter] = SPI_u8ReceiveByte();
	Local_u8Counter++;

}

void MSPI_VidSPI_SetCallBack(void(*Copy_ptrCallBack)(void))
{
	SPI_pvCallBackNotificationFunc = Copy_ptrCallBack;
}

__attribute__((signal)) void __vector_12(void);
void __vector_12(void)
{
	SPI_pvCallBackNotificationFunc();
}
