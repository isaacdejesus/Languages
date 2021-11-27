#include <iostream>
#include "Queue.h"

template <class DataType>
Node<DataType>::Node()
{
    link=nullptr;
}

template <class DataType>
Queue<DataType>::Queue()
{
    count=0;
    front=nullptr;
    back=nullptr;
}

template <class DataType>
bool Queue<DataType>::isEmpty()
{
    return (front==nullptr);
}

template <class DataType>
int Queue<DataType>::getCurrentSize()
{
    return count;
}

template <class DataType>
void Queue<DataType>::enque(DataType info)
{
    Node<DataType> *newNode= new Node<DataType>;
    newNode->info=info;
    newNode->link=nullptr;
    if(isEmpty())
        {
            front=newNode;
            back=newNode;
            count++;
        }
    else
    {
        back->link=newNode;
        back=back->link;
        count++;
    }
    
}

template <class DataType>
DataType Queue<DataType>::peekFront()
{
    if(isEmpty())
        std::cout<<"Empty"<<'\n';

    return front->info;       
}

template <class DataType>
DataType Queue<DataType>::peekBack()
{
    if(isEmpty())
        std::cout<<"Empty"<<'\n';
    
    return back->info;
}

template <class DataType>
DataType Queue<DataType>::dequeue()
{
    DataType toReturn;
    Node<DataType> *temp;
    if(isEmpty())
        std::cout<<"empty"<<'\n';
    
    else
    {
        toReturn=front->info;
        temp=front;
        front=front->link;
        delete temp;
        count--;

            if(front==nullptr)
                back=nullptr;
    }
    
    return toReturn;
}

template <class DataType>
Queue<DataType>::~Queue()
{
    while(!isEmpty())
    {
        dequeue();
    }
}

template class Node<int>;
template class Node<float>;
template class Node<std::string>;
template class Node <char>;

template class Queue <int>;
template class Queue <char>;
template class Queue <float>;
template class Queue <std::string>;