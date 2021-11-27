#include <iostream>
typedef int number;

int main()
{
    number countUpTo;
    number i=1;
    number sum=0;
    std::cout<<"Enter a number to count up to: "<<'\n';
    std::cin>>countUpTo;
    do {
        //std::cout<<i<<'\n';
        sum+=i;
        i++;
    }
    while(i<=countUpTo);
    std::cout<<"Sum is: "<<sum<<'\n';
    return 0;
}
