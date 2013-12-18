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

	testStarted("test_to_create_queue_for_integers_1");
	setup();
		test_to_create_queue_for_integers_1();
	tearDown();
	testEnded();
	testStarted("test_to_create_queue_for_floats_2");
	setup();
		test_to_create_queue_for_floats_2();
	tearDown();
	testEnded();
	testStarted("test_to_create_Queue_for_double_3");
	setup();
		test_to_create_Queue_for_double_3();
	tearDown();
	testEnded();
	testStarted("test_to_create_queue_for_chars_4");
	setup();
		test_to_create_queue_for_chars_4();
	tearDown();
	testEnded();
	testStarted("test_to_create_Queue_for_String_5");
	setup();
		test_to_create_Queue_for_String_5();
	tearDown();
	testEnded();
	testStarted("test_to_enter_int_element_in_queue_6");
	setup();
		test_to_enter_int_element_in_queue_6();
	tearDown();
	testEnded();
	testStarted("test_to_enter_float_element_in_queue");
	setup();
		test_to_enter_float_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_to_enter_double_element_in_queue");
	setup();
		test_to_enter_double_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_to_enter_string_element_in_queue");
	setup();
		test_to_enter_string_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_to_enter_char_element_in_queue");
	setup();
		test_to_enter_char_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_to_enter_int_element_into_Queue_when_it_is_full");
	setup();
		test_to_enter_int_element_into_Queue_when_it_is_full();
	tearDown();
	testEnded();
	testStarted("test_to_enter_float_element_into_Queue_when_it_is_full");
	setup();
		test_to_enter_float_element_into_Queue_when_it_is_full();
	tearDown();
	testEnded();
	testStarted("test_to_delete_int_element_from_Queue");
	setup();
		test_to_delete_int_element_from_Queue();
	tearDown();
	testEnded();
	testStarted("test_to_delete_float_element_from_Queue");
	setup();
		test_to_delete_float_element_from_Queue();
	tearDown();
	testEnded();
	testStarted("test_to_delete_float_element_from_empty_Queue");
	setup();
		test_to_delete_float_element_from_empty_Queue();
	tearDown();
	testEnded();
	testStarted("test_to_enter_new_element_at_the_0_location_for_int_element");
	setup();
		test_to_enter_new_element_at_the_0_location_for_int_element();
	tearDown();
	testEnded();
	testStarted("test_to_enter_new_element_at_the_0_location_for_float_element");
	setup();
		test_to_enter_new_element_at_the_0_location_for_float_element();
	tearDown();
	testEnded();
	testStarted("test_to_enter_new_element_at_the_0_location_for_double_element");
	setup();
		test_to_enter_new_element_at_the_0_location_for_double_element();
	tearDown();
	testEnded();
	testStarted("test_to_enter_new_element_at_the_1_location_for_int_element");
	setup();
		test_to_enter_new_element_at_the_1_location_for_int_element();
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
