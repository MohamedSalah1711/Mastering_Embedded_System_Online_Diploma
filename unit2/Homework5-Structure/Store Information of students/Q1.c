/*
 * Unit 2 : Structure HomeWork
 * Q1.c
 * Author: Mohamed Salah Fathy
 */
#include <stdio.h>
struct Sstudent{
	int roll;
	float marks;
	char name[20];
}student;
void fill_structure(void);
void Displaying_Inf(void);
int main(){
	setbuf(stdout,NULL);	/*Solving eclipse problem*/
	printf("Enter information of students\n");
	fill_structure();	/*Function to get data from student*/
	Displaying_Inf();	/*Function to display student data*/
	return 0;
}
void fill_structure(void){
	printf("Enter name: ");
	scanf("%s",student.name);
	printf("Enter Roll number: ");
	scanf("%d",&student.roll);
	printf("Enter Marks: ");
	scanf("%f",&student.marks);
}
void Displaying_Inf(void){
	printf("name: %s\n",student.name);
	printf("Roll: %d\n",student.roll);
	printf("Marks: %0.1f",student.marks);
}
