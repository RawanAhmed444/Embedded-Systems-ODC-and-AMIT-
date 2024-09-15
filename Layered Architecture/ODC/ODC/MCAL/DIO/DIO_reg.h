/*
 * DIO_reg.h
 *
 * Created: 9/10/2024 7:18:42 PM
 *  Author: RAWAN
 */


/*
In the context of the DIO_reg.h header file, the volatile keyword is used to:
	Prevent Optimization: The compiler may optimize code by assuming 
	that variables do not change their values unless explicitly modified within the program. 
	By declaring the register pointers as volatile,
	the compiler is prevented from making such assumptions,
	ensuring that the correct register values are accessed.
 */ 


#ifndef DIO_REG_H_
#define DIO_REG_H_

/* PORT A REGISTERS*/
#define DDRA_REG	* ((volatile u8 *)0x3B)
#define PORTA_REG	* ((volatile u8 *)0x3A)
#define PINA_REG	* ((volatile u8 *)0x39)


/* PORT B REGISTERS*/
#define DDRB_REG	* ((volatile u8 *)0x38)
#define PORTB_REG	* ((volatile u8 *)0x37)
#define PINB_REG	* ((volatile u8 *)0x36)


/* PORT C REGISTERS*/
#define DDRC_REG	* ((volatile u8 *)0x35)
#define PORTC_REG	* ((volatile u8 *)0x34)
#define PINC_REG	* ((volatile u8 *)0x33)


/* PORT D REGISTERS*/
#define DDRD_REG	* ((volatile u8 *)0x32)
#define PORTD_REG	* ((volatile u8 *)0x31)
#define PIND_REG	* ((volatile u8 *)0x30)


#endif /* DIO_REG_H_ */