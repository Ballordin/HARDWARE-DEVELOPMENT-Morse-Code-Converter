#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <avr/interrupt.h>

#include "UART.h"

#define LED PD7
#define PWM_PIN PB1
#define ON 1
#define OFF 0

extern volatile uint8_t tone;

void GPIO_init();
void setup_pwm();
void turn_on_off_PWM(bool is_on);
void change_tone();
void debug( unsigned int ciclos);
void convertToMorse(char character);

extern bool MORSE;		//valor 0 envia LED, valor 1 envia buzzer
extern bool INF;	//0 envia temperatura, 1 envia char
extern bool MODO;	//0 envia temperatura MORSE, 1 envia temperatura porta serie

extern const char *morseCode[];

#endif