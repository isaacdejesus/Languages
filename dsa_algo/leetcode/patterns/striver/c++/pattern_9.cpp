#include <bits/stdc++.h>
void pattern_7(int n)
{
    for(int row = 0; row < n; row++)
    {
        //spaces
        for(int col = 0; col < n - row - 1; col++)
            std::cout<<" ";
        //stars
        for(int col = 0; col < 2 * row + 1; col++)
            std::cout<<"*";
        //spaces
        for(int col = 0; col < n - row - 1; col++)
            std::cout<<" ";
        std::cout<<'\n';
    }
}
void pattern_8(int n)
{
    for(int row = 0; row < n; row++)
    {
        //spaces
        for(int col = 0; col < row; col++)
            std::cout<<" ";
        //stars
        for(int col = 0; col < 2*n - (2 * row + 1); col++)
            std::cout<<"*";
        //spaces
        for(int col = 0; col < row; col++)
            std::cout<<" ";
        std::cout<<'\n';
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    pattern_7(n);
    pattern_8(n);
}

/*
prints
    *
   ***
  *****
 *******
*********
*********
 *******
  *****
   ***
    *
*/
