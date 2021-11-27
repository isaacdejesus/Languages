#include <iostream>
#include "bubble.h"
using namespace std;
/*
BUBBLE SORT
    worst = O(n^2)
    best = O(1)
*/

void bubble(int arr[], int size){
    int i,j, temp;
    for(i = 0; i < size-1; i++) {
        for(j = 0; j < size-1; j++) {
            if(arr[j] > arr[j+1]) {
                // temp = arr[j];
                // arr[j] = arr[j+1];
                // arr[j+1] = temp;
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void printshit(int arr[], int size) {
    for(int i = 0; i < size-1; i++) {
        cout << arr[i] << endl;
    }
}