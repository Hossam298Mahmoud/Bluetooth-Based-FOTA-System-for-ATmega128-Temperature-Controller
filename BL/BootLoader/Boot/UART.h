/*
 * UART.h
 *
 * Created: 9/22/2023 8:11:34 AM
 *  Author: Hossam Mahmoud
 */ 


#ifndef UART_H_
#define UART_H_

#define F_CPU 8000000UL		/* Define frequency here its 8MHz */
#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)


void USART_Init( unsigned int baud );

void USART_Transmit( unsigned char data );

unsigned char USART_Receive( void );

void UART_SendString(char *str);

#endif /* UART_H_ */