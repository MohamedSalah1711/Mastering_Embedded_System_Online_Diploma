/*
 * ex2.c
 *
 *  Created on: Jun 23, 2023
 *      Author: mohamed salah
 */
#include <stdio.h>
int main(){
	char str[100],count=0;
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	printf("Enter a string: ");
	gets(str);
	for(int i=0;str[i]!='\0';i++){
			count++;
	}
	printf("lenght of string =%d",count);
	return 0;
}
