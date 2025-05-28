/*
 * UART.c
 *
 * Created: 9/22/2023 8:19:53 AM
 *  Author: Hossam Mahmoud
 */ 
#include "UART.h"
#include <avr/io.h>

void USART_Init( unsigned int baud )
{
	/* Set baud rate */
	UBRR0H = (unsigned char)(baud>>8);
	UBRR0L = (unsigned char)baud;
	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 8data, 1stop bit */
	UCSR0C = (0<<USBS0)|(3<<UCSZ00);
	
	/**********************************************************/
		/* Set baud rate */
		UBRR1H = (unsigned char)(baud>>8);
		UBRR1L = (unsigned char)baud;
		/* Enable receiver and transmitter */
		UCSR1B = (1<<RXEN1)|(1<<TXEN1);
		/* Set frame format: 8data, 1stop bit */
		UCSR1C = (0<<USBS1)|(3<<UCSZ10);
}
/****************************************************************************************************/
void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) )
                  	;
	/* Put data into buffer, sends the data */
	UDR0 = data;
}

void USART_Transmit1( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR1A & (1<<UDRE1)) )
	            ;
	/* Put data into buffer, sends the data */
	UDR1 = data;
}
/****************************************************************************************************/
unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) )
	;
	/* Get and return received data from buffer */
	return UDR0;
}

unsigned char USART_Receive1( void )
{
	/* Wait for data to be received */
	while ( !(UCSR1A & (1<<RXC1)) )
	;
	/* Get and return received data from buffer */
	return UDR1;
}
/****************************************************************************************************/
void UART_SendString(char *str)
{
	unsigned char j=0;
	
	while (str[j]!=0)		/* Send string till null */
	{
		USART_Transmit(str[j]);	
		j++;
	}
}

void UART_SendString1(char *str)
{
	unsigned char j=0;
	
	while (str[j]!=0)		/* Send string till null */
	{
		USART_Transmit1(str[j]);
		j++;
	}
}