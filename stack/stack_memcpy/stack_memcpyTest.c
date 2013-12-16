#include "testUtils.h"
#include "stack_memcpy.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
Stack* stack;

void teardown(){
        free(stack);
}
void test_to_create_new_stack_int(){
        stack = create(sizeof(int));
        ASSERT(stack->typeSize == sizeof(int));
        ASSERT(stack->peek == NULL);
        ASSERT(stack->presentElements == 0);
};

void test_to_push_an_int_element_into_the_stack(){
        int element =01;
        stack = create(sizeof(int));
        push(stack,&element);
        ASSERT(*(int*)((*stack->peek).element) == 01);
        ASSERT(stack->presentElements == 1);
        ASSERT((*stack->peek).previous == NULL);
};
void test_to_push_an_float_element_into_the_stack(){
        float element =10.0;
        stack = create(sizeof(float));
        push(stack,&element);
        ASSERT(*(float*)((*stack->peek).element) == 10.0);
        ASSERT(stack->presentElements == 1);
        ASSERT((*stack->peek).previous == NULL);
};
void test_to_push_an_double_element_into_the_stack(){
        double element =10.00000;
        stack = create(sizeof(double));
        push(stack,&element);
        ASSERT(*(double*)((*stack->peek).element) == 10.00000);
        ASSERT(stack->presentElements == 1);
        ASSERT((*stack->peek).previous == NULL);
};
void test_to_push_an_char_element_into_the_stack(){
        char element ='S';
        stack = create(sizeof(char));
        push(stack,&element);
        ASSERT(*(char*)((*stack->peek).element) == 'S');
        ASSERT(stack->presentElements == 1);
        ASSERT((*stack->peek).previous == NULL);
};
void test_to_push_an_string_element_into_the_stack(){
        String element ="apple";
        stack = create(sizeof(String));
        push(stack,&element);
        ASSERT(!strcmp(*(String*)((*stack->peek).element),"apple"));
        ASSERT(stack->presentElements == 1);
        ASSERT((*stack->peek).previous == NULL);
};
void test_to_push_multiple_int_elements_into_the_stack(){
        int elements[] ={11,12,13};
        stack = create(sizeof(int));
        push(stack,&elements[0]);
        push(stack,&elements[1]);
        push(stack,&elements[2]);
        ASSERT(*(int*)((*stack->peek).element) == 13);
        ASSERT(stack->presentElements == 3);
};

void test_to_push_multiple_string_elements_into_the_stack(){
        String elements[] ={"apple","orange"};
        stack = create(sizeof(String));
       push(stack,&elements[0]);
        push(stack,&elements[1]);
        ASSERT(!strcmp(*(String*)((*stack->peek).element),"orange"));
        ASSERT(stack->presentElements == 2);
};

void test_to_pop_an_int_element_from_the_stack(){
        List* list;
        int element = 01;
        stack = create(sizeof(int));
        push(stack,&element);
        list = pop(stack);
        ASSERT(*(int*)list->element == element);
};
void test_to_pop_an_float_element_from_the_stack(){
        List* list;
        float element = 10.0;
        stack = create(sizeof(float));
        push(stack,&element);
        list = pop(stack);
        ASSERT(*(float*)list->element == element);
};

void test_to_pop_an_double_element_from_the_stack(){
        List* list;
        double element = 10.00000;
        stack = create(sizeof(double));
        push(stack,&element);
        list = pop(stack);
        ASSERT(*(double*)list->element == element);
};
void test_pop_char_element_from_the_stack(){
        List* list;
        char element = 'a';
        stack = create(sizeof(char));
        push(stack,&element);
        list = pop(stack);
        ASSERT(*(char*)list->element == element);
};
void test_pop_string_element_from_the_stack(){
        List* list;
        String element = "shital";
        stack = create(sizeof(String));
        push(stack,&element);
        list = pop(stack);
        ASSERT(!strcmp(*(String*)list->element,element));
};
void test_to_pop_int_element_from_the_empty_stack(){
        List* list;
        int element[] ={10,20,30};
        stack = create(sizeof(int));
        push(stack,&element[0]);
        push(stack,&element[1]);
        push(stack,&element[2]);
        ASSERT(*(int*)((*stack->peek).element) == 30);
        ASSERT(stack->presentElements == 3);
        list = pop(stack);
        list = pop(stack);
        list = pop(stack);
        ASSERT(*(int*)list->element == element[0]);
        list = pop(stack);
        ASSERT(NULL == list);
};
