/*
 * FIFO.h
 *
 *  Created on: Aug 11, 2023
 *      Author: mohamed salah
 */

#ifndef FIFO_H_
#define FIFO_H_
#include <stdio.h>
#include <stdint.h>
#define element_type uint8_t
typedef struct {
	element_type* tail;
	element_type* head;
	element_type* base;
	uint32_t count;
	uint32_t length;
}LIFO_Buf_t;
typedef enum{
	FIFO_NULL,
	FIFO_EMPTY,
	FIFO_FULL,
	FIFO_NO_ERROR
}FIFO_Buf_status;
FIFO_Buf_status FIFO_init (LIFO_Buf_t* FIFO,element_type* Buff,uint32_t Buff_length);
FIFO_Buf_status FIFO_Enqueue (LIFO_Buf_t* FIFO ,element_type item);
FIFO_Buf_status FIFO_Dequeue (LIFO_Buf_t* FIFO ,element_type* item);
FIFO_Buf_status FIFO_IS_FULL (LIFO_Buf_t* FIFO);
void FIFO_PRINT(LIFO_Buf_t* FIFO);
#endif /* FIFO_H_ */
