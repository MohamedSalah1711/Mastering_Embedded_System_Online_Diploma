/*
 * FIFO.c
 *
 *  Created on: Aug 11, 2023
 *      Author: mohamed salah
 */
#include "FIFO.h"
FIFO_Buf_status FIFO_init (LIFO_Buf_t* FIFO,element_type* Buff,uint32_t Buff_length){

	FIFO->head=Buff;
	FIFO->tail=Buff;
	FIFO->base=Buff;
	FIFO->count=0;
	FIFO->length=Buff_length;
	if(FIFO->base==NULL || FIFO->length==0){
		return FIFO_NULL;
	}
	return FIFO_NO_ERROR;
}

FIFO_Buf_status FIFO_Enqueue (LIFO_Buf_t* FIFO ,element_type item){
	if(FIFO->head==NULL || FIFO->tail==NULL || FIFO->base==NULL)
		return FIFO_NULL;

	if(FIFO_IS_FULL(FIFO)==FIFO_FULL)
		return FIFO_FULL;
	*(FIFO->head)=item;
	FIFO->count++;
	if((FIFO->head) == ((FIFO->base)+ sizeof(element_type)*(FIFO->length))){
		FIFO->head=FIFO->base;
	}
	else{
		FIFO->head++;
	}

	return FIFO_NO_ERROR;
}
FIFO_Buf_status FIFO_Dequeue (LIFO_Buf_t* FIFO ,element_type* item){
	if(FIFO->head==NULL || FIFO->tail==NULL || FIFO->base==NULL)
		return FIFO_NULL;
	if(FIFO_IS_FULL(FIFO)==FIFO_EMPTY)
		return FIFO_EMPTY;

	*item=*(FIFO->tail);
	FIFO->count--;
	if((FIFO->tail) == ((FIFO->base)+ sizeof(element_type)*(FIFO->length))){
		FIFO->tail=FIFO->base;
	}else{
		FIFO->tail++;
	}
	return FIFO_NO_ERROR;
}
FIFO_Buf_status FIFO_IS_FULL (LIFO_Buf_t* FIFO){
	if(FIFO->count == FIFO->length )
		return FIFO_FULL;
	if(FIFO->count == 0 )
		return FIFO_EMPTY;

	return FIFO_NO_ERROR;
}
void FIFO_PRINT(LIFO_Buf_t* FIFO){
	element_type* temp;
	uint32_t i;
	temp=FIFO->tail;
	if(FIFO_IS_FULL(FIFO)==FIFO_EMPTY){
		printf("FIFO IS EMPTY");
		return FIFO_EMPTY;
	}
	for(i=0 ; i<FIFO->count;i++){
		printf("   %X  \n",*temp);
		temp++;
	}


}
