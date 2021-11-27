#include <iostream>
#include "bubblesort.h"

void bubblesort( int arr[], int size)
{
    int temp;
    for( int i=0; i<size-1; i++)
        for(int j=0; j<size; j++)
            if(arr[j]>arr[j+1])
                {
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
}

void display( int arr[], int size)
{
    for(int i=0; i<size; i++)
        std::cout<<arr[i]<<" ";
}