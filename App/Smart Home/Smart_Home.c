/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Smart_Home.c 
 *        \brief  This Smart Home Project Consists of 5 Applications :  1: LockDoor_System
 *																		2: Digital Clock
 *																		3: Thermometer
 *																		4: Automatic Door
 *																		5: FanController
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Smart_Home.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
app_states_t App_state = LOCKDOOR_APP;  // This enum describes Which App is Selected
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Select_App_Routine_1(void);
void Select_App_Routine_2(void);
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void Select_App_Routine_1(void)
* \Description     : This Routine Selects the Application from the 1st menu
* \Parameters	   : None
* \Return value:   : None
*******************************************************************************/

void Select_App_Routine_1(void){
	LCD_WriteString("1:Show Clock");
	LCD_GoTo(1,0);
	LCD_WriteString("2:Show Temp   ");
	LCD_WriteChar(DOWN_ARROW_ICON);
	LCD_WriteChar(DOWN_ARROW_ICON);
	Bluetooth_Select_Variable(&App_state);
	Bluetooth_Start_Receiving();
	AutomaticDoor_ISR_START();
	while((App_state!=SHOW_TEMP) && (App_state!= DOWN_ARROW) && (App_state != SHOW_CLOCK)){
		while(Bluetooth_Check_DataReceived()==0);
	}
	Bluetooth_Stop_Receiving();
	LCD_Clear();
}
/******************************************************************************
* \Syntax          : void Select_App_Routine_2(void)
* \Description     : This Routine Selects the Application from the 2nd menu
* \Parameters	   : None
* \Return value:   : None
*******************************************************************************/
void Select_App_Routine_2(void){
	LCD_WriteString("3:Door Dist   ");
	LCD_WriteChar(UP_ARROW_ICON);
	LCD_WriteChar(UP_ARROW_ICON);
	LCD_GoTo(1,0);
	LCD_WriteString("4:Set Fan Speed");
	Bluetooth_Select_Variable(&App_state);
	Bluetooth_Start_Receiving();
	while((App_state!=FAN_CONTROLLER) && (App_state!= UP_ARROW) && (App_state != DOOR_DISTANCE)){
		while(Bluetooth_Check_DataReceived()==0);
	}
	Bluetooth_Stop_Receiving();
	LCD_Clear();
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void SmartHome_Initialize(void)
* \Description     : This Routine Initializes The SmartHome Project
* \Parameters	   : None
* \Return value:   : None
*******************************************************************************/

void SmartHome_Initialize(void){
	SmartDoor_Initialize();
	DigitalClock_Init();
	FanController_Init();
	AutomaticDoor_Initialize();
}
/******************************************************************************
* \Syntax          : void SmartHome_Start(void)
* \Description     : This Routine Starts The SmartHome Project
* \Parameters	   : None
* \Return value:   : None
*******************************************************************************/
void SmartHome_Start(void){
	if (App_state == LOCKDOOR_APP)
	{
		SmartDoor_Start();
	}
	else if (App_state == SELECT_APP1)
	{
		Select_App_Routine_1();	
	}
	else if (App_state == SELECT_APP2)
	{
		Select_App_Routine_2();
	}
	else if (App_state == SHOW_CLOCK)
	{
		DigitalClock_Start();	
	}
	else if (App_state == SHOW_TEMP)
	{
		Thermometer_Start();
	}
	else if (App_state == DOOR_DISTANCE)
	{
		AutomaticDoor_Start();
	}
	else if (App_state == FAN_CONTROLLER)
	{
		FanController_Start();
	}
}
/**********************************************************************************************************************
 *  END OF FILE: Smart_Home.c 
 *********************************************************************************************************************/

