#include <bits/stdc++.h>
void pattern_10(int n)
{
    for(int row = 0; row < 2 * n - 1 ; row++)
    {
        for(int col = 0; col < 2 * n - 1; col++)
        {
            int top = row;
            int left = col;
            int right = (2 * n - 2) - col;
            int down = (2 * n - 2) - row;
            std::cout<<(n - std::min(std::min(top, down), std::min(left, right)));
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
4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4
*/
