/*
 * ex2.c
 *
 *  Created on: Jun 22, 2023
 *      Author: Mohamed Salah
 */
#include <stdio.h>
int main(){
	float number[200],avg=0,sum=0;
	int i;
	printf("Enter the numbers of data: ");
	fflush(stdout);
	scanf("%d",&i);
	for(int j=0;j<i;j++){
		printf("%d. Enter number: ",j+1);
		fflush(stdout);
		scanf("%f",&number[j]);
		sum+=number[j];
	}
	avg=(float)sum/i;
	printf("Average = %0.2f",avg);


	return 0;
}
