#include <iostream>
#include "hash.h"
#include <sstream>

template <class DataType>
Node<DataType>::Node()
{
    link=nullptr;
}
template <class DataType>
int hash<DataType>::hashfunction(DataType elemToHash)
{
    std::ostringstream oss;
    oss<<elemToHash;
    std::string elem= oss.str();
    int sum=0;
    for( int i=0; i<elem.length(); i++)
        {
            sum=sum+ static_cast<int>(elem.at(i));
        }
    return (sum%size);
}

template <class DataType>
hash<DataType>::hash(int sizeIn)
{
    if(sizeIn<100)
        size=100;
    
    size=sizeIn;
    head=nullptr;
    Table=new Node<DataType>*[size];
    for(int i=0; i<size; i++)
        {
            Table[i]=nullptr;//each one acts as head for linked list
        }
}

template <class DataType>
void hash<DataType>::display()
{
    for(int i=0; i<size; i++)
    {
        if(Table[i]!=nullptr)
            {
                Node<DataType> *temp;
                temp=Table[i];
                while(temp!=nullptr)
                    {
                        std::cout<<"Displaying info stored at index "<<i<<" "<<temp->info<<'\n';
                        temp=temp->link;
                    }
            }
    }
}

template <class DataType>
void hash<DataType>::insert(DataType elemToInsert)
{
    int locToStore=hashfunction(elemToInsert);
    Node<DataType> *temp;
    Node<DataType> *newNode= new Node<DataType>;
    newNode->info=elemToInsert;
    newNode->link=nullptr;
    temp=Table[locToStore];

    if(temp==nullptr)
        {
            Table[locToStore]=newNode;
        }
    else if(temp!=nullptr)
        {
            while(temp->link!=nullptr)
                {
                    temp=temp->link;
                }
            temp->link=newNode;
        }
}
template class hash<int>;
template class hash<std::string>;
template class hash<float>;
template class hash<char>;
template class hash<double>;
template class Node<int>;
template class Node<std::string>;
template class Node<float>;
template class Node<char>;
template class Node<double>;

