/*
 * Q7.c
 *
 *  Created on: Jul 14, 2023
 *      Author: LEGION
 */
#include <stdio.h>
int check(signed int num);
int main(){
	int number,flag;
	setbuf(stdout,NULL);
	printf("Enter a number");
	scanf("%d",&number);
	flag=check(number);
	if(flag==0){
		printf("number is power of 3");
	}else{
		printf("number is  not power of 3");
	}
	return 0;
}






int check(signed int num){
	int i,temp=1;
	if(num==1){
		temp=0;
	}
	if(num%3==0){
		for(i=0;num>0;i++){
			num/=3;
			if(num==1){
				temp=0;
				break;
			}
		}

	}

	return temp;
}
