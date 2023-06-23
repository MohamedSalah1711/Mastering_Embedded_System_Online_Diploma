/*
 * ex5.c
 *
 *  Created on: Jun 22, 2023
 *      Author: Mohamed Salah
 */
#include <stdio.h>
int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int array[100],No_of_element,i,number;
	printf("Enter number of elements: ");
	scanf("%d",&No_of_element);
	for(i=0;i<No_of_element;i++){
		scanf("%d",&array[i]);
	}
	printf("Enter the elements to be searched: ");
	scanf("%d",&number);
	for(i=0;i<No_of_element;i++){
		if(number==array[i]){
			printf("Number found at location = %d",i+1);
			break;
		}

	}
	if(i==No_of_element){
		printf("Number not found");
	}
	return 0;
}
