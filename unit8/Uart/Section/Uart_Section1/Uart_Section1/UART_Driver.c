/*
 * File Name :UART_Driver.c
 * Learn-In-Depth,
 * Author: mohamed salah
 */ 
#include "UART_Driver.h"

void UART_init(UART_ConfigType* Uart_Config){
	uint16 UBRR_Value=0; /*Storing Value OF UBRR register*/
	/*Asynchronous MODE SELECT*/
	UCSRC |= (1<<7);
	UCSRC |= (Uart_Config->Mode << 6);
	/*Parity Mode*/
	UCSRC |= (Uart_Config->Parity << 4);
	/*Stop bit select*/
	UCSRC |= (Uart_Config->Stop_Bit << 3);
	/*Make UCSZ1:0 zero*/
	UCSRC &=~ (0b11<<1);
	/*choose data size*/
	UCSRC |= (Uart_Config->Size<<1);
	if(Uart_Config->Size == Nine_bit){
		UCSRB |= (1<<2);
	}
	/*Baud Rate equation*/
	UBRR_Value = (uint16)round((F_CPU/(16*Uart_Config->Baud_Rate)))-1;
	UBRRL = ((UBRR_Value & 0X00FF));
	/*Select UBRRH*/
	UBRRH &=~ (1<<15);
	UBRRH |= ((UBRR_Value & 0XFF00)>>8);
	/*Enable Receive and transmit*/
	UCSRB |= (0b11<<3);
	
}
void UART_Deinit(void){
	UDR = 0X00;
	UCSRA = 0X20;
	UCSRB = 0X00;
	UCSRC = 0X86;
	UBRRL = 0x00;
	UBRRH = 0x00;
}
void UART_SendCharacter(uint8 character){
	while(!((UCSRA >> 5) & (1u)));
	UDR = character;
	while(!((UCSRA >> 6) & (1u)));
}
void UART_SendString(uint8* String){
	uint32 count=0;
	while(String[count] != '$'){
		UART_SendCharacter(String[count]);
		count++;	
	}
}
uint8 UART_ReceiveCharacter(void){
	while(!((UCSRA >> 7) & (1u)));
	return UDR;
}
void UART_ReceiveString(uint8* string){
	uint8 count=0;
	while(string[count]!= '$'){
		string[count] =UART_ReceiveCharacter();
		count++; 
	}
}