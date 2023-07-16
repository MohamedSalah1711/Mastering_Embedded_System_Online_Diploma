/*
 * Sum_Without_Loop.c
 *
 *  Created on: Jul 16, 2023
 *      Author: mohamed salah fathy
 */

#include <stdio.h>
int Sum(int number);
int main(){
	int number=100,sum;
	setbuf(stdout,NULL);
	sum=Sum(number);
	printf("%d",sum);
	return 0;

}
int Sum(int number){
	int sum=0;
	if(number==0){
		return sum;
	}
	sum=Sum(number-1)+number;

	return sum;
}
