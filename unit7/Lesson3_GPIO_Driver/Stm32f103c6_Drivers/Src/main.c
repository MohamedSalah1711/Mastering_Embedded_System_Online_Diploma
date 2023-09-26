/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
#include "Stm32f103x6.h"
#include "Stm32f103C6_Driver_gpio.h"
#include "Platform_Types.h"
void clock_init();
void GPIO_init();
void wait_ms(uint32 ms);
int main(void)
{
	clock_init();
	GPIO_init();
	while(1){
		if ((MCAL_GPIO_ReadPin(GPIOA,PIN_1)) == 0){
			MCAL_GPIO_TogglePin(GPIOB,PIN_1);
			while((MCAL_GPIO_ReadPin(GPIOA,PIN_1)) == 0);


		}
		if((MCAL_GPIO_ReadPin(GPIOA,PIN_13)) == 1){
			MCAL_GPIO_TogglePin(GPIOB,PIN_13);
			wait_ms(3);
		}


		wait_ms(3);


	}


}
void clock_init(){
	//ENABLE GPIOA AND GPIOB
	ENABLE_CLOCK_GPIOA();
	ENABLE_CLOCK_GPIOB();
}
void GPIO_init(){
	//PIN 0 >>>PORTA >>>INPUT FLOATING
	//10MHZ SPEED GPIO
	GPIO_PIN_Config PIN_Config;
	PIN_Config.Pin_Num = PIN_1;
	PIN_Config.Mode = Floating_Mode;
	MCAL_GPIO_Init(GPIOA,&PIN_Config);
	//PIN 1 >>>PORTB >>>OUTPUT PUSH-PULL
	//10MHZ SPEED GPIO
	PIN_Config.Pin_Num = PIN_1;
	PIN_Config.Mode = OUTPUT_PP;
	PIN_Config.speed = Max_speed_10MHZ;
	MCAL_GPIO_Init(GPIOB,&PIN_Config);
	//PIN 13 >>>PORTA >>>INPUT FLOATING
	//10MHZ SPEED GPIO
	PIN_Config.Pin_Num = PIN_13;
	PIN_Config.Mode = Floating_Mode;
	MCAL_GPIO_Init(GPIOA,&PIN_Config);
	//PIN 13 >>>PORTB >>>INPUT FLOATING
	//10MHZ SPEED GPIO
	PIN_Config.Pin_Num = PIN_13;
	PIN_Config.Mode = OUTPUT_PP;
	PIN_Config.speed = Max_speed_10MHZ;
	MCAL_GPIO_Init(GPIOB,&PIN_Config);
}
void wait_ms(uint32 ms){
	uint32 i,j;

	for(i=0; i<255 ; i++){
		for(j=0 ; j<ms;j++){

		}


	}


}