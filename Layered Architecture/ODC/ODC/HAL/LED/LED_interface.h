/*
 * LED_interface.h
 *
 * Created: 9/15/2024 8:14:59 PM
 *  Author: RAWAN
 */ 


#include "../../LIB/STD_TYPE.h"


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


void LED_voidInit(u8 copy_u8port, u8 copy_u8pin);
void LED_voidToggle(u8 copy_u8port, u8 copy_u8pin);
void LED_voidOn(u8 copy_u8port, u8 copy_u8pin);
void LED_voidOff(u8 copy_u8port, u8 copy_u8pin);


#endif /* LED_INTERFACE_H_ */