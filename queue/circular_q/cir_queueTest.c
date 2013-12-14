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
        QUEUE res =enQueue(actual,&value);
        int* data = (int*)actual->elements;
        ASSERT(data[0] == TRUE);
        dispose(actual);
}
void test_to_enter_float_element_in_queue(){
        Queue* actual = createQueue(2,sizeof(float));
        float value = 89.0;
        float* data;
        int res = enQueue(actual,&value);
        data = (float*)actual->elements;
        ASSERT(data[0] == 89.0);
        dispose(actual);
}
void test_to_enter_double_element_in_queuee(){
        Queue* actual = createQueue(2,sizeof(double));
        double value = 89.0;
        double* data;
        int res = enQueue(actual,&value);
        data = (double*)actual->elements;
        ASSERT(data[0] == 89.0);
        dispose(actual);
}
void test_to_enter_string_element_in_queue(){
        Queue* actual = createQueue(2,sizeof(String));
        String value = "shital";
        String* data;
        int res = enQueue(actual,&value);
        data = (String*)actual->elements;
        ASSERT(0 == strcmp(data[0], "shital"));
        dispose(actual);
}
void test_to_enter_char_element_in_queue(){
        Queue* actual = createQueue(2,sizeof(char));
        char value = 'A';
        char* data;
        int res = enQueue(actual,&value);
        data = (char*)actual->elements;
        ASSERT(data[0] == 'A');
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
        void* result;
        int value[4] = {3,4,5,6};
        int* data;
        enQueue(actual, &value[0]);
        enQueue(actual, &value[1]);
        enQueue(actual, &value[2]);
        enQueue(actual, &value[3]);
        result = (int*)deQueue(actual);
        data = (int*)actual->elements;
        ASSERT(*(int*)result == 3);
        ASSERT((actual->front) == 1);
        ASSERT(actual->rear == 3);
        dispose(actual);
}

void test_to_delete_float_element_from_Queue(){
        Queue* actual = createQueue(sizeof(float),3);
        float value[3] = {3,4,5};
        void* result;
        float* data;
        enQueue(actual, &value[0]);
        enQueue(actual, &value[1]);
        enQueue(actual, &value[2]);
        result = (float*)deQueue(actual);
        result = (float*)deQueue(actual);
        data = (float*)actual->elements;
        ASSERT(actual->front == 2);
        ASSERT(*(float*)result == 3);
        ASSERT(actual->rear == 2);
        dispose(actual);
}
void test_to_delete_float_element_from_empty_Queue(){
        Queue* actual = createQueue(sizeof(float),5);
        void* result;
        result = deQueue(actual);
        ASSERT(result == NULL);
        dispose(actual);
}

void test_to_enter_new_element_at_the_0_location_for_int_element(){
        Queue* actual = createQueue(sizeof(int),4);
        void* result;
        int* data;
        int value[5] = {5,6,7,8,9};
        enQueue(actual,&value[0]);
        enQueue(actual,&value[1]);
        enQueue(actual,&value[2]);
        enQueue(actual,&value[3]);
        result = deQueue(actual);
        enQueue(actual, &value[4]);
        data = (int*)actual->elements;
        ASSERT(data[0] == 9);        
        ASSERT(*(int*)result = 5);
        
}

void test_to_enter_new_element_at_the_0_location_for_float_element(){
        Queue* actual = createQueue(sizeof(float),4);
        void* result;
        float* data;
        float value[5] = {5.0,6.0,7.0,8.0,9.0};
        enQueue(actual,&value[0]);
        enQueue(actual,&value[1]);
        enQueue(actual,&value[2]);
        enQueue(actual,&value[3]);
        result = deQueue(actual);
        enQueue(actual, &value[4]);
        data = (float*)actual->elements;
        ASSERT(data[0] == 9.0);        
        ASSERT(*(float*)result = 5.0);
        
}

void test_to_enter_new_element_at_the_0_location_for_double_element(){
        Queue* actual = createQueue(sizeof(double),4);
        void* result;
        double* data;
        double value[5] = {5.00000,6.00000,7.00000,8.00000,9.00000};
        enQueue(actual,&value[0]);
        enQueue(actual,&value[1]);
        enQueue(actual,&value[2]);
        enQueue(actual,&value[3]);
        result = deQueue(actual);
        enQueue(actual, &value[4]);
        data = (double*)actual->elements;
        ASSERT(data[0] == 9.00000);        
        ASSERT(*(double*)result = 5.00000);
        
}
// void test_to_delete_string_element_from_Queue_14(){
// 	Queue* actual = createQueue(sizeof(String),5);
// 	String result;
// 	String value = {'shabrin','shital','kajal'};
// 	void* data;
// 	enQueue(actual, &value[0]);
// 	enQueue(actual, &value[1]);
// 	enQueue(actual, &value[2]);
// 	strcpy(result,*(String*)deQueue(actual));
	
// 	ASSERT(strcmp(result,'shabrin'));
// 	ASSERT(actual->rear == 0);
// 	free(actual);
// }


void test_to_enter_new_element_at_the_1_location_for_int_element(){
        Queue* actual = createQueue(sizeof(int),6);
        void* result;
        int* data;
        int value[6] = {5,6,7,8,9,0};
        enQueue(actual,&value[0]);
        enQueue(actual,&value[1]);
        enQueue(actual,&value[2]);
        enQueue(actual,&value[3]);
        enQueue(actual, &value[4]);
        enQueue(actual, &value[5]);
        result = deQueue(actual);
        enQueue(actual, &value[0]);
        data = (int*)actual->elements;
        ASSERT((actual->front) == 1);
        ASSERT(actual->rear == 0);
        ASSERT(data[0] == 5);        
        ASSERT(*(int*)result = 5);

}


// void test_to_enter_new_element_at_the_1_location_for_int_element(){
// result=
// }