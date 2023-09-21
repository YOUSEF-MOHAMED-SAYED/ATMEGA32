/*
 * UART_Init.h
 *
 *  Created on: 27 Aug 2023
 *      Author: Youssef
 */

#ifndef MCAL_UART_INIT_H_
#define MCAL_UART_INIT_H_

void MUART_VoidInit();
void MUART_VoidTransmitData(u8 A_U8Data );
u8 MUART_U8ReceiveData();
void MUART_voidSetBaudRate(u32 A_u32BaudRate);
void MUART_voidSendString (u8 *A_StrPtr);
u8* MUART_U8RecieveString(u32 A_Size);


#endif /* MCAL_UART_INIT_H_ */
