#include "testUtils.h"
#include "process.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Scheduler *pq;
void teardown(){
    free(pq);
}
int compareInt(void* a , void* b){
    return (*(int*)a - *(int*)b);
}
void test_to_create_new_process_scheduler(){
    Scheduler expected = {NULL,0};
    pq = create();
    ASSERT(pq->front == expected.front);
    ASSERT(pq->length == expected.length);
};

void test_to_add_process_in_the_scheduler(){
    Scheduler expected = {NULL,0};
    Condition status = {0,1,0};
    Process process1 = {"process1",1000,status,2,NULL};
    pq = create();
    ASSERT(1 == enqueue(pq, &process1,compareInt));
    ASSERT(pq->front == &process1);
    ASSERT(pq->front->next == NULL);
};

void test_to_add_process_with_high_priority_in_the_scheduler(){
    Scheduler expected = {NULL,0};
    Condition status = {0,1,0};
    Process process1 = {"process1",1000,status,2,NULL};
    Process process2 = {"process2",900,status,1,NULL};
    pq = create();
    ASSERT(1 == enqueue(pq, &process1,compareInt));
    ASSERT(2 == enqueue(pq, &process2,compareInt));
    ASSERT(pq->front == &process2);
    ASSERT(pq->front->next == &process1);
};

void test_to_add_process_with_high_priority_in_between_the_scheduler(){
    Scheduler expected = {NULL,0};
    Condition status = {0,1,0};
    Process *second,*third;
    Process process1 = {"First Process",3000,status,3,NULL};
    Process process2 = {"Second Process",900,status,1,NULL};
    Process process3 = {"Third Process",400,status,2,NULL};
    pq = create();
    ASSERT(1 == enqueue(pq, &process1,compareInt));
    ASSERT(2 == enqueue(pq, &process2,compareInt));
    ASSERT(3 == enqueue(pq, &process3,compareInt));
    ASSERT(pq->front == &process2);
    second = pq->front->next;
    third = second->next;
    ASSERT(second == &process3);
    ASSERT(third == &process1);
    ASSERT(third->next == NULL);
};

void test_to_add_process_with_low_priority_in_the_scheduler(){
    Condition statusprocess1 = {0,1,0};
    Process *second,*third,*fourth,*fifth;
    Process process1 = {"process1",1000,statusprocess1,5,NULL};
    Process process2 = {"process2",500,statusprocess1,1,NULL};
    Process process3 = {"process3",400,statusprocess1,3,NULL};
    Process process4 = {"process4",400,statusprocess1,2,NULL};
    Process process5 = {"process5",400,statusprocess1,8,NULL};
    pq = create();
    ASSERT(1 == enqueue(pq, &process1,compareInt));
    ASSERT(2 == enqueue(pq, &process2,compareInt));
    ASSERT(3 == enqueue(pq, &process3,compareInt));
    ASSERT(4 == enqueue(pq, &process4,compareInt));
    ASSERT(5 == enqueue(pq, &process5,compareInt));
    second = pq->front->next;
    third = second->next;
    fourth = third->next;
    fifth = fourth->next;
    ASSERT(fifth == &process5);
    ASSERT(NULL == fifth->next);
};

void test_to_remove_the_process_from_scheduler(){
    Condition statusprocess1 = {0,1,0};
    Process process1 = {"process1",0,statusprocess1,5,NULL};
    pq = create();
    enqueue(pq, &process1,compareInt);
    ASSERT(0 == dequeue(pq));
    ASSERT(NULL == pq->front);
};

void test_to_remove_the_process_in_the_middle_from_scheduler(){
    Condition statusprocess1 = {0,1,0};
    Process process1 = {"process1",1000,statusprocess1,1,NULL};
    Process process2 = {"process2",0,statusprocess1,5,NULL};
    Process process3 = {"process3",1000,statusprocess1,7,NULL};
    pq = create();
    enqueue(pq, &process1,compareInt);
    enqueue(pq, &process2,compareInt);
    enqueue(pq, &process3,compareInt);
    ASSERT(2 == dequeue(pq));
    ASSERT(pq->front->next == &process3);
};

void test_to_remove_the_last_process_from_scheduler(){
    Condition statusprocess1 = {0,1,0};
    Process process1 = {"process1",1000,statusprocess1,1,NULL};
    Process process2 = {"process2",10,statusprocess1,5,NULL};
    Process process3 = {"process3",0,statusprocess1,7,NULL};
    pq = create();
    enqueue(pq, &process1,compareInt);
    enqueue(pq, &process2,compareInt);
    enqueue(pq, &process3,compareInt);
    ASSERT(2 == dequeue(pq));
    ASSERT(pq->front->next->next == NULL);
};
