#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#include "GPIO.h"

void GPIO_init(){
	// Set the LED as output
	DDRD |= (1 << LED) | (1 << PD6);
}

void setup_pwm(){
	// Set the pwm pin as output
	DDRB |= (1<<PWM_PIN);
	// Toggle OC1A/OC1B on compare match; Set FAST-PWM Mode
	TCCR1A |= (1 << COM1A0) | (1 << WGM11) | (1 << WGM10);
	TCCR1B |= (1 << WGM13) | (1 << WGM12);
	// Clock Select Bit Description - 64 bit prescaler
	// frequency = 16 000 000 / 64 = 250k
	TCCR1B |= (1 << CS11) | (1 << CS10);
	OCR1A = 100; //(expected 2.5 kHz)
}

void turn_on_off_PWM(bool is_on){
	if(is_on){
		// Code
		TCCR1A |= (1 << COM1A0);
		OCR1A = tone;
		} else {
		// Code
		TCCR1A &= ~(1 << COM1A0);
	}
}


void change_tone(){
	OCR1A = tone;
}

//-----//-----

void debug( unsigned int ciclos){
	
	while (ciclos>0)
	{
		PORTD |= (1 << PORTD7); // LED ON
		_delay_ms(3000);      // Dash duration
		PORTD &= ~(1 << PORTD7); // LED OFF
		_delay_ms(3000);      // Dash duration
		ciclos--;
	}
}

//converter para Morse
void convertToMorse(char character) {
	UART_putc('#');
	UART_puts((char *)"Inside convert morse to convert: ");
	UART_putc(character);
	UART_putc('\n');
	// Convert uppercase letter or number to Morse code
	int index;
	if (character >= 'A' && character <= 'Z') {
		index = character - 'A';
	} else if (character >= 'a' && character <= 'z') {
		index = character - 'a'; // Add the correct offset for lowercase letters
	} else if (character >= '0' && character <= '9') {
		index = character - '0' + 26;
	} else {
		// Character is not a valid uppercase letter or number, ignore or handle accordingly
		return;
	}
	// Loop through each Morse code symbol
	for (int i = 0; morseCode[index][i] != '\0'; i++) {
		// Blink the LED according to the Morse code
		if (morseCode[index][i] == '.') {
			if (MORSE==0){
				
				PORTD &= ~(1 << PORTD6); // LED ON
				}else{
				turn_on_off_PWM(1);
			}
			_delay_ms(200);      // Dot duration
			} else if (morseCode[index][i] == '-') {
			if (MORSE==0){
				PORTD &= ~(1 << PORTD6); // LED ON
				}else{
				turn_on_off_PWM(1);
			}
			_delay_ms(600);      // Dash duration
		}


		PORTD |= (1 << PORTD6); // LED OFF
		turn_on_off_PWM(0);
		_delay_ms(50);       // Inter-symbol gap
	}

	_delay_ms(750); // Inter-character gap
}

const char *morseCode[] = {
	".-",   // A
	"-...", // B
	"-.-.", // C
	"-..",  // D
	".",    // E
	"..-.", // F
	"--.",  // G
	"....", // H
	"..",   // I
	".---", // J
	"-.-",  // K
	".-..", // L
	"--",   // M
	"-.",   // N
	"---",  // O
	".--.", // P
	"--.-", // Q
	".-.",  // R
	"...",  // S
	"-",    // T
	"..-",  // U
	"...-", // V
	".--",  // W
	"-..-", // X
	"-.--", // Y
	"--..", // Z
	"-----", // 0
	".----", // 1
	"..---", // 2
	"...--", // 3
	"....-", // 4
	".....", // 5
	"-....", // 6
	"--...", // 7
	"---..", // 8
	"----."  // 9
};