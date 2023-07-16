/*
 * Count_Binary.c
 *
 *  Created on: Jul 16, 2023
 *      Author: mohamed salah fathy
 */

#include <stdio.h>
void Binary_Count(int number);
int main(){
	int number;
	/*Solving eclipse problem*/
	setbuf(stdout,NULL);
	/*Ask user to enter number*/
	printf("Enter a number: ");
	scanf("%d",&number);
	/*calling the function*/
	Binary_Count(number);
	return 0;
}
void Binary_Count(int number){
	int i,count=0;
	for(i=0;i<32;i++){
		if(number & (1<<i)){
			count++;
		}

	}
	printf("Number of ones equal %d",count);
}
