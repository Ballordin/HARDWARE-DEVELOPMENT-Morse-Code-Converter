#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <stdbool.h>
#include <string.h>

/* Custom Modules  */
#include "UART.h"
#include "GPIO.h"

/* End of Custom Modules */


/* Global Vars */
volatile char receivedData[MAX_BUFFER_SIZE];
volatile uint8_t bufferIndex = 0;
volatile uint8_t tone = 100;
bool MORSE = true;

bool cleanstring;
volatile uint8_t sendstring = 0;
/* End Global Vars */
ISR(USART_RX_vect){
	char data = UDR0;

	// Check if buffer is not full
	if (bufferIndex < MAX_BUFFER_SIZE) {
		receivedData[bufferIndex] = data;
		bufferIndex++;
	}
}

int main()
{
	
	_delay_ms(1000);
	
	GPIO_init();
	setup_pwm();
	turn_on_off_PWM(ON);
	UART_init(0);
	UART_putc('D');
	_delay_ms(1000);
	turn_on_off_PWM(OFF);
	char enviarmorse[] = "A enviar MORSE\n";
	char buffer_msg[] = "Buffer has smth      \n";
	sei(); // Set interrupts //
	while(1) {
		UART_puts(enviarmorse);
		if (bufferIndex > 0) // Something on the buffer
		{
			UART_puts(buffer_msg);
			turn_on_off_PWM(OFF);
			sendstring = 1;
			cleanstring = true;
			//debug(3);
				
			for (uint8_t ix = 0; ix < bufferIndex; ix++){
				char letter = receivedData[ix];
				switch (letter) {
					case '!':		//envio do codigo MORSE atraves do buzzer
						MORSE = !MORSE;
					break;
					case '-':		//varia entre porta serie ou temperatura
						//INF = !INF;
					break;
					case '&':		//enviar temperatura codigo Morse, ou porta serie
						//MODO = !MODO;
					break;
					case '\r':
						break;		
					default:
						// MORSE(letter)
						convertToMorse((letter));
					break;
				} // End of Switch
			} // End of for loop
			bufferIndex = 0;
			UART_puts((char *)receivedData);
		} // End of if uart buffer is filled

		// Medir temperatura
		// Enviar temperatura por UART
		_delay_ms(1000);
		turn_on_off_PWM(OFF);
	}
	return 0;
}

