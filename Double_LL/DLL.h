typedef struct node{
        void* element;
        struct node *next;
        struct node *previous;
} Node;

typedef struct {
        int length;
        Node* head;
} List;

List* create();
int insertElement(List* front, int index, void* element);
int removeElement(List* front, int index);
void dispose(List* front);
int isEmpty(List* front);