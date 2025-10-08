#include<bits/stdc++.h>
bool is_even(int n);
int f1(std::vector<int>& v);
int f2(std::vector<int>& v);
int f3(std::vector<int>& v);
int main()
{
    std::vector<int> v = {12, 345, 2, 6, 7896};
    std::cout<<f1(v)<<'\n';
    std::cout<<f2(v)<<'\n';
    std::cout<<f3(v)<<'\n';
    return 0;
}
bool is_even(int n)
{
    int digit_count = 0;
    while(n > 0)
    {
        digit_count++;
        n = n /10;
    }
    return (digit_count & 1) == 0;
}

int f1(std::vector<int>& v)
{
    int even_digits_count = 0;
    for(auto num: v)
    {
        if(is_even(num))
            even_digits_count++;
    }
    return even_digits_count;
}
int f2(std::vector<int>& v)
{
    int even_digits_count = 0;
    for(auto i: v) 
    {
        int length = std::to_string(i).length();
        if(length % 2 == 0)
            even_digits_count++;
    }
    return even_digits_count;
}
int f3(std::vector<int>& v)
{
    int even_digits_count = 0;
    for(auto num: v)
    {
        if(((int)log10(num)  + 1)% 2 == 0)
            even_digits_count++;
    }
    return even_digits_count;
}
