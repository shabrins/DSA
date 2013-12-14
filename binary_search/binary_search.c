#include "binary_search.h"
#include <stdio.h>
#include <stdlib.h>

Binary_search* createList(int length,int typeSize){
	Binary_search* b = calloc(1, sizeof(Binary_search));
    b->left = 0;
    b->right = length;
    b->list = calloc(length,typeSize);
    b->typeSize= typeSize;
    b->middle = 0;
    return b;
}

void* binarySearch(void* list,void* key,int length,int elementSize,compareFunction* compare){
   int first = 0,middle,result;
   int last = length - 1;
   while(first <= last ){
      middle = (first+last)/2;
      result = compare(key,list+(middle*elementSize));
      if(result == 0)
         return (void*)(list+(middle*elementSize));
      if(result < 0)
         last = middle-1;
      else
         first = middle+1;
   }
   return 0;
} 