#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct set{
    // pointer to an array
    int *arr;
    // size of array
    int size;
};

// an alias for set 
typedef struct set set;

set * Set(int length,int *arr){
    set *s = (set *)malloc(sizeof(set));
    s->arr = (int *)malloc(sizeof(s->arr)*length);
    int i;
    for(i = 0; i < length; i++)
    {
        s->arr[i] = 0;
    }
    for(i=0;i<length;i++){
        s->arr[i]= arr[i];
        s->size = s->size + 1;
    }
    return s;
};

bool isEmptySet(set *s){
    return s->size == 0;
};



int Union(set *a,set *b){
    if(isEmptySet(a)&&isEmptySet(b)){
        return 0;
    }
    int new[];
    int i;
    for(i=0;i<a->size;++a){
        new[i] = a->arr[i];
    }
    for(i=a->size-1;i<b->size;++b){
        Add(i);
    }
};


int main()
{
    return 0;
};