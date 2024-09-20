#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"


#include "Timers_interface.h"
#include "Timers_cfg.h"
#include "Timers_prv.h"
#include "Timers_reg.h"


static void(*Timer_pvCallBackFunc[8])(void) = {NULL};

uint8 Timers0_u8Init(Timer0_cfg_t *Timer0_cfg)
{
	uint8 Local_u8Error_state = OK ;
	/*Waveform Generation Mode*/
	switch(Timer0_cfg->WFG0_Mode)
	{
	case Timer0_Normal_Mode        :CLR_BIT(TCCR0,TCCR0_WGM00); CLR_BIT(TCCR0,TCCR0_WGM01); break;
	case Timer0_PWM_Mode           :SET_BIT(TCCR0,TCCR0_WGM00); CLR_BIT(TCCR0,TCCR0_WGM01); break;
	case Timer0_Phase_Correct_Mode :SET_BIT(TCCR0,TCCR0_WGM00); CLR_BIT(TCCR0,TCCR0_WGM01); break;
	case Timer0_CTC_Mode           :CLR_BIT(TCCR0,TCCR0_WGM00); SET_BIT(TCCR0,TCCR0_WGM01); break;
	case Timer0_Fast_PWM_Mode      :SET_BIT(TCCR0,TCCR0_WGM00); SET_BIT(TCCR0,TCCR0_WGM01); break;
	default                        :Local_u8Error_state = NOK;                              break;
	}

	/*Compare Match Output Mode*/
	switch(Timer0_cfg->Com0_Mode)
	{
	case Timer0_Normal_port                 :CLR_BIT(TCCR0,TCCR0_COM00); CLR_BIT(TCCR0,TCCR0_COM01); break;
	case Timer0_Toggle                      :SET_BIT(TCCR0,TCCR0_COM00); CLR_BIT(TCCR0,TCCR0_COM01); break;
	case Timer0_Reserved                    :SET_BIT(TCCR0,TCCR0_COM00); CLR_BIT(TCCR0,TCCR0_COM01); break;
	case Timer0_Clear                       :CLR_BIT(TCCR0,TCCR0_COM00); SET_BIT(TCCR0,TCCR0_COM01); break;
	case Timer0_Set                         :SET_BIT(TCCR0,TCCR0_COM00); SET_BIT(TCCR0,TCCR0_COM01); break;
	case Timer0_Clear_on_compare_set_at_TOP :CLR_BIT(TCCR0,TCCR0_COM00); SET_BIT(TCCR0,TCCR0_COM01); break;
	case Timer0_set_on_compare_Clear_at_TOP :SET_BIT(TCCR0,TCCR0_COM00); SET_BIT(TCCR0,TCCR0_COM01); break;
	default                                 :Local_u8Error_state = NOK;                              break;

	}

	/*Clock Select*/
	TCCR0 &= 0b11111000;
	switch(Timer0_cfg->Clk_Mode)
	{
	case No_clock                  :TCCR0 |=0b000;            break;
	case No_prescaling             :TCCR0 |=0b001;            break;
	case clk_8                     :TCCR0 |=0b010;            break;
	case clk_64                    :TCCR0 |=0b011;            break;
	case clk_256                   :TCCR0 |=0b100;            break;
	case clk_1024                  :TCCR0 |=0b101;            break;
	case EXTI_clk_T0_falling_edge  :TCCR0 |=0b110;            break;
	case EXTI_clk_T0_rising_edge   :TCCR0 |=0b111;            break;
	default                        :Local_u8Error_state = NOK;break;
	}

	/*Set enable compare match interrupt*/
	//SET_BIT(TIMSK,TIMSK_OCIE0);

	return Local_u8Error_state ;
}


uint8 Timer0_SetCompMode(Timer0_Compare_Output_Mode_t Comp_Mode_t)
{
	uint8 Local_u8Error_state = OK ;
	switch(Comp_Mode_t)
	{
	case Timer0_Normal_port                 :CLR_BIT(TCCR0,TCCR0_COM00); CLR_BIT(TCCR0,TCCR0_COM01); break;
	case Timer0_Toggle                      :SET_BIT(TCCR0,TCCR0_COM00); CLR_BIT(TCCR0,TCCR0_COM01); break;
	case Timer0_Reserved                    :SET_BIT(TCCR0,TCCR0_COM00); CLR_BIT(TCCR0,TCCR0_COM01); break;
	case Timer0_Clear                       :CLR_BIT(TCCR0,TCCR0_COM00); SET_BIT(TCCR0,TCCR0_COM01); break;
	case Timer0_Set                         :SET_BIT(TCCR0,TCCR0_COM00); SET_BIT(TCCR0,TCCR0_COM01); break;
	case Timer0_Clear_on_compare_set_at_TOP :CLR_BIT(TCCR0,TCCR0_COM00); SET_BIT(TCCR0,TCCR0_COM01); break;
	case Timer0_set_on_compare_Clear_at_TOP :SET_BIT(TCCR0,TCCR0_COM00); SET_BIT(TCCR0,TCCR0_COM01); break;

	default                        :Local_u8Error_state = NOK;                              break;
	}
	return Local_u8Error_state;
}

void Timers0_voidSetPreloadValue(uint8 Copy_u8PreloadValue)
{
	TCNT0 = Copy_u8PreloadValue ;
}

void Timers0_voidSetCcmpareMatchValue(uint8 Copy_u8CompMatchValue)
{
	OCR0 = Copy_u8CompMatchValue ;
}

uint16 Timers0_voidGetTCNT0_Value(void)
{
	return TCNT0;
}

/*************************************************************************************************************************/

uint8 Timers2_u8Init(Timer2_cfg_t *Timer2_cfg)
{
	uint8 Local_u8Error_state = OK ;
	/*Waveform Generation Mode*/
	switch(Timer2_cfg->WFG2_Mode)
	{
	case Timer2_Normal_Mode        :CLR_BIT(TCCR2,TCCR2_WGM20); CLR_BIT(TCCR2,TCCR2_WGM21); break;
	case Timer2_PWM_Mode           :SET_BIT(TCCR2,TCCR2_WGM20); CLR_BIT(TCCR2,TCCR2_WGM21); break;
	case Timer2_Phase_Correct_Mode :SET_BIT(TCCR2,TCCR2_WGM20); CLR_BIT(TCCR2,TCCR2_WGM21); break;
	case Timer2_CTC_Mode           :CLR_BIT(TCCR2,TCCR2_WGM20); SET_BIT(TCCR2,TCCR2_WGM21); break;
	case Timer2_Fast_PWM_Mode      :SET_BIT(TCCR2,TCCR2_WGM20); SET_BIT(TCCR2,TCCR2_WGM21); break;
	default                        :Local_u8Error_state = NOK;                              break;
	}

	/*Compare Match Output Mode*/
	switch(Timer2_cfg->Com2_Mode)
	{
	case Timer2_Normal_port        :CLR_BIT(TCCR2,TCCR2_COM20); CLR_BIT(TCCR2,TCCR2_COM21); break;
	case Timer2_Toggle             :SET_BIT(TCCR2,TCCR2_COM20); CLR_BIT(TCCR2,TCCR2_COM21); break;
	case Timer2_Reserved           :SET_BIT(TCCR2,TCCR2_COM20); CLR_BIT(TCCR2,TCCR2_COM21); break;
	case Timer2_Clear              :CLR_BIT(TCCR2,TCCR2_COM20); SET_BIT(TCCR2,TCCR2_COM21); break;
	case Timer2_Set                :SET_BIT(TCCR2,TCCR2_COM20); SET_BIT(TCCR2,TCCR2_COM21); break;
	default                        :Local_u8Error_state = NOK;                              break;
	}

	/*Clock Select*/
	TCCR2 &= 0b11111000;
	switch(Timer2_cfg->Clk_Mode)
	{
	case No_clock                  :TCCR2 |=0b000;            break;
	case No_prescaling             :TCCR2 |=0b001;            break;
	case clk_8                     :TCCR2 |=0b010;            break;
	case clk_64                    :TCCR2 |=0b011;            break;
	case clk_256                   :TCCR2 |=0b100;            break;
	case clk_1024                  :TCCR2 |=0b101;            break;
	case EXTI_clk_T0_falling_edge  :TCCR2 |=0b110;            break;
	case EXTI_clk_T0_rising_edge   :TCCR2 |=0b111;            break;
	default                        :Local_u8Error_state = NOK;break;
	}

	/*Set enable compare match interrupt*/
	//SET_BIT(TIMSK,TIMSK_OCIE0);

	return Local_u8Error_state ;
}

uint8 Timer2_SetCompMode(Timer2_Compare_Output_Mode_t Comp_Mode_t)
{
	uint8 Local_u8Error_state = OK ;
	switch(Comp_Mode_t)
	{
	case Timer2_Normal_port                 :CLR_BIT(TCCR2,TCCR2_COM20); CLR_BIT(TCCR2,TCCR2_COM21); break;
	case Timer2_Toggle                      :SET_BIT(TCCR2,TCCR2_COM20); CLR_BIT(TCCR2,TCCR2_COM21); break;
	case Timer2_Reserved                    :SET_BIT(TCCR2,TCCR2_COM20); CLR_BIT(TCCR2,TCCR2_COM21); break;
	case Timer2_Clear                       :CLR_BIT(TCCR2,TCCR2_COM20); SET_BIT(TCCR2,TCCR2_COM21); break;
	case Timer2_Set                         :SET_BIT(TCCR2,TCCR2_COM20); SET_BIT(TCCR2,TCCR2_COM21); break;
	case Timer2_Clear_on_compare_set_at_TOP :CLR_BIT(TCCR2,TCCR2_COM20); SET_BIT(TCCR2,TCCR2_COM21); break;
	case Timer2_set_on_compare_Clear_at_TOP :SET_BIT(TCCR2,TCCR2_COM20); SET_BIT(TCCR2,TCCR2_COM21); break;
	default                                 :Local_u8Error_state = NOK;                              break;
	}
	return Local_u8Error_state;
}


void Timers2_voidSetPreloadValue(uint8 Copy_u8PreloadValue)
{
	TCNT2 = Copy_u8PreloadValue ;
}
void Timers2_voidSetCcmpareMatchValue(uint8 Copy_u8CompMatchValue)
{
	OCR2 = Copy_u8CompMatchValue ;
}
uint16 Timers2_voidGetTCNT0_Value(void)
{
	return TCNT2;
}



/*************************************************************************************************************************/

uint8 Timers1_u8Init(Timer1_cfg_t *Timer1_cfg)
{
	uint8 Local_u8Error_State = OK ;

	if(Timer1_cfg->Ch_Mode == Channel_A )
	{
		switch(Timer1_cfg->Com1_Mode)
		{
		case Timer1_Normal_port                 :CLR_BIT(TCCR1A,TCCR1A_COM1A0); CLR_BIT(TCCR1A,TCCR1A_COM1A1); break;
		case Timer1_disconnected_Fast           :CLR_BIT(TCCR1A,TCCR1A_COM1A0); CLR_BIT(TCCR1A,TCCR1A_COM1A1); break;
		case Timer1_Toggle                      :SET_BIT(TCCR1A,TCCR1A_COM1A0); CLR_BIT(TCCR1A,TCCR1A_COM1A1); break;
		case Timer1_normal_fast                 :SET_BIT(TCCR1A,TCCR1A_COM1A0); CLR_BIT(TCCR1A,TCCR1A_COM1A1); break;
		case Timer1_Clear                       :CLR_BIT(TCCR1A,TCCR1A_COM1A0); SET_BIT(TCCR1A,TCCR1A_COM1A1); break;
		case Timer1_Clear_on_compare_set_at_TOP :CLR_BIT(TCCR1A,TCCR1A_COM1A0); SET_BIT(TCCR1A,TCCR1A_COM1A1); break;
		case Timer1_Set                         :SET_BIT(TCCR1A,TCCR1A_COM1A0); SET_BIT(TCCR1A,TCCR1A_COM1A1); break;
		case Timer1_set_on_compare_Clear_at_TOP :SET_BIT(TCCR1A,TCCR1A_COM1A0); SET_BIT(TCCR1A,TCCR1A_COM1A1); break;
		default                                 :Local_u8Error_State = NOK;                                    break;
		}
	}
	else if(Timer1_cfg->Ch_Mode == Channel_B )
	{
		switch(Timer1_cfg->Com1_Mode)
		{
		case Timer1_Normal_port                 :CLR_BIT(TCCR1A,TCCR1A_COM1B0); CLR_BIT(TCCR1A,TCCR1A_COM1B1); break;
		case Timer1_disconnected_Fast           :CLR_BIT(TCCR1A,TCCR1A_COM1B0); CLR_BIT(TCCR1A,TCCR1A_COM1B1); break;
		case Timer1_Toggle                      :SET_BIT(TCCR1A,TCCR1A_COM1B0); CLR_BIT(TCCR1A,TCCR1A_COM1B1); break;
		case Timer1_normal_fast                 :SET_BIT(TCCR1A,TCCR1A_COM1B0); CLR_BIT(TCCR1A,TCCR1A_COM1B1); break;
		case Timer1_Clear                       :CLR_BIT(TCCR1A,TCCR1A_COM1B0); SET_BIT(TCCR1A,TCCR1A_COM1B1); break;
		case Timer1_Clear_on_compare_set_at_TOP :CLR_BIT(TCCR1A,TCCR1A_COM1B0); SET_BIT(TCCR1A,TCCR1A_COM1B1); break;
		case Timer1_Set                         :SET_BIT(TCCR1A,TCCR1A_COM1B0); SET_BIT(TCCR1A,TCCR1A_COM1B1); break;
		case Timer1_set_on_compare_Clear_at_TOP :SET_BIT(TCCR1A,TCCR1A_COM1B0); SET_BIT(TCCR1A,TCCR1A_COM1B1); break;
		default                                 :Local_u8Error_State = NOK;                                    break;
		}
	}
	else
	{
		Local_u8Error_State = NOK;
	}



	/*Waveform Generation Mode*/
	switch(Timer1_cfg->WFG1_Mode)
	{
	case Timer1_Normal_Mode             :CLR_BIT(TCCR1A,TCCR1A_WGM10); CLR_BIT(TCCR1A,TCCR1A_WGM11); CLR_BIT(TCCR1B,TCCR1B_WGM12); CLR_BIT(TCCR1B,TCCR1B_WGM13);break;
	case Timer1_PWM_8_Bit_Mode          :SET_BIT(TCCR1A,TCCR1A_WGM10); CLR_BIT(TCCR1A,TCCR1A_WGM11); CLR_BIT(TCCR1B,TCCR1B_WGM12); CLR_BIT(TCCR1B,TCCR1B_WGM13);break;
	case Timer1_PWM_9_Bit_Mode          :CLR_BIT(TCCR1A,TCCR1A_WGM10); SET_BIT(TCCR1A,TCCR1A_WGM11); CLR_BIT(TCCR1B,TCCR1B_WGM12); CLR_BIT(TCCR1B,TCCR1B_WGM13);break;
	case Timer1_PWM_10_Bit_Mode         :SET_BIT(TCCR1A,TCCR1A_WGM10); SET_BIT(TCCR1A,TCCR1A_WGM11); CLR_BIT(TCCR1B,TCCR1B_WGM12); CLR_BIT(TCCR1B,TCCR1B_WGM13);break;
	case Timer1_CTC1_Mode               :CLR_BIT(TCCR1A,TCCR1A_WGM10); CLR_BIT(TCCR1A,TCCR1A_WGM11); SET_BIT(TCCR1B,TCCR1B_WGM12); CLR_BIT(TCCR1B,TCCR1B_WGM13);break;
	case Timer1_Fast_PWM_8_Bit_Mode     :SET_BIT(TCCR1A,TCCR1A_WGM10); CLR_BIT(TCCR1A,TCCR1A_WGM11); SET_BIT(TCCR1B,TCCR1B_WGM12); CLR_BIT(TCCR1B,TCCR1B_WGM13);break;
	case Timer1_Fast_PWM_9_Bit_Mode     :CLR_BIT(TCCR1A,TCCR1A_WGM10); SET_BIT(TCCR1A,TCCR1A_WGM11); SET_BIT(TCCR1B,TCCR1B_WGM12); CLR_BIT(TCCR1B,TCCR1B_WGM13);break;
	case Timer1_Fast_PWM_10_Bit_Mode    :SET_BIT(TCCR1A,TCCR1A_WGM10); SET_BIT(TCCR1A,TCCR1A_WGM11); SET_BIT(TCCR1B,TCCR1B_WGM12); CLR_BIT(TCCR1B,TCCR1B_WGM13);break;
	case Timer1_PWM_Phase_Freq_Correct1 :CLR_BIT(TCCR1A,TCCR1A_WGM10); CLR_BIT(TCCR1A,TCCR1A_WGM11); CLR_BIT(TCCR1B,TCCR1B_WGM12); SET_BIT(TCCR1B,TCCR1B_WGM13);break;
	case Timer1_PWM_Phase_Freq_Correct2 :SET_BIT(TCCR1A,TCCR1A_WGM10); CLR_BIT(TCCR1A,TCCR1A_WGM11); CLR_BIT(TCCR1B,TCCR1B_WGM12); SET_BIT(TCCR1B,TCCR1B_WGM13);break;
	case Timer1_PWM_Phase_Correct1      :CLR_BIT(TCCR1A,TCCR1A_WGM10); SET_BIT(TCCR1A,TCCR1A_WGM11); CLR_BIT(TCCR1B,TCCR1B_WGM12); SET_BIT(TCCR1B,TCCR1B_WGM13);break;
	case Timer1_PWM_Phase_Correct2      :SET_BIT(TCCR1A,TCCR1A_WGM10); SET_BIT(TCCR1A,TCCR1A_WGM11); CLR_BIT(TCCR1B,TCCR1B_WGM12); SET_BIT(TCCR1B,TCCR1B_WGM13);break;
	case Timer1_CTC2_Mode               :CLR_BIT(TCCR1A,TCCR1A_WGM10); CLR_BIT(TCCR1A,TCCR1A_WGM11); SET_BIT(TCCR1B,TCCR1B_WGM12); SET_BIT(TCCR1B,TCCR1B_WGM13);break;
	case Timer1_Reserved_Mode           :SET_BIT(TCCR1A,TCCR1A_WGM10); CLR_BIT(TCCR1A,TCCR1A_WGM11); SET_BIT(TCCR1B,TCCR1B_WGM12); SET_BIT(TCCR1B,TCCR1B_WGM13);break;
	case Timer1_Fast_PWM_Mode1          :CLR_BIT(TCCR1A,TCCR1A_WGM10); SET_BIT(TCCR1A,TCCR1A_WGM11); SET_BIT(TCCR1B,TCCR1B_WGM12); SET_BIT(TCCR1B,TCCR1B_WGM13);break;
	case Timer1_Fast_PWM_Mode2          :SET_BIT(TCCR1A,TCCR1A_WGM10); SET_BIT(TCCR1A,TCCR1A_WGM11); SET_BIT(TCCR1B,TCCR1B_WGM12); SET_BIT(TCCR1B,TCCR1B_WGM13);break;
	default                             :Local_u8Error_State = NOK;                                                                                             break;
	}

	/*Clock Select*/
	TCCR1B &= 0b11111000;
	switch(Timer1_cfg->Clk_Mode)
	{
	case No_clock                  :TCCR1B |=0b000;            break;
	case No_prescaling             :TCCR1B |=0b001;            break;
	case clk_8                     :TCCR1B |=0b010;            break;
	case clk_64                    :TCCR1B |=0b011;            break;
	case clk_256                   :TCCR1B |=0b100;            break;
	case clk_1024                  :TCCR1B |=0b101;            break;
	case EXTI_clk_T0_falling_edge  :TCCR1B |=0b110;            break;
	case EXTI_clk_T0_rising_edge   :TCCR1B |=0b111;            break;
	default                        :Local_u8Error_State = NOK; break;
	}

	return Local_u8Error_State ;
}


uint8 Timer1_SetCompMode(Timer1_Compare_Output_Mode_t Comp_Mode_t)
{
	uint8 Local_u8Error_State = OK ;
	switch(Comp_Mode_t)
	{
	case Timer1_Normal_Mode                 :CLR_BIT(TCCR1A,TCCR1A_COM1B0); CLR_BIT(TCCR1A,TCCR1A_COM1B1); break;
	case Timer1_disconnected_Fast           :CLR_BIT(TCCR1A,TCCR1A_COM1B0); CLR_BIT(TCCR1A,TCCR1A_COM1B1); break;
	case Timer1_Toggle                      :SET_BIT(TCCR1A,TCCR1A_COM1B0); CLR_BIT(TCCR1A,TCCR1A_COM1B1); break;
	case Timer1_normal_fast                 :SET_BIT(TCCR1A,TCCR1A_COM1B0); CLR_BIT(TCCR1A,TCCR1A_COM1B1); break;
	case Timer1_Clear                       :CLR_BIT(TCCR1A,TCCR1A_COM1B0); SET_BIT(TCCR1A,TCCR1A_COM1B1); break;
	case Timer1_Clear_on_compare_set_at_TOP :CLR_BIT(TCCR1A,TCCR1A_COM1B0); SET_BIT(TCCR1A,TCCR1A_COM1B1); break;
	case Timer1_Set                         :SET_BIT(TCCR1A,TCCR1A_COM1B0); SET_BIT(TCCR1A,TCCR1A_COM1B1); break;
	case Timer1_set_on_compare_Clear_at_TOP :SET_BIT(TCCR1A,TCCR1A_COM1B0); SET_BIT(TCCR1A,TCCR1A_COM1B1); break;
	default                                 :Local_u8Error_State = NOK;                                    break;
	}
	return Local_u8Error_State ;
}

uint16 Timers1_u16GetTimerValue(void)
{
	return TCNT1 ;
}
uint16 Timers1_u16GetICR1Value(void)
{
	return TOP ;
}
void Timers1_u16Enable_Noise_Canceler(void)
{
SET_BIT(TCCR1B,TCCR1B_ICNC1);
}
uint8 Timers1_u16Edge_Select(Timer1_Edge_Select_HWICU_t  Edge_Select_t)
{
	uint8 Local_u8Error_State = OK ;

	if(Edge_Select_t == Falling_edge_HWICU)
	{
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else if(Edge_Select_t == Rising_edge_HWICU)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else
	{
	    Local_u8Error_State = NOK ;
	}

	return Local_u8Error_State ;
}

void Timer1_SetValue(uint16 Copy_u16Value)
{
	TCNT1 = Copy_u16Value ;
}

void Timers1_voidSetCcmpareMatchValue(uint16 Copy_u8CompMatchValue)
{
	OCR1A = Copy_u8CompMatchValue ;
}
void Timers1_voidSetTopValue(uint16 Copy_u8Value)
{
	TOP = Copy_u8Value ;
}
/*************************************************************************************************************************/

uint8 Timer_u8IntEnable(Timer_Interrupts_t Interrupts_t)
{
	uint8 Local_u8Error_State = OK ;

	switch(Interrupts_t)
	{
	case TIMER0_OVF_INT   :SET_BIT(TIMSK,TIMSK_TOIE0);  break;
	case TIMER0_COMP_INT  :SET_BIT(TIMSK,TIMSK_OCIE0);  break;
	case TIMER1_COMPA_INT :SET_BIT(TIMSK,TIMSK_OCIE1A); break;
	case TIMER1_COMPB_INT :SET_BIT(TIMSK,TIMSK_OCIE1B); break;
	case TIMER1_HWICU_INT :SET_BIT(TIMSK,TIMSK_TICIE1); break;
	case TIMER1_OVF_INT   :SET_BIT(TIMSK,TIMSK_TOIE1);  break;
	case TIMER2_OVF_INT   :SET_BIT(TIMSK,TIMSK_TOIE2);  break;
	case TIMER2_COMP_INT  :SET_BIT(TIMSK,TIMSK_OCIE2);  break;
	default               :Local_u8Error_State = NOK;   break;
	}

	return Local_u8Error_State ;
}



uint8 Timer_u8IntDisable(Timer_Interrupts_t Interrupts_t)
{
	uint8 Local_u8Error_State = OK ;

	switch(Interrupts_t)
	{
	case TIMER0_OVF_INT   :CLR_BIT(TIMSK,TIMSK_TOIE0);  break;
	case TIMER0_COMP_INT  :CLR_BIT(TIMSK,TIMSK_OCIE0);  break;
	case TIMER1_COMPA_INT :CLR_BIT(TIMSK,TIMSK_OCIE1A); break;
	case TIMER1_COMPB_INT :CLR_BIT(TIMSK,TIMSK_OCIE1B); break;
	case TIMER1_HWICU_INT :CLR_BIT(TIMSK,TIMSK_TICIE1); break;
	case TIMER1_OVF_INT   :CLR_BIT(TIMSK,TIMSK_TOIE1);  break;
	case TIMER2_OVF_INT   :CLR_BIT(TIMSK,TIMSK_TOIE2);  break;
	case TIMER2_COMP_INT  :CLR_BIT(TIMSK,TIMSK_OCIE2);  break;
	default               :Local_u8Error_State = NOK;   break;
	}

	return Local_u8Error_State ;
}

/*************************************************************************************************************************/

uint8 Timer_u8SetcallBack(Timer_Interrupts_t Interrupts_t, void(*Copy_pvCallBackFun)(void))
{

	uint8 Local_u8ErrorState = OK ;
	if(Copy_pvCallBackFun != NULL)
	{
		Timer_pvCallBackFunc[Interrupts_t] = Copy_pvCallBackFun ;
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState ;
}



/*************************************************************************************************************************/




__attribute__((signal)) void __vector_11(void);
void __vector_11(void)
{
	if(Timer_pvCallBackFunc[TIMER0_OVF_INT] != NULL)
	{
		Timer_pvCallBackFunc[TIMER0_OVF_INT]();
	}

}

__attribute__((signal)) void __vector_10(void);
void __vector_10(void)
{
	if(Timer_pvCallBackFunc[TIMER0_COMP_INT] != NULL)
	{
		Timer_pvCallBackFunc[TIMER0_COMP_INT]();
	}
}

/*************************************************************************************************************************/

__attribute__((signal)) void __vector_9(void);
void __vector_9(void)
{
	if(Timer_pvCallBackFunc[TIMER1_OVF_INT] != NULL)
	{
		Timer_pvCallBackFunc[TIMER1_OVF_INT]();
	}

}

__attribute__((signal)) void __vector_8(void);
void __vector_8(void)
{
	if(Timer_pvCallBackFunc[TIMER1_COMPB_INT] != NULL)
	{
		Timer_pvCallBackFunc[TIMER1_COMPB_INT]();
	}
}
__attribute__((signal)) void __vector_7(void);
void __vector_7(void)
{
	if(Timer_pvCallBackFunc[TIMER1_COMPA_INT] != NULL)
	{
		Timer_pvCallBackFunc[TIMER1_COMPA_INT]();
	}
}

__attribute__((signal)) void __vector_6(void);
void __vector_6(void)
{
	if(Timer_pvCallBackFunc[TIMER1_HWICU_INT] != NULL)
	{
		Timer_pvCallBackFunc[TIMER1_HWICU_INT]();
	}
}

/*************************************************************************************************************************/

__attribute__((signal)) void __vector_5(void);
void __vector_5(void)
{
	if(Timer_pvCallBackFunc[TIMER2_OVF_INT] != NULL)
	{
		Timer_pvCallBackFunc[TIMER2_OVF_INT]();
	}

}

__attribute__((signal)) void __vector_4(void);
void __vector_4(void)
{
	if(Timer_pvCallBackFunc[TIMER2_COMP_INT] != NULL)
	{
		Timer_pvCallBackFunc[TIMER2_COMP_INT]();
	}
}
