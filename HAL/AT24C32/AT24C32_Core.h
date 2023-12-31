/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  AT24C32_Core.h 
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef AT24C32_CORE_H_
#define AT24C32_CORE_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "I2C_Core.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define AT24C32_Address 0b1010000
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
void AT24C32_INIT(void);

void AT24C32_WriteByte(uint8 addr , uint16 loc ,uint8 data);

void AT24C32_WriteMultipleByte(uint8 addr , uint16 loc ,uint8 *data, uint8 data_size);

void AT24C32_ReadMultipleByte(uint8 addr , uint16 loc ,uint8 *data, uint8 data_size);

uint8 AT24C32_ReadByte(uint8 addr , uint16 loc);

#endif /* AT24C32_CORE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: AT24C32_Core.h  
 *********************************************************************************************************************/