/*
 * LED_prog.c
 *
 *  Created on: Sep 3, 2022
 *      Author: abdal
 */

#include "DIO_Interface.h"
#include "LED_Interface.h"
#include "LED_Config.h"
#include <util/delay.h>


void H_LED_Void_LedInit(u8 Copy_U8_LED)
{
	switch(Copy_U8_LED)
	{
		case LED0:
			M_DIO_Void_SetPinDirection(LED0_PIN,OUTPUT);
			break;
		case LED1:
			M_DIO_Void_SetPinDirection(LED1_PIN,OUTPUT);
			break;
		case LED2:
			M_DIO_Void_SetPinDirection(LED2_PIN,OUTPUT);
			break;
		default:	 break;
	}
}

void H_LED_Void_LedOn(u8 Copy_U8_LED)
{
	switch(Copy_U8_LED)
	{
		case LED0:
			M_DIO_Void_SetPinValue(LED0_PIN, HIGH);
			break;
		case LED1:
			M_DIO_Void_SetPinValue(LED1_PIN, HIGH);
			break;
		case LED2:
			M_DIO_Void_SetPinValue(LED2_PIN, HIGH);
			break;
		default:	 break;

	}
}

void H_LED_Void_LedOff(u8 Copy_U8_LED)
{
	switch(Copy_U8_LED)
	{
		case LED0:
			M_DIO_Void_SetPinValue(LED0_PIN, LOW);
			break;
		case LED1:
			M_DIO_Void_SetPinValue(LED1_PIN, LOW);
			break;
		case LED2:
			M_DIO_Void_SetPinValue(LED2_PIN, LOW);
			break;
		default:	 break;
	}
}


void H_LED_Void_LedToggle(u8 Copy_U8_LED){
	switch(Copy_U8_LED)
	{
	case LED0:
		M_DIO_Void_TogglePinValue(LED0_PIN);
		break;
	case LED1:
		M_DIO_Void_TogglePinValue(LED1_PIN);
		break;
	case LED2:
		M_DIO_Void_TogglePinValue(LED2_PIN);
		break;
	default:	break;
	}
}
void H_LED_Void_LedBlink(u8 Copy_U8_LED){
	M_DIO_Void_SetPinValue(LED0_PIN, HIGH);
	_delay_ms(250);
	M_DIO_Void_SetPinValue(LED0_PIN, LOW);

}
