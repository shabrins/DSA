typedef struct 
{
 void* list;
 int left;
 int right ;
 int middle;
 int typeSize;
} Binary_search;

#define  TRUE   1
#define FALSE   0
#define BOOL int
typedef char String[50];
typedef int compareFunction(void* , void*);
Binary_search* createList(int length,int typeSize);


void* binarySearch(void* list,void* key,int length,int elementSize,compareFunction* compare);

