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

	testStarted("test_to_sort_bank_accounts_by_account_number");
	setup();
		test_to_sort_bank_accounts_by_account_number();
	tearDown();
	testEnded();
	testStarted("test_to_sort_bank_accounts_by_account_balance");
	setup();
		test_to_sort_bank_accounts_by_account_balance();
	tearDown();
	testEnded();
	testStarted("test_to_sort_bank_accounts_by_account_name");
	setup();
		test_to_sort_bank_accounts_by_account_name();
	tearDown();
	testEnded();
	testStarted("test_to_sort_array_of_int_elements");
	setup();
		test_to_sort_array_of_int_elements();
	tearDown();
	testEnded();
	testStarted("test_to_sort_array_of_double_elements");
	setup();
		test_to_sort_array_of_double_elements();
	tearDown();
	testEnded();
	testStarted("test_to_sort_array_of_float_elements");
	setup();
		test_to_sort_array_of_float_elements();
	tearDown();
	testEnded();
	testStarted("test_to_sort_array_of_string_elements");
	setup();
		test_to_sort_array_of_string_elements();
	tearDown();
	testEnded();
	testStarted("test_to_sort_array_of_char_elements");
	setup();
		test_to_sort_array_of_char_elements();
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
