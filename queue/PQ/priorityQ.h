typedef char String[256];

typedef struct queue{
    void* element;
    int priority;
    struct queue *next;
}PQueue;

typedef struct{
    PQueue *front;
    int length;
}List;

List* create();
typedef int compFunc(void* , void*);
int insertFront(PQueue *process,List *list);
int enqueue(List *list ,PQueue *pq, compFunc* compare);
int dequeue(List* list);