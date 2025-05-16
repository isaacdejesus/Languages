#include<bits/stdc++.h>
void f(int i, int n)
{
    if(i > n)
        return;
    std::cout<<i<<'\n';
    std::cout<<"isaac"<<'\n';
    f(++i, n);
}
int main()
{
    f(1, 7);
    f(1, 5);
}
