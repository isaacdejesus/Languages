#include<bits/stdc++.h>
int f(int n)
{
    if(n <= 1)
        return n;
    //return f(n - 1) + f(n - 2);
    //below does same as above
    int last = f(n - 1);
    int second_last = f(n - 2);
    return last + second_last;
}

int main()
{
    std::cout<<f(5)<<'\n';
    std::cout<<f(8)<<'\n';
}
