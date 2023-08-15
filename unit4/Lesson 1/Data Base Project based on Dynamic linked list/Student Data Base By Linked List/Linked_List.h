/*
 * Linked_List.h
 *
 *  Created on: Aug 15, 2023
 *      Author: LEGION
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include <stdio.h>
#include <stdlib.h>
#define Add_Student_Mode 1
#define Delete_Student_Mode 2
#define View_Student_Mode 3
#define Delete_All_Mode 4
#define Get_Nth_Nodemode 5
#define Number_Of_Students 6
#define Nth_Node_From_The_EndMode 7
#define Middle_Of_LinkedlistMode 8

struct Sdata{
	int id;
	char name[35];
	float height;
};
struct Sstudent{
	struct Sdata Student;
	struct Sstudent* P_nextStudent;
};
void Add_Node ();
int Delete_Node (int ID_Number);
void Fill_Data (struct Sstudent* New_student);
void View_Students ();
void Delete_All ();
void Get_Nth_Node (int index);
void NumberOfStudents ();
void Nth_Node_From_The_End (int Index_End);
void Middle_Of_Linkedlist();
#endif /* LINKED_LIST_H_ */
