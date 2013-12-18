#include "stack_memcpy.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Stack* create(int typeSize){
        Stack* stack = calloc(1,sizeof(Stack));
        stack->peek = NULL;
        stack->typeSize = typeSize;
        stack->presentElements = 0;
        return stack;
};

void push(Stack* stack,void* element){
        List* list = calloc(1,sizeof(List*));
        int *elementToBePushed = (int*)calloc(1,stack->typeSize);
        memcpy(elementToBePushed,element,stack->typeSize);
        list->element = elementToBePushed;
        if(stack->peek == NULL){
                list->previous = NULL;
                stack->peek = list;
        }
        else {
                list->previous = stack->peek;
                stack->peek = list;
        }
        stack->presentElements++;
};

List* pop(Stack* stack){
        List* list;
        List* poppedElement;
        if(stack->peek == NULL) return NULL;
        list = calloc(1,sizeof(List*));
        poppedElement = stack->peek;
        list->element = calloc(1,stack->typeSize);
        memcpy(list->element, stack->peek->element,stack->typeSize);
        stack->peek = (*stack->peek).previous;
        poppedElement->previous = NULL;
        return list;
};
