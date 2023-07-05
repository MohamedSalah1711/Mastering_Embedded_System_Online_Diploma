/*
 * ex3.c
 *
 *  Created on: Jul 2, 2023
 *      Author: mohamed salah
 */


#include <stdio.h>
void Reverse();
int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	printf("Enter a sentence: ");
	Reverse();


return 0;
}
void Reverse(){
	char character;
	scanf("%c",&character);
	if(character != '\n'){
	Reverse();
	printf("%c",character);
	}

}
