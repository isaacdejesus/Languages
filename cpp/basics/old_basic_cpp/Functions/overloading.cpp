#include <iostream>

/*
Function overloading allows you to have variations of the same function which take different parameters
Functions all have the same name but differ in number of parameters or return type
*/

int iDivideStuff( int a, int b);
int iDivideStuff( int a, int b, int c);
float iDivideStuff (float a);

int main()
{
    std::cout<<iDivideStuff(100, 10);
    std::cout<<iDivideStuff(100, 8, 9);
    std::cout<<iDivideStuff(9.9);

    return 0;
}

int iDivideStuff( int a, int b)
{
    std::cout<<'\n';
    return a/b;
}

int iDivideStuff(int a, int b, int c)
{   
    std::cout<<'\n';
    return a/b/c;
}

float iDivideStuff(float a)
{
    std::cout<<'\n';
    return a/2;
}