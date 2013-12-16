#include "priorityQ.h"
#include <stdlib.h>
#include <stdio.h>
List* create(){
    List* list = calloc(sizeof(List),1);
    return list;
}
int insertFront(PQueue *process,List *list){
    if(list->front == NULL)
        process->next = NULL;
    else process->next = list->front;
    list->front = process;
    list->length++;
    return list->length;
}
int enqueue(List *list,PQueue *pq,compFunc* compare){
    PQueue *previous,*next,*temp;
    int result;
    temp = list->front;
    if(list->length == 0)
        return insertFront(pq,list);
           if(compare(&pq->priority,&temp->priority) < 0)
        return insertFront(pq,list);
    while(temp != NULL){
        previous = temp;
        next = temp->next;
        temp = temp->next;
        if(pq->priority < next->priority){
                previous->next = pq;
                    pq->next = next;
                    return ++list->length;
        }
    };
    return 0;
}
int dequeue(List *list){
        if(list->length == 0) return 1;
        list->front = list->front->next;
        list->length--;
    return 0;
}