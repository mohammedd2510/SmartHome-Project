/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Digital_Clock.c 
 *        \brief  This Application is Simply a Digital Clock Used To Show Time,Day and Date
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Digital_Clock.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static uint8 sec,hours,min,day; 
static uint8 year;
static char* midday;
static char* day_name;
static char* month_name;		
		
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

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
* \Syntax          : void DigitalClock_Init(void)
* \Description     : This Routine Initializes The DigitalClock Application
* \Parameters	   : None
* \Return value:   : None
*******************************************************************************/
void DigitalClock_Init(void){
	RTC_Init();
}

/******************************************************************************
* \Syntax          : void DigitalClock_Start(void)
* \Description     : This Routine Starts The DigitalClock Application
* \Parameters      : None
* \Return value:   : None
*******************************************************************************/
void DigitalClock_Start(void){
	while(App_state != GO_BACK){	
	RTC_GetTime(&sec,&min,&hours,&midday);
	RTC_GetDate(&day_name,&day,&month_name,&year);
	LCD_GoTo(0,0);
	LCD_WriteInteger(hours);
	LCD_WriteString(" : ");
	RTC_LCD_Write_Clock(min);
	LCD_WriteString(" : ");
	RTC_LCD_Write_Clock(sec);
	LCD_WriteString("  ");
	LCD_WriteString(midday);
	LCD_WriteString(" ");
	LCD_GoTo(1,0);
	LCD_WriteString(day_name);
	LCD_WriteString(",");
	RTC_LCD_Write_Clock(day);
	LCD_WriteString(" ");
	LCD_WriteString(month_name);
	LCD_WriteString(" ");
	RTC_LCD_Write_Clock(year);
	Bluetooth_Select_Variable(&App_state);
	Bluetooth_Start_Receiving();
	if (App_state == GO_BACK)
	{
		Bluetooth_Check_DataReceived();
		Bluetooth_Stop_Receiving();
	}
	}
	App_state = SELECT_APP1;
	LCD_Clear();
}

/**********************************************************************************************************************
 *  END OF FILE: Digital_Clock.c 
 *********************************************************************************************************************/

