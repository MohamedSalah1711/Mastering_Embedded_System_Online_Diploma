/*
 * main.c
 *
 *  Created on: Aug 3, 2023
 *      Author: LEGION
 */

#include "main.h"
int main(){
	int i;
	APB2ENR_REG|=(1<<2);
	CHR_REG &= 0xff0fffff;
	CHR_REG|=(2<<20);
	R_ODR_t* R_ODR= (R_ODR_t*)(GPIO_PortA + 0x0c);
	while(1){
		R_ODR->Pin.Pin_13=1;
		for(i=0; i<5000;i++);
		R_ODR->Pin.Pin_13=0;
		for(i =0; i<5000;i++);
	}
	return 0;
}
