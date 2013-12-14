#include "testUtils.h"
#include "stack.h"
#include <memory.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct {
     char item_name[256];
     int price;
} Records;

int areEqualStruct(Records a,Records b){
	if(a.price!=b.price) return 0;
	return 0 == strcmp(a.item_name,b.item_name);
}

int areEqual(Stack *src , Stack *exptd){
	int result = (src->length==exptd->length);
	if(!result) return result;
	return 0 == memcmp(src->elements, exptd->elements, exptd->length*exptd->typeSize);
}

void test_to_creat_a_stack(){
	int expectedValue[] = {0,0};
	Stack exptd = {expectedValue,-1,4,2};
	Stack *src = create(sizeof(int),2);
	ASSERT(areEqual(src,&exptd));
}

void test_to_creat_a_stack_float(){
	float expectedValue[] = {0,0};
	Stack exptd = {expectedValue,-1,4,2};
	Stack *src = create(sizeof(float),2);
	ASSERT(areEqual(src,&exptd));
}

void test_to_creat_a_stack_char(){
	Stack *src = create(sizeof(char),2);
	char expectedValue[] = {'\0','\0'};
	Stack exptd = { &expectedValue,-1,sizeof(char),2};
	ASSERT(areEqual(src,&exptd));
}

void test_to_creat_a_stack_string(){
	Stack *src = create(sizeof(String),2);
	String expectedValue[] = {"",""};
	Stack exptd = { &expectedValue,-1,sizeof(String),2};
	ASSERT(areEqual(src,&exptd));
}

void test_to_creat_a_stack_double(){
	Stack *src = create(sizeof(double),2);
	double expectedValue[] = {0.00000,0.00000};
	Stack exptd = { &expectedValue,-1,sizeof(double),2};
	ASSERT(areEqual(src,&exptd));
}

void test_to_push_element_in_the_stack(){
	Stack *src = create(sizeof(int),2);
	int element = 1;
	STACK restult;
    restult = push(src,&element);
	ASSERT(restult==TRUE);
};

void test_to_push_element_in_the_stack_float(){
	Stack *src = create(sizeof(float),2);
	float element = 1;
	STACK restult;
    restult = push(src,&element);
	ASSERT(restult==TRUE);
};

void test_to_push_element_in_the_stack_char(){
	Stack *src = create(sizeof(char),2);
	char element = '\0';
	STACK restult;
    restult = push(src,&element);
	ASSERT(restult==TRUE);
};

void test_to_push_element_in_the_stack_string(){
	Stack *src = create(sizeof(String),2);
	String element[] = {" "," "};
	STACK restult;
    restult = push(src,&element);
	ASSERT(restult==TRUE);
};

void test_to_push_element_in_the_stack_double(){
	Stack *src = create(sizeof(double),2);
	double element = 0.000000;
	STACK restult;
    restult = push(src,&element);
	ASSERT(restult==TRUE);
};

void test_to_pop_elements_from_stack(){
	Stack *src = create(sizeof(int),2);
	int* data = src->elements;
	int* restult;
	data[0]=1;
	data[0]=2;
    restult = pop(src);
	ASSERT(restult==NULL);
};

void test_to_pop_elements_from_stack_float(){
	Stack *src = create(sizeof(float),2);
	float* data = src->elements;
	int* restult;
	data[0]=1.1;
	data[0]=2.1;
    restult = pop(src);
	ASSERT(restult==NULL);
};

void test_to_pop_elements_from_stack_double(){
	Stack *src = create(sizeof(double),2);
	double* data = src->elements;
	int* restult;
	data[0]=1.100000;
	data[0]=2.100000;
    restult = pop(src);
	ASSERT(restult==NULL);
};

void test_to_pop_elements_from_stack_String(){
	Stack *src = create(sizeof(String),2);
	String* data = src->elements;
	int* restult;
	data="1.100000";
    restult = pop(src);
	ASSERT(restult==NULL);
};

void test_to_creat_a_stack_and_dispose(){
	int expectedValue[] = {0,0};
	Stack exptd = {expectedValue,-1,4,2};
	Stack *src = create(sizeof(int),2);
	ASSERT(areEqual(src,&exptd));
	dispose(src);
}

void test_to_check_stack_is_empty(){
	Stack *stack = create(sizeof(int),2);
	ASSERT(isEmpty(stack));
}
