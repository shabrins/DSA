#include "testUtils.h"
#include "hashmap.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areKeyEqueal(void* key1 , void* key2 ){
	return *(int*)key1 - *(int*)key2;
}
int hashFun(void* key){
	return *(int*)key;
}

typedef struct {
	int key;
	char* data[30];
} Intern;

Intern shab = {15442 , "shab"};
Intern xyz = {15443 , "xyz"};
Intern abc = {15444 , "abc"};

void test_add_an_element_to_hashmap(){
	HashMap hash = createHash(hashFun , areKeyEqueal);
	ASSERT(put(&hash,&shab.key,&shab.data));
	ASSERT(strcmp(get(&hash,&shab.key),"shab"));
}


void test_add_an_element_to_hashmap_1(){
	HashMap hash = createHash(hashFun , areKeyEqueal);
	ASSERT(put(&hash,&xyz.key,&xyz.data));
	ASSERT(strcmp(get(&hash,&xyz.key),"xyz"));
}