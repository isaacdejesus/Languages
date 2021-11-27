#include <iostream>
#include <string>

//There are three ways to pass parameters to a function
//By value doesn't change the original values
//By address changes the original
//By reference changes original
//Reference function are also called inline functions because they run in main
//The funciton is not called. instead, the function code is copied and run in main.
//by reference doesn't allocate extra variables in stack like other functions
//it is best not to use complex code inside by reference functions since they run in main

std::string byValue( std::string a);
std::string byAddress( std::string *a);
std::string byReference( std::string &a);
int main()
{
    std::string var="Hello";
    byValue(var);
    std::cout<<var<<'\n';
    //by address takes a pointer as argument, therefore we pass the address of the var as argument or a pointer
    byAddress(&var);
    std::cout<<var<<'\n';
    byReference(var);
    std::cout<<var<<'\n';
    return 0;
}

std::string byValue( std::string a)
{
    a="I am potato";
    std::cout<<'\n';
    return a;
}

//By address takes pointer as argument. We pass the argument as follow &variable
std::string byAddress( std::string *a)
{
    *a="I am potato";
    std::cout<<'\n';
    return *a;
}

std::string byReference( std::string &a)
{
    a="I am potato, sometimes...";
    std::cout<<'\n';
    return a;
}