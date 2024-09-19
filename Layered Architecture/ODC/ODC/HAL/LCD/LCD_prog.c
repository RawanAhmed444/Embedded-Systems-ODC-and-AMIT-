/*
 * LCD_prog.c
 *
 * Created: 9/17/2024 9:46:43 PM
 *  Author: RAWAN
 */ 
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "LCD_interface.h"
#include "LED_config.h"


#define  F_CPU 16000000UL
#include <util/delay.h>


void LCD_voidSendHighData(u8 copy_u8data)
{
	u8 LCD_PINS[4] = {LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN};
	u8 LOC_u8it = 0;
	for (LOC_u8it = 0; LOC_u8it < 4; LOC_u8it++)
	{
		/*Getting the value of each bit in each iteration*/
		DIO_voidSetPinVal(LCD_DPORT, LCD_PINS[LOC_u8it], GET_BIT(copy_u8data, LOC_u8it));
	}
}

void LCD_voidSendEnablePulse()
{
	/*Send Enable pulse*/
	DIO_voidSetPinVal(LCD_CPORT, LCD_EN_PIN, HIGH);
	_delay_ms(2);
	DIO_voidSetPinVal(LCD_CPORT, LCD_EN_PIN, LOW);
}

void LCD_voidSendCommand(u8 copy_u8command)
{
	/*Making RS pin as low to send command*/
	DIO_voidSetPinVal(LCD_CPORT, LCD_RS_PIN, LOW);
	
	/*Making RW pin as ow to write command*/
	DIO_voidSetPinVal(LCD_CPORT, LCD_RW_PIN, LOW);
	
	/*Check if it was 4_bit_mode or 8_bit_mode*/
	#if LCD_MODE == _8_BIT_MODE
		/*Send Command*/
		DIO_voidSetPortVal(LCD_DPORT, copy_u8command);
		/*Send Enable pulse*/
		LCD_voidSendEnablePulse();
	#elif LCD_MODE == _4_BIT_MODE
		/*Sending the MSBs of the command first*/
		LCD_voidSendHighData(copy_u8command>>4);
		LCD_voidSendEnablePulse();
		/*Sending the LSBs of the command*/
		LCD_voidSendHighData(copy_u8command);
		LCD_voidSendEnablePulse();
	#endif	
}

void LCD_voidSendData(u8 copy_u8data)
{
	/*Making RS pin as high to send data*/
	DIO_voidSetPinVal(LCD_CPORT, LCD_RS_PIN, HIGH);
	
	/*Making RW pin as ow to write data*/
	DIO_voidSetPinVal(LCD_CPORT, LCD_RW_PIN, LOW);
	
	/*Check if it was 4_bit_mode or 8_bit_mode*/
	#if LCD_MODE == _8_BIT_MODE
	/*Send Data*/
	DIO_voidSetPortVal(LCD_DPORT, copy_u8data);
	/*Send Enable pulse*/
	LCD_voidSendEnablePulse();
	
	#elif LCD_MODE == _4_BIT_MODE
	/*Sending the MSBs of the data first*/
	LCD_voidSendHighData(copy_u8data>>4);
	LCD_voidSendEnablePulse();
	/*Sending the LSBs of the data*/
	LCD_voidSendHighData(copy_u8data);
	LCD_voidSendEnablePulse();
	
	#endif
}

void LCD_voidInit(void)
{
	_delay_ms(40);
	#if LCD_MODE == _8_BIT_MODE
	/*Send command function set*/
	LCD_voidSendCommand(0b00111000)	//Activating 2 lines display and 5x7 dots character font set
	
	#elif LCD_MODE == _4_BIT_MODE
	LCD_voidSendHighData(0b0010);
	LCD_voidSendEnablePulse();
	LCD_voidSendHighData(0b0010);
	LCD_voidSendEnablePulse();
	LCD_voidSendHighData(0b1000);
	LCD_voidSendEnablePulse();
	
	#endif
	
	/*Sending command display on/off*/
	_delay_us(45);
	LCD_voidSendCommand(0b00001111);	//Setting the entire display on and displaying the cursor and making it blinks
	/*Sending command display clear*/
	_delay_us(45);
	LCD_voidSendCommand(0b00000001);
	/*Sending command entry mode set*/ 
	_delay_ms(2);
	LCD_voidSendCommand(0b00000111);	//Setting I/D as high to increase the cursor as we write in EN, and also activating the shifting to move on the LCD  
}

void LCD_voidSendString(u8 *str)
{
	u8 i = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		LCD_voidSendData(str[i]);
	}	
}

void LCD_voidGotoxy(u8 copy_u8x, u8 copy_u8y)
{
	/*Setting the address where i want to go*/
	/*0x40 = 64 in decimal (Multiplying the row index by 64 gives us the starting address of that row.
	 *Adding the column index to this starting address gives us the final address of the desired cell within the DDRAM.)*/
	u8 DDRAM_address = copy_u8x + copy_u8y * 0x40;	
	
	/*Setting bit DP7 TO 1 as in the instruction of setting DDRAM address*/
	SET_BIT(DDRAM_address, 7);
	
	/*Sending the command*/
	LCD_voidSendCommand(DDRAM_address);
}

void LCD_voidDrawData(u8 copy_u8pattern, u8 *data, u8 copy_u8x, u8 copy_u8y)
{
	/*Setting the address where i want to go in CGRAM*/
	/*CGRAM is typically divided into 8-byte blocks. 
	 *Each block represents a single custom character pattern.
	 *To calculate the starting address of the desired pattern block, we multiply the pattern index by 8.
	 *This ensures that the address points to the beginning of the correct 8-byte block.
	 */
	u8 CGRAM_address = copy_u8pattern * 8;
	
	/*Setting bit DP6 TO 0 as in the instruction of setting CGRAM address*/
	CLR_BIT(CGRAM_address, 6);
	/*Setting bit DP7 TO 1 as in the instruction of setting CGRAM address*/
	SET_BIT(CGRAM_address, 7);
	
	/*Sending the command*/
	LCD_voidSendCommand(CGRAM_address);
	
	/*Draw data in the CGRAM*/
	u8 loc_i = 0;
	/*Writing each byte of the custom character data from the data array to the CGRAM*/
	for (loc_i = 0; loc_i < 8; loc_i++)
	{
		LCD_voidSendData(data[loc_i]);
	}
	
	/*Go to the location in the DDRAM*/
	LCD_voidGotoxy(copy_u8x, copy_u8y);
	
	/*Sending data to the DDRAM*/
	LCD_voidSendData(copy_u8pattern);
}

void LCD_voidSendNumber(u32 copy_u8number)
{
	u8 array[10];
	if (copy_u8number == 0)
	{
		LCD_voidSendData('0');
		return;	
	}
	s8 i = 0;
	for (i = 0; copy_u8number != 0; i++)
	{
		array[i] = copy_u8number % 10 + 48;
		copy_u8number /= 10;
	}
	i--;
	while (i >= 0)
	{
		LCD_voidSendData(array[i]);
		i--;
	}
}