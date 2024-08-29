#include "STD_TYPES.h"
#include "Map.h"

sint32 Map(sint32 Input_Range_Min ,sint32 Input_Range_Max ,sint32 output_Range_Min ,sint32 output_Range_Max ,sint32 Input_value)
{
	return ((Input_value - Input_Range_Min) * (output_Range_Max - output_Range_Min) / (Input_Range_Max - Input_Range_Min) + output_Range_Min) ;
}
