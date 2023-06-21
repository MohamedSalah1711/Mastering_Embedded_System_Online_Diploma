/*
 * ex7.c
 *
 *  Created on: Jun 21, 2023
 *      Author: mohamed salah
 */
#include <stdio.h>
void main(){
	int number,Fact=1;
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d",&number);
	if(number<0){
		printf("Error!!! Factorial of Negative Number doesn't exist");
	}else if(number==0){
		printf("Factorial= %d",Fact);
	}else{
		for(int i=1;i<=number;i++){
			Fact*=i;
		}
		printf("Factorial= %d",Fact);
	}


}

