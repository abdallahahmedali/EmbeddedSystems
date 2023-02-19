/*
 * UART_Prog.c
 *
 *  Created on: Sep 30, 2022
 *      Author: abdal
 */

#include "UART_Interface.h"
#include "UART_Private.h"

void M_UART_Void_UARTInit(void)
{
	/* Force setting the first bit in UCSRC */
	u8 Local_U8_UCSRC = 0b10000000;
	/* TO SELECT BOUDRATE 9600 */
	UBRRL_REG = 103;

	/* TO DISABLE PARITY BIT */
	CLR_BIT(Local_U8_UCSRC, UPM0_BIT);
	CLR_BIT(Local_U8_UCSRC, UPM1_BIT);

	/* TO SELECT 1 BIT STOP */
	CLR_BIT(Local_U8_UCSRC, USBS_BIT);

	/* TO SELECT ASYNCH MODE */
	CLR_BIT(Local_U8_UCSRC, UMSEL_BIT);

	/* TO SELECT CHARACTER SIZE -> 8-BIT*/
	CLR_BIT(UCSRB_REG, UCSZ2_BIT);
	SET_BIT(Local_U8_UCSRC, UCSZ1_BIT);
	SET_BIT(Local_U8_UCSRC, UCSZ0_BIT);

	/* SETTING UCSRC */
	UCSRC_REG = Local_U8_UCSRC;

	/* TO ENABLE THE TX - RX CIRCUITS */
	SET_BIT(UCSRB_REG, RXEN_BIT); // RX
	SET_BIT(UCSRB_REG, TXEN_BIT); // TX


	SET_BIT(TWCR_REG, TWIE_PIN); // Int Enable

	SET_BIT(TWCR_REG, TWEN_PIN); // Int Enable

}
void M_UART_Void_UARTSend(u8 Copy_U8_Data){
	UDR_REG = Copy_U8_Data;
	while(GET_BIT(UCSRA_REG, TXC_BIT) == 0);
}
u8 M_UART_Void_UARTRec(void){
	while(GET_BIT(UCSRA_REG, RXC_BIT) == 0);
	return UDR_REG;
}


