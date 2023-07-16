/*
 * Reverse_Words.c
 *
 *  Created on: Jul 16, 2023
 *      Author: mohamed salah fathy
 */


#include <stdio.h>
void ReverseWord(char sttr[]);
int main(){
	char str[100]="Mohamed gamal";
	setbuf(stdout,NULL);
	ReverseWord(str);

	return 0;
}
void ReverseWord(char sttr[]){
	int space,i,j;
	char str[100];
	for(i=0;sttr[i]!='\0';i++){
		if(sttr[i]==' '){
			space=i;
			break;

		}
	}
	for(i=space,j=0;sttr[i]!='\0';i++,j++){
		str[j]=sttr[i];
	}
	str[j++]=' ';
	for(i=0;i<space;i++,j++){
		str[j]=sttr[i];
	}
	str[j]='\0';
	puts(str);
}
