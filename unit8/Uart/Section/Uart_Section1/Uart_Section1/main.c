/*
 * File Name :main.c
 * Learn-In-Depth,
 * Author: mohamed salah
 */ 

#include "GPIO_Driver.h"
#include "UART_Driver.h"
#include "Lcd.h"
int main(void)
{
	UART_ConfigType Config_Uart = {Asynchronous,Disabled,One_bit,Eight_bit,Baud_Rate_9600};
	UART_init(&Config_Uart);
	UART_SendCharacter('a');
    while(1)
    {
		
    }
}