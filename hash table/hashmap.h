#include "./include/iterator.h"

#ifndef _COMPARE_
#define _COMPARE_
typedef int (*compare)(void* firstElement, void* secondElement);
typedef int (*hash)(void *key);
#endif        
#ifndef _HASHMAP_
#define _HASHMAP_
typedef struct {
        void *buckets;
        hash hashFunc;
        compare cmp;
} HashMap;

HashMap createMap(hash hashFunc, compare compareKey);
int put(HashMap* map, void* key, void* value);
void* get(HashMap* map, void* key);
int remove_hash(HashMap* map, void* key);
void* keys(HashMap* map);
#endif