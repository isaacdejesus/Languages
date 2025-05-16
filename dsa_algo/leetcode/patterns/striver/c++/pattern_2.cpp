#include <bits/stdc++.h>
void pattern_2(int n)
{
    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col <= row; col++)
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
    pattern_2(n);
}

/*
prints
*
* * 
* * *
* * * *
*/
