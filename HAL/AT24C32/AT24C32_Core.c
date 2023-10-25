/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  AT24C32_Core.c 
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "AT24C32_Core.h"

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

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


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
void AT24C32_INIT(void){
	I2C_MasterInit();
}

void AT24C32_WriteByte(uint8 addr , uint16 loc ,uint8 data){
	I2C_StartCondition();
	I2C_SendAddress_WriteOperation(addr);
	I2C_WriteByte(loc>>8);
	I2C_WriteByte(loc&0xFF);
	I2C_WriteByte(data);
	I2C_StopCondition();
	_delay_ms(10);
}

uint8 AT24C32_ReadByte(uint8 addr , uint16 loc){
	uint8 data=0;
	I2C_StartCondition();
	I2C_SendAddress_WriteOperation(addr);
	I2C_WriteByte(loc>>8);
	I2C_WriteByte(loc&0xFF);
	I2C_RepeatedStart();
	I2C_SendAddress_ReadOperation(addr);
	data=I2C_ReadByte_NACK();
	I2C_StopCondition();
	_delay_ms(10);
	return data;
}
void AT24C32_WriteMultipleByte(uint8 addr , uint16 loc ,uint8 *data, uint8 data_size){
	uint8 cnt=0;
	I2C_StartCondition();
	I2C_SendAddress_WriteOperation(addr);
	I2C_WriteByte(loc>>8);
	I2C_WriteByte(loc&0xFF);
	while (cnt < data_size){
	I2C_WriteByte(data[cnt]);
	cnt++;	
	}
	I2C_StopCondition();
	_delay_ms(10);
}
void AT24C32_ReadMultipleByte(uint8 addr , uint16 loc ,uint8 *data, uint8 data_size){
	uint8 cnt=0;
	I2C_StartCondition();
	I2C_SendAddress_WriteOperation(addr);
	I2C_WriteByte(loc>>8);
	I2C_WriteByte(loc&0xFF);
	I2C_RepeatedStart();
	I2C_SendAddress_ReadOperation(addr);
	while (cnt < data_size){
		if (cnt == data_size-1)
		{
			data[cnt]=I2C_ReadByte_NACK();
		}
		else{
		data[cnt]=I2C_ReadByte_ACK();}
		cnt++;
	}
	I2C_StopCondition();
	_delay_ms(10);
}
/**********************************************************************************************************************
 *  END OF FILE: AT24C32_Core.c 
 *********************************************************************************************************************/

