#include "testUtils.h"
#include "DLL.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

List* front;

void setup(){
        front = create();
}

void tearDown(){
        dispose(front);
}

void test_to_create_DLL(){
        ASSERT(0==front->length);
}

void test_to_insert_an_element_in_the_DDL(){
        int element = 7;
        insertElement(front, 0, &element);
        ASSERT(NULL == front->head->next);
        ASSERT(1==front->length);
}

void test_to_insert_an_element_in_between_in_the_DDL(){
        int element=1,element2=2;
        insertElement(front, 0, &element);
        insertElement(front, 1, &element2);
        insertElement(front, 2, &element2);
        insertElement(front, 1, &element);
        ASSERT(4==front->length);
}

void test_to_insert_an_element_in_end_in_the_DDL(){
        int element=1,element2=2;
        insertElement(front, 0, &element);
        insertElement(front, 1, &element2);
        ASSERT(1==*(int*)(front->head->element));
        ASSERT(2==*(int*)(front->head->next->element));
        ASSERT(NULL == front->head->next->next);
        ASSERT(front->head == front->head->next->previous);
        ASSERT(2==front->length);
}


void test_to_remove_an_element_from_the_DDL(){
        int element=2,element2=3;
        insertElement(front, 0, &element);
        insertElement(front, 1, &element2);
        insertElement(front, 2, &element2);
        ASSERT(3==front->length);
        ASSERT(2==*(int*)(front->head->element));
        removeElement(front, 0);
        ASSERT(3==*(int*)(front->head->next->element));
        ASSERT(2==front->length);
}

void test_to_delete_an_element_from_between_in_the_DDL(){
        int element=2,element2=3;
        insertElement(front, 0, &element);
        insertElement(front, 1, &element2);
        insertElement(front, 2, &element);
        ASSERT(3==front->length);
        ASSERT(3==*(int*)(front->head->next->element));
        removeElement(front, 1);
        ASSERT(2==*(int*)(front->head->next->element));
        ASSERT(2==front->length);
}

void test_to_remove_an_element_from_end_in_the_DDL(){
        int element=2,element2=3;
        insertElement(front, 0, &element);
        insertElement(front, 1, &element2);
        insertElement(front, 2, &element2);
        ASSERT(3==front->length);
        removeElement(front, 2        );
        ASSERT(2==front->length);
}


