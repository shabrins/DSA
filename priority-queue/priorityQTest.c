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

void test_to_enqueueElements_in_the_PQ_int(){
    int value = 10;
    Node firstNode = {&value,30,NULL};
    pq = create();
    ASSERT(1 == enqueueElements(pq, &firstNode,compareInt));
}

void test_to_enqueueElements_in_the_PQ_float(){
	float value = 10.0;
 	Node firstNode = {&value,30,NULL};
	pq = create();
	ASSERT(1 == enqueueElements(pq, &firstNode,compareInt));
	
}
void test_to_enqueueElements_in_the_PQ_double(){
	double value = 100.00000;
	Node firstNode = {&value,30,NULL};
	pq = create();
	ASSERT(1 == enqueueElements(pq, &firstNode,compareInt));
}

void test_to_enqueueElements_in_the_PQ_char(){
	char value = 'A';
	Node firstNode = {&value,30,NULL};
	pq = create();
	ASSERT(1 == enqueueElements(pq, &firstNode,compareInt));
}

void test_to_enqueueElements_in_the_PQ_string(){
	String value = "apple";
	Node firstNode = {&value,30,NULL};
	pq = create();
	ASSERT(1 == enqueueElements(pq, &firstNode,compareInt));
	
}

void test_to_enqueueElements_in_the_PQ_int_with_high_priority(){
	int value[] = {10,20};
	List expected = {NULL,0};
	Node firstNode = {&value[0],30,NULL};
	Node secondNode = {&value[1],20,NULL};
	pq = create();
	ASSERT(1 == enqueueElements(pq, &firstNode,compareInt));
	ASSERT(2 == enqueueElements(pq, &secondNode,compareInt));
	
}

void test_to_enqueueElements_in_the_PQ_with_high_priority_float(){
	float value[] = {20.0,10.0};
	List expected = {NULL,0};
	Node firstNode = {&value[0],30,NULL};
	Node secondNode = {&value[1],20,NULL};
	pq = create();
	ASSERT(1 == enqueueElements(pq, &firstNode,compareInt));
	ASSERT(2 == enqueueElements(pq, &secondNode,compareInt));
	
}

void test_to_enqueueElements_in_the_PQ_with_high_priority_char(){
	char value[] = {'a','b'};
	List expected = {NULL,0};
	Node firstNode = {&value[0],30,NULL};
	Node secondNode = {&value[1],20,NULL};
	pq = create();
	ASSERT(1 == enqueueElements(pq, &firstNode,compareInt));
	ASSERT(2 == enqueueElements(pq, &secondNode,compareInt));
	
}

void test_to_enqueueElements_in_middle_in_the_PQ_int(){
    int value = 10;
    List expected = {NULL,0};
	Node *second,*third;
	Node firstNode = {&value,40,NULL};
	Node secondNode = {&value,30,NULL};
	Node thirdNode = {&value,20,NULL};
	pq = create();
	ASSERT(1 == enqueueElements(pq, &firstNode,compareInt));
	ASSERT(2 == enqueueElements(pq, &secondNode,compareInt));
	ASSERT(3 == enqueueElements(pq, &thirdNode,compareInt));
}

	
void test_dequeueElements_element_from_PQ_per_priority(){
	int value[] = {10,20,30};
	Node *second,*third;
	Node firstNode = {&value[0],40,NULL};
	Node secondNode = {&value[1],30,NULL};
	Node thirdNode = {&value[2],20,NULL};
	pq = create();
	ASSERT(1 == enqueueElements(pq, &firstNode,compareInt));
	ASSERT(2 == enqueueElements(pq, &secondNode,compareInt));
	ASSERT(3 == enqueueElements(pq, &thirdNode,compareInt));
	ASSERT(0 == dequeueElements(pq));
	ASSERT(0 == dequeueElements(pq));
	ASSERT(0 == dequeueElements(pq));
}
void test_to_remove_from_empty_PQ(){
    pq = create();
        ASSERT(1 == dequeueElements(pq));
}