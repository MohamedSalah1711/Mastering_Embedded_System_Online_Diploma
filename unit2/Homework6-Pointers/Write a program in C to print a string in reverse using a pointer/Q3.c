/*unit 2
 * Pointers HomeWork
 * Q3.c
 *  Mastering embedded system diploma
 * Author: Mohamed salah fathy
 */
#include <stdio.h>
int main(){
	setbuf(stdout,NULL);	/*Solving eclipse problem*/
	char str[30];
	char rev_str[30];
	char *ptr_str=str;
	char *ptr_rev=rev_str;
	int i;
	printf("enter string ");
	gets(str);
	for(i=0;str[i]!='\0';i++){
		ptr_str++;
	}
	ptr_str--;
	i--;
	for(;i>=0;i--){
		*ptr_rev=*ptr_str;
		ptr_rev++;
		ptr_str--;

	}
	*ptr_rev='\0';
	puts(rev_str);
	return 0;
}
