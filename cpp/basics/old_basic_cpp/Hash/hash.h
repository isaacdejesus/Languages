#ifndef HASH_H
#define HASH_H
#include <iostream>
template <class DataType>
struct Node
{
    DataType info;
    Node<DataType> *link;
    Node();
};

template <class DataType>
class hash
{
    private:
        int size;
        Node<DataType> *head;
        Node<DataType> **Table;

    public:
        hash(int sizeIn=100);
        //bool isEmpty();
        void insert(DataType elemToInsert);
        int hashfunction(DataType elemToHash);
        void display();

};

#endif