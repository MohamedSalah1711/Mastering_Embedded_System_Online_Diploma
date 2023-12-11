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

#define MCU_Act_As_Master

#include "Stm32f103x6.h"
#include "Stm32F103C6_EXTI_Driver.h"
#include "Stm32f103C6_Driver_USART.h"
#include "Stm32f103C6_Driver_gpio.h"
#include "Stm32f103C6_Driver_SPI.h"
#include "Lcd.h"
void Enable_Clock(){
	ENABLE_CLOCK_GPIOA();
	ENABLE_CLOCK_GPIOB();
	ENABLE_CLOCK_AFIO();
}
uint8 ch;
void UART_IRQ_CallBack(void){
#ifdef MCU_Act_As_Master
	MCAL_USART_ReceiveData(USART1, &ch, Enable);
	MCAL_USART_Send_Data(USART1, &ch, Disable);
	//Send SPI
	MCAL_GPIO_WritePin(GPIOA ,PIN_4,0);
	MCAL_SPI_TX_RX(SPI1,&ch,Polling);
	MCAL_GPIO_WritePin(GPIOA ,PIN_4,1 );

#endif
}
int main(void)
{
	GPIO_PIN_Config Pin_config;
	Enable_Clock();
	//UART INIT
	USART_Pin_Config USART_Config={Eight_Bit,One_Bit,Both,Baud_Rate_115200,Enable,Interrupt_RXNEIE_Enable,none,NONE,UART_IRQ_CallBack};
	MCAL_USART_Init(USART1, &USART_Config);
	MCAL_USART_GPIO_Set_Pins(USART1);
	//SPI_INIT
	SPI_Config SPI1_Config;
	//Common configuration
	SPI1_Config.Phase = Second_Edge;
	SPI1_Config.Polarity = Idle_One;
	SPI1_Config.Format = EIGHT_BITS;
	SPI1_Config.Endian_Format = MSB;
	SPI1_Config.BaudRate = fPCLK_8;
	//Master Configuration
#ifdef MCU_Act_As_Master
	SPI1_Config.Mode = Master;
	SPI1_Config.Interrupt_Pooling = Polling;
	SPI1_Config.Nss_mode = SoftWare;
	SPI1_Config.Pin_Mode = Input;
	SPI1_Config.P_CallBack = NULL;
#endif
	MCAL_SPI_Init(SPI1, &SPI1_Config);
	MCAL_SPI_GPIO_Set_Pins(SPI1);

	//Configre slave select on porta pin4 by gpio
	Pin_config.Mode = OUTPUT_PP;
	Pin_config.speed = Max_speed_10MHZ;
	Pin_config.Pin_Num = PIN_4;
	MCAL_GPIO_Init(GPIOA,&Pin_config);
	//Force slave select idle mode high
	MCAL_GPIO_WritePin(GPIOA ,PIN_4,1 );

	while(1){

	}
}
