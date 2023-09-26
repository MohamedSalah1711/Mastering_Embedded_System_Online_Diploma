/*
 * Registers.h
 *
 *  Created on: Sep 18, 2023
 *      Author: LEGION
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_
//RCC reg
#define RCC_BASE 0x40021000
#define RCC_APB2ENR *((volatile unsigned int *)(RCC_BASE + 0x18))
//GPIO reg
#define GPIO_Port_A_BASE 0x40010800
#define GPIO_Port_B_BASE 0x40010C00
#define GPIOA_CRL *((volatile unsigned int *)(GPIO_Port_A_BASE + 0x00))
#define GPIOB_CRL *((volatile unsigned int *)(GPIO_Port_B_BASE + 0x00))
#define GPIOA_CRH *((volatile unsigned int *)(GPIO_Port_A_BASE + 0x04))
#define GPIOB_CRH *((volatile unsigned int *)(GPIO_Port_B_BASE + 0x04))
#define GPIOA_IDR *((volatile unsigned int *)(GPIO_Port_A_BASE + 0x08))
#define GPIOB_IDR *((volatile unsigned int *)(GPIO_Port_B_BASE + 0x08))
#define GPIOA_ODR *((volatile unsigned int *)(GPIO_Port_A_BASE + 0x0C))
#define GPIOB_ODR *((volatile unsigned int *)(GPIO_Port_B_BASE + 0x0C))
#endif /* REGISTERS_H_ */
