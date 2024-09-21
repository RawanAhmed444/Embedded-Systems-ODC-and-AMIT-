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
	SWITCH_voidInit(DIO_PORTA, DIO_PIN0);
	LED_voidInit(DIO_PORTD, DIO_PIN0);
	while (1) {
		_delay_ms(DEBOUNCE_DELAY); // Debounce delay

		if (SWITCH_u8ReadVal(DIO_PORTA, DIO_PIN0) == 1) {
			LED_voidOn(DIO_PORTD, DIO_PIN0);
			} else {
			LED_voidOff(DIO_PORTD, DIO_PIN0);
		}
	}
}

