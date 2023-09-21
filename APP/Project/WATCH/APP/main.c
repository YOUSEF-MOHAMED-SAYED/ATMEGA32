/*
 * main.c
 *
 *  Created on: 13 Aug 2023
 *      Author: Youssef
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO.h"
#include "../HAL/7_Segment_init.h"


int main()
{
	u8 iteration1 = 1 ;
	u8 iteration2 = 1 ;
	u8 iteration3 = 0 ;
	HSSD_voidInit(PORTA);
	HSSD_voidInit(PORTD);
	HSSD_voidInit(PORTC);
	HSSD_voidInit(PORTB);
	HSSD_voidDisplayNum(PORTB , 1);
	HSSD_voidDisplayNum(PORTA , 2);
	while(1)
	{
		HSSD_voidCountUP(PORTD , Zero);
		HSSD_voidDisplayNum(PORTC , iteration1 );
		iteration1++;
		if( iteration1 > 6)
		{
			iteration1 = 1 ;
			HSSD_voidDisplayNum(PORTC , 0 );
			HSSD_voidDisplayNum(PORTA , iteration2 );
			HSSD_voidDisplayNum(PORTB , iteration3 );
			iteration2++;
			if(iteration2 > 9)
			{
				iteration3++;
			}
		}
	}
}
