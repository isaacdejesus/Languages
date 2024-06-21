#include <bits/stdc++.h>
void pattern_10(int n)
{
    for(int row = 0; row < n ; row++)
    {
        for(int col = 0; col < n; col++)
        {
            if(row == 0 || col == 0 || row == n - 1 || col == n - 1)
                std::cout<<"*";
            else 
                std::cout<<" ";

        }
        std::cout<<'\n';
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    pattern_10(n);
}

/*
prints
****
*  *
*  *
*  *
****
*/
