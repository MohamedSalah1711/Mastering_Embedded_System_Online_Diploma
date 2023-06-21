/*
 * ex6.c
 *
 *  Created on: Jun 20, 2023
 *      Author: mohamed salah
 */

/*
 Write Source Code to Swap Two Numbers

#########Console_output######
Enter value of a: 1.20
Enter value of b: 2.45

After swapping, value of a = 2.45
After swapping, value of b = 1.2
#############################
 */

#include <stdio.h>
void main(){
	float a,b,temp;
	printf("Enter value of a: ");
	fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b: ");
	fflush(stdout);
	scanf("%f",&b);
	temp=a;
	a=b;
	b=temp;
	printf("After swapping, value of a = %0.2f\nAfter swapping, value of b = %0.2f",a,b);




}
