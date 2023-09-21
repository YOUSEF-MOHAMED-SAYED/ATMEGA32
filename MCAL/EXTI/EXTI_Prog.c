/*
 * EXTI_Prog.c
 *
 *  Created on: 20 Aug 2023
 *      Author: Youssef
 */

#include "EXTI_Init.h"

#define METI_MCUCR_REG 		*((volatile u8 *)0X55)
#define METI_MCUCSR_REG 	*((volatile u8 *)0X54)
#define METI_GICR_REG 		*((volatile u8 *)0X5B)
#define METI_GIFR_REG 		*((volatile u8 *)0X5A)

void MEXTI_VoidSenseControl(u8 A_U8EXTI_Line , u8 A_U8EXTI_Sense)
{
	switch(A_U8EXTI_Line)
	{
		case EXTI_Line0 :
				switch(A_U8EXTI_Sense)
				{
				case LOWLevel :
					Clr_Bit(METI_MCUCR_REG , 0);
					Clr_Bit(METI_MCUCR_REG , 1);
					break;
				case AnyChang :
					Set_Bit(METI_MCUCR_REG , 0);
					Clr_Bit(METI_MCUCR_REG , 1);
					break;
				case FALLING :
					Clr_Bit(METI_MCUCR_REG , 0);
					Set_Bit(METI_MCUCR_REG , 1);
					break;
				case RISING :
					Set_Bit(METI_MCUCR_REG , 0);
					Set_Bit(METI_MCUCR_REG , 1);
					break;
				}
				break;
		case EXTI_Line1 :
				switch(A_U8EXTI_Sense)
				{
				case LOWLevel :
					Clr_Bit(METI_MCUCR_REG , 2);
					Clr_Bit(METI_MCUCR_REG , 3);
					break;
				case AnyChang :
					Set_Bit(METI_MCUCR_REG , 2);
					Clr_Bit(METI_MCUCR_REG , 3);
					break;
				case FALLING :
					Clr_Bit(METI_MCUCR_REG , 2);
					Set_Bit(METI_MCUCR_REG , 3);
					break;
				case RISING :
					Set_Bit(METI_MCUCR_REG , 2);
					Set_Bit(METI_MCUCR_REG , 3);
					break;
				}
				break;
		case EXTI_Line2 :
				switch(A_U8EXTI_Sense)
				{
				case FALLING :
					Clr_Bit(METI_MCUCSR_REG , 6);
					break;
				case RISING :
					Set_Bit(METI_MCUCR_REG , 6);
					break;
				}
				break;
	}
}

void METI_VoidEnable(u8 A_U8EXTI_Line)
{
	switch( A_U8EXTI_Line)
	{
		case EXTI_Line0 : Set_Bit(METI_GICR_REG , 6); break;
		case EXTI_Line1 : Set_Bit(METI_GICR_REG , 7); break;
		case EXTI_Line2 : Set_Bit(METI_GICR_REG , 5); break;
	}
}

void METI_VoidDisEnable(u8 A_U8EXTI_Line)
{
	switch( A_U8EXTI_Line)
	{
		case EXTI_Line0 : Clr_Bit(METI_GICR_REG , 6); break;
		case EXTI_Line1 : Clr_Bit(METI_GICR_REG , 7); break;
		case EXTI_Line2 : Clr_Bit(METI_GICR_REG , 5); break;
	}
}
