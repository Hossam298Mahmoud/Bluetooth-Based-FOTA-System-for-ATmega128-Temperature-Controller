/*
 * GPIO_MCAL.h
 *
 * Created: 9/3/2023 12:22:32 PM
 *  Author: Hossam Mahmoud
 */ 
#ifndef GPIO_MCAL_H_
#define GPIO_MCAL_H_

#include<stdint.h>

#define BIT_SET(BASE,PIN)     (*((volatile char*)(BASE+2)) |= 1<<PIN)          //SET A BIT IN SPECIFIC PORT

#define BIT_CLEAR(BASE,PIN)   (*((volatile char*)(BASE+2)) &= ~(1<<PIN))       //CLEAR A BIT IN SPECIFIC PORT

#define BIT_CHECK(BASE,PIN)   (*((volatile char*)(BASE+2))>>PIN & 1)           //CHECK(GET) A BIT IN SPECIFIC PORT

#define BIT_FLIP(BASE,PIN)    (*((volatile char*)(BASE+2)) ^= 1<<PIN)          //TOGGLE A BIT IN SPECIFIC PORT

//DDR for Specify which Pin is INPUT OR OUPUT
#define INPUT   0
#define OUTPUT  1
 
//BASE Addresses for PORTS Of ATmeg16
#define A_Base   0X39
#define B_Base   0X36
#define C_Base   0X33
#define D_Base   0X30
//DEFINE PIN NUMBERS 
#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7
//DEFINATIONS OF FUNCTIONS Which USED IN INPUT/OUTPUT DRIVER

void DIR_BIT(uint8_t BASE , uint8_t PIN , uint8_t DIR);    //SPECIFY THE DIRECTION OF SPECIFIC PIN INPUT OR OUTPUT

void DIR_PORT(uint8_t BASE , uint8_t VAL);                 //SPECIFY THE DIRECTION OF SPECIFIC PORT INPUT OR OUTPUT

void SET_BIT(uint8_t BASE , uint8_t PIN);                  //SET A BIT IN SPECIFIC PORT

void CLEAR_BIT(uint8_t BASE , uint8_t PIN);                //CLEAR A BIT IN SPECIFIC PORT

void FLIP_BIT(uint8_t BASE , uint8_t PIN);                 //TOGGLE A BIT IN SPECIFIC PORT

uint8_t READ_BIT(uint8_t BASE , uint8_t PIN);              //CHECK(GET) A BIT IN SPECIFIC PORT

void WRITE_PORT(uint8_t BASE , uint8_t VAL);               //WRITE A VALUE TO A SPECIFIC PORT

void SET_PORT(uint8_t BASE);                               //SET A SPECIFIC PORT

void CLEAR_PORT(uint8_t BASE);                             //CLEAR A SPECIFIC PORT

uint8_t READ_PORT(uint8_t BASE);                          //READ A SPECIFIC  PORT
  
#endif /* GPIO_MCAL_H_ */