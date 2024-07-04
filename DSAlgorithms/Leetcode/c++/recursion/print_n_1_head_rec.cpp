#include<bits/stdc++.h>
void f(int i, int n)
{
    if(i > n)
        return;
    f(i + 1, n);
    std::cout<<i<<'\n';  //work done at return time
}
int main()
{
    f(1, 3);
    f(1, 5);
}
