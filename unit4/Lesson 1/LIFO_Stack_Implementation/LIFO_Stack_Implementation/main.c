/*
 * main.c
 * Made by >>> Mohamed salah fathy
 * Learn-In-Depth course
 * Implementation of Lifo
 */
#include "Lifo.h"

#define Buffer_Size 5
Buf_states Static_Buffer;
int main(){
	unsigned char Buffer[Buffer_Size],temp;
	int i;
	Lifo_Init(&Static_Buffer,Buffer,Buffer_Size);
	for(i=0 ; i<Buffer_Size ; i++){
		printf("%d\n",i);
		Lifo_Push_Item(&Static_Buffer,i);
	}
	for(i=0 ; i<Buffer_Size ; i++){

		Lifo_Pop_Item(&Static_Buffer,&temp);
		printf(" \n%d ",temp);
	}

	return 0;
}
