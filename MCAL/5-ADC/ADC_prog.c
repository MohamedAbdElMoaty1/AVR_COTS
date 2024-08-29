#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"

#include "ADC_reg.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"
#include "ADC_interface.h"


void ADC_voidInit(void)
{
#if ADC_u8Reference_Voltage == AVCC
	/*Set AVCC as reference voltage*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif ADC_u8Reference_Voltage == AREF
	/*Set AVCC as reference voltage*/
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#else
#error wrong ADC_u8Reference_Voltage configuration

#endif

	/*Select left adjust or Right adjust according to resolution configuration*/
#if ADC_u8Resolution   == EIGHT_BITS
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif ADC_u8Resolution == TEN_BITS
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#else
#error wrong ADC_u8Resolution configuration

#endif

	/*Disable auto trigger*/
	CLR_BIT(ADCSRA,ADCSRA_ADATE);

	/*Disable interrupt enable*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);

	/*Enable ADC*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);

	/*configure the Prescaler division factor*/
	ADCSRA &= PRESCALER_BIT_MASK;                                          // clear the prescaler bits
	ADCSRA |= ADC_u8PRESCALER_DIVISION_FACTOR << PRESCALER_BIT_POS ;



}

uint16 ADC_u8GetChannelReading(uint8 Coppy_u8Channel)
{

	/*Set the input channel*/
	ADMUX &= CHANNEL_BIT_MASK;              //clear the channel selection bits
	ADMUX |= Coppy_u8Channel;

	/*Start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	/*Polling (with blocking) on the conversion complete*/
	while(!(GET_BIT(ADCSRA,ADCSRA_ADIF)));

	/*clear the conversion complete*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);


#if ADC_u8Resolution   == EIGHT_BITS
	return ADCH ;
#elif ADC_u8Resolution == TEN_BITS
	return ADCL ;
#endif

}



