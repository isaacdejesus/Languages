#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

template <class DataType>
class arrayStack
{
    private:
        int count;
        int maxSize;
        DataType *array;
    public:
        arrayStack(int size);
        bool isEmpty();
        bool isFull();
        void push(DataType value);
        DataType pop();
        DataType top();
};
#endif