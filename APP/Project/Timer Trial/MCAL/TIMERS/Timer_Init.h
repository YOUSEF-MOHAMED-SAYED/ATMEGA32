/*
 * Timer_Init.h
 *
 *  Created on: 23 Aug 2023
 *      Author: Youssef
 */

#ifndef MCAL_TIMERS_TIMER_INIT_H_
#define MCAL_TIMERS_TIMER_INIT_H_

void MTIMERS_voidInit();
void MTIMERS_VoidStart();
void MTIMERS_VoidStop();
void MTIMERS_VoidSetIntervals(u32 A_U32IntervalCounters , void(*A_TIMERS_Ptr)(void));
void MTIMERS_VoidPreLoadval(u16 A_U16PreLoadVal);

#endif /* MCAL_TIMERS_TIMER_INIT_H_ */
