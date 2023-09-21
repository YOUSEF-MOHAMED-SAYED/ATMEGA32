/*
 * main.c
 *
 *  Created on: 20 Aug 2023
 *      Author: Youssef
 */

#include "../MCAL/EXTI/GIE_Init.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/TIMERS/Timer_Init.h"

volatile u8 flag = 0 ;
void toggle ()
{
	if (flag == 1)
	{
		MDIO_VoidSETPinValue(PORTC , PIN0 , HIGH);
		flag = 0 ;
	}
	else
	{
		MDIO_VoidSETPinValue(PORTC , PIN0 , LOW);
		flag = 1 ;
	}
}

void main()
{
	MDIO_VoidSetPINDirecion(PORTC , PIN0 , OUTPUT);
	MGIE_VoidEnable();
	MTIMERS_voidInit();
	MTIMERS_VoidSetIntervals(2000 , toggle);
	MTIMERS_VoidStart();
	while(1)
	{

	}

}
