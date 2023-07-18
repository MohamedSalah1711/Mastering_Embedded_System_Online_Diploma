/*
 * Unit 2 : Structure HomeWork
 * Q4.c
 * Author: Mohamed Salah Fathy
 */
#include <stdio.h>
struct Sstudent{
	int roll;
	int mark;
	char name[20];
};
int main(){
	int i;
	setbuf(stdout,NULL);	/*Solving eclipse problem*/
	struct Sstudent data[10];
	printf("Enter information of student:\n");
	for(i=0;i<10;i++){ /*fill data of student*/
		printf("for roll number %d\n",(i+1));
		data[i].roll=(i+1);
		printf("enter a name : ");
		scanf("%s",data[i].name);
		printf("enter mark : ");
		scanf("%d",&data[i].mark);
	}
	printf("Displaying information of students:\n");
	for(i=0;i<10;i++){
		printf("Information for roll number %d\n",data[i].roll);
		printf("Name: %s\n",data[i].name);
		printf("Marks: %d\n",data[i].mark);
	}
	return 0;
}
