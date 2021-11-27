#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include <iostream>

template <class DataType>
class arrayQueue
{
    private:
        int count;
        int maxSize;
        DataType *list;

    public:
        arrayQueue(int Size=100);
        ~arrayQueue();
        bool isEmpty();
        bool isFull();
        int getCurrentSize();
        void enqueue(DataType info);
        DataType dequeue();
        DataType front();
        DataType back();
        void displayAll();
    
};

#endif

