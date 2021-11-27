#include <iostream>
#include "chicken.h"
#include <string>

template <class DataType>
chicken<DataType>::chicken(DataType name, DataType beingType):being<DataType>(name)
{
    this->beingType=beingType;
}

template <class DataType>
void chicken<DataType>::setType(DataType beingType)
{
    this->beingType=beingType;
}

template <class DataType>
void chicken<DataType>::display()
{
    std::cout<<"My name is: "<<this->name<<". I am a: "<<this->beingType<<'\n';
}

template class chicken<std::string>;