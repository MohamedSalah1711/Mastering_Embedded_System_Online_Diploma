/*
 * Sum_All_Digit.c
 *
 *  Created on: Jul 14, 2023
 *      Author: mohamed salah fathy
 */

#include <stdio.h>
void Sum_digit(int number);
int main(){
	int number;
	/*Solving eclipse problem*/
	setbuf(stdout,NULL);
	/*Ask user to enter number*/
	printf("Enter a number: ");
	scanf("%d",&number);
	/*calling the function*/
	Sum_digit(number);
	return 0;
}
void Sum_digit(int number){
	int digit,Sum_digit=0;
	while(number!=0){
		digit=number%10;
		Sum_digit+=digit;
		number/=10;
	}
	printf("Sum digit = %d",Sum_digit);
}
