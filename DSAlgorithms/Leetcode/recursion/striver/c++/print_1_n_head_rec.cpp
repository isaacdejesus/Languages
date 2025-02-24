#include<bits/stdc++.h>
void f(int i, int n)
{
    if(i < 1)
        return;
    f(i - 1, n);
    std::cout<<i<<'\n';  //work done at return time
}
int main()
{
    f(3, 3);
    f(5, 5);
}
