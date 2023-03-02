#include "STD_TYPES.h"

#include "StopWatchFunctions.h"

#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"


/* Variable to increment the value of the seconds */
u8 Global_u8Second=0;

/* Variable to increment the value of the Minutes */
u8 Global_u8Minute=0;

/* Variable to increment the value of the Hours */
u8 Global_u8Hour=0;

void StopWatch_Init(void)
{
	/* Configure INT0, INT1, and INT2 pins as INPUT PULLUP pins */
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_INPULLUP);
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_INPULLUP);
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_INPULLUP);


	/* Configure first 4 pins in PORTC as output pins (Data Lines) */
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_OUTPUT);

	/* configure first 6 pins in PORTA As output pins(control lines) */
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN3,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_OUTPUT);

	/* initial value 5 volt to display all segments in the same time for the first time */
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN3,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_HIGH);

	/* Initial value for the begin of the 7 segment all segments = 0 in the first */
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN3,DIO_u8PIN_HIGH);

	/* Enable Global Interrupt */
	GIE_voidEnable();

	/* initialize the configure structure of external interrup0 in the FALLING_EDGE */
	EXTI_voidInt0Init();

	/* initialize the configure structure of external interrup1 in the RISING_EDGE */
	EXTI_voidInt1Init();

	/* initialize the configure structure of external interrup2 in the FALLING_EDGE */
	EXTI_voidInt2Init();

	/**/
	TIMER_voidTimer1Enable(TIMER1_MODE_CTC_OCR1A,TIMER1_MODE_CHANNEL_A_SET_OC1A,TIMER1_MODE_CHANNEL_B_NORMAL);

	TIMER_voidTimer1SetOCR1A(1000);
}

void Reset_StopWatch(void)
{
	Global_u8Second=0;
	Global_u8Minute=0;
	Global_u8Hour=0;
}

void Stop_stopWatch(void)
{
	TIMER_voidTimer1Stop();
}

void Resume_StopWatch(void)
{
	TIMER_voidTimer1Continue();
}

void Detect_Seconds(void)
{
	//Set time counters
	Global_u8Second++;

	if(59==Global_u8Second)//Seconds
	{
		Global_u8Second=0;
		Global_u8Minute++;
	}


	if(59==Global_u8Minute)//Minutes
	{
		Global_u8Minute=0;
		Global_u8Hour++;
	}


	if(24==Global_u8Hour)//Hours
	{
		Global_u8Second=0;
		Global_u8Minute=0;
		Global_u8Hour=0;
	}

}
