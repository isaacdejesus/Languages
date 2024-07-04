#include<bits/stdc++.h>
int gcd(int a, int b)
{
    while(a > 0 && b > 0)
    {
        if(a > b)
            a = a % b;
        else
            b = b % a;
    }
    if(a == 0)
        return b;
    return a;
}

int main()
{
    std::cout<<gcd(11, 13)<<'\n';
    std::cout<<gcd(9, 12)<<'\n';
}
