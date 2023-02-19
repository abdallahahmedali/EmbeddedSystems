
#include "LCD_Interface.h"
#include "GIE_Interface.h"
#include <util/delay.h>
#include "STD.h"
#include "Servo_Interface.h"
#include "DCMotor_Interface.h"
#include "HC_SR04_interface.h"
#include "UART_Interface.h"
#include "Buzzer_Interface.h"
#include "WDT_Interface.h"

#define MAX_DISTANCE	30
#define TURN_SPEED		10
#define TURN_TIME		900

#define FORWARD_VISION	90
#define LEFT_VISION		180
#define RIGHT_VISION	0

u8 APP_U8_CurrentSpeed = 1;

//void Turn_Left()
//{
//	H_DCMotor_Void_DCMotorStop();
//	_delay_ms(3000); //Time for motor to stop
//	H_DCMotor_Void_DCMotorRSetDirection(CW);  // initially forward
//	H_DCMotor_Void_DCMotorLSetDirection(CCW); // initially forward
//	H_DCMotor_Void_DCMotorStart();
//	H_DCMotor_Void_DCMotorLSetSpeed(45);
//	_delay_ms(2000);  //Turning time
//	H_DCMotor_Void_DCMotorStop();
//	_delay_ms(2000);  //Time for motor to stop after turning
//	H_DCMotor_Void_DCMotorRSetDirection(CCW); // initially forward
//	H_DCMotor_Void_DCMotorLSetDirection(CCW); // initially forward
//	H_DCMotor_Void_DCMotorStart();
//	H_DCMotor_Void_DCMotorLSetSpeed(45);
//
//
//
//}
//void Turn_Right()
//{
//	H_DCMotor_Void_DCMotorStop();
//	_delay_ms(3000); //Time for motor to stop
//	H_DCMotor_Void_DCMotorRSetDirection(CCW);  // initially forward
//	H_DCMotor_Void_DCMotorLSetDirection(CW); // initially forward
//	H_DCMotor_Void_DCMotorStart();
//	H_DCMotor_Void_DCMotorLSetSpeed(45);
//	_delay_ms(2000); //Turning time
//	H_DCMotor_Void_DCMotorStop();
//	_delay_ms(2000); //Time for motor to stop after turning
//	H_DCMotor_Void_DCMotorRSetDirection(CCW); // initially forward
//	H_DCMotor_Void_DCMotorLSetDirection(CCW); // initially forward
//	H_DCMotor_Void_DCMotorStart();
//	H_DCMotor_Void_DCMotorLSetSpeed(45);
//
//
//
//}

void APP_Void_MoveForward(u8 Copy_U8_Speed)
{
	H_DCMotor_Void_DCMotorStart();
	H_DCMotor_Void_DCMotorLSetSpeed(Copy_U8_Speed);
	_delay_ms(200);
}

void APP_Void_StopVehicle(){
	H_DCMotor_Void_DCMotorLSetSpeed(1);
	_delay_ms(100);
	//H_DCMotor_Void_DCMotorStop();
}

u8 APP_Void_Scan()
{
	u32 Local_U32_UltraSonicReading = (u32) H_HC_SR04_GetDistance();
	H_LCD_Void_LCDClearScreen();
	H_LCD_Void_WriteNumber(Local_U32_UltraSonicReading);
	if(Local_U32_UltraSonicReading <= MAX_DISTANCE){
		return 1;
	}

	return 0;
}

void APP_Void_SelectVision(u8 Copy_U8_Angle){
	H_Servo_Void_ServoSetAngel(Copy_U8_Angle);
	H_Servo_Void_ServoStart();
	_delay_ms(100);
}

void APP_Void_TurnRight()
{
	H_DCMotor_Void_DCMotorRSetDirection(CW);
	H_DCMotor_Void_DCMotorLSetDirection(CCW);
	H_DCMotor_Void_DCMotorLSetSpeed(95);
	H_DCMotor_Void_DCMotorStart();
//	_delay_ms(500);
	_delay_ms(TURN_TIME);//Turning time
	//H_DCMotor_Void_DCMotorStop();

}
void APP_Void_TurnLeft()
{
	H_DCMotor_Void_DCMotorRSetDirection(CCW);
	H_DCMotor_Void_DCMotorLSetDirection(CW);
	H_DCMotor_Void_DCMotorLSetSpeed(95);
	H_DCMotor_Void_DCMotorStart();
//	_delay_ms(500);
	_delay_ms(TURN_TIME);//Turning time
}

void APP_init(void)
{
	M_GIE_Void_GlobalInterruptEnable();
	H_HC_SR04_Init();
	H_LCD_Void_LCDInit();
	H_DCMotor_Void_DCMotorLInit();
	H_DCMotor_Void_DCMotorRInit();
	H_DCMotor_Void_DCMotorRSetDirection(CW);// initially forward
	H_DCMotor_Void_DCMotorLSetDirection(CW); // initially forward
	//M_UART_Void_UARTInit();
	H_Servo_Void_ServoInit();
}
int main()
{
	APP_init();


	// Look Forward -> Default Vision
	APP_Void_SelectVision(FORWARD_VISION);

	// Start Movement
	APP_Void_MoveForward(45);
	u32 Local_U32_Read;
    while(1){
    	_delay_ms(800);
    	Local_U32_Read = (u32) H_HC_SR04_GetDistance();
    	_delay_ms(300);
    	H_LCD_Void_LCDClearScreen();
    	H_LCD_Void_WriteNumber(Local_U32_Read);

    	if(Local_U32_Read <= MAX_DISTANCE){
    		APP_Void_StopVehicle();
    		_delay_ms(300);
    		H_Servo_Void_ServoSetAngel(RIGHT_VISION);
    		_delay_ms(500);

    		u8 Local_U8_ScanCounter = 1;
    		// Avoiding Readings Issues
    		while(Local_U8_ScanCounter < 30)
    		{
    			Local_U8_ScanCounter++;
        		Local_U32_Read = (u32) H_HC_SR04_GetDistance();
        		_delay_ms(10);

    		}
    		if(Local_U32_Read > MAX_DISTANCE)
    		{
    			H_LCD_Void_LCDClearScreen();
    			H_LCD_Void_WriteString("RIGHT");
				APP_Void_TurnRight();
				APP_Void_StopVehicle();
				_delay_ms(300);
				H_DCMotor_Void_DCMotorRSetDirection(CW);
				H_DCMotor_Void_DCMotorLSetDirection(CW);
				H_Servo_Void_ServoSetAngel(FORWARD_VISION);
				APP_Void_MoveForward(45);
    		}else{
        		H_Servo_Void_ServoSetAngel(LEFT_VISION);
        		_delay_ms(500);
        		Local_U8_ScanCounter = 1;
				// Avoiding Readings Issues
				while(Local_U8_ScanCounter < 30)
				{
					Local_U8_ScanCounter++;
					Local_U32_Read = (u32) H_HC_SR04_GetDistance();
					_delay_ms(10);

				}
				if(Local_U32_Read > MAX_DISTANCE)
				{

	    			H_LCD_Void_LCDClearScreen();
	    			H_LCD_Void_WriteString("LEFT");
					APP_Void_TurnLeft();
					APP_Void_StopVehicle();
					_delay_ms(300);
					H_DCMotor_Void_DCMotorRSetDirection(CW);
					H_DCMotor_Void_DCMotorLSetDirection(CW);
					H_Servo_Void_ServoSetAngel(FORWARD_VISION);
					APP_Void_MoveForward(45);
				}else{
					APP_Void_StopVehicle();
				}
    		}
    	}
//    	if((u32) H_HC_SR04_GetDistance() <= MAX_DISTANCE){
//    		APP_Void_StopVehicle();
//    		_delay_ms(250);
//    		APP_Void_SelectVision(LEFT_VISION);
//    		_delay_ms(1000);
//    		Local_U32_Read = (u32) H_HC_SR04_GetDistance();
//    		_delay_ms(1000);
//    		if(Local_U32_Read <= MAX_DISTANCE){
//        		APP_Void_TurnLeft();
//        		APP_Void_MoveForward(35);
//    		}else{
//        		APP_Void_SelectVision(RIGHT_VISION);
//        		_delay_ms(1000);
//    			//if((u32) H_HC_SR04_GetDistance() <= MAX_DISTANCE){
//            		APP_Void_TurnRight();
//            		APP_Void_MoveForward(35);
////    			}else{
////    				break;
////    			}
//    		}
//    	}else{
//    		// Look Forward -> Default Vision
//    		APP_Void_SelectVision(FORWARD_VISION);
//    	}
//    	_delay_ms(1000);
	}

	return 0;
}
//
