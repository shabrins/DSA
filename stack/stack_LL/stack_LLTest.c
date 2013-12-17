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

// void test_to_insert_element_in__the_end_int(){
//     int value;
//     Node *result;
//     list = create();
//     value = 10;
//     push(list,&value);
//     ASSERT(10 == *(int*)list->head->element);
//     ASSERT(NULL == list->head->next);
//     ASSERT(1 == list->length);
    
//     value = 12;
//     push(list,&value);
//     result = list->head->next;
//     ASSERT(12 == *(int*)result->element);
//     ASSERT(NULL == result->next);
//     ASSERT(2 == list->length);
// }
// void test_inserts_elements_at_the_end_of_linkList_for_character(){
//     char value;
//     Node *result1,*result2;
//     list = create();
//     value = 'a';
//     push(list,&value);
//     ASSERT('a' == *(char*)list->head->data);
//     ASSERT(NULL == list->head->next);
//     ASSERT(1 == list->length);
    
//     value = 'b';
//     push(list,&value);
//     result1 = list->head->next;
//     ASSERT('b' == *(char*)result1->data);
//     ASSERT(NULL == result1->next);
//     ASSERT(2 == list->length);
// }
// void test_inserts_elements_at_the_end_of_linkList_for_string(){
//     String value;
//     Node *result1,*result2;
//     list = create();
//     strcpy(value,"shital");
//     push(list,&value);
//     ASSERT(!strcmp("shital",*(String*)list->head->data));
//     ASSERT(NULL == list->head->next);
//     ASSERT(1 == list->length);
//     strcpy(value,"komal");
//     push(list,&value);
//     result1 = list->head->next;
//     ASSERT(!strcmp("komal",*(String*)list->head->data));
//     ASSERT(NULL == result1->next);
//     ASSERT(2 == list->length);
// }
// void test_deletes_last_element_in_the_linkList(){
//     int* values = malloc(sizeof(int)*4);
//     void* result;
//     list = create();
//     values[0] = 10;values[1] = 15;values[2] = 16;values[3] = 17;
//     push(list,&values[0]);
//     push(list,&values[1]);
//     push(list,&values[2]);
//     result = pop(list);
//     ASSERT(*(int*)result == 16);
//     ASSERT(2 == list->length);
//     result = pop(list);
//     ASSERT(*(int*)result == 15);
//     ASSERT(1 == list->length);
//     result = pop(list);
//     ASSERT(*(int*)result == 10);
//     ASSERT(0 == list->length);
// }
// void test_deletes_last_element_in_the_linkList_for_character(){
//     char* values = malloc(sizeof(char)*4);
//     void* result;
//     list = create();
//     values[0] = 'a';values[1] = 'b';values[2] = 'c';values[3] = 'd';
//     push(list,&values[0]);
//     push(list,&values[1]);
//     push(list,&values[2]);
//     result = pop(list);
//     ASSERT(*(char*)result == 'c');
//     ASSERT(2 == list->length);
//     result = pop(list);
//     ASSERT(*(char*)result == 'b');
//     ASSERT(1 == list->length);
//     result = pop(list);
//     ASSERT(*(char*)result == 'a');
//     ASSERT(0 == list->length);
// }