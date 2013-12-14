#include "testUtils.h"
#include "process.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void test_for_creating_a_bufferHead(){
        ProcessScheduler* pq;
        PQ process1 = {"Browser",10,1};
        pq = create();
        ASSERT(0==pq->length);
        ASSERT(-1==pq->rear);
}

void test_for_inserting_a_process_scheduler(){
        ProcessScheduler* pq;
        PQ process1 = {"Browser",3600,1};
        pq = create();
        PQinsert(pq, &process1);
        ASSERT(pq->bufferHead=&process1);
        ASSERT(pq->length==1);
        ASSERT(pq->rear==0);
}

void test_for_inserting_2_processes_in_process_scheduler(){
        ProcessScheduler* pq;
        PQ process1 = {"Browser",3600,1};
        PQ process2 = {"GCC",1500,1};
        pq = create();
        PQinsert(pq, &process1);
        PQinsert(pq, &process2);
        ASSERT(pq->bufferHead=&process1);
        ASSERT(pq->bufferHead->link=&process2);
        ASSERT(pq->length==2);
        ASSERT(pq->rear==1);
}

void test_to_insert_3_PQes_in_the_scheduler(){
        ProcessScheduler* pq;
        PQ process1 = {"Browser",3600,3};
        PQ process2 = {"GCC",1500,1};
        PQ process3 = {"Nodejs",2000,2};
        pq = create();
        PQinsert(pq, &process1);
        PQinsert(pq, &process2);
        PQinsert(pq, &process3);
        ASSERT(pq->bufferHead=&process1);
        ASSERT(pq->bufferHead->link=&process2);
        ASSERT(pq->bufferHead->link->link = &process3);
        ASSERT(pq->length==3);
        ASSERT(pq->rear==2);
}


void test_for_deleting_a_process_in_scheduler(){
        ProcessScheduler* pq;
        PQ process1 = {"Browser",3600,1};
        pq = create();
        PQinsert(pq, &process1);
        ASSERT(pq->bufferHead=&process1);
        ASSERT(pq->length==1);
        ASSERT(pq->rear==0);
        PQdelete(pq);
        ASSERT(pq->length == 0);
}