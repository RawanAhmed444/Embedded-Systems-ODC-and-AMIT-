/*
 * main.c
 *
 * Created: 9/9/2024 11:36:24 PM
 *  Author: RAWAN
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL // Define the system clock frequency
#include <util/delay.h>

int main(void)
{
	/*Hex values of pins in PORTD to display numbers*/
	int arr [10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F} ;
	DDRD = 0x7F ;	// Setting all pins of PORTD as output except D7 (not needed) 
    while(1)
    {
        /*Displaying numbers on PORTD from 0 to 9 with delay 1 second between*/ 
		for (int x = 0; x < 10; x++)
		{
			PORTD = arr[x] ;
			_delay_ms(10000) ;
		}
    }
}
