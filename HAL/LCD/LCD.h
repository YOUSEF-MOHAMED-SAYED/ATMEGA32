/*
 * LCD.h
 *
 *  Created on: 15 Aug 2023
 *      Author: Youssef
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#include "../../LIB/STD_TYPES.h"


#define Control_PORT PORTB
#define Data_PORT    PORTA

#define LCD_FunctionSet   0b00111100
#define LCD_DisplayOnOff  0b00001100
#define LCD_DisplayClear  0b00000001
#define LCD_EntryMode     0b00000110
#define LCD_EntryModeShift 0b00000111


#define LCD_ROW1   127
#define LCD_ROW2   191
#define LCD_LINE_1 1
#define LCD_LINE_2 2

void HLCD_VoidSendCommand(u8 A_U8cmd);
void HLCD_VoidInit();
void HLCD_VoidSendData(u8 A_U8data);
void HLCD_VoidClear();
void HLCD_VoidCurser(u8 A_U8RowNO , u8 A_U8ColNO );
void HLCD_VoidSetString(u8 *A_U8ptrString );
void HLCD_VoidDisplayNumber(s32 A_S32Number);
void HLCD_VoidSaveCustomCharacter(u8 A_CGRAMIndex , u8 A_U8Character[]);
void HLCD_VoidDisplayCustomCharacter(u8 A_CGRAMIndex);


#endif /* HAL_LCD_LCD_H_ */
