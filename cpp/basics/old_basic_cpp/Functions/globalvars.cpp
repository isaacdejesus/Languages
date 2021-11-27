#include <iostream>
//declaring global var
float globalVar=1.0;
//Global vars are initiated during loading time and are not destroyed until the program stops.
//Global var once initiated remains in memory. Not initiated every time a function is called
//Global vars can be used by all functions

float aFunction( float var);

int main()
{
    std::cout<<aFunction(globalVar);
    return 0;
}

float aFunction( float var)
{
    globalVar+=.2;
    return globalVar;
}