/*
 * ex6.c
 *
 *  Created on: Jun 21, 2023
 *      Author: mohamed salah
 */
#include <stdio.h>
void main(){
	int number,sum=0;
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d",&number);
	for(int i=0;i<=number;i++){
		sum+=i;
	}
	printf("Sum= %d",sum);

}

