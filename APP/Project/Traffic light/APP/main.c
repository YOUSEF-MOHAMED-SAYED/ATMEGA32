/*
 * main.c
 *
 *  Created on: 16 Aug 2023
 *      Author: Youssef
 */

#include "../LIB/STD_TYPES.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/7_segment/7_Segment_init.h"
#include "../MCAL/DIO.h"
#include "../HAL/KPD/KPD_Init.h"
#include <util/delay.h>

int main()
{
	MDIO_VoidSetPortDirection(PORTA , 0XFF);
	MDIO_VoidSetPortDirection(PORTB , 0XFF);
	HLCD_VoidInit();
	HSSD_voidInit(PORTC);
	HSSD_voidInit(PORTD);
	HLCD_VoidSetString("Welcome to Cairo Traffic Signals ");
	_delay_ms(300);
	HLCD_VoidClear();
	HLCD_VoidCurser(LCD_LINE_2 , 2);
	HLCD_VoidSetString("Please Follow the Rules");
	_delay_ms(300);
	HLCD_VoidClear();
	while(1)
	{
		MDIO_VoidSETPortBit(PORTB , PIN3 , HIGH);
		HLCD_VoidCurser(1,8);
		HLCD_VoidSetString("GO");
		HSSD_voidDisplayNum(PORTC , 4);
		HSSD_voidDisplayNum(PORTD , 0);
		_delay_ms(1000);
		HSSD_voidDisplayNum(PORTC , Three);
		HSSD_voidCountDOWN(PORTD , Nine);
		HSSD_voidDisplayNum(PORTD,Zero);
		_delay_ms(1000);
		HSSD_voidDisplayNum(PORTC , Two);
		HSSD_voidCountDOWN(PORTD , Nine);
		HSSD_voidDisplayNum(PORTD,Zero);
		_delay_ms(1000);
		HSSD_voidDisplayNum(PORTC , One);
		HSSD_voidCountDOWN(PORTD , Nine);
		HSSD_voidDisplayNum(PORTD,Zero);
		_delay_ms(1000);
		HSSD_voidDisplayNum(PORTC , Zero);
		HSSD_voidCountDOWN(PORTD , Nine);
		HSSD_voidDisplayNum(PORTD,Zero);
		_delay_ms(1000);
		HSSD_voidTurnOFF(PORTC);
		HLCD_VoidClear();
		HLCD_VoidCurser(1,7);
		HLCD_VoidSetString("READY");
		MDIO_VoidSETPortBit(PORTB , PIN3 , LOW);
		MDIO_VoidSETPortBit(PORTB , PIN4 , HIGH);
		HSSD_voidCountDOWN(PORTD , Three);
		HSSD_voidDisplayNum(PORTD,Zero);
		_delay_ms(1000);
		HLCD_VoidClear();
		MDIO_VoidSETPortBit(PORTB , PIN4 , LOW);
		HSSD_voidInit(PORTC);
		MDIO_VoidSETPortBit(PORTB , PIN5 , HIGH);
		HLCD_VoidCurser(1,7);
		HLCD_VoidSetString("STOP");
		HSSD_voidDisplayNum(PORTC , 4);
		HSSD_voidDisplayNum(PORTD , 0);
		_delay_ms(1000);
		HSSD_voidDisplayNum(PORTC , Three);
		HSSD_voidCountDOWN(PORTD , Nine);
		HSSD_voidDisplayNum(PORTD,Zero);
		_delay_ms(1000);
		HSSD_voidDisplayNum(PORTC , Two);
		HSSD_voidCountDOWN(PORTD , Nine);
		HSSD_voidDisplayNum(PORTD,Zero);
		_delay_ms(1000);
		HSSD_voidDisplayNum(PORTC , One);
		HSSD_voidCountDOWN(PORTD , Nine);
		HSSD_voidDisplayNum(PORTD,Zero);
		_delay_ms(1000);
		HSSD_voidDisplayNum(PORTC , Zero);
		HSSD_voidCountDOWN(PORTD , Nine);
		HSSD_voidDisplayNum(PORTD,Zero);
		_delay_ms(1000);
		HSSD_voidTurnOFF(PORTC);
		HLCD_VoidClear();
		MDIO_VoidSETPortBit(PORTB , PIN5 , LOW);

	}
	return 0;
}
