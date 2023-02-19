/*
 * LCD_Interface.h
 *
 *  Created on: Sep 10, 2022
 *      Author: abdal
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#include "DIO_Interface.h"
#include "LCD_Config.h"

#define ROW_0		0
#define ROW_1		1

#define COL_0		0
#define COL_1		1
#define COL_2		2
#define COL_3		3
#define COL_4		4
#define COL_5		5
#define COL_6		6
#define COL_7		7
#define COL_8		8
#define COL_9		9
#define COL_A		0xA
#define COL_B		0xB
#define COL_C		0xC
#define COL_D		0xD
#define COL_E		0xE
#define COL_F		0xF

void H_LCD_Void_LCDInit(void);
void H_LCD_Void_LCDReadMode(void);
void H_LCD_Void_LCDWriteCharacter(u8);
void H_LCD_Void_LCDWriteCommand(u8);
void H_LCD_Void_LCDClearScreen(void);
void H_LCD_Void_WriteString(u8*);
void H_LCD_Void_WriteNumber(d32);
void H_LCD_Void_LCDGoTo(u8,u8);



#endif /* HAL_LCD_LCD_INTERFACE_H_ */
