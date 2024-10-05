#ifndef ULTRASONIC_INTERFACE_H
#define ULTRASONIC_INTERFACE_H

typedef struct
{
    uint8 Port;
    uint8 Trigger_Pin;
    uint8 Echo_Pin;
}Ultrasonic_t;

uint8 Ultrasonic_Init(Ultrasonic_t *Ultrasonic_Config);
uint16 Ultrasonic_GetDistance(Ultrasonic_t *Ultrasonic_Config);

#endif //ULTRASONIC_INTERFACE_H
