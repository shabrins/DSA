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

	testStarted("test_to_creat_a_stack");
	setup();
		test_to_creat_a_stack();
	tearDown();
	testEnded();
	testStarted("test_to_creat_a_stack_float");
	setup();
		test_to_creat_a_stack_float();
	tearDown();
	testEnded();
	testStarted("test_to_creat_a_stack_char");
	setup();
		test_to_creat_a_stack_char();
	tearDown();
	testEnded();
	testStarted("test_to_creat_a_stack_string");
	setup();
		test_to_creat_a_stack_string();
	tearDown();
	testEnded();
	testStarted("test_to_creat_a_stack_double");
	setup();
		test_to_creat_a_stack_double();
	tearDown();
	testEnded();
	testStarted("test_to_push_element_in_the_stack");
	setup();
		test_to_push_element_in_the_stack();
	tearDown();
	testEnded();
	testStarted("test_to_push_element_in_the_stack_float");
	setup();
		test_to_push_element_in_the_stack_float();
	tearDown();
	testEnded();
	testStarted("test_to_push_element_in_the_stack_char");
	setup();
		test_to_push_element_in_the_stack_char();
	tearDown();
	testEnded();
	testStarted("test_to_push_element_in_the_stack_string");
	setup();
		test_to_push_element_in_the_stack_string();
	tearDown();
	testEnded();
	testStarted("test_to_push_element_in_the_stack_double");
	setup();
		test_to_push_element_in_the_stack_double();
	tearDown();
	testEnded();
	testStarted("test_to_pop_elements_from_stack");
	setup();
		test_to_pop_elements_from_stack();
	tearDown();
	testEnded();
	testStarted("test_to_pop_elements_from_stack_float");
	setup();
		test_to_pop_elements_from_stack_float();
	tearDown();
	testEnded();
	testStarted("test_to_pop_elements_from_stack_double");
	setup();
		test_to_pop_elements_from_stack_double();
	tearDown();
	testEnded();
	testStarted("test_to_pop_elements_from_stack_String");
	setup();
		test_to_pop_elements_from_stack_String();
	tearDown();
	testEnded();
	testStarted("test_to_creat_a_stack_and_dispose");
	setup();
		test_to_creat_a_stack_and_dispose();
	tearDown();
	testEnded();
	testStarted("test_to_check_stack_is_empty");
	setup();
		test_to_check_stack_is_empty();
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
