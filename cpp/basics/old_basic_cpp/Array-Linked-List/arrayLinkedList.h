#include <iostream>
#include <cassert>

#ifndef ARRAYLINKEDLIST_H
#define ARRAYLINKEDLIST_H

template<typename T>
class arrayLinkedList
{
public:
	arrayLinkedList(int = 100);
	arrayLinkedList(const arrayLinkedList<T>& other);
	arrayLinkedList<T>& operator=(const arrayLinkedList<T>& copy);
	bool isEmpty() const;
	bool isFull() const;
	int listSize( ) const;
	int maxListSize( ) const;
	void print() const;
	void clearList( );
	void removeAt(int);
	void remove(const T&);
	void insert(const T&);
	void retrieveAt(int pos, T& d) const;
	int search(const T&) const;
	~arrayLinkedList( );
private:
	T* list;
	int length;
	int maxSize;
};

#endif


//list resizing;
//avoid resizing too often
//only double size when full
//only half list when 1/4 full
//because halving the list when at half, leads to immediate doubling when next element is added
// void arrayList<T>::doubleList()

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