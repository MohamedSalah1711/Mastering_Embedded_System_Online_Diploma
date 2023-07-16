/*
 * Unique_Number.c
 *
 *  Created on: Jul 16, 2023
 *      Author: mohamed salah fathy
 */


#include <stdio.h>
void Unique_Number(int array[],int size);
int main(){
	int arr[3]={4,2,4};;
	/*Solving eclipse problem*/
	setbuf(stdout,NULL);
	/*calling the function*/
	Unique_Number(arr,3);
	return 0;
}
void Unique_Number(int array[],int size){
	int i=0,unique_number=0;
	for(i=0;i<size;i++){
		unique_number ^= array[i];
	}
	printf("unique number is %d",unique_number);
}
