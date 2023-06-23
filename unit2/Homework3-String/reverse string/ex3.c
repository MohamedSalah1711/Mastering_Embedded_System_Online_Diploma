/*
 * ex2.c
 *
 *  Created on: Jun 23, 2023
 *      Author: mohamed salah
 */
#include <stdio.h>
int main(){
	char str[100],temp;
	int count=0;
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	printf("Enter a string: ");
	gets(str);
	for(int i=0;str[i]!='\0';i++){
		count++;
	}
	for(int i=0;i<count/2;i++){
		temp=str[count-1-i];
		str[count-1-i]=str[i];
		str[i]=temp;
	}
	str[count]='\0';
	printf("\n reverse string is %s",str);

	return 0;
}
