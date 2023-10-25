/*
 * App.c
 *
 * Created: 10/19/2023 3:34:43 PM
 * Author : Mohamed Osama
 */ 

#include "App.h"	

int main(void)
{
	SmartHome_Initialize(); // Initializes The SmartHome Project
    while (1) 
    {
		SmartHome_Start();
	}
}

