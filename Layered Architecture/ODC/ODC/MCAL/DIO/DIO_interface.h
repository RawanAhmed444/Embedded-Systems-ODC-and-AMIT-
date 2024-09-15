/*
 * DIO_interface.h
 *
 * Created: 9/10/2024 7:18:42 PM
 *  Author: RAWAN
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


/*PIN DIRECTION*/
#define OUTPUT	1
#define INPUT	0


/*PIN VALUE*/
#define HIGH	1
#define LOW		0  


/*PINS*/
#define DIO_PIN0	0
#define DIO_PIN1	1
#define DIO_PIN2	2
#define DIO_PIN3	3
#define DIO_PIN4	4
#define DIO_PIN5	5
#define DIO_PIN6	6
#define DIO_PIN7	7


/*PORTS*/
#define DIO_PORTA	0
#define DIO_PORTB	1
#define DIO_PORTC	2
#define DIO_PORTD	3


/*DIO FUNCTIONS PROTOTYPES*/


/*PIN FUNCTIONS*/
void DIO_voidSetPinDir(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8dir) ;
void DIO_voidSetPinVal(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8dval) ;
void DIO_voidTogglePin(u8 copy_u8port, u8 copy_u8pin) ;
u8 DIO_u8ReadPinVal(u8 copy_u8port, u8 copy_u8pin) ;


/*PORT FUNCTIONS*/
void DIO_voidSetPortDir(u8 copy_u8port, u8 copy_u8dir) ;
void DIO_voidSetPortVal(u8 copy_u8port, u8 copy_u8dval) ;


#endif /* DIO_INTERFACE_H_ */