/*
 * KEYPAD_prog.c
 *
 * Created: 9/22/2024 9:04:31 PM
 *  Author: RAWAN
 */ 


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "KEYPAD_config.h"


u8 KEYPAD_ARR[4][4] = {{7, 8, 9, '/'},
					   {4, 5, 6, '*'},
					   {1, 2, 3, '-'},
					   {'c', 0, '=', '+'}};
						   
u8 COL_ARR[4] = {KEYPAD_COL0_PIN, KEYPAD_COL1_PIN, KEYPAD_COL2_PIN, KEYPAD_COL3_PIN};
u8 ROW_ARR[4] = {KEYPAD_ROW0_PIN, KEYPAD_ROW1_PIN, KEYPAD_ROW2_PIN, KEYPAD_ROW3_PIN};

void KEYPAD_voidInit(void)
{
	u8 loc_it = 0;
	for (loc_it = 0; loc_it < 4; loc_it++)
	{
		/*Set COL pins as OUTPUT HIGH*/
		DIO_voidSetPinDir(KEYPAD_COL_PORT, COL_ARR[loc_it], OUTPUT);
		DIO_voidSetPinVal(KEYPAD_COL_PORT, COL_ARR[loc_it], HIGH);	
		
		/*Set ROW pins as INPUT HIGH to enable internal pull_up*/
		DIO_voidSetPinDir(KEYPAD_ROW_PORT, ROW_ARR[loc_it], INPUT);
		DIO_voidSetPinVal(KEYPAD_ROW_PORT, ROW_ARR[loc_it], HIGH);
	}
}

u8 KEYPAD_u8GetKey(void)
{
	u8 row = 0;
	u8 col = 0;
	u8 val = 0;
	
	/*Loop over each col*/
	for (col = 0; col < 4; col++)
	{
		/*Set current col as low*/
		DIO_voidSetPinVal(KEYPAD_COL_PORT, COL_ARR[col], LOW);
		
		/*Loop over each row*/
		for (row = 0; row < 4; row++)
		{
			/*Check if the key is pressed*/
			if (DIO_u8ReadPinVal(KEYPAD_ROW_PORT, ROW_ARR[row]) == 0)
			{
				val = KEYPAD_ARR[col][row];
				
				/*Check if the key is still pressed*/
				while (DIO_u8ReadPinVal(KEYPAD_ROW_PORT, ROW_ARR[row]) == 0);
				return val;	
			}
		}
		
		/*Set current col as HIGH again*/
		DIO_voidSetPinVal(KEYPAD_COL_PORT, COL_ARR[col], HIGH);
	}
	
	return val;
}	
