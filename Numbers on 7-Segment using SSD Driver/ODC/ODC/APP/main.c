/*
 * main.c
 *
 * Created: 9/15/2024 9:16:06 PM
 *  Author: RAWAN
 */

/*Displaying numbers from 0 to 9 using SSD driver*/


#include "../HAL/SSD/SSD_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#define  F_CPU 16000000UL
#include <util/delay.h>


int main(void) 
{
	SSD_voidInit(DIO_PORTD);
	while (1)
	{
		for (int x = 0; x < 10; x++)
		{
			SSD_voidDisplayNumber(DIO_PORTD, x);
			_delay_ms(1000);
		}
	}
}