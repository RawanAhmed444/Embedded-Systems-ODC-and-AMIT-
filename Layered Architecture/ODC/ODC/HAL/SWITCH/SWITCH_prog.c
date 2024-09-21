/*
 * SWITHC_prog.c
 *
 * Created: 9/21/2024 6:30:50 PM
 *  Author: RAWAN
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SWITCH_config.h"
#include "SWITCH_interface.h"


void SWITCH_voidInit(u8 copy_u8port, u8 copy_u8pin)
{
	//Set LED_PIN as INPUT
	DIO_voidSetPinDir(copy_u8port, copy_u8pin, INPUT);
}


u8 SWITCH_u8ReadVal(u8 copy_u8port, u8 copy_u8pin)
{
		u8 LOC_var = DIO_u8ReadPinVal(copy_u8port, copy_u8pin);
		return LOC_var;
}