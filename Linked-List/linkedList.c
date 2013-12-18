#include "linkedList.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

SList* create(){
        SList* list;
        list = (SList*)malloc(sizeof(SList));
        list->head = NULL;
        list->length = 0;
        return list;
};


int frontInsertion(Node* currentNode,SList* list,int index,Node* head){
        if(index == 0){
                list->head = currentNode;
         return 1;
    }
    return 0;
};

int endInsertion(Node* currentNode,SList* list,int index,Node* head){
        if(index == list->length){
        head->next = currentNode;
                return 1;
    }
    return 0;
};

void middleInsertion(Node* currentNode,Node* head){
  
        currentNode->next = head->next;
        head->next = currentNode;
}

int insertElement(SList *list,int index,void* data){
    Node *head,*currentNode;
    int i;
    if(index <= -1 || index > list->length)
            return 0;
    list->length++;
        head = list->head;
    for (i = 0; i < index; ++i){
            if(head->next != NULL)
                    head = head->next;
    }
    currentNode = malloc(sizeof(Node));
    currentNode->next = NULL;
    currentNode->element = data;
        if(1 == frontInsertion(currentNode,list,index,head)) return 1;
        if(1 == endInsertion(currentNode,list,index,head)) return 1;
        middleInsertion(currentNode, head);
    return 1;
}

int nodeDeletion(SList* list,int index){
    int i;
    Node *head, *deletedNode;
    if(index <= -1 || index >= list->length)
        return 0;
    head = list->head;
    for(i=0;i<index;i++)
        head = head->next;
    if(i == 0){
        list->head = list->head->next;
    list->length--;

        free(head);
        return 1;
    }
    if(i == list->length - 1){
        list->head->next = NULL;
            list->length--;
                return 1;
    }
    list->head->element = head->next->element;
    list->length--;

    return 1;
};