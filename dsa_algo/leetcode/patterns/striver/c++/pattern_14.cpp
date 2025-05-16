#include <bits/stdc++.h>
void pattern_14(int n)
{
    for(int row = 0; row <= n; row++)
    {
        for(char ch = 'A'; ch <= 'A' + row; ch++)
        { //Loop char which in this case represent cols. Loop from 'A' to 'A' + row char
            std::cout<<ch<<" ";  //ex, if row is 2, We would output A, B, C since C is A + 2 in ascii
        }
        std::cout<<'\n';
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    pattern_14(n);
}

/*
a
ab
abc
abcd
abcde
*/
