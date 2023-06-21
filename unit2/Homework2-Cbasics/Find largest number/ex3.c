/*
 * ex3.c
 *
 *  Created on: Jun 21, 2023
 *      Author: mohamed salah
 */
#include <stdio.h>
void main(){
	float number1,number2,number3;
	printf("Enter the three numbers: ");
	fflush(stdout);
	scanf("%f\n%f\n%f",&number1,&number2,&number3);
	if(number1>number2){
		if(number1>number3){

			printf("Largest number is %0.2f ",number1);

		}else{
			printf("Largest number is %0.2f ",number3);
		}
	}else{
		if(number2>number3){

			printf("Largest number is %0.2f ",number2);
		}else{

			printf("Largest number is %0.2f ",number3);
		}
	}
}

