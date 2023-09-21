/*
 * KBD.c
 *
 *  Created on: 14 Aug 2023
 *      Author: Youssef
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO.h"
#include "KPD_Init.h"
#include <util/delay.h>


u8 GKPD_KEYS[ KPD_ROWS ][ KPD_COLUMNS ] = {
		{ 7 , 8 , 9 , '/' },
		{ 4 , 5 , 6 , '*' },
		{ 1 , 2 , 3 , '-' },
		{ 'C' , 0 , '=' , '+' }
};
void HKPD_VoidInit()
{
	MDIO_VoidSetPortDirection( KPD_PORT ,0X0F);
	MDIO_VoidSetPortValue( KPD_PORT , 0XFF);
}

u8 HKPD_U8GetPressedKey()
{
	u8 Pressed_Key ;
	u8 Stop = 1 ;
	while(Stop)
	{
		for(u8 col = 0 ; col < KPD_COLUMNS ; col++)
		{
			MDIO_VoidSETPortBit( KPD_PORT , col , LOW ); // Active current column
			for(u8 row = 0 ; row < KPD_ROWS ; row++)
			{
				if( MDIO_U8GetPinValue( KPD_PORT , row+4) == 0)
				{
					_delay_ms(20);
					while(MDIO_U8GetPinValue( KPD_PORT , row+4) == 0){}
					_delay_ms(20);
					Pressed_Key = GKPD_KEYS[row][col];
					Stop = 0 ;
				}
			}
			MDIO_VoidSETPortBit( KPD_PORT , col , HIGH ); // DeActive current column
		}
	}
	return Pressed_Key ;
}
