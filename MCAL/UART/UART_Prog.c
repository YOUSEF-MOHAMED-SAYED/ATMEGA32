/*
 * UART_Prog.c
 *
 *  Created on: 27 Aug 2023
 *      Author: Youssef
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "UART_Init.h"
#include "UART_Prv.h"
#include "UART_Config.h"

void MUART_VoidInit()
{
	/* Set baud rate  to 9600*/
	UBRRL = 51;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format:
	 *  8 data
	 *  1 stop bit
	 *  0 polarity
	 */
	UCSRC = (1<<URSEL)|(0<<USBS)|(3<<UCSZ0);
}

void MUART_VoidTransmitData(u8 A_U8Data )
{
	/* Wait for empty transmit buffer */
	while (Get_Bit( UCSRA , UDRE) == 0){}

	/* Put data into buffer, sends the data */
	UDR = A_U8Data;
}

u8 MUART_U8ReceiveData()
{
	/* Wait for data to be received */
	while (Get_Bit(UCSRA,RXC ) == 0){}

	/* Get and return received data from buffer */
	return UDR;
}

void MUART_voidSetBaudRate(u32 A_u32BaudRate)
{
	UBRRL=A_u32BaudRate;
}

void MUART_voidSendString (u8 *A_StrPtr)
{
	while (*A_StrPtr != '\0')
		{
			MUART_voidTransmitData(*A_StrPtr);
			A_StrPtr++;
		}
}

u8* MUART_U8RecieveString(u32 A_Size)
{
	u8 String_Recived[A_Size];
	for(u32 i = 0 ; i < A_Size ; i++)
	{
		String_Recived[i]= MUART_U8ReceiveData();
		if(String_Recived[i] == '\n' || String_Recived[i] == '\r')
		{
			String_Recived[i] = '\0';
			break;
		}
	}
	return String_Recived;
}
