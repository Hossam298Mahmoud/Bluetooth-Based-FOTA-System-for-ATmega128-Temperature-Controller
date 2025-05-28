/*
 * KEYPAD.h
 *
 * Created: 11/17/2023 2:09:52 PM
 *  Author: Hossam Mahmoud
 */ 
#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <stdint.h>



static char keys[4][4] = {
		{'N','0','=','+'},
		{'1','2','3','-'},
		{'4','5','6','X'},
		{'7','8','9','/'}
		};

char GetKey(uint8_t Base);

#endif /* KEYPAD_H_ */