/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  RTC_Core.c 
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "RTC_Core.h"

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
uint8 BCD_to_Decimal(uint8 BCD_NUM);
uint8 Decimal_to_BCD(uint8 Decimal);
void RTC_Write_Byte (uint8 RTC_Add ,uint8 Reg_Add , uint8 Data);
uint8 RTC_Read_Byte(uint8 RTC_Add ,uint8 Reg_Add);
char* Days_Dec_to_string(uint8 days_dec);
char* Month_Dec_to_string(uint8 month_dec);
char* midday_val_to_string(uint8 midday_val);
void  RTC_strcpy(char *dest, char*source);
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
uint8 BCD_to_Decimal(uint8 BCD_NUM){
	uint8 Decimal_num =0;
	Decimal_num = (BCD_NUM & 0x0f) + ((BCD_NUM>>4)*10);
	return Decimal_num;
}
void RTC_Write_Byte (uint8 RTC_Add ,uint8 Reg_Add , uint8 Data){
	I2C_StartCondition();
	I2C_SendAddress_WriteOperation(RTC_Add);
	I2C_WriteByte(Reg_Add);
	I2C_WriteByte(Data);
	I2C_StopCondition();
}
uint8 RTC_Read_Byte(uint8 RTC_Add ,uint8 Reg_Add){
	uint8 Data=0;
	I2C_StartCondition();
	I2C_SendAddress_WriteOperation(RTC_Add);
	I2C_WriteByte(Reg_Add);
	I2C_RepeatedStart();
	I2C_SendAddress_ReadOperation(RTC_Add);
	Data=I2C_ReadByte_NACK();
	I2C_StopCondition();
	return Data;
}
char* Days_Dec_to_string(uint8 days_dec){
	static char Days_str[4]={0};
	switch (days_dec){
		case SATURDAY :	RTC_strcpy(Days_str,"Sat");break;
		case SUNDAY   :	RTC_strcpy(Days_str,"Sun");break;
		case MONDAY   :	RTC_strcpy(Days_str,"Mon");break;
		case TUESDAY  :	RTC_strcpy(Days_str,"Tue");break;
		case WEDNESDAY :RTC_strcpy(Days_str,"Wed");break;
		case THURSDAY  :RTC_strcpy(Days_str,"Thu");break;
		case FRIDAY    :RTC_strcpy(Days_str,"Fri");break;
	} 
	return Days_str;
}
char* Month_Dec_to_string(uint8 month_dec){
	static char Months_str[4]={0};
	switch (month_dec){
		case JANUARY   :RTC_strcpy(Months_str,"Jan");break;
		case FEBURARY  :RTC_strcpy(Months_str,"Feb");break;
		case MARCH     :RTC_strcpy(Months_str,"Mar");break;
		case APRIL     :RTC_strcpy(Months_str,"Apr");break;
		case MAY	   :RTC_strcpy(Months_str,"May");break;
		case JUNE	   :RTC_strcpy(Months_str,"Jun");break;
		case JULY      :RTC_strcpy(Months_str,"Jul");break;
		case AUGUST    :RTC_strcpy(Months_str,"Aug");break;
		case SEPTEMBER :RTC_strcpy(Months_str,"Sep");break;
		case OCTOBER   :RTC_strcpy(Months_str,"Oct");break;
		case NOVEMBER  :RTC_strcpy(Months_str,"Nov");break;
		case DECEMBER  :RTC_strcpy(Months_str,"Dec");break;
	}
	return Months_str;
}
char* midday_val_to_string(uint8 midday_val){
	static char Midday_str[3]={0};
	switch (midday_val){
		case AM  :RTC_strcpy(Midday_str,"AM");break;
		case PM  :RTC_strcpy(Midday_str,"PM");break;
	}
	return Midday_str;	
}
void  RTC_strcpy(char *dest, char*source){
	while ((*source)!='\0')
	{
		*dest++=*source++;
	}
	*dest = '\0';
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void RTC_Init(void){
	I2C_MasterInit();
	#if (RTC_INIT != INITIALIZED)
	RTC_Write_Byte(RTC_ADD,SECONDS_REG,0X00); // Enable Crystal for First Time
	#endif
	RTC_Write_Byte(RTC_ADD,CONTROL_REG,0x03); // crystal = 32.768khz
}
void RTC_SetTime(uint8 sec , uint8 min ,uint8 hours , Midday_Status_t midday ){
	RTC_Write_Byte(RTC_ADD ,SECONDS_REG ,sec);
	_delay_ms(50);
	RTC_Write_Byte(RTC_ADD ,MINUTES_REG ,min);
	_delay_ms(50);
	RTC_Write_Byte(RTC_ADD ,HOURS_REG , (hours|(1<<Midday_Format)|(midday<<Midday_bit)) );
	_delay_ms(50);
}
void RTC_SetDate (Day_name_t day_name ,uint8 day , Month_name_t month , uint8 year ){
	RTC_Write_Byte(RTC_ADD ,DAY_REG ,day_name);
	_delay_ms(50);
	RTC_Write_Byte(RTC_ADD ,DATE_REG ,day);
	_delay_ms(50);
	RTC_Write_Byte(RTC_ADD ,MONTH_REG , month );
	_delay_ms(50);
	RTC_Write_Byte(RTC_ADD ,YEAR_REG ,  year );
	_delay_ms(50);
}

void RTC_GetTime(uint8* sec , uint8* min ,uint8* hours , char** midday ){
	uint8 sec_bcd,min_bcd,hours_bcd;
	uint8 sec_dec,min_dec,hours_dec;
	uint8 hours_Reg=0;
	uint8 midday_val=0;
	sec_bcd=RTC_Read_Byte(RTC_ADD ,SECONDS_REG);sec_dec = BCD_to_Decimal(sec_bcd);
	_delay_ms(50);
	min_bcd=RTC_Read_Byte(RTC_ADD ,MINUTES_REG );min_dec =BCD_to_Decimal(min_bcd);
	_delay_ms(50);
	hours_Reg=RTC_Read_Byte(RTC_ADD ,HOURS_REG);
	_delay_ms(50);
	hours_bcd = hours_Reg & 0x1f; hours_dec=BCD_to_Decimal(hours_bcd);
	midday_val = (hours_Reg >> Midday_bit)&0x01;
	/*************************************************/
	*sec =sec_dec;
	*min =min_dec;
	*hours = hours_dec;
	*midday=midday_val_to_string(midday_val);
}
void RTC_GetDate(char** day_name ,uint8* day , char** month , uint8* year ){
	uint8 day_name_val,day_bcd,month_bcd,year_bcd;
	uint8 day_dec,month_dec,year_dec;
	day_name_val=RTC_Read_Byte(RTC_ADD ,DAY_REG);
	_delay_ms(50);
	day_bcd=RTC_Read_Byte(RTC_ADD ,DATE_REG );day_dec =BCD_to_Decimal(day_bcd);
	_delay_ms(50);
	month_bcd=RTC_Read_Byte(RTC_ADD ,MONTH_REG);month_dec =BCD_to_Decimal(month_bcd);
	_delay_ms(50);
	year_bcd=RTC_Read_Byte(RTC_ADD ,YEAR_REG);year_dec =BCD_to_Decimal(year_bcd);
	_delay_ms(50);
	/*************************************************/
	*day_name =Days_Dec_to_string(day_name_val);
	*day =day_dec;
	*month = Month_Dec_to_string(month_dec);
	*year =year_dec;
}
void RTC_LCD_Write_Clock(uint8 Clk_time){
	if (Clk_time<10)
	{
		LCD_WriteInteger(0);
		LCD_WriteInteger(Clk_time);
	}
	else LCD_WriteInteger(Clk_time);
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                                                                                 
* \Parameters	   : None                                                      
* \Return value:   :                               
*******************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: RTC_Core.c 
 *********************************************************************************************************************/
