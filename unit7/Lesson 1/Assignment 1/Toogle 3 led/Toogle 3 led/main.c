/*
 * main.c
 *
 * Created: 9/19/2023 1:57:02 AM
 *  Author: mohamed salah
 */ 
#define PORTD (*(volatile unsigned char *)(0x32))
#define DDRD (*(volatile unsigned char *)(0x31))
#define PIND (*(volatile unsigned char *)(0x30))
void GPIO_init(void);
void Led_seq(void);
void waiting(void);
int main(void)
{	
	GPIO_init();
	while(1)
		{
			 Led_seq();
			 /*Buzzer ON*/
			 PORTD |= (1<<4);
			 waiting();
			 PORTD &= ~(1<<4);
		}
}
void GPIO_init(void){
	/*make led and buzzer output pins*/
	DDRD|= (1<<5) | (1<<6) | (1<<7) | (1<<4);
	PORTD =0;
}
void Led_seq(void){
	int i;
	for(i=5 ; i<8 ; i++){
		
		PORTD |= (1<<i);
		waiting();
		PORTD &=~ (1<<i);
	}
	
}
void waiting(void){
	int i,j;
	for(i=0 ; i<1000 ;i++){
		for(j=0;j<255;j++);
	}
	
}