/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DS18B20_Core.h 
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef DS18B20_CORE_H_
#define DS18B20_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "DS18B20_Cfg.h"
#include "DIO_Core.h"
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <util/delay.h>
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define tRSTL 480
#define tRSTH 480
#define tSLOT 60
#define tLOW1 1
#define tLOW0 60
#define tREC 1
#define tRDV 14
#define SKIPROM 0XCC
#define CONVTEMP  0X44
#define READ_SCRATCHPAD 0XBE
#define TEMP_CONV_CONST 0.0625
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
uint8 DS18B20_GetTemp(void);
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif /* DS18B20_CORE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: DS18B20_Core.h 
 *********************************************************************************************************************/





