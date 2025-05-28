/*
 * MyProject.c
 *
 * Created: 12/28/2023 10:40:48 AM
 * Author : Hossam Mahmoud
 */ 
#define  F_CPU  8000000UL
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include "ADC.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "GPIO_MCAL.h"

void EnterRef(char *Buff)
{
	char  key ,i=0;
	while (1)
	{
			key=  GetKey( D_Base );
			if (key == '=')
			{ 
				Buff[3]='\0';
				return;
			}
			if ((key == 'X') && (i>0))
			{
				LCD_Command(0x10);
				LCD_Char('\0');
				LCD_Command(0x10);
				Buff[--i]=0;
			}
			
			else if ((key != 0) && (i<3))
			{
				Buff[i]=key;
				LCD_Char(key);
				i++;
			}
	}

	
}
int main(void)
{
	char Buff[6],Ref_Value[4] , key; float read ;
	DDRC |=(1<<PC0)|(1<<PC1);
	ADC_Init(PA0);
	LCD_Init();
   /************************************************************************************/
	while (1)
	{
		LCD_String_xy(0,4,"Automatic");
		LCD_String_xy(1,2,"Temp Control");
		_delay_ms(3000);
		LCD_Clear();
		LCD_String_xy(0,0,"Enter Temp Ref");
		LCD_String_xy(1,0,"Temp Ref: ");
		EnterRef(Ref_Value);
		LCD_Clear();
		LCD_String_xy(0,0,"Temp Ref: ");
		LCD_String(Ref_Value);
		LCD_String("'C");
		LCD_String_xy(1,0,"Press = to Cont.");
	    
		while ((key = GetKey( D_Base)) == 0);
		if (key == '=')
		{
			break;
		}
		else
		{
			LCD_Clear();
		}
	}
	
	LCD_Clear();
	LCD_String_xy(0,0,"Temp Ref: ");
	LCD_String(Ref_Value);
	LCD_String("'C");
    LCD_String_xy(1,0,"Temp = ");

    while (1) 
    {
		    read =(float)(ADC_Read(0)*500)/1024;
		    dtostrf(read,4,2,Buff);
			LCD_String_xy(1,7,Buff);
			LCD_String("'C");
			if(read>atoi(Ref_Value))
			{
				PORTC |=(1<<PC1);
				PORTC &=~(1<<PC0);
			}
			else
			{
				PORTC |=(1<<PC0);
				PORTC &=~(1<<PC1);
			}
			_delay_ms(3000); 
			LCD_String_xy(1,7,"         ");
    }
}

