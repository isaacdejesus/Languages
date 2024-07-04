#include<bits/stdc++.h>
bool armstrong_number(int n){
    int original_number = n;
    int sum = 0;
    int last_digit = 0;
    int count_digits = (int) (log10(n) + 1);
    while(n > 0)
    {
        last_digit = n % 10;
        n = n/10;
        sum = sum + pow(last_digit, count_digits);
    }
    return sum == original_number;
}

int main()
{
    std::cout<<armstrong_number(371)<<'\n';
    std::cout<<armstrong_number(1634)<<'\n';
    std::cout<<armstrong_number(35)<<'\n';
}
