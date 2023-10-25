/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  LCD_Core.h 
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef LCD_CORE_H_
#define LCD_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "LCD_Cfg.h"
#include "DIO_Core.h"
#ifndef F_CPU
#define  F_CPU  16000000U
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


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void LCD_Init(void);
void LCD_WriteCommand(uint8 cmd);
void LCD_WriteChar(uint8 chr);
void LCD_WriteString(char *chr);
void LCD_WriteInteger(sint32 num);
void LCD_Clear(void);
void LCD_GoTo(uint8 Row,uint8 Col);
void LCD_Custom_Char_Init(void);
 

#endif /* LCD_CORE_H_ */
/**********************************************************************************************************************
 *  END OF FILE: LCD_Core.h 
 *********************************************************************************************************************/





