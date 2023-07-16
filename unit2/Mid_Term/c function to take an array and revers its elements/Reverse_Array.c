/*
 * Reverse_Array.c
 *
 *  Created on: Jul 16, 2023
 *      Author: mohamed salah fathy
 */

#define SIZE	5
#include <stdio.h>
void Reverse_Array(int a[]);
int main(){
	int array[SIZE]={1,2,3,4,5};
	Reverse_Array(array);


	return 0;
}
void Reverse_Array(int a[]){
	int temp[SIZE],i;
	for(i=0;i<SIZE;i++){
		temp[i]=a[SIZE-1-i];
		printf("%d ",temp[i]);
	}
}
