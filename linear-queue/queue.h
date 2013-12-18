typedef struct {
        int capacity;
        int length;
        int front;
        int rear;
        void *elements;
}Queue;
typedef char String[256];

#define  TRUE   1
#define FALSE   0
#define QUEUE  int

Queue* createQueue(int length,int typeSize);
int enQueue(Queue *q,void* element);
void* deQueue(Queue *q);
void* front(Queue *q);
void dispose(Queue *q);