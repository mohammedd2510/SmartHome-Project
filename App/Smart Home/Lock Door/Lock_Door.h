/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Lock_Door.h 
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef LOCK_DOOR_H_
#define LOCK_DOOR_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "LCD_Core.h"
#include "LED.h"
#include "BUZZ.h"
#include "SERVO_MOTOR_Core.h"
#include "PORT_Core.h"
#include "Bluetooth_Core.h"
#include "AT24C32_Core.h"
#include "Smart_Home.h"
#include "STEPPER_Core.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define DOOR_ICON 0x00U
#define DOOR_LOCKED_ICON 0X01U
#define DOOR_UNLOCKED_ICON 0X02U
#define Smile_Face 0x03U

#define PIN_SIZE 4
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
typedef enum {
	INIT_STATE=0,
	SET_NEW_PIN = '1',
	CHEK_CURRENT_PIN = '2'
}Lock_status_t;
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void SmartDoor_Initialize(void);
void SmartDoor_Start(void);
 
#endif /* LOCK_DOOR_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Lock_Door.h 
 *********************************************************************************************************************/





