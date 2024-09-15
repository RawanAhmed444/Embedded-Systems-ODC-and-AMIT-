/*
 * main.c
 *
 * Created: 9/15/2024 11:28:00 PM
 *  Author: RAWAN
 */ 


#include "../HAL/SSD/SSD_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#define F_CPU 16000000UL // Define the system clock frequency
#include <util/delay.h>

/*
 * Turn on Green LED for 10 seconds.
 * Then turn on Yellow LED for 3 seconds.
 * Then turn on Red LED for 10 seconds.
 * Apply forever while counting down the seconds on two 7-segment displays
 */


int main(void)
{
	/*Initializing 3 LEDs and 2 7-Segment Displays*/
	LED_voidInit(DIO_PORTA, DIO_PIN0);
	LED_voidInit(DIO_PORTA, DIO_PIN1);
	LED_voidInit(DIO_PORTA, DIO_PIN2);
	SSD_voidInit(DIO_PORTC);
	SSD_voidInit(DIO_PORTD);
	
			
    while(1)
    {		
         /*lightening green led while counting 10 seconds down on two 7-segments displays*/
         for (u8 x = 0; x < 10; x++)
         {
			 
			 LED_voidOn(DIO_PORTA, DIO_PIN2);	//Setting PINA2 HIGH
			 while (x == 0)		//Counting number 10
			 {
				 SSD_voidDisplayNumberDescending(DIO_PORTC, 9);
				 SSD_voidDisplayNumberDescending(DIO_PORTD, 8);
				 _delay_ms(500) ;
				 break ;
			 }
			 SSD_voidDisplayNumberDescending(DIO_PORTC, x);
			 SSD_voidDisplayNumberDescending(DIO_PORTD, 9);
			 _delay_ms(500) ;
			 LED_voidOff(DIO_PORTA, DIO_PIN2);	//Setting PINA2 LOW
         }
		 /*lightening yellow led while counting 3 seconds down on two 7-segments displays*/
		 for (u8 x = 0; x < 3; x++)
		 {
			 
			 LED_voidOn(DIO_PORTA, DIO_PIN1);	//Setting PINA1 HIGH
			 SSD_voidDisplayNumberDescending(DIO_PORTC, x+6);
			 SSD_voidDisplayNumberDescending(DIO_PORTD, 9);
			 _delay_ms(500) ;
			 while (x == 8)		//When reaching 3 break the loop
			 {
				 break ;
			 }
			 LED_voidOff(DIO_PORTA, DIO_PIN1);	//Setting PINA1 LOW
		 }
		 /*lightening red led while counting 10 seconds down on two 7-segments displays*/
		 for (u8 x = 0; x < 10; x++)
		 {
			 
			 LED_voidOn(DIO_PORTA, DIO_PIN0);	//Setting PINA0 HIGH
			 while (x == 0)		//Counting number 10
			 {
				 SSD_voidDisplayNumberDescending(DIO_PORTC, 9);
				 SSD_voidDisplayNumberDescending(DIO_PORTD, 8);
				 _delay_ms(500) ;
				 break ;
			 }
			 SSD_voidDisplayNumberDescending(DIO_PORTC, x);
			 SSD_voidDisplayNumberDescending(DIO_PORTD, 9);
			 _delay_ms(500) ;
			 LED_voidOff(DIO_PORTA, DIO_PIN0);	//Setting PINA2 LOW
		 }
    }
}