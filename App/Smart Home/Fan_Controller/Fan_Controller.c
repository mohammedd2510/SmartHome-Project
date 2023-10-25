/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Fan_Controller.c 
 *        \brief  This Application Controls The FanSpeed Using Two Modes   1: Auto Mode the FanSpeed is Changed Automatically with Temperature
																		   2: Manual Mode The user enter the Duty Cycle of The Fan 
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fan_Controller.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
volatile uint8 FanAuto_Flag =0; // This flag == 1 if the FanSpeed mode is Auto Mode 
volatile uint8 Temp=0; // Temp is Stored here
uint8 Auto_FanSpeed =0;  // AutoFanSpeed is Stored Here
uint8 FanSpeed_Rec=0; // Fan Speed Received from BlueTooth is stored here
uint8 Man_FanSpeed =0; // Manual Fan Speed is calculated here
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void FanAutoSpeed_Routine(void)
* \Description     : This Routine Controls FanSpeed with the measured temprature
* \Parameters	   : None
* \Return value:   : None
*******************************************************************************/
void FanAutoSpeed_Routine(void){
	Temp=DS18B20_GetTemp();
	if (Temp <=15)
	{
		FAN_SetSpeed(0);
		Auto_FanSpeed =0;
	}
	else if (Temp <= 20 && Temp >15)
	{
		FAN_SetSpeed(25);
		Auto_FanSpeed =25;
	}
	else if (Temp <= 30 && Temp >20)
	{
		FAN_SetSpeed(50);
		Auto_FanSpeed =50;
	}
	else if (Temp <= 40 && Temp >30)
	{
		FAN_SetSpeed(75);
		Auto_FanSpeed =75;
	}
	else if (Temp >40)
	{
		FAN_SetSpeed(90);
		Auto_FanSpeed =90;
	}
}
/******************************************************************************
* \Syntax          : void FanManualSpeed_Routine(void)
* \Description     : This Routine Receives The Manual Fan Speed From User then store it in Man_FanSpeed Var
* \Parameters	   : None
* \Return value:   : None
*******************************************************************************/
void FanManualSpeed_Routine(void){
	Bluetooth_Select_Variable(&FanSpeed_Rec);
	uint8 rec_cnt=0;
	for (rec_cnt=0;rec_cnt<2;rec_cnt++)
	{
		while(Bluetooth_Check_DataReceived()==0);
		if ((FanSpeed_Rec>='0')&&(FanSpeed_Rec<='9'))
		{
			Man_FanSpeed *=10;
			Man_FanSpeed +=(FanSpeed_Rec - 0x30);
			LCD_WriteChar(FanSpeed_Rec);
		}
		else if (FanSpeed_Rec == GO_BACK)
		{
			App_state = GO_BACK;
			break;
		}
		else rec_cnt--;
	}
}
/******************************************************************************
* \Syntax          : void FanController_Init(void)
* \Description     : This Routine Initializes The FanController Application
* \Parameters	   : None
* \Return value:   : None
*******************************************************************************/
void FanController_Init(void){
	FAN_Init();
}
/******************************************************************************
* \Syntax          : void FanController_Start(void)
* \Description     : This Routine starts The FanController Application
* \Parameters	   : None
* \Return value:   : None
*******************************************************************************/
void FanController_Start(void){
	 select_Fan_Mode:
	LCD_Clear();
	Bluetooth_Check_DataReceived();
	LCD_WriteString("1: Auto Speed");
	LCD_GoTo(1,0);
	LCD_WriteString("2: Manual Speed");
	Bluetooth_Select_Variable(&App_state);
	Bluetooth_Start_Receiving();
    while(App_state != GO_BACK && App_state != FAN_AUTO_SPEED && App_state!= FAN_MANUAL_SPEED);
	Bluetooth_Check_DataReceived();
	if (App_state == FAN_AUTO_SPEED)
	{
		FanAuto_Flag=0;
		LCD_Clear();
		while(App_state != GO_BACK){
			LCD_GoTo(0,0);
			FanAutoSpeed_Routine();
			LCD_WriteString("FanSpeed = ");
			LCD_WriteInteger(Auto_FanSpeed);
			LCD_WriteChar('%');
			LCD_WriteString("      ");
			LCD_GoTo(1,0);
			LCD_WriteString("Temp = ");
			LCD_WriteInteger(Temp);
			LCD_WriteChar(CELSIUS_ICON);
			LCD_WriteString("C");
			LCD_WriteString("       ");
		}
		Bluetooth_Check_DataReceived();
		FanAuto_Flag=1;
		App_state = FAN_CONTROLLER;
		goto select_Fan_Mode;
	}
	else if (App_state == FAN_MANUAL_SPEED)
	{
		FanAuto_Flag=0;
		LCD_Clear();
		LCD_WriteString(" Fan Speed: ");
		FanManualSpeed_Routine();
		if (App_state == GO_BACK)
		{
			Man_FanSpeed =0;
			App_state =FAN_CONTROLLER;
			goto select_Fan_Mode;
		}
		FAN_SetSpeed(Man_FanSpeed);
		Man_FanSpeed =0;
		Bluetooth_Select_Variable(&App_state);
		while(App_state != GO_BACK);
		App_state = FAN_CONTROLLER;
		Bluetooth_Check_DataReceived();
		goto select_Fan_Mode;
	}
	Bluetooth_Check_DataReceived();
	Bluetooth_Stop_Receiving();
	LCD_Clear();
	App_state = SELECT_APP2;
}


/**********************************************************************************************************************
 *  END OF FILE: Fan_Controller.c 
 *********************************************************************************************************************/
