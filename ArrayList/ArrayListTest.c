#include <stdlib.h>
#include "testUtils.h"
#include "ArrayList.h"

const int SUCCESS = 1;
const int FAILURE = 0;

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct {
        int id;
        char* name;
        int age;
} Intern;

Intern prateek = {15386, "Prateek", 18};
Intern ji = {13432, "Immortal", 17};        
ArrayList interns;
ArrayList *internsPtr;

void setup() {
        int noOfElements = 2;        
        interns = create(noOfElements);
        internsPtr = &interns;
}

void tearDown() {
        dispose(internsPtr);        
}

void test_insert_element(){
        int result = insert(internsPtr, 0, &prateek);
        Intern *actual = (Intern*)get(interns, 0);
        ASSERT(result == SUCCESS);
        ASSERT(prateek.id == actual->id);
}

void test_insert_multiple_elements() {
        insert(internsPtr, 0, &prateek);
        insert(internsPtr, 1, &ji);
        ASSERT(&prateek == get(interns, 0));
        ASSERT(&ji == get(interns, 1));
}

void test_interns_grows_beyond_capacity() {
        int noOfElements = 1;
        ArrayList list = create(noOfElements);
        ArrayList *listPtr = &list;
        insert(listPtr, 0, &prateek);
        insert(listPtr, 1, &ji);
        ASSERT(&prateek == get(list, 0));
        ASSERT(&ji == get(list, 1));

        dispose(listPtr);                
}

void test_should_not_insert_at_index_beyond_length() {
        int result = FAILURE;
        result = insert(internsPtr, 2, &prateek);
        ASSERT(result == FAILURE);
}

void test_should_not_insert_at_negative_index() {
        int result = FAILURE;
        result = insert(internsPtr, -1, &prateek);
        ASSERT(result == FAILURE);
}

void test_insert_at_middle_should_shift_the_elements() {
        Intern tanbirka = {43343, "Tanbir Ka"};
        insert(internsPtr, 0, &prateek);
        insert(internsPtr, 1, &ji);
        insert(internsPtr, 1, &tanbirka);        
        ASSERT(&prateek == get(interns, 0));
        ASSERT(&tanbirka == get(interns, 1));
        ASSERT(&ji == get(interns, 2));
}

void test_should_not_insert_when_list_is_null() {
        int result = insert(NULL, 1, &prateek);
        ASSERT(result == FAILURE);
}

void test_deletes_single_element_from_list(){
        int result;
        insert(internsPtr, 0, &prateek);
        ASSERT(1 == interns.length);
        result = remove(internsPtr, 0);
        ASSERT(NULL == get(interns, 0));
        ASSERT(0 == interns.length);
        ASSERT(result == SUCCESS);
}

void test_deletes_and_shifts_elements_left(){
        int result;
        insert(internsPtr, 0, &prateek);
        insert(internsPtr, 0, &ji);
        ASSERT(2 == interns.length);
        result = remove(internsPtr, 0);
        ASSERT(&prateek == get(interns, 0));
        ASSERT(NULL == get(interns, 1));
        ASSERT(result == SUCCESS);        
}

void test_iterator_tells_that_next_data_is_present(){
        Iterator it;
        insert(internsPtr, 0, &prateek);
        it = getIterator(internsPtr);
        ASSERT(1 == it.hasNext(&it));
}

void test_iterator_tells_that_next_data_is_not_present(){
        Iterator it;
        it = getIterator(internsPtr);
        ASSERT(0 == it.hasNext(&it));
}

void test_iterator_gives_the_data_of_next_index(){
        Iterator it;
        insert(internsPtr, 0, &prateek);
        insert(internsPtr, 0, &ji);
        it = getIterator(internsPtr);
        ASSERT(&ji == it.next(&it));
        ASSERT(&prateek == it.next(&it));
        ASSERT(NULL == it.next(&it));
}

