#ifndef STEPPERMOTOR_INTERFACE_H
#define STEPPERMOTOR_INTERFACE_H

#define STP_u8RCW           0u
#define STP_u8RCCW          1u


typedef struct 
{
	uint8 Port_Wire;
	uint8 BLue_Wire;
	uint8 Pink_Wire;
	uint8 Yellow_Wire;
	uint8 Orange_Wire;

}STP_u8cfg_t;

uint8 STP_u8Rotate(STP_u8cfg_t* Copy_pstr_obj ,uint8 Copy_u8Direction , uint16 Copy_u8Angle);




#endif //STEPPERMOTOR_INTERFACE_H
