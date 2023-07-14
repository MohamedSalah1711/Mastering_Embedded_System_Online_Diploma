/*
 * Q3.c
 *
 *  Created on: Jul 13, 2023
 *      Author: LEGION
 */

#include <stdio.h>
#define Size 5
void reverse(int a[]);
int main(){
	setbuf(stdout,NULL);
	int a[Size]={1,2,3,4,5};
	reverse(a);

	return 0;
}
void reverse(int a[]){
	int i;
	for(i=Size-1;i>=0;i--){
		printf("%d ",a[i]);
	}
}
