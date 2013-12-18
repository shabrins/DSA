#include "linkedList.h"
#include "testUtils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

SList* list;


typedef char String_256[256];
typedef struct
{
        int accountNumber;
        int balance;
}Account;

int areAccountsEqual(Account expected,Account actual){
        return expected.accountNumber == actual.accountNumber && expected.balance == actual.balance;
}

void tearDown(){
        free(list);
}

void display(Node *q){
        if(q==NULL) printf("element not  available\n");;
     while(q!=NULL){
     printf("\n%d",*(int*)q->element);
     q=q->next;
    }
}


void test_create_SLinkedList_with_head_pointing_to_NULL(){
    list = create();
    ASSERT(NULL == list->head);
    ASSERT(0 == list->length);
}

void test_to_insert_element_in_front_int(){
    int num = 20;
    list = create();
    insertElement(list, 0,&num);
    ASSERT(20 == *(int*)list->head->element);
    ASSERT(NULL == list->head->next);
    ASSERT(1 == list->length);
}

void test_to_insert_one_elements_in_the_end_of_LL_int(){
    int value;
    Node *result1,*result2;
    list = create();
    value = 20;
    insertElement(list,0,&value);
    ASSERT(20 == *(int*)list->head->element);
    ASSERT(NULL == list->head->next);
    ASSERT(1 == list->length);
};

void test_to_insert_multiple_elements_in_the_end_of_LL_int(){
    int value;
    Node *result1,*result2;
    list = create();
    value = 20;
    insertElement(list,0,&value);
    ASSERT(20 == *(int*)list->head->element);
    ASSERT(NULL == list->head->next);
    ASSERT(1 == list->length);
    value = 21;
    insertElement(list,1,&value);
    result1 = list->head->next;
    ASSERT(21 == *(int*)result1->element);
    ASSERT(NULL == result1->next);
    ASSERT(2 == list->length);
    value = 22;
    insertElement(list,2,&value);
    result2 = result1->next;
    ASSERT(22 == *(int*)result2->element);
    ASSERT(NULL == result2->next);
    ASSERT(3 == list->length);
}

void test_to_insert_multiple_elements_at_head(){
    int* value = malloc(sizeof(int)*3);
    list = create();
    value[0] = 11;value[1] = 12;value[2] = 13;
    insertElement(list, 0, value);
    ASSERT(11 == *(int*)list->head->element);
    ASSERT(1 == list->length);
    insertElement(list,0,value+1);
    ASSERT(12 == *(int*)list->head->element);
    insertElement(list,0,value+2);
    ASSERT(13 == *(int*)list->head->element);
    ASSERT(3 == list->length);
}

void test_to_insert_multiple_double_elements_at_head(){
    double* value = malloc(sizeof(double)*3);
    list = create();
    value[0] = 11.0;value[1] = 12.0;value[2] = 13.0;
    insertElement(list, 0, value);
    ASSERT(11.0 == *(double*)list->head->element);
    ASSERT(1 == list->length);
    insertElement(list,0,value+1);
    ASSERT(12.0 == *(double*)list->head->element);
    insertElement(list,0,value+2);
    ASSERT(13.0 == *(double*)list->head->element);
    ASSERT(3 == list->length);
}

void test_to_insert_multiple_char_elements_at_head(){
    char* value = malloc(sizeof(char)*3);
    list = create();
    value[0] = 'a';value[1] = 'b';value[2] = 'c';
    insertElement(list, 0, value);
    ASSERT('a' == *(char*)list->head->element);
    ASSERT(1 == list->length);
    insertElement(list,0,value+1);
    ASSERT('b' == *(char*)list->head->element);
    insertElement(list,0,value+2);
    ASSERT('c' == *(char*)list->head->element);
    ASSERT(3 == list->length);
}

void test_to_add_element_in_middle_of_LL_int(){
    Node *second,*third,*fourth;
    int* value = malloc(sizeof(int)*4);
    value[0] = 12;value[1] = 14;value[2] = 15;value[3] = 20;
    list = create();
    insertElement(list, 0, value+0);
    ASSERT(1 == list->length);
    insertElement(list,1,value+2);
    ASSERT(2 == list->length);
    insertElement(list,2,value+1);
    ASSERT(3 == list->length);
    insertElement(list,1,value+3);
    ASSERT(4 == list->length);
    second = list->head->next;
    third = second->next;
    fourth = third->next;
    ASSERT(12 == *(int*)list->head->element);
    ASSERT(15 == *(int*)second->element);
    ASSERT(20 == *(int*)third->element);
    ASSERT(14 == *(int*)fourth->element);
}


void test_to_insert_string_elements_in_LL(){
    String_256* names = malloc(sizeof(String_256)*3);
    list = create();
    strcpy(names[0], "apple");
    strcpy(names[1], "ball");
    strcpy(names[2], "cat");
    insertElement(list, 0, &names[0]);
    ASSERT(0 == strcmp("apple",(char*)list->head->element));
    ASSERT(1 == list->length);
    insertElement(list, 1, &names[1]);
    ASSERT(0 == strcmp("ball",(char*)list->head->next->element));
    ASSERT(2 == list->length);
}

void test_to_insert_struct_elements_to_LL(){
    Account* accounts = malloc(sizeof(Account)*3);
    list = create();
    accounts[0].accountNumber = 001;accounts[0].balance = 1000;
    accounts[1].accountNumber = 002;accounts[1].balance = 2000;
    accounts[2].accountNumber = 003;accounts[2].balance = 3000;
    insertElement(list, 0,&accounts[0]);
    ASSERT(areAccountsEqual(accounts[0], *(Account*)list->head->element));
    ASSERT(1 == list->length);
    insertElement(list, 1, &accounts[1]);
    ASSERT(areAccountsEqual(accounts[1], *(Account*)list->head->next->element));
    ASSERT(2 == list->length);
    insertElement(list, 1, &accounts[2]);
    ASSERT(areAccountsEqual(accounts[1], *(Account*)list->head->next->element));
    ASSERT(3 == list->length);
}

void test_to_delete_an_element_from_LL_of_single_element(){
    int* value = malloc(sizeof(int));
    *value = 5;
    list = create();
    insertElement(list, 0, value);
    ASSERT(nodeDeletion(list, 0));
    ASSERT(0 == list->length);
    ASSERT(NULL == list->head);
}


void test_delete_an_element_from_LL_of_multiple_elements(){
    int* value = malloc(sizeof(int)*3);
    list = create();
    value[0] = 10;value[1] = 11;value[2] = 12;
    insertElement(list, 0,&value[0]);
    insertElement(list, 1,&value[1]);
    insertElement(list, 2,&value[2]);
    ASSERT(3 == list->length);
    ASSERT(10 == *(int*)list->head->element);
    ASSERT(nodeDeletion(list, 0));
    ASSERT(2 == list->length);
    ASSERT(11 == *(int*)list->head->element);
}


void test_to_delete_last_LL_element(){
    int* value = malloc(sizeof(int)*3);
    list = create();
    value[0] = 10;value[1] = 11;value[2] = 12;
    insertElement(list, 0,&value[0]);
    insertElement(list, 1,&value[1]);
    insertElement(list, 2,&value[2]);
    ASSERT(nodeDeletion(list, 2));
    ASSERT(2 == list->length);
    ASSERT(NULL == list->head->next);
}

void test_to_delete_middle_LL_element(){
    int* value = malloc(sizeof(int)*3);
    list = create();
    value[0] = 10;value[1] = 11;value[2] = 12;
    insertElement(list, 0,&value[0]);
    insertElement(list, 1,&value[1]);
    insertElement(list, 2,&value[2]);
    ASSERT(nodeDeletion(list, 1));
    ASSERT(2 == list->length);
    ASSERT(12 == *(int*)list->head->element);
}