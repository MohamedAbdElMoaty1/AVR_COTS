#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H



#define SWITCH_u8PULL_UPP     1u
#define SWITCH_u8PULL_DOWN    0u


#define SWITCH_u8PRESSED      1u
#define SWITCH_u8RELEASED     2u

typedef struct
{
uint8 SWITCH_u8Port ;
uint8 SWITCH_u8Pin  ;
uint8 SWITCH_u8Pull_t ;
}SWITCH_config_t;


uint8 SWITCH_u8GetState(const SWITCH_config_t *Copy_pstrObj ,uint8 *Copy_pu8State);

#endif  //SWITCH_INTERFACE_H
