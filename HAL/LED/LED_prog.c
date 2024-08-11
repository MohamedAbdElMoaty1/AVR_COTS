#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "LED_interface.h"
#include "LED_prv.h"
#include "LED_cfg.h"



uint8 LED_u8Set_On(const LED_Config_t *Copy_pstrObj)
{
	uint8 Local_u8ErrorState = OK ;
	if(Copy_pstrObj != NULL)
	{
		if((Copy_pstrObj->LED_u8Act_t) == LED_u8ACT_HIGH)
		{
			DIO_u8SetPinValue(Copy_pstrObj->LED_u8Port , Copy_pstrObj->LED_u8Pin ,DIO_u8PIN_HIGH);
		}
		else if((Copy_pstrObj->LED_u8Act_t) == LED_u8ACT_LOW)
		{
			DIO_u8SetPinValue(Copy_pstrObj->LED_u8Port , Copy_pstrObj->LED_u8Pin ,DIO_u8PIN_LOW);
		}

	}

	else
	{
		Local_u8ErrorState = NULL_PTR_ERR ;
	}

	return Local_u8ErrorState ;

}

uint8 LED_u8Set_Off(const LED_Config_t *Copy_pstrObj)
{
	uint8 Local_u8ErrorState = OK ;
	if(Copy_pstrObj != NULL)
	{
		if((Copy_pstrObj->LED_u8Act_t) == LED_u8ACT_HIGH)
		{
			DIO_u8SetPinValue(Copy_pstrObj->LED_u8Port , Copy_pstrObj->LED_u8Pin ,DIO_u8PIN_LOW);
		}
		else if((Copy_pstrObj->LED_u8Act_t) == LED_u8ACT_LOW)
		{
			DIO_u8SetPinValue(Copy_pstrObj->LED_u8Port , Copy_pstrObj->LED_u8Pin ,DIO_u8PIN_HIGH);
		}
	}

	else
	{
		Local_u8ErrorState = NULL_PTR_ERR ;
	}

	return Local_u8ErrorState ;

}
uint8 LED_u8Toggle(const LED_Config_t *Copy_pstrObj)
{
	uint8 Local_u8ErrorState = OK ;
	if(Copy_pstrObj != NULL)
	{
		DIO_u8TogglePinValue(Copy_pstrObj->LED_u8Port,Copy_pstrObj->LED_u8Pin);
	}

	else
	{
		Local_u8ErrorState = NULL_PTR_ERR ;
	}

	return Local_u8ErrorState ;

}
