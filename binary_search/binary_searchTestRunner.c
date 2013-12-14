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

	testStarted("test_to_create_list_to_search_integer");
	setup();
		test_to_create_list_to_search_integer();
	tearDown();
	testEnded();
	testStarted("test_to_create_list_to_search_float");
	setup();
		test_to_create_list_to_search_float();
	tearDown();
	testEnded();
	testStarted("test_creating_new_list_for_double");
	setup();
		test_creating_new_list_for_double();
	tearDown();
	testEnded();
	testStarted("test_creating_new_list_for_char");
	setup();
		test_creating_new_list_for_char();
	tearDown();
	testEnded();
	testStarted("test_to_search_element_from_the_list_of_int");
	setup();
		test_to_search_element_from_the_list_of_int();
	tearDown();
	testEnded();
	testStarted("test_to_search_element_from_the_list_of_integers_which_is_not_available");
	setup();
		test_to_search_element_from_the_list_of_integers_which_is_not_available();
	tearDown();
	testEnded();
	testStarted("test_to_search_first_element_from_the_list_of_int");
	setup();
		test_to_search_first_element_from_the_list_of_int();
	tearDown();
	testEnded();
	testStarted("test_to_search_last_element_from_the_list_of_int");
	setup();
		test_to_search_last_element_from_the_list_of_int();
	tearDown();
	testEnded();
	testStarted("test_search_element_from_the_list_of_floats");
	setup();
		test_search_element_from_the_list_of_floats();
	tearDown();
	testEnded();
	testStarted("test_search_element_from_the_list_of_floats_which_is_not_available");
	setup();
		test_search_element_from_the_list_of_floats_which_is_not_available();
	tearDown();
	testEnded();
	testStarted("test_search_element_from_the_list_of_Strings");
	setup();
		test_search_element_from_the_list_of_Strings();
	tearDown();
	testEnded();
	testStarted("test_search_element_from_the_list_of_Strings_which_is_not_available");
	setup();
		test_search_element_from_the_list_of_Strings_which_is_not_available();
	tearDown();
	testEnded();
	testStarted("test_to_search_element_from_the_list_of_char");
	setup();
		test_to_search_element_from_the_list_of_char();
	tearDown();
	testEnded();
	testStarted("test_to_search_element_from_the_list_of_characters_whichis_not_available");
	setup();
		test_to_search_element_from_the_list_of_characters_whichis_not_available();
	tearDown();
	testEnded();
	testStarted("test_to_search_element_from_the_list_for_characters_if_elements_are_repeated");
	setup();
		test_to_search_element_from_the_list_for_characters_if_elements_are_repeated();
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
