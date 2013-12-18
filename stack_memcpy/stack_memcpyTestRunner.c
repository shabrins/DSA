#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_to_create_new_stack_int");
	setup();
		test_to_create_new_stack_int();
	tearDown();
	testEnded();
	testStarted("test_to_push_an_int_element_into_the_stack");
	setup();
		test_to_push_an_int_element_into_the_stack();
	tearDown();
	testEnded();
	testStarted("test_to_push_an_float_element_into_the_stack");
	setup();
		test_to_push_an_float_element_into_the_stack();
	tearDown();
	testEnded();
	testStarted("test_to_push_an_double_element_into_the_stack");
	setup();
		test_to_push_an_double_element_into_the_stack();
	tearDown();
	testEnded();
	testStarted("test_to_push_an_char_element_into_the_stack");
	setup();
		test_to_push_an_char_element_into_the_stack();
	tearDown();
	testEnded();
	testStarted("test_to_push_an_string_element_into_the_stack");
	setup();
		test_to_push_an_string_element_into_the_stack();
	tearDown();
	testEnded();
	testStarted("test_to_push_multiple_int_elements_into_the_stack");
	setup();
		test_to_push_multiple_int_elements_into_the_stack();
	tearDown();
	testEnded();
	testStarted("test_to_push_multiple_string_elements_into_the_stack");
	setup();
		test_to_push_multiple_string_elements_into_the_stack();
	tearDown();
	testEnded();
	testStarted("test_to_pop_an_int_element_from_the_stack");
	setup();
		test_to_pop_an_int_element_from_the_stack();
	tearDown();
	testEnded();
	testStarted("test_to_pop_an_float_element_from_the_stack");
	setup();
		test_to_pop_an_float_element_from_the_stack();
	tearDown();
	testEnded();
	testStarted("test_to_pop_an_double_element_from_the_stack");
	setup();
		test_to_pop_an_double_element_from_the_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_char_element_from_the_stack");
	setup();
		test_pop_char_element_from_the_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_string_element_from_the_stack");
	setup();
		test_pop_string_element_from_the_stack();
	tearDown();
	testEnded();
	testStarted("test_to_pop_int_element_from_the_empty_stack");
	setup();
		test_to_pop_int_element_from_the_empty_stack();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
