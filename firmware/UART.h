#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100

//extern volatile char receivedData[];
//extern volatile uint8_t bufferIndex;
extern volatile uint8_t tone;

void UART_init(unsigned int baud_rate);
void UART_putc(unsigned char data);
void UART_puts(char* s);
void UART_putU8(uint8_t val);

