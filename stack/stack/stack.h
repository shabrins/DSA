#include <stdbool.h>
typedef struct{
	void *elements;
	int top;
	int typeSize;
	int length;
}Stack;

typedef char String[256];

#define  TRUE   1
#define FALSE   0
#define STACK  int

Stack* create(int typeSize, int elements);
int push(Stack *stack, void* elements);
void* pop(Stack *stack);
void dispose(Stack *stack);
int isEmpty(Stack *stack); 
int isFull(Stack *stack);