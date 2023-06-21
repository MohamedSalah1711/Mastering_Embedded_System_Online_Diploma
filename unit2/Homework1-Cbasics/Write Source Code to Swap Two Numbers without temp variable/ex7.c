/*
 * ex7.c
 *
 *  Created on: Jun 20, 2023
 *      Author: mohamed salah
 */



#include <stdio.h>
void main(){
	float a,b;
	printf("Enter value of a: ");
	fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b: ");
	fflush(stdout);
	scanf("%f",&b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("After swapping, value of a = %0.2f\nAfter swapping, value of b = %0.2f",a,b);




}
