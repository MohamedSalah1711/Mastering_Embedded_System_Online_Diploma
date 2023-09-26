/*
 * Created By : Mohamed salah fathy
 * GPIO Lab 1
 * */
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "Registers.h"
void init_clock(void);
void init_GPIO(void);
int main(void)
{
	init_clock();
	init_GPIO();
	int i;
	while(1){

		if (((GPIOA_IDR & (1<<1))>>1) ==0 ){

				GPIOB_ODR ^= (1<<1);
				while(((GPIOA_IDR & (1<<1))>>1) ==0 );


		}if (((GPIOA_IDR & (1<<13))>>13) == 1 ){

				GPIOB_ODR ^= (1<<13);


		}
		for(i=0; i<500;i++);

	}

}
void init_clock(void){
	/*Enable Port A clock*/
	RCC_APB2ENR |= (1<<2);
	/*Enable Port B clock*/
	RCC_APB2ENR |= (1<<3);
}
void init_GPIO(void){
	/*PB1 output push-pull mode*/
	GPIOB_CRL &= ~(0b11<<6);
	/*MAX SPEED = 10 MHZ*/
	GPIOB_CRL &= ~(0b11 << 4);
	GPIOB_CRL |=  (0b01 << 4);
	/*PB13 output push-pull mode*/
	GPIOB_CRH &= ~(0b11<<22);
	/*MAX SPEED = 10 MHZ*/
	GPIOB_CRH &= ~(0b11 << 20);
	GPIOB_CRH |=  (0b01 << 20);
	/*A1 AND A13 IS INPUT FOLATING BY RESET STATE*/
}


