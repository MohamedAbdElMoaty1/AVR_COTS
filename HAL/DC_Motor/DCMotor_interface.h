#ifndef DC_INTERFACE_H
#define DC_INTERFACE_H

typedef struct
{
uint8 Port;
uint8 Pin1;
uint8 Pin2;
}DCMotor_u8Config_t;


uint8 DCMotor_u8RotateCW(DCMotor_u8Config_t *Copy_pstr_obj);
uint8 DCMotor_u8RotateCCW(DCMotor_u8Config_t *Copy_pstr_obj);
uint8 DCMotor_u8Stop(DCMotor_u8Config_t *Copy_pstr_obj);

#endif //DC_INTERFACE_H
