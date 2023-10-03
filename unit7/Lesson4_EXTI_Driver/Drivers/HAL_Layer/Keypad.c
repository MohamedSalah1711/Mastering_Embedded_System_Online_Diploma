/*
 * Keypad.c
 *
 * Created: 9/23/2023 2:38:54 AM
 *  Author: LEGION
 */ 
#include "Keypad.h"
uint8 Keypad_Row[Number_Of_Row] = {PIN_0,PIN_1,PIN_3,PIN_4};
uint8 Keypad_Cols[Number_Of_COls] = {PIN_5,PIN_6,PIN_7,PIN_8};
uint8 keys_char[Number_Of_Row][Number_Of_COls]={
		{'7','8','9','/'},
		{'4','5','6','X'},
		{'1','2','3','-'},
		{' ','0','=','+'}
};

void KEYPAD_init(void){
	uint8 i;
	//Configure ROWS PINS AS INPUT PULL UP
	GPIO_PIN_Config PIN_Config={Keypad_Row[0],Max_speed_10MHZ,Input_PD};
	for(i = 0 ; i<Number_Of_Row ; i++){
		PIN_Config.Pin_Num=Keypad_Row[i];
		MCAL_GPIO_Init(KEYPAD_PORT,&PIN_Config);
	}
	//Configure Cols PINS AS OUTPUT PP
	PIN_Config.Mode=OUTPUT_PP;
	for(i = 0 ; i<Number_Of_COls ; i++){
		PIN_Config.Pin_Num=Keypad_Cols[i];
		MCAL_GPIO_Init(KEYPAD_PORT,&PIN_Config);
	}
}
char KEYPAD_get_pressed(void){
	uint8 cols,rows,count;
	//Write Logic High for all Coloumns PINs (Due to pull up resist on rows)
	//iterate zero for coloums pins and check for pressing
	for(cols = 0 ; cols < Number_Of_COls ; cols++ ){
		for(count = 0 ; count < Number_Of_COls ; count++){
			MCAL_GPIO_WritePin(KEYPAD_PORT,Keypad_Cols[count],PIN_LOW);
		}
		MCAL_GPIO_WritePin(KEYPAD_PORT,Keypad_Cols[cols],PIN_HIGH);
		for(rows = 0 ; rows < Number_Of_Row ; rows++){
			if ((MCAL_GPIO_ReadPin(KEYPAD_PORT,Keypad_Row[rows]))){
				while((MCAL_GPIO_ReadPin(KEYPAD_PORT,Keypad_Row[rows])));
				return keys_char[rows][cols];
			}
		}
	}
	return 'N';
}
