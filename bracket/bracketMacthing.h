typedef struct {
        void* elements;
        int top;
        int length;
        int typeSize;
}Stack;

#define  true   1
#define false   0
#define bool  int

typedef char String[256];
Stack* create(int length,int typeSize);
int push(Stack* s,void* element);

void* pop(Stack* s);
void* peek(Stack* s);
int isEmpty(Stack* s);
int isFull(Stack* s);


bool breakMatch(String str);
