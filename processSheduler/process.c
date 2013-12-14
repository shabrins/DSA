#include "process.h"
#include <stdio.h>
#include <stdlib.h>

ProcessScheduler* create(){
        ProcessScheduler* pq = malloc(sizeof(ProcessScheduler));
        pq->length=0;
        pq->rear=-1;
        return pq;
}

int Qfull(ProcessScheduler* pq){                    
 if(pq->front == -1) return 1;
 return 0;
};
 
int Qempty(ProcessScheduler* pq){                   
 if(pq->front > pq->rear) return 1;
 return 0;
};


int PQinsert(ProcessScheduler* pq, PQ* p){
        if(pq->length==0 && pq->rear==-1){
                pq->bufferHead = p;
                p->link = pq->bufferHead;
                pq->rear++;
                pq->length++;
                return 1;
        }
        if(pq->length > 0 && pq->rear > -1){
                PQ* temp_value = pq->bufferHead;
                while(temp_value->link != pq->bufferHead){
                        temp_value = temp_value->link;
                }
                temp_value->link = p;
                p->link = pq->bufferHead;
                pq->rear++;
                pq->length++;
                return 1;
        };



        return 1;
}

ProcessScheduler* PQdelete(){                     
	 ProcessScheduler* pq;
	 if(Qempty(pq)){
	 pq->length=-1;
	 pq->front=-1;
	 return(pq); 
	}
	 else
	 {
	  pq = pq[front];
	  front = front+1;
	  return TRUE;
	 }
	}

