#include<bits/stdc++.h>
bool reverse_number(int n)
{
    int reversed_number = 0;
    int original_number = n;
    while(n > 0)
    {
        int last_digit = n % 10;
        n = n /10;
        reversed_number = reversed_number * 10 + last_digit;
    }
    return reversed_number == original_number;
}

int main()
{
    std::cout<<reverse_number(11211)<<'\n';
    std::cout<<reverse_number(4253)<<'\n';
}
