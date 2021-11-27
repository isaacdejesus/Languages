#include<stdio.h>

int main()
{
    //integer constant
    int int_constant = 100;
    //long constants end with l or L
    long long_constantL = 10000;
    //unsigned constansts end with u or U
    long long_unsigned_constantUL = 900000000;
    //double constant
    double double_constant = 123.4;
    //float constant end with f or F. l or L for long
    float long_float_constantFL = 123.4;
    //character constant is a single char in single quotes
    //value is the numeric value of the char
    char char_constant = 'a';
    //constant expressions involve only constants
    #define MAXLINE 1000
    char line[MAXLINE +1];
    //string literal/constant is sequence of 0+ chars in double quotes
    //A string constant is an array of chars terminating in '\0'
    //enum constants
    enum months { January = 1, February, March, April, May, June, July, August, September, October, November, December};

    return 0;
}
