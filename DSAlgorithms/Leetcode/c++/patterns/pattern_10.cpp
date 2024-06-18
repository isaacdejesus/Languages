#include <bits/stdc++.h>
void pattern_10(int n)
{
    for(int row = 1; row <= 2 * n - 1; row++)
    {
        int stars = row;
        if(row > n) 
            stars = 2 * n - row;
        for(int col = 1; col <= stars; col++)
        {
            std::cout<<"*";
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
1 *         [1 star]
2 **        [2 stars]
3 ***       [3 stars]
4 ****      [4 stars]
5 *****     [5 stars]
6 ****      [4 stars]
7 ***       [3 stars]
8 **        [2 stars]
9 *         [1 star]
*/
