#include <iostream>
#include <string>
#include "stack.h"

template <class DataType>
Node<DataType>::Node()
{
    link=nullptr;
}
template<class DataType>
Stack<DataType>::Stack() {
    head = nullptr;
    count = 0;
}

template<class DataType>
bool Stack<DataType>::isEmpty() {
    return(head == nullptr);
}

template<class DataType>
void Stack<DataType>::push(DataType val) {
    Node<DataType> *newNode = new Node<DataType>;
    newNode->info = val;

    if(isEmpty()) {
        head = newNode;
        count++;
    } else {
        newNode->link = head;
        head = newNode;
        count++;
    }
}

template<class DataType>
DataType Stack<DataType>::top() {

    DataType temp;
    if(isEmpty()) 
        std::cout << "empty" <<'\n';
    else
        temp= head->info;
    return temp;
}

template <class DataType>
DataType Stack<DataType>::pop()
{
    DataType toReturn;
    if(isEmpty())
        std::cout<<"Empty, nothing to pop"<<'\n';
    else
    {
        Node<DataType> *temp;
        toReturn=head->info;
        temp=head;
        head=head->link;
        delete temp;
    }

    return toReturn;
    
}

template <class DataType>
Stack<DataType>::~Stack()
{
   
}

template class Stack<std::string>;
template class Stack<int>;
template class Stack<float>;
template class Stack<char>;

template class Node<int>;
template class Node<std::string>;
template class Node<float>;
template class Node<char>;