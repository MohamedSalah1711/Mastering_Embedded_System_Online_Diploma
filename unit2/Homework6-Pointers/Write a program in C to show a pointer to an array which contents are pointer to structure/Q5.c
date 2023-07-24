/*unit 2
 * Pointers HomeWork
 * Q5.c
 *  Mastering embedded system diploma
 * Author: Mohamed salah fathy
 */
#include <stdio.h>
struct Semployee {
	char Name[20];
	int id;
};
int main(){
	setbuf(stdout,NULL);	/*Solving eclipse problem*/
	struct Semployee emp1={"mohamed",1000},emp2={"ahmed",1001},emp3={"ali",1002};
	struct Semployee *array[]={&emp1,&emp2,&emp3};
	struct Semployee *(*pts)[3]=&array;
	printf("First Employee name : %s\n",(**(*pts+0)).Name);
	printf("First Employee Id : %d\n",(**(*pts+0)).id);
	printf("second Employee name : %s\n",(**(*pts+1)).Name);
	printf("second Employee Id : %d\n",(**(*pts+1)).id);
	printf("third Employee name : %s\n",(**(*pts+2)).Name);
	printf("third Employee Id : %d\n",(**(*pts+2)).id);




	return 0;
}
