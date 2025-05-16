#include<bits/stdc++.h>
void print_divisors(int n)
{
    for(int i = 1; i <=n; i++)
    {
        if((n % i) == 0)
            std::cout<<i<<" ";
    }
}

void print_divs(int n)
{
    std::vector<int> list;
    for(int i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            list.push_back(i);  //i is a divisor
            if((n/i) != i)      //check if second operand isn't same as i
                list.push_back(n/i);  //if different then add to list since it is also a divisor
        }
    }
    sort(list.begin(), list.end());
    for(auto it: list)
        std::cout<<it<<" ";
}
void print_divs_improved(int n)  //gets rid of sqrt function
{
    std::vector<int> list;
    for(int i = 1; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            list.push_back(i);  //i is a divisor
            if((n/i) != i)      //check if second operand isn't same as i
                list.push_back(n/i);  //if different then add to list since it is also a divisor
        }
    }
    sort(list.begin(), list.end());
    for(auto it: list)
        std::cout<<it<<" ";
}

int main()
{
    print_divs(36);
}
