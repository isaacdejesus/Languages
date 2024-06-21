#include <bits/stdc++.h>
void pattern_7(int n)
{
    for(int row = 0; row < n; row++)
    {
        //spaces
        for(int col = 0; col < n - row - 1; col++)
            std::cout<<" ";
        //chars
        char ch = 'A';
        int break_point = (2 * row + 1) /2;
        for(int col = 1; col <= 2 * row + 1; col++)
        {
            std::cout<<ch;
            if(col <= break_point)
                ch++;
            else
                ch--;
        }
        //spaces
        for(int col = 0; col < n - row - 1; col++)
            std::cout<<" ";
        std::cout<<'\n';
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    pattern_7(n);
}

/*
0     A
1    ABA
2   ABCBA
3  ABCDCBA
4 ABCDEDCBA
*/
