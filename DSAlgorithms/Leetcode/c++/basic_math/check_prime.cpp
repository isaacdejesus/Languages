#include<bits/stdc++.h>
bool check_prime(int n)
{
    int count = 0;
    for(int i = 1; i*i <=n; i++)
    {
        if(n % i == 0)
        {
            count++;
            if((n/i) != i)
                count++;
        }
    }
    if(count == 2)
        return 1;
    else 
        return 0;
}

int main()
{
    std::cout<<check_prime(13)<<'\n';
    std::cout<<check_prime(4)<<'\n';
}
