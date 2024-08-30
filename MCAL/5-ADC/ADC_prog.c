#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"

#include "ADC_reg.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"
#include "ADC_interface.h"

/* Global pointers for ADC result and callback function */
static uint16* ADC_pu16Result = NULL;
static void(*ADC_pvCallBackNotificationFunc)(void) = NULL;

/* Busy flag to indicate if ADC is currently in use */
static uint8 ADC_u8BusyFlag = IDEL;

/* Function to initialize the ADC */
void ADC_voidInit(void)
{
	/* Configure the reference voltage for ADC */
#if ADC_u8Reference_Voltage == AVCC
	/* Set AVCC as reference voltage */
	SET_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);
#elif ADC_u8Reference_Voltage == AREF
	/* Set AREF as reference voltage */
	CLR_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);
#else
#error wrong ADC_u8Reference_Voltage configuration
#endif

	/* Set data format to Left/Right Adjust according to resolution */
#if ADC_u8Resolution == EIGHT_BITS
	SET_BIT(ADMUX, ADMUX_ADLAR);
#elif ADC_u8Resolution == TEN_BITS
	CLR_BIT(ADMUX, ADMUX_ADLAR);
#else
#error wrong ADC_u8Resolution configuration
#endif

	/* Disable auto trigger and interrupt initially */
	CLR_BIT(ADCSRA, ADCSRA_ADATE);
	CLR_BIT(ADCSRA, ADCSRA_ADIE);

	/* Enable ADC */
	SET_BIT(ADCSRA, ADCSRA_ADEN);

	/* Configure the prescaler division factor */
	ADCSRA &= PRESCALER_BIT_MASK; // Clear the prescaler bits
	ADCSRA |= ADC_u8PRESCALER_DIVISION_FACTOR << PRESCALER_BIT_POS;
}

/* Function for synchronous ADC conversion */
uint16 ADC_u8StartConversionSynch(uint8 Copy_u8Channel, uint16* Copy_pu16Result)
{
	uint8  Local_u8Error_State = OK; // Variable to hold error state
	uint32 Local_u32Counter    = 0u;


	if (Copy_pu16Result != NULL)
	{
		/* Check if ADC is idle */
		if (ADC_u8BusyFlag == IDEL)
		{
			ADC_u8BusyFlag = BUSY; // Mark ADC as busy

			/* Set the input channel */
			ADMUX &= CHANNEL_BIT_MASK; // Clear the channel selection bits
			ADMUX |= Copy_u8Channel;

			/* Start conversion */
			SET_BIT(ADCSRA, ADCSRA_ADSC);

			/* Polling for conversion complete or timeout */
			while (((GET_BIT(ADCSRA, ADCSRA_ADIF)) == 0) && (Local_u32Counter < ADC_u32TIMEOUT))
			{
				Local_u32Counter++;
			}

			if (Local_u32Counter == ADC_u32TIMEOUT)
			{
				Local_u8Error_State = TIMEOUT_ERR; // Timeout error
			}
			else
			{
				/* Clear the conversion complete flag */
				SET_BIT(ADCSRA, ADCSRA_ADIF);

				/* Get the ADC result based on resolution */
#if ADC_u8Resolution == EIGHT_BITS
				*Copy_pu16Result = ADCH; // 8-bit result
#elif ADC_u8Resolution == TEN_BITS
				*Copy_pu16Result = ADC; // 10-bit result
#endif
			}

			ADC_u8BusyFlag = IDEL; // Mark ADC as idle
		}
		else
		{
			Local_u8Error_State = BUSY_ERR; // ADC is busy error
		}
	}
	else
	{
		Local_u8Error_State = NULL_PTR_ERR; // Null pointer error
	}

	return Local_u8Error_State;
}

/* Function for asynchronous ADC conversion */
uint16 ADC_u8StartConversionAsynch(uint8 Copy_u8Channel, uint16* Copy_pu16Result, void(*Copy_pvNotificationFunc)(void))
{
	uint8 Local_u8Error_State = OK;

	if ((Copy_pu16Result != NULL) && (Copy_pvNotificationFunc != NULL))
	{
		/* Check if ADC is idle */
		if (ADC_u8BusyFlag == IDEL)
		{
			ADC_u8BusyFlag = BUSY; // Mark ADC as busy

			/* Set global pointers to hold the result and callback function */
			ADC_pu16Result = Copy_pu16Result;
			ADC_pvCallBackNotificationFunc = Copy_pvNotificationFunc;

			/* Set the input channel */
			ADMUX &= CHANNEL_BIT_MASK; // Clear the channel selection bits
			ADMUX |= Copy_u8Channel;

			/* Start conversion */
			SET_BIT(ADCSRA, ADCSRA_ADSC);

			/* Enable ADC interrupt */
			SET_BIT(ADCSRA, ADCSRA_ADIE);

		}
		else
		{
			Local_u8Error_State = BUSY_ERR ;    // ADC is busy error
		}


	}
	else
	{
		Local_u8Error_State = NULL_PTR_ERR; // Null pointer error
	}

	return Local_u8Error_State;
}

/* ADC Conversion Complete Interrupt Service Routine (ISR) */
__attribute__((signal)) void __vector_16(void);
void __vector_16(void)
{
	/* Get the ADC result based on resolution */
#if ADC_u8Resolution == EIGHT_BITS
	*ADC_pu16Result = ADCH; // 8-bit result
#elif ADC_u8Resolution == TEN_BITS
	*ADC_pu16Result = ADC; // 10-bit result
#endif

	/* Disable ADC interrupt */
	CLR_BIT(ADCSRA, ADCSRA_ADIE);

	ADC_u8BusyFlag = IDEL; // Mark ADC as idle

	/* Call the user-provided callback function */
	if (ADC_pvCallBackNotificationFunc != NULL)
	{
		ADC_pvCallBackNotificationFunc();
	}
}
