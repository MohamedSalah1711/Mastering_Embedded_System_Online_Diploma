/*
 * ex1.c
 *
 *  Created on: Jun 22, 2023
 *      Author: Mohamed Salah
 */
#include <stdio.h>
int main(){
	float a[2][2],b[2][2];
	int i,j;
	setbuf(stdout,NULL);
	printf("Enter the elements of 1st matrix\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("Enter a%d%d:",(i+1),(j+1));
			scanf("%f\n",&a[i][j]);

		}

	}

	printf("Enter the elements of 2st matrix\n");
	fflush(stdout);
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("Enter b%d%d:",(i+1),(j+1));
			scanf("%f\n",&b[i][j]);

		}

	}
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			a[i][j]+=b[i][j]; /*Sum and store in array a*/
		}

	}
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%f\t",a[i][j]);

		}
		printf("\n");

	}

	return 0;
}

