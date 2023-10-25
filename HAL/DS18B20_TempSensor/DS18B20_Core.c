/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DS18B20_Core.c 
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "DS18B20_Core.h"

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
void OneWire_Reset(void);
void OneWire_WriteBit(uint8 bit);
uint8 OneWire_ReadBit(void);
void OneWire_WriteByte(uint8 byte);
uint8 OneWire_ReadByte(void);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
void OneWire_Reset(void){
	DIO_SetPinDirection(DS18B20_PIN , PIN_OUTPUT);
	DIO_WriteChannel(DS18B20_PIN ,PIN_LOW);
	_delay_us(tRSTL);
	DIO_SetPinDirection(DS18B20_PIN , PIN_INPUT);
	_delay_us(tRSTH);
}
void OneWire_WriteBit(uint8 bit){
	DIO_SetPinDirection(DS18B20_PIN , PIN_OUTPUT);
	DIO_WriteChannel(DS18B20_PIN ,PIN_LOW);
	_delay_us(tLOW1);
	if (bit==1)
	{
		DIO_SetPinDirection(DS18B20_PIN , PIN_INPUT);
	}
		_delay_us(tSLOT);
		DIO_SetPinDirection(DS18B20_PIN , PIN_INPUT);
	
}
uint8 OneWire_ReadBit(void){
	uint8 bit=0;
	DIO_SetPinDirection(DS18B20_PIN , PIN_OUTPUT);
	DIO_WriteChannel(DS18B20_PIN ,PIN_LOW);
	_delay_us(tREC);
	DIO_SetPinDirection(DS18B20_PIN , PIN_INPUT);
	_delay_us(tRDV);
	DIO_ReadChannel(DS18B20_PIN,&bit);
	_delay_us(tSLOT-tREC-tRDV);
	return bit;
}
void OneWire_WriteByte(uint8 byte){
	uint8 cnt = 0;
	for (cnt=0;cnt<8;cnt++)
	{
		OneWire_WriteBit((byte>>cnt)&0x01);
	}
}
uint8 OneWire_ReadByte(void){
	uint8 cnt = 0 , byte =0;
	for (cnt=0;cnt<8;cnt++)
	{
		byte|=(OneWire_ReadBit()<<cnt);
	}
	return byte;
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
uint8 DS18B20_GetTemp(void){
	uint8 Temp=0;
	uint8 D_Temp_L =0;
	uint8 D_Temp_H =0;
	OneWire_Reset(); //reset
	OneWire_WriteByte(SKIPROM); //skip ROM
	OneWire_WriteByte(CONVTEMP);  //start temperature conversion
	while (OneWire_ReadBit()==0); //wait until conversion is complete
	OneWire_Reset(); //reset
	OneWire_WriteByte(SKIPROM);//skip ROM
	OneWire_WriteByte(READ_SCRATCHPAD); //read ScratchPad
	//read 2 byte from ScratchPad
	D_Temp_L =OneWire_ReadByte();
	D_Temp_H =OneWire_ReadByte();
	//convert the 12 bit value obtained
	Temp = ((D_Temp_H<<8)|(D_Temp_L))*TEMP_CONV_CONST;
	return Temp;
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                                                                                                                 
* \Parameters	   : None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: DS18B20_Core.c 
 *********************************************************************************************************************/
