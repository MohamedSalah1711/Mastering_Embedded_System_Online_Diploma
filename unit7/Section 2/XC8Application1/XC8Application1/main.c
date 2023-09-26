/*
 * main.c
 *
 * Created: 9/22/2023 3:37:04 PM
 *  Author: LEGION
 */ 
#include "Lcd.h"
int main(void)
{  
	KEYPAD_init();
	LCD_init();
	uint8_t key_pressed;
    while(1)
    {
    key_pressed= KEYPAD_get_pressed();
	if(key_pressed!= 'N'){LCD_Send_a_charachter(key_pressed);}
	
    }
}