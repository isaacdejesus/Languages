#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>

template<class DataType1, class DataType2>
class animal
{
    private:
        DataType1 animalSpecie;
        DataType1 animalName;
        DataType2 animalAge;
    public: 
        animal();
        animal(DataType1 animalSpecie, DataType1 animalName, DataType2 animalAge);
        void setAnimalSpecie(DataType1 animalSpecie);
        void setAnimalName(DataType1 animalName);
        void setAnimalAge(DataType2 animalAge);
        virtual void display();
};
#endif

