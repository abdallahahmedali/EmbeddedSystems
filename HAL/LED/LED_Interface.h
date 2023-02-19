/*
 * LED_Interface.h
 *
 *  Created on: Sep 3, 2022
 *      Author: abdal
 */

#ifndef LED_LED_INTERFACE_H_
#define LED_LED_INTERFACE_H_


#define LED0	0
#define LED1	1
#define LED2	2

void H_LED_Void_LedInit(u8);
void H_LED_Void_LedOn(u8);
void H_LED_Void_LedOff(u8);
void H_LED_Void_LedToggle(u8);
void H_LED_Void_LedBlink(u8);

#endif /* LED_LED_INTERFACE_H_ */
