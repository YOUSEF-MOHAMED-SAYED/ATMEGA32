/*
 * GIE_Prog.c
 *
 *  Created on: 20 Aug 2023
 *      Author: Youssef
 */

#include "GIE_Init.h"

#define MGIE_SREG_REG *((volatile u8 *)0X5F)

void MGIE_VoidEnable()
{
	Set_Bit(MGIE_SREG_REG , 7);
}

void MGIE_VoidDisEnable()
{
	Clr_Bit(MGIE_SREG_REG , 7);
}
