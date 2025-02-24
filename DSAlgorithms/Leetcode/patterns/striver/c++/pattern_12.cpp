#include <bits/stdc++.h>
void pattern_12(int n)
{
    int space = 2 * (n - 1);
    for(int row = 1; row <= n; row++)
    {
        //print numbers
        for(int col = 1; col <= row; col++)
            std::cout<<col;
        //print spaces
        for(int col = 1; col <= space; col++)
            std::cout<<" ";
        for(int col = row; col >= 1; col--)
            std::cout<<col;
        std::cout<<'\n';
        space -= 2;
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    pattern_12(n);
}

/*
1      1
12    21
123  321
12344321
 
*/
