/*
 * Lcd.h
 *
 * Created: 9/22/2023 3:41:31 PM
 *  Author: MOHAMED SALAH FATHY
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "GPIO_Driver.h"
#define LCD_DATA_PORT GPIOA
#define LCD_CONTROL_PORT GPIOB
#define First_Data_PIN PIN_4
#define Last_Data_PIN PIN_7
#define RS_PIN		PIN_1
#define RW_PIN		PIN_2
#define EN_PIN		PIN_3
#define First_Control_PIN PIN_1
#define Last_Control_PIN PIN_3
#define LCD_FUNCTION_8BIT_2LINES     (0x38)
#define LCD_FUNCTION_4BIT_2LINES     (0x28)
#define LCD_MOVE_DISP_RIGHT          (0x1C)
#define LCD_MOVE_DISP_LEFT           (0x18)
#define LCD_MOVE_CURSOR_RIGHT        (0x14)
#define LCD_MOVE_CURSOR_LEFT         (0x10)
#define LCD_DISP_OFF                 (0x08)
#define LCD_DISP_ON_CURSOR           (0x0E)
#define LCD_DISP_ON_CURSOR_BLINK     (0x0F)
#define LCD_DISP_ON_BLINK            (0x0D)
#define LCD_DISP_ON                  (0x0C)
#define LCD_ENTRY_DEC                (0x04)
#define LCD_ENTRY_DEC_SHIFT          (0x05)
#define LCD_ENTRY_INC                (0x06)
#define LCD_ENTRY_INC_SHIFT          (0x07)
#define LCD_BEGIN_AT_FIRST_ROW       (0x80)
#define LCD_BEGIN_AT_SECOND_ROW      (0xC0)
#define LCD_CLEAR                    (0x01)
#define LCD_ENTRY_MODE               (0x06)
#define FOUR_BIT_MODE
void LCD_init(void);
void LCD_clear_screen(void);
void LCD_send_command(uint8 command);
void LCD_Send_a_charachter(const uint8 character);
void LCD_Send_String(const uint8  *string);
void LCD_MOVE_CURSOR_XY(uint8 line , uint8 pos);
void wait_ms(uint32 time);
uint8 Get_command_bit(uint8 command,uint8 bit_num);
#endif /* LCD_H_ */