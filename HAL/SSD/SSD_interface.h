#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H


#define SSD_u8ANODE     0u
#define SSD_u8CATHODE   1u
#define SSD_u8ETA_KIT   2u

#define SSD_u8PINA0     0u
#define SSD_u8PINA1     1u

typedef struct
{
	uint8 SSD_u8type;             /*1.SSD_u8ANODE      2.SSD_u8CATHODE   3.SSD_u8ETA_KIT*/
	uint8 SSD_u8Led_Port;
	uint8 SSD_u8LedA_Pin;         /*1.SSD_u8PINA0      2.SSD_u8PINA1*/
	uint8 SSD_u8Enable_Port;
	uint8 SSD_u8Enable_Pin;
}SSD_u8Config_t;

uint8 SSD_u8On(const SSD_u8Config_t *Copy_pstr_obj);
uint8 SSD_u8Off(const SSD_u8Config_t *Copy_pstr_obj);
uint8 SSD_u8SetNumber(const SSD_u8Config_t *Copy_pstr_obj , uint8 Copy_u8Number);

#endif //SSD_INTERFACE_H
