#include "testUtils.h"
#include "hashMap.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int compare(void* first,void* second){
        return *(int*)first - *(int*)second;
}

int hashCodeGenerator(void* key){
        return *(int*)key;
}
HashMap* map;

void setup(){
        map = createHashMap(hashCodeGenerator, compare);
}

void tearDown(){
        disposeHashMap(map);
}

void test_to_add_key_in_the_hash_map(){
        int key = 1;
        int value = 10;
        ASSERT(putMapNode(map, &key,&value));
        ASSERT(&value == getValue(map, &key));
}

void test_add_already_exsisting_value_in_the_hash_map(){
        int key = 1;
        int _10 = 10,_20 = 20;
        ASSERT(putMapNode(map, &key,&_10));
        ASSERT(putMapNode(map, &key,&_20));
        ASSERT(&_20 == getValue(map, &key));
}

void test_add_data_that_doesnt_exsisting_value_in_the_hash_map(){
        int key = 1;
        ASSERT(NULL == getValue(map, &key));
}

void test_to_remove_specific_key_and_value_from_hash_map(){
        int key = 1;
        int value = 10;
        ASSERT(putMapNode(map, &key,&value));
        ASSERT(removeMapNode(map, &key));
        ASSERT(NULL == getValue(map, &key));
}

void test_to_remove_and_value_which_is_not_present_in_hash_map(){
        int key = 1;
        ASSERT(0 == removeMapNode(map, &key));
}

void test_to_get_all_the_keys_from_hash_map(){
        int key = 1;
        int value = 10;
        MapIterator mapIt;
        ASSERT(putMapNode(map, &key,&value));
        mapIt = mapKeys(map);
        ASSERT(&key == nextKey(&mapIt));
        ASSERT(NULL == nextKey(&mapIt));
}