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

void test_to_insert_an_element_in_the_DLL(){
        int element = 7;
        ASSERT(insertElement(front, 0, &element));
        ASSERT(element=*(int*)removeElement(front, 0));
}

void test_to_insert_an_element_in_the_DLL_float(){
        float element = 7.0;
        ASSERT(insertElement(front, 0, &element));
        ASSERT(element=*(float*)removeElement(front, 0));
}


void test_to_insert_an_element_in_the_DLL_double(){
        double element = 7.00000;
        ASSERT(insertElement(front, 0, &element));
        ASSERT(element=*(double*)removeElement(front, 0));
}

void test_to_insert_an_element_in_the_DLL_char(){
        char element = 'a';
        ASSERT(insertElement(front, 0, &element));
        ASSERT(element=*(char*)removeElement(front, 0));
}

void test_to_insert_an_element_in_between_in_the_DLL(){
        int element=1,element2=2;
        ASSERT(insertElement(front, 0, &element));
        ASSERT(insertElement(front, 1, &element2));
        ASSERT(insertElement(front, 2, &element2));
        ASSERT(insertElement(front, 1, &element));
        ASSERT(element=*(int*)removeElement(front, 1));
};

void test_to_insert_an_element_in_end_in_the_DLL(){
        int element=1,element2=2;
        ASSERT(insertElement(front, 0, &element));
        ASSERT(insertElement(front, 1, &element2));
        ASSERT(element2=*(int*)removeElement(front, 1));
}


void test_to_remove_an_element_from_the_DLL(){
        int element=2,element2=3;
        ASSERT(insertElement(front, 0, &element));
        ASSERT(insertElement(front, 1, &element2));
        ASSERT(element = *(int*)removeElement(front, 0));
}

void test_to_remove_an_element_from_the_DLL_float(){
        float element=2.0,element2=3.0;
        ASSERT(insertElement(front, 0, &element));
        ASSERT(insertElement(front, 1, &element2));
        ASSERT(element = *(float*)removeElement(front, 0));
}

void test_to_remove_an_element_from_the_DLL_double(){
        double element=2.00000,element2=3.00000;
        ASSERT(insertElement(front, 0, &element));
        ASSERT(insertElement(front, 1, &element2));
        ASSERT(element = *(double*)removeElement(front, 0));
}

void test_to_remove_an_element_from_the_DLL_char(){
        char element='a',element2='b';
        ASSERT(insertElement(front, 0, &element));
        ASSERT(insertElement(front, 1, &element2));
        ASSERT(element = *(char*)removeElement(front, 0));
}

void test_to_insert_and_remove_an_element_from_the_DLL_Multiple_times(){
        int element=2,element2=3,element3=4;
        ASSERT(insertElement(front, 0, &element));
        ASSERT(insertElement(front, 1, &element2));
        ASSERT(element = *(int*)removeElement(front, 0));
        ASSERT(insertElement(front, 1, &element3));
        ASSERT(element = *(int*)removeElement(front, 1));
        ASSERT(insertElement(front, 1, &element3));

};

void test_to_remove_an_element_from_between_in_the_DLL(){
        int element=2,element2=3;
        ASSERT(insertElement(front, 0, &element));
        ASSERT(insertElement(front, 1, &element2));
        ASSERT(insertElement(front, 2, &element2));
        ASSERT(element2=*(int*)removeElement(front, 1));
}


void test_to_remove_an_element_from_end_in_the_DLL(){
        int element=2,element2=3;
        ASSERT(insertElement(front, 0, &element));
        ASSERT(insertElement(front, 1, &element2));
        ASSERT(insertElement(front, 2, &element2));
        ASSERT(element2=*(int*)removeElement(front, 2));
}

void test_to_remove_an_element_which_is_not_present_in_the_DLL(){
        int element=2,element2=3;
        insertElement(front, 0, &element);
        insertElement(front, 1, &element2);
        insertElement(front, 2, &element2);
        ASSERT(NULL==removeElement(front, 3));
}

