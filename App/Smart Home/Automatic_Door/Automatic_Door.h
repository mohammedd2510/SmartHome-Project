/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Automatic_Door.h 
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef AUTOMATIC_DOOR_H_
#define AUTOMATIC_DOOR_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "ULTRASONIC_Core.h"
#include "Smart_Home.h"
#include "GPT_Core.h"
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
void AutomaticDoor_Initialize(void);
void AutomaticDoor_Start(void);

 void AutomaticDoor_ISR(void);
 void AutomaticDoor_ISR_START(void);
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 

#endif /* AUTOMATIC_DOOR_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Automatic_Door.h 
 *********************************************************************************************************************/




