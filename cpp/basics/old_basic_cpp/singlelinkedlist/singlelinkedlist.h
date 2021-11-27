#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H  
#include <iostream>

template <class DataType>
class node
{
    public:
        DataType info;
        node <DataType> *link;
        node ();
};
template <class DataType>
class singlelinkedlist
{
    private:
        int count;
        node <DataType> *head;
        node <DataType> *tail;
    public:
        singlelinkedlist();
        bool isEmpty();
        void display();
        void addAtBeginning( DataType info);
        void addAtEnd( DataType info);
        void addAtIndex( DataType info, int index);
        void addBeforeIndex( DataType info, int index);
        void addAfterIndex(DataType info, int index);
        int search(DataType toFind);
        node <DataType> * objectAtIndex( int index);
        void printInfoAtNode(node <DataType> *val);
        void addInOrder(DataType info);
        void swapNodes( node<DataType> *val1, node <DataType> *val2);
        void swapInfo(node<DataType> *val1, node <DataType> *val2);
        void bubbleSort();
        // void swapData()
        //need to be implemented
        // void addAtMid(DataType info);
        // void deleteAtIndex(int index);
        // void deleteAtEnd();
        // void deleteAtBeginning();
        // void del(DataType toDel);
        // void displayInReverse();
        // void displayRecursively();
        //copy constructor
        //overload =operator
        //overload != operator
        //overload == operator
        //destructor
        //sorts
        
};

#endif