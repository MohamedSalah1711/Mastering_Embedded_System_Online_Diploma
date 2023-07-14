/*
 * q4.c
 *
 *  Created on: Jul 13, 2023
 *      Author: Mohamed salah
 */
#include <stdio.h>
void convert(char a[]);
int main(){
	setbuf(stdout,NULL);
	char asciinumber[5]="1234";
	convert(asciinumber);
	return 0;
}

void convert(char a[]){
	unsigned int number;
	number = atoi( a );
	printf("number = %d\n", number );
}
