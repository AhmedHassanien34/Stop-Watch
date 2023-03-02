/*
 * main.c
 *
 *  Created on: Mar 2, 2023
 *      Author: Torres
 */

#include "util/delay.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"

#include "StopWatchFunctions.h"


extern u8 Global_u8Second;
extern u8 Global_u8Minute;
extern u8 Global_u8Hour;

void main(void)
{
	/*Initializations*/
	StopWatch_Init();

	EXTI_u8Int0SetCallBack(Reset_StopWatch);
	EXTI_u8Int1SetCallBack(Stop_stopWatch);
	EXTI_u8Int2SetCallBack(Resume_StopWatch);

	TIMER_voidTimer1SetCallBack(Detect_Seconds);

	for(;;)
	{
		//Sec0
		DIO_u8SetPortValue(DIO_u8PORTA,DIO_u8PORT_LOW);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);

		DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_LOW);
		DIO_u8SetPortValue(DIO_u8PORTC,(Global_u8Second%10) & 0X0F);

		_delay_ms(1);

		//**********************************************************************************************
		//Sec1
		DIO_u8SetPortValue(DIO_u8PORTA,DIO_u8PORT_LOW);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);

		DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_LOW);
		DIO_u8SetPortValue(DIO_u8PORTC,(Global_u8Second/10) & 0X0F);

		_delay_ms(1);

		//**********************************************************************************************
		//Min0
		DIO_u8SetPortValue(DIO_u8PORTA,DIO_u8PORT_LOW);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_HIGH);

		DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_LOW);
		DIO_u8SetPortValue(DIO_u8PORTC,(Global_u8Minute%10) & 0X0F);

		_delay_ms(1);

		//**********************************************************************************************
		//Min1
		DIO_u8SetPortValue(DIO_u8PORTA,DIO_u8PORT_LOW);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN3,DIO_u8PIN_HIGH);

		DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_LOW);
		DIO_u8SetPortValue(DIO_u8PORTC,(Global_u8Minute/10) & 0X0F);

		_delay_ms(1);

		//**********************************************************************************************
		//Hour0
		DIO_u8SetPortValue(DIO_u8PORTA,DIO_u8PORT_LOW);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_HIGH);

		DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_LOW);
		DIO_u8SetPortValue(DIO_u8PORTC,(Global_u8Hour%10) & 0X0F);

		_delay_ms(1);

		//**********************************************************************************************
		//Hour1
		DIO_u8SetPortValue(DIO_u8PORTA,DIO_u8PORT_LOW);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_HIGH);

		DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_LOW);
		DIO_u8SetPortValue(DIO_u8PORTC,(Global_u8Hour/10) & 0X0F);

		_delay_ms(1);

	}
}
