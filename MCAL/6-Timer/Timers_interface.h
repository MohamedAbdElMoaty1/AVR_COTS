#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H


typedef enum
{
	TIMER0_OVF_INT,
	TIMER0_COMP_INT,
	TIMER1_COMPA_INT,
	TIMER1_COMPB_INT,
	TIMER1_CAP_INT,
	TIMER1_OVF_INT,
	TIMER2_OVF_INT,
	TIMER2_COMP_INT,
	TIMER1_HWICU_INT,
}Timer_Interrupts_t;

/***************************************************/
typedef enum
{
	Timer0_Normal_Mode,
	Timer0_PWM_Mode,
	Timer0_Phase_Correct_Mode,
	Timer0_CTC_Mode,
	Timer0_Fast_PWM_Mode
}Timer0_WFG_Mode_t;


typedef enum
{
	Timer0_Normal_port,
	Timer0_Toggle,        // OC0
	Timer0_Clear,         // OC0
	Timer0_Set,           // OC0
	Timer0_Reserved,       // OC0
	Timer0_Clear_on_compare_set_at_TOP,
	Timer0_set_on_compare_Clear_at_TOP
}Timer0_Compare_Output_Mode_t;

typedef enum
{
	No_clock,
	No_prescaling,
	clk_8,
	clk_64,
	clk_256,
	clk_1024,
	EXTI_clk_T0_falling_edge,
	EXTI_clk_T0_rising_edge
}Clock_Select_t;


typedef struct
{
	Timer0_WFG_Mode_t WFG0_Mode;
	Timer0_Compare_Output_Mode_t Com0_Mode;
	Clock_Select_t Clk_Mode;
}Timer0_cfg_t;


/*****************************************************************************************/
typedef enum
{
	Timer2_Normal_Mode,
	Timer2_PWM_Mode,
	Timer2_Phase_Correct_Mode,
	Timer2_CTC_Mode,
	Timer2_Fast_PWM_Mode
}Timer2_WFG_Mode_t;


typedef enum
{
	Timer2_Normal_port,
	Timer2_Toggle,
	Timer2_Clear,
	Timer2_Set,
	Timer2_Reserved,
	Timer2_Clear_on_compare_set_at_TOP,
	Timer2_set_on_compare_Clear_at_TOP
}Timer2_Compare_Output_Mode_t;

typedef struct
{
	Timer2_WFG_Mode_t WFG2_Mode;
	Timer2_Compare_Output_Mode_t Com2_Mode;
	Clock_Select_t Clk_Mode;
}Timer2_cfg_t;

/*****************************************************************************************/


typedef enum
{
	Channel_A,
	Channel_B
}Timer1_Ch_t;

typedef enum
{
	Timer1_Normal_port,
	Timer1_Toggle,        // OC1A/OC1B
	Timer1_Clear,         // OC1A/OC1B
	Timer1_Set,           // OC1A/OC1B
	Timer1_disconnected_Fast,
	Timer1_normal_fast,
	Timer1_Clear_on_compare_set_at_TOP,
	Timer1_set_on_compare_Clear_at_TOP
}Timer1_Compare_Output_Mode_t;

typedef enum
{
	Timer1_Normal_Mode,
	Timer1_PWM_8_Bit_Mode,
	Timer1_PWM_9_Bit_Mode,
	Timer1_PWM_10_Bit_Mode,
	Timer1_CTC1_Mode,
	Timer1_Fast_PWM_8_Bit_Mode,
	Timer1_Fast_PWM_9_Bit_Mode,
	Timer1_Fast_PWM_10_Bit_Mode,
	Timer1_PWM_Phase_Freq_Correct1,
	Timer1_PWM_Phase_Freq_Correct2,
	Timer1_PWM_Phase_Correct1,
	Timer1_PWM_Phase_Correct2,
	Timer1_CTC2_Mode,
	Timer1_Reserved_Mode,
	Timer1_Fast_PWM_Mode1,
	Timer1_Fast_PWM_Mode2
}Timer1_WFG_Mode_t;

typedef struct
{
	Timer1_Ch_t Ch_Mode;
	Timer1_Compare_Output_Mode_t Com1_Mode;
	Timer1_WFG_Mode_t WFG1_Mode;
	Clock_Select_t Clk_Mode;
}Timer1_cfg_t;

typedef enum
{
	Falling_edge_HWICU,
	 Rising_edge_HWICU
}Timer1_Edge_Select_HWICU_t;


/************************************************************************************************/
uint8 Timers0_u8Init(Timer0_cfg_t *Timer0_cfg);
void Timers0_voidSetPreloadValue(uint8 Copy_u8PreloadValue);
void Timers0_voidSetCcmpareMatchValue(uint8 Copy_u8CompMatchValue);
uint16 Timers0_voidGetTCNT0_Value(void);
uint8 Timer0_SetCompMode(Timer0_Compare_Output_Mode_t Comp_Mode_t);
/************************************************************************************************/
uint8 Timer_u8SetcallBack(Timer_Interrupts_t Interrupts_t, void(*Copy_pvCallBackFun)(void));
/************************************************************************************************/
uint8 Timers1_u8Init(Timer1_cfg_t *Timer1_cfg);
void Timers1_voidSetCcmpareMatchValue(uint16 Copy_u8CompMatchValue);
void Timer1_SetValue(uint16 Copy_u16Value);
uint16 Timers1_u16GetTimerValue(void);
uint16 Timers1_u16GetICR1Value(void);
void Timers1_u16Enable_Noise_Canceler(void);
uint8 Timers1_u16Edge_Select(Timer1_Edge_Select_HWICU_t  Edge_Select_t);
void Timers1_voidSetTopValue(uint16 Copy_u8Value);
uint8 Timer1_SetCompMode(Timer1_Compare_Output_Mode_t Comp_Mode_t);
/************************************************************************************************/
uint8 Timers2_u8Init(Timer2_cfg_t *Timer2_cfg);
void Timers2_voidSetPreloadValue(uint8 Copy_u8PreloadValue);
void Timers2_voidSetCcmpareMatchValue(uint8 Copy_u8CompMatchValue);
uint16 Timers2_voidGetTCNT0_Value(void);
uint8 Timer2_SetCompMode(Timer2_Compare_Output_Mode_t Comp_Mode_t);
/************************************************************************************************/
uint8 Timer_u8IntEnable(Timer_Interrupts_t Interrupts_t);
uint8 Timer_u8IntDisable(Timer_Interrupts_t Interrupts_t);
/************************************************************************************************/

#endif //TIMERS_INTERFACE_H
