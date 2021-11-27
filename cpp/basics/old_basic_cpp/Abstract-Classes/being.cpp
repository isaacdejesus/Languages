#include <iostream>
#include <string>
#include "being.h"

template<class DataType>
being<DataType>::being(DataType name)
{
    this->name=name;
}

template <class DataType>
void being<DataType>::setName(DataType name)
{
    this->name=name;
}

// template <class DataType>
// void being<DataType>::setType(DataType beingType)
// {

// }

// template <class DataType>
// void being<DataType>::display()
// {

// }

//Needed when splitting class into h/.cpp files
template class being<std::string>;
