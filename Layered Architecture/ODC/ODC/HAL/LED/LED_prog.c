/*
 * LED_prog.c
 *
 * Created: 9/15/2024 8:15:26 PM
 *  Author: RAWAN
 */ 


#include "LED_interface.h"
#include "LED_config.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"


void LED_voidInit(u8 copy_u8port)
{
	//Set LED_PIN as OUTPUT
	DIO_voidSetPinDir(copy_u8port, LED_PIN, OUTPUT);
}


void LED_voidToggle(u8 copy_u8port)
{
	DIO_voidToggelPinVal(copy_u8port, LED_PIN);
}


void LED_voidOn(u8 copy_u8port)
{
	DIO_voidSetPinVal(copy_u8port, LED_PIN, HIGH);
}


void LED_voidOff(u8 copy_u8port)
{
	DIO_voidSetPinVal(copy_u8port, LED_PIN, LOW);
}
