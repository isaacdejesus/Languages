#include <iostream>

int aFunction( int a=1);
int main()
{
    //static function is always available in memory. Not destroyed when the function ends.
    //but it can only be used by the function in which it was declared in
    //In the example below, the value of plus is saved in memory. And recalled every time the function is called.
    std::cout<<aFunction();
    std::cout<<aFunction();

    return 0;
}

int aFunction(int a)
{
    std::cout<<'\n';
    static int plus=0;
    plus+=3;
    return a+ plus;
}