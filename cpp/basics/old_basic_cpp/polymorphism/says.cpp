#include <iostream>
#include "says.h"
#include <string>

template<class DataType1, class DataType2>
says<DataType1, DataType2>::says():animal<DataType1, DataType2>()
{
    animalSays="";
}

template<class DataType1, class DataType2>
says<DataType1, DataType2>::says(DataType1 animalSpecie, DataType1 animalName, DataType2 animalAge, DataType1 animalSays):animal<DataType1, DataType2>(animalSpecie, animalName, animalAge)
{
    this->animalSays=animalSays;
}

template<class DataType1, class DataType2>
void says<DataType1, DataType2>::display()
{
    //calls display function of base class
    animal<DataType1, DataType2>::display();
    std::cout<<"Animal says: "<<animalSays<<'\n';

}

//Only needed when using polymorphism
//need to declare expected datatypes
template class says <std::string, int>;