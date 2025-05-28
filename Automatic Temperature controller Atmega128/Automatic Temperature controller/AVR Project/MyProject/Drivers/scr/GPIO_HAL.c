/*
 * GPIO_HAL.c
 *
 * Created: 9/3/2023 12:34:54 PM
 *  Author: Hossam Mahmoud
 */ 
#include "GPIO_MCAL.h"    

void DIR_BIT(uint8_t BASE , uint8_t PIN , uint8_t DIR)    //SPECIFY THE DIRECTION OF SPECIFIC PIN INPUT OR OUTPUT
{
	if (DIR==OUTPUT)
	{
		*((volatile char*)(BASE+1)) |= 1<<PIN ;
	}
	else if (DIR==INPUT)
	{
		*((volatile char*)(BASE+1)) &= ~(1<<PIN) ;
	}
}

void DIR_PORT(uint8_t BASE , uint8_t VAL)                 //SPECIFY THE DIRECTION OF SPECIFIC PORT INPUT OR OUTPUT
{
	*((volatile char*)(BASE+1)) = VAL ;
}

void SET_BIT(uint8_t BASE , uint8_t PIN)                  //SET A BIT IN SPECIFIC PORT
{
	*((volatile char*)(BASE+2)) |= 1<<PIN ;
}

void CLEAR_BIT(uint8_t BASE , uint8_t PIN)                //CLEAR A BIT IN SPECIFIC PORT
{
	*((volatile char*)(BASE+2)) &= ~(1<<PIN) ;
}

void FLIP_BIT(uint8_t BASE , uint8_t PIN)                 //TOGGLE A BIT IN SPECIFIC PORT
{
	*((volatile char*)(BASE+2)) ^= 1<<PIN ;
}

uint8_t READ_BIT(uint8_t BASE , uint8_t PIN)              //CHECK(GET) A BIT IN SPECIFIC PORT
{
   return  *((volatile char*)(BASE))>>PIN & 1 ;
}

void WRITE_PORT(uint8_t BASE , uint8_t VAL)               //WRITE A VALUE TO A SPECIFIC PORT
{
	*((volatile char*)(BASE+2)) = VAL ;
}

void SET_PORT(uint8_t BASE)                               //SET A SPECIFIC PORT
{
   *((volatile char*)(BASE+2)) = 0xFF ;
}

void CLEAR_PORT(uint8_t BASE)                             //CLEAR A SPECIFIC PORT
{
    *((volatile char*)(BASE+2)) = 0x00 ;
}

uint8_t READ_PORT(uint8_t BASE)                          //READ A SPECIFIC  PORT
{
	return *((volatile char*)(BASE));
}