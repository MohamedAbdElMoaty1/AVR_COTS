#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "SSD_interface.h"
#include "SSD_prv.h"
#include "SSD_cfg.h"

uint8 SSD_u8On(const SSD_u8Config_t *Copy_pstr_obj)
{
	uint8 Local_u8ErrorState = OK ;

	if(Copy_pstr_obj != NULL)
	{
		if(Copy_pstr_obj->SSD_u8type == SSD_u8ANODE || Copy_pstr_obj->SSD_u8type == SSD_u8ETA_KIT)
		{
			DIO_u8SetPinValue(Copy_pstr_obj -> SSD_u8Enable_Port,Copy_pstr_obj -> SSD_u8Enable_Pin, DIO_u8PIN_HIGH);
		}
		else if(Copy_pstr_obj->SSD_u8type == SSD_u8CATHODE )
		{
			DIO_u8SetPinValue(Copy_pstr_obj -> SSD_u8Enable_Port,Copy_pstr_obj -> SSD_u8Enable_Pin, DIO_u8PIN_LOW);
		}
		else
		{
			Local_u8ErrorState = NOK ;
		}

	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR ;
	}
	return Local_u8ErrorState ;

}

uint8 SSD_u8Off(const SSD_u8Config_t *Copy_pstr_obj)
{
	uint8 Local_u8ErrorState = OK ;
	if(Copy_pstr_obj != NULL)
	{
		if(Copy_pstr_obj->SSD_u8type == SSD_u8ANODE || Copy_pstr_obj -> SSD_u8type == SSD_u8ETA_KIT)
		{
			DIO_u8SetPinValue(Copy_pstr_obj -> SSD_u8Enable_Port,Copy_pstr_obj -> SSD_u8Enable_Pin, DIO_u8PIN_LOW);
		}
		else if(Copy_pstr_obj->SSD_u8type == SSD_u8CATHODE )
		{
			DIO_u8SetPinValue(Copy_pstr_obj -> SSD_u8Enable_Port,Copy_pstr_obj -> SSD_u8Enable_Pin, DIO_u8PIN_HIGH);
		}
		else
		{
			Local_u8ErrorState = NOK ;
		}

	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR ;
	}
	return Local_u8ErrorState ;
}

uint8 SSD_u8SetNumber(const SSD_u8Config_t *Copy_pstr_obj , uint8 Copy_u8Number)
{

	uint8 Local_u8ErrorState = OK ;

	uint8 SSD_ArrNum[10]= {
			0b00111111,  //0
			0b00000110,  //1
			0b01011011,  //2
			0b01001111,  //3
			0b01100110,  //4
			0b01101101,  //5
			0b01111101,  //6
			0b00000111,  //7
			0b01111111,  //8
			0b01101111,  //9
	};

	if(Copy_pstr_obj != NULL)
	{

		if(Copy_pstr_obj -> SSD_u8type == SSD_u8ANODE)
		{
			if(Copy_pstr_obj -> SSD_u8LedA_Pin == SSD_u8PINA0)
			{
				DIO_u8SetPortValue(Copy_pstr_obj -> SSD_u8Led_Port , ~(SSD_ArrNum[Copy_u8Number]) );
			}
			else if(Copy_pstr_obj->SSD_u8LedA_Pin == SSD_u8PINA1)
			{
				DIO_u8SetPortValue(Copy_pstr_obj -> SSD_u8Led_Port , ~(SSD_ArrNum[Copy_u8Number]<<1) );
			}
			else
			{
				Local_u8ErrorState = NOK ;
			}
		}
		else if(Copy_pstr_obj -> SSD_u8type == SSD_u8CATHODE || Copy_pstr_obj -> SSD_u8type == SSD_u8ETA_KIT )
		{
			if(Copy_pstr_obj -> SSD_u8LedA_Pin == SSD_u8PINA0)
			{
				DIO_u8SetPortValue(Copy_pstr_obj -> SSD_u8Led_Port ,(SSD_ArrNum[Copy_u8Number]) );
			}
			else if(Copy_pstr_obj -> SSD_u8LedA_Pin == SSD_u8PINA1)
			{
				DIO_u8SetPortValue(Copy_pstr_obj -> SSD_u8Led_Port ,(SSD_ArrNum[Copy_u8Number]<<1) );
			}
			else
			{
				Local_u8ErrorState = NOK ;
			}
		}

		else
		{
			Local_u8ErrorState = NOK ;
		}

	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR ;
	}
	return Local_u8ErrorState ;
}

