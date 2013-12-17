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

	testStarted("test_to_create_new_process_scheduler");
	setup();
		test_to_create_new_process_scheduler();
	tearDown();
	testEnded();
	testStarted("test_to_add_process_in_the_scheduler");
	setup();
		test_to_add_process_in_the_scheduler();
	tearDown();
	testEnded();
	testStarted("test_to_add_process_with_high_priority_in_the_scheduler");
	setup();
		test_to_add_process_with_high_priority_in_the_scheduler();
	tearDown();
	testEnded();
	testStarted("test_to_add_process_with_high_priority_in_between_the_scheduler");
	setup();
		test_to_add_process_with_high_priority_in_between_the_scheduler();
	tearDown();
	testEnded();
	testStarted("test_to_add_process_with_low_priority_in_the_scheduler");
	setup();
		test_to_add_process_with_low_priority_in_the_scheduler();
	tearDown();
	testEnded();
	testStarted("test_to_remove_the_process_from_scheduler");
	setup();
		test_to_remove_the_process_from_scheduler();
	tearDown();
	testEnded();
	testStarted("test_to_remove_the_process_in_the_middle_from_scheduler");
	setup();
		test_to_remove_the_process_in_the_middle_from_scheduler();
	tearDown();
	testEnded();
	testStarted("test_to_remove_the_last_process_from_scheduler");
	setup();
		test_to_remove_the_last_process_from_scheduler();
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
