/*
 * HC_SR04_prog.c
 *
 *  Created on: Feb 6, 2023
 *      Author: abdal
 */


#include <avr/io.h>
#include <util/delay.h>
#include "DIO_Interface.h"
#include "Timer_Interface.h"
#include "HC_SR04_interface.h"
#include "STD.h"
#include "BitMask.h"
#include "GIE_Interface.h"
#include "LCD_Interface.h"


void H_HC_SR04_Init(){
	M_GIE_Void_GlobalInterruptEnable();
	M_DIO_Void_SetPinDirection(TRIGGER_PIN, OUTPUT);
	M_DIO_Void_SetPinDirection(ECHO_PIN, INPUT);

	M_Timer_Void_TimerInit();
}

//Function to generate trigger pulse on Trigger pin
void H_HC_SR04_SendTriggerPulse() {
	 //Set trigger pin high
	 M_DIO_Void_SetPinValue(TRIGGER_PIN, HIGH);
	 //Wait for 10us
	 _delay_us(10);
	 //Set trigger pin low
	 M_DIO_Void_SetPinValue(TRIGGER_PIN, LOW);
}


//Function to calculate and return the distance in cm
float H_HC_SR04_GetDistance() {

	//Variable to store the duration of echo pulse
	float duration;

	//Generate trigger pulse
	H_HC_SR04_SendTriggerPulse();

	//Wait for the rising edge of echo pulse
	//while((PIND & (1 << ECHO_PIN)) == 0);
	u32 x = 0;
	while(M_DIO_U8_GetPinValue(ECHO_PIN) == 0)
	{
		if(++x >= 1000)
			break;
	}
	x = 0;
	//Record the start time of echo pulse
	M_Timer_Void_TimerStart(TIMER0_CHANNEL);
	unsigned long startTime = M_Timer_Void_GetTime();

	//Wait for the falling edge of echo pulse
	while(M_DIO_U8_GetPinValue(ECHO_PIN) > 0)
	{
		if(++x >= 1000)
			break;
	}

	//Record the end time of echo pulse
	unsigned long endTime = M_Timer_Void_GetTime();
	M_Timer_Void_TimerStop(TIMER0_CHANNEL);

	 //Calculate duration of echo pulse
	duration = endTime - startTime;

	//Calculate distance in cm   using speed = 343m/s and divide by 2 as sound travels back and forth
	return (duration*34300)/(2*F_OSC*1000000);
	//return startTime;

}


