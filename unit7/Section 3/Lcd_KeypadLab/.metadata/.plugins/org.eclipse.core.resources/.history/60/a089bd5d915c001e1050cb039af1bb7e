/*
 * Keypad.c
 *
 * Created: 9/23/2023 2:38:54 AM
 *  Author: LEGION
 */ 
#include "Keypad.h"
uint8_t keys_char[4][4]={
	{'7','8','9','/'},
	{'4','5','6','X'},
	{'1','2','3','-'},
	{' ','0','=','+'}
};
void KEYPAD_init(void){
	// first 4 pin as input and second for pin as output
	KEYPAD_PORT_DIR = 0XF0;
	KEYPAD_PORT = 0XFF; //VCC FOR ROWS
	
}
char KEYPAD_get_pressed(void){
	int ROW,COLS;
	for(COLS =0 ; COLS<4 ;COLS ++){
		KEYPAD_PORT |= 0XF0;
		KEYPAD_PORT &=~ (1<<(COLS+4));
		for(ROW = 0 ; ROW < 4 ; ROW++){
		if(!(KEYPAD_READ_DATA & (1<<ROW))){
			while(!(KEYPAD_READ_DATA & (1<<ROW)));
			return keys_char[ROW][COLS];
		}	
		
			
			
			
		}
	}
	return 'N';
}