/*
 * main.c
 *
 *  Created on: Sep 13, 2023
 *      Author: mohamed salah
 */


#include "Register.h"
#include <avr/interrupt.h>
#include <util/delay.h>
void Setup_interrupt(){
	//enable global interrupt
	SREG |= (1<<7);
	/*Interrupt 1 Sense Control
	 * The rising edge of INT1 generates an interrupt request.
	 * */
	MCUCR |= (0b11 << 2);
	//Bit 1, 0 – ISC01, ISC00: Interrupt Sense Control 0 Bit 1 and Bit 0 (sense any logical change)
	MCUCR |= (1 << 0);
	//Bit 6 – ISC2: Interrupt Sense Control 2 (falling edge)
	MCUCSR &=~ (1<<6);
	//GICR ENABLE INTERRUPT
	GICR |= (0b111 << 5);
}
void Led_init(){
	//Configure Pin 5,6,7 as output Pins
	DDRD |= (1<<5) | (1<<6) | (1<<7);
	//initialize by zero
	PORTD &= ~(1<<5) & (~(1<<6)) & (~(1<<7));
}
void Buttons_init(){
	//Configure PD2,PD3,PB2 as input Pins
	DDRD &=~(1<<2) & (~(1<<3));
	DDRB &=~ (1<<2);

}
ISR(INT0_vect){
	PORTD |= (1<<5);
	_delay_ms(1000);
}
ISR(INT1_vect){
	PORTD |= (1<<6);
	_delay_ms(1000);
}
ISR(INT2_vect){
	PORTD |= (1<<7);
	_delay_ms(1000);
}
int main(void){
	Led_init();
	Buttons_init();
	Setup_interrupt();
	while(1){
		PORTD &= ~(1<<5) & (~(1<<6)) & (~(1<<7));
	}
return 0;
}
