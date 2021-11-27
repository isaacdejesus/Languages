#include <iostream>
#include "arrayStack.h"

template<class DataType>
bool arrayStack<DataType>::isEmpty()
{
    return(count==0);
}

template<class DataType>
bool arrayStack<DataType>::isFull()
{
    return(count==maxSize);
}
template<class DataType>
arrayStack<DataType>::arrayStack(int size)
{
    count=0;
    maxSize=size;
    array=new DataType[maxSize];
}

template<class DataType>
void arrayStack<DataType>::push(DataType value)
{
    if(isFull())
        std::cout<<"Stack if full"<<'\n';

    else if(isEmpty())
        {
            array[0]=value;
            count++;
        }
    else
    {
        array[count]=value;
        count++;
    }
}

template<class DataType>
DataType arrayStack<DataType>::top()
{
    DataType temp;
    if(isEmpty())
        std::cout<<"stack is empty"<<'\n';
    else
    {
        temp=array[count-1];
    }
    return temp;
}

template<class DataType>
DataType arrayStack<DataType>::pop()
{
    DataType temp;
    if(isEmpty())
        std::cout<<"Can't pop from empty stack"<<'\n';
    else
    {
        count--;
        temp=array[count];
    }
    return temp;
    
}

template class arrayStack <std::string>;
template class arrayStack <int>;
template class arrayStack <float>;
template class arrayStack <char>;
