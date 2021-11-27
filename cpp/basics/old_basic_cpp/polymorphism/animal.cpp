#include <iostream>
#include "animal.h"
#include <string>

//default constructor
template<class DataType1, class DataType2>
animal<DataType1, DataType2>::animal()
{
    animalSpecie="";
    animalName="";
    animalAge=0;
}

//overloaded constructor
template<class DataType1, class DataType2>
animal<DataType1, DataType2>::animal(DataType1 animalSpecie, DataType1 animalName, DataType2 animalAge)
{
    this->animalSpecie=animalSpecie;
    this->animalName=animalName;
    this->animalAge=animalAge;
}

template<class DataType1, class DataType2>
void animal<DataType1, DataType2>::setAnimalSpecie(DataType1 animalSpecie)
{
    this->animalSpecie=animalSpecie;
}

template<class DataType1, class DataType2>
void animal<DataType1, DataType2>::setAnimalName(DataType1 animalName)
{
    this->animalName=animalName;
}

template<class DataType1, class DataType2>
void animal<DataType1, DataType2>::setAnimalAge(DataType2 animalAge)
{
    this->animalAge=animalAge;
}

template<class DataType1, class DataType2>
void animal<DataType1, DataType2>::display()
{
    std::cout<<"Specie: "<<animalSpecie<<'\n';
    std::cout<<"Name: "<<animalName<<'\n';
    std::cout<<"Age: "<<animalAge<<'\n';
}

template class animal<std::string, int>;
