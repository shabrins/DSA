#include "process.h"
#include <stdlib.h>

Scheduler* create(){
    Scheduler *pqueue = calloc(sizeof(Scheduler),1);
    return pqueue;
};

int frontInsertion(Scheduler *pqueue, Process *process){
    if(pqueue->front == NULL)
        process->next = NULL;
    else process->next = pqueue->front;
    pqueue->front = process;
    pqueue->length++;
    return pqueue->length;
}
int enqueue(Scheduler *pqueue, Process* process,compFunc* compare){
    Process *previous,*next,*temp;
    temp = pqueue->front;
    if(pqueue->length == 0 || (compare(&process->priority,&temp->priority) < 0))
        return frontInsertion(pqueue, process);
    for(;temp->next != NULL;temp = temp->next){
        previous = temp;
        next = temp->next;
        if(process->priority < next->priority){
            previous->next = process;
            process->next = next;
            return ++pqueue->length;
        }
    };
    temp->next = process;
    process->next = NULL;
    return ++pqueue->length;
}
int dequeue(Scheduler *pqueue){
    Process* temp,*previous,*next;
    int i = 0;
    temp = pqueue->front;
    if(pqueue->length == 1){
        if(temp->seconds == 0)
            pqueue->front = NULL;
        return --pqueue->length;
    }
    if(temp->seconds == 0)
        pqueue->front = temp->next;
    for(;temp->next != NULL;temp = temp->next){
        previous = temp;
        next = temp->next;
        if(next->seconds == 0){
            previous->next = next->next;
            return --pqueue->length;
        }
    }
    if(NULL == temp->next){
        previous->next = NULL;
        return --pqueue->length;
    };
    return 0;
}
