/*
 * ex1.c
 *
 *  Created on: Jun 21, 2023
 *      Author: mohamed salah
 */
#include <stdio.h>
void main(){
	int number;
	printf("Enter the number you want to check: ");
	fflush(stdout);
	scanf("%d",&number);
	if((number%2)==0){
		printf("%d is Even",number);
	}else{
		printf("%d is odd",number);
	}



}

