/*
 * LCD_prog.c
 *
 *  Created on: Sep 10, 2022
 *      Author: abdal
 */

#include "LCD_Interface.h"
#include "LCD_Private.h"


void H_LCD_Void_LCDInit(void){
#if LCD_MODE == _8_BIT_MODE

	M_DIO_Void_SetPinDirection(LCD_D0_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D1_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D2_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D3_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D4_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D5_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D6_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D7_PIN,OUTPUT);

	M_DIO_Void_SetPinDirection(LCD_RW_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_RS_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_E_PIN,OUTPUT);

	H_LCD_Void_LCDWriteCommand(LCD_8_Bit_MODE_COMMAND); // 8-bit mode
	H_LCD_Void_LCDWriteCommand(LCD_DISPLAY_ON_COMMAND);	// Enable Screen
#elif LCD_MODE == _4_BIT_MODE

	M_DIO_Void_SetPinDirection(LCD_D4_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D5_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D6_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D7_PIN,OUTPUT);

	M_DIO_Void_SetPinDirection(LCD_RW_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_RS_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_E_PIN,OUTPUT);


	H_LCD_Void_LCDWriteCommand(LCD_4_Bit_MODE_COMMAND_1); // 8-bit mode1
	H_LCD_Void_LCDWriteCommand(LCD_4_Bit_MODE_COMMAND_2); // 8-bit mode2
	H_LCD_Void_LCDWriteCommand(LCD_4_Bit_MODE_COMMAND_3); // 8-bit mode3
	H_LCD_Void_LCDWriteCommand(LCD_DISPLAY_ON_COMMAND);	// Enable Screen
	H_LCD_Void_LCDWriteCommand(LCD_RETURN_HOME);	// start from first digit in LCD
	H_LCD_Void_LCDWriteCommand(LCD_CLEAR_SCREEN_COMMAND);	// Clear Screen
#endif
}

void H_LCD_Void_LCDReadMode(void){
	M_DIO_Void_SetPinValue(LCD_RW_PIN,LOW);
}
void H_LCD_Void_LCDWriteCharacter(u8 Copy_U8_Char){
	M_DIO_Void_SetPinValue(LCD_RS_PIN,HIGH);
#if LCD_MODE == _8_BIT_MODE

	M_DIO_Void_SetPinValue(LCD_D0_PIN,GET_BIT(Copy_U8_Char,0));
	M_DIO_Void_SetPinValue(LCD_D1_PIN,GET_BIT(Copy_U8_Char,1));
	M_DIO_Void_SetPinValue(LCD_D2_PIN,GET_BIT(Copy_U8_Char,2));
	M_DIO_Void_SetPinValue(LCD_D3_PIN,GET_BIT(Copy_U8_Char,3));
	M_DIO_Void_SetPinValue(LCD_D4_PIN,GET_BIT(Copy_U8_Char,4));
	M_DIO_Void_SetPinValue(LCD_D5_PIN,GET_BIT(Copy_U8_Char,5));
	M_DIO_Void_SetPinValue(LCD_D6_PIN,GET_BIT(Copy_U8_Char,6));
	M_DIO_Void_SetPinValue(LCD_D7_PIN,GET_BIT(Copy_U8_Char,7));

	M_DIO_Void_SetPinValue(LCD_E_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_E_PIN,LOW);
#elif LCD_MODE == _4_BIT_MODE

	M_DIO_Void_SetPinValue(LCD_D4_PIN,GET_BIT(Copy_U8_Char,4));
	M_DIO_Void_SetPinValue(LCD_D5_PIN,GET_BIT(Copy_U8_Char,5));
	M_DIO_Void_SetPinValue(LCD_D6_PIN,GET_BIT(Copy_U8_Char,6));
	M_DIO_Void_SetPinValue(LCD_D7_PIN,GET_BIT(Copy_U8_Char,7));

	M_DIO_Void_SetPinValue(LCD_E_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_E_PIN,LOW);

	M_DIO_Void_SetPinValue(LCD_D4_PIN,GET_BIT(Copy_U8_Char,0));
	M_DIO_Void_SetPinValue(LCD_D5_PIN,GET_BIT(Copy_U8_Char,1));
	M_DIO_Void_SetPinValue(LCD_D6_PIN,GET_BIT(Copy_U8_Char,2));
	M_DIO_Void_SetPinValue(LCD_D7_PIN,GET_BIT(Copy_U8_Char,3));

	M_DIO_Void_SetPinValue(LCD_E_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_E_PIN,LOW);

#endif
	_delay_ms(3);
}
void H_LCD_Void_LCDWriteCommand(u8 Copy_U8_Command){
	M_DIO_Void_SetPinValue(LCD_RS_PIN,LOW);
#if LCD_MODE == _8_BIT_MODE
	M_DIO_Void_SetPinValue(LCD_D0_PIN,GET_BIT(Copy_U8_Command,0));
	M_DIO_Void_SetPinValue(LCD_D1_PIN,GET_BIT(Copy_U8_Command,1));
	M_DIO_Void_SetPinValue(LCD_D2_PIN,GET_BIT(Copy_U8_Command,2));
	M_DIO_Void_SetPinValue(LCD_D3_PIN,GET_BIT(Copy_U8_Command,3));
	M_DIO_Void_SetPinValue(LCD_D4_PIN,GET_BIT(Copy_U8_Command,4));
	M_DIO_Void_SetPinValue(LCD_D5_PIN,GET_BIT(Copy_U8_Command,5));
	M_DIO_Void_SetPinValue(LCD_D6_PIN,GET_BIT(Copy_U8_Command,6));
	M_DIO_Void_SetPinValue(LCD_D7_PIN,GET_BIT(Copy_U8_Command,7));

	M_DIO_Void_SetPinValue(LCD_E_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_E_PIN,LOW);
#elif LCD_MODE == _4_BIT_MODE

	M_DIO_Void_SetPinValue(LCD_D4_PIN,GET_BIT(Copy_U8_Command,4));
	M_DIO_Void_SetPinValue(LCD_D5_PIN,GET_BIT(Copy_U8_Command,5));
	M_DIO_Void_SetPinValue(LCD_D6_PIN,GET_BIT(Copy_U8_Command,6));
	M_DIO_Void_SetPinValue(LCD_D7_PIN,GET_BIT(Copy_U8_Command,7));

	M_DIO_Void_SetPinValue(LCD_E_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_E_PIN,LOW);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_D4_PIN,GET_BIT(Copy_U8_Command,0));
	M_DIO_Void_SetPinValue(LCD_D5_PIN,GET_BIT(Copy_U8_Command,1));
	M_DIO_Void_SetPinValue(LCD_D6_PIN,GET_BIT(Copy_U8_Command,2));
	M_DIO_Void_SetPinValue(LCD_D7_PIN,GET_BIT(Copy_U8_Command,3));

	M_DIO_Void_SetPinValue(LCD_E_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_E_PIN,LOW);

#endif

	_delay_ms(3);
}

void H_LCD_Void_WriteString(u8* Copy_U8_StrArray)
{
	int Local_U8_CharIndex = 0;
	while(Copy_U8_StrArray[Local_U8_CharIndex] != NULL){
		H_LCD_Void_LCDWriteCharacter(Copy_U8_StrArray[Local_U8_CharIndex]);
		Local_U8_CharIndex++;
	}
}

void H_LCD_Void_LCDClearScreen(void)
{
	H_LCD_Void_LCDWriteCommand(LCD_CLEAR_SCREEN_COMMAND);
	H_LCD_Void_LCDWriteCommand(LCD_RETURN_HOME);	// start from first digit in LCD
}

void H_LCD_Void_WriteNumber(d32 Copy_D32_Number)
{
	u8 Local_U8_NumberArray[10] = {0};
	u8 Local_U8_Counter = 0;
	u8 Local_U8_DecCounter = 0;
	s32 Local_S32_IntNum = Copy_D32_Number;

	while(Local_S32_IntNum != Copy_D32_Number)
	{

		Copy_D32_Number *= 10;
		Local_S32_IntNum = Copy_D32_Number;
		Local_U8_DecCounter++;
	}


	if(Copy_D32_Number < 0){
		H_LCD_Void_LCDWriteCharacter('-');
		Copy_D32_Number *= -1;
	}

	Local_S32_IntNum = Copy_D32_Number;
	do
	{
		Local_U8_NumberArray[Local_U8_Counter++] = (Local_S32_IntNum%10);
		Local_S32_IntNum = Local_S32_IntNum / 10;
	}
	while(Local_S32_IntNum);

	while(Local_U8_Counter)
	{
		H_LCD_Void_LCDWriteCharacter(Local_U8_NumberArray[--Local_U8_Counter] + 48);
		if(Local_U8_DecCounter == Local_U8_Counter && Local_U8_Counter)
			H_LCD_Void_LCDWriteCharacter('.');
	}
}



void H_LCD_Void_LCDGoTo(u8 Copy_U8_RowNum,u8 Copy_U8_ColNum){
	H_LCD_Void_LCDWriteCommand(LCD_ROWBASE + LCD_ROWOFFSET*Copy_U8_RowNum + Copy_U8_ColNum);
}
