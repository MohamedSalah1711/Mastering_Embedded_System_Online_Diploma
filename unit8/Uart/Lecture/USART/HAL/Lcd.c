/*
 * Lcd.c
 *
 * Created: 9/22/2023 4:43:39 PM
 *  Author: mohamed salah
 */ 
#include "Lcd.h"
void wait_ms(uint32 time){
	uint32 i,j;
	for(i=0 ; i<time ; i++){

		for(j = 0; j<255; j++){

		}
	}


}
void LCD_init(void){
	uint8 count;
	GPIO_PIN_Config Pin_Config;
	wait_ms(40);
	//make the data port output GP PUSH_PULL
	for(count = First_Data_PIN ; count <= Last_Data_PIN ;count++ ){
		Pin_Config.Mode = OUTPUT_PP;
		Pin_Config.Pin_Num = count;
		Pin_Config.speed = Max_speed_10MHZ;
		MCAL_GPIO_Init(LCD_DATA_PORT,&Pin_Config);
	}
	//make the control port output GP PUSH_PULL
	for(count = First_Control_PIN ; count <= Last_Control_PIN ;count++ ){
		Pin_Config.Mode = OUTPUT_PP;
		Pin_Config.Pin_Num = count;
		Pin_Config.speed = Max_speed_10MHZ;
		MCAL_GPIO_Init(LCD_CONTROL_PORT,&Pin_Config);
	}

	//write zero to control pins
	for(count = First_Control_PIN ; count <= Last_Control_PIN ;count++ ){

		MCAL_GPIO_WritePin(LCD_CONTROL_PORT,count,PIN_LOW);
	}
	wait_ms(20);

#ifdef FOUR_BIT_MODE
	LCD_send_command(0x32);
	LCD_send_command(LCD_FUNCTION_4BIT_2LINES);	

#endif

	LCD_send_command(LCD_DISP_ON_CURSOR_BLINK);
	LCD_clear_screen();
	LCD_send_command(LCD_ENTRY_MODE);
}
void LCD_send_command(uint8 command){
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,RW_PIN,PIN_LOW);
	wait_ms(2);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,RS_PIN,PIN_LOW);
	wait_ms(2);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,First_Data_PIN,Get_command_bit(command,4));
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,First_Data_PIN+1,Get_command_bit(command,5));
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,First_Data_PIN+2,Get_command_bit(command,6));
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,First_Data_PIN+3,Get_command_bit(command,7));
	wait_ms(2);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,EN_PIN,PIN_HIGH);
	wait_ms(2);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,EN_PIN,PIN_LOW);
	wait_ms(2);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,First_Data_PIN,Get_command_bit(command,0));
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,First_Data_PIN+1,Get_command_bit(command,1));
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,First_Data_PIN+2,Get_command_bit(command,2));
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,First_Data_PIN+3,Get_command_bit(command,3));
	wait_ms(2);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,EN_PIN,PIN_HIGH);
	wait_ms(2);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,EN_PIN,PIN_LOW);
	wait_ms(1);
}
void LCD_clear_screen(void){
	LCD_send_command(LCD_CLEAR);
}
void LCD_Send_a_charachter(const uint8 character){
#ifdef FOUR_BIT_MODE
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,RW_PIN,PIN_LOW);
	wait_ms(2);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,RS_PIN,PIN_HIGH);
	wait_ms(2);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,First_Data_PIN,(Get_command_bit(character,4)));
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,First_Data_PIN+1,Get_command_bit(character,5));
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,First_Data_PIN+2,Get_command_bit(character,6));
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,First_Data_PIN+3,Get_command_bit(character,7));
	wait_ms(2);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,EN_PIN,PIN_HIGH);
	wait_ms(2);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,EN_PIN,PIN_LOW);
	wait_ms(1);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,First_Data_PIN,Get_command_bit(character,0));
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,First_Data_PIN+1,Get_command_bit(character,1));
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,First_Data_PIN+2,Get_command_bit(character,2));
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,First_Data_PIN+3,Get_command_bit(character,3));
	wait_ms(2);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,EN_PIN,PIN_HIGH);
	wait_ms(2);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT,EN_PIN,PIN_LOW);
	wait_ms(1);
#endif

}
void LCD_Send_String(const uint8  *string){
	uint8 i=0;
	while(string[i] != '\0'){
		LCD_Send_a_charachter(string[i]);
		i++;	
		if(i == 16){
			LCD_MOVE_CURSOR_XY (1 , 0);

		}else if ( i== 32 || i== 33){
			LCD_clear_screen();
			LCD_MOVE_CURSOR_XY(0,0);
			i=0;
		}

	}


}
void LCD_MOVE_CURSOR_XY(uint8 line , uint8 pos){
	if(line==0){
		if(pos < 16 && pos >= 0){
			LCD_send_command(LCD_BEGIN_AT_FIRST_ROW + pos);

		}

	}else if (line == 1 ){

		if(pos < 16 && pos >= 0){
			LCD_send_command(LCD_BEGIN_AT_SECOND_ROW + pos);

		}

	}


}
uint8 Get_command_bit(uint8 command,uint8 bit_num){

	return (((command)>>(bit_num))&(1U));

}
