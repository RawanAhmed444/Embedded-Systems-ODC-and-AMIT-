/*
 * SSD_prog.c
 *
 * Created: 9/15/2024 8:14:22 PM
 *  Author: RAWAN
 */ 


#include "SSD_interface.h"
#include "SSD_config.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"


void SSD_voidInit(u8 copy_u8port)
{
	//Set the whole PORT as OUTPUT
	DIO_voidSetPortDir(copy_u8port, 0xFF);
}


void SSD_voidDisplayNumberAscending(u8 copy_u8port, u8 copy_u8number)
{
	u8 arr [10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	DIO_voidSetPortVal(copy_u8port, arr[copy_u8number]);
}


void SSD_voidDisplayNumberDescending(u8 copy_u8port, u8 copy_u8number)
{
	u8 arr [10] = {0x6F, 0x7F, 0x07, 0x7D, 0x6D, 0x66, 0x4F, 0x5B, 0x06, 0x3F};
	DIO_voidSetPortVal(copy_u8port, arr[copy_u8number]);
}
