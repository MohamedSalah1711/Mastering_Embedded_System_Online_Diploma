/*
 * Register.h
 *
 *  Created on: Jul 27, 2023
 *      Author: LEGION
 */

#ifndef REGISTER_H_
#define REGISTER_H_
#define RCC_Base_Adress 	0x40021000
#define RCC_Gpio_Offset		0x18
#define	GPIO_PortA			0x40010800
#define GPIO_CRH_Offset		0x04
#define GPIOA_ODRRegister	0x0c
#define APB2ENR_REG 		*(volatile uint32 *)(RCC_Base_Adress+RCC_Gpio_Offset)
#define CRH_Register		*(volatile uint32 *)(GPIO_PortA+GPIO_CRH_Offset)
#define	GPIOA_ODR_Register	*(volatile uint32 *)(GPIO_PortA+GPIOA_ODRRegister)
#endif /* REGISTER_H_ */
