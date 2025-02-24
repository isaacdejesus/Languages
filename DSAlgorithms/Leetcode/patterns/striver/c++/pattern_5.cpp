#include <bits/stdc++.h>
void pattern_5(int n)
{
    for(int row = 1; row <= n; row++)
    {
        for(int col = 0; col < n - row + 1; col++)
        {
            std::cout<<"* ";
        }
        std::cout<<'\n';
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    pattern_5(n);
}

/*
prints
* * * * *
* * * *
* * *
* *
*
*/
