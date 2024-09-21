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
	DIO_voidSetPinDir(DIO_PORTA,DIO_PIN0, OUTPUT);
	DIO_voidSetPinDir(DIO_PORTA,DIO_PIN1, OUTPUT);
	while (1) {
		/*Clockwise*/
		DIO_voidSetPinVal(DIO_PORTA, DIO_PIN0, HIGH);
		DIO_voidSetPinVal(DIO_PORTA, DIO_PIN1, LOW);
		_delay_ms(3000);
		/*Counter clockwise*/
		DIO_voidTogglePin(DIO_PORTA, DIO_PIN0);
		DIO_voidTogglePin(DIO_PORTA, DIO_PIN1);
		_delay_ms(3000);
	}
}

