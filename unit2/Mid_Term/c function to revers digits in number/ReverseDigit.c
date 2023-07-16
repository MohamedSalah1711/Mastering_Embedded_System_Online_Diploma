/*
 * ReverseDigit.c
 *
 *  Created on: Jul 16, 2023
 *      Author: mohamed salah fathy
 */


#include <stdio.h>
void Reverse_Digit(int number);
int main(){
	int number;
	/*Solving eclipse problem*/
	setbuf(stdout,NULL);
	/*Ask user to enter number*/
	printf("Enter a number: ");
	scanf("%d",&number);
	/*calling the function*/
	Reverse_Digit(number);


	return 0;
}
void Reverse_Digit(int number){
	int temp=0,reminder;
	while(number!=0){
		reminder=number%10;
		temp+=reminder;
		temp*=10;
		number/=10;
	}
	temp/=10;
	printf("number in Reverse = %d",temp);

}
