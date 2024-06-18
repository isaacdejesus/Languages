#include <bits/stdc++.h>
void pattern_11(int n)
{
    int start = 1;
    for(int row = 0; row < n; row++)
    {
        if(row % 2 == 0)
            start = 1;
        else 
            start = 0;
        for(int col = 0; col <= row; col++)
        {
            std::cout<<start;
            start = 1 - start;
        }
        std::cout<<'\n';
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    pattern_11(n);
}

/*
prints
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
*/
