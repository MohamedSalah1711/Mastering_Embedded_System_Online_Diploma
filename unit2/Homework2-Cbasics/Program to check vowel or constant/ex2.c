/*
 * ex2.c
 *
 *  Created on: Jun 21, 2023
 *      Author: mohamed salah
 */
#include <stdio.h>
void main(){
	char character;
	printf("Enter an alphabet: ");
	fflush(stdout);
	scanf("%c",&character);
	if((character=='a')||(character=='e')||(character=='i')||(character=='o')||(character=='u')||
			(character=='A')||(character=='E')||(character=='I')||(character=='O')||(character=='U')){
		printf("%c is vowel",character);
	}else{
		printf("%c is constant",character);
	}



}

