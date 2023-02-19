/*
 * UART_Interface.h
 *
 *  Created on: Sep 30, 2022
 *      Author: abdal
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

#include "UART_Config.h"
#include "STD.h"
#include "BitMask.h"
#include "LED_Interface.h"

void M_UART_Void_UARTInit(void);
void M_UART_Void_UARTSend(u8);
u8 M_UART_Void_UARTRec(void);


#endif /* MCAL_UART_UART_INTERFACE_H_ */
