#include<bits/stdc++.h>
int count_digits (int n)
{
    int count = 0;
    while(n > 0)
    {
        count++;
        n = n/10;
    }
    return count;
}
int count_digits_(int n)
{
    int count = (int)(log10(n) + 1);
    return count;
}

int main()
{
    std::cout<<count_digits(5)<<'\n';
    std::cout<<count_digits(10)<<'\n';
}
