/*
 * TIMER_PROG.c
 *
 *  Created on: 23 Aug 2023
 *      Author: Youssef
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "Timer_Init.h"
#include "Timer_Prv.h"
#include "Timer_Confg.h"

u32 G_IntervalCounter ;
void(*TIME_OVF)(void);

void MTIMERS_voidInit()
{
	TCCR0 = 0X00;
	Set_Bit( TIMSK , TOIE0);
}

void MTIMERS_VoidSetIntervals(u32 A_U32IntervalCounters , void(*A_TIMERS_Ptr)(void))
{
	G_IntervalCounter = A_U32IntervalCounters ;
	TIME_OVF = A_TIMERS_Ptr ;
	MTIMERS_VoidStart();
}

void MTIMERS_VoidPreLoadval(u16 A_U16PreLoadVal)
{
	TCNT0 = A_U16PreLoadVal;
}

void MTIMERS_VoidStart()
{
	TCCR0 = ( TCCR0 & 0XF8) | (PRS_Clock) ;
}

void MTIMERS_VoidStop()
{
	TCCR0 = ( TCCR0 & 0XF8) | 0X00 ;
}

void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	static u32 L_U32Counter = 0 ;
	L_U32Counter ++ ;
	if( L_U32Counter == G_IntervalCounter)
	{
		TIME_OVF();
		L_U32Counter = 0 ;
	}
}
