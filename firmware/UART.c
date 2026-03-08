#include "UART.h"

#define BAUDRATE 9600
#define FOSC 8000000UL
#define UBRR_VALUE ((FOSC / (BAUDRATE * 16UL)) - 1)


void UART_init(unsigned int baud_rate){
		UCSR0A = 0x00;
		UCSR0B = (1<<RXEN0) | (1<<RXCIE0)| (1<<TXEN0);
		UCSR0C = (1<<UCSZ01)| (1<<UCSZ00);
		UBRR0H= (UBRR_VALUE>>8);
		UBRR0L= UBRR_VALUE;
}
void UART_putc( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) )
	;
	/* Put data into buffer, sends the data */
	UDR0 = data;
}

void UART_puts(char* s){
	while (*s != '\0')
	{
		UART_putc(*s);
		*s++;
	}
}
void UART_putU8(uint8_t val){
	uint8_t dig1 = '0', dig2 = '0';
	// count value in 100s place
	while(val >= 100){
		val -= 100;
		dig1++;
	}

	// count value in 10s place
	while(val >= 10)
	{
		val -= 10;
		dig2++;
	}

	// print first digit (or ignore leading zeros)
	if(dig1 != '0') UART_putc(dig1);

	// print second digit (or ignore leading zeros)
	if((dig1 != '0') || (dig2 != '0')) UART_putc(dig2);

	// print final digit
	UART_putc(val + '0');
}
