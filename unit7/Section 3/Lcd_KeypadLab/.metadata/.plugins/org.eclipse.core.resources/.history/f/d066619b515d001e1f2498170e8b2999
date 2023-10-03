/*
 * Keypad.h
 *
 * Created: 9/23/2023 2:38:45 AM
 *  Author: LEGION
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include <avr/io.h>
#define F_CPU 8000000UL
#include <avr/delay.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#define KEYPAD_PORT PORTC
#define FIRST_PIN_ROW PB4 //vcc output
#define FIRST_PIN_COL PB0 //input
#define KEYPAD_PORT_DIR DDRC
#define KEYPAD_READ_DATA PINC
void KEYPAD_init(void);
char KEYPAD_get_pressed(void);
#endif /* KEYPAD_H_ */