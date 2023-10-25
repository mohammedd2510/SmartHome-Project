/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Automatic_Door.c 
 *        \brief  Automatic Door That opens if you are near it then closes when you are far
				  uses UltraSonic And Servo Motor 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Automatic_Door.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
volatile uint32 Dist =0; // The Distance Measured from UltraSonic

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
* \Syntax          : void AutomaticDoor_Initialize(void)
* \Description     : This Routine Initializes The Automatic Door Application
* \Parameters	   : None
* \Return value:   : None
*******************************************************************************/
void AutomaticDoor_Initialize(void)
{
	Ultrasonic_Init();
	GPT_SetTime();
	
}

/******************************************************************************
* \Syntax          : void AutomaticDoor_ISR_START(void)
* \Description     : Start The ISR of The Automatic Door
* \Parameters      : None
* \Return value:   : None
*******************************************************************************/
void AutomaticDoor_ISR_START(void){
	IRQH_Set_CallBack(Timer_Counter0_Overflow_VECTOR_INDEX,AutomaticDoor_ISR);	
}

/******************************************************************************
* \Syntax          : void AutomaticDoor_ISR(void)
* \Description     : This ISR Responsible for Distance Measurement using Ultrasonic and Servo motor Control with that distance
* \Parameters      : None
* \Return value:   : None
*******************************************************************************/
void AutomaticDoor_ISR(void){
		 static uint8 UltrasonicTrigger_flag=0; // if this Flag == 1 , the ultrasonic trigger signal is sent
		 static uint8 dist_Cap_flag=0;  // if this Flag == 1 , then ultrasonic Distance is Captured using ICU
	if (dist_Cap_flag ==1)
	{
			GPT_Init();
			Dist =0;
			dist_Cap_flag = 0;
	}
    else if (UltrasonicTrigger_flag ==0)
	{
		Ultrasonic_Trigger();
		UltrasonicTrigger_flag =1;
	}
	if (UltrasonicTrigger_flag ==1)
	{
		Dist =Ultrasonic_GetDistance();
	}
	if (Dist>0)
	{
		if ((Dist<20))
		{
			ServoMotor_Init();
			CLEAR_TIMER1_COUNTING_REG();
			ServoMotor_SetDegree(90);
			dist_Cap_flag =1;
			UltrasonicTrigger_flag =0;
		}
		else if((Dist>=20)){
			ServoMotor_Init();
			CLEAR_TIMER1_COUNTING_REG();
			ServoMotor_SetDegree(0);
			dist_Cap_flag =1;
			UltrasonicTrigger_flag =0;
		}
	}
}


/******************************************************************************
* \Syntax          : void AutomaticDoor_Start(void)
* \Description     : This Routine Starts The AutomaticDoor_Application
* \Parameters      : None
* \Return value:   : None
*******************************************************************************/

void AutomaticDoor_Start(void)
{	
	uint8 dist_l=0; // used to Save The Dist var Once Captured
	Bluetooth_Select_Variable(&App_state);
	Bluetooth_Start_Receiving();
	while(App_state != GO_BACK)
	{
		if (Dist > 0)
		{
			dist_l = Dist;
			LCD_GoTo(0,0);
			LCD_WriteString("Dist = ");
			LCD_WriteInteger(dist_l);
			LCD_WriteString(" cm              ");
			if (dist_l<20)
			{
				LCD_GoTo(1,0);
				LCD_WriteString("Door : Open         ");
			}
			else{
				LCD_GoTo(1,0);
				LCD_WriteString("Door : Closed         ");
			}
		}	
	}
	Bluetooth_Check_DataReceived();
	Bluetooth_Stop_Receiving();
	App_state = SELECT_APP2;
	LCD_Clear();
}




/**********************************************************************************************************************
 *  END OF FILE: Automatic_Door.c 
 *********************************************************************************************************************/
