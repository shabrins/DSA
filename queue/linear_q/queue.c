#include "Queue.h"
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
	if(isFull(q))
        return 0;
    else{
    	void* address;
        q->length++;
        q->rear = q->rear + 1;
        address = q->elements+(q->rear*q->length);
		memmove(address,element, q->length);
    }
    return 1;
}

void* deQueue(Queue* q){
	void* data = malloc(q->length);
	if(isEmpty(q))
		return NULL;
    memcpy(data,q->elements,q->length);
    memmove(q->elements,q->elements+q->length,(q->capacity-1)*q->length);
    q->rear--;
 	return data;
}

void* front(Queue *q){
    if(q->rear == -1)
    	return NULL;
    return &q->front;
}

void dispose(Queue *q){
    free(q->elements);
 }