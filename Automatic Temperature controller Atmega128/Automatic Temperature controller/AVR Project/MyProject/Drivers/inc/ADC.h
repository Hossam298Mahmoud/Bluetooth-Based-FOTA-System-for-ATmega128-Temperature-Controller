/*
 * ADC.h
 *
 * Created: 9/19/2023 1:47:51 PM
 *  Author: Hossam Mahmoud
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

#define SET(BASE,PIN)     (*((volatile uint8_t*)(BASE)) |= 1<<PIN)          //SET A BIT IN SPECIFIC PORT

#define CLEAR(BASE,PIN)   (*((volatile uint8_t*)(BASE)) &= ~(1<<PIN))       //CLEAR A BIT IN SPECIFIC PORT

#define CHECK(BASE,PIN)   (*((volatile uint8_t*)(BASE))>>PIN & 1)           //CHECK(GET) A BIT IN SPECIFIC PORT

#define FLIP(BASE,PIN)    (*((volatile uint8_t*)(BASE)) ^= 1<<PIN)          //TOGGLE A BIT IN SPECIFIC PORT

#define ADC_CREG         0x26
#define ADC_MUX          0x27
#define ADC_L            0x24
#define ADC_H            0x25

void ADC_Init();

uint16_t ADC_Read(uint8_t CH);

#endif /* ADC_H_ */