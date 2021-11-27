#include <iostream>
#include <string>
//https://fuckingfunctionpointers.com/
//declaring a pointer to function
//datatype (*pointername)(parametertypes)= functionname;
//declaring pointer to function as array
//returntype(*pointername[])(paramatertype)={funtion1, function2,...}

void nameof(std::string nameIn, char sexIn);
void hobbyof(std::string hobbyIn, char yearsIn);
int main()
{
    //pointer declaration and ini
    void (*pointer[])(std::string, char)={nameof, hobbyof};
    //function call
    pointer[0]("isaac", 'm');
    pointer[1]("writer", 's');
    return 0;
}

void nameof(std::string nameIn, char sexIn)
{
    std::cout<<"Name is: "<<nameIn<<'\n';
    std::cout<<"Sex is: "<<sexIn<<'\n';
}
void hobbyof(std::string  hobbyIn, char yearsIn)
{
    std::cout<<"Hobby is: "<<hobbyIn<<'\n';
    std::cout<<"First char, corresponding to number of years at hobby: "<<yearsIn<<'\n';
}