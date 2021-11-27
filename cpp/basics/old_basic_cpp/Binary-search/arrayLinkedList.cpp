#include <iostream>
#include "arrayLinkedList.h"

template <class DataType>
arrayLinkedList<DataType>::arrayLinkedList(int n)
{
    length=0;
    if(n<0)
        maxSize=100;
    else
        maxSize=n;
    
    list= new DataType[maxSize];
}

template <class DataType>
arrayLinkedList<DataType>::arrayLinkedList(const arrayLinkedList<DataType>& other)
{
    length=other.length;
    maxSize=other.maxSize;
    list= new DataType[other.maxSize];
    for(int i=0; i<other.maxSize; i++)
        {
            list[i]=other.list[i];
        }
}

template <class DataType>
 arrayLinkedList<DataType>& arrayLinkedList<DataType>::operator=(const arrayLinkedList<DataType>& copy)
{
    //std::cout<<"chicken";
    if( this==&copy)
        return *this;
    
	//delete [] list;
    this->length=copy.length;
    this->maxSize=copy.maxSize;
    this->list= new DataType[copy.maxSize];
    for(int i=0; i<copy.maxSize; i++)
        {
            this->list[i]=copy.list[i];
        }
    return *this;
}

template <class DataType>
arrayLinkedList<DataType>::~arrayLinkedList()
{
    delete [] list;
}

template<class DataType>
bool arrayLinkedList<DataType>::isEmpty() const
{
	//will return true is length is 0, else will return false
	return(length==0);
}

template<class DataType>
bool arrayLinkedList<DataType>::isFull() const
{
	return(length==maxSize);
}

template <class DataType>
int arrayLinkedList<DataType>::listSize( ) const
{
	return length;
}

template< class DataType>
int arrayLinkedList<DataType>::maxListSize( ) const
{
	return maxSize;
}

template <class DataType>
void arrayLinkedList<DataType>::print() const
{
	for(int i=0; i<length; i++)
		{
			std::cout<<list[i]<<" ";
		}
		std::cout<<'\n';
}

template <class DataType>
void arrayLinkedList<DataType>::clearList( )
{
	//reset pointer back to first index
	length=0;
}

template <class DataType>
void arrayLinkedList<DataType>::removeAt(int index)
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

template <class DataType>
int arrayLinkedList<DataType>::search(const DataType element) const
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

template <class DataType>
void arrayLinkedList<DataType>::remove(const DataType value)
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

template <class DataType>
void arrayLinkedList<DataType>::retrieveAt(int pos, DataType d) const
{
	if(!isEmpty() && pos>=0 && pos<length)
		{
			d=list[pos];
		}
	else 
		std::cout<<"Error msg from??"<<'\n';
}

template <class DataType>
void arrayLinkedList<DataType>::insert(const DataType value)
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
					DataType temp, temp2;
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

template <class DataType>
int arrayLinkedList<DataType>::binarySearch(const DataType &element) const
{
	//binary search requires list to be in order
	int first=0;
	int last=length-1;
	int mid;
	bool found=false;

	while(first<=last && !found)
		{
			mid=(first+last)/2;
			if(list[mid]==element)
				found=true;
			else if(list[mid]>element)
				last=mid-1;
			else 
				first=mid+1;
		}
	if(found)
		return mid;
	else return
		-1;
}
template class arrayLinkedList<std::string>;
template class arrayLinkedList <int>;
template class arrayLinkedList <float>;
template class arrayLinkedList <char>;