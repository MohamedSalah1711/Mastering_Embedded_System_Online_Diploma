/*
 * Prime.c
 *
 *  Created on: Jul 16, 2023
 *      Author: mohamed salah fathy
 */

#include <stdio.h>
void Prime_interval(int number1,int number2);
int main(){
	int number1,number2;
	/*Solving eclipse problem*/
	setbuf(stdout,NULL);
	/*Ask user to enter number*/
	printf("Enter two number: ");
	scanf("%d %d",&number1,&number2);
	/*calling the function*/
	Prime_interval(number1,number2);
	return 0;
}
void Prime_interval(int number1,int number2){
	int i,j,temp=0;
	for(i=number1;i<number2;i++){
		for(j=2;j<=i/2;j++){
			if(i%j==0){
				temp=1;
				break;
			}

		}
		if(temp==0){
			printf("%d ",i);
		}else{
			temp=0;
		}

	}
}
