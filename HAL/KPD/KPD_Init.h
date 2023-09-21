/*
 * KPD_Init.h
 *
 *  Created on: 14 Aug 2023
 *      Author: Youssef
 */

#ifndef HAL_KPD_KPD_INIT_H_
#define HAL_KPD_KPD_INIT_H_

#include "../../LIB/STD_TYPES.h"

#define KPD_ROWS    4
#define KPD_COLUMNS 4
#define KPD_PORT PORTC

void HKPD_VoidInit();
u8 HKPD_U8GetPressedKey();


#endif /* HAL_KPD_KPD_INIT_H_ */
