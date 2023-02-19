/*
 * DIO_Prog.c
 *
 *  Created on: Sep 2, 2022
 *      Author: abdal
 */


#include "DIO_Interface.h"
#include "DIO_Private.h"



u8* M_DIO_U8_FetchDDR(u8 Copy_U8_Group)
{
	u8* ret;
	switch(Copy_U8_Group)
	{
		case GroupA:
			ret = &DDRA_REG;
			break;
		case GroupB:
			ret = &DDRB_REG;
			break;
		case GroupC:
			ret = &DDRC_REG;
			break;
		case GroupD:
			ret = &DDRD_REG;
			break;
	}

	return ret;
}
u8* M_DIO_U8_FetchPORT(u8 Copy_U8_Group)
{
	u8* ret;
	switch(Copy_U8_Group)
	{
		case GroupA:
			ret = &PORTA_REG;
			break;
		case GroupB:
			ret = &PORTB_REG;
			break;
		case GroupC:
			ret = &PORTC_REG;
			break;
		case GroupD:
			ret = &PORTD_REG;
			break;

	}
	return ret;
}

u8* M_DIO_U8_FetchPIN(u8 Copy_U8_Group)
{
	u8* ret;
	switch(Copy_U8_Group)
	{
		case GroupA:
			ret = &PINA_REG;
			break;
		case GroupB:
			ret = &PINB_REG;
			break;
		case GroupC:
			ret = &PINC_REG;
			break;
		case GroupD:
			ret = &PIND_REG;
			break;

	}
	return ret;
}

void M_DIO_Void_SetPinDirection(u8 Copy_u8_Number, u8 Copy_U8_State){
	u8 Local_U8_Units = Copy_u8_Number % 10;
	u8 Local_U8_Tens  = Copy_u8_Number / 10;
	u8* DDR = M_DIO_U8_FetchDDR(Local_U8_Tens);
	switch(Copy_U8_State)
	{
		case HIGH:
			SET_BIT(*DDR, Local_U8_Units);
			break;
		case LOW:
			CLR_BIT(*DDR, Local_U8_Units);
			break;
	}
}
void M_DIO_Void_SetPinValue(u8 Copy_u8_Number, u8 Copy_U8_State){
	u8 Local_U8_Units = Copy_u8_Number % 10;
	u8 Local_U8_Tens  = Copy_u8_Number / 10;
	u8* PORT = M_DIO_U8_FetchPORT(Local_U8_Tens);
	switch(Copy_U8_State)
	{
	case HIGH:
		SET_BIT(*PORT, Local_U8_Units);
		break;
	case LOW:
		CLR_BIT(*PORT, Local_U8_Units);
		break;
	}

}

void M_DIO_Void_SetRegValue(u8 Copy_u8_Group, u8 Copy_U8_Value){
	u8* PORT = M_DIO_U8_FetchPORT(Copy_u8_Group);
	*PORT = Copy_U8_Value;
}

u8 M_DIO_U8_GetPinValue(u8 Copy_u8_Number){
	u8 Local_U8_Units = Copy_u8_Number % 10;
	u8 Local_U8_Tens  = Copy_u8_Number / 10;
	u8* PIN = M_DIO_U8_FetchPIN(Local_U8_Tens);
	return GET_BIT(*PIN,Local_U8_Units);
}



void M_DIO_Void_TogglePinValue(u8 Copy_U8_Num){

	u8 Local_U8_Pin  = Copy_U8_Num % 10;
	u8 Local_U8_Port = Copy_U8_Num / 10;

	switch(Local_U8_Port)
	{
	case 1: TOG_BIT(PORTA_REG,Local_U8_Pin); break;
	case 2: TOG_BIT(PORTB_REG,Local_U8_Pin); break;
	case 3: TOG_BIT(PORTC_REG,Local_U8_Pin); break;
	case 4: TOG_BIT(PORTD_REG,Local_U8_Pin); break;
	}
}
void M_DIO_Void_SetPinPullUpRes(u8 Copy_U8_Number ,u8 Copy_U8_State){
	u8 Local_U8_Units = Copy_U8_Number % 10;
	u8 Local_U8_Tens  = Copy_U8_Number / 10;
	u8* PORT = M_DIO_U8_FetchPORT(Local_U8_Tens);
	switch(Copy_U8_State)
	{
	case ENABLE:
		SET_BIT(*PORT, Local_U8_Units);
		break;
	case DISABLE:
		CLR_BIT(*PORT, Local_U8_Units);
		break;
	}
}
