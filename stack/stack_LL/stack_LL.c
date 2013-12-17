#include "stack_LL.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"



int push(SList* S,void* element){
    int result,index;
    index = S->length;
    result = insertElement(S,index,element);
    return result;
}
void* pop(SList* S){
    void* result;
    int index = S->length-1;
    result = nodeDeletion(S,index);
    return result;
};