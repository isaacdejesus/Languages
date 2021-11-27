#ifndef CHICKEN_H
#define CHICKEN_H

#include <iostream>
#include <string>
#include "being.h"

template<class DataType>
class chicken: public being<DataType>
{
    private:
        //DataType name;
        DataType beingType;
    public:
        chicken(DataType name= "", DataType beingType="");
        void setType(DataType beingType);
        void setName( DataType name);
        void display();
};

#endif