/*
 * q6.c
 *
 *  Created on: Jul 14, 2023
 *      Author: LEGION
 */

#include <stdio.h>
int get_bit(int number);
int main(){
	setbuf(stdout,NULL);
	int number=71,fourth_bit;
	fourth_bit=get_bit(number);
	printf("%d",fourth_bit);

	return 0;
}





int get_bit(int number){
	int fourth_bit;
	if(number&(1<<3)){
		fourth_bit=1;
	}else{
		fourth_bit=0;
	}
	return fourth_bit;
}
