typedef struct{
    void* element;
    void* previous;
} List;


typedef struct {
    List* peek;
    int presentElements;
    int typeSize;
} Stack;

typedef char String[256];

Stack* create(int typeSize);
void push(Stack* stack,void* element);
List* pop(Stack* stack);