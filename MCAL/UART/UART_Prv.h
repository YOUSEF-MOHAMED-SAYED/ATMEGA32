/*
 * UART_Prv.h
 *
 *  Created on: 27 Aug 2023
 *      Author: Youssef
 */

#ifndef MCAL_UART_PRV_H_
#define MCAL_UART_PRV_H_

#define UDR			 *(volatile u8*)(0X2C)
#define UCSRA		 *(volatile u8*)(0X2B)
#define UCSRB		 *(volatile u8*)(0X2A)
#define UBRRL		 *(volatile u8*)(0X29)
#define UBRRH		 *(volatile u8*)(0X40)
#define UCSRC		 *(volatile u8*)(0X40)

// UCSRA BITS
#define RXC			7
#define TXC			6
#define UDRE		5
#define FE			4
#define DOR			3
#define PE			2
#define U2X			1
#define MPCN		0


// UCSRB BITS
#define RXCIE		7
#define TXCIE		6
#define UDRIE		5
#define RXEN		4
#define TXEN		3
#define UCSZ2		2
#define RXB8		1
#define TXB8		0

// UCSRC BITS
#define URSEL		7
#define UMSEL		6
#define UPM1		5
#define UPM0		4
#define USBS		3
#define UCSZ1		2
#define UCSZ0		1
#define UCPOL		0

#endif /* MCAL_UART_PRV_H_ */
