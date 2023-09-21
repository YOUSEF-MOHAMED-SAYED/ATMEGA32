/*
 * main.c
 *
 *  Created on: 16 Aug 2023
 *      Author: Youssef
 */

#include "../LIB/STD_TYPES.h"
#include "../HAL/LCD/LCD.h"
#include "../MCAL/DIO.h"
#include "../HAL/KPD/KPD_Init.h"
#include <util/delay.h>

void main()
{
	MDIO_VoidSetPortDirection(PORTA , 0XFF);
	MDIO_VoidSetPortDirection(PORTB , 0XFF);
	HLCD_VoidInit();
	HKPD_VoidInit();
	u8 Meem1[]={0x00, 0x00, 0x00, 0x1F, 0x05, 0x07, 0x00, 0x00};
	u8 Ein[]={0x08, 0x14, 0x10, 0x0F, 0x08, 0x08, 0x06, 0x00};
	u8 Alf[]={0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00};
	u8 Lam[]={0x01, 0x01, 0x01, 0x1F, 0x00, 0x00, 0x00, 0x00};
	u8 Seen[]={0x00, 0x00, 0x15, 0x1F, 0x00, 0x00, 0x00, 0x00};
	u8 LamAlf[]={0x02, 0x12, 0x0A, 0x07, 0x1E, 0x00, 0x00};
	u8 Meem2[]={0x00, 0x00, 0x00, 0x1F, 0x05, 0x07, 0x00, 0x00};
	u8 Haah[]={0x1C, 0x14, 0x1C, 0x07, 0x00, 0x00, 0x00, 0x00};
	HLCD_VoidSaveCustomCharacter(0,Meem1);
	HLCD_VoidSaveCustomCharacter(1,Ein);
	HLCD_VoidSaveCustomCharacter(2,Alf);
	HLCD_VoidSaveCustomCharacter(3,Lam);
	HLCD_VoidSaveCustomCharacter(4,Seen);
	HLCD_VoidSaveCustomCharacter(5,LamAlf);
	HLCD_VoidSaveCustomCharacter(6,Meem2);
	HLCD_VoidSaveCustomCharacter(7,Haah);
	u8 L_Pressed =0 ;
	u8 L_Sign = '+' ;
	s32 L_Operand1 = 0 , L_Operand2 =0;
	u8 L_TheOperation =0 ;
	f32 L_Result =0 ;
	HLCD_VoidSetString("Welcome Dude");
	_delay_ms(500);
	HLCD_VoidClear();

	while(1)
	{
		if( L_Pressed != '+' && L_Pressed != '-' && L_Pressed != '*' && L_Pressed != '/' )
		{
			 L_Sign = '+' ;
			 L_Operand1 = 0 ;
			 L_Operand2 =0 ;
			 L_Result =0 ;
			 if(L_Pressed == 'C'){
				HLCD_VoidCurser(LCD_LINE_1 , 13);
				HLCD_VoidDisplayCustomCharacter(0);
				HLCD_VoidCurser(LCD_LINE_1 , 12);
				HLCD_VoidDisplayCustomCharacter(1);
				HLCD_VoidCurser(LCD_LINE_1,11);
				HLCD_VoidSendData(' ');
				HLCD_VoidCurser(LCD_LINE_1 , 10);
				HLCD_VoidDisplayCustomCharacter(2);
				HLCD_VoidCurser(LCD_LINE_1 , 9);
				HLCD_VoidDisplayCustomCharacter(3);
				HLCD_VoidCurser(LCD_LINE_1 , 8);
				HLCD_VoidDisplayCustomCharacter(4);
				HLCD_VoidCurser(LCD_LINE_1 , 7);
				HLCD_VoidDisplayCustomCharacter(5);
				HLCD_VoidCurser(LCD_LINE_1 , 6);
				HLCD_VoidDisplayCustomCharacter(6);
				HLCD_VoidCurser(LCD_LINE_1 , 5);
				HLCD_VoidDisplayCustomCharacter(7);
				_delay_ms(700);
				HLCD_VoidClear();
				break;
			 }
			// Enter the first operand
			L_Sign = HKPD_U8GetPressedKey();
			// If operand is negative number
			if(L_Sign == '-')
			{
				HLCD_VoidSendData(L_Sign);
				L_Pressed = HKPD_U8GetPressedKey();
			}
			else
			{
			L_Pressed = L_Sign ;
			}
			while( L_Pressed != '+' && L_Pressed != '-' && L_Pressed != '*' && L_Pressed != '/' && L_Pressed != '=')
			{
				if(L_Pressed != 'C')
				{
					HLCD_VoidDisplayNumber(L_Pressed);
					L_Operand1 = L_Operand1*10 + L_Pressed ;//store first number in Operand one
				}
				else
				{
					HLCD_VoidCurser(LCD_LINE_1 , 13);
					HLCD_VoidDisplayCustomCharacter(0);
					HLCD_VoidCurser(LCD_LINE_1 , 12);
					HLCD_VoidDisplayCustomCharacter(1);
					HLCD_VoidCurser(LCD_LINE_1,11);
					HLCD_VoidSendData(' ');
					HLCD_VoidCurser(LCD_LINE_1 , 10);
					HLCD_VoidDisplayCustomCharacter(2);
					HLCD_VoidCurser(LCD_LINE_1 , 9);
					HLCD_VoidDisplayCustomCharacter(3);
					HLCD_VoidCurser(LCD_LINE_1 , 8);
					HLCD_VoidDisplayCustomCharacter(4);
					HLCD_VoidCurser(LCD_LINE_1 , 7);
					HLCD_VoidDisplayCustomCharacter(5);
					HLCD_VoidCurser(LCD_LINE_1 , 6);
					HLCD_VoidDisplayCustomCharacter(6);
					HLCD_VoidCurser(LCD_LINE_1 , 5);
					HLCD_VoidDisplayCustomCharacter(7);
					_delay_ms(700);
					HLCD_VoidClear();
					break;
				}
				L_Pressed = HKPD_U8GetPressedKey();
			}
			if(L_Sign == '-')
			{
				L_Operand1 *= -1 ;
				L_Sign = '+';
			}
			// select the operation
			if(L_Pressed != '=')
			{
				HLCD_VoidSendData(L_Pressed);
				L_TheOperation = L_Pressed ;
			}
			// Enter The second Operand
			if (L_Pressed != '=')
			{
				L_Sign = HKPD_U8GetPressedKey();
				// If operand is negative number
				if(L_Sign == '-')
				{
					HLCD_VoidSendData(L_Sign);
					L_Pressed = HKPD_U8GetPressedKey();
				}
				else
				{
				L_Pressed = L_Sign ;
				}
				while( L_Pressed != '=')
				{
					if(L_Pressed != 'C')
					{
						HLCD_VoidDisplayNumber(L_Pressed);
						L_Operand2 = L_Operand2*10 + L_Pressed ;//store second number in Operand2
					}
					else
					{
						HLCD_VoidCurser(LCD_LINE_1 , 13);
						HLCD_VoidDisplayCustomCharacter(0);
						HLCD_VoidCurser(LCD_LINE_1 , 12);
						HLCD_VoidDisplayCustomCharacter(1);
						HLCD_VoidCurser(LCD_LINE_1,11);
						HLCD_VoidSendData(' ');
						HLCD_VoidCurser(LCD_LINE_1 , 10);
						HLCD_VoidDisplayCustomCharacter(2);
						HLCD_VoidCurser(LCD_LINE_1 , 9);
						HLCD_VoidDisplayCustomCharacter(3);
						HLCD_VoidCurser(LCD_LINE_1 , 8);
						HLCD_VoidDisplayCustomCharacter(4);
						HLCD_VoidCurser(LCD_LINE_1 , 7);
						HLCD_VoidDisplayCustomCharacter(5);
						HLCD_VoidCurser(LCD_LINE_1 , 6);
						HLCD_VoidDisplayCustomCharacter(6);
						HLCD_VoidCurser(LCD_LINE_1 , 5);
						HLCD_VoidDisplayCustomCharacter(7);
						_delay_ms(700);
						HLCD_VoidClear();
						break;
					}
					L_Pressed = HKPD_U8GetPressedKey();
				}
				if(L_Sign == '-')
				{
					L_Operand2 *= -1 ;
					L_Sign = '+';
				}
			}
			HLCD_VoidCurser(2,5);
			switch(L_TheOperation)
			{
			case '+': L_Result = L_Operand1 + L_Operand2 ; break;
			case '-': L_Result = L_Operand1 - L_Operand2 ; break;
			case '*': L_Result = L_Operand1 * L_Operand2 ; break;
			case '/':
				if( L_Operand2 == 0)
				{
					HLCD_VoidSetString("MATH ERROR");
					_delay_ms(400);
					HLCD_VoidClear();
					break;
				}
				else
				{
				L_Result = (f32)(L_Operand1 / L_Operand2) ; break;
				}
			}
			HLCD_VoidDisplayNumber(L_Result);
			L_Pressed = HKPD_U8GetPressedKey();
			HLCD_VoidClear();
		}
		else
		{
			L_Operand1 = 0 ; L_Operand2 = 0 ;
			HLCD_VoidDisplayNumber(L_Result);
			L_TheOperation = L_Pressed;
			if(L_TheOperation != 0)
			{
				HLCD_VoidSendData(L_TheOperation);
			}
			L_Sign = HKPD_U8GetPressedKey();
			// If operand is negative number
			if(L_Sign == '-')
			{
				HLCD_VoidSendData(L_Sign);
				L_Pressed = HKPD_U8GetPressedKey();
			}
			else
			{
			L_Pressed = L_Sign ;
			}
			while( L_Pressed != '+' && L_Pressed != '-' && L_Pressed != '*' && L_Pressed != '/' && L_Pressed != '=')
			{
				if(L_Pressed != 'C')
				{
					HLCD_VoidDisplayNumber(L_Pressed);
					L_Operand1 = L_Operand1*10 + L_Pressed ;//store  number in Operand one
				}
				else
				{
					HLCD_VoidCurser(LCD_LINE_1 , 13);
					HLCD_VoidDisplayCustomCharacter(0);
					HLCD_VoidCurser(LCD_LINE_1 , 12);
					HLCD_VoidDisplayCustomCharacter(1);
					HLCD_VoidCurser(LCD_LINE_1,11);
					HLCD_VoidSendData(' ');
					HLCD_VoidCurser(LCD_LINE_1 , 10);
					HLCD_VoidDisplayCustomCharacter(2);
					HLCD_VoidCurser(LCD_LINE_1 , 9);
					HLCD_VoidDisplayCustomCharacter(3);
					HLCD_VoidCurser(LCD_LINE_1 , 8);
					HLCD_VoidDisplayCustomCharacter(4);
					HLCD_VoidCurser(LCD_LINE_1 , 7);
					HLCD_VoidDisplayCustomCharacter(5);
					HLCD_VoidCurser(LCD_LINE_1 , 6);
					HLCD_VoidDisplayCustomCharacter(6);
					HLCD_VoidCurser(LCD_LINE_1 , 5);
					HLCD_VoidDisplayCustomCharacter(7);
					_delay_ms(700);
					HLCD_VoidClear();
					break;
				}
				L_Pressed = HKPD_U8GetPressedKey();
			}
			if(L_Sign == '-')
			{
				L_Operand1 *= -1 ;
				L_Sign = '+';
			}
			HLCD_VoidCurser(2,5);
			switch(L_TheOperation)
			{
			case '+': L_Result = L_Result + L_Operand1 ; break;
			case '-': L_Result = L_Result - L_Operand1 ; break;
			case '*': L_Result = L_Result * L_Operand1 ; break;
			case '/':
				if( L_Operand1 == 0)
				{
					HLCD_VoidSetString("MATH ERROR");
					_delay_ms(400);
					HLCD_VoidClear();
					break;
				}
				else
				{
				L_Result = L_Result / L_Operand1 ; break;
				}
			}
			HLCD_VoidDisplayNumber(L_Result);
			L_Pressed = HKPD_U8GetPressedKey();
			HLCD_VoidClear();
		}
	}
}
