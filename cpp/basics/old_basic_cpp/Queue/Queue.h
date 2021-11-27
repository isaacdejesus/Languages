#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

template <class DataType>
struct Node {
    DataType info;
    Node<DataType> *link;
    Node();
};

template <class DataType>
class Queue
{
    private:
        int count;
        Node<DataType> *back;
        Node<DataType> *front;
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        int getCurrentSize();
        void enque(DataType info);
        DataType dequeue();
        DataType peekFront();
        DataType peekBack();
};
#endif
