/*unit 2
 * Pointers HomeWork
 * Q2.c
 *  Mastering embedded system diploma
 * Author: Mohamed salah fathy
 */
#include <stdio.h>
#define Number_Of_Alphabets 27
int main(){
	setbuf(stdout,NULL);	/*Solving eclipse problem*/
	char x[Number_Of_Alphabets]; /*Ascii of A*/
	char *ptr=x;
	int i;
	for(i=0;i<Number_Of_Alphabets-1;i++){
		*ptr=i+'A';
		ptr++;
	}
	ptr=x;
	for(i=0;i<Number_Of_Alphabets-1;i++){
		printf("%c ",*ptr);
		ptr++;
	}


	return 0;
}
