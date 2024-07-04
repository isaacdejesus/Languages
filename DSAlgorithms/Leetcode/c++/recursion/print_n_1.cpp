#include<bits/stdc++.h>
void f(int i, int n)
{
    if(i < 1)
        return;
    std::cout<<i<<'\n';
    f(--i, n);
}
void f2(int i, int n)
{
    if(i >= n)
        return;
    f2(++i, n);
    std::cout<<i<<'\n';
}
int main()
{
    //f(5, 5);
    //f(7, 7);
    f2(0, 5);
}
