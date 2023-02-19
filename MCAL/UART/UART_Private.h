/*
 * UART_Private.h
 *
 *  Created on: Sep 30, 2022
 *      Author: abdal
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

#define UCSRA_REG			*(volatile u8*)0x2B
#define UCSRB_REG			*(volatile u8*)0x2A
#define UCSRC_REG			*(volatile u8*)0x40
#define UBRRL_REG			*(volatile u8*)0x29
#define UDR_REG				*(volatile u8*)0x2C
#define TWCR_REG			*(volatile u8*)0x36


/*UCSRA_REG Bits*/
#define RXC_BIT						7
#define TXC_BIT						6
/*UCSRB_REG Bits*/
#define RXEN_BIT					4
#define TXEN_BIT					3
#define UCSZ2_BIT					2
/*UCSRC_REG Bits*/
#define UMSEL_BIT					6
#define UPM1_BIT					5
#define UPM0_BIT					4
#define USBS_BIT					3
#define UCSZ1_BIT					2
#define UCSZ0_BIT					1
/*UBRRL_REG Bits*/
/*UDR_REG Bits*/


#define TWIE_PIN					0
#define TWEN_PIN					2

#endif /* MCAL_UART_UART_PRIVATE_H_ */
