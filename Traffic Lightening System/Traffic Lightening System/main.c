/*
 * main.c
 *
 * Created: 9/14/2024 9:54:52 PM
 *  Author: RAWAN
 */ 


#include <avr/io.h>
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
	/*Setting DDRA, DDRC,and DDRD registers as output*/
	DDRA = 0x07 ;
	DDRC = 0x7F ;
	DDRD = 0x7F ;
	
	/*Hex values of pins in PORTC and PORTD to display numbers in descending order*/
	int arr [10] = {0x6F, 0x7F, 0x07, 0x7D, 0x6D, 0x66, 0x4F, 0x5B, 0x06, 0x3F} ;
			
    while(1)
    {		
         /*lightening green led while counting 10 seconds down on two 7-segments displays*/
         for (int x = 0; x < 10; x++)
         {
			 
			 PORTA = 0x04 ;	//Setting PINA2 HIGH
			 while (x == 0)	//Counting number 10
			 {
				 PORTC = arr[9] ;
				 PORTD = arr[8] ;
				 _delay_ms(100) ;
				 break ;
			 }
			 PORTC = arr[x] ;
			 PORTD = arr[9] ;
			 _delay_ms(100) ;
			 while (x == 8)	//When reaching 0 break the loop
			 {
				 break ;
			 }
         }
		 /*lightening yellow led while counting 3 seconds down on two 7-segments displays*/
		 for (int x = 0; x < 3; x++)
		 {
			 
			 PORTA = 0x02 ;	//Setting PINA1 HIGH
			 PORTC = arr[x+6] ;
			 PORTD = arr[9] ;
			 _delay_ms(100) ;
			 while (x == 8)	//When reaching 0 break the loop
			 {
				 break ;
			 }
		 }
		 /*lightening red led while counting 10 seconds down on two 7-segments displays*/
		 for (int x = 0; x < 10; x++)
		 {
			 
			 PORTA = 0x01 ;	//Setting PINA0 HIGH
			 while (x == 0)	//Counting number 10
			 {
				 PORTC = arr[9] ;
				 PORTD = arr[8] ;
				 _delay_ms(100) ;
				 break ;
			 }
			 PORTC = arr[x] ;
			 PORTD = arr[9] ;
			 _delay_ms(100) ;
			 while (x == 8)	//When reaching 0 break the loop
			 {
				 break ;
			 }
		 }
    }
}
