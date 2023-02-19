/*
 * Buzzer_Prog.c
 *
 *  Created on: Sep 3, 2022
 *      Author: abdal
 */

#include "DIO_Interface.h"
#include "Buzzer_Interface.h"
#include "util/delay.h"

void H_Buzzer_Void_Init()
{
	M_DIO_Void_SetPinDirection(PA3_PIN,OUTPUT);
}

void H_Buzzer_Void_On()
{
	M_DIO_Void_SetPinValue(PA3_PIN,HIGH);
	_delay_ms(100);
}

void H_Buzzer_Void_Off()
{
	M_DIO_Void_SetPinValue(PA3_PIN,LOW);
}

void H_Buzzer_Void_Blink(u16 Copy_U16_Space)
{
	M_DIO_Void_SetPinValue(PA3_PIN, HIGH);
	_delay_ms(Copy_U16_Space);
	M_DIO_Void_SetPinValue(PA3_PIN, LOW);
	_delay_ms(Copy_U16_Space);
}
