/*
 * ex5.c
 *
 *  Created on: Jun 20, 2023
 *      Author: mohamed salah
 */

/*
Write C Program to Find ASCII Value of a Character

#########Console_output######
Enter a character: G
ASCII value of G = 71
#############################
 */
#include <stdio.h>
void main(){
	char character;
	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c",&character);
	printf("ASCII value of %c = %d",character,character);




}
