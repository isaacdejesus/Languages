#include <iostream>
#include <cassert>

#ifndef ARRAYLINKEDLIST_H
#define ARRAYLINKEDLIST_H

template<class DataType>
class arrayLinkedList
{
public:
	arrayLinkedList(int = 100);
	arrayLinkedList(const arrayLinkedList<DataType>& other);
	arrayLinkedList<DataType>& operator=(const arrayLinkedList<DataType>& copy);
	bool isEmpty() const;
	bool isFull() const;
	int listSize( ) const;
	int maxListSize( ) const;
	void print() const;
	void clearList( );
	void removeAt(int);
	void remove(const DataType);
	void insert(const DataType);
	void retrieveAt(int pos, DataType d) const;
	int search(const DataType) const;
	int binarySearch(const DataType &) const;
	~arrayLinkedList( );
private:
	DataType* list;
	int length;
	int maxSize;
};

#endif


//list resizing;
//avoid resizing too often
//only double size when full
//only half list when 1/4 full
//because halving the list when at half, leads to immediate doubling when next element is added
// void arrayList<DataType>::doubleList()

// {
// 	T *temp= new T[maxSize];
// 	for(int i=0; i<maxSize; i++)
// 	{
// 		temp[i]=list[i];
// 	}

// 	delete [] list;
// 	maxSize=maxSize*2;
// 	list=new T[maxSize];

// }