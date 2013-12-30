#include "testUtils.h"
#include "hashmap.h"
#include <string.h>
#include <stdio.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areKeyEqual(void* key1 , void* key2 ){
        return *(int*)key1 - *(int*)key2;
}
int hashFun(void *key){
        return *(int*)key;
};
typedef struct{
        int key;
        char value[50];
} Intern;
Intern abc = {15441,"abc"};
Intern pqr = {15445,"pqr"};
Intern xyz = {15345,"xyz"};
Intern aaa = {15349,"aaa"};
Intern shab = {15348,"shab"};


void test_add_an_element_to_hashmap(){
        HashMap map = createMap(hashFun, areKeyEqual);
        ASSERT(put(&map, &pqr.key, &pqr.value));
        ASSERT(0 == strcmp(pqr.value,(char*)get(&map, &pqr.key)));
}
void test_add_multiple_elements_to_hashmap(){
        HashMap map = createMap(hashFun, areKeyEqual);
        ASSERT(put(&map, &pqr.key, &pqr.value));
        ASSERT(put(&map, &abc.key, &abc.value));
        ASSERT(put(&map, &xyz.key, &xyz.value));
        ASSERT(0 == strcmp(pqr.value,(char*)get(&map, &pqr.key)));
        ASSERT(0 == strcmp(abc.value,(char*)get(&map, &abc.key)));
        ASSERT(0 == strcmp(xyz.value,(char*)get(&map, &xyz.key)));
}
void test_get_not_found_data_in_hashmap(){
        HashMap map = createMap(hashFun, areKeyEqual);
        ASSERT(put(&map, &pqr.key, &pqr.value));
        ASSERT(NULL == get(&map, &abc.key));
}
void test_remove_hash_data_from_hashmap(){
        HashMap map = createMap(hashFun, areKeyEqual);
        ASSERT(put(&map, &pqr.key, &pqr.value));
        ASSERT(1 == remove_hash(&map, &pqr.key));
        ASSERT(NULL == get(&map, &pqr.key));
}
void test_remove_hash_data_from_when_data_not_present(){
        HashMap map = createMap(hashFun, areKeyEqual);
        ASSERT(put(&map, &pqr.key, &pqr.value));
        ASSERT(0 == remove_hash(&map, &abc.key));
}
void test_keys_of_gives_all_keys_in_map(){
        HashMap map = createMap(hashFun, areKeyEqual);
        Iterator it;        
        void* result;
        int key1 = 67809 , value1 = 6;
        ASSERT(put(&map, &pqr.key, &pqr.value));
        ASSERT(put(&map, &abc.key, &abc.value));
        ASSERT(put(&map, &xyz.key, &xyz.value));
        ASSERT(put(&map, &aaa.key, &aaa.value));
        ASSERT(put(&map, &key1, &value1));
        result = keys(&map);
        
}