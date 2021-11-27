#ifndef SAYS_H
#define SAYS_H
#include <iostream>
#include "animal.h"
#include <string>

template<class DataType1, class DataType2>
class says : public animal<DataType1, DataType2>
{
    private:
        DataType1 animalSays;
    
    public:
        says();
        says(DataType1 animalSpecie, DataType1 animalName, DataType2 animalAge, DataType1 animalSays);
        void display();
};
#endif

