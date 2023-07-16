/*
 * Max_Zeros.c
 *
 *  Created on: Jul 16, 2023
 *      Author: mohamed salah fathy
 */
#include <stdio.h>
void Binary_Count(int num);
int main(){
	int number; /*32 bit number*/
	/*Solving eclipse problem*/
	setbuf(stdout,NULL);
	/*Ask user to enter number*/
	printf("Enter a number: ");
	scanf("%d",&number);
	/*calling the function*/
	Binary_Count(number);
	return 0;
}

void Binary_Count(int num){
	int i,count=0,max=0;
	for(i=0;i<32;i++){
		if(!(num & (1<<i))){
			while((num & (1<<(i+1)))){
				i++;
				count++;

			}
		}
		if(count>max){
			max=count;
			count=0;
		}
	}
	printf("Number of max ones %d",max);
}
