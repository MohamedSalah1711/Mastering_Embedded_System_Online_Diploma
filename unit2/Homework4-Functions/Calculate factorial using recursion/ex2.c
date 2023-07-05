/*
 * ex2.c
 *
 *  Created on: Jul 2, 2023
 *      Author: mohamed salah
 */

#include <stdio.h>
int factorial(int number);
int main(){
	int num,fact;
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	printf("enter a positive number: ");
	scanf("%d",&num);
	fact=factorial(num);
	printf("factorial of %d = %d",num,fact);
	return 0;
}
int factorial(int number){
	int fact=1;
	if(number==0 || number==1){
		/*Do nothing*/
	}else{
	fact=number*factorial(number-1);
	}
	return fact;
}
