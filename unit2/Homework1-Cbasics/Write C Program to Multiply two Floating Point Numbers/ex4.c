/*
 * ex4.c
 *
 *  Created on: Jun 20, 2023
 *      Author: mohamed salah
 */

/*
Write C Program to Multiply two Floating Point Numbers
i should see the Console as following:
##########Console-output###

###########################
Enter two numbers: 2.4
1.1
Product: 2.640000
 */

#include <stdio.h>
void main(){
	float number1,number2,product;
	printf("Enter two numbers: ");
	fflush(stdout);
	scanf("%f \n %f",&number1,&number2);
	product=number1*number2;
	printf("Product: %f",product);




}
