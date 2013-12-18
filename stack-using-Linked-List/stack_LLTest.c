#include "testUtils.h"
#include "stack_LL.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Stack* front;

void setup(){
        front = create();
}

void tearDown(){
        dispose(front);
}

void test_to_push_element_in_the_stack_int(){
        int element1 = 1;
        int element2 = 2;
        pushElement(front, &element1);
        ASSERT(1 == front->length);
        ASSERT(element1 == *(int*)(front->head->element));
        pushElement(front, &element2);
        ASSERT(element2 == *(int*)(front->head->next->element));
}

void test_to_push_element_in_the_stack_float(){
        float element1 = 1.0;
        float element2 = 2.0;
        pushElement(front, &element1);
        ASSERT(1 == front->length);
        ASSERT(element1 == *(float*)(front->head->element));
        pushElement(front, &element2);
        ASSERT(element2 == *(float*)(front->head->next->element));
}

void test_to_push_element_in_the_stack_double(){
        double element1 = 1.00000;
        double element2 = 2.00000;
        pushElement(front, &element1);
        ASSERT(1 == front->length);
        ASSERT(element1 == *(double*)(front->head->element));
        pushElement(front, &element2);
        ASSERT(element2 == *(double*)(front->head->next->element));
}

void test_to_push_element_in_the_stack_char(){
        char element1 = 'a';
        char element2 = 'b';
        pushElement(front, &element1);
        ASSERT(1 == front->length);
        ASSERT(element1 == *(char*)(front->head->element));
        pushElement(front, &element2);
        ASSERT(element2 == *(char*)(front->head->next->element));
}


void test_to_pop_element_from_the_stack(){
        int element1 = 1;
        int element2 = 2;
        pushElement(front, &element1);
        pushElement(front, &element2);
        ASSERT(element1 == *(int*)(front->head->element));
        ASSERT(element2 == *(int*)(front->head->next->element));
        popElement(front);
        ASSERT(NULL == front->head->next);
        ASSERT(front->length == 1);
        popElement(front);
        ASSERT(front->length == 0);
        ASSERT(NULL == front->head);
}

void test_to_pop_element_from_the_stack_float(){
        float element1 = 1.0;
        float element2 = 2.0;
        pushElement(front, &element1);
        pushElement(front, &element2);
        ASSERT(element1 == *(float*)(front->head->element));
        ASSERT(element2 == *(float*)(front->head->next->element));
        popElement(front);
        ASSERT(NULL == front->head->next);
        ASSERT(front->length == 1);
        popElement(front);
        ASSERT(front->length == 0);
        ASSERT(NULL == front->head);
}

void test_to_pop_element_from_the_stack_double(){
        double element1 = 1.00000;
        double element2 = 2.00000;
        pushElement(front, &element1);
        pushElement(front, &element2);
        ASSERT(element1 == *(double*)(front->head->element));
        ASSERT(element2 == *(double*)(front->head->next->element));
        popElement(front);
        ASSERT(NULL == front->head->next);
        ASSERT(front->length == 1);
        popElement(front);
        ASSERT(front->length == 0);
        ASSERT(NULL == front->head);
}


void test_to_pop_element_from_the_stack_char(){
        char element1 = 'a';
        char element2 = 'b';
        pushElement(front, &element1);
        pushElement(front, &element2);
        ASSERT(element1 == *(char*)(front->head->element));
        ASSERT(element2 == *(char*)(front->head->next->element));
        popElement(front);
        ASSERT(NULL == front->head->next);
        ASSERT(front->length == 1);
        popElement(front);
        ASSERT(front->length == 0);
        ASSERT(NULL == front->head);
}

void test_to_check_whether_the_stack_is_Empty(){
        ASSERT(isEmpty(front));
}


void test_to_get_the_peek_element_of__the_stack(){
        int arr[] = {1,2,3,4};
        pushElement(front, &arr);
        ASSERT(1 == *(int*)(peek(front)));
        pushElement(front, &arr[1]);
        ASSERT(2 == *(int*)(peek(front)));
        pushElement(front, &arr[2]);
        ASSERT(3 == *(int*)(peek(front)));
}