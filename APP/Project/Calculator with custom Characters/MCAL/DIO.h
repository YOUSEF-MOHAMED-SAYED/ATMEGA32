/*
 *  Created on: 11 Aug 2023
 *      Author: Youssef
 */

#ifndef DIO_H_
#define DIO_H_

/////////////////////////
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
/* FUCTIONS PROTOTYPING */
void MDIO_VoidSetPortDirection(u8 A_U8PortNAME , u8 A_U8Value);
void MDIO_VoidSetPINDirecion(u8 A_U8PortName , u8 A_U8PinNO , u8 A_U8PinDirection);
void MDIO_VoidSetPortValue(u8 A_U8PortNAME , u8 A_U8Value);
void MDIO_VoidSETPortBit(u8 A_U8PortName , u8 A_U8PinNO , u8 A_U8PinValue);
void MDIO_VoidSETPinValue(u8 A_U8PinName , u8 A_U8PinNO , u8 A_U8PinValue);
u8 MDIO_U8GetPinValue(u8 A_U8PortNAME , u8 A_PinNO);

/* PORT define */
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

/* PINS define */
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

/* Status define */
#define INPUT 0
#define OUTPUT 1

#define LOW  0
#define HIGH 1

/* FUNCTION DEFINE */




#endif /* DIO_H_ */
