#include "testUtils.h"
#include "priorityQ.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int compareInt (void* a, void* b){
    return (*(int*)a - *(int*)b);
}
List *pq;
void teardown(){
    free(pq);
}
void test_to_create_a_new_process(){
    List expected = {NULL,0};
    pq = create();
    ASSERT(pq->front == expected.front);
    ASSERT(pq->length == expected.length);
}
void test_to_enqueue_elements_in_the_PQ_int(){
    int value = 10;
    PQueue firstNode = {&value,30,NULL};
    pq = create();
    ASSERT(1 == enqueue(pq, &firstNode,compareInt));
    ASSERT(pq->front == &firstNode);
    ASSERT(pq->front->next == NULL);
}
void test_to_enqueue_elements_in_the_PQ_float(){
	float value = 10.0;
 	PQueue firstNode = {&value,30,NULL};
	pq = create();
	ASSERT(1 == enqueue(pq, &firstNode,compareInt));
	ASSERT(pq->front == &firstNode);
	ASSERT(pq->front->next == NULL);
}
void test_to_enqueue_elements_in_the_PQ_double(){
	double value = 100.00000;
	PQueue firstNode = {&value,30,NULL};
	pq = create();
	ASSERT(1 == enqueue(pq, &firstNode,compareInt));
	ASSERT(pq->front == &firstNode);
	ASSERT(pq->front->next == NULL);
}
void test_to_enqueue_elements_in_the_PQ_char(){
	char value = 'A';
	PQueue firstNode = {&value,30,NULL};
	pq = create();
	ASSERT(1 == enqueue(pq, &firstNode,compareInt));
	ASSERT(pq->front == &firstNode);
	ASSERT(pq->front->next == NULL);
}
void test_to_enqueue_elements_in_the_PQ_string(){
	String value = "apple";
	PQueue firstNode = {&value,30,NULL};
	pq = create();
	ASSERT(1 == enqueue(pq, &firstNode,compareInt));
	ASSERT(pq->front == &firstNode);
	ASSERT(pq->front->next == NULL);
}
void test_to_enqueue_elements_in_the_PQ_int_with_high_priority(){
	int value[] = {10,20};
	List expected = {NULL,0};
	PQueue firstNode = {&value[0],30,NULL};
	PQueue secondNode = {&value[1],20,NULL};
	pq = create();
	ASSERT(1 == enqueue(pq, &firstNode,compareInt));
	ASSERT(2 == enqueue(pq, &secondNode,compareInt));
	ASSERT(pq->front == &secondNode);
	ASSERT(pq->front->next == &firstNode);
}

void test_to_enqueue_elements_in_the_PQ_with_high_priority_float(){
	float value[] = {20.0,10.0};
	List expected = {NULL,0};
	PQueue firstNode = {&value[0],30,NULL};
	PQueue secondNode = {&value[1],20,NULL};
	pq = create();
	ASSERT(1 == enqueue(pq, &firstNode,compareInt));
	ASSERT(2 == enqueue(pq, &secondNode,compareInt));
	ASSERT(pq->front == &secondNode);
	ASSERT(pq->front->next == &firstNode);
}

void test_to_enqueue_elements_in_the_PQ_with_high_priority_char(){
	char value[] = {'a','b'};
	List expected = {NULL,0};
	PQueue firstNode = {&value[0],30,NULL};
	PQueue secondNode = {&value[1],20,NULL};
	pq = create();
	ASSERT(1 == enqueue(pq, &firstNode,compareInt));
	ASSERT(2 == enqueue(pq, &secondNode,compareInt));
	ASSERT(pq->front == &secondNode);
	ASSERT(pq->front->next == &firstNode);
}

void test_to_enqueue_elements_in_middle_in_the_PQ_int(){
    int value = 10;
    List expected = {NULL,0};
	PQueue *second,*third;
	PQueue firstNode = {&value,40,NULL};
	PQueue secondNode = {&value,30,NULL};
	PQueue thirdNode = {&value,20,NULL};
	pq = create();
	ASSERT(1 == enqueue(pq, &firstNode,compareInt));
	ASSERT(2 == enqueue(pq, &secondNode,compareInt));
	ASSERT(3 == enqueue(pq, &thirdNode,compareInt));
	ASSERT(pq->front == &thirdNode);
	second = pq->front->next;
	third = second->next;
	ASSERT(second == &secondNode);
	ASSERT(third == &firstNode);
	ASSERT(third->next == NULL);
	}

	
void test_dequeue_element_from_PQ_per_priority(){
	int value[] = {10,20,30};
	PQueue *second,*third;
	PQueue firstNode = {&value[0],40,NULL};
	PQueue secondNode = {&value[1],30,NULL};
	PQueue thirdNode = {&value[2],20,NULL};
	pq = create();
	ASSERT(1 == enqueue(pq, &firstNode,compareInt));
	ASSERT(2 == enqueue(pq, &secondNode,compareInt));
	ASSERT(3 == enqueue(pq, &thirdNode,compareInt));
	ASSERT(pq->front == &thirdNode);
	second = pq->front->next;
	third = second->next;
	ASSERT(second == &secondNode);
	ASSERT(third == &firstNode);
	ASSERT(third->next == NULL);
	ASSERT(0 == dequeue(pq));
	ASSERT(20 == *(int*)pq->front->element);
	ASSERT(pq->length == 2);
	ASSERT(0 == dequeue(pq));
	ASSERT(10 == *(int*)pq->front->element);
	ASSERT(pq->length == 1);
	ASSERT(0 == dequeue(pq));
}
void test_to_remove_from_empty_PQueue(){
    pq = create();
        ASSERT(1 == dequeue(pq));
}