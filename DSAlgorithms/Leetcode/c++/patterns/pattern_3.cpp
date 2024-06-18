#include <bits/stdc++.h>
void pattern_3(int n)
{
    for(int row = 1; row <= n; row++)
    {
        for(int col = 1; col <= row; col++)
        {
            std::cout<<col<<" ";
        }
        std::cout<<'\n';
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    pattern_3(n);
}

/*
prints
1
1 2
1 2 3
1 2 3 4
*/
