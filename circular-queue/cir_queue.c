#include "cir_queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
Queue * createQueue(int length,int typeSize){
	Queue *q;
    q = (Queue *)malloc(sizeof(Queue));
    q->elements = calloc(length,typeSize);
    q->capacity = length;
    q->length = typeSize;
    q->front = 0;
    q->rear = -1;
    return q;
}
int isFull(Queue* q){
	if(q->capacity-1 == q->rear)
		return TRUE;
	return FALSE;
}
int isEmpty(Queue* q){
	if(q->rear==-1)
		return TRUE;
	return FALSE;
}
int enQueue(Queue *q,void* element){
	int length = q->front;
	if(q->front > 0 && q->length)
		q->rear = -1;
	if(isFull(q))
        return 0;
    else{
    	void* address;
        q->length++;
        q->rear++;
        address = q->elements+(q->rear*q->length);
		memmove(address,element, q->length);
    }
    return 1;
}

void* deQueue(Queue* queue){
        if(isEmpty(queue)) return NULL;        
        queue->front++;
        return queue->elements;

}

void* front(Queue *q){
    if(q->rear == -1)
    	return NULL;
    return &q->front;
}

void dispose(Queue *q){
    free(q->elements);
 }
