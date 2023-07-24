/*unit 2
 * Pointers HomeWork
 * Q4.c
 *  Mastering embedded system diploma
 * Author: Mohamed salah fathy
 */
#include <stdio.h>
int main(){
	int array[15],size,i;
	int *ptr;
	ptr=array;
	setbuf(stdout,NULL);	/*Solving eclipse problem*/
	printf("Input the number of elements to store in the array (max 15): ");
	scanf("%d",&size);
	printf("Input 5 number of elements in the array :\n");
	for(i=0;i<size;i++){
		printf("element - %d : ",i+1);
		scanf("%d",&array[i]);
		ptr++;
	}
	for(i=0;i<size;i++){
		ptr--;
		printf("element - %d : 	%d\n",(size-i),*(ptr));

	}
	return 0;
}
