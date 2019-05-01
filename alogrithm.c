#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "math.h"

void swap(int *p,int *q){
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
};

void bubbleSort(int *arr,int length)
{
    int i,j;
    for(i=0;i<length-1;i++){
        for(j = 0; j < length - 1; j++)
        {
           if(arr[i]< arr[j]){
                swap(&arr[i],&arr[j]);
           }
        }
        
    }
};

/* bool isPrime(int n)
{
    int i,j;
    for(int i=0; i==n; i++){
        for(int j=0; j==(int)sqrt((double)n);j++){
            if (i*j == 0) {
                return false;
            }
        }
    }
    return true;
};*/



int main()
{
    int arr[] = {4,6,2,7,90,45,23,78,20,34,21,67,45,23,67,89,9,56};
    int length = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,length);

    int i = 0;
    while(i<length){
        printf("%d \t",arr[i]);
        i = i +1;
    }
    printf("\n");

    printf("%d", isPrime(8));
    printf("\n");
    return 0;
}