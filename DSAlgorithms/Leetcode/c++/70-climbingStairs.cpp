#include <iostream>

int climbingStairs(int n)
{
    int one = 1;
    int two = 1;
    int temp;
    while(n > 1)
    {
        temp = one;
        one = one + two;
        two = temp;
        --n;
    }
    return one;
}


int climbingStairs2(int n)
{
    int one = 1;
    int two = 1;
    int temp;
    for(int i = 0; i < n - 1; i++)
    {
        temp = one;
        one = one + two;
        two = temp;
    }
    return one;
}