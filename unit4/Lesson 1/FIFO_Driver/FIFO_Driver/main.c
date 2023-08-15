/*
 * main.c
 *
 *  Created on: Aug 11, 2023
 *      Author: mohamed salah
 */
#include "FIFO.h"
#define Buffer_length 5
element_type buffer[Buffer_length];
LIFO_Buf_t I2C_buffer;
int main(){
	uint8_t i,temp;
	if(FIFO_init(&I2C_buffer,buffer,Buffer_length)==FIFO_NO_ERROR){
		printf("Init Done\n");
	}
	for(i=0 ; i<7 ; i++){
		printf("Push (%x)",i);
		if(FIFO_Enqueue(&I2C_buffer,i)==FIFO_NO_ERROR){
			printf("FIFO Push is done\n");
		}else{
			printf("FIFO Push is failed\n");
		}

	}
	FIFO_PRINT(&I2C_buffer);
	if(FIFO_Dequeue(&I2C_buffer,&temp)==FIFO_NO_ERROR){
		printf("FIFO POP is done\n");
		printf("Poped value is (%x)\n",temp);
	}else{
		printf("FIFO POP is failed\n");
	}
	if(FIFO_Dequeue(&I2C_buffer,&temp)==FIFO_NO_ERROR){
		printf("FIFO POP is done\n");
		printf("Poped value is (%x)\n",temp);
	}else{
		printf("FIFO POP is failed\n");
	}
	FIFO_PRINT(&I2C_buffer);



	return 0;
}

