#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    // value of a node
    int value;
    // pointer to another node
    struct Node *pointer;
};

// an alias for node
typedef struct Node Node;

struct linkedList
{
    // monitors the length of the linkedList
    int size;
    // pointer to the head
    Node *head;
};

// an alias for linkedList
typedef struct linkedList linkedList;

// check to see if the linkedlist is isEmpty
bool isEmpty(linkedList *l){
    return l->size == 0;
}

// create a linkedList container model
linkedList* createLinkList(){
    // creating a linkedlist type of memory using malloc()
    linkedList * l = (linkedList *)malloc(sizeof(linkedList *));
    //initialize the members of the elinkedlist
    l->size = 0;
    l->head=NULL;
    return l;
};

// add an item inside a linkedlist
void add(linkedList *l,int value){
    // create a node instance structure
    Node * n = (Node *)malloc(sizeof(linkedList *));
    // initialize the member values
    n->value = value;
    n->pointer=NULL;
    if(isEmpty(l)){
        l->head = n; // make head = newNode
        l->size++;
    }else{
        n->pointer = l->head; // make the head the newNode
        l->head = n; // make head = newNode
        l->size++;
    }
}

// return a value of node
int pop(linkedList *l){
    if(isEmpty(l)){
        printf("linkedList is currently empty\n");
    }
    if(l->head->pointer == NULL){
        int value =l->head->value; // store the value;
        free(l->head);
        l->head = NULL;
        l->size--;
        return value;
    }
    Node *n = l->head; // make n the current node
    while(n->pointer->pointer!= NULL){
        n = n->pointer; // look to the last node;
    }
    int value = n->pointer->value;
    free(n->pointer);
    n->pointer = 0;
    l->size--;
    return value;
}
bool contains(linkedList *l,int value){
    if(isEmpty(l)){
        return false;
    }else
    {
        Node *n = l->head;
        while(n != NULL && n->value != value){
            n=n->pointer;
        }
        if(n==NULL){
            return false;
        }
        return true;
    }
    
}

void erase(linkedList *l,int value){
    if (isEmpty(l)) {
         printf("linkedList is currently empty\n");
    }
    Node *n = l->head;
    if(l->size == 1 && n->value == value){
        free(n);
        l->head = NULL;
        l->size--;
    }
    while(n->pointer != NULL && n->pointer->value != value){
        n = n->pointer;
    }
    // Node *deleteNext = n->pointer;
    if(n->pointer != NULL){
        free(n->pointer);
        n->pointer=n->pointer->pointer;
        l->size--;
        
    }
   
}

void Transverse(linkedList *l){
    Node *n = l->head;
    while(n!=NULL){
        printf("%d\n",n->value);
        n = n->pointer;
    }
    
}



int  main()
{
    linkedList* l = createLinkList();
    add(l,8);
     add(l,5);
      add(l,4);
       add(l,3);
        add(l,2);
    // printf("%i\n",contains(l,6));
    
    

    
    return 0;
}