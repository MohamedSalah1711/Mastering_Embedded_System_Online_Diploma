/*
 * Unit 2 : Structure HomeWork
 * Q5.c
 * Author: Mohamed Salah Fathy
 */
#include <stdio.h>
#define pi 3.14
#define AREA(R)	((R)*(R)*(pi));
int main(){
	float raduis,area;
	setbuf(stdout,NULL);
	printf("Enter raduis to calculate area: ");
	scanf("%f",&raduis);
	area=AREA(raduis);
	printf("Area = %0.2f",area);
	return 0;
}
