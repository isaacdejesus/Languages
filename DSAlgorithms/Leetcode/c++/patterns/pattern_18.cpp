#include <bits/stdc++.h>
void pattern_18(int n)
{
    for(int row = 0; row < n; row++)
    {
        for(char ch = 'E' - row; ch <= 'E'; ch++)
        {
            std::cout<<ch<<" ";
        }
        std::cout<<'\n';
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    pattern_18(n);
}

/*
E 
D E
C D E
B C D E
A B C D E
*/
