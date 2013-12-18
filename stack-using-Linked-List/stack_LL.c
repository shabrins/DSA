#include "stack_LL.h"
#include <stdlib.h>
int pushElement(Stack* front, void* data){
        insertElement(front, front->length, data);
        return 1;
}

void popElement(Stack* front){
        removeElement(front, front->length-1);
}

void* peek(Stack* front){
        Node* head = front->head;
        while(head->next != NULL){
                head = head->next;
        }
        return head->element;
}