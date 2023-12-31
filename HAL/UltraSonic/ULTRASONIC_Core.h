/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  ULTRASONIC_Core.h 
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef ULTRASONIC_CORE_H_
#define ULTRASONIC_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "ULTRASONIC_Cfg.h"
#include "ICU_Core.h"
#include "DIO_Core.h"

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

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Ultrasonic_Init(void);
uint32 Ultrasonic_GetDistance(void);
void Ultrasonic_Trigger(void);
 
#endif /* ULTRASONIC_CORE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: ULTRASONIC_Core.h 
 *********************************************************************************************************************/





