/*
 * Register.h
 *
 *  Created on: Sep 13, 2023
 *      Author: LEGION
 */

#ifndef REGISTER_H_
#define REGISTER_H_
#define SREG (*(volatile unsigned char *)(0X5F))
#define GICR (*(volatile unsigned char *)(0X5B))
#define GIFR (*(volatile unsigned char *)(0X5A))
#define MCUCR (*(volatile unsigned char *)(0X55))
#define MCUCSR (*(volatile unsigned char *)(0X54))
//Gpio Regs
#define PORTD 	(*(volatile uint8*)(0X32))
#define DDRD 	(*(volatile uint8*)(0X31))
#define PIND 	(*(volatile uint8*)(0X30))
#define PORTB 	(*(volatile uint8*)(0X38))
#define DDRB 	(*(volatile uint8*)(0X37))
#define PINB 	(*(volatile uint8*)(0X36))
#endif /* REGISTER_H_ */
