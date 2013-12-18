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

	testStarted("test_create_SLinkedList_with_head_pointing_to_NULL");
	setup();
		test_create_SLinkedList_with_head_pointing_to_NULL();
	tearDown();
	testEnded();
	testStarted("test_to_insert_element_in_front_int");
	setup();
		test_to_insert_element_in_front_int();
	tearDown();
	testEnded();
	testStarted("test_to_insert_one_elements_in_the_end_of_LL_int");
	setup();
		test_to_insert_one_elements_in_the_end_of_LL_int();
	tearDown();
	testEnded();
	testStarted("test_to_insert_multiple_elements_in_the_end_of_LL_int");
	setup();
		test_to_insert_multiple_elements_in_the_end_of_LL_int();
	tearDown();
	testEnded();
	testStarted("test_to_insert_multiple_elements_at_head");
	setup();
		test_to_insert_multiple_elements_at_head();
	tearDown();
	testEnded();
	testStarted("test_to_insert_multiple_double_elements_at_head");
	setup();
		test_to_insert_multiple_double_elements_at_head();
	tearDown();
	testEnded();
	testStarted("test_to_insert_multiple_char_elements_at_head");
	setup();
		test_to_insert_multiple_char_elements_at_head();
	tearDown();
	testEnded();
	testStarted("test_to_add_element_in_middle_of_LL_int");
	setup();
		test_to_add_element_in_middle_of_LL_int();
	tearDown();
	testEnded();
	testStarted("test_to_insert_string_elements_in_LL");
	setup();
		test_to_insert_string_elements_in_LL();
	tearDown();
	testEnded();
	testStarted("test_to_insert_struct_elements_to_LL");
	setup();
		test_to_insert_struct_elements_to_LL();
	tearDown();
	testEnded();
	testStarted("test_to_delete_an_element_from_LL_of_single_element");
	setup();
		test_to_delete_an_element_from_LL_of_single_element();
	tearDown();
	testEnded();
	testStarted("test_delete_an_element_from_LL_of_multiple_elements");
	setup();
		test_delete_an_element_from_LL_of_multiple_elements();
	tearDown();
	testEnded();
	testStarted("test_to_delete_last_LL_element");
	setup();
		test_to_delete_last_LL_element();
	tearDown();
	testEnded();
	testStarted("test_to_delete_middle_LL_element");
	setup();
		test_to_delete_middle_LL_element();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}
