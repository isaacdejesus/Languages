#include <iostream>

int factorial(int n);

int main()
{
    int value;
    std::cout<<"Enter a number: "<<'\n';
    std::cin>>value;
    std::cout<<'\n';
    std::cout<<"Factorial is: "<<factorial(value);
    return 0;
}

int factorial( int n)
{
    if(n==1)
        return 1;
    else
    {
            return n* factorial(n-1);
    }
    
}