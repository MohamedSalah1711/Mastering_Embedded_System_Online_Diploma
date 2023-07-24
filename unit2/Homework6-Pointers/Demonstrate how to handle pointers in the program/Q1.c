/*unit 2
 * Pointers HomeWork
 * Q1.c
 *  Mastering embedded system diploma
 * Author: Mohamed salah fathy
 */
#include <stdio.h>

int main(){
	setbuf(stdout,NULL);	/*Solving eclipse problem*/
	int *ab,m=29; /*ab is a pointer and m is an integer*/
	printf("Adress of m = 0x%p\n Value of m = %d\n",&m,m);
	ab=&m; /*Assign pointer value to point adress of variable m*/
	printf("Now ab is assigned with adress of m\n");
	printf("Adress of pointer ab = 0x%p\nContent of pointer ab = %d\n",&ab,*ab);
	m=34;
	printf("Adress of m = 0x%p\n Value of m = %d\n",&m,m);
	*ab=7;
	printf("Adress of m = 0x%p\n Value of m = %d\n",&m,m);


	return 0;
}

