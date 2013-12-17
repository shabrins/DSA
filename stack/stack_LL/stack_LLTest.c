#include "testUtils.h"
#include "stack_LL.h"
#include "linkedList.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



typedef char String[256];

SList* s;

void tearDown(){
        free(s);
}


void test_create_SLinkedlist_with_head_pointing_to_NULL(){
    s = create();
    ASSERT(NULL == s->head);
    ASSERT(0 == s->length);
}

void test_to_insert_element_in_the_front_int(){
    int value = 10;
    int result;
    list = create();
    result = push(List,&value);
    ASSERT(result==1);
    ASSERT(10 == *(int*)list->head->element);
    ASSERT(NULL == list->head->next);
    ASSERT(1 == list->length);
}