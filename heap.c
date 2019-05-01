#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct heap{
    // array pointer
    int *heap_arr;
    // heap size
    int size;
};

// an alias for heap
typedef struct   heap heap;

heap*  createHeap(int max_size){
    heap *h = (heap *)malloc(sizeof(heap));
    h->heap_arr = (int*)malloc(sizeof(h->heap_arr) * max_size);
    int i;
    for(i=0;i < max_size;i++){
        h->heap_arr[i] =0;
    };

    h->size = 0;
    return h;
};

void swap(int *p,int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
};

void minHeapify(heap *h){
    int i;
    i = h->size - 1;
    while(i>0 && h->heap_arr[i] < h->heap_arr[(i-1)/2]){
        swap(&h->heap_arr[i],&h->heap_arr[(i-1)/2]);
        i=(i-1)/2;
    };
};

void maxHeapify(heap *h){
    int i;
    i = h->size - 1;
    while(i>0 && h->heap_arr[i] > h->heap_arr[(i-1)/2]){
        swap(&h->heap_arr[i],&h->heap_arr[(i-1)/2]);
        i=(i-1)/2;
    };
};



void add(heap *h,int value){
    h->heap_arr[h->size] = value;
    h->size = h->size + 1;
    minHeapify(h);
};




int main()
{
    return 0;
}