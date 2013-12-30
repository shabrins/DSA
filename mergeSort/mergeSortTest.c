#include "testUtils.h"
#include "mergeSort.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct {
	int  AccNo;
	char* name;
} Account;

int compareInt(void* prev, void* next){
	return *(int*)prev < *(int*)next;
}

int compareFloat (void* prev, void* next){
	return *(float*)prev <
	 *(float*)next;
}

int compareChar (void* prev, void* next){
	return *(char*)prev < *(char*)next;
}

int compareAccount (void* prev, void* next){
	Account* first = (Account*)prev;
	Account* second = (Account*)next;
	return first->AccNo < second->AccNo;
}


void test_to_merge_sort_elementsay_of_type_int(){
	int count;
	int actual[] = {0,0};
	int left[]= {2};
	int right[]={1};
	merge(actual, left, right, 1, 1, sizeof(int), compareInt);
	for (count = 0; count < 2; ++count)
	{
		ASSERT(count+1 == actual[count]);
	}
}


void test_to_merge_sort_type_int_elements(){
	int count;
	int elements[] = {4,3,2,1};
	mergeSort(&elements,4,sizeof(int),compareInt);
	for(count=0 ; count < 4 ; count++){
		ASSERT(elements[count]==count+1);
	}
}

void test_to_merge_sort_type_int_elements_for_odd_no_of_elements(){
	int count;
	int elements[] = {5,4,3,2,1};
	mergeSort(&elements,5,sizeof(int),compareInt);
	for(count=0 ; count < 5 ; count++){
		ASSERT(elements[count]==count+1);
	}
}

void test_to_merge_sort_type_float_elements(){
	int count;
	float elements[] = {4.1f,3.1f,2.1f,1.1f};
	float expected[] = {1.1f,2.1f,3.1f,4.1f};
	mergeSort(&elements,4,sizeof(float),compareFloat);
	for(count=0 ; count < 4 ; count++){
		ASSERT(elements[count]==expected[count]);
	}
}

void test_to_merge_sort_type_char_elements(){
	char elements[] = {'e','d','c','b','a'};
	mergeSort(elements, 5, sizeof(char), compareChar );
	ASSERT(elements[0] == 'a');
	ASSERT(elements[1] == 'b');
	ASSERT(elements[2] == 'c');
	ASSERT(elements[3] == 'd');
	ASSERT(elements[4] == 'e');
}

void test_to_merge_sort_type_Struct_elements(){
	Account elements[] = {{3,"Prayas"},{1,"Manish"},{2,"Shabrin"}};
	mergeSort(elements, 3, sizeof(Account), compareAccount );
	ASSERT(1 == elements[0].AccNo);
	ASSERT(2 == elements[1].AccNo);
	ASSERT(3 == elements[2].AccNo);
}

