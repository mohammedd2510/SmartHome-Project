/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  RTC_Core.h 
 *       Module:  RTC Module
 *
 *  Description:  
 *  
 *********************************************************************************************************************/
#ifndef RTC_CORE_H_
#define RTC_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "I2C_Core.h"
#include "LCD_Core.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define RTC_ADD 0b1101000

#define RTC_INIT 1
#define UNINITIALIZED 0
#define INITIALIZED 1

#define Midday_bit 5
#define Midday_Format 6
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
	SECONDS_REG =0,
	MINUTES_REG,
	HOURS_REG,
	DAY_REG,
	DATE_REG,
	MONTH_REG,
	YEAR_REG,
	CONTROL_REG,
	}RTC_Registers_Add_t;

typedef enum {
	SATURDAY =1 ,
	SUNDAY,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY
	}Day_name_t;
	
typedef enum {
	JANUARY =1 ,
	FEBURARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
}Month_name_t;

typedef enum {
	AM =0 ,
	PM
	}Midday_Status_t;
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void RTC_Init(void);
void RTC_SetTime(uint8 sec , uint8 min ,uint8 hours , Midday_Status_t midday );
void RTC_SetDate (Day_name_t day_name ,uint8 day , Month_name_t month , uint8 year );

void RTC_GetTime(uint8* sec , uint8* min ,uint8* hours , char** midday );
void RTC_GetDate(char** day_name ,uint8* day , char** month , uint8* year );

void RTC_LCD_Write_Clock(uint8 Clk_time);
 
#endif /* RTC_CORE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: RTC_Core.h 
 *********************************************************************************************************************/





