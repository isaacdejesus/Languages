#include <iostream>

//default arguments allow you to have set values to arguments to be used if user doesn't input them

int addStuffUp(int a, int b, int c=8);

int  main()
{
    std::cout<<addStuffUp(1, 3);
    return 0;
}


int addStuffUp(int a, int b, int c)
{
    return a+b+c;
}