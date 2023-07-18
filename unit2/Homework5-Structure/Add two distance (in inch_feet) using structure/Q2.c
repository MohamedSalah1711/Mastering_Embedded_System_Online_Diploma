/*
 * Unit 2 : Structure HomeWork
 * Q2.c
 * Author: Mohamed Salah Fathy
 */
#include <stdio.h>
struct Sdistance {
	int feet;
	float inch;
};
struct Sdistance Distance1,Distance2,Sum;
int main(){
	setbuf(stdout,NULL);	/*Solving eclipse problem*/
	printf("Enter information for 1st distance\n");
	printf("Enter feet: ");
	scanf("%d",&Distance1.feet);
	printf("Enter inch: ");
	scanf("%f",&Distance1.inch);
	printf("Enter information for 2nd distance\n");
	printf("Enter feet: ");
	scanf("%d",&Distance2.feet);
	printf("Enter inch: ");
	scanf("%f",&Distance2.inch);
	/*Calculate sum distance*/
	Sum.feet=Distance1.feet+Distance2.feet;
	Sum.inch=Distance1.inch+Distance2.inch;
	while(Sum.inch>=12){ /*Converting inch to feet*/
		Sum.inch-=12;
		Sum.feet++;
	}
	printf("Sum of distance %d' %0.2f\"",Sum.feet,Sum.inch);
	return 0;

}

