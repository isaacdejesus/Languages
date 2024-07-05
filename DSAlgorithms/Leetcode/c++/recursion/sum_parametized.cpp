#include<bits/stdc++.h>
void f(int sum, int n)
{
    if(n < 1)
    {
        std::cout<<sum<<'\n';
        return;
    }
    f(sum + n, n - 1);
}
int main()
{
    f(0, 3);
    f(0, 5);
}
