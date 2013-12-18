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

	testStarted("test_to_enqueueElements_in_the_PQ_int");
	setup();
		test_to_enqueueElements_in_the_PQ_int();
	tearDown();
	testEnded();
	testStarted("test_to_enqueueElements_in_the_PQ_float");
	setup();
		test_to_enqueueElements_in_the_PQ_float();
	tearDown();
	testEnded();
	testStarted("test_to_enqueueElements_in_the_PQ_double");
	setup();
		test_to_enqueueElements_in_the_PQ_double();
	tearDown();
	testEnded();
	testStarted("test_to_enqueueElements_in_the_PQ_char");
	setup();
		test_to_enqueueElements_in_the_PQ_char();
	tearDown();
	testEnded();
	testStarted("test_to_enqueueElements_in_the_PQ_string");
	setup();
		test_to_enqueueElements_in_the_PQ_string();
	tearDown();
	testEnded();
	testStarted("test_to_enqueueElements_in_the_PQ_int_with_high_priority");
	setup();
		test_to_enqueueElements_in_the_PQ_int_with_high_priority();
	tearDown();
	testEnded();
	testStarted("test_to_enqueueElements_in_the_PQ_with_high_priority_float");
	setup();
		test_to_enqueueElements_in_the_PQ_with_high_priority_float();
	tearDown();
	testEnded();
	testStarted("test_to_enqueueElements_in_the_PQ_with_high_priority_char");
	setup();
		test_to_enqueueElements_in_the_PQ_with_high_priority_char();
	tearDown();
	testEnded();
	testStarted("test_to_enqueueElements_in_middle_in_the_PQ_int");
	setup();
		test_to_enqueueElements_in_middle_in_the_PQ_int();
	tearDown();
	testEnded();
	testStarted("test_dequeueElements_element_from_PQ_per_priority");
	setup();
		test_dequeueElements_element_from_PQ_per_priority();
	tearDown();
	testEnded();
	testStarted("test_to_remove_from_empty_PQ");
	setup();
		test_to_remove_from_empty_PQ();
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
