typedef struct node{
    void* element;
    struct node *next;
}Node;



typedef struct list{
        Node* head;
        int length;
}SList;

SList* create();
int insertElement(SList *list,int index,void* element);
int nodeDeletion(SList* list,int index);