/*
 * ex1.c
 *
 *  Created on: Jun 23, 2023
 *      Author: mohamed salah
 */
#include <stdio.h>
int main(){
	char str[100],character,count=0;
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	printf("Enter a string: ");
	gets(str);
	printf("\nEnter a character: ");
	scanf("%c",&character);
	for(int i=0;str[i]!='\0';i++){
		if(str[i]==character){
			count++;
		}
	}
	printf("Frequency of %c = %d",character,count);
	return 0;
}
