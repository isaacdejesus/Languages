#include <bits/stdc++.h>
void print_1(int n)
{
    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < n; col++)
        {
            std::cout<<"* ";
        }
        std::cout<<'\n';
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    print_1(n);
}

/* prints
****
****
****
****
*/
