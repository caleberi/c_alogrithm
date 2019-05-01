#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    // value of a node
    int value;
    // pointer to another node
    struct Node *next;
    // pointer to the previous node
    struct Node *prev;
};

// an alias for node
typedef struct Node Node;

struct doubleLinkedList
{
    // monitors the length of the doubleLinkedList
    int size;
    // pointer to the head
    Node *head;
    // pointer to the tail
    Node *tail;
};

// an alias for doubleLinkedList
typedef struct doubleLinkedList doubleLinkedList;

// check to see if the linkedlist is isEmpty
bool isEmpty(doubleLinkedList *d){
    return d->size == 0;
}
// moving through the list
void Transverse(doubleLinkedList *d){
    Node *n = d->head;
    while(n!=NULL){
        printf("%d\n",n->value);
        n = n->next;
    }
    
}

// searching the list
bool contains(doubleLinkedList *d,int value){
    if(isEmpty(d)){
        return false;
    }else
    {
        Node *n = d->head;
        while(n != NULL && n->value != value){
            n=n->next;
        }
        if(n==NULL){
            return false;
        }
        return true;
    }
    
}

// create a doubleLinkedList container model
doubleLinkedList* createDoubleLinkedList(){
    // creating a linkedlist type of memory using malloc()
    doubleLinkedList * d = (doubleLinkedList *)malloc(sizeof(doubleLinkedList *));
    //initialize the members of the elinkedlist
    d->size = 0;
    d->head=NULL;
    d->tail = NULL;
    return d;
};

void add(doubleLinkedList *d,int value){
    Node *n = (Node *)malloc(sizeof(Node *));
    n->value=value;
    n->next = NULL;
    n->prev = NULL;

    if(d->head == NULL){
        d->head = n; // set the newNode  to be the head
        d->tail = n; // set the newNode  to be the tail
    }else
    {
        n->prev = d->tail; // making the newnode previous to be equal tail the 
        d->tail->next = n; // makes the tail's next to be the new node
        d->tail =  n; // make the newnode the tail
    }
}
bool destroy(doubleLinkedList *d,int value){
    Node *n =  (Node *)malloc(sizeof(Node *));
    if(d->head == NULL){
        return false;
    }

    if(d->head->value == value){
        if(d->head == d->tail){
            free(d->head);
            free(d->tail);
            d->head = NULL;
            d->tail =  NULL;
        }else{
            d->head = d->head->next;
            d->head->prev = NULL;
        }
        return true;
    }
    n = d->head->next;
    while(n!=NULL && n->value != value){
        n=n->next;
    };
    if(n == d->tail){
        d->tail = d->tail->prev;
        d->tail->next = NULL;
        return true;
    }else if(n != NULL)
    {
        n->prev->next = n->next;
        n->next->prev = n->prev;
        return true;
    }
    return false;
}

void reverseTransverse(doubleLinkedList *d){
    while(d->tail != NULL){
        printf("%d\n",d->tail->value);
      d->tail = d->tail->prev;
    }
}

int main()
{

    doubleLinkedList *d = createDoubleLinkedList();
    add(d,3);
    add(d,4);
    add(d,5);
    add(d,6);
    add(d,7);
    destroy(d,5);
    // Transverse(d);
    reverseTransverse(d);
    
    return 0;
}
