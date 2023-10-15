/*
 * File Name :GPIO_Driver.c
 * Learn-In-Depth,
 * Author: mohamed salah
 */ 
#include "GPIO_Driver.h"

void MCAL_GPIO_Init(GPIO_typedef* GPIOx,GPIO_PinConfig* Pin_Config){
	if(Pin_Config->Mode == output_mode){
		GPIOx->DDRx_Port |= (1<<Pin_Config->PIN_NUM);
		if(Pin_Config->Pin_State == PIN_HIGH){
			GPIOx->PORTx_Port |= (1<<Pin_Config->PIN_NUM);
		}else{
			GPIOx->PORTx_Port &= ~(1<<Pin_Config->PIN_NUM);
		}
	}else{
		GPIOx->DDRx_Port &= ~(1<<Pin_Config->PIN_NUM);
		if(Pin_Config->PUD == Input_NoPullup){
			GPIOx->PORTx_Port &= ~(1<<Pin_Config->PIN_NUM);
			}else{
			GPIOx->PORTx_Port |= (1<<Pin_Config->PIN_NUM);
		}
	}
}
uint8 MCAL_GPIO_ReadPin(GPIO_typedef* GPIOx,uint8 Pin_Num){
	
	return ((GPIOx->PINx_Port>>Pin_Num) & (1u));
	
}
uint8 MCAL_GPIO_ReadPort(GPIO_typedef* GPIOx){
	
	return (GPIOx->PINx_Port);
}
void MCAL_GPIO_WritePin(GPIO_typedef* GPIOx,uint8 Pin_Num,uint8 value){
	if(value == PIN_LOW){
		GPIOx->PORTx_Port &=~ (1<<Pin_Num);
	}else{
		GPIOx->PORTx_Port |= (1<<Pin_Num);
	}
	
}
void MCAL_GPIO_WritePort(GPIO_typedef* GPIOx,uint8 value){
	
	GPIOx->PORTx_Port = value;
	
}