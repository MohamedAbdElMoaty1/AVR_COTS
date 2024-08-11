#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H


#define LED_u8ACT_LOW     0u
#define LED_u8ACT_HIGH    1u

typedef struct
{
uint8 LED_u8Port;     /*LED Port*/
uint8 LED_u8Pin;      /*LED Pin*/
uint8 LED_u8Act_t;    /*1.LED_u8ACT_LOW    2.LED_u8ACT_HIGH*/
}LED_Config_t;

uint8 LED_u8Set_On(const LED_Config_t *Copy_pstrObj);
uint8 LED_u8Set_Off(const LED_Config_t *Copy_pstrObj);
uint8 LED_u8Toggle(const LED_Config_t *Copy_pstrObj);

#endif
