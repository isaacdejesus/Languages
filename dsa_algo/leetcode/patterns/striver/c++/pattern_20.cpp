#include <bits/stdc++.h>
void pattern_10(int n)
{
    int spaces = 2 * n - 2;
    for(int row = 1; row <= 2 * n - 1; row++)
    {
        int stars = row;
        if(row > n)
            stars = 2 * n - row;
        //stars
        for(int col = 1; col <= stars; col++)
            std::cout<<"*";
        //spaces
        for(int col = 1; col <= spaces; col++)
            std::cout<<" ";
        //stars
        for(int col = 1; col <= stars; col++)
            std::cout<<"*";
        std::cout<<'\n';
        if(row < n)
            spaces -= 2;
        else
            spaces += 2;
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
x        x
xx      xx
xxx    xxx
xxxx  xxxx
xxxxxxxxxx
xxxx  xxxx
xxx    xxx
xx      xx
x        x
*/
