#include "DLL.h"
#include <stdlib.h>
#include <stdlib.h>

List* create(){
        List* front = calloc(1,sizeof(List));
        front->length=0;
        front->head=NULL;
        return front;
}

Node* nodeCreation(void* previous,void* next){
        Node* node = calloc(1, sizeof(Node));
        node->next = next;
        node->previous = previous;
        return node;
}

int insertElement(List *front, int index, void *element){
        Node *head=NULL,*previous=NULL,*next=NULL;
        int i;
        head = front->head;
    while(head!= NULL){
        previous = head;
        head = head->next;
    }
    head = previous;
        if(front->length==0){
                front->head = nodeCreation(previous, next);;
                front->head->element=element;
                front->length++;        
                return 1;
        }
        if(front->length == index){
        head->next = nodeCreation(previous, next);
        head->next->element = element;
        front->length++;
        return 1;
        }
        if(index >= 0 && index < front->length){
                next = previous->next;
                head->next = nodeCreation(previous, next);
                head->element = element;
                front->length ++;
                return 1;
        }
        return 1;        
}


int isEmpty(List* front){
        if(front->head == NULL)
                return 1;
        return 0;
}

void* removeElement(List *front, int index){
        Node *temp,*temp2;
        int count = 1;
        if(index >= front->length)
                return NULL;
        if(index == 0){
                front->head = front->head->next;
                front->length--;
                return temp;
        }
        temp = front->head;
        while(count < index){
                temp = temp->next;
                count++;
        }
        temp2=temp->next;
        temp->next = temp->next->next;
        if(temp->next != NULL)
                temp->next->previous = temp;
        free(temp2);
        front->length--;
        return temp2->element;
}

void dispose(List* front){
        Node* temp = front->head;
        Node* t1 = temp ;
        int count = 0;
        while(t1 != NULL){
                if(count != 0)
                        temp = t1;
                t1 = temp->next;
                if (temp != NULL)
                        free(temp);
                count++;
        }
}
