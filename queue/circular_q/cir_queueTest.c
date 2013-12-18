#include "testUtils.h"
#include "cir_Queue.h"

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
        int value = 1;
        ASSERT(enQueue(actual,&value));
        ASSERT(deQueue(actual));
        dispose(actual);
}
void test_to_enter_float_element_in_queue(){
        Queue* actual = createQueue(2,sizeof(float));
        float value = 89.0;
        ASSERT(enQueue(actual,&value));
        ASSERT(deQueue(actual));
        dispose(actual);
}
void test_to_enter_double_element_in_queue(){
        Queue* actual = createQueue(2,sizeof(double));
        double value = 89.0;
        ASSERT(enQueue(actual,&value));
        ASSERT(deQueue(actual));
        dispose(actual);
}
void test_to_enter_string_element_in_queue(){
        Queue* actual = createQueue(2,sizeof(String));
        String value = "shital";
        ASSERT(enQueue(actual,&value));
        ASSERT(deQueue(actual));
        dispose(actual);
}
void test_to_enter_char_element_in_queue(){
        Queue* actual = createQueue(2,sizeof(char));
        char value = 'A';
        ASSERT(enQueue(actual,&value));
        ASSERT(deQueue(actual));
        dispose(actual);
}

void test_to_enter_int_element_into_Queue_when_it_is_full(){
        Queue* actual = createQueue(sizeof(int),4);
        float value = 5;
        actual->rear = 3;
        ASSERT(enQueue(actual,&value) == 0);
        dispose(actual);
}

void test_to_enter_float_element_into_Queue_when_it_is_full(){
        Queue* actual = createQueue(sizeof(float),4);
        float value = 5.0;
        actual->rear = 3;
        ASSERT(enQueue(actual,&value) == 0);
        dispose(actual);
}

void test_to_delete_int_element_from_Queue(){
        Queue* actual = createQueue(sizeof(int),4);
        int value[4] = {3,4,5,6};
        ASSERT(enQueue(actual, &value[0]));
        ASSERT(enQueue(actual, &value[1]));
        ASSERT(enQueue(actual, &value[2]));
        ASSERT(enQueue(actual, &value[3]));
        ASSERT((int*)deQueue(actual));
        ASSERT(enQueue(actual, &value[0]));
        dispose(actual);
}

void test_to_delete_float_element_from_Queue(){
        Queue* actual = createQueue(sizeof(int),4);
        int value[4] = {3.0,4.0,5.0,6.0};
        ASSERT(enQueue(actual, &value[0]));
        ASSERT(enQueue(actual, &value[1]));
        ASSERT(enQueue(actual, &value[2]));
        ASSERT(enQueue(actual, &value[3]));
        ASSERT((int*)deQueue(actual));
        ASSERT(enQueue(actual, &value[0]));
        dispose(actual);
}
void test_to_delete_float_element_from_empty_Queue(){
        Queue* actual = createQueue(sizeof(float),5);
        ASSERT(NULL == deQueue(actual));
        dispose(actual);
}

void test_to_enter_new_element_at_the_0_location_for_int_element(){
        Queue* actual = createQueue(sizeof(int),4);
        int value[5] = {5,6,7,8,9};
        ASSERT(enQueue(actual,&value[0]));
        ASSERT(enQueue(actual,&value[1]));
        ASSERT(enQueue(actual,&value[2]));
        ASSERT(enQueue(actual,&value[3]));
        ASSERT(deQueue(actual));
        ASSERT(enQueue(actual, &value[4]));
}

void test_to_enter_new_element_at_the_0_location_for_float_element(){
       Queue* actual = createQueue(sizeof(float),4);
        float value[5] = {5.0,6.0,7.0,8.0,9.0};
        ASSERT(enQueue(actual,&value[0]));
        ASSERT(enQueue(actual,&value[1]));
        ASSERT(enQueue(actual,&value[2]));
        ASSERT(enQueue(actual,&value[3]));
        ASSERT(deQueue(actual));
        ASSERT(enQueue(actual, &value[4]));        
}

void test_to_enter_new_element_at_the_0_location_for_double_element(){
        Queue* actual = createQueue(sizeof(double),4);
        double value[5] = {5.00000,6.00000,7.00000,8.00000,9.00000};
        ASSERT(enQueue(actual,&value[0]));
        ASSERT(enQueue(actual,&value[1]));
        ASSERT(enQueue(actual,&value[2]));
        ASSERT(enQueue(actual,&value[3]));
        ASSERT(deQueue(actual));
        ASSERT(enQueue(actual, &value[4]));   
}

void test_to_enter_new_element_at_the_1_location_for_int_element(){
        Queue* actual = createQueue(sizeof(int),6);
        int value[6] = {5,6,7,8,9,0};
        ASSERT(enQueue(actual,&value[0]));
        ASSERT(enQueue(actual,&value[1]));
        ASSERT(enQueue(actual,&value[2]));
        ASSERT(enQueue(actual,&value[3]));
        ASSERT(deQueue(actual));
        ASSERT(enQueue(actual, &value[0]));
}


