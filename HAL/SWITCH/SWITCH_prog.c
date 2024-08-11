#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "SWITCH_interface.h"
#include "SWITCH_prv.h"
#include "SWITCH_cfg.h"




uint8 SWITCH_u8GetState(const SWITCH_config_t *Copy_pstrObj ,uint8 *Copy_pu8State)
{
	uint8 Local_u8ErrorState = OK ;
	uint8 Local_u8State ;

	if(Copy_pstrObj != NULL  && Copy_pu8State != NULL)
	{

		DIO_u8ReadPinValue(Copy_pstrObj->SWITCH_u8Port,Copy_pstrObj->SWITCH_u8Pin,&Local_u8State);

		if(Copy_pstrObj->SWITCH_u8Pull_t == SWITCH_u8PULL_UPP)
		{
			if(Local_u8State == DIO_u8PIN_HIGH)
			{
				*Copy_pu8State = SWITCH_u8PRESSED ;      /*reverse logic*/
			}
			else if(Local_u8State == DIO_u8PIN_LOW)
			{
				*Copy_pu8State = SWITCH_u8RELEASED ;     /*reverse logic*/
			}
		}
		else if(Copy_pstrObj->SWITCH_u8Pull_t == SWITCH_u8PULL_DOWN)
		{
			if(Local_u8State == DIO_u8PIN_HIGH)
			{
				*Copy_pu8State = SWITCH_u8RELEASED ;     /*reverse logic*/
			}
			else if(Local_u8State == DIO_u8PIN_LOW)
			{
				*Copy_pu8State = SWITCH_u8PRESSED ;      /*reverse logic*/
			}
		}
	}

	else
	{
		Local_u8ErrorState = NULL_PTR_ERR ;
	}

	return Local_u8ErrorState ;
}

