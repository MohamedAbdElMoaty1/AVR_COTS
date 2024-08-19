#include "STD_TYPES.h"
#include "ErrType.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "StepperMotor_interface.h"
#include "StepperMotor_prv.h"
#include "StepperMotor_cfg.h"



uint8 STP_u8Rotate(STP_u8cfg_t *Copy_pstr_obj ,uint8 Copy_u8Direction , uint16 Copy_u8Angle)
{
	uint8  Local_u8ErrorState   = OK;
	uint16 Local_u8STP_FullStep = 0;
	uint16 Local_u8Loop_Counter = 0;

	if(Copy_pstr_obj != NULL)
	{
		Local_u8STP_FullStep = (uint16)(((uint32)Copy_u8Angle * (uint32)2048) / (uint32)360);

		if(Copy_u8Direction == STP_u8RCW)
		{

			for(Local_u8Loop_Counter = 0 ; Local_u8Loop_Counter <= Local_u8STP_FullStep ; Local_u8Loop_Counter++ )
			{
				if( (Local_u8Loop_Counter%4) == 0)
				{
					DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->BLue_Wire,DIO_u8PIN_HIGH);
					DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Pink_Wire,DIO_u8PIN_HIGH);
					DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Yellow_Wire,DIO_u8PIN_HIGH);
					DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Orange_Wire,DIO_u8PIN_LOW);
					_delay_ms(2);
				}

				if( (Local_u8Loop_Counter%4) == 1)
				{
					DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->BLue_Wire,DIO_u8PIN_HIGH);
					DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Pink_Wire,DIO_u8PIN_HIGH);
					DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Yellow_Wire,DIO_u8PIN_LOW);
					DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Orange_Wire,DIO_u8PIN_HIGH);
					_delay_ms(2);
				}
				if( (Local_u8Loop_Counter%4) == 2)
				{
					DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->BLue_Wire,DIO_u8PIN_HIGH);
					DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Pink_Wire,DIO_u8PIN_LOW);
					DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Yellow_Wire,DIO_u8PIN_HIGH);
					DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Orange_Wire,DIO_u8PIN_HIGH);
					_delay_ms(2);
				}

				if( (Local_u8Loop_Counter%4) == 3)
				{
					DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->BLue_Wire,DIO_u8PIN_LOW);
					DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Pink_Wire,DIO_u8PIN_HIGH);
					DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Yellow_Wire,DIO_u8PIN_HIGH);
					DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Orange_Wire,DIO_u8PIN_HIGH);
					_delay_ms(2);
				}
			}

		}
		else if(Copy_u8Direction == STP_u8RCCW)
		{
			for(Local_u8Loop_Counter = 0 ; Local_u8Loop_Counter <= Local_u8STP_FullStep ; Local_u8Loop_Counter++ )
			{

				if( (Local_u8Loop_Counter%4) == 0)
				{
				DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->BLue_Wire,DIO_u8PIN_LOW);
				DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Pink_Wire,DIO_u8PIN_HIGH);
				DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Yellow_Wire,DIO_u8PIN_HIGH);
				DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Orange_Wire,DIO_u8PIN_HIGH);
				_delay_ms(2);
				}

				if( (Local_u8Loop_Counter%4) == 1)
				{
				DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->BLue_Wire,DIO_u8PIN_HIGH);
				DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Pink_Wire,DIO_u8PIN_LOW);
				DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Yellow_Wire,DIO_u8PIN_HIGH);
				DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Orange_Wire,DIO_u8PIN_HIGH);
				_delay_ms(2);
				}

				if( (Local_u8Loop_Counter%4) == 2)
				{
				DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->BLue_Wire,DIO_u8PIN_HIGH);
				DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Pink_Wire,DIO_u8PIN_HIGH);
				DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Yellow_Wire,DIO_u8PIN_LOW);
				DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Orange_Wire,DIO_u8PIN_HIGH);
				_delay_ms(2);
				}

				if( (Local_u8Loop_Counter%4) == 3)
				{
				DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->BLue_Wire,DIO_u8PIN_HIGH);
				DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Pink_Wire,DIO_u8PIN_HIGH);
				DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Yellow_Wire,DIO_u8PIN_HIGH);
				DIO_u8SetPinDirection(Copy_pstr_obj->Port_Wire,Copy_pstr_obj->Orange_Wire,DIO_u8PIN_LOW);
				_delay_ms(2);
				}

			}
		}

		else
		{
			Local_u8ErrorState = NOK;
		}

	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}




