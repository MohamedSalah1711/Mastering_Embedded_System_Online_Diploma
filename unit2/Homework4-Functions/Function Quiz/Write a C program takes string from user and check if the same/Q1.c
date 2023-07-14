/*
 * Q1.c
 *
 *  Created on: Jul 13, 2023
 *      Author: Mohamed salah fathy
 */
#include <stdio.h>
#include <string.h>
#define Size 50
char username[Size]="mohamed";
int Check(char user[]);
int main(){
	char user[Size];
	int flag;
	setbuf(stdout,NULL);
	printf("Enter User Name: ");
	gets(user);
	flag=Check(user);
	if(flag==0){
		printf("Identical");
	}else{
		printf("Not Identical");
	}



	return 0;
}
int Check(char user[]){
	int check_flag=1,lenght1,lenght2,i;
	lenght1=strlen(username);
	lenght2=strlen(user);
	if(lenght1==lenght2){
		for(i=0;user[i]!="\0";i++){
			if(user[i]!=username[i]){
				check_flag=0;
				break;
			}
		}
	}
	return check_flag;
}
