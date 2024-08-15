#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "DCMotor_interface.h"
#include "DCMotor_prv.h"
#include "DCMotor_cfg.h"





uint8 DCMotor_u8RotateCW(DCMotor_u8Config_t *Copy_pstr_obj)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_pstr_obj != NULL)
	{
		DIO_u8SetPinValue(Copy_pstr_obj->Port,Copy_pstr_obj->Pin2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pstr_obj->Port,Copy_pstr_obj->Pin1,DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState ;
}
uint8 DCMotor_u8RotateCCW(DCMotor_u8Config_t *Copy_pstr_obj)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_pstr_obj != NULL)
	{
		DIO_u8SetPinValue(Copy_pstr_obj->Port,Copy_pstr_obj->Pin1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pstr_obj->Port,Copy_pstr_obj->Pin2,DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState = NOK;

	}
	return Local_u8ErrorState ;

}

uint8 DCMotor_u8Stop(DCMotor_u8Config_t *Copy_pstr_obj)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_pstr_obj != NULL)
	{
		DIO_u8SetPinValue(Copy_pstr_obj->Port,Copy_pstr_obj->Pin1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pstr_obj->Port,Copy_pstr_obj->Pin2,DIO_u8PIN_LOW);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState ;
}

