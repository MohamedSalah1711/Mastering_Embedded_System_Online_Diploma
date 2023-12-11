/*
 * HC-05.c
 *
 *  Created on: Dec 5, 2023
 *      Author: mohamed salah
 */
#include "HC-05.h"
uint16 Received_char=0;
void HAL_HC05_Init(){
	ENABLE_CLOCK_GPIOA();
	ENABLE_CLOCK_AFIO();
	ENABLE_CLOCK_GPIOB();
	USART_Pin_Config USART_CON={Eight_Bit,One_Bit,Both,Default_Baud,Enable,Interrupt_RXNEIE_Enable,none,NONE,HAL_HC05_RecieveChar};
	MCAL_USART_Init(Bluetooth_Uart, &USART_CON);

}
void HAL_HC05_RecieveChar(void){
	MCAL_USART_ReceiveData(Bluetooth_Uart,&Received_char,Enable);
}
