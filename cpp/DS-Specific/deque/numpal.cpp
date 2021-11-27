#include<iostream>
#include<string>

int main()
{
    int x = 22313;
    std::string str = std::to_string(x);

    for(auto digit: str)
        std::cout<<digit<<' ';
    return 0;
}
