/*
 * Unit 2 : Structure HomeWork
 * Q3.c
 * Author: Mohamed Salah Fathy
 */
#include <stdio.h>
struct Scomplex{
	float Real;
	float imaginary;
};
struct Scomplex Add(struct Scomplex number1,struct Scomplex number2);
int main(){
	setbuf(stdout,NULL);	/*Solving eclipse problem*/
	struct Scomplex Number1,Number2,sum;
	printf("Enter information for 1st complex number\n");
	printf("Enter real and imaginary respectively: ");
	scanf("%f",&Number1.Real);
	scanf("%f",&Number1.imaginary);
	printf("Enter information for 1st complex number\n");
	printf("Enter real and imaginary respectively: ");
	scanf("%f",&Number2.Real);
	scanf("%f",&Number2.imaginary);
	sum=Add(Number1,Number2);
	printf("Sum= %0.2f+%0.2fi",sum.Real,sum.imaginary);
	return 0;
}
struct Scomplex Add(struct Scomplex number1,struct Scomplex number2){
	struct Scomplex Sum;
	Sum.Real=number1.Real+number2.Real;		/*Sum Real part*/
	Sum.imaginary=number1.imaginary+number2.imaginary;	/*Sum imaginary part*/
	return Sum;
}
