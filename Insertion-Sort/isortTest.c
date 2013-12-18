#include "testUtils.h"
#include "isort.h"
#include <stdio.h>
#include <memory.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


int areEqual(Account* expected,Account* actual){
        int result = expected->accountNumber == actual->accountNumber && expected->balance == actual->balance;
    return result;
};


int intCompare ( void* a, void* b){
    return (*(int*)a - *(int*)b);
};

int doubleCompare( void* a, void* b){
    return (*(double*)a - *(double*)b);
};

int floatCompare( void* a, void* b){
    return (*(float*)a - *(float*)b);
};

int charCompare( void* a, void* b){
    return (*(char*)a - *(char*)b);
};

int stringCompare (const void* a,const void* b){
    return strcmp(a,b);
};

int compareAccountsByAccountNumber(void* first, void* second) {
	Account* firstAccount = (Account*)first;
	Account* secondAccount = (Account*)second;
	return firstAccount->accountNumber - secondAccount->accountNumber;
};

int compareAccountsByName(void* first, void* second) {
	Account* firstAccount = (Account*)first;
	Account* secondAccount = (Account*)second;
	return strcmp(firstAccount->name,secondAccount->name);
};

int compareAccountsByBalance(void* first, void* second) {
	Account* firstAccount = (Account*)first;
	Account* secondAccount = (Account*)second;
	return firstAccount->balance - secondAccount->balance;
};

void test_to_sort_bank_accounts_by_account_number(){
        Account exptd[] = { {01, 1000},{02, 2000},{03, 3000},{04,4000}};
        Account bankAcc[] = {{04,4000},{03, 3000}, {01, 1000},{02, 2000}};
        isort(bankAcc, 4, sizeof(Account), compareAccountsByAccountNumber);
        ASSERT(1 == areEqual(exptd,bankAcc));

};

void test_to_sort_bank_accounts_by_account_balance(){
        Account exptd[] = { {01, 1000},{02, 2000},{03, 3000},{04,4000}};
        Account bankAcc[] = {{04,4000},{03, 3000}, {01, 1000},{02, 2000}};
        isort(bankAcc, 4, sizeof(Account), compareAccountsByBalance);
        ASSERT(1 == areEqual(exptd,bankAcc));

};

void test_to_sort_bank_accounts_by_account_name(){
        Account exptd[] = { {01, 1000.00,"aaaaaa"},{02, 2000.00,"bbbbb"},{03, 3000.00,"ccccc"},{04,4000.00,"ddddd"}};
        Account bankAcc[] = {{04,4000.00,"ddddd"},{03, 3000.00,"ccccc"}, {01, 1000.00,"aaaaaa"},{02, 2000.00,"bbbbb"}};
        isort(bankAcc, 4, sizeof(Account), compareAccountsByName);
        ASSERT(1 == areEqual(exptd,bankAcc));

};

void test_to_sort_array_of_int_elements(){
        int exptd[] = {4,5,6,7,8};
        int actual[] ={8,4,5,7,6};
        isort(actual, 5, sizeof(int), intCompare);
        ASSERT(0 == memcmp(exptd, actual, sizeof(exptd)));
};



void test_to_sort_array_of_double_elements(){
        int expected[] = {1.00000,2.00000,3.00000,4.00000};
        int actual[] = {4.00000,3.00000,1.00000,2.00000};
        isort(actual, 4, sizeof(int), intCompare);
        ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
};


void test_to_sort_array_of_float_elements(){
        float expected[] = {1.00,2.00,3.00,4.00};
        float actual[] = {4.00,3.00,1.00,2.00};
        isort(actual, 4, sizeof(float),floatCompare);
        ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
};

void test_to_sort_array_of_string_elements(){
        String expected[] = {"1.00","2.00","3.00","4.00"};
        String actual[] = {"4.00","3.00","1.00","2.00"};
        isort(actual, 4, sizeof(String),stringCompare );
        ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
};
