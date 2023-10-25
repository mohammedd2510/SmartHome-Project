/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  STEPPER_Core.c 
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "STEPPER_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
void Delay_ms(uint32 ms){
	while(ms--){
		_delay_ms(1);
	}
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

void SET_STEPPER_MOTOR(uint16 Angle ,Stepper_Direction_t dir  , uint8 RPM){
	uint16 Number_of_Step_Sequences = Angle /STEP_ANGLE;
	uint16 sequence_cnt =0;
	uint32 step_delay =0;
	if (RPM < 1)
	{
		step_delay =15;
	}
	else if (RPM > 14)
	{
		step_delay=1;
	}
	else{
	 step_delay =(uint32)((1000.0*60.0)/(8.0*RPM*512));
	}
	switch (dir){
		case ANTICLOCKWISE :
		for (sequence_cnt =0; sequence_cnt <Number_of_Step_Sequences; sequence_cnt++)
		{
				DIO_WriteChannel(STEPPER_COIL_A,PIN_HIGH);
				Delay_ms(step_delay);
				DIO_WriteChannel(STEPPER_COIL_A,PIN_HIGH);
				DIO_WriteChannel(STEPPER_COIL_B,PIN_HIGH);
				Delay_ms(step_delay);
				DIO_WriteChannel(STEPPER_COIL_A,PIN_LOW);
				Delay_ms(step_delay);
				DIO_WriteChannel(STEPPER_COIL_C,PIN_HIGH);
				Delay_ms(step_delay);
				DIO_WriteChannel(STEPPER_COIL_B,PIN_LOW);
				Delay_ms(step_delay);
				DIO_WriteChannel(STEPPER_COIL_D,PIN_HIGH);
				Delay_ms(step_delay);
				DIO_WriteChannel(STEPPER_COIL_C,PIN_LOW);
				Delay_ms(step_delay);
				DIO_WriteChannel(STEPPER_COIL_A,PIN_HIGH);
				Delay_ms(step_delay);
				DIO_WriteChannel(STEPPER_COIL_D,PIN_LOW);
				DIO_WriteChannel(STEPPER_COIL_A,PIN_LOW);
		}
		break;
		case CLOCKWISE :
			for (sequence_cnt =0; sequence_cnt <Number_of_Step_Sequences; sequence_cnt++)
			{
			DIO_WriteChannel(STEPPER_COIL_A,PIN_HIGH);
			DIO_WriteChannel(STEPPER_COIL_D,PIN_HIGH);
			Delay_ms(step_delay);
			DIO_WriteChannel(STEPPER_COIL_A,PIN_LOW);
			Delay_ms(step_delay);
			DIO_WriteChannel(STEPPER_COIL_C,PIN_HIGH);
			Delay_ms(step_delay);
			DIO_WriteChannel(STEPPER_COIL_D,PIN_LOW);
			Delay_ms(step_delay);
			DIO_WriteChannel(STEPPER_COIL_B,PIN_HIGH);
			Delay_ms(step_delay);
			DIO_WriteChannel(STEPPER_COIL_C,PIN_LOW);
			Delay_ms(step_delay);
			DIO_WriteChannel(STEPPER_COIL_A,PIN_HIGH);
			Delay_ms(step_delay);
			DIO_WriteChannel(STEPPER_COIL_B,PIN_LOW);
			Delay_ms(step_delay);
			DIO_WriteChannel(STEPPER_COIL_A,PIN_LOW);
			}
		break;
	}
}


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

/**********************************************************************************************************************
 *  END OF FILE: STEPPER_Core.c 
 *********************************************************************************************************************/

