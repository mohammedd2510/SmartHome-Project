/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Fan_Controller.h 
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef FAN_CONTROLLER_H_
#define FAN_CONTROLLER_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Smart_Home.h"
#include "FAN_Core.h"
#include "DS18B20_Core.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern volatile uint8 FanAuto_Flag; 
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void FanController_Init(void);
void FanController_Start(void);
void FanAutoSpeed_Routine(void);
void FanManualSpeed_Routine(void);
#endif /* FAN_CONTROLLER_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Fan_Controller.h 
 *********************************************************************************************************************/





