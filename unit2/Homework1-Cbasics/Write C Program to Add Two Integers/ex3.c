/*
 * ex3.c
 *
 *  Created on: Jun 20, 2023
 *      Author: mohamed salah
 */

/*
  i should see the Console as following:
##########Console-output###
Enter two integers: 12
11
Sum: 23
 */
#include <stdio.h>
void main(){
	int number1,number2;
	printf("Enter two integers: ");
	fflush(stdout);
	scanf("%d \n %d",&number1,&number2);
	printf("Sum: %d",(number1+number2));




}
