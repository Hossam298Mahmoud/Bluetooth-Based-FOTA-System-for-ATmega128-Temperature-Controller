/*
 * ADC.c
 *
 * Created: 9/19/2023 2:04:44 PM
 *  Author: Hossam Mahmoud
 */ 

#include "ADC.h"


void ADC_Init()
{   
	// ENABLE THE ADC MOUDULE
	SET(ADC_CREG ,7);
	
	//SETTING THA PRESCALAR (DIVISION FACTOR) ---- ADC CLOCK SETTING
	SET(ADC_CREG ,0);
	SET(ADC_CREG ,1);
	CLEAR(ADC_CREG ,2);
	
	//LEFT ADJUST FOR RESULTS
	CLEAR(ADC_MUX ,5);
	
	//SELECT THE ADC REFERENCE VOLTAGE 
	SET(ADC_MUX ,6);
	CLEAR(ADC_MUX ,7);    
}

uint16_t  ADC_Read(uint8_t CH)
{
	//SELECT THE CHANNEL TO BE READ
	 *((volatile uint8_t*)ADC_MUX) &= 0xE0;
	 *((volatile uint8_t*)ADC_MUX) |= CH;
	
	//START CONVERSION PROCESS  
	SET(ADC_CREG ,6);
	
	//WAIT UNTIL THE CONVERSION IS FINISHED 
	while(*((volatile uint8_t*)ADC_CREG) & (1<<6));   
	
	return *((volatile uint16_t*)ADC_L)  ;
	//dtostrf((float)(ADC_Read(0)*5)/1024,4,2,str);
}


//sprintf(str,"%3d",(ADCH*5)/255);
//dtostrf((float)((ADCL+ADCH*256)*500)/1024,4,2,str);       //ok ----10 BIT precision  ADLRA=0
//dtostrf((float)(ADCH*500)/256,4,2,str);                  //ok ----8 BIT precision  ADLRA=1  
//dtostrf((float)((ADCL/64+ADCH*4)*500)/1024,4,2,str);    //ok ----10 BIT precision  ADLRA=1
