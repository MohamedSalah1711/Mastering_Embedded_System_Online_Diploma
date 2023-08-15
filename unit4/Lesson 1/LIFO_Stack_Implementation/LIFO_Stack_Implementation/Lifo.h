/*
 * Lifo.h
 * Made by >>> Mohamed salah fathy
 * Learn-In-Depth course
 * Implementation of Lifo
 */

#ifndef LIFO_H_
#define LIFO_H_
#include <stdio.h>
typedef struct
{
unsigned int length;
unsigned int count;
unsigned char* base;
unsigned char* head;
}Buf_t;
typedef enum {
	LIFO_NO_ERROR,
	LIFO_NULL,
	LIFO_EMPTY,
	LIFO_FULL

}Buf_states;
/*
 * Function: Lifo_Push_Item
 * ----------------------------
 * PURPOSE : Push item in stack buffer
 * returns: Returns enum value indicates buffer states
 */
Buf_states Lifo_Push_Item(Buf_t* L_Buf,unsigned char item);
/*
 * Function: Lifo_Pop_Item
 * ----------------------------
 * PURPOSE : Pop item from stack buffer
 * returns: Returns enum value indicates buffer states
 */
Buf_states Lifo_Pop_Item(Buf_t* L_Buf,unsigned char* item);
/*
 * Function: Lifo_Init
 * ----------------------------
 * PURPOSE : init the buffer and the struct
 * returns: Returns enum value indicates buffer states
 */
Buf_states Lifo_Init(Buf_t* L_Buf,unsigned char* buf,unsigned int length);

#endif /* LIFO_H_ */
