/*
 * LCD.h
 *
 * Created: 9/12/2023 10:08:48 PM
 *  Author: Hossam Mahmoud
 */ 
#ifndef LCD_H_
#define LCD_H_

#include <stdint.h>
#include <avr/io.h>

#define Clear_Display     0x01
#define Return_Home       0x02
#define Mode_8Bit         0x38
#define Mode_4Bit         0x28
#define Displayon_Blink   0x0E

#define RS  2
//#define RW  1
#define EN  3

#define LCD_Command_Port      PORTB
#define LCD_Command_Dir       DDRB

#define LCD_Data_Port         PORTB
#define LCD_Data_Dir          DDRB

/***************************************************************************************/
uint8_t i;

void LCD_Command(unsigned char cmd);

void LCD_Init (void);

void LCD_Char (unsigned char char_data);

void LCD_String (char *str);

void LCD_Clear();
	
void LCD_String_xy (char row, char pos, char *str) ;

#endif /* LCD_H_ */