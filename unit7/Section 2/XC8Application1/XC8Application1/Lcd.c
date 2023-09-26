/*
 * Lcd.c
 *
 * Created: 9/22/2023 4:43:39 PM
 *  Author: mohamed salah
 */ 
#include "Lcd.h"

void LCD_init(void){
	_delay_ms(40);	
	LCD_DATA_DIR = 0xff;
	LCD_CONTROL_DIR |= (1<<RS_PIN) | (1<<RW_PIN) | (1<<EN_PIN);
	LCD_CONTROL_PORT &=~ ((1<<RS_PIN)|(1<<RW_PIN)|(1<<EN_PIN));
	_delay_ms(20);
	
	#ifdef FOUR_BIT_MODE
	LCD_send_command(0x32);
	LCD_send_command(LCD_FUNCTION_4BIT_2LINES);	
	
	#endif
	
	LCD_send_command(LCD_DISP_ON_CURSOR_BLINK);
	LCD_clear_screen();
	LCD_send_command(LCD_ENTRY_MODE);
}
void LCD_send_command(uint32_t command){
	
	
	
	
	LCD_CONTROL_PORT &=~ (1<<RW_PIN);
	_delay_ms(2);
	LCD_CONTROL_PORT &=~ (1<<RS_PIN);
	_delay_ms(2);
	LCD_DATA_PORT = (LCD_DATA_PORT & 0X0F) | (command & 0XF0);
	_delay_ms(2);
	LCD_CONTROL_PORT &=~ (1<<EN_PIN);
	_delay_ms(2);
	LCD_CONTROL_PORT |= (1<<EN_PIN);
	_delay_ms(1);
	LCD_CONTROL_PORT &=~ (1<<RS_PIN);
	_delay_ms(2);
	LCD_CONTROL_PORT &=~ (1<<RW_PIN);
	_delay_ms(2);
	LCD_DATA_PORT = (LCD_DATA_PORT & 0X0F) | (command << 4);
	_delay_ms(2);
	LCD_CONTROL_PORT &=~ (1<<EN_PIN);
	_delay_ms(1);
	LCD_CONTROL_PORT |= (1<<EN_PIN);
	
	
}
void LCD_clear_screen(void){
	LCD_send_command(LCD_CLEAR);
}
void LCD_Send_a_charachter(const uint8_t character){
	#ifdef FOUR_BIT_MODE
	LCD_CONTROL_PORT |= (1<<RS_PIN);
	_delay_ms(2);
	LCD_CONTROL_PORT &=~ (1<<RW_PIN);
	_delay_ms(2);
	LCD_DATA_PORT = (LCD_DATA_PORT & 0X0F) | (character & 0XF0);
	_delay_ms(2);
	LCD_CONTROL_PORT &=~ (1<<EN_PIN);
	_delay_ms(2);
	LCD_CONTROL_PORT |= (1<<EN_PIN);
	_delay_ms(2);
	LCD_CONTROL_PORT |= (1<<RS_PIN);
	_delay_ms(2);
	LCD_CONTROL_PORT &=~ (1<<RW_PIN);
	_delay_ms(2);
	LCD_DATA_PORT = (LCD_DATA_PORT & 0X0F) | (character << 4);
	_delay_ms(2);
	LCD_CONTROL_PORT &=~ (1<<EN_PIN);
	_delay_ms(2);
	LCD_CONTROL_PORT |= (1<<EN_PIN);
	#endif
	
}
void LCD_Send_String(const uint8_t  *string){
	uint8_t i=0;
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
void LCD_MOVE_CURSOR_XY(uint8_t line , uint8_t pos){
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