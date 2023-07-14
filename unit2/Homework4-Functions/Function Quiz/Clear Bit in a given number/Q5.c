/*
 * Q5.c
 *
 *  Created on: Jul 13, 2023
 *      Author: LEGION
 */
#include <stdio.h>
int clear_bit(int number,int bit_number);
int main(){
	setbuf(stdout,NULL);
	int num=3,bit_num=0,new_num;
	new_num=clear_bit(num,bit_num);
	printf("%d",new_num);

	return 0;
}


int clear_bit(int number,int bit_number){
	int new_number;
	new_number=number&~(1<<bit_number);
	return new_number;
}
