/*
 * ex1.c
 *
 *  Created on: Jul 2, 2023
 *      Author: mohamed salah
 */


#include <stdio.h>
void prime_Num(int num);
int temp=0;
int main(){
	int num1,num2;
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	printf("Enter two numbers(interval): ");
	scanf("%d %d",&num1,&num2);
	printf("prime number between %d and %d are : ",num1,num2);
	for(int i=num1+1;i<num2;i++){
		prime_Num(i);
		if(temp==0){
			printf("%d ",i);
		}

	}

	return 0;
}
void prime_Num(int num){
int flag=0;
	for(int i=2;i<=num/2;i++){
		if(num%i==0){
			flag=1;
			break;
		}
	}
	temp=flag;
}
