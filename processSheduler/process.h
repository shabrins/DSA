typedef char String[256];

#define  TRUE   1
#define FALSE   0
#define PQUEUE  int

typedef struct pq{ 
	String Pname;
	int seconds;
    int priority;
    struct pq *link;
	} PQ;


typedef struct {
 	PQ *bufferHead; 
 	void *last;
 	int length;
    int rear;
    int front;
 	} ProcessScheduler;





ProcessScheduler* create();
int PQinsert(ProcessScheduler* pq, PQ* p);
int Qfull(ProcessScheduler* pq);
int Qempty(ProcessScheduler* pq);


