#ifndef BEING_H
#define BEING_H
#include <iostream>
#include <string>
template<class DataType>
class being
{
    public: 
        DataType name;
    public:
        being(DataType name= "");
        void setName( DataType name);
        virtual void setType(DataType beingType)=0;
        virtual void display()=0;
};

#endif