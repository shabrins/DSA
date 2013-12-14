#include "bracketMacthing.h"
# include <stdio.h>
#include <string.h>
#include <stdlib.h>


void* getElement(Stack* s,int top){
        return s->elements+top*s->typeSize;
};

Stack* create(int length, int typeSize){
        Stack* s;
        s = (Stack*)calloc(sizeof(Stack), 1);
        s->elements = calloc(typeSize, length);
        s->typeSize = typeSize;
        s->length = length;
        s->top = 0;
        return s;
}

int isEmpty(Stack* stack){
        if(stack->top)
                return 0;
        return 1;
}
int isFull(Stack* stack){
        if(stack->top==stack->length)
                return 1;
        return 0;
}

int push(Stack* stack,void* element){
        if(isFull(stack))
                return 0;
        memcpy(getElement(stack,stack->top++),element,stack->typeSize);
        return 1;
}
void* pop(Stack* stack){
        if(stack -> top ==0) return NULL;
        return getElement(stack,--(stack->top));
};

void* peek(Stack* stack){
        if(isEmpty(stack)) return NULL;
        return getElement(stack,(stack->top-1));
}

bool breakMatch(String str){
    Stack* stack;
    const char* input = str;
    void* current;
    int i,limit;
    stack = create(500,sizeof(char));
    limit = strlen(input);
    for(i=0;i<limit;i++){
        if(input[i]=='{'|| input[i]=='[' || input[i]=='(')
                push(stack, (void*)&input[i]);
        if(input[i]=='}'){
            current = peek(stack);
            if(NULL==current) return false;
			if('{' != *(char*)current)
                return false;
            else
                pop(stack);
        }
        if(input[i] == ']'){
            current = peek(stack);
            if(NULL==current) return false;
            if('[' != *(char*)current)
                return false;
            else
                pop(stack);
        }
        if(input[i]==')'){
            current = peek(stack);
            if(NULL==current) return false;
			if('(' == *(char*)current)
                   pop(stack);
            else
                return false;
        }
    }
    if(stack->top==0)
        return true;
    else
        return false;
    return 0;
}
