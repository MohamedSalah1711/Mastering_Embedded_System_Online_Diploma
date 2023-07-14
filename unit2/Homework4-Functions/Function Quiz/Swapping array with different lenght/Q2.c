/*
 * Q2.c
 *
 *  Created on: Jul 13, 2023
 *      Author: Mohamed salah fathy
 */

#include <stdio.h>
#define First_Array_size 3
#define Second_Array_size 5
#define Max_size 5
void swap(int array1[],int array2[]);
int main(){
	int Array1[Max_size],Array2[Max_size],i;
	setbuf(stdout,NULL);
	printf("Enter first Array: ");
	for(i=0;i<First_Array_size;i++){
		scanf("%d ",&Array1[i]);
	}
	printf("Enter second Array: ");
	for(i=0;i<Second_Array_size;i++){
		scanf("%d ",&Array2[i]);
	}
	printf("Array Befor swapping\n");
	printf("Frist array ->");
	for(i=0;i<First_Array_size;i++){
		printf("%d\t",Array1[i]);
	}
	printf("\n");
	printf("second array ->");
	for(i=0;i<Second_Array_size;i++){
		printf("%d\t",Array2[i]);
	}
	swap(Array1,Array2);
	printf("\nArray After swapping\n");
	printf("Frist array ->");
	for(i=0;i<Second_Array_size;i++){
		printf("%d\t",Array1[i]);
	}
	printf("second array ->");
	for(i=0;i<First_Array_size;i++){
		printf("%d\t",Array2[i]);
	}

	return 0;
}
void swap(int array1[],int array2[]){
	int temp,i;
	for(i=0;i<Max_size;i++){
		temp=array1[i];
		array1[i]=array2[i];
		array2[i]=temp;

	}

}

