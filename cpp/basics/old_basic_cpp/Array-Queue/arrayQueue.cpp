#include<iostream>
#include "arrayQueue.h"

template <class DataType>
arrayQueue<DataType>::arrayQueue(int Size)
{
    count=0;
    if(Size<0)
        maxSize=100;
    else
        maxSize=Size;

    list= new DataType[maxSize];
}

template <class DataType>
arrayQueue<DataType>::~arrayQueue()
{
    delete [] list;
}

template <class DataType>
bool arrayQueue<DataType>::isEmpty()
{
    return(count==0);
}

template <class DataType>
bool arrayQueue<DataType>::isFull()
{
    return(count==maxSize);
}

template <class DataType>
int arrayQueue<DataType>::getCurrentSize()
{
    return count;
}

template <class DataType>
void arrayQueue<DataType>::enqueue(DataType info)
{
    if(isFull())
        std::cout<<"Queue is full"<<'\n';
    else if(isEmpty())
        {
            list[count]=info;
            count++;
        }
    else
        {
            count++;
            DataType temp;
            DataType temp2;
            temp2=info;
            for(int i=0; i<count; i++)
                {   
                    temp=list[i];
                    list[i]=temp2;
                    temp2=temp;
                }
        }
}

template <class DataType>
DataType arrayQueue<DataType>::dequeue()
{
    DataType deleting;
    if(isEmpty())
        std::cout<<"Queue is empty"<<'\n';
    else
        {
            count--;
            deleting=list[count];
        }
    return deleting;
}
template <class DataType>
DataType arrayQueue<DataType>::front()
{
    if(isEmpty())
        std::cout<<"Queue is empty"<<'\n';

    return list[count-1];
}

template <class DataType>
DataType arrayQueue<DataType>::back()
{
    if(isEmpty())
        std::cout<<"Queue is empty"<<'\n';
    return list[0];
}

template <class DataType>
void arrayQueue<DataType>::displayAll()
{
    for(int i=0; i<count; i++)
        {
            std::cout<<list[i]<<" ";
        }
    std::cout<<'\n';
}





template class arrayQueue<std::string>;
template class arrayQueue <int>;
template class arrayQueue <float>;
template class arrayQueue <char>;