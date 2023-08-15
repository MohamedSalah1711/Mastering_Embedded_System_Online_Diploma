/*
 * main.c
 *
 *  Created on: Aug 15, 2023
 *      Author: mohamed salah
 */
#include "Linked_List.h"
int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int select_mode=0,id,index,index_end;
	while(1){
		printf("================\n");
		printf("\tchoose one of the following options\n");
		printf("1: Add student\n2: Delete_Student\n3: view_student\n4: Delete_All\n");
		printf("5: Get_Nth_Nodemode\n6: Number_Of_Students\n7: Nth_Node_From_The_EndMode\n8: Middle_Of_LinkedlistMode\n");
		printf("Enter Option Number: ");
		scanf("%d",&select_mode);
		switch(select_mode){
		case Add_Student_Mode:
			Add_Node();
			break;
		case Delete_Student_Mode:
			printf("\n enter number of id");
			scanf("%d",&id);
			Delete_Node(id);
			break;
		case View_Student_Mode:
			View_Students();
			break;
		case Delete_All_Mode:
			Delete_All();
			break;
		case Get_Nth_Nodemode:
			printf("\n enter number of index");
			scanf("%d",&index);
			Get_Nth_Node (index);
			break;
		case Number_Of_Students:
			NumberOfStudents();
			break;
		case Nth_Node_From_The_EndMode:
			printf("\n enter index from the end");
			scanf("%d",&index_end);
			Nth_Node_From_The_End(index_end);
			break;
		case Middle_Of_LinkedlistMode:
			Middle_Of_Linkedlist();
			break;
		}
	}

	return 0;
}

