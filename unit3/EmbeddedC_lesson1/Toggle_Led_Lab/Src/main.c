/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed salah fahty
 * @brief          : Main program body
 ******************************************************************************
*/
#include "Platform_Types.h"
#include "Register.h"

int main(void)
{
	APB2ENR_REG|=(1<<2); /*Enable Rcc for gpio*/
	CRH_Register &= 0xFF0FFFFF;
	CRH_Register |= (2<<20);
	while(1){
		GPIOA_ODR_Register|=(1<<13);
		for(int i=0;i<5000;i++);
		GPIOA_ODR_Register&=~(1<<13);
		for(int i=0;i<5000;i++);
	}

	return 0;
}
