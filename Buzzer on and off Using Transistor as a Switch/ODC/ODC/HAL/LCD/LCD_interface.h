/*
 * LCD_interface.h
 *
 * Created: 9/17/2024 9:46:59 PM
 *  Author: RAWAN
 */ 
#include "../../LIB/STD_TYPE.h"


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/*LCD Modes to select from*/
#define _4_BIT_MODE 0
#define _8_BIT_MODE 1


#define LCD_MODE _4_BIT_MODE


void LCD_voidSendCommand(u8 copy_u8command);
void LCD_voidSendData(u8 copy_u8data);
void LCD_voidInit(void);


void LCD_voidSendString(u8 *str);

void LCD_voidGotoxy(u8 copy_u8x, u8 copy_u8y);

void LCD_voidDrawData(u8 copy_u8pattern, u8 *data, u8 copy_u8x, u8 copy_u8y);

void LCD_voidSendNumber(u32 copy_u8number);


#endif /* LCD_INTERFACE_H_ */