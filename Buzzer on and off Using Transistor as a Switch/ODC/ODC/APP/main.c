/*
 * main.c
 *
 * Created: 9/19/2024 8:57:02 PM
 *  Author: RAWAN
 */ 
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_config.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPE.h"

#define  F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	DIO_voidSetPinDir(DIO_PORTD, DIO_PIN0, OUTPUT);
	while (1)
	{
		
		DIO_voidSetPinVal(DIO_PORTD, DIO_PIN0, HIGH);
		_delay_ms(1000);
		DIO_voidSetPinVal(DIO_PORTD, DIO_PIN0, LOW);	
		_delay_ms(1000);
	}
}

