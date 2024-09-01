#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H



typedef struct
{
	uint8   ChainSize ;
	uint8*  ChannelArr;
	uint16* ResultArr;
	void(*NotificationFunc)(void);
}ADC_Chain_t;

void ADC_voidInit(void);
uint16 ADC_u8StartSingleConversionSynch(uint8 Coppy_u8Channel , uint16* Copy_pu16Result);
uint16 ADC_u8StartSingleConversionAsynch(uint8 Coppy_u8Channel , uint16* Copy_pu16Result , void(*Copy_pvNotificationFunc)(void));

uint8 ADC_u8StartChainConversionAsynch(const ADC_Chain_t* Copy_Obj);


#endif //ADC_INTERFACE_H
