/*
 * File Name :GPIO_Driver.c
 * Learn-In-Depth,
 * Author: mohamed salah
 */ 
#include "GPIO_Driver.h"

void MCAL_GPIO_Init(GPIO_typedef* GPIOx,GPIO_PinConfig* Pin_Config){
	GPIO_typedef* Port=NULL;
	Port = GPIOx;
	if(Pin_Config->Mode == output_mode){
		Port->DDRx_Port |= (1<<Pin_Config->PIN_NUM);
		if(Pin_Config->Pin_State == PIN_HIGH){
			Port->PORTx_Port |= (1<<Pin_Config->PIN_NUM);
		}else{
			Port->PORTx_Port &= ~(1<<Pin_Config->PIN_NUM);
		}
	}else{
		Port->DDRx_Port &= ~(1<<Pin_Config->PIN_NUM);
		if(Pin_Config->PUD == Input_NoPullup){
			Port->PORTx_Port &= ~(1<<Pin_Config->PIN_NUM);
			}else{
			Port->PORTx_Port |= (1<<Pin_Config->PIN_NUM);
		}
	}
}
uint8 MCAL_GPIO_ReadPin(GPIO_typedef* GPIOx,uint8 Pin_Num){
	
	return ((GPIOx->PINx_Port>>Pin_Num) & (1u));
	
}
uint8 MCAL_GPIO_ReadPort(GPIO_typedef* GPIOx){
	
	return (GPIOx->PINx_Port);
}
