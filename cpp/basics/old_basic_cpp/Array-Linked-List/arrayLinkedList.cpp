#include <iostream>
#include "arrayLinkedList.h"

template <typename T>
arrayLinkedList<T>::arrayLinkedList(int n)
{
    length=0;
    if(n<0)
        maxSize=100;
    else
        maxSize=n;
    
    list= new T[maxSize];
	
    //cout<<maxSize;
}

template <typename T>
arrayLinkedList<T>::arrayLinkedList(const arrayLinkedList<T>& other)
{
    length=other.length;
    maxSize=other.maxSize;
    list= new T[other.maxSize];
    for(int i=0; i<other.maxSize; i++)
        {
            list[i]=other.list[i];
        }
}

template <typename T>
 arrayLinkedList<T>& arrayLinkedList<T>::operator=(const arrayLinkedList<T>& copy)
{
    //std::cout<<"chicken";
    if( this==&copy)
        return *this;
    
	//delete [] list;
    this->length=copy.length;
    this->maxSize=copy.maxSize;
    this->list= new T[copy.maxSize];
    for(int i=0; i<copy.maxSize; i++)
        {
            this->list[i]=copy.list[i];
        }
    return *this;
}

template <typename T>
arrayLinkedList<T>::~arrayLinkedList()
{
    delete [] list;
}

template<typename T>
bool arrayLinkedList<T>::isEmpty() const
{
	//will return true is length is 0, else will return false
	return(length==0);
}

template<typename T>
bool arrayLinkedList<T>::isFull() const
{
	return(length==maxSize);
}

template <typename T>
int arrayLinkedList<T>::listSize( ) const
{
	return length;
}

template< typename T>
int arrayLinkedList<T>::maxListSize( ) const
{
	return maxSize;
}

template <typename T>
void arrayLinkedList<T>::print() const
{
	for(int i=0; i<length; i++)
		{
			std::cout<<list[i]<<" ";
		}
		std::cout<<'\n';
}

template <typename T>
void arrayLinkedList<T>::clearList( )
{
	//reset pointer back to first index
	length=0;
}

template <typename T>
void arrayLinkedList<T>::removeAt(int index)
{
	//checks list for index to be in range of size
	if(!isEmpty() && index>=0 && index <length)
		{
			//if at end of list
			if(index==length-1)
				{
					length--;
				}
			else
			{
				for( int i=index; i<length; i++)
					{
						list[i]=list[i+1];//?
					}
					length--;
			}
			
		}
		else
		{
			std::cout<<"error msg"<<'\n';
		}
		
}

template <typename T>
int arrayLinkedList<T>::search(const T& element) const
{
	int result=-1;
	if(isEmpty())
		result=-1;

	for(int i=0; i<length; i++)
		{
			if(list[i]==element)
				{
					std::cout<<"Found at: "<<i<<'\n';
					result= i;
				}
		}
	return result;
}

template <typename T>
void arrayLinkedList<T>::remove(const T& value)
{
	//Damn, this is one sexy function <3
	//int index=search(value);
	//std::cout<<"Removing value at index: "<<index<<'\n';
	if(search(value)!=-1)
		{
			//std::cout<<"Value found!"<<'\n';
			removeAt(search(value));
			//will you marry me!
		}
	else if(search(value)==-1)
		std::cout<<"bad error msg"<<'\n';
}

template <typename T>
void arrayLinkedList<T>::retrieveAt(int pos, T& d) const
{
	if(!isEmpty() && pos>=0 && pos<length)
		{
			d=list[pos];
		}
	else 
		std::cout<<"Error msg from??"<<'\n';
}

template <typename T>
void arrayLinkedList<T>::insert(const T& value)
{
	int index=-1;
	if(isEmpty())
	{
		list[length]=value;
		length++;
	}
	else if(length==maxSize)
		std::cout<<"List is full"<<'\n';
	else
	{
		for( int i=0; i<length; i++)
			{
				if(list[i]>value)
					{
						index=i;
						break;		
					}
			}
			//if there is no value >new, add at end
			if(index==-1)
			{
				list[length]=value;
				length++;
			}
			else if(index!=-1)
				{	
					T temp, temp2;
					temp2=value;
					length++;
					for( int i=index; i<length; i++)
						{
							temp=list[i];
							list[i]=temp2;
							temp2=temp;
						}
						//std::cout<<"index before new val is"<<index<<'\n';
				}
	}
	
}


template class arrayLinkedList<std::string>;
template class arrayLinkedList <int>;
template class arrayLinkedList <float>;
template class arrayLinkedList <char>;