#include <bits/stdc++.h>
void pattern_13(int n)
{
    int number = 1;
    for(int row = 1; row <= n; row++)
    {
        //print numbers
        for(int col = 1; col <= row; col++)
        {
            std::cout<<number<<" ";
            number++;
        }
        std::cout<<'\n';
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    pattern_13(n);
}

/*
 1
 2 3
 4 5 6
 7 8 9 10
 11 12 13 14 15
*/
