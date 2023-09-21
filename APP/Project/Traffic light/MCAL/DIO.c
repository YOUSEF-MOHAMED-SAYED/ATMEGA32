/*
 *  Created on: 11 Aug 2023
 *      Author: Youssef
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "DIO.h"

#define DIO_PORTA_REG		*((volatile u8 *) 0X3B)
#define DIO_DDRA_REG		*((volatile u8 *) 0X3A)
#define DIO_PINA_REG		*((volatile u8 *) 0X39)

#define DIO_PORTB_REG		*((volatile u8 *) 0X38)
#define DIO_DDRB_REG		*((volatile u8 *) 0X37)
#define DIO_PINB_REG		*((volatile u8 *) 0X36)

#define DIO_PORTC_REG		*((volatile u8 *) 0X35)
#define DIO_DDRC_REG		*((volatile u8 *) 0X34)
#define DIO_PINC_REG		*((volatile u8 *) 0X33)

#define DIO_PORTD_REG		*((volatile u8 *) 0X32)
#define DIO_DDRD_REG		*((volatile u8 *) 0X31)
#define DIO_PIND_REG		*((volatile u8 *) 0X30)

/* SET DDR Bits */
void MDIO_VoidSetPortDirection(u8 A_U8PortNAME , u8 A_U8Value)
{
	if ( (A_U8PortNAME<=PORTD) && (A_U8Value <= 0XFF))
	{
		switch( A_U8PortNAME )
		{
			case PORTA:
					Set_Byte( DIO_DDRA_REG , A_U8Value ); break;
			case PORTB:
					Set_Byte( DIO_DDRB_REG , A_U8Value ); break;
			case PORTC:
					Set_Byte( DIO_DDRC_REG , A_U8Value ); break;
			case PORTD:
					Set_Byte( DIO_DDRD_REG , A_U8Value ); break;
		}
	}
}
/* set DDR Bit by Bit */
void MDIO_VoidSetPINDirecion(u8 A_U8PortName , u8 A_U8PinNO , u8 A_U8PinDirection)
{
	if ( (A_U8PortName<=PORTD) && (A_U8PinNO<=PIN7) && (A_U8PinDirection <=OUTPUT))
	{
		switch( A_U8PortName )
		{
			case PORTA:
					switch(A_U8PinDirection)
					{
						case OUTPUT: Set_Bit( DIO_DDRA_REG , A_U8PinNO ); break;
						case INPUT : Clr_Bit( DIO_DDRA_REG , A_U8PinNO ); break;
					}
					break;
			case PORTB:
					switch(A_U8PinDirection)
					{
						case OUTPUT : Set_Bit( DIO_DDRB_REG , A_U8PinNO ); break;
						case INPUT  : Clr_Bit( DIO_DDRB_REG , A_U8PinNO ); break;
					}
					break;
			case PORTC:
					switch(A_U8PinDirection)
					{
						case OUTPUT : Set_Bit( DIO_DDRC_REG , A_U8PinNO ); break;
						case INPUT  : Clr_Bit( DIO_DDRC_REG , A_U8PinNO ); break;
					}
					break;
			case PORTD:
					switch(A_U8PinDirection)
					{
						case OUTPUT : Set_Bit( DIO_DDRD_REG , A_U8PinNO ); break;
						case INPUT  : Clr_Bit( DIO_DDRD_REG , A_U8PinNO ); break;
					}
					break;
		}
	}
}
/* SET PORT Bits */
void MDIO_VoidSetPortValue(u8 A_U8PortNAME , u8 A_U8Value)
{
	switch( A_U8PortNAME )
	{
		case PORTA:
				Set_Byte( DIO_PORTA_REG , A_U8Value ); break;
		case PORTB:
				Set_Byte( DIO_PORTB_REG , A_U8Value ); break;
		case PORTC:
				Set_Byte( DIO_PORTC_REG , A_U8Value ); break;
		case PORTD:
				Set_Byte( DIO_PORTD_REG , A_U8Value ); break;
	}
}

void MDIO_VoidSETPortBit(u8 A_U8PortName , u8 A_U8PinNO , u8 A_U8PinValue)
{
	switch( A_U8PortName )
	{
		case PORTA:
				switch(A_U8PinValue)
				{
					case HIGH : Set_Bit( DIO_PORTA_REG , A_U8PinNO ); break;
					case LOW :  Clr_Bit( DIO_PORTA_REG , A_U8PinNO ); break;
				}
				break;
		case PORTB:
				switch(A_U8PinValue)
				{
					case HIGH : Set_Bit( DIO_PORTB_REG , A_U8PinNO ); break;
					case LOW :  Clr_Bit( DIO_PORTB_REG , A_U8PinNO ); break;
				}
				break;
		case PORTC:
				switch(A_U8PinValue)
				{
					case HIGH : Set_Bit( DIO_PORTC_REG , A_U8PinNO ); break;
					case LOW  : Clr_Bit( DIO_PORTC_REG , A_U8PinNO ); break;
				}
				break;
		case PORTD:
				switch(A_U8PinValue)
				{
					case HIGH : Set_Bit( DIO_PORTD_REG , A_U8PinNO ); break;
					case LOW :  Clr_Bit( DIO_PORTD_REG , A_U8PinNO ); break;
				}
				break;
	}
}
/*set PIN */
void MDIO_VoidSETPinValue(u8 A_U8PinName , u8 A_U8PinNO , u8 A_U8PinValue)
{
	switch( A_U8PinName )
	{
		case PORTA:
				switch(A_U8PinValue)
				{
					case HIGH : Set_Bit( DIO_PINA_REG , A_U8PinNO ); break;
					case LOW :  Clr_Bit( DIO_PINA_REG , A_U8PinNO ); break;
				}
				break;
		case PORTB:
				switch(A_U8PinValue)
				{
					case HIGH : Set_Bit( DIO_PINB_REG , A_U8PinNO ); break;
					case LOW :  Clr_Bit( DIO_PINB_REG , A_U8PinNO ); break;
				}
				break;
		case PORTC:
				switch(A_U8PinValue)
				{
					case HIGH : Set_Bit( DIO_PINC_REG , A_U8PinNO ); break;
					case LOW  :  Clr_Bit( DIO_PINC_REG , A_U8PinNO ); break;
				}
				break;
		case PORTD:
				switch(A_U8PinValue)
				{
					case HIGH : Set_Bit( DIO_PIND_REG , A_U8PinNO ); break;
					case LOW :  Clr_Bit( DIO_PIND_REG , A_U8PinNO ); break;
				}
				break;
	}
}

/* GET Direction of BIT */
u8 MDIO_U8GetPinValue(u8 A_U8PortNAME , u8 A_PinNO)
{
	u8 PINValue;
	switch( A_U8PortNAME )
	{
		case PORTA:
				PINValue = Get_Bit( DIO_PINA_REG , A_PinNO ) ; break;
		case PORTB:
				PINValue = Get_Bit( DIO_PINB_REG , A_PinNO ) ; break;
		case PORTC:
				PINValue = Get_Bit( DIO_PINC_REG , A_PinNO ) ; break;
		case PORTD:
				PINValue = Get_Bit( DIO_PIND_REG , A_PinNO ) ; break;

	}
	return PINValue;
}


