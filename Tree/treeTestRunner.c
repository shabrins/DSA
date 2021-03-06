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

	testStarted("test_to_insert_root");
	setup();
		test_to_insert_root();
	tearDown();
	testEnded();
	testStarted("test_to_insert_nodes_under_root_node");
	setup();
		test_to_insert_nodes_under_root_node();
	tearDown();
	testEnded();
	testStarted("test_to_insert_multiple_nodes_at_root_node");
	setup();
		test_to_insert_multiple_nodes_at_root_node();
	tearDown();
	testEnded();
	testStarted("test_to_insert_child_at_of_root");
	setup();
		test_to_insert_child_at_of_root();
	tearDown();
	testEnded();
	testStarted("test_to_insert_child_at_3rd_layer");
	setup();
		test_to_insert_child_at_3rd_layer();
	tearDown();
	testEnded();
	testStarted("test_to_check_child_of_a_leaf_node");
	setup();
		test_to_check_child_of_a_leaf_node();
	tearDown();
	testEnded();
	testStarted("test_to_delete_a_node_under_root_node");
	setup();
		test_to_delete_a_node_under_root_node();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
