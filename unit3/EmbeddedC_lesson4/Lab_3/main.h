/*
 * main.h
 *
 *  Created on: Aug 3, 2023
 *      Author: mohamed salah fathy
 */
#ifndef MAIN_H_
#define MAIN_H_
typedef volatile unsigned int vuint32;
#define SYSCTL_RCGC2_R 			(*((vuint32*)0x400FE108))
#define GPIO_PORTF_DATA_R		(*((vuint32*)0x400253FC))
#define GPIO_PORTF_DIR_R		(*((vuint32*)0x40025400))
#define GPIO_PORTF_DEN_R		(*((vuint32*)0x4002551C))
#endif /* MAIN_H_ */
