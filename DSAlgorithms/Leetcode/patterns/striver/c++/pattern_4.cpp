#include <bits/stdc++.h>
void pattern_3(int n)
{
    for(int row = 1; row <= n; row++)
    {
        for(int col = 1; col <= row; col++)
        {
            std::cout<<row<<" ";
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
2 2
3 3 3
4 4 4 4
5 5 5 5 5
*/
