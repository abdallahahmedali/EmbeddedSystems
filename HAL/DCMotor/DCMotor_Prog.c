/*
 * DCMotor_Prog.c
 *
 *  Created on: Sep 28, 2022
 *      Author: abdal
 */
//motor left
#include "DCMotor_Interface.h"
#include "DIO_Interface.h"

void H_DCMotor_Void_DCMotorLInit(void)
{
	M_Timer_Void_PWMInit(TIMER1_CHANNEL);
	//M_DIO_Void_SetPinDirection(PA1_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(PC3_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(PC4_PIN,OUTPUT);
	//M_DIO_Void_SetPinDirection(PD4_PIN,OUTPUT);
	//M_DIO_Void_SetPinValue(PD4_PIN,LOW);
}
void H_DCMotor_Void_DCMotorLSetDirection(u8 Copy_U8_MotorDirection)
{
	switch(Copy_U8_MotorDirection)
	{
	case CW:
		M_DIO_Void_SetPinValue(PC3_PIN, LOW);
		M_DIO_Void_SetPinValue(PC4_PIN, HIGH);
		break;
	case CCW:
		M_DIO_Void_SetPinValue(PC3_PIN, HIGH);
		M_DIO_Void_SetPinValue(PC4_PIN, LOW);
		break;
	default:break;
	}
}
void H_DCMotor_Void_DCMotorLSetSpeed(u8 Copy_U8_MotorSpeed)
{
	M_Timer1_Void_PWM_OCR(OCR_CHANNEL_B,Copy_U8_MotorSpeed);
	//M_Timer_Void_PWMSetDutyCycle(TIMER1_CHANNEL,Copy_U8_MotorSpeed);
}
//MOTOR right
void H_DCMotor_Void_DCMotorRInit(void)
{
	M_DIO_Void_SetPinDirection(PC5_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(PC6_PIN,OUTPUT);
	//M_DIO_Void_SetPinDirection(PD5_PIN,OUTPUT);
	//M_DIO_Void_SetPinValue(PD5_PIN,LOW);
}
void H_DCMotor_Void_DCMotorRSetDirection(u8 Copy_U8_MotorDirection)
{
	switch(Copy_U8_MotorDirection)
	{
	case CW:
		M_DIO_Void_SetPinValue(PC5_PIN, LOW);
		M_DIO_Void_SetPinValue(PC6_PIN, HIGH);
		break;
	case CCW:
		M_DIO_Void_SetPinValue(PC5_PIN, HIGH);
		M_DIO_Void_SetPinValue(PC6_PIN, LOW);
		break;
	default:break;
	}
}
void H_DCMotor_Void_DCMotorRSetSpeed(u8 Copy_U8_MotorSpeed)
{
	M_Timer1_Void_PWM_OCR(OCR_CHANNEL_A,Copy_U8_MotorSpeed);
}
//start
void H_DCMotor_Void_DCMotorStart(void)
{  M_Timer_Void_TimerStart(TIMER1_CHANNEL);
	//M_DIO_Void_SetPinDirection(PA1_PIN, HIGH);
}
void H_DCMotor_Void_DCMotorStop(void)
{
	M_Timer_Void_TimerStop(TIMER1_CHANNEL);
	//M_DIO_Void_SetPinDirection(PA1_PIN, LOW);
}
