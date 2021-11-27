#include <iostream>
#include "arrayHash.h"
#include <sstream>

template <class DataType>
arrayHash<DataType>::arrayHash(int sizeIn)
{
    if(sizeIn<100)
        size=100;
    else
        size=sizeIn;
    
    length=0;
    Table=new DataType[size];
    state=new int[size];
    for(int i=0; i<size; i++)
    {
        state[i]=0;
    }
}

template <class DataType>
int arrayHash<DataType>::hashFunction(DataType elemToHash)
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
void arrayHash<DataType>::linearProbe(DataType element)
{
    int insertAtIndex=hashFunction(element);

    //check if full
    if(length==size)
        {
            std::cout<<"array is full";
            return;
        }
    //check if element is duplicate
    if(Table[insertAtIndex]==element)
        {
            std::cout<<"Duplicates not allowed."<<'\n';
            return;
        }

    //check if another value already in key
    while(state[insertAtIndex]==1)
    {
        std::cout<<insertAtIndex<<" Hash slot is occupied. Looking for an empty slot for : "<<element<<'\n';
        if(state[insertAtIndex]==1)
            {

                insertAtIndex=(insertAtIndex+1)%size;
            }
    }
    Table[insertAtIndex]=element;
    state[insertAtIndex]=1;
    length++;

}

template <class DataType>
void arrayHash<DataType>::display()
{
    for(int i=0; i<size; i++)
    {
        if(state[i]==1)
            {
                std::cout<<Table[i]<<" "<<'\n';
            }
    }
}

template <class DataType>
void arrayHash<DataType>::remove(DataType element)
{
    int elementToFind=hashFunction(element);
    bool found=false;
    while(state[elementToFind]==1 || state[elementToFind]==-1)
    {
        if(Table[elementToFind]==element)
        {
            found=true;
            break;
        }
        else
            elementToFind=(elementToFind+1)%size;
    }

    if(found)
        {
            state[elementToFind]=-1;
            length--;
        }
    else if(!found)
        {
            std::cout<<"Can not delete."<<'\n';
        }
}

template <class DataType>
int arrayHash<DataType>::search(DataType elemToFind)
{
    int toReturn=-1;
    int elementToFind=hashFunction(elemToFind);
    bool found=false;

    while(state[elementToFind]==1 ||state[elementToFind]==-1)
    {
        if(Table[elementToFind]==elemToFind)
        {
            found=true;
            break;
        }
        else
            elementToFind=(elementToFind+1)%size;
    }
    if(found)
        toReturn=elementToFind;
    else 
    {
        std::cout<<elemToFind<<" was not found in hash table"<<'\n';
        //return;
    }

    return toReturn;
}






template class arrayHash<int>;
template class arrayHash<std::string>;
template class arrayHash<float>;
template class arrayHash<double>;
template class arrayHash<char>;