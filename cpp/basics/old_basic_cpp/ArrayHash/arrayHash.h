#ifndef ARRAYHASH_H
#define ARRAYHASH_H
#include <iostream>

template <class DataType>
class arrayHash
{
    private:
        int size;
        int length;
        int *state;
        DataType *Table;
        int hashFunction(DataType elemToHash);
    public:
        arrayHash(int sizeIn=100);
        void linearProbe(DataType element);
        void remove(DataType element);
        int search( DataType elemToFind);
        void display();
        ~arrayHash();
};
#endif
