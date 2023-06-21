/*
 * ex2.c
 *
 *  Created on: Jun 20, 2023
 *      Author: mohamed salah
 */

/*
 * Write C Program to Print a Integer Entered by a User
i should see the Console as following:
##########Console-output###
Enter a integer: 25
You entered: 25
 */
#include <stdio.h>
void main(){
	int number;
	printf("Enter a integer: ");
	fflush(stdout);
	scanf("%d",&number);
	printf("\nYou entered: %d",number);



}
