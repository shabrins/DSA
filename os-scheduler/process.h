typedef char string[256];
typedef struct{
    int execute;
    int wait;
    int stop;
}Condition;


typedef struct P{
    string processName;
    int seconds;
    Condition PStatus;
    int priority;
    struct P *next;
}Process;


typedef struct{
    Process *front;
    int length;
}Scheduler;


Scheduler* create();
typedef int compFunc(void* , void*);
int enqueue(Scheduler *queue,Process *process,compFunc* compare);        
int dequeue(Scheduler *queue);