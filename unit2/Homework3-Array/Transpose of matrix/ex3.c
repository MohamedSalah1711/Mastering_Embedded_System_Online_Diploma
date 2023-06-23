/*
 * ex3.c
 *
 *  Created on: Jun 22, 2023
 *      Author: Mohamed Salah
 */
#include <stdio.h>
int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int a[100][100],b[100][100];
	int row,cols,i,j;
	printf("Enter rows and colums: ");
	scanf("%d\n%d",&row,&cols);
	printf("Enter Element of matrix:\n");
	for(i=0;i<row;i++){
		for(j=0;j<cols;j++){
			printf("Enter elements a%d%d ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}

	}
	for(i=0;i<row;i++){
		for(j=0;j<cols;j++){
			b[j][i]=a[i][j];
		}

	}
	printf("Entered matrix: \n");
	for(i=0;i<row;i++){
		for(j=0;j<cols;j++){
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
	printf("Transposed matrix: \n");
	for(i=0;i<cols;i++){
		for(j=0;j<row;j++){
			printf("%d  ",b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
