/*
 * LCD.c
 *
 *  Created on: 15 Aug 2023
 *      Author: Youssef
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO.h"
#include "LCD.h"
#include <util/delay.h>

void HLCD_VoidSendCommand(u8 A_U8cmd)
{
	/* control RS and R/W pins */
	MDIO_VoidSETPortBit(Control_PORT , PIN0 , LOW);
	MDIO_VoidSETPortBit(Control_PORT , PIN1 , LOW);
	/* write command */
	MDIO_VoidSetPortValue(Data_PORT, A_U8cmd);
	/* pulse on Enable */
	MDIO_VoidSETPortBit(Control_PORT , PIN2 , HIGH);
	_delay_ms(1);
	MDIO_VoidSETPortBit(Control_PORT , PIN2 , LOW);
	_delay_ms(1);
}
void HLCD_VoidSendData(u8 A_U8data)
{
	/* control RS and R/W pins */
	MDIO_VoidSETPortBit(Control_PORT , PIN0 , HIGH);
	MDIO_VoidSETPortBit(Control_PORT , PIN1 , LOW);
	/* write DATA */
	MDIO_VoidSetPortValue(Data_PORT, A_U8data);
	/* pulse on Enable */
	MDIO_VoidSETPortBit(Control_PORT , PIN2 , HIGH);
	_delay_ms(1);
	MDIO_VoidSETPortBit(Control_PORT , PIN2 , LOW);
	_delay_ms(1);
}

void HLCD_VoidInit()
{
	// wait 30ms
	_delay_ms(30);
	// function set
	HLCD_VoidSendCommand(LCD_FunctionSet);
	//wait more than 39us -> 1ms
	_delay_ms(1);
	// display on/off
	HLCD_VoidSendCommand(LCD_DisplayOnOff);
	//wait more than 39us -> 1ms
	_delay_ms(1);
	// display clear
	HLCD_VoidSendCommand(LCD_DisplayClear);
	//wait more than 1.53ms -> 2ms
	_delay_ms(2);
	// Entry Mode
	HLCD_VoidSendCommand(LCD_EntryMode);
}

void HLCD_VoidClear()
{
	HLCD_VoidSendCommand(LCD_DisplayClear);
	_delay_ms(2);
}

void HLCD_VoidSetString(u8 *A_U8ptrString )
{
	u8 Counter = 0 ;
	while (*A_U8ptrString > 0)
	{
		Counter++;
		HLCD_VoidSendData( *A_U8ptrString ++);
		_delay_ms(50);
		if(Counter == 16)
		{
			HLCD_VoidSendCommand(LCD_EntryModeShift);
		}
	}
	HLCD_VoidSendCommand(LCD_EntryMode);
}

void HLCD_VoidCurser(u8 A_U8RowNO , u8 A_U8ColNO )
{
	switch(A_U8RowNO)
	{
		case LCD_LINE_1 : HLCD_VoidSendCommand(LCD_ROW1 + A_U8ColNO); break;
		case LCD_LINE_2 : HLCD_VoidSendCommand(LCD_ROW2 + A_U8ColNO); break;

	}
}

void HLCD_VoidDisplayNumber(s32 A_S32Number)
{
	u32 L_Number = 1 ;
	if( A_S32Number == 0)
		HLCD_VoidSendData('0');
	if( A_S32Number < 0)
	{
		HLCD_VoidSendData('-');
		A_S32Number *= -1 ;
	}
	while(A_S32Number != 0 )
	{
		L_Number = (L_Number *10) + A_S32Number%10 ;
		A_S32Number = A_S32Number/10 ;
	}
	while( L_Number != 1)
	{
		HLCD_VoidSendData((L_Number%10 + 48));
		L_Number =L_Number /10 ;
	}
}

void HLCD_VoidSaveCustomCharacter(u8 A_CGRAMIndex , u8 A_U8Character[])
{
	//GO to CGRAM and book 8 Location
	HLCD_VoidSendCommand(0b01000000 + (A_CGRAMIndex *8));
	for(u8 IndexCounter = 0 ; IndexCounter < 8 ; IndexCounter++)
	{
		HLCD_VoidSendData(A_U8Character[IndexCounter]);
	}
	//GOback to DDRAM
	HLCD_VoidSendCommand(0X80);
}

void HLCD_VoidDisplayCustomCharacter(u8 A_CGRAMIndex)
{
	if( A_CGRAMIndex <= 8)
	{
		HLCD_VoidSendData(A_CGRAMIndex);
	}
}

