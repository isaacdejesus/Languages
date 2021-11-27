#include <iostream>
#include "animal.h"
#include "says.h"
#include <string>

int main()
{

    animal<std::string, int> *baseAnimal=new animal<std::string, int>("cat", "joo", 8);
    baseAnimal->display();
    says<std::string, int> *wolfAnimal= new says<std::string, int>("wolf", "whitewolf", 8, "ihavenoidead.somesort.of.roar");
    wolfAnimal->display();

    //another way of using class pointers with polymorphism
    //creates a pointer of animal type which points to says object type
    animal<std::string, int> *anotherAnimal= new says<std::string, int>();
    //When a pointer of base class points to derived class object, function calls will result in functions of the base class
    //In order to access functions of the derived class, the base class should be declared as virtual.
    //Therefore, the following will call the display function of the derived class
    std::cout<<"Now displaying info using the pointer pointing to derived object: "<<'\n';
    anotherAnimal->display();
    return 0;
}