/*
 * DCMotor_Interface.h
 *
 *  Created on: Sep 28, 2022
 *      Author: abdal
 */

#ifndef HAL_DCMOTOR_DCMOTOR_INTERFACE_H_
#define HAL_DCMOTOR_DCMOTOR_INTERFACE_H_

#include "DIO_Interface.h"
#include "BitMask.h"
#include "STD.h"
#include "Timer_Interface.h"

#define CW		0
#define CCW		1


void H_DCMotor_Void_DCMotorRInit(void);
void H_DCMotor_Void_DCMotorRSetDirection(u8);
void H_DCMotor_Void_DCMotorRSetSpeed(u8);
void H_DCMotor_Void_DCMotorRStart(void);
void H_DCMotor_Void_DCMotorStop(void);
void H_DCMotor_Void_DCMotorLInit(void);
void H_DCMotor_Void_DCMotorLSetDirection(u8);
void H_DCMotor_Void_DCMotorStart(void);
void H_DCMotor_Void_DCMotorLSetSpeed(u8);
#endif /* HAL_DCMOTOR_DCMOTOR_INTERFACE_H_ */
