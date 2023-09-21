/*
 * Timer_Prv.h
 *
 *  Created on: 23 Aug 2023
 *      Author: Youssef
 */

#ifndef MCAL_TIMERS_TIMER_PRV_H_
#define MCAL_TIMERS_TIMER_PRV_H_

#define TCCR0		*((volatile u8*)(0x53))
#define FOCO			7
#define WGM00			6
#define WGM01			3
#define COM01			5
#define COM00			4

#define TCNT0		*((volatile u8*)(0x52))

#define OCR0		*((volatile u8*)(0x5C))

#define TIMSK		*((volatile u8*)(0x59))
#define OCIE0			1
#define TOIE0			0

#define TIFR		*((volatile u8*)(0x58))
#define OCF0			1
#define TOV0			0

#define Clock_NOPRS 		0b001
#define Clock_PRS8 			0b010
#define Clock_PRS64 		0b011
#define Clock_PRS256		0b100
#define Clock_PRS1024 		0b101
#define Clock_onfalling 	0b110
#define Clock_onrising	 	0b111

#endif /* MCAL_TIMERS_TIMER_PRV_H_ */
