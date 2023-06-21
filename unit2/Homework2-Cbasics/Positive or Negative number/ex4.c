/*
 * ex4.c
 *
 *  Created on: Jun 21, 2023
 *      Author: mohamed salah
 */
#include <stdio.h>
void main(){
	float number;
	printf("Enter the number you want to check: ");
	fflush(stdout);
	scanf("%f",&number);
	if(number>0){
		printf("%0.2f is positive",number);
	}else if((number==0)){

		printf("you entered zero");
	}else{
		printf("%0.2f is negative",number);
	}



}

