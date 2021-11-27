#include <stdio.h>

int max( int, int);
int smallermax( int, int);

int main()
{
    int a = 99;
    int b = 101;

    printf("%d\n", smallermax(a,b));

    //newline printed after every 10th element and after the nth element.
    //all others are followed by blanks
    int n= 66;
    int A[n];
    for ( int i = 1; i <=  n; i++)
        printf("%6d%c", A[i], (i%10==0 || i==n ) ? '\n' : ' ');

    return 0;
}

//compute max of 2 numbers
int max( int a, int b)
{
    int z = 0;

    if ( a > b)
        z = a;
    else
        z = b;
    return z;
}

int smallermax( int a, int b)
{
    int z = 0;

    //function uses ternary op
    //expr1 ? expr2 : expr3
    //expr1 is eval first, if true, expr2 is the answer.
    //if expr1 is false, expr3 is the answer
    z = ( a > b) ? a : b;
    return z;
}
