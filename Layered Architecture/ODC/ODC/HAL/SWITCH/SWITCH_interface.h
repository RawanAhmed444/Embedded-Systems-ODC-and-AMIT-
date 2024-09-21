/*
 * SWITCH_interface.h
 *
 * Created: 9/21/2024 6:31:15 PM
 *  Author: RAWAN
 */ 


#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_


void SWITCH_voidInit(u8 copy_u8port, u8 copy_u8pin);
u8 SWITCH_u8ReadVal(u8 copy_u8port, u8 copy_u8pin);

#endif /* SWITCH_INTERFACE_H_ */