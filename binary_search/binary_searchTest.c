#include "testUtils.h"
#include "binary_search.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


int compareInt (void* a, void* b){
    return (*(int*)a - *(int*)b);
}
int compareDouble (void* a, void* b){
    return (*(double*)a - *(double*)b);
}
int compareString(void *a, void *b){
         return (strcmp((char *)a,(char *)b));
}
int compareChar(void* a, void* b){
        return (*(char*)a - *(char*)b);
}

void test_to_create_list_to_search_integer(){
	 int index;
        Binary_search* b;
        int list_element[] = {0.0,0.0,0.0,0.0,0.0};
        b = createList(5,sizeof(int));
        index = memcmp(list_element,b->list,5);
        ASSERT(!index);
        ASSERT(b->typeSize == 4);
        ASSERT(b->left == 0);
        ASSERT(b->right == 5);
        ASSERT(b->middle == 0);
}


void test_to_create_list_to_search_float(){
        float index;
        Binary_search* b;
        float list_element[] = {0.0,0.0,0.0,0.0,0.0};
        b = createList(5,sizeof(float));
        index = memcmp(list_element,b->list,5);
        ASSERT(!index);
        ASSERT(b->typeSize == 4);
        ASSERT(b->left == 0);
        ASSERT(b->right == 5);
        ASSERT(b->middle == 0);
}
void test_creating_new_list_for_double(){
        double i;
        Binary_search* b;
        double testList[] = {0.0,0.0,0.0,0.0,0.0};
        b = createList(5,sizeof(double));
        i = memcmp(testList,b->list,5);
        ASSERT(!i);
        ASSERT(b->typeSize == 8);
        ASSERT(b->left == 0);
        ASSERT(b->right == 5);
        ASSERT(b->middle == 0);
}
void test_creating_new_list_for_char(){
        char i;
        Binary_search* b;
        char testList[] = {'\0','\0','\0','\0','\0'};
        b = createList(5,sizeof(char));
        i = memcmp(testList,b->list,5);
        ASSERT(!i);
        ASSERT(b->typeSize == 1);
        ASSERT(b->left == 0);
        ASSERT(b->right == 5);
        ASSERT(b->middle == 0);
}
void test_to_search_element_from_the_list_of_int(){
    int elements[5] = {4,6,7,8,2};
    int key = 8;
    int* result = binarySearch(elements,&key, 5, sizeof(int), compareInt);
    ASSERT(8 == *result);
    ASSERT(&elements[3] == result);
};
void test_to_search_element_from_the_list_of_integers_which_is_not_available(){
    int elements[5] = {4,6,7,8,2};
    int key = 9;
    int* result = binarySearch(elements,&key, 5, sizeof(int), compareInt);
    ASSERT((int*)result == NULL);
};
void test_to_search_first_element_from_the_list_of_int(){
    int elements[5] = {4,6};
    int key = 4;
    int* result = binarySearch(elements,&key, 2, sizeof(int), compareInt);
    ASSERT(4 == *result);
    ASSERT(&elements[0] == result);
};

void test_to_search_last_element_from_the_list_of_int(){
    int elements[] = {1,2,3,4,5};
    int key = 5;
    int* result = binarySearch(elements,&key, 5, sizeof(int), compareInt);
    ASSERT(5 == *result);
    ASSERT(&elements[4] == result);
};

void test_search_element_from_the_list_of_floats(){
    float elements[5] = {4.7f,6.4f,7.3f,8.5f,2.2f};
    float key = 6.4f;
    float* result = binarySearch(elements,&key, 5, sizeof(float), compareInt);
    ASSERT(6.4f == *result);
    ASSERT(&elements[1] == result);
};
void test_search_element_from_the_list_of_floats_which_is_not_available(){
    float elements[5] = {4.7f,6.4f,7.3f,8.5f,2.2f};
    float key = 4.6f;
    float* result = binarySearch(elements,&key, 5, sizeof(float), compareInt);
    ASSERT(NULL == (float*)result);
};

void test_search_element_from_the_list_of_Strings(){
    String elements[3] = {"shabrin","shital","manali"};
    String key = "shabrin";
    String* result = binarySearch(elements,&key, 3, sizeof(String), compareString);
    ASSERT(!(strcmp("shabrin",*result)));
    ASSERT(&elements[0] == result);
};
void test_search_element_from_the_list_of_Strings_which_is_not_available(){
    String elements[3] = {"shabrin","shital","manali"};
    String key = "shay";
    String* result = binarySearch(elements,&key, 3, sizeof(String), compareString);
    ASSERT(NULL == (String*)result);
};


void test_to_search_element_from_the_list_of_char(){
    char elements[3] = {'m','a','n'};
    char key = 'a';
    char* result = binarySearch(elements,&key, 3, sizeof(char), compareChar);
    ASSERT('a' == *result);
    ASSERT(&elements[1] == result);
};
void test_to_search_element_from_the_list_of_characters_whichis_not_available(){
    char elements[3] = {'m','a','n'};
    char key = 'k';
    char* result = binarySearch(elements,&key, 3, sizeof(char), compareChar);
    ASSERT(NULL == (char*)result);
};

void test_to_search_element_from_the_list_for_characters_if_elements_are_repeated(){
    char elements[3] = {'s','s','a'};
    char key = 's';
    char* result = binarySearch(elements,&key, 3, sizeof(char), compareChar);
    ASSERT('s' == *result);
    ASSERT(&elements[1] == result);
};