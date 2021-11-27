#ifndef STACK_H
#define STACK_H

template<class DataType>
struct Node
{
    DataType info;
    Node<DataType> *link;
    Node();
};

template<class DataType>
class Stack
{
    private:
        int count;
        Node<DataType> *head;

    public:
        Stack();
        bool isEmpty();
        void push(DataType val);//add to head 
        DataType pop();
        DataType top();
        ~Stack();
};
#endif