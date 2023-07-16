/*
 * SquareRoot.c
 *
 *  Created on: Jul 15, 2023
 *      Author: mohamed salah fathy
 */
#include <stdio.h>
void SquareRoot(float number);
int main(){
	int number;
	/*Solving eclipse problem*/
	setbuf(stdout,NULL);
	/*Ask user to enter number*/
	printf("Enter a number: ");
	scanf("%d",&number);
	/*calling the function*/
	SquareRoot(number);
	return 0;
}

void SquareRoot(float number){
	int i;
	float digit=1;
	float Square_Root=1;
	for(i=0;i<=6;i++){
		while(Square_Root*Square_Root<=number){
			Square_Root+=digit;
		}
		Square_Root-=digit;
		if(Square_Root*Square_Root==number){
			break;
		}
		digit=digit/10;
	}
	printf("square root is %0.4f",Square_Root);
}
