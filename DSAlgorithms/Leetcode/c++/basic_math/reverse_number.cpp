#include<bits/stdc++.h>
int reverse_number(int n)
{
    int reversed_number = 0;
    while(n > 0)
    {
        int last_digit = n % 10;
        n = n /10;
        reversed_number = reversed_number * 10 + last_digit;
    }
    return reversed_number;
}

int main()
{
    std::cout<<reverse_number(9876)<<'\n';
    std::cout<<reverse_number(4253)<<'\n';
}
