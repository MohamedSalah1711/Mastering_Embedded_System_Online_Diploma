/*
 * Keypad.h
 *
 * Created: 9/23/2023 2:38:45 AM
 *  Author: LEGION
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "Stm32f103C6_Driver_gpio.h"
#define KEYPAD_PORT GPIOB
#define Number_Of_Row 4
#define Number_Of_COls 4

#define FIRST_PIN_ROW PIN_0 //vcc output
#define FIRST_PIN_COL PIN_5 //input
void KEYPAD_init(void);
char KEYPAD_get_pressed(void);
#endif /* KEYPAD_H_ */
