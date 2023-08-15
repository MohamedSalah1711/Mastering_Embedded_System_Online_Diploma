/*
 * Linked_List.c
 *
 *  Created on: Aug 15, 2023
 *      Author: LEGION
 */
#include "Linked_List.h"
struct Sstudent* Head= NULL;
void Add_Node ()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	struct Sstudent* New_Student=NULL;
	struct Sstudent* Last_Student=NULL;
	/*check if first element*/
	if(Head==NULL){
		New_Student=(struct Sstudent*)malloc(sizeof(struct Sstudent));
		Head=New_Student;
		New_Student->P_nextStudent=NULL;
	}else{
		New_Student=(struct Sstudent*)malloc(sizeof(struct Sstudent));
		Last_Student=Head;
		while(Last_Student->P_nextStudent != NULL){
			Last_Student=Last_Student->P_nextStudent;
		}
		Last_Student->P_nextStudent=New_Student;
		New_Student->P_nextStudent=NULL;
	}
	Fill_Data(New_Student);
}
int Delete_Node (int ID_Number)
{
	struct Sstudent* temp=NULL;
	struct Sstudent* Prev=NULL;
	if(Head)
	{
		temp=Head;
		while(temp)
		{
			if(temp->Student.id==ID_Number)
			{
				if(Prev)
				{
					Prev->P_nextStudent=temp->P_nextStudent;

				}else
				{
					Head=Head->P_nextStudent;
				}
				free(temp);
				return 1;
			}
			Prev=temp;
			temp=temp->P_nextStudent;
		}

	}
	printf("cannot find id");
	return 0;
}
void View_Students (){
	struct Sstudent* temp=NULL;
	int count=1;
	if(Head){
		temp=Head;
		while(temp){
			printf("Record Number %d\n",count);
			printf("ID: %d\n",temp->Student.id);
			printf("Name: %s\n",temp->Student.name);
			printf("height: %0.2f\n",temp->Student.height);
			temp=temp->P_nextStudent;
			count++;
		}
	}else{
		printf("Empty list\n");
	}
}
void Delete_All (){
	struct Sstudent* temp=NULL;
	if(Head){
		temp=Head;
		while(temp){
			struct Sstudent* temp2=temp;
			temp=temp->P_nextStudent;
			free(temp2);
		}
	}else{
		printf("Empty list\n");
	}
}
void Fill_Data(struct Sstudent* New_student){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	printf("Enter Id number: ");
	scanf("%d",&New_student->Student.id);
	printf("Enter name : ");
	gets(New_student->Student.name);
	gets(New_student->Student.name);
	printf("enter height: ");
	scanf("%f",&New_student->Student.height);

}
void Get_Nth_Node(int index){
	struct Sstudent* temp;
	if(Head==NULL){
		printf("empty list");
	}else{
		temp=Head;
		while(--index){
			if(temp==NULL){
				break;
			}
			temp=temp->P_nextStudent;
		}
		printf("ID: %d\n",temp->Student.id);
		printf("Name: %s\n",temp->Student.name);
		printf("height: %0.2f\n",temp->Student.height);
	}

}
void NumberOfStudents(){
	int count=0;
	if(Head==NULL){
		printf("empty list");
	}else{
		struct Sstudent* temp=Head;
		while(temp){
			count++;
			temp=temp->P_nextStudent;
		}
	}
	printf("Number Of Students = %d",count);
}
void Nth_Node_From_The_End (int Index_End){
	if(Head==NULL){
		printf("empty list");

	}else{
		struct Sstudent* ref_Ptr=Head;
		struct Sstudent* main_Ptr=Head;
		/*move ref ptr*/
		while(--Index_End){
			if(ref_Ptr==NULL){
				break;
			}
			ref_Ptr=ref_Ptr->P_nextStudent;
		}
		if(Index_End){
			printf("Number is not exist\n");
		}else{
			while(ref_Ptr){
				ref_Ptr=ref_Ptr->P_nextStudent;
				main_Ptr=main_Ptr->P_nextStudent;
			}
			printf("ID: %d\n",main_Ptr->Student.id);
			printf("Name: %s\n",main_Ptr->Student.name);
			printf("height: %0.2f\n",main_Ptr->Student.height);

		}
	}
}
void Middle_Of_Linkedlist(){
	if(Head==NULL){
		printf("empty list");

	}else{
		struct Sstudent* slow_Ptr=Head;
		struct Sstudent* fast_Ptr=Head;
		while(fast_Ptr!=NULL && slow_Ptr!=NULL){
			fast_Ptr=fast_Ptr->P_nextStudent->P_nextStudent;
			slow_Ptr=slow_Ptr->P_nextStudent;
		}
		printf("ID: %d\n",slow_Ptr->Student.id);
		printf("Name: %s\n",slow_Ptr->Student.name);
		printf("height: %0.2f\n",slow_Ptr->Student.height);
	}
}
