#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "ADC_interface.h"

#include "LM35_interface.h"
#include "LM35_prv.h"
#include "LM35_cfg.h"

void LM35_voidInit(void)
{
	ADC_voidInit();
}

uint16 LM35_uint8GetTempFrom8BitADC(uint8 copy_uint8ADC_Channel)
{
	uint16 Local_u8DigitalRes = 0;
	uint16 Local_u16TempValue = 0;


	ADC_u8StartSingleConversionSynch(copy_uint8ADC_Channel, &Local_u8DigitalRes);
	Local_u16TempValue = (Local_u8DigitalRes * 500) / 256;

	return Local_u16TempValue;
}

uint16 LM35_uint8GetTempFrom10BitADC(uint8 copy_uint8ADC_Channel)
{
	uint16 Local_u8DigitalRes = 0;
	uint16 Local_u16TempValue = 0;


	ADC_u8StartSingleConversionSynch(copy_uint8ADC_Channel, &Local_u8DigitalRes);
	Local_u16TempValue = ((uint32)Local_u8DigitalRes * 500) / 1024 ;

	return Local_u16TempValue;
}
