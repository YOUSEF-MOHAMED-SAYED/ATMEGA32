/*
 *  Created on: 13 Aug 2023
 *      Author: Youssef
 */

#ifndef HAL_7_SEGMENT_INIT_H_
#define HAL_7_SEGMENT_INIT_H_

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO.h"

#define CATHODE 1
#define ANODE   2

#define SSD_Type CATHODE

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
 *    9     |  0  | 1 | 0 | 1 | 1 | 1 | 1 | 1 *
 */

#define Zero   0
#define One    1
#define Two    2
#define Three  3
#define Four   4
#define Five   5
#define Six    6
#define Seven  7
#define Eeight 8
#define Nine   9

void HSSD_voidInit(u8 A_U8SSD_PORT );
void HSSD_voidDisplayNum(u8 A_U8SSD_PORT , u8 A_U8Num);
void HSSD_voidCountUP(u8 A_U8SSD_PORT , u8 A_U8Num);
void HSSD_voidCountDOWN(u8 A_U8SSD_PORT , u8 A_U8Num);
void HSSD_voidTurnOFF(u8 A_U8SSD_PORT);


#endif /* HAL_7_SEGMENT_INIT_H_ */
