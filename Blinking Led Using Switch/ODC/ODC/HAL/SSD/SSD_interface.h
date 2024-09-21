/*
 * SSD_interface.h
 *
 * Created: 9/15/2024 8:14:08 PM
 *  Author: RAWAN
 */ 


#include "../../LIB/STD_TYPE.h"


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_


/*SSD TYPES*/
#define COMMON_CATHODE  0
#define COMMON_ANODE    1

/*Defining SSD as common cathode*/
#define SSD_TYPE COMMON_CATHODE


void SSD_voidInit(u8 copy_u8port);
void SSD_voidDisplayNumberAscending(u8 copy_u8port, u8 copy_u8number);
void SSD_voidDisplayNumberDescending(u8 copy_u8port, u8 copy_u8number);


#endif /* SSD_INTERFACE_H_ */