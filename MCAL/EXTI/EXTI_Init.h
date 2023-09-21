/*
 * EXTI_Init.h
 *
 *  Created on: 20 Aug 2023
 *      Author: Youssef
 */

#ifndef MCAL_EXTI_EXTI_INIT_H_
#define MCAL_EXTI_EXTI_INIT_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO.h"

#define EXTI_Line0 	0
#define EXTI_Line1 	1
#define EXTI_Line2 	2

#define LOWLevel 	0
#define AnyChang 	1
#define FALLING 	2
#define RISING 		3

void MEXTI_VoidSenseControl(u8 A_U8EXTI_Line , u8 A_U8EXTI_Sense);
void METI_VoidEnable(u8 A_U8EXTI_Line);
void METI_VoidDisEnable(u8 A_U8EXTI_Line);


#endif /* MCAL_EXTI_EXTI_INIT_H_ */
