#include "testUtils.h"
#include "queue.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int areEqual(Queue* src,Queue* expected){
	int res = (src->capacity == expected->capacity)
		&& (src->length == expected->length)
		&& (src->front == expected->front)
		&& (src->rear == expected->rear);
		if(!res)
			return res;
		return 0 == memcmp(src->elements, expected->elements, src->length*src->capacity);			
}

void test_to_create_queue_for_integers_1() {
	int expectedArr[2]={0,0};
	Queue expected = {2,sizeof(int),0,-1,expectedArr};
	Queue* src = createQueue(2,sizeof(int));
	ASSERT(areEqual(src, &expected));
}
void test_to_create_queue_for_floats_2() {
	float expectedArr[2]={0.0,0.0};
	Queue expected = {2,sizeof(float),0,-1,expectedArr};
	Queue* src = createQueue(2,sizeof(float));
	ASSERT(areEqual(src, &expected));
}

void test_to_create_Queue_for_double_3() {
	double expectedArr[2]={0.0,0.0};
	Queue expected = {2,sizeof(double),0,-1,expectedArr};
	Queue* src = createQueue(2,sizeof(double));
	ASSERT(areEqual(src, &expected));
}

void test_to_create_queue_for_chars_4() {
	char expectedArr[2]={0,0};
	Queue expected = {2,sizeof(char),0,-1,expectedArr};
	Queue* src = createQueue(2,sizeof(char));
	ASSERT(areEqual(src, &expected));
}
void test_to_create_Queue_for_String_5() {
	String expectedArr[2]={0,0};
	Queue expected = {2,sizeof(String),0,-1,expectedArr};
	Queue* src = createQueue(2,sizeof(String));
	ASSERT(areEqual(src, &expected));
}


void test_to_enter_int_element_in_queue_6(){
	Queue* actual = createQueue(2,sizeof(int));
	int value = 2;
	int* data = (int*)actual->elements;
	ASSERT(1==enQueue(actual,&value));
	free(actual);
}

void test_to_enter_float_element_in_Queue_7(){
	Queue* actual = createQueue(2,sizeof(float));
	float value = 2.0;
	float* data = (float*)actual->elements;
	ASSERT(1==enQueue(actual,&value));
	free(actual);
}

void test_to_enter_double_element_in_Queue_8(){
	Queue* actual = createQueue(2,sizeof(double));
	double value = 2.00000;
	double* data = (double*)actual->elements;
	ASSERT(1==enQueue(actual,&value));
	free(actual);
}


void test_to_enter_string_element_in_queue_9(){
	Queue* actual = createQueue(2,sizeof(String));
	String value = "shabrin";
	String* data;
	int res = enQueue(actual,&value);
	data = (String*)actual->elements;
	ASSERT(0 == strcmp(data[0], "shabrin"));
	free(actual);
}
void test_to_enter_char_element_in_Queue_10(){
	Queue* actual = createQueue(2,sizeof(char));
	char value = '2';
	char* data = (char*)actual->elements;
	ASSERT(1==enQueue(actual,&value));
	free(actual);
}

void test_to_enter_element_in_queue_when_it_is_full_11(){
	Queue* actual = createQueue(2,sizeof(int));
	int value[3] = {1,2,3};
	int* data = (int*)actual->elements;
	enQueue(actual,&value[0]);
	enQueue(actual,&value[1]);
	ASSERT(0==enQueue(actual,&value[2]));
	free(actual);
}


void test_to_delete_int_element_from_Queue_12(){
	Queue* actual = createQueue(sizeof(int),3);
	void* result;
	int value1 = 3;
	int value2 = 4;
	int data;
	enQueue(actual, &value1);
	enQueue(actual, &value2);
	result = (int*)deQueue(actual);
	data = *(int*)actual->elements;
	ASSERT(*(int*)result == 3);
	ASSERT(actual->rear == 0);
	free(actual);
}

void test_to_delete_float_element_from_Queue_13(){
	Queue* actual = createQueue(sizeof(float),3);
	void* result;
	float value1 = 3.0;
	float value2 = 4.0;
	float data;
	enQueue(actual, &value1);
	enQueue(actual, &value2);
	result = (float*)deQueue(actual);
	data = *(float*)actual->elements;
	ASSERT(*(float*)result == 3.0);
	ASSERT(actual->rear == 0);
	free(actual);
}


void test_to_delete_string_element_from_Queue_14(){
	Queue* actual = createQueue(sizeof(String),5);
	String result;
	String value = "3.000000";
	String value1 = "4.000000";
	void* data;
	enQueue(actual, &value);
	enQueue(actual, &value1);
	strcpy(result,*(String*)deQueue(actual));
	ASSERT(strcmp(result,"3.000000"));
	ASSERT(actual->rear == 0);
	free(actual);
}

void test_to_delete_elements_from_empty_queue_15(){
	Queue* actual = createQueue(sizeof(int),5);
	void* result;
	result = deQueue(actual);
	ASSERT(result == NULL);
}