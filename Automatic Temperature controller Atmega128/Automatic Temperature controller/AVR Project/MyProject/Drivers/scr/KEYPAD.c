/*
 * KEYPAD.c
 *
 * Created: 11/17/2023 2:09:41 PM
 *  Author: Hossam Mahmoud
 */ 
/**************************4x4 keypad Code**************************/
#include "GPIO_MCAL.h"
#include "KEYPAD.h"

static const uint8_t  ROWS = 4; //four rows
static const uint8_t  COLS = 4; //four columns
static uint8_t i,k;

char GetKey(uint8_t Base)
{
	DIR_PORT(Base,0x0F);
	WRITE_PORT(Base,0xFF);
	
	for (i=0 ; i < ROWS ; i++)
	{
	     CLEAR_BIT(Base,i);	 
	/**************************************************************/
		 for (k=0 ; k < COLS ; k++)
		 {
			 if(!READ_BIT(Base,k+4))
			 {
				 while(!READ_BIT(Base,k+4));
				 return keys[i][k];
			 }
		 }
	 /************************************************************/	
	     SET_BIT(Base,i);
	}
	
	return 0;
}


