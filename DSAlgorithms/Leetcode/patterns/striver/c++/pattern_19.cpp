#include <bits/stdc++.h>
void pattern_19(int n)
{
    int ini_spaces = 0;
    for(int row = 0; row < n; row++)
    {
        //stars
        for(int col = 1; col <= n - row; col++)
            std::cout<<"*";
        //spaces
        for(int col = 0; col < ini_spaces; col++)
            std::cout<<" ";
        //stars
        for(int col = 1; col <= n - row; col++)
            std::cout<<"*";
        ini_spaces += 2;
        std::cout<<'\n';
    }
    ini_spaces = 2 * n - 2;
    for(int row = 1; row <= n; row++)
    {
        //stars
        for(int col = 1; col <= row; col++)
            std::cout<<"*";
        //spaces
        for(int col = 0; col < ini_spaces; col++)
            std::cout<<" ";
        //stars
        for(int col = 1; col <= row; col++)
            std::cout<<"*";
        ini_spaces -= 2;
        std::cout<<'\n';

    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    pattern_19(n);
}

/*
xxxxxxxxxx
xxxx  xxxx
xxx    xxx
xx      xx
x        x
x        x
xx      xx
xxx    xxx
xxxx  xxxx
xxxxxxxxxx
*/
