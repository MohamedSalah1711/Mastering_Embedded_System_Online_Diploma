/*
 * main.h
 *
 *  Created on: Aug 3, 2023
 *      Author: mohamed salah fathy
 */
#ifndef MAIN_H_
#define MAIN_H_
typedef volatile unsigned int vuint32;
#define RCC_Base_adress 0x40021000
#define GPIO_PortA		0x40010800
#define APB2ENR_REG		*(vuint32*)(RCC_Base_adress + 0x18)
#define CHR_REG			*(vuint32*)(GPIO_PortA + 0x04)
typedef union {
	vuint32 all_fields;
	struct {
		vuint32 reserved:13;
		vuint32 Pin_13:1;
	}Pin;
}R_ODR_t;
#endif /* MAIN_H_ */
