/*
 * ex3.c
 *
 *  Created on: Jul 2, 2023
 *      Author: mohamed salah
 */


#include <stdio.h>
int power(int num,int base);
int main(){
	int num,base,result;
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	printf("Enter a base number: ");
	scanf("%d",&base);
	printf("Enter a power number: ");
	scanf("%d",&num);
	result=power(num,base);
	printf("%d",result);

return 0;
}
int power(int num,int base){
	if(num==0){
		return 1;
	}
	return base*power(num-1,base);
}
