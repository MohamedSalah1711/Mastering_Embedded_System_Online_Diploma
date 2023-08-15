/*
 * Lifo.c
 * Made by >>> Mohamed salah fathy
 * Learn-In-Depth course
 * Implementation of Lifo
 */
#include "Lifo.h"
/*
 * Function: Lifo_Init
 * ----------------------------
 * PURPOSE : init the buffer and the struct
 * returns: Returns enum value indicates buffer states
 */
Buf_states Lifo_Init(Buf_t* L_Buf,unsigned char* buf,unsigned int length){
	if(buf==NULL){
			return LIFO_NULL;
		}
	L_Buf->count=0;
	L_Buf->base=buf;
	L_Buf->head=buf;
	L_Buf->length=length;

	return LIFO_NO_ERROR;
}
/*
 * Function: Lifo_Push_Item
 * ----------------------------
 * PURPOSE : Push item in stack buffer
 * returns: Returns enum value indicates buffer states
 */
Buf_states Lifo_Push_Item(Buf_t* L_Buf,unsigned char item){
	/*check if buffer is full*/
	if((L_Buf->count)==(L_Buf->length)){
		return LIFO_FULL;
	}
	/*check if pointer is valid*/
	if(L_Buf->base==NULL || L_Buf->head==NULL){
		return LIFO_NULL;
	}
	*(L_Buf->head)=item;
	L_Buf->head++;
	L_Buf->count++;

	return LIFO_NO_ERROR;
}
/*
 * Function: Lifo_Pop_Item
 * ----------------------------
 * PURPOSE : Pop item from stack buffer
 * returns: Returns enum value indicates buffer states
 */
Buf_states Lifo_Pop_Item(Buf_t* L_Buf,unsigned char* item){
	if(L_Buf->base==NULL || L_Buf->head==NULL){
			return LIFO_NULL;
		}
	if((L_Buf->count)==0){
		return LIFO_EMPTY;
	}
	L_Buf->head--;
	L_Buf->count--;
	*item=*(L_Buf->head);
	return LIFO_NO_ERROR;
}

