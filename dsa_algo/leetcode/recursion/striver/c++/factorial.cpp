#include<bits/stdc++.h>
int f(int n)
{
    if(n < 1)
        return 1;
    return n * f(n - 1);
}
int main()
{
    std::cout<<f(3);
    std::cout<<'\n';
    std::cout<<f(5);
    std::cout<<'\n';
}
