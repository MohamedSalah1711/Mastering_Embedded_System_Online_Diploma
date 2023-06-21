/*
 * ex5.c
 *
 *  Created on: Jun 21, 2023
 *      Author: mohamed salah
 */
#include <stdio.h>
void main(){
	char character;
	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c",&character);
	if((character>=65) && (character<=122)){ /*From ascii table*/
		printf("%c is an Alphabet",character);
	}else{
		printf("%c is not Alphabet",character);
	}



}

