#include <bits/stdc++.h>
void pattern_6(int n)
{
    for(int row = 1; row <= n; row++)
    {
        for(int col = 1; col <= n - row + 1; col++)
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
    pattern_6(n);
}

/*
prints
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
*/
