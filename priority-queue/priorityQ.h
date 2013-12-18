typedef char String[256];

typedef struct node{
    void* element;
    int priority;
    struct node *next;
}Node;

typedef struct{
    Node *front;
    int length;
}List;

List* create();
typedef int compFunc(void* , void*);
int insertFront(Node *process,List *list);
int enqueueElements(List *list ,Node *pq, compFunc* compare);
int dequeueElements(List* list);