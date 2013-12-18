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

	testStarted("test_to_create_DLL");
	setup();
		test_to_create_DLL();
	tearDown();
	testEnded();
	testStarted("test_to_insert_an_element_in_the_DLL");
	setup();
		test_to_insert_an_element_in_the_DLL();
	tearDown();
	testEnded();
	testStarted("test_to_insert_an_element_in_the_DLL_float");
	setup();
		test_to_insert_an_element_in_the_DLL_float();
	tearDown();
	testEnded();
	testStarted("test_to_insert_an_element_in_the_DLL_double");
	setup();
		test_to_insert_an_element_in_the_DLL_double();
	tearDown();
	testEnded();
	testStarted("test_to_insert_an_element_in_the_DLL_char");
	setup();
		test_to_insert_an_element_in_the_DLL_char();
	tearDown();
	testEnded();
	testStarted("test_to_insert_an_element_in_between_in_the_DLL");
	setup();
		test_to_insert_an_element_in_between_in_the_DLL();
	tearDown();
	testEnded();
	testStarted("test_to_insert_an_element_in_end_in_the_DLL");
	setup();
		test_to_insert_an_element_in_end_in_the_DLL();
	tearDown();
	testEnded();
	testStarted("test_to_remove_an_element_from_the_DLL");
	setup();
		test_to_remove_an_element_from_the_DLL();
	tearDown();
	testEnded();
	testStarted("test_to_remove_an_element_from_the_DLL_float");
	setup();
		test_to_remove_an_element_from_the_DLL_float();
	tearDown();
	testEnded();
	testStarted("test_to_remove_an_element_from_the_DLL_double");
	setup();
		test_to_remove_an_element_from_the_DLL_double();
	tearDown();
	testEnded();
	testStarted("test_to_remove_an_element_from_the_DLL_char");
	setup();
		test_to_remove_an_element_from_the_DLL_char();
	tearDown();
	testEnded();
	testStarted("test_to_insert_and_remove_an_element_from_the_DLL_Multiple_times");
	setup();
		test_to_insert_and_remove_an_element_from_the_DLL_Multiple_times();
	tearDown();
	testEnded();
	testStarted("test_to_remove_an_element_from_between_in_the_DLL");
	setup();
		test_to_remove_an_element_from_between_in_the_DLL();
	tearDown();
	testEnded();
	testStarted("test_to_remove_an_element_from_end_in_the_DLL");
	setup();
		test_to_remove_an_element_from_end_in_the_DLL();
	tearDown();
	testEnded();
	testStarted("test_to_remove_an_element_which_is_not_present_in_the_DLL");
	setup();
		test_to_remove_an_element_which_is_not_present_in_the_DLL();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}
