#include<bits/stdc++.h>
void f(int i, int n)
{
    if(i > n)
        return;
    std::cout<<i<<'\n';
    f(++i, n);
}
int main()
{
    f(1, 5);
    f(1, 7);
}
