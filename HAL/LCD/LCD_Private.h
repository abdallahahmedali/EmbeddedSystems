/*
 * LCD_Private.h
 *
 *  Created on: Sep 10, 2022
 *      Author: abdal
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

#define LCD_8_Bit_MODE_COMMAND				0x38

#define LCD_4_Bit_MODE_COMMAND_1			0x33
#define LCD_4_Bit_MODE_COMMAND_2			0x32
#define LCD_4_Bit_MODE_COMMAND_3			0x28

#define LCD_DISPLAY_ON_COMMAND				0x0C
#define LCD_CLEAR_SCREEN_COMMAND			0x01

#define LCD_RETURN_HOME						0x02

#define _8_BIT_MODE							8
#define _4_BIT_MODE							4

#define NULL								'\0'

#define LCD_ROWOFFSET						0x40
#define LCD_ROWBASE							0x80




#endif /* HAL_LCD_LCD_PRIVATE_H_ */
