/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  STEPPER_Core.h 
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef STEPPER_CORE_H_
#define STEPPER_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STEPPER_Cfg.h"
#include "DIO_Core.h"
#ifndef F_CPU
#define F_CPU 16000000U
#endif
#include <util/delay.h>
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum {
	ANTICLOCKWISE,
	CLOCKWISE
	}Stepper_Direction_t;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void SET_STEPPER_MOTOR(uint16 Angle ,Stepper_Direction_t dir  , uint8 RPM);
 
#endif /* STEPPER_CORE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: STEPPER_Core.h 
 *********************************************************************************************************************/





