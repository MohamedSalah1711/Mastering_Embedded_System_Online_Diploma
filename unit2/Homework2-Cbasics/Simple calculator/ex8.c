/*
 * ex8.c
 *
 *  Created on: Jun 21, 2023
 *      Author: mohamed salah
 */
#include <stdio.h>
void main(){
	char operator;
	float num1,num2;
	printf("Enter operator either + or - or * or divide: ");
	fflush(stdout);
	scanf("%c",&operator);
	printf("Enter two operands: ");
	fflush(stdout);
	scanf("%f\n%f",&num1,&num2);
	switch(operator){
	case '+':
		printf("%0.2f + %0.2f= %0.2f",(num1),(num2),(num1+num2));
		break;
	case '-':
		printf("%0.2f - %0.2f= %0.2f",(num1),(num2),(num1-num2));
		break;

	case '*':
		printf("%0.2f * %0.2f= %0.2f",(num1),(num2),(num1*num2));
		break;

	case '/':
		printf("%0.2f / %0.2f= %0.2f",(num1),(num2),(num1/num2));
		break;
	default:
		printf("Wrong Operator!!!");
		break;
	}
}

