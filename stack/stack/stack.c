#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

Stack* create(int typeSize, int length){
	Stack* stack = calloc(1,sizeof(Stack));
	stack->typeSize = typeSize;
	stack->length = length;
	stack->top = -1;
	stack->elements = calloc(stack->length,stack->typeSize);
	return stack;
};


int isEmpty(Stack *stack){
	return -1 == stack->top;
};

int isFull(Stack *stack){
	if((stack->top+1)>=stack->length)
		return 1;
	return 0;
};

int push(Stack *stack, void *elements){
	if(isFull(stack))
		return false;
	memcpy(stack->elements+(stack->typeSize*(stack->top+1)),elements,stack->typeSize);
	stack->top++;
	return true;
};


void* pop(Stack *stack){
	if(isEmpty(stack))
      return 0;
    return stack->elements + ((stack->top--)*stack->typeSize);
};



void dispose(Stack *stack){
	free(stack->elements);
	free(stack);
};
