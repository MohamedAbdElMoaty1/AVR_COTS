#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "Timers_interface.h"
#include "GIE_interface.h"

#include "Ultrasonic_interface.h"
#include "Ultrasonic_prv.h"
#include "Ultrasonic_cfg.h"


static volatile uint16  Glaobal_u16T1 = 0 ;
static volatile uint16  Glaobal_u16T2 = 0 ;
static volatile uint8 Glaobal_u8Flag  = 0 ;
static volatile uint8 Glaobal_u8Capflag  = 0 ;
static volatile uint32 Global_u32ONTicks = 0 ;


static void Ultrasonic_Trigger(Ultrasonic_t *Ultrasonic_Config)
{
	DIO_u8SetPinValue(Ultrasonic_Config->Port , Ultrasonic_Config->Trigger_Pin, DIO_u8PIN_HIGH);
	_delay_us(10);
	DIO_u8SetPinValue(Ultrasonic_Config->Port , Ultrasonic_Config->Trigger_Pin, DIO_u8PIN_LOW);
}


uint8 Ultrasonic_Init(Ultrasonic_t *Ultrasonic_Config)
{
	uint8 Local_u8Error_State = OK ;
	if (Ultrasonic_Config != NULL)
	{
		DIO_u8SetPinDirection(Ultrasonic_Config->Port , Ultrasonic_Config->Trigger_Pin, DIO_u8PIN_OUTPUT);
		DIO_u8SetPinDirection(Ultrasonic_Config->Port , Ultrasonic_Config->Echo_Pin, DIO_u8PIN_INPUT);

		Timers1_u16Edge_Select(Rising_edge_HWICU);
		Timer_u8SetcallBack(TIMER1_HWICU_INT,&Ultrasonic_ISR);
		GIE_voidEnableGlobal();
	}
	else
	{
		Local_u8Error_State = NOK;
	}
	return Local_u8Error_State;
}

uint16 Ultrasonic_GetDistance(Ultrasonic_t *Ultrasonic_Config)
{
	f32    Time = 0;
	uint16 distance = 0;
	Timer1_cfg_t timer1Config =
	{
			.Ch_Mode   = Channel_A,
			.Com1_Mode = Timer1_Normal_port ,
			.WFG1_Mode = Timer1_Normal_Mode ,
			.Clk_Mode  = clk_8
	};

	Timers1_u8Init(&timer1Config);
	Timer_u8IntEnable(TIMER1_HWICU_INT);

	Timers1_u16Enable_Noise_Canceler();
	GIE_voidEnableGlobal();

	Ultrasonic_Trigger(Ultrasonic_Config);

	if (Glaobal_u8Capflag==1)
	{
		Global_u32ONTicks = (Glaobal_u16T2 - Glaobal_u16T1) ;
		Time =(f32)((f64)Global_u32ONTicks*(0.5 / 1000000.0));
		distance = Time*34645.0/2.0;
		Glaobal_u8Capflag=0;

	}
	return distance;
}

void Ultrasonic_ISR()
{
	if (Glaobal_u8Flag == 0)
	{
		Glaobal_u16T1 = Timers1_u16GetICR1Value() ;
		Glaobal_u8Flag = 1;
		Timers1_u16Edge_Select(Falling_edge_HWICU);
	}
	else if (Glaobal_u8Flag == 1)
	{
		Glaobal_u16T2 = Timers1_u16GetICR1Value() ;
		Timers1_u16Edge_Select(Rising_edge_HWICU);
		Glaobal_u8Capflag=1;
		Glaobal_u8Flag =0;
	}
}
