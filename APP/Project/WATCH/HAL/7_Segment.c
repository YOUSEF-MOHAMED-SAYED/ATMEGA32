/*
 *
 *  Created on: 13 Aug 2023
 *      Author: Youssef
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO.h"
#include <util/delay.h>
#include "7_Segment_init.h"

/* FOLLOW This Table for Common Cathode **
 *  Decimal | DOT | G | F | E | D | C | B | A *
 *    0     |  0  | 0 | 1 | 1 | 1 | 1 | 1 | 1 *
 *    1     |  0  | 0 | 0 | 0 | 0 | 1 | 1 | 0 *
 *    2     |  0  | 1 | 0 | 1 | 1 | 0 | 1 | 1 *
 *    3     |  0  | 1 | 0 | 0 | 1 | 1 | 1 | 1 *
 *    4     |  0  | 1 | 1 | 0 | 0 | 1 | 1 | 0 *
 *    5     |  0  | 1 | 1 | 0 | 1 | 1 | 0 | 1 *
 *    6     |  0  | 1 | 1 | 1 | 1 | 1 | 0 | 1 *
 *    7     |  0  | 0 | 0 | 0 | 0 | 1 | 1 | 1 *
 *    8     |  0  | 1 | 1 | 1 | 1 | 1 | 1 | 1 *
 *    9     |  0  | 1 | 1 | 0 | 1 | 1 | 1 | 1 *
 */
u8 NUMS[10]={
		0b00111111 , //0
		0b00000110 , //1
		0b01011011 , //2
		0b01001111 , //3
		0b01100110 , //4
		0b01101101 , //5
		0b01111101 , //6
		0b00000111 , //7
		0b01111111 , //8
		0b01101111   //9
};

void HSSD_voidInit(u8 A_U8SSD_PORT )
{
	MDIO_VoidSetPortDirection( A_U8SSD_PORT , 0XFF);
}

void HSSD_voidDisplayNum(u8 A_U8SSD_PORT , u8 A_U8Num)
{
#if   SSD_Type == 1
	MDIO_VoidSetPortValue(A_U8SSD_PORT ,NUMS[A_U8Num]);
#elif SSD_Type == 2
	MDIO_VoidSetPortValue(A_U8SSD_PORT ,~NUMS[A_U8Num]);
#endif
}

void HSSD_voidCountUP(u8 A_U8SSD_PORT , u8 A_U8Num)
{
	for(u8 Counter = A_U8Num ; Counter <= 9 ; Counter++ )
	{
		HSSD_voidDisplayNum(A_U8SSD_PORT, Counter );
		_delay_ms(1000);
	}
}

void HSSD_voidCountDOWN(u8 A_U8SSD_PORT , u8 A_U8Num)
{
	for(u8 Counter = A_U8Num ; Counter >= Zero ; Counter-- )
	{
		HSSD_voidDisplayNum(A_U8SSD_PORT, Counter );
		_delay_ms(1000);
	}
}
void HSSD_voidTurnOFF(u8 A_U8SSD_PORT)
{
	MDIO_VoidSetPortDirection( A_U8SSD_PORT , 0X00);

}
