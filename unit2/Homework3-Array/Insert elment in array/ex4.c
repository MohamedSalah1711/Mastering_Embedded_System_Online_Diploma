/*
 * ex4.c
 *
 *  Created on: Jun 22, 2023
 *      Author: Mohamed Salah
 */
#include <stdio.h>
int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int array[100],No_of_element,i,number,location;
	printf("Enter number of elements: ");
	scanf("%d",&No_of_element);
	for(i=0;i<No_of_element;i++){
		scanf("%d",&array[i]);
	}
	printf("Enter the elements to be inserted: ");
	scanf("%d",&number);
	printf("Enter the location: ");
	scanf("%d",&location);
	for(i=No_of_element;i>=0;i--){
		if(i>location-1){
			array[i]=array[i-1];
		}
	}
	array[location-1]=number;
	for(i=0;i<No_of_element+1;i++){
		printf("%d ",array[i]);
	}



	return 0;
}
