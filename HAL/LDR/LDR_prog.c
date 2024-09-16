#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "ADC_interface.h"

#include "LDR_interface.h"
#include "LDR_cfg.h"
#include "LDR_prv.h"


void LDR_VoidInit(void)
{
	ADC_voidInit();
}


uint16 LDR_u16GetResistanceFrom8BitADC(uint8 Copy_u8Adc_Channel)
{
	uint16 Local_u16Adc_Res  = 0;
	f32 Local_f32Get_Voltage = 0;
	uint16 Local_u16Ldr_Res  = 0;


	ADC_u8StartSingleConversionSynch(Copy_u8Adc_Channel, &Local_u16Adc_Res);

	// Convert ADC digital result to voltage (assuming an 8-bit ADC, max value = 255)
	Local_f32Get_Voltage = ((float)Local_u16Adc_Res / 255.0) * VREF;

	if (Local_f32Get_Voltage > 0 && Local_f32Get_Voltage < VREF)
	{
		// Use voltage divider formula to calculate LDR resistance
		Local_u16Ldr_Res = (uint16)((R_FIXED * (VREF - Local_f32Get_Voltage)) / Local_f32Get_Voltage);
	}

	return Local_u16Ldr_Res;
}


uint16 LDR_u16GetResistanceFrom10BitADC(uint8 Copy_u8Adc_Channel)
{
	uint16 Local_u16Adc_Res  = 0;
	f32 Local_f32Get_Voltage = 0;
	uint16 Local_u16Ldr_Res  = 0;

	ADC_u8StartSingleConversionSynch(Copy_u8Adc_Channel, &Local_u16Adc_Res);

	// Convert ADC digital result to voltage (assuming a 10-bit ADC, max value = 1023)
	Local_f32Get_Voltage = ((float)Local_u16Adc_Res / 1023.0) * VREF;

	// Ensure voltage is not zero to avoid division by zero
	if (Local_f32Get_Voltage > 0 && Local_f32Get_Voltage < VREF)
	{
		// Use voltage divider formula to calculate LDR resistance
		Local_u16Ldr_Res = (uint16)((R_FIXED * (VREF - Local_f32Get_Voltage)) / Local_f32Get_Voltage);
	}

	return Local_u16Ldr_Res;
}
