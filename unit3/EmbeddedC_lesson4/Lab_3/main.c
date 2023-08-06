/*
 * main.c
 *
 *  Created on: Aug 3, 2023
 *      Author: mohamed salah
 */

#include "main.h"
int main(){
	vuint32 delay_counter;
	SYSCTL_RCGC2_R=0x00000020;
	for(delay_counter=0; delay_counter<400;delay_counter++);
	GPIO_PORTF_DIR_R|=(1<<3);
	GPIO_PORTF_DEN_R|=(1<<3);
	while(1){
		GPIO_PORTF_DATA_R|=(1<<3);
		for(delay_counter=0; delay_counter<40000;delay_counter++);
		GPIO_PORTF_DATA_R&=~(1<<3);
		for(delay_counter=0; delay_counter<40000;delay_counter++);
	}
	return 0;
}
